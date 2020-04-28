/*=========================================================================*/
/*        ASSIGNMENT NO : 15                 SUBJECT : DSF                 */
/*        DATE OF COMPLETION : 26-3-03      CLASS   : SE IT                */
/*=========================================================================*/
/* PROBLEM STATEMENT ::  REPRESENT A GIVEN GRAPH USING ADJACENCY LIST OR   */
/*                       ARRAY AND GENERATE A MINIMUM SPANNING TREE USING  */
/*                       KRUSTAL'S AND PRIME'S ALGORITHMS                  */
/*=========================================================================*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


/*    ***********  DECLARATION    OF    ALL    FUNCTIONS   ***********     */

 void krustal(int a[50],int b[150],int c[50],int no);
 void prim(int a[50],int b[150],int c[50],int no);

/*=========================================================================*/
/*	    START OF THE MAIN FUNCTION                                     */
/*=========================================================================*/

void main()
{
  char ch,ch1;
//  int *a=0,*b=0,*c=0;
  int s,no,i,j,k,h,sum=0,val=0,a[50],b[150],c[50];
/*  b = (int*)malloc(sizeof(no*no*sizeof(int)));
  c = (int*)malloc(sizeof(no*sizeof(int)));
  a = (int*)malloc(sizeof(no*sizeof(int)));*/
  do
  {
   clrscr();
   printf("\n\n\t=======================================================");
   printf("\n\n\t              **********  MENU  ************");
   printf("\n\n\t=======================================================");
   printf("\n\n\n\n\t\t 1> CREATE GRAPH ");
   printf("\n\n\t\t 2> DISPLAY ");
   printf("\n\n\t\t 3> PRIM'S ALGORITHM ");
   printf("\n\n\t\t 4> KRUSTAL ALGORITHM ");
   printf("\n\n\t\t 5> EXIT    ");
   printf("\n\n\n\t\t  ENTER YOUR CHOICE : ");
   scanf("%c",&ch1);
   switch(ch1)
   {
    case '1':
	      clrscr();
	      //*a=NULL,*b=NULL,*c=NULL;
	      printf("\n\n\t============================================");
	      printf("\n\n\n\t      INSERTION    OF    THE    GRAPH       ");
	      printf("\n\n\n\t============================================");
	      printf("\n\n\n\n\n\t  ENTER THE NO OF NODES TO BE INSERTED : ");
	      scanf("%d",&no);
	      for(i=0;i<no*no;i++)
		b[i] = 0;
	      for(i=0;i<no;i++)
	      {
	       do
	       {
		printf("\n\n\n\t  ");
		printf("ENTER THE CONNECTED VERTICES FOR VERTEX  %d : ",i+1);
		scanf("%d",&s);
		if(s<no+1 && s>0 && b[i*no+(s-1)] == 0 && i+1 != s)
		{
		 printf("\n\n\n\t  ENTER THE DISTANCE BETWEEN %d AND %d : ",i+1,s);
		 scanf("%d",&h);
		 b[i*no+(s-1)] = h;
		 b[(s-1)*no+i] = h;
		}
		else if(s<no+1 && s>0 && b[i*no+(s-1)] != 0 && i+1 != s)
		{
		 printf("\n\n\n\t  THE DISTANCE BETWEEN %d AND %d : ",i+1,s);
		 h = b[i*no+(s-1)];
		 printf("%d",h);
		}
		else if(s<no+1 && s>0 && b[i*no+(s-1)] == 0 && i+1 == s)
		{
		 printf("\n\n\n\t  THE DISTANCE BETWEEN %d AND %d : 0",i+1,s);
		}
		//printf("\n\n\t\t S = %d",s);
	       }while(s<no+1 && s>0);
	      }
	      getch();
	      break;
    case '2':
	      clrscr();
	      char an;
	      printf("\n\n\t===============================================");
	      printf("\n\n\t ********    DISPLAYING THE GRAPH     ********");
	      printf("\n\n\t===============================================");
	      printf("\n\n\n\n\n\t\t THE GRAPH IS  : \n\n\n\n\n\t\t");
	      printf("DISPLAYING THE ADJENCY MATRIX \n\n\n\n\n\t\t\t");
	      for(i=0;i<no*no;i++)
	      {
		printf("    %d",b[i]);
		if((i+1) % no == 0)
		  printf("\n\n\t\t\t");
	      }
	      getch();
	      break;
    case '3':
	      prim(a,b,c,no);
	      getch();
	      break;
    case '4':
	      krustal(a,b,c,no);
	      getch();
	      break;
    case '5':
	      exit(1);
   }
  }while(ch1 != '5');
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :    PRIM()                                              */
/*       OBJECTIVE :   TO FIND MIN SPANNING TREE USING PRIM'S AGORITHM     */
/*       PARAMETERS :  ADJACENCY MAT & MAT TO CHECK TRAVERSAL, STORE NODES */
/*       RETURN TYPE : VOID     					   */
/*-------------------------------------------------------------------------*/

void prim(int a[50],int b[150],int c[50],int no)
{
  clrscr();
  int flag1=0,flag2=0,x=0,sum=0,val=100,u=0,h=0,i,k,j;
  printf("\n\n\t===============================================");
  printf("\n\n\t   ****         PRIM'S ALGORITHM        ****  ");
  printf("\n\n\t===============================================");
  for(i=0;i<no;i++)
     a[i] = 0;
  a[0] = 1;
  c[h] = 1;
  h++;
  while(flag1 == 0)
  {
    flag2=0,x=0,val=100;
    for(k=0;k<no;k++)
    {
      if(a[k] == 1)
      {
       for(i=0;i<no;i++)
       {
	if(a[i] != 1 && b[i+no*k] != 0)
	  if(val > b[i+no*k])
	{
	  val = b[i+no*k];
	  x = i;
	}
       }
      }
    }
    sum = sum + val;
    c[h] = x+1;
    h++;
    a[x] = 1;
    i = 0;
    while(flag2 == 0 && i<no)
    {
      if(a[i] == 0)
	flag2=1;
      i++;
    }
    if(flag2 == 1)
    {
     for(j=0;j<no;j++)
     {
       int y= (i-1)*no+j;
       if(b[y] != 0)
	 u = 1;
     }
     if(u ==0)
       flag1=1;
    }
    else
      flag1 = 1;
  }
  printf("\n\n\n\n\n\t   VERTICES TRAVERSED OF MINIMUM SPANNING TREE \n\n\n");
  for(i=0;i<no;i++)
  {
    printf("\n\n\n\t\tVERTEX =  %d",c[i]);
  }
  printf("\n\n\n\n\n\t\tWEIGHT OF THE GRAPH = %d",sum);
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :    KRUSTAL()                                           */
/*       OBJECTIVE :   TO FIND MIN SPANNING TREE USING KRUSTAL'S AGORITHM  */
/*       PARAMETERS :  ADJACENCY MAT & MAT TO CHECK TRAVERSAL, STORE NODES */
/*       RETURN TYPE : VOID     					   */
/*-------------------------------------------------------------------------*/

void krustal(int a[50],int b[150],int c[50],int no)
{
  clrscr();
  int flag1=0,flag2,x=0,sum=0,val,u=0,i,j,h=0,va=0,k,g,y=0,iter=0;
  printf("\n\n\t===============================================");
  printf("\n\n\t   ****        KRUSTAL ALGORITHM        ****  ");
  printf("\n\n\t===============================================");

  for(i=0;i<no;i++)
    c[i] = 0;
  for(i=0;i<no;i++)
    a[i] = 0;
  a[0] = 1;

  while(flag1 == 0)
  {
   flag2=0,x=0,val=100;
   if(iter == 0)
   {
    for(i=0;i<no;i++)
    {
     for(j=0;j<no;j++)
     {
      if(val > b[j+no*i] && b[j+no*i] != 0)
      {
	val = b[j+no*i];
	x = j;
	y = i;
      }
     }
    }
    sum = sum + val;
    c[h] = x+1;
    h++;
    c[h] = y+1;
    h++;
    a[x] = 1;
    a[y] = 1;
    iter++;
   }
   else if(iter!=0)
   {
     for(k=0;k<no;k++)
     {
       if(a[k] == 1)
       {
	 for(i=0;i<no;i++)
	 {
	   if(a[i] != 1 && b[i+no*k] != 0 && val > b[i+no*k])
	   {
	     val = b[i+no*k];
	     x = i;
	   }
	 }
       }
     }
     sum = sum + val;
     c[h] = x+1;
     h++;
     a[x] = 1;
   }
   i = 0;
   while(flag2 == 0 && i<no)
   {
     if(a[i] == 0)
       flag2=1;
     i++;
   }
   if(flag2 == 1)
   {
     for(j=0;j<no;j++)
     {
       int y= (i-1)*no+j;
       if(b[y] != 0)
	 u = 1;
     }
     if(u ==0)
       flag1=1;
   }
   else
     flag1 = 1;
  }
  printf("\n\n\n\n\n\t   VERTICES TRAVERSED OF MINIMUM SPANNING TREE \n\n\n");
  for(i=0;i<no;i++)
  {
    printf("\n\n\n\t\tVERTEX =  %d",c[i]);
  }
  printf("\n\n\n\n\n\t\tWEIGHT OF THE GRAPH = %d",sum);
}

/*=========================================================================*/
/*                END        OF        THE       PROGRAM                   */
/*=========================================================================*/
