/*=========================================================================*/
/*        DATE OF COMPLETION : 16-3-03      CLASS   : SE IT                */
/*=========================================================================*/
/* PROBLEM STATEMENT ::  REPRESENT A GIVEN GRAPH USING ADJACENCY LIST AND  */
/*                       PERFORM DEPTH FIRST SEARCH AND BREADTH FIRST      */
/*                       SEARCH                                            */
/*=========================================================================*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<process.h>

struct graph
{
  int vert;
  struct graph *next;
};

struct stack
{
  struct graph *dat;
  struct stack *next;
}*front;

struct queue
{
  int dat;
  struct queue *link;
}*front1,*rear;

/*    ***********  DECLARATION    OF    ALL    FUNCTIONS   ***********     */

graph* insert(struct graph *start,int c);
void display(struct graph *start);
void bfs(struct graph *start[20],int n);
void dfs(struct graph *start[20],int n);
void push(struct graph*);
graph* pop();
void add(int ch);
int retn(void);

/*=========================================================================*/
/*	    START OF THE MAIN FUNCTION                                     */
/*=========================================================================*/

void main()
{
 int n=0,v[20],i,s;
 char ch1;
 struct graph *g[20];
 for(i=0;i<n;i++)
 {
  v[i] = 0;
  g[i] =  NULL;
}

 do
 {
   clrscr();
   printf("\n\n\t=======================================================");
   printf("\n\n\t              **********  MENU  ************");
   printf("\n\n\t=======================================================");
   printf("\n\n\n\n\t\t 1> CREATE GRAPH ");
   printf("\n\n\t\t 2> DISPLAY ");
   printf("\n\n\t\t 3> B F S ");
   printf("\n\n\t\t 4> D F S ");
   printf("\n\n\t\t 5> EXIT    ");
   printf("\n\n\n\t\t  ENTER YOUR CHOICE  : ");
   scanf("%c",&ch1);
   switch(ch1)
   {
     case '1':
		clrscr();
		printf("\n\n\t============================================");
		printf("\n\n\n\t      INSERTION    OF    THE    GRAPH       ");
		printf("\n\n\n\t============================================");
		printf("\n\n\n\n\n\t  ENTER THE NO OF NODES TO BE INSERTED : ");
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
		  v[i] = 0;
		  g[i] =  NULL;
		  g[i] = insert(g[i],i+1);
		}
		for(i=0;i<n;i++)
		{
		 printf("\n\n\n\t  ");
		 printf("ENTER THE CONNECTED VERTICES FOR VERTEX  %d : ",i+1);
		 do
		 {
		   scanf("%d",&s);
		   if(s<n+1 && s>0)
		     g[i] = insert(g[i],s);
		   //printf("\n\n\t\t S = %d",s);
		 }while(s<n+1 && s>0);
		}
		getch();
		break;
     case '2':
		clrscr();
		printf("\n\n\t============================================");
		printf("\n\n\t          DISPLAYING   THE    GRAPH         ");
		printf("\n\n\t============================================");
		printf("\n\n\n\n\n\t\t THE GRAPH IS  : ");
		if(n == 0)
		  printf("\b\b\b EMPTY !!");
		else
		{
		 printf("\n\n\n\t");
		 printf("--------------------------------------------");
		 printf("\n\n\t\t      VERTEX\t ADJACENT VERTICES\n\n\t");
		 printf("--------------------------------------------\n");
		 for(i=0;i<n;i++)
		 {
		   printf("\n\t            |        |    ");
		   printf("\n\t VERTEX %d   |  ",i+1);
		   display(g[i]);
		   printf("\n\t            |        |    ");
		 }
		}
		getch();
		break;
     case '3':
		clrscr();
		bfs(g,n);
		getch();
		break;
     case '4':
		clrscr();
		dfs(g,n);
		getch();
		break;
     case '5':
		exit(0);
   }
 }while(ch1 != '5');
 getch();
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   INSERT()                                             */
/*       OBJECTIVE :  TO INSERT THE VERTICES AND EDGES OF THE GRAPH        */
/*       PARAMETERS : STRUCT NODE*                                         */
/*       RETURN TYPE   :  STRUCT GRAPH*                                    */
/*-------------------------------------------------------------------------*/

