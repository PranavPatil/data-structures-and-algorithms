/*=========================================================================*/
/*        DATE OF COMPLETION : 15-2-03      CLASS   : SE IT                */
/*=========================================================================*/
/* PROBLEM STATEMENT ::  WRITE A MENU DRIVEN PROGRAM TO PERFORM FOLLOWING  */
/*                       OPERATIONS ON DOUBLY LINK LISTS : CREATE, INSERT  */
/*                       DELETE AND DISPLAY                                */
/*=========================================================================*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<process.h>

struct node
{
  struct node *left;
  int info;
  struct node *right;
};

/*    ***********  DECLARATION    OF    ALL    FUNCTIONS   ***********     */

node* insert(struct node *start);
void display(struct node *start);
node* deletem(struct node *start);

/*=========================================================================*/
/*	    START OF THE MAIN FUNCTION                                     */
/*=========================================================================*/

void main()
{
  struct node *start;
  char ch,ch1;
  int y,no,i;
  start = NULL;
  do
  {
   clrscr();
   printf("\n\n\t=======================================================");
   printf("\n\n\t              **********  MENU  ************");
   printf("\n\n\t=======================================================");
   printf("\n\n\n\n\t\t 1> CREATE DLL ");
   printf("\n\n\t\t 2> INSERT ");
   printf("\n\n\t\t 3> DELETE ");
   printf("\n\n\t\t 4> DISPLAY ");
   printf("\n\n\t\t 5> EXIT    ");
   printf("\n\n\n\t\t  ENTER YOUR CHOICE : ");
   scanf("%c",&ch1);
   switch(ch1)
   {
    case '1':
	      clrscr();
	      start = NULL;
	      printf("\n\n\t===============================================");
	      printf("\n\n\t ****    OPERATION OF CREATION OF DLL    ****");
	      printf("\n\n\t===============================================");
	      printf("\n\n\n\n\tENTER THE NO OF ELEMENTS IN THE DLL : ");
	      scanf("%d",&no);
	      for(i=0;i<no;i++)
		start = insert(start);
	      getch();
	      break;
    case '2':
	      clrscr();
	      printf("\n\n\t===============================================");
	      printf("\n\n\t ****    INSERTION OF ELEMENTS IN DLL    ****");
	      printf("\n\n\t===============================================");
	      printf("\n\n\n\n\tENTRY OF NEW ELEMENTS IN THE DLL \n\n");
	      start = insert(start);
	      getch();
	      break;
    case '3':
	      clrscr();
	      printf("\n\n\t===============================================");
	      printf("\n\n\t ****  DELETION OF THE ELEMENTS IN DLL  ****");
	      printf("\n\n\t===============================================");
	      start = deletem(start);
	      getch();
	      break;
    case '4':
	      clrscr();
	      printf("\n\n\t===============================================");
	      printf("\n\n\t ****  DISPLAYING THE OF ELEMENTS IN DLL  ****");
	      printf("\n\n\t===============================================");
	      printf("\n\n\n\n\tTHE DOUBLY LINKED LIST IS : ");
	      display(start);
	      getch();
	      break;
    case '5':
	      getch();
	      exit(0);
   }
  }while(ch1 != '5');
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   INSERT()                                             */
/*       OBJECTIVE :  TO INSERT THE ELEMENTS OF DLL                        */
/*       PARAMETERS : STRUCT NODE*                                         */
/*-------------------------------------------------------------------------*/

node* insert(struct node *start)
{
 char ch;
 struct node *p,*r;
 p = (node*)malloc(sizeof(struct node));
 printf("\n\n\n\tENTER THE DATA : ");
 scanf("%d",&p->info);
 p->right = NULL;
 p->left = NULL;
 if(start == NULL)
 {
   start = p;
 }
 else
 {
  r = start;
  while(r->right != NULL)
   r = r->right;
  r->right = p;
  p->left = r;
 }
 return(start);
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   DELETEM()                                            */
/*       OBJECTIVE :  TO DELETE THE ELEMENTS OF DLL                        */
/*       PARAMETERS : STRUCT NODE*                                         */
/*-------------------------------------------------------------------------*/

node* deletem(struct node *start)
{
 int num,found=0;
 struct node *q;
 q = start;
 if(q == NULL)
  printf("\n\n\n\n\tTHE DLL IS EMPTY !!");
 else
 {
  printf("\n\n\n\n\tENTER THE NODE TO BE DELETED  : ");
  scanf("%d",&num);
  while((found == 0) && (q != NULL))
  {
    if(q->info == num)
     found=1;
    else
     q=q->right;
  }
  if(found==0)
  {
    printf("\n\n\n\tNUMBER IS NOT PRESENT !!");
    getch();
  }
  else
  {
   if(q == start)
   {
    start = start->right;
    q->right=NULL;
    start->left=NULL;
    free(q);
   }
   else
   {
    (q->right)->left = q->left;
    (q->left)->right = q->right;
    q->left = NULL;
    q->right = NULL;
    free(q);
   }
   printf("\n\n\n\tNUMBER IS SUCCESSFULLY DELETED !!");
  }
 }
 return(start);
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   DISPLAY()                                            */
/*       OBJECTIVE :  TO DISPLAY THE ELEMENTS OF DLL                       */
/*       PARAMETERS : STRUCT NODE*                                         */
/*-------------------------------------------------------------------------*/

void display(struct node *start)
{
  struct node *q;
  q = start;
  if(q == NULL)
   printf("\n\n\n\tTHE DLL IS EMPTY !!");
  else
  {
   printf("\n\n\n\t");
   while(q != NULL)
   {
     printf("  %d",q->info);
     q = q->right;
   }
  }
}
/*=========================================================================*/
/*                END        OF        THE       PROGRAM                   */
/*=========================================================================*/
