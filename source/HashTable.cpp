/*=========================================================================*/
/*        ASSIGNMENT NO : 16                 SUBJECT : DSF                  */
/*        DATE OF COMPLETION : 1-4-03      CLASS   : SE IT                 */
/*=========================================================================*/
/* PROBLEM STATEMENT ::  CREATE A HASH TABLE AND HANDLE  THE COLLISIONS AND*/
/*                       USING LINEAR PROBING WITH OR WITHOUT REPLACEMENT  */
/*=========================================================================*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<process.h>

struct student
{
  char name[10];
  int roll,year;
};

struct node
{
  int data;
  struct student rec;
  struct node *next;
  struct node *tail;
};

/*    ***********  DECLARATION    OF    ALL    FUNCTIONS   ***********     */

node* insert1(struct node*,struct node*);
node* insert2(struct node*,struct node*);
int hash(int roll);
node* search(struct node *root,int temp1);
void display(struct node *head);
node* sort(struct node* r,struct node* p);
node* deleten(struct node *root);
node* get_par(struct node *root,struct node *cur1);
node* get_prev(struct node *root,struct node *cur1);

/*=========================================================================*/
/*	               START OF THE MAIN FUNCTION                          */
/*=========================================================================*/

void main(void)
{
 int i,flag,no,nm;
 char temp1[15],c,choice;
 struct  node *s=NULL,*root=NULL;
 do
 {
  clrscr();
  printf("\n\n\t================================================");
  printf("\n\n\t         **********  MENU  ************");
  printf("\n\n\t================================================");
  printf("\n\n\n\n\t\t  1> ENTER");
  printf("\n\n\t\t  2> DISPLAY");
  printf("\n\n\t\t  3> DELETE ");
  printf("\n\n\t\t  4> SEARCH ");
  printf("\n\n\t\t  5> EXIT");
  printf("\n\n\n\t\t  ENTER THE CHOICE  : ");
  scanf("%c",&choice);
  switch(choice)
  {
   case '1':
	    clrscr();
	    printf("\n\n\t================================================");
	    printf("\n\n\t      ********** DATA ENTRY ************");
	    printf("\n\n\t================================================");
	    printf("\n\n\n\n\t\tENTER THE WAY RECORD'S TO BE INSERTED : ");
	    printf("\n\n\n\n\n\t\t  1> WITH REPLACEMENT");
	    printf("\n\n\n\t\t  2> WITHOUT REPLACEMENT");
	    printf("\n\n\n\n\t\t  ENTER THE CHOICE  : ");
	    scanf("%d",&nm);
	    printf("\n\n\n\t==============================================");
	    printf("\n\n\n\n\t  ENTER THE NO OF STUDENTS TO BE INSERTED : ");
	    scanf("%d",&no);
	    for(i=0;i<no;i++)
	    {
	      s=(node*)malloc(sizeof(struct node));
	      s->next=NULL;
	      s->tail = NULL;
	      printf("\n\n\n\t==============================================");
	      printf("\n\n\n\n\t  ENTER THE NAME OF THE STUDENT  : ");
	      scanf("%s",&s->rec.name);
	      printf("\n\n\n\n\t  ENTER THE ROLL NO  : ");
	      scanf("%d",&s->rec.roll);
	      printf("\n\n\n\n\t  ENTER THE YEAR  : ");
	      scanf("%d",&s->rec.year);
	      if(root==NULL)
	      {
		  s->data = hash(s->rec.roll);
		  root = s;
	      }
	      else
	       if(nm == 1)
		 root = insert1(root,s);
	       else if(nm == 2)
		 root = insert2(root,s);
	    }
	      getch();
	      break;
   case '2':
	      clrscr();
	      display(root);
	      getch();
	      break;
   case '3':
	      clrscr();
	      root = deleten(root);
	      getch();
	      break;
   case '4':
	      int val;
	      char ch;
	      struct node *temp=NULL;
	      do
	      {
	       clrscr();
	       printf("\n\n\t===================================================");
	       printf("\n\n\t     ******     SEARCH OPERATION     ******");
	       printf("\n\n\t===================================================");
	       printf("\n\n\n\n\n\t   ENTER THE ROLL NO TO BE SEARCHED : ");
	       scanf("%d",&val);
	       temp = search(root,val);
	       if(temp==NULL)
		 printf("\n\n\n\n\n\t\t   ELEMENT NOT FOUND !!!\n");
	       else
	       {
		printf("\n\n\n\n\t ********  ELEMENT FOUND  !!!  ********\n");
		printf("\n\n\n\n\t   NAME  =  %s",temp->rec.name);
		printf("\n\n\n\t   ROLL NO = %d",temp->rec.roll,temp->rec.year);
		printf("\n\n\n\t   YEAR = %d",temp->rec.year);
	       }
	       printf("\n\n\n\n\t   MORE ELEMENTS TO BE SEARCHED (Y|N) : ");
	       scanf("%s",&ch);
	      }while(ch=='y' || ch=='Y');
	      getch();
	      break;
   case '5':
	      exit(0);
  }
 }while(choice!='5');
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :    INSERT1()                                           */
/*       OBJECTIVE :   TO INSERT THE RECORDS WITH REPLACEMENT              */
/*       PARAMETERS :  PTR TO FIRST RECORD,PTR TO RECORD TO BE INSERTED    */
/*       RETURN TYPE : STRUCT NODE*					   */
/*-------------------------------------------------------------------------*/

node* insert1(struct node  *r,struct node *p)
{
  struct node *temp=NULL,*cur=NULL,*t;
  int flag=0,i,h;
  p->data = hash(p->rec.roll);
  h = hash(p->rec.roll);
  temp = r;
  while(temp != NULL && flag==0)
  {
    if(temp->data==h)
    { flag = 1;
      cur = temp;  }
    temp = temp->next;
  }
  if(flag==0)
  {
     r = sort(r,p);
  }
  else if(flag==1)
  {
    temp = r;
    p->data = cur->data;
    p->tail = cur;
    if(temp->rec.roll == cur->rec.roll)
    {
      if(cur->next!= NULL)
      {
	p->next = cur->next;
	r = p;
      }
      else if(cur->next== NULL)
	r = p;
     temp = r;
     while(temp->next != NULL)
	temp = temp->next;
     cur->data=hash(p->rec.roll);
     temp->next = cur;
     cur->next = NULL;
    }
    else
    {
     while(temp != NULL && (temp->next->next)->rec.roll == cur->rec.roll)
	temp = temp->next;
     t = temp;
     if(cur->next!= NULL)
     {
       p->next = cur->next;
       t->next = p;
     }
     else if(cur->next== NULL)
       t->next = p;
    }
    temp = r;
    while(temp->next != NULL)
	temp = temp->next;
    cur->data=hash(p->rec.roll);
    temp->next = cur;
    cur->next = NULL;
  }
  return(r);
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :    HASH()                                              */
/*       OBJECTIVE :   TO FIND THE ADDRESS OF THE RECORD                   */
/*       PARAMETERS :  ROLL NUMBER OF THE STUDENT                          */
/*       RETURN TYPE : INTEGER       					   */
/*-------------------------------------------------------------------------*/

int hash(int roll)
{
  int h;
  h = roll%10;
  return(h);
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :    INSERT2()                                           */
/*       OBJECTIVE :   TO INSERT THE RECORDS WITHOUT REPLACEMENT           */
/*       PARAMETERS :  PTR TO FIRST RECORD,PTR TO RECORD TO BE INSERTED    */
/*       RETURN TYPE : STRUCT NODE*					   */
/*-------------------------------------------------------------------------*/

node* insert2(struct node  *r,struct node *p)
{
  struct node *temp=NULL,*cur=NULL;
  int flag=0,i,h;
  h = hash(p->rec.roll);
  temp = r;
  while(temp != NULL && flag==0)
  {
    if(temp->data==h)
    { flag = 1;
      cur = temp;  }
    temp = temp->next;
  }
  if(flag==0)
  {
    r = sort(r,p);
  }
  else if(flag==1)
  {
    temp = r;
    while(temp->next != NULL)
       temp = temp->next;
    p->data=0;
    temp->next = p;
    cur->tail = p;
  }
  return(r);
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :    DISPLAY()                                           */
/*       OBJECTIVE :   TO DISPLAY ALL THE RECORDS                          */
/*       PARAMETERS :  PTR TO THE FIRST RECORD                             */
/*       RETURN TYPE : STRUCT NODE*					   */
/*-------------------------------------------------------------------------*/

void display(struct node *head)
{
  struct node *temp=NULL;
  temp=head;
  printf("\n\n\t===============================================");
  printf("\n\n\t ****    DISPLAYING  THE  RECORD    ****");
  printf("\n\n\t===============================================");
  if(temp==NULL)
  {
    printf("\n\n\n\n\t\t  THE RECORD IS EMPTY  !!!");
    getch();
  }
  else
  {
    temp=head;
    printf("\n\n\n\n\n\n\n\t");
    printf("\tNAME\tROLL NO\t   YEAR\t  HASH");
    while(temp!=NULL)
    { printf("\n\n\n\n\t\t");
      printf(" %s\t  %d\t    %d",temp->rec.name,temp->rec.roll,temp->rec.year);
      printf("\t   %d",temp->data);
      temp=temp->next;
    }
  }
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :    SEARCH()                                            */
/*       OBJECTIVE :   TO SEARCH A RECORD FROM THE SET OF RECORDS          */
/*       PARAMETERS :  PTR TO THE FIRST RECORD                             */
/*       RETURN TYPE : STRUCT NODE*					   */
/*-------------------------------------------------------------------------*/

node* search(struct node *root,int temp1)
{
  char ch;
  int h,flag=0;
  struct node *temp=NULL,*cur;
  temp=root;
  h = hash(temp1);

  while(temp->data != h && temp != NULL)
    temp = temp->next;

  if(temp->data == h)
  {
    while(flag==0 && temp != NULL)
    {
      if(temp->rec.roll == temp1)
	 flag = 1;
      if(temp->rec.roll != temp1)
	 temp = temp->tail;
    }
  }
  if(flag==0)
    temp = NULL;
  return(temp);
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :    SORT()                                              */
/*       OBJECTIVE :   TO SORT THE INSERTED RECORDS                        */
/*       PARAMETERS :  PTR TO THE FIRST RECORD                             */
/*       RETURN TYPE : STRUCT NODE*					   */
/*-------------------------------------------------------------------------*/

node* sort(struct node* r,struct node* p)
{
    int flag=0;
    struct node *temp;
    p->data = hash(p->rec.roll);
    p->tail = NULL;
    temp = r;
    while(temp != NULL && flag==0)
    {
     if(temp->next!=NULL && p->data > temp->data && p->data < temp->next->data)
     {
       p->next = temp->next;
       temp->next = p;
       flag = 1;
     }
     else if(p->data > temp->data && temp->next==NULL)
     {
       flag = 1;
       p->next = NULL;
       temp->next = p;
     }
     else if(p->data < temp->data)
     {
       flag = 1;
       p->next = temp;
       r = p;
     }
     temp =  temp->next;
    }
    return(r);
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :    DELETEN()                                           */
/*       OBJECTIVE :   TO DELETE A RECORD                                  */
/*       PARAMETERS :  PTR TO THE ROOT                                     */
/*       RETURN TYPE : STRUCT NODE*					   */
/*-------------------------------------------------------------------------*/

node* deleten(struct node *root)
{
  int no;
  struct node *temp,*par=NULL,*cur1=NULL;
  struct node *p,*s;
  printf("\n\n\t===================================================");
  printf("\n\n\t*****  DELETION OF NODE FROM THE SEARCH TREE  *****");
  printf("\n\n\t===================================================");
  printf("\n\n\n\n\n\n\t  ENTER THE ROLL NO OF STUDENT TO BE DELETED :  ");
  scanf("%d",&no);
  cur1 = search(root,no);
  if(cur1==NULL)
    printf("\n\n\n\n\n\t\t  ELEMENT NOT FOUND !!!\n");
  else if(cur1!=NULL)
  {
   printf("\n\n\n\t  ELEMENT  %d  SUCCESSFULLY DELETED !!\n",cur1->rec.roll);
   par = get_par(root,cur1);
   p = NULL;
   if(par==NULL)
   {
    if(cur1->tail!=NULL)
    {
      cur1->tail->data = cur1->data;
      s = get_prev(root,cur1->tail);
      s->next = cur1->tail->next;
      cur1->tail->next = cur1->next;
      if(cur1->rec.roll != root->rec.roll)
      { p = get_prev(root,cur1);
	p->next = cur1->tail;
      }
      else if(cur1->rec.roll == root->rec.roll)
	root = cur1->tail;
      cur1->next = NULL;
      free(cur1);
    }
    else if(cur1->tail==NULL)
    {
      if(cur1->rec.roll != root->rec.roll)
      { p = get_prev(root,cur1);
	p->next = cur1->next;
      }
      else if(cur1->rec.roll == root->rec.roll)
	root = root->next;
      cur1->next = NULL;
      free(cur1);
    }
   }
   else if(par!=NULL)
   {
    if(cur1->tail!=NULL)
    {
      par->tail = cur1->tail;
      s = get_prev(root,cur1->tail);
      s->next = cur1->tail->next;
      p = get_prev(root,cur1);
      p->next = cur1->tail;
      cur1->tail->next = cur1->next;
      cur1->next = NULL;
      free(cur1);
    }
    else if(cur1->tail==NULL)
    {
      par->tail = NULL;
      p = get_prev(root,cur1);
      p->next = cur1->next;
      cur1->next = NULL;
      free(cur1);
    }
   }
  }
  return(root);
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :    GET_PAR()                                           */
/*       OBJECTIVE :   TO OBTAIN THE PREVIOUS RECORD OF SAME HASH VALUE    */
/*       PARAMETERS :  PTR TO ROOT,PTR TO RECORD                           */
/*       RETURN TYPE : STRUCT NODE*					   */
/*-------------------------------------------------------------------------*/

node* get_par(struct node *root,struct node *cur1)
{
  int flag=0;
   struct node *temp = root,*par;
   while(temp->data != cur1->data && temp != NULL)
     temp = temp->next;
   if(temp->data == cur1->data)
   {
     while(flag==0 && temp != NULL)
     {
      if(temp->tail->rec.roll == cur1->data)
	 flag = 1;
      if(temp->tail->rec.roll != cur1->data)
	 temp = temp->tail;
     }
   }
  if(flag==0)
    par = NULL;
  if(flag==1)
    par = temp;
  return(par);
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :    GET_PREV()                                          */
/*       OBJECTIVE :   TO OBTAIN THE PREVIOUS RECORD                       */
/*       PARAMETERS :  PTR TO ROOT,PTR TO RECORD                           */
/*       RETURN TYPE : STRUCT NODE*					   */
/*-------------------------------------------------------------------------*/

node* get_prev(struct node *root,struct node *cur1)
{
  int flag=0;
  struct node *temp = root,*p;
  while(temp->next!=NULL && flag==0)
  {
    if(temp->next==cur1)
       flag=1;
    else if(temp->next!=cur1)
       temp = temp->next;
  }
  if(flag==1)
    p = temp;
  if(flag==0)
    p = NULL;
  return(p);
}

/*=========================================================================*/
/*                END        OF        THE       PROGRAM                   */
/*=========================================================================*/
