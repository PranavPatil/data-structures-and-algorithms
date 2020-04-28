/*=========================================================================*/
/*        DATE OF COMPLETION : 27-2-03      CLASS   : SE IT                */
/*=========================================================================*/
/* PROBLEM STATEMENT ::  IMPLEMENT BINARY SEARCH TREE AS AN ABSTRACT DATA  */
/*                       TYPE                                              */
/*=========================================================================*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<process.h>

 struct node
 {
  struct node *left;
  int data;
  struct node *right;
 };

/*    ***********  DECLARATION    OF    ALL    FUNCTIONS   ***********     */

 node* insert(struct node*,struct node*);
 void recurpre(node *cur);
 void recurin(node *cur);
 void recurpost(node *cur);
 void recur(struct node *root);
 void search(struct node *root);
 node* deleten(struct node *root);
 node* leftmost_right(struct node *temp);
 node* findparent(struct node *root,struct node *temp);
 node* insert_node(struct node* root);

/*=========================================================================*/
/*	    START OF THE MAIN FUNCTION                                     */
/*=========================================================================*/

 void main()
 {
   int c,i,flag,no,temp1,num;
   char choice;
   struct node *s,*root,*r,*q;
   root=NULL;
   do
   {
    clrscr();
    printf("\n\n\t=======================================================");
    printf("\n\n\t              **********  MENU  ************");
    printf("\n\n\t=======================================================");
    printf("\n\n\n\n\n\t\t\t1> ENTER ");
    printf("\n\n\t\t\t2> DELETE ");
    printf("\n\n\t\t\t3> INSERT ");
    printf("\n\n\t\t\t4> SEARCH ");
    printf("\n\n\t\t\t5> DISPLAY ");
    printf("\n\n\t\t\t6> EXIT    ");
    printf("\n\n\n\t\t\tENTER YOUR CHOICE : ");
    scanf("%c",&choice);
    switch(choice)
    {
     case '1':
	       root=NULL;
	       clrscr();
	       printf("\n\n\t================================================");
	       printf("\n\n\t    ********** DATA ENTRY ************\n\n\t");
	       printf("================================================\n\n");
	       printf("\n\n\t  ENTER THE NO OF NODES TO BE INSERTED : ");
	       scanf("%d",&no);
	       for(i=0;i<no;i++)
	       {
		s=(node*)malloc(sizeof(struct node));
		s->left=NULL;
		s->right=NULL;
		printf("\n\n\n\n\t  ENTER THE DATA  : ");
		scanf("%d",&s->data);
		if(root==NULL)
		 root = s;
		else
		 root = insert(root,s);
	       }
	       break;

     case '2':
	      clrscr();
	      root = deleten(root);
	      getch();
	      break;
     case '3':
	      clrscr();
	      root = insert_node(root);
	      getch();
	      break;
     case '4':
	      clrscr();
	      search(root);
	      getch();
	      break;
     case '5':
	      clrscr();
	      recur(root);
	      break;

     case '6':
	      exit(0);
  }
 }while(choice!=3);
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   INSERT()                                             */
/*       OBJECTIVE :  TO INSERT THE NODES IN THE SEARCH TREE               */
/*       PARAMETERS : STRUCT NODE*,STRUCT NODE*                            */
/*       RETURN TYPE : STRUCT NODE*					   */
/*-------------------------------------------------------------------------*/

node* insert(struct node  *r,struct node *p)
{
   if((r->right == NULL) && (p->data > r->data))
   {
     r->right = p;
   }
   else
     if((r->right != NULL) && (p->data > r->data))
     {
       insert(r->right,p);
     }
   if((r->left == NULL) && (p->data < r->data))
   {
     r->left = p;
   }
   else
     if((r->left != NULL) && (p->data < r->data))
     {
       insert(r->left,p);
     }
     return(r);
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   RECUR()                                              */
/*       OBJECTIVE :  TO DISPLAY SEARCH TREE IN PREORDER,INORDER,POSTORDER */
/*       PARAMETERS : STRUCT NODE*                                         */
/*-------------------------------------------------------------------------*/

void recur(struct node *root)
{
  char c;
  do
  {
    clrscr();
    printf("\n\n\t================================================");
    printf("\n\n\n\t        **********  MENU  ************");
    printf("\n\n\n\t================================================");
    printf("\n\n\n\n\t\t    1> PREORDER");
    printf("\n\n\t\t    2> INORDER");
    printf("\n\n\t\t    3> POSTORDER");
    printf("\n\n\t\t    4> EXIT");
    printf("\n\n\n\t\t    ENTER THE CHOICE : ");
    scanf("%s",&c);
    if(root==NULL)
       printf("\n\n\t\t TREE NOT STARTED YET");
    switch(c)
    {
      case '1':
		clrscr();
		printf("\n\n\t==============================================");
		printf("\n\n\n\t **********  PREORDER TRAVERSAL  ********** ");
		printf("\n\n\n\t============================================");
		printf("\n\n\n\n\t   PREORDER TRAVERSAL : ");
		recurpre(root);
		getch();
		break;
      case '2':
		clrscr();
		printf("\n\n\t==============================================");
		printf("\n\n\n\t **********  INORDER TRAVERSAL  ********** ");
		printf("\n\n\n\t============================================");
		printf("\n\n\n\n\t   INORDER TRAVERSAL : ");
		recurin(root);
		getch();
		break;
      case '3':
		clrscr();
		printf("\n\n\t==============================================");
		printf("\n\n\n\t *********  POSTORDER TRAVERSAL  ********* ");
		printf("\n\n\n\t============================================");
		printf("\n\n\n\n\t   POSTORDER TRAVERSAL : ");
		recurpost(root);
		getch();
		break;
      case '4':
		break;
    }
  }while(c!='4');
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   RECURPRE()                                           */
/*       OBJECTIVE :  TO TRAVERSE THE SEARCH TREE IN PREORDER              */
/*       PARAMETERS : STRUCT NODE*                                         */
/*-------------------------------------------------------------------------*/

void recurpre(node *cur)
{
   if(cur!=NULL)
   {
     printf("%d  ",cur->data);
      recurpre(cur->left);
      recurpre(cur->right);
   }
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   RECURIN()                                            */
/*       OBJECTIVE :  TO TRAVERSE THE SEARCH TREE IN INORDER               */
/*       PARAMETERS : STRUCT NODE*                                         */
/*-------------------------------------------------------------------------*/

void recurin(node *cur)
{
   if(cur!=NULL)
   {
     recurin(cur->left);
     printf("%d  ",cur->data);
     recurin(cur->right);
   }
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   RECURPOST()                                          */
/*       OBJECTIVE :  TO TRAVERSE THE SEARCH TREE IN POSTORDER             */
/*       PARAMETERS : STRUCT NODE*                                         */
/*-------------------------------------------------------------------------*/

void recurpost(node *cur)
{
   if(cur!=NULL)
   {
     recurpost(cur->left);
     recurpost(cur->right);
     printf("%d  ",cur->data);
   }
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   SEARCH()                                             */
/*       OBJECTIVE :  TO SEARCH THE NODES FROM THE SEARCH TREE             */
/*       PARAMETERS : STRUCT NODE*                                         */
/*-------------------------------------------------------------------------*/

void search(struct node *root)
{
  char ch;
  int i,temp1;
  struct node *s;
  do
  {
    clrscr();
    printf("\n\n\t===================================================");
    printf("\n\n\t     ******     SEARCH OPERATION     ******");
    printf("\n\n\t===================================================");
    printf("\n\n\n\n\t  ENTER THE NAME TO BE SEARCHED : ");
    scanf("%d",&temp1);
    i=0;
    s=root;
    while(s != NULL && i==0)
    {
     if(s->data<temp1)
      s = s->right;
     if(s->data>temp1)
      s = s->left;
     if(s->data==temp1)
      i=1;
    }
    if(i==0)
     printf("\n\n\t  ELEMENT NOT FOUND \n");
    else
     printf("\n\n\t  ELEMENT FOUND =  %d\n",s->data);
    printf("\n\n\t  MORE ELEMENTS TO BE SEARCHED (Y|N) : ");
    scanf("%s",&ch);
  }while(ch=='y' || ch=='Y');
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   DELETEN()                                            */
/*       OBJECTIVE :  TO DELETE THE NODES IN THE SEARCH TREE               */
/*       PARAMETERS : STRUCT NODE*,INTEGER NO                              */
/*       RETURN TYPE : STRUCT NODE*  [ROOT]                                */
/*-------------------------------------------------------------------------*/

node* deleten(struct node *root)
{
  int i,no;
  struct node *temp,*par=NULL,*cur=NULL;
  struct node *s;
  i=0;
  s=root;
  printf("\n\n\t===================================================");
  printf("\n\n\t*****  DELETION OF NODE FROM THE SEARCH TREE  *****");
  printf("\n\n\t===================================================");
  printf("\n\n\n\n\t  ENTER THE ELEMENT TO BE DELETED :  ");
  scanf("%d",&no);
  while(s != NULL && i==0)
  {
    if(s->data<no)
     s = s->right;
    if(s->data>no)
     s = s->left;
    if(s->data==no)
    {
     i=1;
     temp = s;
    }
  }
  if(i==0)
    printf("\n\n\t  ELEMENT NOT FOUND \n");
  else
  {
     printf("\n\n\t  ELEMENT  %d  SUCCESSFULLY DELETED !!\n",temp->data);
   par = findparent(root,temp);
   if(par->left == temp)
   {
    if(temp->right !=NULL)
    {
     cur = leftmost_right(temp);
     cur->left = temp->left;
     par->left = temp->right;
    }
    else
     par->left = temp->left;
   }
   else if(par->right == temp)
   {
    if(temp->right!=NULL)
    {
     cur = leftmost_right(temp);
     cur->left = temp->left;
     par->right = temp->right;
    }
   }
   else
    par->right = temp->left;
   free(temp);
  }
  return(root);
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   LEFTMOST_RIGHT()                                     */
/*       OBJECTIVE :  TO INSERT THE NODES IN THE SEARCH TREE               */
/*       PARAMETERS : STRUCT NODE*                                         */
/*       RETURN TYPE : STRUCT NODE*  [LEFTMOST RIGHT NODE]                 */
/*-------------------------------------------------------------------------*/

node* leftmost_right(struct node *temp)
{
  temp = temp->right;
  while(temp->left != NULL)
  {
    temp = temp->left;
  }
  return(temp);
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   FINDPARENT()                                         */
/*       OBJECTIVE :  TO FIND THE PARENT OF NODE IN THE SEARCH TREE        */
/*       PARAMETERS : STRUCT NODE*,STRUCT NODE*		      	           */
/*       RETURN TYPE : STRUCT NODE*  [PARENT]                              */
/*-------------------------------------------------------------------------*/

node* findparent(struct node *root,struct node *temp)
{
  int i=0;
  struct node *s=root,*et;
  while(s != NULL && i==0)
  {
    if(s->data<temp->data)
    {
      et = s;
      s = s->right;
    }
    if(s->data>temp->data)
    {
      et = s;
      s = s->left;
    }
    if(s->data==temp->data)
      i=1;
  }
  return(et);
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   INSERT_NODE()                                        */
/*       OBJECTIVE :  TO INSERT THE NODES IN THE SEARCH TREE               */
/*       PARAMETERS : STRUCT NODE*                                         */
/*-------------------------------------------------------------------------*/

node* insert_node(struct node* root)
{
 int flag=0,m;
 struct node *temp = root;
 struct node *p=NULL;
 p = (node*)malloc(sizeof(struct node));
 p->left = NULL;
 p->right = NULL;
 printf("\n\n\t===================================================");
 printf("\n\n\t******    INSERTION OF NODE IN SEARCH TREE     ******");
 printf("\n\n\t===================================================");
 printf("\n\n\n\n\t  ENTER THE ELEMENT TO BE INSERTED :  ");
 scanf("%d",&p->data);
 m = p->data;
 printf("%d",p->data);
 while(flag != 1)
 {
  if(temp->data>p->data)
  {
    if(temp->left != NULL)
    {
      if(temp->left->data<p->data)
      {
	p->left = temp->left;
	if(temp->left->right->data>p->data)
	{
	  p->right = temp->left->right;
	  temp->left->right = NULL;
	}
	else
	  p->right = NULL;
	temp->left = p;
	flag = 1;
      }
      else
	temp = temp->left;
    }
    else
    {
      temp->left =  p;
      flag =1;
    }
  }
  if(temp->data<p->data)
  {
    if(temp->right != NULL)
    {
      if(temp->right->data>p->data)
      {
	p->right = temp->right;
	if(temp->right->left->data<p->data)
	{
	  p->left = temp->right->left;
	  temp->right->left = NULL;
	}
	else
	  p->left = NULL;
	temp->right = p;
	flag = 1;
      }
      else
	temp = temp->right;
    }
    else
    {
      temp->right =  p;
      flag =1;
    }
  }
 }
 printf("\n\n\t  ELEMENT  %d  SUCCESSFULLY INSERTED !!\n",m);
 return(root);
}
/*=========================================================================*/
/*                END        OF        THE       PROGRAM                   */
/*=========================================================================*/
