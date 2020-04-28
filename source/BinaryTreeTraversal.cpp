/*=========================================================================*/
/*        ASSIGNMENT NO : 7                 SUBJECT : DSF                  */
/*        DATE OF COMPLETION : 19-2-03      CLASS   : SE IT                */
/*=========================================================================*/
/* PROBLEM STATEMENT ::  WRITE A PROGRAM TO CREATE A BINARY TREE  AND      */
/*                       PERFORM RECURSIVE AND NON-RECURSIVE  TRAVERSALS   */
/*=========================================================================*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<process.h>

struct node
{
 struct node *left;
 char data[10];
 struct node *right;
};

struct stack
{
  struct node *dat;
  struct stack *next;
};

/*    ***********  DECLARATION    OF    ALL    FUNCTIONS   ***********     */

node* insert(struct node *,struct node *);
void recurpre(node *cur);
void recurin(node *cur);
void recurpost(node *cur);
void recur(struct node *root,int ch);
void nonrecurpre(struct node *root);
void nonrecurin(struct node *root);
void nonrecurpost(struct node *root);
node* pop(struct stack **front);
void push(struct node *tem,struct stack **front);
void display_stack();

/*=========================================================================*/
/*	               START OF THE MAIN FUNCTION                          */
/*=========================================================================*/

void main(void)
{
 int choice,i,flag,no;
 char temp1[15],c;
 struct  node *s,*root,*r,*q;
 root=NULL;
 do
 {
  clrscr();
  printf("\n\n\t================================================");
  printf("\n\n\t         **********  MENU  ************");
  printf("\n\n\t================================================");
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
	   printf("\n\n\t      ********** DATA ENTRY ************");
	   printf("\n\n\t================================================");
	   printf("\n\n\n\n\tENTER THE NO OF NODES TO BE INSERTED : ");
	   scanf("%d",&no);
	   for(i=0;i<no;i++)
	   {
	     s=(node*)malloc(sizeof(struct node));
	     s->left=NULL;
	     s->right=NULL;
	     printf("\n\n\n\n\tENTER THE DATA  : ");
	     scanf("%s",&s->data);
	     if(root==NULL)
	       root = s;
	     else
	       root = insert(root,s);
	   }
	   break;

   case 2:
	   do
	   {
	     int ch=0;
	     clrscr();
	     printf("\n\n\t================================================");
	     printf("\n\n\t        **********   MENU   ************");
	     printf("\n\n\t================================================");
	     printf("\n\n\n\n\t\t 1> RECURSIVE");
	     printf("\n\n\t\t 2> NON-RECURSIVE");
	     printf("\n\n\t\t 3> EXIT");
	     printf("\n\n\t\t ENTER THE CHOICE : ");
	     scanf("%c",&c);
	     switch(c)
	     {
	      case '1':
			ch=1;
			recur(root,ch);
			break;
	      case '2':
			ch=2;
			recur(root,ch);
			break;
	      case '3':
			break;
	     }
	   }while(c!='3');
	   break;
   case 3:
	   exit(0);
  }
 }while(choice!=3);
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   INSERT()                                             */
/*       OBJECTIVE :  TO INSERT THE NODES IN THE BINARY TREE               */
/*       PARAMETERS : STRUCT NODE*,STRUCT NODE*                            */
/*       RETURN TYPE : STRUCT NODE*					   */
/*-------------------------------------------------------------------------*/

