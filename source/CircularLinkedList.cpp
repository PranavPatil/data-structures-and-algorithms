/*=========================================================================*/
/*        DATE OF COMPLETION : 8-2-03      CLASS   : SE IT                */
/*=========================================================================*/
/* PROBLEM STATEMENT ::  REPRESENT POLYNOMIAL AS CIRCULAR LINKED LIST AND  */
/*                       WRITE A MENU DRIVEN PROGRAM TO PERFORM ADDITION,  */
/*                       MULTIPLICATION AND EVALUATION                     */
/*=========================================================================*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<process.h>
#include<math.h>
#define NULL 0
struct polyn
{
 int no1,no2;
 struct polyn *next;
};
/*    ***********  DECLARATION    OF    ALL    FUNCTIONS   ***********     */

struct polyn *enter_poly(int n,struct polyn *start);
void display_poly(struct polyn *head);
polyn *insert(polyn *list,int x,int y);
void del(struct polyn *head);
polyn *creat(polyn *start,int x,int y);
polyn *creatnode(void);
void attach(polyn *start1,polyn *start2);
void add(struct polyn *p,struct polyn *q);
void multi(struct polyn *head1,struct polyn *head2);
int eval(struct polyn *start,int num);

/*=========================================================================*/
/*	    START OF THE MAIN FUNCTION                                     */
/*=========================================================================*/