graph* insert(struct graph *start,int c)
{
 char ch;
 struct graph *p,*r;
 p = (graph*)malloc(sizeof(struct graph));
 p->next = NULL;
 p->vert = c;
 if(start == NULL)
 {
   start = p;
 }
 else
 {
  r = start;
  while(r->next != NULL)
   r = r->next;
  r->next = p;
 }
 return(start);
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   DISPLAY()                                            */
/*       OBJECTIVE :  TO DISPLAY THE GRAPH                                 */
/*       PARAMETERS : STRUCT GRAPH*                                        */
/*-------------------------------------------------------------------------*/

void display(struct graph *start)
{
  int flag = 0;
  struct graph *q=NULL;
  q = start;
  if(q == NULL)
   printf("\n\n\n\tTHE GRAPH IS EMPTY !!");
  else
  {
   while(q != NULL)
   {
     if(flag == 1)
      printf("   |  ");
     printf("  %d",q->vert);
     q = q->next;
     flag++;
   }
  }
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   PUSH()                                               */
/*       OBJECTIVE :  TO PUSH THE PTR TO VERTICES ON THE STACK             */
/*       PARAMETERS : STRUCT GRAPH*                                        */
/*-------------------------------------------------------------------------*/

void push(struct graph *data)
{
 struct stack *p=NULL;
 p = (stack*)malloc(sizeof(struct stack));
 p->dat= data;
 p->next = NULL;
 if(front == NULL)
 {
  front=p;
 }
 else
 {
   p->next=front;
   front=p;
 }
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   POP()                                                */
/*       OBJECTIVE :  TO POP THE ELEMENTS FROM THE STACK                   */
/*       RETURN TYPE : STRUCT GRAPH*                                       */
/*-------------------------------------------------------------------------*/

graph* pop()
{
 struct stack *p=NULL;
 struct graph *elem;
 p = front;
 if(p == NULL)
  getch();
 else
 {
  elem=front->dat;
  front=front->next;
  p->next=NULL;
  free(p);
 }
 return(elem);
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   ADD()                                                */
/*       OBJECTIVE :  TO PUSH  VERTICES IN THE QUEUE                       */
/*       PARAMETERS : INTEGER                                              */
/*-------------------------------------------------------------------------*/

void add(int ch)
{
  struct queue *p;
  p = (queue*)malloc(sizeof(struct queue));
  p->dat = ch;
  p->link = NULL;
  if(front1 == NULL)
  {
    front1 = p;
    rear = p;
  }
  else
  {
   rear->link = p;
   rear = rear->link;
  }
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   RETN()                                               */
/*       OBJECTIVE :  TO POP THE VERTICES FROM THE QUEUE                   */
/*       RETURN TYPE : INTEGER                                             */
/*-------------------------------------------------------------------------*/

int retn(void)
{
  int num;
  struct queue *q;
  q = front1;
  if(q == NULL)
    getch();
  else
  {
    num = front1->dat;
    front1 = front1->link;
    q->link = NULL;
    free(q);
  }
  return(num);
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   DFS()                                                */
/*       OBJECTIVE :  TO TRAVERSE THE GRAPH USING D.F.S                    */
/*       RETURN TYPE : STRUCT GRAPH* ARRAY , INTEGER N                     */
/*-------------------------------------------------------------------------*/

void dfs(struct graph *start[20],int n)
{
  int i,no,v[20],count=-1;
  struct graph *q;
  front =  NULL;
  printf("\n\n\t=======================================================");
  printf("\n\n\t           DEPTH FIRST SEARCH OF THE GRAPH             ");
  printf("\n\n\t=======================================================");
  printf("\n\n\n\n\n\t\t DEPTH FIRST SEARCH : ");
  if(n == 0)
    printf("\n\n\n\t\tTHE GRAPH IS EMPTY !!");
  else
  {
   for(i=0;i<n;i++)
     v[i] = 0;
   i = 0;
   q = start[i];
   printf("\n\n\n\t\t    %d",q->vert);
   v[i] = 1;
   push(q);
   count++;
   q = q->next;
   if(q == NULL)
     getch();
   else
   {
    do
    {
     do
     {
      while(v[q->vert-1] != 0 && q != NULL)
	q = q->next;
      if(q != NULL)
      {
       printf("  %d",q->vert);
       v[q->vert-1] = 1;
       i = q->vert;
       push(q);
       count++;
       q = start[i-1];
       q = q->next;
      }
     }while(q->next != NULL);
     do
     {
      q = pop();
      count--;
      q = q->next;
      while(v[q->vert-1] != 0 && q != NULL)
	q = q->next;
     }while(q == NULL && count != -1);
    }while(v[q->vert-1] == 0 && q != NULL);
   }
  }
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   BFS()                                                */
/*       OBJECTIVE :  TO TRAVERSE THE GRAPH USING B.F.S                    */
/*       RETURN TYPE : STRUCT GRAPH* ARRAY , INTEGER N                     */
/*-------------------------------------------------------------------------*/

void bfs(struct graph *start[20],int n)
{
  int i,v[20],count=-1,num;
  struct graph *q;
  front1 =  NULL;
  rear = NULL;
  printf("\n\n\t=======================================================");
  printf("\n\n\t           BREADTH FIRST SEARCH OF THE GRAPH           ");
  printf("\n\n\t=======================================================");
  printf("\n\n\n\n\n\t\t BREADTH FIRST SEARCH : ");
  if(n == 0)
    printf("\n\n\n\t\tTHE GRAPH IS EMPTY !!");
  else
  {
   for(i=0;i<n;i++)
     v[i] = 0;
   i = 0;
   q = start[i];
   printf("\n\n\n\t\t    %d",q->vert);
   v[i] = 1;
   q = q->next;
   if(q == NULL)
     getch();
   else
   {
     do
     {
      while(q != NULL)
      {
	if(v[q->vert-1] == 0)
	{
	 add(q->vert);
	 count++;
	}
	q = q->next;
      }
      if(q == NULL)
      {
	num = retn();
	count--;
	if(v[num-1] == 0)
	{
	 q = start[num-1];
	 printf("   %d",q->vert);
	 v[q->vert-1] = 1;
	}
	q = q->next;
      }
     }while(count > -1);
   }
  }
}

/*=========================================================================*/
/*                END        OF        THE       PROGRAM                   */
/*=========================================================================*/
