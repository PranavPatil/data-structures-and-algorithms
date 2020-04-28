/*=========================================================================*/
/*        DATE OF COMPLETION : 6-2-03      CLASS   : SE IT                 */
/*=========================================================================*/
/* PROBLEM STATEMENT ::  REPRESENT CIRCULAR QUEUE USING ARRAY AND WRITE    */
/*                       A PROGRAM TO PERFORM FOLLOWING OPERATIONS :INSERT */
/*                       DELETE,FINDING FRONT AND REAR ELEMENT             */
/*=========================================================================*/
#include<stdio.h>
#include<conio.h>
#include<process.h>
#define MAXSIZE  10

  struct st
  {
    int front,rear;
    int kount;
    int queue[MAXSIZE];
  };
  struct st s;

/*    ***********  DECLARATION    OF    ALL    FUNCTIONS   ***********     */

  int empty(void);
  int full(void);
  void add(void);
  void deletem(void);
  void display(void);
  void front(void);
  void rear(void);

/*=========================================================================*/
/*	     START    OF   THE    MAIN    FUNCTION                         */
/*=========================================================================*/
 void main()
 {
   char ch;
   s.front=0;
   s.rear=-1;
   s.kount=0;
   do
   {
     clrscr();
     printf("\n\t============================================");
     printf("\n\n\n\t     ************* MENU *************");
     printf("\n\n\n\t============================================");
     printf("\n\n\n\n\n\t\t1> ADD");
     printf("\n\n\t\t2> DISPLAY");
     printf("\n\n\t\t3> DELETE");
     printf("\n\n\t\t4> FIND FRONT ELEMENT");
     printf("\n\n\t\t5> FIND REAR ELEMENT");
     printf("\n\n\t\t6> EXIT");
     printf("\n\n\t\t ENTER YOUR CHOICE : ");
     scanf("%c",&ch);
     switch(ch)
     {
       case '1':
		 add();
		 getch();
		 break;
       case '2':
		 display();
		 getch();
		 break;
       case '3':
		 deletem();
		 getch();
		 break;
       case '4':
		 front();
		 getch();
		 break;
       case '5':
		 rear();
		 getch();
		 break;
       case '6':
		 exit (1);
		 break;
     }
   } while(ch != '6');
   getch();
 }
/*-------------------------------------------------------------------------*/
/*       FUNCTION :   FULL()                                               */
/*       OBJECTIVE :  TO CHECK FOR QUEUE FULL                              */
/*       PARAMETERS : VOID                                                 */
/*-------------------------------------------------------------------------*/
 int full(void)
 {
  if(s.kount == MAXSIZE)
       return(1);
  else
       return(0);
 }
/*-------------------------------------------------------------------------*/
/*       FUNCTION :   EMPTY()                                              */
/*       OBJECTIVE :  TO CHECK FOR QUEUE EMPTY                             */
/*       PARAMETERS : VOID                                                 */
/*-------------------------------------------------------------------------*/

 int empty(void)
 {
  if(s.kount == 0)
      return(1);
  else
      return(0);
 }
/*-------------------------------------------------------------------------*/
/*       FUNCTION :   ADD()                                                */
/*       OBJECTIVE :  TO ADD ELEMENTS TO THE QUEUE                         */
/*       PARAMETERS : VOID                                                 */
/*-------------------------------------------------------------------------*/

  void add(void)
  {
   int x,con=0,m;
   clrscr();
   printf("\n\n\t===============================================");
   printf("\n\n\n\t        ADDITION OF ELEMENTS TO THE QUEUE  ");
   printf("\n\n\n\t===============================================\n");
   printf("\n\n\n\n\tENTER THE NO OF ELEMENTS TO BE INSERTED : ");
   scanf("%d",&m);
   do
    {
      if(full()==1)
      {
	 printf("\n\n\t\t QUEUE FULL !!!!\n");
	 break;
      }
      else
      {
	 s.rear =(s.rear+1)% MAXSIZE;
	 printf("\n\n\n\tENTER AN ELEMENT TO BE ADDED  : ");
	 scanf("%d",&x);
	 s.queue[s.rear] =x;
	 s.kount++;
      }
      flushall();
      con++;
    }while(con<m);
  }
