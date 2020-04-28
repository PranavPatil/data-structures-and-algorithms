/*=========================================================================*/
/*        ASSIGNMENT NO : 7                 SUBJECT : DSF                  */
/*        DATE OF COMPLETION : 18-2-03      CLASS   : SE IT                */
/*=========================================================================*/
/* PROBLEM STATEMENT ::  WRITE A PROGRAM TO CREATE A GENERALISED LINKED    */
/*                       LIST AND PERFORM FOLLOWING OPERATIONS :   COPY ,  */
/*                       EQUIVALENCE AND DEPTH                             */
/*=========================================================================*/

#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<ctype.h>
#define stacksize 20


/*                    STRUCTURE TO STORE NODE IN A GLL                     */

  struct gllnode
  {
      int flag;
      union onetotwo
      {
	 char data;
	 struct gllnode *dlink;
      }u;
      struct gllnode *link;
  };
  typedef struct gllnode gll;


/*         STRUCTURE TO STORING ADDRESS OF THE NODES IN THE STACK          */

  struct stacktype
  {
   int top;
   gll *stack[stacksize];
  };
  typedef struct stacktype ST;


/*               STRUCTURE FOR STORING INTEGERS IN THE STACK               */

  struct stackint
  {
   int top;
   int pos[stacksize];
  };
  typedef struct stackint SI;


/*    ***********  DECLARATION    OF    ALL    FUNCTIONS   ***********     */

  gll *creategll();
  void printgll(gll *head);
  int check_equivalence(gll *heada,gll *headb);
  gll *copy(gll *head1);
  void push(ST *s,gll *cur);
  void pushint(SI *s,int x);
  int popint(SI *s);
  gll *pop(ST *s);
  gll *createnode();

/*=========================================================================*/
/*	               START OF THE MAIN FUNCTION                          */
/*=========================================================================*/

