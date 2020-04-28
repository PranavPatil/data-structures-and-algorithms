/*=========================================================================*/
/*        ASSIGNMENT NO : 10                 SUBJECT : DSF                 */
/*        DATE OF COMPLETION : 4-3-03      CLASS   : SE IT                 */
/*=========================================================================*/
/* PROBLEM STATEMENT ::  CREATE A BINARY SEARCH TREE AND FIND THE HEIGHT   */
/*                       OF THE TREE AND PRINT THE LEAF NODES              */
/*=========================================================================*/

#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<graphics.h>
#define SIZE 50


typedef struct bst                //STRUCTURE FOR BINARY TREE
{
	struct bst *lc;
	struct bst *rc;
	int data;
}bst;

/*    ***********  DECLARATION    OF    ALL    FUNCTIONS   ***********     */

void create_tree(bst *root,int val);
bst *create_node(void);
void display(bst *cur,int ,int ,int,int);
int height(bst *head,int,int );
void leaf(bst *head);

/*=========================================================================*/
/*	    START OF THE MAIN FUNCTION                                     */
/*=========================================================================*/

void main()
{
  int ch,data,no,val,hgt,n,i;
  bst *head , *root;
  int flag=0;
  char ans;
  do
  {
    clrscr();                     /* CLEARS TEXT MODE WINDOW */
    printf("\n\n\t=======================================================");
    printf("\n\n\t              **********  MENU  ************");
    printf("\n\n\t=======================================================");
    printf("\n\n\n\n\n\t\t     1> CREATE SEARCH TREE");
    printf("\n\n\t\t     2> DISPLAY BINARY SEARCH TREE");
    printf("\n\n\t\t     3> FIND HEIGHT OF THE TREE");
    printf("\n\n\t\t     4> DISPLAY LEAF NODES OF THE TREE");
    printf("\n\n\t\t     5> EXIT    ");
    printf("\n\n\n\t\t     ENTER YOUR CHOICE : ");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
	       clrscr();
	       printf("\n\n\t==============================================");
	       printf("\n\n\t   ********** DATA ENTRY ************\n\n\t");
	       printf("==============================================\n\n");
	       printf("\n\n\t  ENTER THE NO OF NODES TO BE INSERTED : ");
	       scanf("%d",&n);
	       head=create_node();
	       head->lc=NULL;
	       printf("\n\n\n\n\t  ENTER THE ROOT NODE : ");
	       scanf("%d",&data);
	       root=create_node();
	       root->data=data;
	       head->lc=root;
	       root->lc=NULL;
	       root->rc=NULL;
	       flag=1;
	       for(i=0;i<n-1;i++)
	       {
		 printf("\n\n\n\n\t  ENTER THE DATA  : ");
		 scanf("%d",&no);
		 create_tree(head,no);
	       }
	       break;
      case 2: if(flag==1)
	      {
		int gd=VGA,gm=1;
		initgraph(&gd,&gm,"c:\\tc\\bgi");
		cleardevice();
		setbkcolor(BLACK);    /* SET BACKGROUND COLOUR AS BLACK */
		setcolor(15);
		printf("\n\n\t THE SEARCH TREE IS :: ");
		display(head->lc,0,640,320,50);
		getch();
		closegraph();
	      }
	      else
		printf("\n\n\n\n\t CREATE THE TREE FIRST  !!!");
	      break;
      case 3: if(flag==1)
	      {
		int gd=VGA,gm=1;
		initgraph(&gd,&gm,"c:\\tc\\bgi");
		hgt=height(head->lc,0,0); /* FUN CALL TO FIND HEIGHT OF TREE */
		cleardevice();
		setbkcolor(BLACK);     /* SET BACKGROUND COLOUR AS BLACK */
		setcolor(15);
		printf("\n\n\n\t THE HEIGHT OF THE TREE : %d",hgt);
		display(head->lc,0,640,320,50);
		getch();
		closegraph();
	      }
	      else
		printf("\n\n\n\n\t CREATE TREE FIRST  !!!");
	      break;
      case 4: if(flag==1)
	      {
	       int gd=VGA,gm=1;
	       initgraph(&gd,&gm,"c:\\tc\\bgi");
		cleardevice();
		setbkcolor(BLACK);     /* SET BACKGROUND COLOUR AS BLACK */
		setcolor(15);
	       printf("\n\n\n\t THE LEAF NODES ARE  : \n\n");
	       leaf(head->lc);         /* FUNCTION CALL TO DISPLAY LEAF */
	       display(head->lc,0,640,320,50);
	       getch();
	       closegraph();
	      }
	      else
		printf("\n\n\tCREATE THE TREE FIRST!");
	      break;
      case 5:
	      exit(0);
	      break;
    }
  }while(ch != 5);
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :    CREATE_NODE()                                       */
/*       OBJECTIVE :   TO CREATE THE NODES FOR THE SEARCH TREE             */
/*       PARAMETERS :  VOID                                                */
/*       RETURN TYPE : STRUCT BST*					   */
/*-------------------------------------------------------------------------*/

