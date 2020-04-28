/*----------------------------------------------------------------------
	   PROBLEM STATEMENT     :
		  WRITE A MENU DRIVEN PROGRAM TO CREATE A BINARY SEARCH TREE
		  AND PERFORM THE FOLLOWING OPERATIONS NON RECUSSIVELY:--
		1] CREATE A TREE.
		2] TO FIND THE HEIGHT OF THE TREE.
		3] TO FIND THE WIDTH OF THE TREE.

-----------------------------------------------------------------------
PROBLEM DEFINITIONS :

  1. BINARY SEARCH TREE :
     --------------------
		 A BINARY SEARCH TREE IS A BINARY TREE WHEREIN
    (a) ALL THE KEYS HAVING VALUE LESS THAN THAT OF THE ROOT  WILL BE
       IN THE LEFT SUBTREE.
    (b) ALL THE KEYS HAVING VALUE GREATER THAN THAT OF THE ROOT WILL BE
       IN THE RIGHT SUBTREE.
    (c) THE LEFT AND RIGHT SUBTREES ARE AGAIN SEARCH TREES.


  2. HEIGHT OF A BINARY SEARCH TREE :
     --------------------------------
	IT IS THE MAXIMUM PATH LENGTH OF ANY LEAF NODE IN THE TREE.


  3. WIDTH OF A BINARY SEARCH TREE :
     -------------------------------
       IT IS THE MAXIMUM NO. OF NODES OF A PARTICULAR LEVEL ,
	FOR ANY LEVEL OF THE TREE.

-------------------------------------------------------------------------------*/


/* -------------------------- START OF PROGRAM ------------------------------*/

#include<stdio.h>	 	  /* HEADER FILES */
#include<conio.h>
#include<alloc.h>

#define SIZE 30

typedef struct node
 {
   struct node *lc;             /* STRUCTURE FOR NODE OF A BINARY SEARCH TREE */
   int data;
   struct node *rc;
  }bsnode;

struct que
    {
      bsnode *queue[SIZE];       /*STRUCTURE FOR QUEUE */
      int front;
      int rear;
      int cnt;
      int mark;
     };
typedef struct que qs;


/*--------------------------- START OF MAIN ---------------------------------*/
  void main(void)
   {
       unsigned t;                          /* VARIABLE DECLARATION */
       int stop=1,no,ch,l,i,big;
       int cnt[10];
	  bsnode *head;

	  void add(bsnode*cur,qs *q);
       bsnode *create_tree(void);
       void bfs(bsnode *head);
	  void menu(void);
	  void dis(qs *q1);

       while(stop!=0 )
       {
	 clrscr();
	 menu();
	 printf("\nENTER YOUR CHOICE :");
	 scanf("%d",&ch);

	 switch(ch)
	  {

	  case 1:
	      head=create_tree();
	      break;


	 case 2:
		printf("\n******LEVELWISE DISPLAY OF THE BINARY TREE IS*********\n\n");
		bfs(head);
		break;

	 default :
	       printf("\nPRESS ANY KEY TO EXIT .........");
	       stop=0;

	    }

	      getch();
	  }
   }

/*--------------------------------------------------------------------------
FUNCTION           : menu
		      USED TO DISPLAY THE MENU .

PARAMETERS PASSED  : NONE.

RETURN             : NONE.

TIME COMPLEXITY    : O(1)
-----------------------------------------------------------------------------*/
 void menu(void)
   {
     printf("\n\t\tMENU");
     printf("\n\t1]. CREATE A NEW TREE");
     printf("\n\t2]. DISPLAY LEVELWISE AND HEIGHT AND WIDTH OF THE TREE");
     printf("\n\t3]. EXIT \n");
    }

/*--------------------------------------------------------------------------
FUNCTION           : create_tree
		      USED TO CREATE A BINARY SEARCH TREE.

PARAMETERS PASSED  : NONE.

RETURN             : head.

TIME COMPLEXITY    : O(log(n))
		   n->NO. OF ELEMENTS IN THE BINARY SEARCH TREE
-----------------------------------------------------------------------------*/
 bsnode  *create_tree(void)
    {
      int stop=1,no;
      bsnode *root,*head;
      void insert(bsnode *head,int no);
      bsnode *createnode(void);
      head=createnode();

      printf("\nENTER THE ROOT OF THE NO : ");
      scanf("%d",&no);

	 root=createnode();
	 root->data=no;
	 head->lc=root;
	 if(no==-999)
	   stop=0;

	while(stop!=0)
	 {
	   printf("\nENTER THE NEW NO.        : ");
	   scanf("%d",&no);
	   if(no==-999)
	     stop=0;
	   else
	      insert(head,no);
	  }
       return(head);
     }

/*--------------------------------------------------------------------------
FUNCTION           : create_node
		      USED TO CREATE A NODE OF THE BINARY SEARCH TREE.

PARAMETERS PASSED  : NONE.

RETURN             : new.

TIME COMPLEXITY    : O(1)
-----------------------------------------------------------------------------*/
     bsnode *createnode(void)
      {
	 bsnode *new=NULL;

	 new=(bsnode*)calloc(sizeof(bsnode),1);
	 if(new==NULL)
	   {
	     printf("\nALLOCATION FAILURE .......");
	     getch();
	     exit(0);
	    }
	  return(new);
	}
