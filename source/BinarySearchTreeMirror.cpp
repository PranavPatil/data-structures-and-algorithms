/*=========================================================================*/
/*        ASSIGNMENT NO : 11                 SUBJECT : DSF                 */
/*        DATE OF COMPLETION : 8-3-03      CLASS   : SE IT                 */
/*=========================================================================*/
/* PROBLEM STATEMENT ::  CREATE A BINARY SEARCH TREE AND FIND ITS MIRROR   */
/*                       IMAGE. PRINT THE ORIGINAL AND THE MIRROR IMAGE    */
/*                       USING LEVEL WISE PRINTING                         */
/*=========================================================================*/

#include<stdio.h>
#include<conio.h>
#include<graphics.h>

/*     *************    DECLARATION   OF   STRUCTURE    **************     */

 typedef struct bst
 {
   struct bst *lc,*rc;
   int data;
 }bst;

/*    ***********  DECLARATION    OF    ALL    FUNCTIONS   ***********     */

 void mirror(bst *root);
 void display_levelwise(bst *m[20][20]);
 bst *createnode(void);
 void createbst(bst *root);
 void levelwise(bst *root,bst *m[20][20],int a[20],int level);
 void display(bst *root,int low,int hi,int mid,int y);

/*=========================================================================*/
/*	    START OF THE MAIN FUNCTION                                     */
/*=========================================================================*/

 void main(void)
 {
   bst *root,*r;                  /* DECARATION OF LOCAL VARIABLES */
   int ch,no,i,level;
   root=createnode();             /* CREATE ROOT NODE */
   root->data=32767;
   r=root;
   do
   {
    clrscr();                     /* CLEARS TEXT MODE WINDOW */
    printf("\n\n\t=======================================================");
    printf("\n\n\t              **********  MENU  ************");
    printf("\n\n\t=======================================================");
    printf("\n\n\n\n\n\t\t\t1> ENTER ");
    printf("\n\n\t\t\t2> DISPLAY ");
    printf("\n\n\t\t\t3> MIRROR IMAGE ");
    printf("\n\n\t\t\t4> EXIT    ");
    printf("\n\n\n\t\t\tENTER YOUR CHOICE : ");
    scanf("%d",&ch);
    switch(ch)
    {
     case 1:
	     clrscr();
	     printf("\n\n\t================================================");
	     printf("\n\n\t    ********** DATA ENTRY ************\n\n\t");
	     printf("================================================\n\n");
	     createbst(root);
	     getch();
	     break;
     case 2:
	     root=r;
	     if(root->lc==NULL)
	     printf("\n\n\n\n\t   ENTER THE TREE FIRST !!!");
	     else
	     {
	       int gd=VGA,gm=1;
	       bst *m[20][20]={NULL};
	       int a[20]={0};
	       /* INITIALISES THE GRAPHICS SYSTEM CALLING INITGRAPH FUN */

	       initgraph(&gd,&gm,"c:\\tc\\bgi");
	       cleardevice();
	       setbkcolor(BLACK);          /* SET BACKGROUND COLOUR AS BLACK */
	       setcolor(15);
	       printf("\n\n ORIGINAL TREE IS :\n\t\t");
	       levelwise(root,m,a,-1);
	       display_levelwise(m);       /* DISPLAY TREE LEVELWISE */
	       root=r;
	       display(root,100,640,370,10);
	       getch();
	       closegraph();              /* SHUTS THE GRAPHICS SYSTEM */
	     }
	     break;
     case 3:
	     root=r;
	     if(root->lc==NULL)
	       printf("\n\n\n\n\t   ENTER THE TREE FIRST !!!");
	     else
	     {
	       {
		 int gd=VGA,gm=1;
		 bst *m[20][20]={NULL};
		 int a[20]={0};
		 initgraph(&gd,&gm,"c:\\tc\\bgi");
		 cleardevice();
		 setbkcolor(BLACK);
		 setcolor(15);
		 printf("\n\n ACTUAL TREE IS :");
		 levelwise(root,m,a,-1);
		 display_levelwise(m);
		 root=r;
		 display(root,150,640,320,10);
		 getch();
		 closegraph();
	       }
	       {
		 int gd=VGA,gm=1;
		 bst *m[20][20]={NULL};
		 int a[20]={0};
		 root=r;
		 initgraph(&gd,&gm,"c:\\tc\\bgi");
		 cleardevice();
		 setbkcolor(BLACK);
		 setcolor(15);
		 printf("\n\n THE MIRROR IMAGE OF TREE IS ::\n\t");
		 mirror(root);
		 levelwise(root,m,a,-1);
		 display_levelwise(m);
		 root=r;
		 display(root,0,640,320,10);
		 getch();
		 closegraph();
	       }
	     }
	     break;
     case 4:
	     exit(0);
    }
   }while(ch!=4);
 getch();
 }

/*-------------------------------------------------------------------------*/
/*       FUNCTION :    CREATENODE()                                        */
/*       OBJECTIVE :   TO CREATE THE NODES  ( TO ALLOCATE MEMORY )         */
/*       PARAMETERS :  VOID                                                */
/*       RETURN TYPE : STRUCT BST*					   */
/*-------------------------------------------------------------------------*/