bst *create_node()              //FUNCTION TO ALLOCATE MEMORY
{
  bst *p;
  p=(bst*)malloc(sizeof(bst));
  if(p==NULL)
  {
    printf("\n\n\n\n\t  ALLOCATION FAILED !!!");
    getch();
    exit(0);
  }
  return(p);
}


/*-------------------------------------------------------------------------*/
/*       FUNCTION :    CREATE_TREE()                                       */
/*       OBJECTIVE :   TO CREATE THE BINARY SEARCH TREE                    */
/*       PARAMETERS :  HEAD OF TREE AND VALUE TO BE ADDED                  */
/*       RETURN TYPE : VOID					           */
/*-------------------------------------------------------------------------*/

void create_tree(bst *head,int val)
{
  bst *create_node(void);
  bst *cur,*par,*p;
  cur=head->lc;
  par=head;
  while(cur!=NULL)
  {
    if( val>cur->data)
    {
      par=cur;
      cur=cur->rc;
    }
    else
    {
      par=cur;
      cur=cur->lc;
    }
  }
  if(val>par->data)
  {
    p=create_node();
    par->rc=p;
    p->data=val;
    p->lc=NULL;
    p->rc=NULL;
  }
  else
  {
    p=create_node();
    par->lc=p;
    p->data=val;
    p->lc=NULL;
    p->rc=NULL;
  }
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :    DISPLAY()                                           */
/*       OBJECTIVE :   TO DISPLAY THE TREE IN GRPHICS MODE                 */
/*       PARAMETERS :  ROOT , SCREEN DIM.                                  */
/*       RETURN TYPE : VOID					           */
/*-------------------------------------------------------------------------*/

void display(bst *root,int low,int hi,int mid,int y)
{
  int org;                      /* LOCAL VARIABLE DECLARATION */
  char s[5];
  if(root!=NULL)
  {
    org=mid;
    mid=(low+hi)/2;

    if(root->lc!=NULL)
      display(root->lc,low,mid,mid,y+80);  /* RECURSIVE CALL TO FUNCTION */
    if(root->rc!=NULL)
      display(root->rc,mid,hi,mid,y+80);

    circle(mid,y,10);              /* DRAW THE CIRCLE */

    itoa(root->data,s,10);      /* CONVERTS INTEGER TO STRING */
    /* DISPLAYS STRING AT SPECIFIC LOCATION ( GRAPHICS MODE ) */

    outtextxy (mid-3,y-3,s);

    if(org>mid)
      line(mid+5,y-5,org-5,y-75);        /* DRAW A LINE */
    if(org<mid)
      line(mid-5,y-5,org+5,y-75);
  }
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :    HEIGHT()                                            */
/*       OBJECTIVE :   TO FIND THE HEIGHT OF THE BINARY SEARCH TREE        */
/*       PARAMETERS :  STRUCT BST* CUR , INTEGER , INTEGER                 */
/*       RETURN TYPE : INTEGER					           */
/*-------------------------------------------------------------------------*/

int height(bst*cur,int hl,int hr)
{
  if(cur!=NULL)
  {
    hl=height(cur->lc,hl,hr);
    hr=height(cur->rc,hl,hr);
    return( hr>hl ? hr+1 : hl+1 );
  }
  else
    return(0);
}


/*-------------------------------------------------------------------------*/
/*       FUNCTION :    LEAF()                                              */
/*       OBJECTIVE :   TO DISPLAY THE LEAF NODES OF THE SEARCH TREE        */
/*       PARAMETERS :  HEAD OF TREE AND VALUE TO BE ADDED                  */
/*       RETURN TYPE : VOID					           */
/*-------------------------------------------------------------------------*/

 void leaf(bst *cur)
 {
   if(cur!=NULL)
   {
     if(cur->lc==NULL && cur->rc==NULL)
     {
       printf("%d\t",cur->data);
     }
     else
     {
       leaf(cur->lc);
       leaf(cur->rc);
     }
   }
 }

/*=========================================================================*/
/*                END        OF        THE       PROGRAM                   */
/*=========================================================================*/
