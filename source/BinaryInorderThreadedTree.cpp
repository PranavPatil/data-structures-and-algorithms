/*=========================================================================*/
/*        DATE OF COMPLETION : 13-3-03      CLASS   : SE IT                */
/*=========================================================================*/
/* PROBLEM STATEMENT ::  CREATE A BINARY INORDER THREADED TREE AND PERFORM */
/*                       ALL THREE TRAVERSALS                              */
/*=========================================================================*/
#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<process.h>

typedef struct tree
{
  struct tree *left;
  int dat,lflag,rflag;
  struct tree *right;
}*tr;

struct tree *s,*header=NULL;

/*    ***********  DECLARATION    OF    ALL    FUNCTIONS   ***********     */

tree* getnode(int val);
void insert(tree *s,tree *newn);
void preorder(struct tree *root);
void inorder(struct tree *root);
void postorder(struct tree *root);

/*=========================================================================*/
/*	    START OF THE MAIN FUNCTION                                     */
/*=========================================================================*/

void main(void)
{
 tr t,newn;
 char c;
 int val;
 int choice,i,flag,no;
 char temp1[15];
 struct  tree *s,*root,*r,*q;
 root=NULL;
 do
 {
  clrscr();
  printf("\n\n\t================================================");
  printf("\n\n\n\t         **********  MENU  ************");
  printf("\n\n\n\t================================================");
  printf("\n\n\n\n\t\t  1> ENTER");
  printf("\n\n\t\t  2> DISPLAY");
  printf("\n\n\t\t  3> EXIT");
  printf("\n\n\n\t\t  ENTER THE CHOICE  : ");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1:
	   root=NULL;
	   clrscr();
	   printf("\n\n\t================================================");
	   printf("\n\n\n\t     INSERTION OF NODES OF THE THREADED TREE  ");
	   printf("\n\n\n\t================================================");
	   header = (tree*)malloc(sizeof(struct tree));
	   header->dat = 0;
	   header->left = NULL;
	   printf("\n\n\n\n\t     ENTER THE NO OF NODES TO BE INSERTED : ");
	   scanf("%d",&no);
	   for(i=0;i<no;i++)
	   {
	     printf("\n\n\n\t     ENTER THE DATA  : ");
	     scanf("%d",&val);
	     s = getnode(val);
	     header->lflag = 0;
	     header->rflag = 1;
	     header->right = s;
	     s->left = header;
	     s->right = header;
	     if(root==NULL)
	       root = s;
	     else
	       insert(root,s);
	   }
	   getch();
	   break;

   case 2:
	   do
	   {
	     clrscr();
	     printf("\n\n\t================================================");
	     printf("\n\n\n\t        **********   MENU   ************");
	     printf("\n\n\n\t================================================");
	     printf("\n\n\n\n\t\t 1> PREORDER");
	     printf("\n\n\t\t 2> INORDER");
	     printf("\n\n\t\t 3> POSTORDER");
	     printf("\n\n\t\t 4> EXIT");
	     printf("\n\n\t\t ENTER THE CHOICE : ");
	     scanf("%c",&c);
	     switch(c)
	     {
	      case '1':
			clrscr();
			preorder(root);
			getch();
			break;
	      case '2':
			clrscr();
			inorder(root);
			getch();
			break;
	      case '3':
			clrscr();
			postorder(root);
			getch();
			break;
	      case '4':
			break;
	     }
	   }while(c!='4');
	   break;
   case 3:
	   exit(0);
  }
 }while(choice!=3);
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   INSERT()                                             */
/*       OBJECTIVE :  TO INSERT THE NODES OF THE GRAPH                     */
/*       PARAMETERS : STRUCT TREE*,STRUCT TREE*                            */
/*-------------------------------------------------------------------------*/