node* insert(struct node  *r,struct node *p)
{
  char ans;
  int flag=0,i;
  printf("\n\n\n\n\tWISH TO INSERT LEFT-RIGHT OF %s : [L|R] : ",r->data);
  do
  {
    ans=getch();
    if((ans=='R')||(ans=='r'))
    {
      flag = 1;
      printf("\b  RIGHT");
      if(r->right==NULL)
	r->right=p;
      else
	insert(r->right,p);
    }
    else if(ans=='L' || ans=='l')
    {
      flag = 1;
      printf("\b  LEFT");
      if(r->left==NULL)
	r->left=p;
      else
	insert(r->left,p);
    }
  }while(flag != 1);
  return(r);
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   RECUR()                                              */
/*       OBJECTIVE :  TO DISPLAY BINARY TREE IN PREORDER,INORDER,POSTORDER */
/*       PARAMETERS : STRUCT NODE* ,INTEGER CH                             */
/*-------------------------------------------------------------------------*/

void recur(struct node *root,int ch)
{
  char c;
  do
  {
    clrscr();
    printf("\n\n\t================================================");
    printf("\n\n\t         **********  MENU  ************");
    printf("\n\n\t================================================");
    printf("\n\n\n\n\t\t 1> PREORDER");
    printf("\n\n\t\t 2> INORDER");
    printf("\n\n\t\t 3> POSTORDER");
    printf("\n\n\t\t 4> EXIT");
    printf("\n\n\t\t ENTER THE CHOICE : ");
    scanf("%s",&c);
    if(root==NULL)
       printf("\n\n\t\t TREE NOT STARTED YET");
    switch(c)
    {
      case '1':
		if(ch==1)
		{
		 clrscr();
		 printf("\n\n\t============================================");
		 printf("\n\n\n\t*****  RECURSIVE PREORDER TRAVERSAL  *****");
		 printf("\n\n\n\t============================================");
		 printf("\n\n\n\n\t  PREORDER TRAVERSAL : ");
		 recurpre(root);
		}
		if(ch==2)
		 nonrecurpre(root);
		getch();
		break;
      case '2':
		if(ch==1)
		{
		 clrscr();
		 printf("\n\n\t============================================");
		 printf("\n\n\n\t*****   RECURSIVE INORDER TRAVERSAL  *****");
		 printf("\n\n\n\t============================================");
		 printf("\n\n\n\n\t  INORDER TRAVERSAL : ");
		 recurin(root);
		}
		if(ch==2)
		 nonrecurin(root);
		getch();
		break;
      case '3':
		if(ch==1)
		{
		 clrscr();
		 printf("\n\n\t============================================");
		 printf("\n\n\n\t*****  RECURSIVE POSTORDER TRAVERSAL *****");
		 printf("\n\n\n\t============================================");
		 printf("\n\n\n\n\t  POSTORDER TRAVERSAL : ");
		 recurpost(root);
		}
		if(ch==2)
		 nonrecurpost(root);
		getch();
		break;
      case '4':
		break;
    }
  }while(c!='4');
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   RECURPRE()                                           */
/*       OBJECTIVE :  TO TRAVERSE THE BINARY TREE IN PREORDER RECURSIVELY  */
/*       PARAMETERS : STRUCT NODE*                                         */
/*-------------------------------------------------------------------------*/

void recurpre(node *cur)
{
   if(cur!=NULL)
   {
     printf("%s  ",cur->data);
      recurpre(cur->left);
      recurpre(cur->right);
   }
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   RECURIN()                                            */
/*       OBJECTIVE :  TO TRAVERSE THE BINARY TREE IN INORDER RECURSIVELY   */
/*       PARAMETERS : STRUCT NODE*                                         */
/*-------------------------------------------------------------------------*/

void recurin(node *cur)
{
   if(cur!=NULL)
   {
     recurin(cur->left);
     printf("%s  ",cur->data);
     recurin(cur->right);
   }
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   RECURPOST()                                          */
/*       OBJECTIVE :  TO TRAVERSE THE BINARY TREE IN POSTORDER RECURSIVELY */
/*       PARAMETERS : STRUCT NODE*                                         */
/*-------------------------------------------------------------------------*/

void recurpost(node *cur)
{
   if(cur!=NULL)
   {
     recurpost(cur->left);
     recurpost(cur->right);
     printf("%s  ",cur->data);
   }
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   RECURPRE()                                           */
/*       OBJECTIVE :  TO TRAVERSE BINARY TREE IN PREORDER NON-RECURSIVELY  */
/*       PARAMETERS : STRUCT NODE*                                         */
/*-------------------------------------------------------------------------*/

void nonrecurpre(struct node *root)
{
  struct node *temp;
  struct stack *front;
  temp=root;
  clrscr();
  printf("\n\n\t================================================");
  printf("\n\n\n\t***     NON-RECURSIVE  PREORDER TRAVERSAL    ***");
  printf("\n\n\n\t================================================");
  printf("\n\n\n\n\t   PREORDER TRAVERSAL : ");
  push(NULL,&front);
  while(temp != NULL)
  {
    while(temp != NULL)
    {
      printf("%s   ",temp->data);
      if(temp->right != NULL)
      {
	push(temp->right,&front);
      }
      temp = temp->left;
    }
    temp = pop(&front);
  }
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   RECURIN()                                            */
/*       OBJECTIVE :  TO TRAVERSE BINARY TREE IN INORDER NON-RECURSIVELY   */
/*       PARAMETERS : STRUCT NODE*                                         */
/*-------------------------------------------------------------------------*/

void nonrecurin(struct node *root)
{
  struct node *cur;
  struct stack *st;
  clrscr();
  printf("\n\n\t================================================");
  printf("\n\n\n\t***      NON-RECURSIVE INORDER TRAVERSAL     ***");
  printf("\n\n\n\t================================================");
  printf("\n\n\n\n\t   INORDER TRAVERSAL : ");
  push(NULL,&st);
  cur=root;
  while(cur != NULL)
  {
    while(cur != NULL)
    {
      push(cur,&st);
      cur=cur->left;
    }
    cur = pop(&st);
    while(cur != NULL)
    {
      printf(" %s ",cur->data);
      if(cur->right!=NULL)
      {
	cur = cur->right;
	break;
      }
      else
       cur = pop(&st);
    }
  }
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   RECURPOST()                                          */
/*       OBJECTIVE :  TO TRAVERSE BINARY TREE IN POSTORDER NON-RECURSIVELY */
/*       PARAMETERS : STRUCT NODE*                                         */
/*-------------------------------------------------------------------------*/

void nonrecurpost(struct node *root)
{
  int flag=0,ch=0,m=0;
  struct node *temp1,*temp2,*cur=root;
  struct stack *stk;
  clrscr();
  printf("\n\n\t================================================");
  printf("\n\n\n\t ***    NON-RECURSIVE POSTORDER TRAVERSAL    ***");
  printf("\n\n\n\t================================================");
  printf("\n\n\n\n\t  POSTORDER TRAVERSAL : ");
  push(NULL,&stk);
  while(cur!=NULL)
  {
   if(cur->right==NULL && cur->left==NULL && m==0)
   {
     printf(" %s",cur->data);
     break;
   }
   else
   {
    m=1;
    while(cur->left!=NULL && ch==0)
    {
      push(cur,&stk);
      cur=cur->left;
      if(cur->left==NULL)
	push(cur,&stk);
    }
    if(cur->right!=NULL)
    {
      push(cur,&stk);
      cur = cur->right;
      ch=0;
      if(cur->right==NULL && cur->left==NULL)
	push(cur,&stk);
    }
    else
    {
      do
      {
	if(flag==1 && temp2 != NULL)
	{
	  temp1=temp2;
	  temp2=pop(&stk);
	  cur=temp2;
	  if(temp2->right->data==temp1->data || temp2->right!=NULL || temp2->left!=NULL)
	    printf("  %s",temp1->data);
	}
	if(flag==0)
	{
	  temp1=pop(&stk);
	  temp2=pop(&stk);
	  flag=1;
	  cur=temp2;
	  printf("  %s",temp1->data);
	}
      }while(temp2->right->data==temp1->data && temp2 != NULL);
      ch=1;
    }
   }
  }
}
/*-------------------------------------------------------------------------*/
/*       FUNCTION :   PUSH()                                               */
/*       OBJECTIVE :  TO PUSH THE NODES OF THE BINARY TREE ON THE STACK    */
/*       PARAMETERS : STRUCT NODE* , STRUCT STACK**                        */
/*-------------------------------------------------------------------------*/

void push(struct node *tem,struct stack **front1)
{
 struct stack *p=NULL;
 p = (stack*)malloc(sizeof(struct stack));
 p->dat=tem;
 p->next = NULL;
 if(*front1 == NULL)
 {
  *front1=p;
 }
 else
 {
   p->next=*front1;
   *front1=p;
 }
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   POP()                                                */
/*       OBJECTIVE :  TO POP THE ELEMENTS FROM THE STACK                   */
/*       PARAMETERS : STRUCT STACK**                                       */
/*       RETURN TYPE : STRUCT NODE                                         */
/*-------------------------------------------------------------------------*/

node* pop(struct stack **front1)
{
 struct stack *p=NULL,*front;
 struct node *elem=NULL;
 p = *front1;
 if(p == NULL)
  getch();
 else
 {
  front  = *front1;
  elem=front->dat;
  *front1=front->next;
  p->next=NULL;
  free(p);
 }
 return(elem);
}

/*=========================================================================*/
/*                END        OF        THE       PROGRAM                   */
/*=========================================================================*/