bst *createnode()
{
  bst *new;                 /* DECLARATION OF LOCAL VARIABLES */
  new=(bst*)malloc(sizeof(struct bst));
  new->lc=new->rc=NULL;
  if(new==NULL)
  {
    printf("\n\n\n\n\t   ALLOCATION FAILED  !!");
    getch();
    exit(0);
  }
  return(new);
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   CREATEBST()                                          */
/*       OBJECTIVE :  TO INSERT THE NODES IN THE SEARCH TREE               */
/*       PARAMETERS : STRUCT BST* ROOT ( PTR TO ROOT NODE )                */
/*       RETURN TYPE : VOID              				   */
/*-------------------------------------------------------------------------*/

void createbst(bst *root)
{
  bst *ptr,*new,*cur;             /* DECLARATION OF LOCAL VARIABLES */
  int flag,no,i;
  char ans;
  printf("\n\n\t  ENTER THE NO OF NODES TO BE INSERTED : ");
  scanf("%d",&no);
  new=createnode();
  printf("\n\n\n\n\t ENTER THE ROOT NODE : ");
  scanf("%d",&new->data);
  root->lc=new;
  cur=new;
  for(i=0;i<no-1;i++)
  {
    new=createnode();
    printf("\n\n\n\n\t  ENTER THE DATA  : ");
    scanf("%d",&new->data);
    ptr=cur;
    flag=0;
   do
   {
     if(ptr->data>=new->data)
     {
      if(ptr->lc)
	 ptr=ptr->lc;
      else
      {
	ptr->lc=new;
	flag=1;
      }
     }
     else
     {
      if(ptr->rc)
	ptr=ptr->rc;
      else
      {
	ptr->rc=new;
	flag=1;
      }
     }
   } while(flag==0);
  }
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :    DISPLAY()                                           */
/*       OBJECTIVE :   TO DISPLAY THE SEARCH TREE GRAPHICALLY	           */
/*       PARAMETERS :  PTR TO ROOT,MIN&MAX SIZE OF TEXT SCREEN,            */
/*                     MID OF BOTH & HEIGHT DIFFERENCE BETWEEN 2 NODES     */
/*       RETURN TYPE : VOID			         		   */
/*-------------------------------------------------------------------------*/

 void display(bst *root,int low,int hi,int mid,int y)
 {
   int org;                   /* DECLARATION OF LOCAL VARIABLES */
   char s[5];
   if(root!=NULL)
   {
     org=mid;
     mid=(low+hi)/2;
     if(root->lc)
     display(root->lc,low,mid,mid,y+80);  /* RECURSIVE CALL TO THE FN */
     if(root->rc)
     display(root->rc,mid,hi,mid,y+80);
     circle(mid,y,10);                    /* DRAW A CIRCLE */
     itoa(root->data,s,10);             /* CONVERTS INTEGER TO STRING */
     outtextxy (mid-3,y-3,s);   /* DISPLAYS STR AT SPECIFIED LOCN */
     if(org>mid)
     line(mid+5,y-5,org-5,y-75);        /* DRAW A LINE */
     if(org<mid)
     line(mid-5,y-5,org+5,y-75);
   }
 }

/*-------------------------------------------------------------------------*/
/*       FUNCTION :    LEVELWISE()                                         */
/*       OBJECTIVE :   TO ACCEPT THE SEARCH TREE  IN LEVEL FORMAT          */
/*       PARAMETERS :  PTR TO THE ROOT NODE OF THE TREE                    */
/*       RETURN TYPE : VOID      					   */
/*-------------------------------------------------------------------------*/

 void levelwise(bst *root,bst *m[20][20],int a[20],int level)
 {
  if(root!=NULL)
  {
    level++;
    m[level][a[level]]=root;
    a[level]++;
    levelwise(root->lc,m,a,level);
    levelwise(root->rc,m,a,level);
  }
 }

/*-------------------------------------------------------------------------*/
/*       FUNCTION :    DISPLAY_LEVELWISE()                                 */
/*       OBJECTIVE :   TO DISPLAY THE SEARCH TREE LEVELWISE                */
/*       PARAMETERS :  POINTERS TO THE ARRAY                               */
/*       RETURN TYPE : VOID      					   */
/*-------------------------------------------------------------------------*/

 void display_levelwise(bst *m[20][20])
 {
   int i=0,k;
   while(m[i][0]!=NULL)
   {
     k=0;
     printf("\n\nLEVEL  %d",i);
     while(m[i][k]!=NULL)
     {
       printf("   %d",m[i][k]->data);
       k++;
     }
     printf("\n\n   ");
     i++;
   }
 }

/*-------------------------------------------------------------------------*/
/*       FUNCTION :    MIRROR()                                            */
/*       OBJECTIVE :   TO OBTAIN THE MIRROR IMAGE OF THE SEARCH TREE       */
/*       PARAMETERS :  POINTER TO THE ROOT NODE OF THE TREE                */
/*       RETURN TYPE : VOID     					   */
/*-------------------------------------------------------------------------*/

 void mirror(bst *root)
 {
   bst *temp;
   if(root!=NULL)
   {
     temp=root->lc;          /* TO SWAP THE NODES */
     root->lc=root->rc;
     root->rc=temp;
     mirror(root->lc);       /* RECURSIVE CALL TO THE FUNCTION */
     mirror(root->rc);
   }
 }

/*=========================================================================*/
/*                END        OF        THE       PROGRAM                   */
/*=========================================================================*/