void main(void)
{
 gll *heada=NULL,*headb=NULL,*headcpy=NULL;
 char choice,ch,set;
 int retval,val;
 do
 {
  clrscr();
  printf("\n\n\t================================================");
  printf("\n\n\t         **********  MENU  ************");
  printf("\n\n\t================================================");
  printf("\n\n\n\n\t\t  1> ENTER");
  printf("\n\n\t\t  2> DISPLAY");
  printf("\n\n\t\t  3> COPY ");
  printf("\n\n\t\t  4> EQUIVALENCE");
  printf("\n\n\t\t  5> EXIT");
  printf("\n\n\n\t\t  ENTER THE CHOICE  : ");
  choice = getch();
  switch(choice)
  {
   case '1':
	      clrscr();
	      printf("\n\n\t================================================");
	      printf("\n\n\t      ********** ACCEPT GLL ************");
	      printf("\n\n\t================================================");
	      printf("\n\n\n\n\n\t  ENTER THE SET'S WITH PROPER PARANTHESIS:");
	      printf("\n\n\n\n\t  ENTER SET A  :: ") ;
	      heada=creategll();
	      printf("\n\n\n\n\t  ENTER SET B  :: ");
	      headb=creategll();
	      getch();
	      break;
   case '2':
	      clrscr();
	      printf("\n\n\t===============================================");
	      printf("\n\n\t     *******    DISPLAYING GLL 1    *******    ");
	      printf("\n\n\t===============================================");
	      printf("\n\n\n\n\t");
	      printf("  SET A HAS GLL WITH HEADER NODE AT LOCATION ");
	      printf(" ::  %u",heada);
	      printf("\n\n\n\t  THE GLL OF SET A IS  ::");
	      printgll(heada);
	      clrscr();
	      printf("\n\n\t===============================================");
	      printf("\n\n\t     *******    DISPLAYING GLL 2    *******    ");
	      printf("\n\n\t===============================================");
	      printf("\n\n\n\n\t");
	      printf("  SET B HAS GLL WITH HEADER NODE AT THE LOCATION ");
	      printf(" ::  %u",headb);
	      printf("\n\n\n\n\t  THE GLL OF SET B IS  ::");
	      printgll(headb);
	      getch();
	      break;
   case '3':
	      clrscr();
	      printf("\n\n\t===============================================");
	      printf("\n\n\t   *******    TO GET COPY OF GLL    *******    ");
	      printf("\n\n\t===============================================");
	      printf("\n\n\n\n\n\t  ");
	      printf("ENTER THE SET COPY OF WHOSE GLL IS TO FOUND (A/B) :: ");
	      scanf("%c",&set);
	      if(set=='a' || set=='A')
	      {
		headcpy=copy(heada);
		printf("\n\n\n\n\t");
		printf("  COPY OF SET A HAS ITS HEADER AT THE LOCATION");
		printf(" ::  %u",headcpy);
		printf("\n\n\n\n\t  THE GLL OF THE COPY IS ::");
		printgll(headcpy);
	      }
	      else if(set=='b' || set=='B')
	      {
	       headcpy=copy(headb);
	       printf("\n\n\n\n\t");
	       printf("  COPY OF SET B HAS ITS HEADER NODE AT LOCATION");
	       printf(" ::  %u",headcpy);
	       printf("\n\n\n\n\t  THE GLL OF THE COPY IS ::");
	       printgll(headcpy);
	      }
	      else
	      {
		printf("\n\n\n\n\n\t\t  NO SUCH SET EXISITNG  !!!");
		getch();
	      }
	      getch();
	      break;
   case '4':
	      clrscr();
	      printf("\n\n\t===================================================");
	      printf("\n\n\t  ******    CHECK OF EQUIVALENCE OF GLL    ******  ");
	      printf("\n\n\t===================================================");
	      retval=check_equivalence(heada,headb);
	      if(retval==1)
	      printf("\n\n\n\n\n\t  THE GENERALISED LISTS FORMED FROM SET A"
		     " \n\n\n\t  AND SET B ARE SAME.");
	      else
	      printf("\n\n\n\n\n\t  THE GENERALISED LISTS FORMED FROM SET A"
		     "\n\n\t  AND SET B ARE NOT SAME");
	      getch();
	      break;
   case '5':
	      break;
  }
 }while(choice!='5');
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :    CREATEGLL()                                         */
/*       OBJECTIVE :   TO CREATE GLL AND TO FIND AND PRINT DEPTH OF THE GLL*/
/*       PARAMETERS :  VOID                                                */
/*       RETURN TYPE : STRUCT GLL*					   */
/*-------------------------------------------------------------------------*/

 gll *creategll()
  {
  gll *cur,*prev,*newf;
   ST s;
   int depth=0;
   char ch;
   s.top=-1;
   cur=createnode();
   prev=cur;
   scanf("%c",&ch);
   while(ch != '\n')
    {
     if(isalpha(ch))
      {
       cur->flag=0;
       cur->u.data=ch;
       newf=createnode();
       cur->link=newf;
      }
     if(ch== '(')
      {
       push(&s,cur);
       cur->flag=1;
       newf=createnode();
       cur->u.dlink=newf;
       depth++;
      }
     if(ch==')')
      {
       prev->link=NULL;
       free(cur);
       cur=pop(&s);
       newf=createnode();
       cur->link=newf;
      }
     if(ch== '(' || ch== ')' || isalpha(ch))
      {
       prev=cur;
       cur=newf;
      }
      scanf("%c",&ch);
     }
    prev->link=NULL;
    free(cur);
    printf("\n\n\n\t  THE DEPTH OF THE GLL  ::  %d",depth);
    return(prev);
   }

/*-------------------------------------------------------------------------*/
/*       FUNCTION :    PUSH()                                              */
/*       OBJECTIVE :   TO PUSH A NODE IN THE STACK OF TYPE 'ST'            */
/*       PARAMETERS :  PTR OF STRUCT 'ST'TO PUSH , PTR CUR OF STRUCT GLL   */
/*       RETURN TYPE : VOID     					   */
/*-------------------------------------------------------------------------*/

  void push(ST *s,gll *cur)
   {
    s->stack[++s->top]=cur;
   }

/*-------------------------------------------------------------------------*/
/*       FUNCTION :    POP()                                               */
/*       OBJECTIVE :   TO POP AND RETURN ELEMENT AT TOP OF THE STACK       */
/*       PARAMETERS :  ADDRESS OF THE STACK STRUCT S*                      */
/*       RETURN TYPE : STRUCT GLL*     					   */
/*-------------------------------------------------------------------------*/

  gll *pop(ST *s)
   {
    return(s->stack[s->top--]);
   }

/*-------------------------------------------------------------------------*/
/*       FUNCTION :    PUSHINT()                                           */
/*       OBJECTIVE :   TO PUSH AN INTEGER IN THE STACK OF TYPE 'ST'        */
/*       PARAMETERS :  NUMBER TO PUSH AND ADDRESS OF THE STACK             */
/*       RETURN TYPE : VOID             				   */
/*-------------------------------------------------------------------------*/

  void pushint(SI *s,int x)
   {
    s->pos[++s->top]=x ;
   }

/*-------------------------------------------------------------------------*/
/*       FUNCTION :    POPINT()                                            */
/*       OBJECTIVE :   TO POP AND RETURN ELEMENT AT THE TOP OF THE STACK   */
/*       PARAMETERS :  ADDRESS OF THE STACK OF TYPE 'ST'                   */
/*       RETURN TYPE : INTEGER   					   */
/*-------------------------------------------------------------------------*/

  int popint(SI *s)
    {
     return(s->pos[s->top--]);
    }

/*-------------------------------------------------------------------------*/
/*       FUNCTION :    CREATENODE()                                        */
/*       OBJECTIVE :   TO CREATE A NODE OF THE TYPE 'GLL'                  */
/*       PARAMETERS :  VOID                                                */
/*       RETURN TYPE : STRUCT GLL* PTR POINTING TO MEMORY LOCAN ALLOCATED  */
/*-------------------------------------------------------------------------*/

   gll *createnode()
    {
     gll *newf=NULL;
     newf=(gll *)malloc(sizeof(gll));
     if(newf==NULL)
      {
       printf("\n\n\n\n\t\t  ALLOCATION FAILED !!!");
       getch();
      }
     else
      {
	newf->flag=0;
	newf->link=NULL;
	newf->u.data=0;
	newf->u.dlink=NULL;
      }
    return(newf);
 }

/*-------------------------------------------------------------------------*/
/*       FUNCTION :    CHECK_EQUIVALENCE()                                 */
/*       OBJECTIVE :   TO CHECK IF THE TWO GLLS ARE EQUIVELENT             */
/*       PARAMETERS :  THE HEADER NODES OF THE TWO GLLS                    */
/*       RETURN TYPE : INTEGER (RET 1 IF THE GLL ARE EQUAL ELSE RET 0)     */
/*-------------------------------------------------------------------------*/

  int check_equivalence(gll *heada,gll *headb)
   {
    gll *pop(ST *s);
    gll *cura=heada->u.dlink;
    gll *curb=headb->u.dlink;
    ST sa,sb;
    sa.top=-1;
    sb.top=-1;
    push(&sa,heada);
    push(&sb,headb);
    while(cura!=heada && curb!=headb)
     {
      if(cura->flag==0)
       {
	if(curb->flag!=0)
	 return(0);
	if(cura->u.data!=curb->u.data)
	 return(0);
	cura=cura->link;
	curb=curb->link;
	if(cura==NULL && curb ==NULL)
	 {
	  cura=pop(&sa);
	  curb=pop(&sb);
	  if(cura!=heada)
	   cura=cura->link;
	  if(curb!=headb)
	   curb=curb->link;
	 }
	else if(cura==NULL && curb!=NULL)
	 return(0);
	else if(curb==NULL &&cura!=NULL)
	 return(0);
       }
      else
       {
	if(curb->flag!=1)
	 return(0);
	push(&sa,cura);
	push(&sb,curb);
	cura=cura->u.dlink;
	curb=curb->u.dlink;
       }
      }
     if(cura!=heada || curb!= headb)
      return(0);
     return(1);
   }

/*-------------------------------------------------------------------------*/
/*       FUNCTION :    PRINTGLL()                                          */
/*       OBJECTIVE :   TO PRINT THE GLL                                    */
/*       PARAMETERS :  THE HEADER NODES OF THE GLL                         */
/*       RETURN TYPE : VOID      					   */
/*-------------------------------------------------------------------------*/

  void printgll(gll *head)
   {
    gll *cur;
    int row=25,col=15;
    ST s;
    SI srow,scol;
    srow.top=-1;
    scol.top=-1;
    s.top=-1;
    push(&s,head);
    gotoxy(col,row); printf("#");
    row++;
    gotoxy(col,row);printf("%c",'|');
    row++;
    cur=head->u.dlink;
    while(cur != head)
     {
      if(cur->flag==0)
       {
	gotoxy(col,row);printf("%c",cur->u.data);
	col++;
	if(cur->link!=NULL)
	 {
	  gotoxy(col,row);printf("->");
	  col=col+3;
	 }
	cur=cur->link;
	while(cur==NULL)
	 {
	  cur=pop(&s);
	  col=popint(&scol);
	  row=popint(&srow);
	  if(cur !=head)
	   cur=cur->link;
	  }
	 }
       else
	{
	 gotoxy(col,row);printf("#");
	 if(cur->link != NULL)
	   {
	   gotoxy(col+1,row);printf("->");
	   pushint(&scol,col+4);
	  }
	 else
	      pushint(&scol,col+1);
	    pushint(&srow,row);
	   row++;
	   gotoxy(col,row);printf("%c",'|');
	   row++;
	   push(&s,cur);
	   cur=cur->u.dlink;
	  }
	 }
	getch();
      }

/*-------------------------------------------------------------------------*/
/*       FUNCTION :    COPY()                                              */
/*       OBJECTIVE :   TO MAKE A COPY OF THE GLL                           */
/*       PARAMETERS :  THE HEADER NODE OF THE GLL TO BE COPIED             */
/*       RETURN TYPE : STRUCT GLL* (RETURNS HEADER NODE OF THE COPY)	   */
/*-------------------------------------------------------------------------*/

 gll *copy(gll *head1)
 {
   gll *pop(ST *s);
   gll *createnode() ;
   gll *head2,*cur1,*cur2,*newf;
   ST s1,s2;
   s1.top=-1;
   s2.top=-1;
   head2=createnode();
   head2->flag=1;
   cur2=createnode();
   head2->u.dlink=cur2;
   cur2=head2->u.dlink;
   push(&s1,head1);
   push(&s2,head2);
   cur1=head1->u.dlink;
   while(cur1!=head1)
   {
    if(cur1->flag==0)
    {
      cur2->flag=0;
      cur2->u.data=cur1->u.data;
      cur1=cur1->link;
      if(cur1!=NULL)
      {
	newf=createnode();
	cur2->link=newf;
	cur2=cur2->link;
      }
      else
      {
	while( cur1==NULL)
	{
	  cur1=pop(&s1);
	  cur2=pop(&s2);
	  if(cur1==head1)
	    break;
	  cur1=cur1->link;
	  if(cur1!=NULL)
	  {
	    newf=createnode();
	    cur2->link=newf;
	    cur2=cur2->link;
	  }
	}
      }
    }
    else if(cur1->flag==1)
    {
      cur2->flag=1;
      newf=createnode();
      cur2->u.dlink=newf;
      push(&s1,cur1);
      push(&s2,cur2);
      cur1=cur1->u.dlink ;
      cur2=cur2->u.dlink;
    }
   }
   return(cur2);
 }

/*=========================================================================*/
/*                END        OF        THE       PROGRAM                   */
/*=========================================================================*/