/*-------------------------------------------------------------------------*/
/*       FUNCTION :   DELETEM()                                            */
/*       OBJECTIVE :  TO DELETE THE QUEUE ELEMENTS                         */
/*       PARAMETERS : VOID                                                 */
/*-------------------------------------------------------------------------*/

   void deletem(void)
 {
   char ch;
   clrscr();
   printf("\n\n\t===============================================");
   printf("\n\n\n\t        DELETION OF ELEMENTS OF THE QUEUE  ");
   printf("\n\n\n\t===============================================");
   do
   {
     if(empty()== 1)
     {
       printf("\n\n\n\n\n\t\t QUEUE  IS  EMPTY!!\n");
       break;
     }
     else
     {
       printf("\n\n\n\n\t\t%d  HAS BEEN DELETED !! ",s.queue[s.front]);
       s.front=(s.front+1) % MAXSIZE;
       s.kount--;
     }
    printf("\n\n\n\t\tDO YOU WANT TO DELETE MORE ?  [Y\N] : ");
    flushall();
    ch=getch();
   }while (ch =='y' || ch == 'Y');
 }
/*-------------------------------------------------------------------------*/
/*       FUNCTION :   DISPLAY()                                            */
/*       OBJECTIVE :  TO DISPLAY THE QUEUE ELEMENTS                        */
/*       PARAMETERS : VOID                                                 */
/*-------------------------------------------------------------------------*/

 void display(void)
 {
  int i;
  clrscr();
  printf("\n\n\t===============================================");
  printf("\n\n\n\t           DISPLAYING THE QUEUE  ");
  printf("\n\n\n\t===============================================");
  if(empty()== 1)
      printf("\n\n\n\n\n\t\tQUEUE  IS  EMPTY!!!!");
  if(empty()== 0)
  {
    printf("\n\n\n\n\t\tDISPLAYING QUEUE !!!\n\n\n\t\t");
    for(i=s.front;i<=s.rear;i++)
       printf("%d   ",s.queue[i]);
  }
  return;
 }

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   FRONT()                                              */
/*       OBJECTIVE :  TO DISPLAY THE FRONT ELEMENT OF THE QUEUE            */
/*       PARAMETERS : VOID                                                 */
/*-------------------------------------------------------------------------*/

void front(void)
{
  clrscr();
  printf("\n\n\t===============================================");
  printf("\n\n\n\t    DISPLAYING THE FRONT ELEMENT OF THE QUEUE  ");
  printf("\n\n\n\t===============================================");
  if(empty()==1)
   printf("\n\n\n\n\n\t\tQUEUE IS EMPTY !!");
  else
  {
   printf("\n\n\n\n\t THE FRONT ELEMENT OF THE QUEUE IS : %d",s.queue[s.front]);
  }
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   REAR()                                               */
/*       OBJECTIVE :  TO DISPLAY THE REAR ELEMENT OF THE QUEUE            */
/*       PARAMETERS : VOID                                                 */
/*-------------------------------------------------------------------------*/

void rear(void)
{
  clrscr();
  printf("\n\n\t===============================================");
  printf("\n\n\n\t    DISPLAYING THE REAR ELEMENT OF THE QUEUE  ");
  printf("\n\n\n\t===============================================");
  if(empty()==1)
    printf("\n\n\n\n\n\t\tQUEUE IS EMPTY !!");
  else
  {
   printf("\n\n\n\n\t THE REAR ELEMENT OF THE QUEUE IS : %d",s.queue[s.rear]);
  }
}

/*=========================================================================*/
/*                END        OF        THE       PROGRAM                   */
/*=========================================================================*/