/*-----------------------------------------------------------------------
FUNCTION           : bfs
		      USED TO DISPLAY THE TREE LEVELWISE .

PARAMETERS PASSED  : head->CALL BY VALUE.

RETURN             : NONE.

TIME COMPLEXITY    : O(N*N)
		    WHERE , N-> NO. OF NODES IN THE TREE.
-----------------------------------------------------------------------------*/
  void bfs(bsnode *head)
   {
     bsnode *cur,*new;
     qs q;
     int stop=1,x,i,l,w,width;
     bsnode *rem(qs *q);
     void add(bsnode*cur,qs *q);
     void dis(qs *q);

     q.cnt =0;
     q.front=q.rear=0;

     printf("\n\n");

     add(head->lc,&q);
     printf("\nLEVEL 1:\t");
     printf("%d",head->lc->data);
     l=1;
     w=1;
     width=1;

     add(head,&q);
     printf("\n");

     while(stop==1)
      {
	cur=rem(&q);
	if(qempty(q.cnt)==1)
	   stop=0;
	else
	 {
	   if(cur==head)
	    {
	     l++;
	     if(q.front > q.rear)
		w=(q.rear+SIZE)-q.front;
	     else
		w=q.rear-q.front;
	     if(w>width)
	       width=w;
	     printf("LEVEL %d : \t",l);
	     dis(&q);
	     printf("\n");
	     add(head,&q);
	     }
	    else
	     {
	       if(cur->lc!=NULL)
		 {
		  add(cur->lc,&q);
		  }

	       if(cur->rc!=NULL)
		 {
		   add(cur->rc,&q);
		 }
	     }
	 }
   }

   printf("\nTHE HEIGHT OF THE TREE IS : %d" , l);
   printf("\nTHE WIDTH OF THE TREE IS  : %d",width);
}

/*--------------------------------------------------------------------------
FUNCTION           : qfull
		      USED TO CHECK IF THE QUEUE IS FULL.

PARAMETERS PASSED  : pos->CALL BY VALUE.

RETURN             : integer value.

TIME COMPLEXITY    : O(1)
-----------------------------------------------------------------------------*/

  int qfull(int pos)
   {
     if(pos==SIZE-1)
       return (1);
     else
	return (0);
     }
/*--------------------------------------------------------------------------
FUNCTION           : add
		      USED TO ADD A NEW RECORD INTO THE QUEUE .

PARAMETERS PASSED  : cur->CALL BY VALUE.
		     q1->CALL BY REFERENCE.

RETURN             : NONE.

TIME COMPLEXITY    : O(1)
-----------------------------------------------------------------------------*/
void add(bsnode *cur,qs *q1)
  {

       if(qfull(q1->cnt)!=1)
	 {
	   q1->mark=0;
	   q1->queue[q1->rear]=cur;
	   q1->rear=(q1->rear+1)%SIZE;
	   q1->cnt++;
	  }
	else
	  {
	    printf("\nTHE QUEUE IS FULL \n");
	   }
    }


/*--------------------------------------------------------------------------
FUNCTION           : qempty
		      USED TO CHECK IF THE QUEUE IS EMPTY.

PARAMETERS PASSED  : pos->CALL BY VALUE.

RETURN             : integer value.

TIME COMPLEXITY    : O(1)
-----------------------------------------------------------------------------*/
   int qempty(int pos)
     {
       if(pos==0)
	 return(1);
	else
	  return(0);
       }

/*--------------------------------------------------------------------------
FUNCTION           : dis
		      USED TO DISPLAY THE RECORDS IN THE QUEUE OF A PARTICULAR LEVEL.

PARAMETERS PASSED  : q1->CALL BY REF.

RETURN             : NONE.

TIME COMPLEXITY    : O(N)
		     WHERE , N-> NO. OF ELEMENTS PRESENT IN THE QUEUE.
-----------------------------------------------------------------------------*/
 void dis(qs *q1)
   {
     int i,j,x,stop=0;

     i=q1->front;
     do
       {
	if(q1->queue[i]!=NULL)
	 printf("%d\t",q1->queue[i]->data);
	else
	  {
	    printf("\t ");
	   }
	i++;
	if(i==SIZE)
	 i=0;
	if(i==q1->rear)
	 stop=1;
	}
	 while(stop==0);

   }


/*--------------------------------------------------------------------------
FUNCTION           : remove
		      USED TO DELETE A RECORD FROM THE QUEUE.

PARAMETERS PASSED  : q1->CALL BY REFERENCE.

RETURN             : new.

TIME COMPLEXITY    : O(1)
-----------------------------------------------------------------------------*/
   bsnode *rem(qs *q1)
    {
      bsnode *new;

      if(qempty(q1->cnt)==1)
	return(NULL);
       else
	 {
	   new=q1->queue[q1->front];
	   q1->queue[q1->front]=NULL;
	   q1->front= ( q1->front+1)%SIZE;
	   q1->cnt--;
	   return(new);
	  }
     }

/*--------------------------------------------------------------------------
FUNCTION           : insert
		      USED TO INSERT A NEW NO.IN THE BINARY SEARCH TREE.

PARAMETERS PASSED  : head-> CALL BY VALUE.
		     no ->CALL BY VALUE.

RETURN             : NONE.

TIME COMPLEXITY    : O(N)
		     WHERE N->NO. OF ELEMENTS AFTER WHICH THE
		     NEW NO IS INSERTED.
-----------------------------------------------------------------------------*/
 void insert(bsnode *head,int no)
   {
     bsnode *new,*par,*cur;

     par=head;
     cur=head->lc;
       while(cur!=NULL)
	 {
	   if(cur->data>no)
	     {
	      par=cur;
	      cur=cur->lc;
	      }
	   else
	      {
		par=cur;
		cur=cur->rc;
	       }
	  }
	   new=createnode();
	   new->lc=new->rc=NULL;
	   new->data=no;

	   if(par->data > new->data)
	     {
		par->lc=new;
	      }
	    if(par->data < new->data )
	      {
		par->rc =new;
	       }
	     if(par->data == new->data)
	      {
		 printf("\nRECORD ALREADY PRESENT \n");
	       }
     }
/* ========================= END OF PROGRAM ===============================*/









