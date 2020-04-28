/*=========================================================================*/
/*        DATE OF COMPLETION : 10-2-03      CLASS   : SE IT                */
/*=========================================================================*/
/* PROBLEM STATEMENT ::  IMPLEMENT STACK AS AN ABSTRACT DATA TYPE USING    */
/*                       ARRAY/LINKED LIST. USE THIS ADT FOR EXPRESSION    */
/*                       CONVERSION AND EVALUATION                         */
/*=========================================================================*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

struct node
{
 int info;
 struct node *next;
}*p,*front;

/*    ***********  DECLARATION    OF    ALL    FUNCTIONS   ***********     */

void push_stack(void);
void display_stack(void);
void pop_stack(void);
int stackop(void);
void postfix(char str[40]);
int isp(char opn);
int icp(char opn);
void evaluate(char exp[30]);
int error(char str[40]);
/*=========================================================================*/
/*	    START OF THE MAIN FUNCTION                                     */
/*=========================================================================*/
void main()
{
 char expn[30],exp[30],op;
 int an;
 do
 {
  clrscr();
  printf("\n\t============================================");
  printf("\n\n\n\t     ************* MENU *************");
  printf("\n\n\n\t============================================");
  printf("\n\n\n\t1> CREATE THE STACK");
  printf("\n\n\t2> CONVERSION TO INFIX TO POSTFIX EXPRESSION");
  printf("\n\n\t3> EVALUATION OF POSTFIX EXPRESSION");
  printf("\n\n\t4> EXIT");
  printf("\n\n\t ENTER YOUR CHOICE : ");
  scanf("%c",&op);
  switch(op)
  {
   case '1':
	     stackop();
	     break;
   case '2':
	     clrscr();
	     printf("\n\t============================================");
	     printf("\n\n\n\t CONVERSION TO INFIX TO POSTFIX EXPRESSION ");
	     printf("\n\n\n\t============================================");
	     printf("\n\n\n    ENTER THE EXPRESSION  : ");
	     scanf("%s",&expn);
	     an=error(expn);
	     if(an==0)
	       printf("\n\n     INVALID EXPRESSION !!");
	     if(an==1)
	     {
	       printf("\n\n      EXPRESSION !!");
	       postfix(expn);
	     }
	     getch();
	     break;
   case '3':
	     clrscr();
	     printf("\n\t============================================");
	     printf("\n\n\n\t EVALUATION OF POSTFIX EXPRESSION ");
	     printf("\n\n\n\t============================================");
	     printf("\n\n\n\tENTER THE POSTFIX EXPRESSION : ");
	     scanf("%s",&exp);
	     evaluate(exp);
	     break;
   case '4':
	     exit(0);
	     break;
  }
 }while(op!='4');
 getch();
}
/*-------------------------------------------------------------------------*/
/*       FUNCTION :   STACKOP()                                            */
/*       OBJECTIVE :  TO PERFORM STACK OPERATIONS                          */
/*       PARAMETERS : VOID                                                 */
/*-------------------------------------------------------------------------*/
int stackop(void)
{
  char ch;
  int y;
  front=NULL;
  do
  {
   clrscr();
   printf("\n\t----STACK USING LINK LIST----\n\n\n");
   gotoxy(9,2);
   printf("1>   ADD AN ELEMENT TO THE STACK\n\n");
   printf("\t2>  DISPLAY STACK\n\n");
   printf("\t3>  DELETE AN ELEMENT FROM STACK\n\n");
   printf("\t4>  QUIT");
   gotoxy(9,2);
   for(;;)
   {
     ch = getch();
     if(ch == 13)
      break;
     if(ch == 0)
     {
      ch = getch();
      if(ch == 80)
      {
       y = wherey();
       gotoxy(9,y+2);
      }
      if(ch == 72)
      {
       y = wherey();
       gotoxy(9,y-2);
      }
     }
   }
   switch(wherey())
   {
    case 2:
	    push_stack();
	    break;
    case 4:
	    display_stack();
	    break;
    case 6:
	    pop_stack();
	    break;
    case 8:
	    return(1);
    default:
	    printf("\n\n\nWRONG CHOICE !!!!!\n");
	    break;
   }
  }while(ch!=80);
  flushall();
  return(0);
}
/*-------------------------------------------------------------------------*/
/*       FUNCTION :   PUSH_STACK()                                         */
/*       OBJECTIVE :  TO POP THE ELEMENTS FROM THE STACK                   */
/*       PARAMETERS : VOID                                                 */
/*-------------------------------------------------------------------------*/
void push_stack(void)
{
 char ch;
 clrscr();
 p = (node*)malloc(sizeof(struct node));
 printf("\n\n        OPERATION TO PUSH THE ELEMENTS ON THE STACK");
 printf("\n\n\n\tENTER THE DATA : ");
 scanf("%d",&p->info);
 p->next = NULL;
 if(front == NULL)
 {
  front=p;
 }
 else
 {
   p->next=front;
   front=p;
 }
}
/*-------------------------------------------------------------------------*/
/*       FUNCTION :   DISPLAY_STACK()                                            */
/*       OBJECTIVE :  TO DISPLAY THE STACK CONTENTS                        */
/*       PARAMETERS : VOID                                                 */
/*-------------------------------------------------------------------------*/
void display_stack(void)
{
 clrscr();
 printf("\n\n\n\t\t DISPLAYING THE STACK");
 p = front;
 if(p==NULL)
  printf("\n\n\n\t     THE STACK IS EMPTY\n");
 else
 {
  printf("\n\n\n\t STACK IS :\n\n");
  while(p != NULL)
  {
   printf("\n\n\t\t%d",p->info);
   p = p->next;
  }
 }
 getch();
}
/*-------------------------------------------------------------------------*/
/*       FUNCTION :   POP_STACK()                                          */
/*       OBJECTIVE :  TO POP THE ELEMENTS OF THE STACK                     */
/*       PARAMETERS : VOID                                                 */
/*-------------------------------------------------------------------------*/
void pop_stack(void)
{
 int num;
 clrscr();
 printf("\n\n        OPERATION TO POP THE ELEMENTS FROM THE STACK");
 p = front;
 if(p == NULL)
  printf("\n\n\n\t\tTHE STACK IS EMPTY !!\n");
 else
 {
  printf("\n\n\n\n\t  ELEMENT DELETED IS  %d",front->info);
  front=front->next;
  p->next=NULL;
  free(p);
 }
 getch();
}
int icp(char opn)
{
 int vn;
 switch(opn)
 {
   case'+' :     vn=1;
		 break;

   case'-' :     vn=1;
		 break;

   case'*' :     vn=2;
		 break;

   case'/' :     vn=2;
		 break;

   case'%' :     vn=2;
		 break;

   case'^' :     vn=4;
		 break;

   case'$' :     vn=5;
		 break;

   case'(' :     vn=6;
		 break;
 }
 return(vn);
}
int isp(char opm)
{
 int vm;
 switch(opm)
 {
   case'+' :     vm=1;
		 break;

   case'-' :     vm=1;
		 break;

   case'*' :     vm=2;
		 break;

   case'/' :     vm=2;
		 break;

   case'%' :     vm=2;
		 break;

   case'^' :     vm=3;
		 break;

   case'$' :     vm=5;
		 break;

   case'(' :     vm=0;
		 break;

   case'#' :     vm=-1;
		 break;
 }
 return(vm);
}
/*-------------------------------------------------------------------------*/
/*       FUNCTION :   POSTFIX()                                            */
/*       OBJECTIVE :  TO CONVERT INFIX TO POSTFIX EXPRESSION               */
/*       PARAMETERS : CHAR STR[80]                                         */
/*-------------------------------------------------------------------------*/
void postfix(char str[40])
{
 int j=0,k=1,top=0,i;
 char stack[20],x;
 stack[0]='#';
 printf("\n\n\n\n     INPUT    OUTPUT           STACK \n\n");
 do
 {
  if(str[k-1]!='\0')
   printf("\n\n\t%c\t",str[k-1]);
  top=1;
  for(j=0;j<k;j++)
  {
   if(j<strlen(str))
   {
    x=str[j];
    if(isalpha(x)!=0)
    {
      printf("%c",x);
    }
    else
    {
     if(top==1)
     {
       stack[1]=x;
       top++;
     }
     else if(stack[top-1] == '(')
     {
       stack[top]=x;
       top++;
     }
     else
     {
       do
       {
	 if(icp(x)>isp(stack[top-1]))
	 {
	   stack[top]=x;
	   top++;
	 }
	 else
	 {
	   while(icp(x)<=isp(stack[top-1]))
	   {
	     printf("%c",stack[top-1]);
	     top=top-1;
	   }
	 }
       }while(icp(x)>isp(stack[top-1])  && x!='(' && x!='^');
     }
     if(x==')')
     {
       while(stack[top-1]!='(')
       {
	 if(stack[top-1]!=')')
	   printf("%c",stack[top-1]);
	 top=top-1;
       }
       top=top-1;
     }
    }
   }
  }
  if(k<strlen(str))
  {
    printf("\t\t");
    for(i=0;i<top;i++)
      printf("%c",stack[i]);
  }
  k++;
 }while(k<strlen(str)+1);
 while(top>1 && stack[top-1]!='#')
 {
   printf("%c",stack[top-1]);
   top=top-1;
 }
 printf("\t\t");
 for(i=0;i<top;i++)
    printf("%c",stack[i]);
 getch();
}
/*-------------------------------------------------------------------------*/
/*       FUNCTION :   EVALUATE()                                           */
/*       OBJECTIVE :  TO EVALUATE POSTFIX EXPRESSION                       */
/*       PARAMETERS : VOID                                                 */
/*-------------------------------------------------------------------------*/
void evaluate(char exp[30])
{
  float bin[30],a,t1,t2,t3;
  int top=0,i=0,dt=0,k=1,stack[30],y=0;
  while(exp[i]!='\0')
  {
    if(isalpha(exp[i]))
    {
      printf("\n\n\tENTER THE VALUE OF %c : ",exp[i]);
      scanf("%f",&a);
      dt=dt+1;
      bin[dt]=a;
    }
    i++;
  }
  printf("\n\n\n       TOKEN   STACK      OPERATION\n\n");
  do
  {
  if(exp[k-1]!='\0')
    printf("\n\n\t%c\t",exp[k-1]);
    top=0,dt=0;
    for(i=0;i<k;i++)
    {
     if(i<strlen(exp))
     {
      if(isalpha(exp[i]))
      {
	y=1;
	dt=dt+1;
	top=top+1;
	stack[top]=bin[dt];
      }
      else
      {
	switch(exp[i])
	{
	  case'^':
		   t1=stack[top];
		   top=top-1;
		   t2=stack[top];
		   top=top-1;
		   t3=pow(t2,t1);
		   top=top+1;
		   stack[top]=t3;
		   printf("\b\b\b\b\b");
		   y=2;
		   break;
	  case'/':
		   t1=stack[top];
		   top=top-1;
		   t2=stack[top];
		   top=top-1;
		   t3=t2/t1;
		   top=top+1;
		   stack[top]=t3;
		   y=3;
		   printf("\b\b\b\b\b");
		   break;
	  case'*':
		   t1=stack[top];
		   top=top-1;
		   t2=stack[top];
		   top=top-1;
		   t3=t2*t1;
		   top=top+1;
		   stack[top]=t3;
		   printf("\b\b\b\b\b");
		   y=4;
		   break;
	  case'+':
		   t1=stack[top];
		   top=top-1;
		   t2=stack[top];
		   top=top-1;
		   t3=t2+t1;
		   top=top+1;
		   stack[top]=t3;
		   printf("\b\b\b\b\b");
		   y=5;
		   break;
	  case'-':
		   t1=stack[top];
		   top=top-1;
		   t2=stack[top];
		   top=top-1;
		   t3=t2-t1;
		   top=top+1;
		   stack[top]=t3;
		   printf("\b\b\b\b\b");
		   y=6;
		   break;
	}
      }
      printf("%d ",stack[top]);
     }
    }
    if(y==1)
       printf("\t   PUSH");
    if(y==2)
       printf("\t   SQUARE");
    if(y==3)
       printf("\t   DIVISION");
    if(y==4)
       printf("\t   MULTIPLY");
    if(y==5)
       printf("\t   ADDITION");
    if(y==6)
       printf("\t   SUBTRACTION");
    k++;
  }while(k<strlen(exp)+1);
  printf("\n\n\n\n\tTHE EVALUATION RESULT IS  %f",t3);
  getch();
}
/*-------------------------------------------------------------------------*/
/*       FUNCTION :   ERROR()                                              */
/*       OBJECTIVE :  TO EXPRESSION FIND THE VALID EXPRESSION              */
/*       PARAMETERS : CHAR STR[40]                                         */
/*-------------------------------------------------------------------------*/
int error(char str[40])
{
  int j=0,flag=0,m,bk=0,bt=0,alp=0,nes=0;
  char x;
  while(j<strlen(str))
  {
    x=str[j];
    if(x=='(')
    {
      if(alp==0 && nes==0)
	bk++,bt++;
      j++;
    }
    else if(isalpha(x)!=0)
    {
      if(nes==0)
	flag++;
      alp=1,j++;
      if(j<strlen(str))
	x=str[j];
      if(x=='+')
	flag++,j++,alp=0;
      if(x=='-')
	flag++,j++,alp=0;
      if(x=='*')
	flag++,j++,alp=0;
      if(x=='/')
	flag++,j++,alp=0;
      if(x=='%')
	flag++,j++,alp=0;
      if(x=='^')
	flag++,j++,alp=0;
      if(x=='$')
	flag++,j++,alp=0;
    }
    else if(x==')')
    {
      bk++,bt--,j++,nes=1;
      if(j<strlen(str))
	x=str[j];
      if(x=='+')
	flag++,j++,nes=0;
      if(x=='-')
	flag++,j++,nes=0;
      if(x=='*')
	flag++,j++,nes=0;
      if(x=='/')
	flag++,j++,nes=0;
      if(x=='%')
	flag++,j++,nes=0;
      if(x=='^')
	flag++,j++,nes=0;
      if(x=='$')
	flag++,j++,nes=0;
    }
    else
     j++;
  }
  flag=flag+bk;
  if(flag==strlen(str) && bt==0)
     m=1;
  else
     m=0;
  return(m);
}
/*=========================================================================*/
/*                END        OF        THE       PROGRAM                   */
/*=========================================================================*/