void insert(tree *s,tree *newn)
{
 struct tree *t;
 t = s;
 char ans;
 printf("\n\n\n\t     WISH TO INSERT LEFT-RIGHT OF %d : [L|R] : ",s->dat);
 ans = getch();
 if((ans=='L')||(ans=='l'))
 {
   printf("\b  LEFT");
   if(t->lflag == 1)
     insert(t->left,newn);
   else
   {
     newn->left = t->left;
     newn->right = t;
     t->left = newn;
     t->lflag = 1;
   }
 }
 else
 {
   printf("\b  RIGHT");
   if(t->rflag == 1)
     insert(t->right,newn);
   else
   {
     newn->right = t->right;
     newn->left = t;
     t->rflag = 1;
     t->right = newn;
   }
 }
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   GETNODE()                                            */
/*       OBJECTIVE :  TO CREATE A NODE                                     */
/*       PARAMETERS : INTEGER                                              */
/*-------------------------------------------------------------------------*/

tr getnode(int val)
{
 tr p;
 p = (tree*)malloc(sizeof(struct tree));
 p->lflag = 0;
 p->rflag = 0;
 p->dat = val;
 p->left = NULL;
 p->right = NULL;
 return(p);
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   PREORDER()                                           */
/*       OBJECTIVE :  TO TRAVERSE THE THREADED TREE IN PREORDER            */
/*       PARAMETERS : STRUCT TREE*                                         */
/*-------------------------------------------------------------------------*/

void preorder(struct tree *root)
{
  struct tree *temp = root;
  printf("\n\n\t================================================");
  printf("\n\n\n\t   **********  PREORDER TRAVERSAL  **********");
  printf("\n\n\n\t================================================");
  printf("\n\n\n\n\t   PREORDER TRAVERSAL :  %d",temp->dat);
  do
  {
    while(temp->lflag == 1)
    {
       temp = temp->left;
       printf("  %d",temp->dat);
    }
    while(temp->rflag == 0)
    {
       temp = temp->right;
    }
    if(temp->rflag == 1 && temp->dat != 0)
    {
       temp = temp->right;
       printf("  %d",temp->dat);
    }
  }while(temp->dat != 0);
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   INORDER()                                            */
/*       OBJECTIVE :  TO TRAVERSE THE THREADED TREE IN INORDER             */
/*       PARAMETERS : STRUCT TREE*                                         */
/*-------------------------------------------------------------------------*/

void inorder(struct tree *root)
{
  struct tree *temp = root;
  printf("\n\n\t================================================");
  printf("\n\n\n\t   **********  INORDER TRAVERSAL  **********");
  printf("\n\n\n\t================================================");
  printf("\n\n\n\n\t   INORDER TRAVERSAL :");
  do
  {
    while(temp->lflag == 1)
    {
      temp = temp->left;
    }
    while(temp->rflag == 0)
    {
      printf("  %d",temp->dat);
      temp = temp->right;
    }
    if(temp->rflag == 1 && temp->dat != 0)
    {
      printf("  %d",temp->dat);
      temp = temp->right;
    }
  }while(temp->dat != 0);
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   POSTORDER()                                          */
/*       OBJECTIVE :  TO TRAVERSE THE THREADED TREE IN POSTORDER           */
/*       PARAMETERS : STRUCT TREE*                                         */
/*-------------------------------------------------------------------------*/

void postorder(struct tree *root)
{
  struct tree *temp = root;
  int array[30],count=0,i,val=0;
  printf("\n\n\t================================================");
  printf("\n\n\n\t  **********  POSTORDER TRAVERSAL  **********");
  printf("\n\n\n\t================================================");
  printf("\n\n\n\n\t  POSTORDER TRAVERSAL :");
  do
  {
    while(temp->lflag == 1)
    {
      temp = temp->left;
    }
    while(temp->rflag == 0)
    {
      printf("  %d",temp->dat);
      if(temp->dat == array[count-1] && count > -1)
      {
	 val = temp->dat;
	 count--;
	 while(val == array[count] && count > -1)
	 {
	  count--;
	  printf("  %d",array[count]);
	  val = array[count];
	  count--;
	 }
	 count++;
      }
      temp = temp->right;
    }
    if(temp->rflag == 1 && temp->dat != 0)
    {
       array[count] = temp->dat;
       count++;
       temp = temp->right;
       array[count] = temp->dat;
       count++;
    }
    if(temp->dat == 0 && count > -1)
    {
       count--;
       while(temp->dat == 0 && count > -1)
       {
	 count--;
	 printf("  %d",array[count]);
	 count--;
       }
    }
  }while(temp->dat != 0);
}