void main(void)
{
 int flag1=0,flag2=0,n1,n2,val1,val2,num1,num2;
 char op;
 struct polyn *start1=NULL,*start2=NULL;
 do
 {
  clrscr();
  printf("\n\t============================================");
  printf("\n\n\n\t  ************* MENU *************");
  printf("\n\n\n\t============================================");
  printf("\n\n\n\t1> ENTER THE POLYNOMIALS");
  printf("\n\n\t2> DISPLAY THE POLYNOMIALS");
  printf("\n\n\t3> ADDITION OF POLYNOMIALS");
  printf("\n\n\t4> MULTIPLICATION OF POLYNOMIALS");
  printf("\n\n\t5> EVALUATION OF POLYNOMIALS");
  printf("\n\n\t6> EXIT ");
  printf("\n\n\t ENTER YOUR CHOICE : ");
  scanf("%c",&op);
  switch(op)
  {
   case '1':
	     clrscr();
	     printf("\n\n\t===============================================");
	     printf("\n\n\t   OPERATION ON POLYNOMIALS  ");
	     printf("\n\n\t===============================================");
	     if(flag1==1)
	     {
		del(start1);
		start1->next=start1;
	     }
	     printf("\n\n\n\n  ****>>>     ENTER THE ENTERIES : ");
	     scanf("%d",&n1);
	     printf("\n\n\t ENTER FIRST POLYNOMIAL ");
	     start1= enter_poly(n1,start1);
	     flag1=1;
	     if(flag2==1)
	     {
		del(start2);
		start2->next=start2;
	     }
	     printf("\n\n\t=================================================");
	     printf("\n\n\n  ****>>>     ENTER THE ENTERIES : ");
	     scanf("%d",&n2);
	     printf("\n\n\t ENTER SECOND POLYNOMIAL ");
	     start2= enter_poly(n2,start2);
	     flag2=1;
	     getch();
	     break;
   case '2':
	     clrscr();
	     printf("\n\n\t===============================================");
	     printf("\n\n\t   DISPLAYING THE POLYNOMIALS  ");
	     printf("\n\n\t===============================================");
	     printf("\n\n\n\n\t  POLYNOMIAL 1 \n\n\n\t  ");
	     display_poly(start1);
	     printf("\n\n\n\n\t  POLYNOMIAL 2 \n\n\n\t  ");
	     display_poly(start2);
	     getch();
	     break;
   case '3':
	     clrscr();
	     printf("\n\n\t===============================================");
	     printf("\n\n\t   ADDITION OF POLYNOMIALS  ");
	     printf("\n\n\t===============================================");
	     printf("\n\n\n\n\t  POLYNOMIAL 1 \n\n\n\t  ");
	     display_poly(start1);
	     printf("\n\n\n\n\t  POLYNOMIAL 2 \n\n\n\t  ");
	     display_poly(start2);
	     printf("\n\n\n\n\t  ADDITION OF POLYNOMIAL :\n\n\n\t  ");
	     add(start1,start2);
	     getch();
	     break;
   case '4':
	     clrscr();
	     printf("\n\n\t===============================================");
	     printf("\n\n\t   MULTIPLICATION OF POLYNOMIALS  ");
	     printf("\n\n\t===============================================");
	     printf("\n\n\n\n\t  POLYNOMIAL 1 \n\n\n\t  ");
	     display_poly(start1);
	     printf("\n\n\n\n\t  POLYNOMIAL 2 \n\n\n\t  ");
	     display_poly(start2);
	     printf("\n\n\n\n\t  MULTIPLICATION OF POLYNOMIAL :\n\n\n\t  ");
	     multi(start1,start2);
	     getch();
	     break;
   case '5':
	     clrscr();
	     printf("\n\n\t===============================================");
	     printf("\n\n\t   EVALUATION OF POLYNOMIALS   ");
	     printf("\n\n\t===============================================");
	     printf("\n\n\n\n\t  POLYNOMIAL 1 \n\n\n\t  ");
	     display_poly(start1);
	     printf("\n\n\n\t  ENTER THE VALUE OF X = ");
	     scanf("%d",&num1);
	     val1 = eval(start1,num1);
	     printf("\n\n\n\t  RESULT OF EVALUATION OF POLYNOMIAL 1 = %d",val1);
	     printf("\n\n\n\n\t  POLYNOMIAL 2 \n\n\n\t  ");
	     display_poly(start2);
	     printf("\n\n\n\t  ENTER THE VALUE OF X = ");
	     scanf("%d",&num2);
	     val2 = eval(start2,num2);
	     printf("\n\n\n\t  RESULT OF EVALUATION OF POLYNOMIAL 2 = %d",val2);
	     getch();
	     break;
   case '6':
	     exit(0);
	     break;
  }
 }while(op!='6');
 getch();
}
/*-------------------------------------------------------------------------*/
/*       FUNCTION :   ENTER_POLY()                                         */
/*       OBJECTIVE :  TO ENTER THE POLYNOMIALS                             */
/*       PARAMETERS : INT N ,STRUCT POLYN* HEAD                             */
/*-------------------------------------------------------------------------*/
struct polyn *enter_poly(int n,struct polyn *head)
{
 int i,u,v;
 struct polyn  *pn;
 head=creatnode();
 for(i=0;i<n;i++)
 {
  printf("\n\n\n\tENTER THE CO-EFFIENT : ");
  scanf("%d",&u);
  printf("\n\n\n\tENTER THE DEGREE : ");
  scanf("%d",&v);
  if(head->next==head)
  {
   pn=(polyn*)malloc(sizeof(struct polyn));
   pn->no1=u;
   pn->no2=v;
   pn->next=pn;
   attach(head,pn);
  }
  else
  {
    head=insert(head,u,v);
  }
 }
 return(head);
}
/*-------------------------------------------------------------------------*/
/*       FUNCTION :   DISPLAY_POLY()                                       */
/*       OBJECTIVE :  TO DISPLAY THE POLYNOMIALS                           */
/*       PARAMETERS : STRUCT POLYN  *HEAD                                  */
/*-------------------------------------------------------------------------*/
void display_poly(struct polyn *head)
{
 struct polyn *p,*q,*s;
 q=head->next;
 while(q->next!=head)
 {
   if(q->no2==q->next->no2)
   {
     q->next->no1 = (q->no1) + (q->next->no1);
     s=head->next;
     while(s->next!=q)
       s=s->next;
     s->next=q->next;
     q->next=NULL;
     free(q);
     q=s;
   }
   q=q->next;
 }
 p = head->next;
 if(head==NULL)
  printf("\n\n\n\t     NO POLYNOMIAL TO DISPLAY\n\n\n\t");
 else
 {
  while(p != head)
  {
   if(p->no1!=0)
   {
    if(p->no1 != 1 && p->no2 > 1)
     printf("%dX^%d + ",p->no1,p->no2);
    if(p->no1==1 && p->no2 > 1)
     printf("X^%d +",p->no2);
    if(p->no2 == 1)
     printf("%dX +",p->no1);
    if(p->no2 == 0)
     printf("%d  ",p->no1);
   }
   p = p->next;
  }
  printf("\b\b = 0");
 }
 getch();
}
/*-------------------------------------------------------------------------*/
/*       FUNCTION :   DEL()                                                */
/*       OBJECTIVE :  TO DELETE THE PREVIOUS POLYNOMIALS                   */
/*       PARAMETERS : STRUCT POLYN  *HEAD                                  */
/*-------------------------------------------------------------------------*/
void del(struct polyn *head)
{
  struct polyn *r1,*f;
  if(head->next==head)
  {
   printf("\n\n  NULL");
  }
  else
  {
   r1=head->next;
   while(r1->next!=head)
   {
     r1= head->next;
     f = head->next;
     head = f->next;
     r1->next=r1;
     free(r1);
   }
  }
}
/*-------------------------------------------------------------------------*/
/*       FUNCTION :   ADD()                                                */
/*       OBJECTIVE :  TO ADD TWO POLYNOMIALS                               */
/*       PARAMETERS : STRUCT POLY *P , STRUCT POLYN *Q                     */
/*-------------------------------------------------------------------------*/
void add(struct polyn *p,struct polyn *q)
{
  struct polyn *front=NULL,*t,*z;
  int x,y;
  if(p!=NULL && q!=NULL)
  {
   front=creatnode();
   t=p->next;
   z=q->next;
   while((t != p) && (z != q))
   {
    if(t->no2==z->no2)
    {
       x = t->no1 + z->no1;
       y = t->no2;
       front = creat(front,x,y);
       t = t->next;
       z = z->next;
    }
    if(t->no2 < z->no2)
    {
       x = z->no1;
       y = z->no2;
       front = creat(front,x,y);
       z= z->next;
    }
    if(t->no2 > z->no2)
    {
       x = t->no1;
       y = t->no2;
       front = creat(front,x,y);
       t = t->next;
    }
   }
   if(t==p && z!=q)
   {
     while(z!=q)
     {
      x = z->no1;
      y = z->no2;
      z = z->next;
      front = creat(front,x,y);
     }
   }
   if(t!=p && z==q)
   {
     while(t!=p)
     {
      x = t->no1;
      y = t->no2;
      t = t->next;
      front = creat(front,x,y);
     }
   }
  }
  getch();
  display_poly(front);
}
/*-------------------------------------------------------------------------*/
/*       FUNCTION :   MULTI()                                              */
/*       OBJECTIVE :  TO MULTIPLY TWO POLYNOMIALS                          */
/*       PARAMETERS : STRUCT POLYN *HEAD1 ,STRUCT POLYN *HEAD2             */
/*-------------------------------------------------------------------------*/
void multi(struct polyn *head1,struct polyn *head2)
{
 struct polyn  *s,*d,*start=NULL,*q,*ten;
 int x,y;
 if(head1!=NULL && head2!=NULL)
 {
   start=creatnode();
   d=head2->next,s=head1->next;
   while(s!=head1)
   {
    while(d!=head2)
    {
     x = (d->no1)*(s->no1);
     y = (d->no2)+(s->no2);
     d=d->next;
     if(start->next==start)
     {
      ten=(polyn*)malloc(sizeof(struct polyn));
      ten->no1=x;
      ten->no2=y;
      ten->next=ten;
      attach(start,ten);
     }
     else
     {
      start=insert(start,x,y);
     }
    }
    s=s->next;
    d=head2->next;
   }
 }
 display_poly(start);
 getch();
}
/*-------------------------------------------------------------------------*/
/*       FUNCTION :   CREAT()                                              */
/*       OBJECTIVE :  TO DELETE THE PREVIOUS POLYNOMIALS                   */
/*       PARAMETERS : STRUCT POLYN  *START , INT X , INT Y                 */
/*-------------------------------------------------------------------------*/
polyn *creat(polyn *start,int x,int y)
{
  struct polyn  *q,*temp,*tem;
  temp =(polyn*)malloc(sizeof(struct polyn));
  temp->next=temp;
  temp->no1=x;
  temp->no2=y;
  tem=start;
  if(tem->next==tem)
  {
    start->next = temp;
    temp->next = start;
  }
  else
  {
    while(tem->next != start)
    {
      tem=tem->next;
    }
    tem->next = temp;
    temp->next = start;
  }
  return(start);
}
/*-------------------------------------------------------------------------*/
/*       FUNCTION :   INSERT()                                             */
/*       OBJECTIVE :  TO SORT THE POLYNOMIALS                              */
/*       PARAMETERS : STRUCT POLYN  *LIST ,INT X , INT Y                   */
/*-------------------------------------------------------------------------*/
polyn *insert(polyn *list,int x,int y)
{
  struct polyn *p1,*p2,*p,*s;
  p1=NULL;
  p2=list->next;
  if(p2->next==p2)
    printf("\n\n\n\t     NO POLYNOMIAL TO DISPLAY\n\n\n\t");
  for(;p2->no2 > y;p2=p2->next)
  {
    p1=p2;
    if(p2->next==p2)
    {
     p2=p2->next;
     break;
    }
  }
  p=(polyn*)malloc(sizeof(struct polyn));
  p->no1=x;
  p->no2=y;
  p->next=p2;
  if(p1==NULL)
  {
    attach(p2,p);
  }
  else
  {
     attach(p1->next,p);
  }
  return(list);
}
/*-------------------------------------------------------------------------*/
/*       FUNCTION :   ATTACH()                                             */
/*       OBJECTIVE :  TO ATTACH TWO NODES                                  */
/*       PARAMETERS : STRUCT POLYN  *START1 ,STRUCT  POLYN *TEMP           */
/*-------------------------------------------------------------------------*/
void attach(polyn *start1,polyn *temp)
{
  polyn  *tem=NULL;
  tem=start1;
  if(tem->next==tem)
  {
    start1->next = temp;
    temp->next = start1;
  }
  else
  {
    while(tem->next != start1)
    {
      tem=tem->next;
    }
    tem->next = temp;
    temp->next = start1;
  }
}
/*-------------------------------------------------------------------------*/
/*       FUNCTION :   CREATNODE()                                          */
/*       OBJECTIVE :  TO CREAT A NEW NODE                                  */
/*       PARAMETERS : VOID                                                 */
/*-------------------------------------------------------------------------*/
polyn *creatnode(void)
{
  struct polyn  *q,*p=NULL;
  p =(polyn*)malloc(sizeof(struct polyn));
  if(p==NULL)
  {
    printf("\n\n ALLOCATION FAILED !!");
    exit(0);
  }
  p->next=p;
  p->no1=0;
  p->no2=0;
  return(p);
}
/*-------------------------------------------------------------------------*/
/*       FUNCTION :   EVAL()                                               */
/*       OBJECTIVE :  TO EVALUATE THE  POLYNOMIALS                         */
/*       PARAMETERS : STRUCT POLY*  HEAD                                   */
/*-------------------------------------------------------------------------*/
int eval(polyn *start,int num)
{
  struct polyn *tep;
  int sum=0;
  tep = start->next;
  while(tep != start)
  {
    sum = sum + (tep->no1 * pow(num,tep->no2));
    tep = tep->next;
  }
  return(sum);
}
/*=========================================================================*/
/*                END        OF        THE       PROGRAM                   */
/*=========================================================================*/
