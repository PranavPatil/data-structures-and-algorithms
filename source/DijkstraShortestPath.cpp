/*=========================================================================*/
/*        ASSIGNMENT NO : 14                SUBJECT : DSF                  */
/*        DATE OF COMPLETION : 22-3-03      CLASS   : SE IT                */
/*=========================================================================*/
/* PROBLEM STATEMENT ::  REPRESENT A GIVEN GRAPH USING ADJACENCY LIST OR   */
/*                       ARRAY AND FIND THE SHORTEST PATH USING DIJKSTRA`S */
/*                       ALGORITHM                                         */
/*=========================================================================*/

#include<stdio.h>
#include<conio.h>
#define  infinity   999


/*    ***********  DECLARATION    OF    ALL    FUNCTIONS   ***********     */

 void dijkstra(int b[150],int no);

/*=========================================================================*/
/*	                START OF THE MAIN FUNCTION                         */
/*=========================================================================*/

void main()
{
  char ch,ch1;
  int s,no,i,j,k,h,b[150];
  do
  {
   clrscr();
   printf("\n\n\t=======================================================");
   printf("\n\n\t              **********  MENU  ************");
   printf("\n\n\t=======================================================");
   printf("\n\n\n\n\t\t 1> CREATE GRAPH ");
   printf("\n\n\t\t 2> DISPLAY ");
   printf("\n\n\t\t 3> DIJKSTRA'S ALGORITHM ");
   printf("\n\n\t\t 4> EXIT    ");
   printf("\n\n\n\t\t  ENTER YOUR CHOICE : ");
   scanf("%c",&ch1);
   switch(ch1)
   {
    case '1':
	      clrscr();
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
	      dijkstra(b,no);
	      getch();
	      break;
    case '4':
	      break;
   }
  }while(ch1 != '4');
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :    DIJKSTRA()                                          */
/*       OBJECTIVE :   TO FIND SHORTEST PATH USING DIJKSTRA'S ALGORITHM    */
/*       PARAMETERS :  ADJACENCY MATRIX AND NO OF NODES INSERTED NODES     */
/*-------------------------------------------------------------------------*/

 void dijkstra(int b[150],int no)
 {
   int  a[50],c[50],d[50],i,v,j,k,start,end,x=infinity,val,m=infinity,n;
   int flag1=0,u=0,g,temp[50],tp=0;
   clrscr();
   printf("\n\n\n\t====================================================");
   printf("\n\n\n\t***  DIJKSTRA'S ALGORITHM FOR SHORTEST PATH ***");
   printf("\n\n\n\t====================================================");
   for(i=0;i<no;i++)
   {
     a[i] = 0;
   }
   for(i=0;i<no;i++)
   {
     c[i] = 0;
   }
   for(i=0;i<no;i++)
   {
     d[i] = infinity;
   }
   printf("\n\n\n\n\t   ENTER THE FIRST NODE AND LAST NODE OF THE PATH");
   printf("\n\n\n\t   START NODE  : ");
   scanf("%d",&start);
   printf("\n\n\n\t   LAST NODE   : ");
   scanf("%d",&end);
   a[u] = start;
   u++;
   c[start-1] = 1;
   d[start-1] = 0;

   v = start-1;
  while(flag1 == 0)
  {
    x,val=infinity,m=infinity,n=0;
   for(k=0;k<no;k++)
   {
     if(c[k] == 1)
     {
       for(i=0;i<no;i++)
       {
	 val=infinity,x=infinity;
	 if(c[i] != 1 && b[i+no*k] != 0)
	 {
	   val = d[v] +  b[i+no*k];
	   if(val < d[i])
	   {
	     x = val;
	     d[i] = val;
	   }
	   else if(val > d[i])
	     x = d[i];
	   if(x < m)
	   {
	     m = x;
	     n = i;
	     g = k;
	   }
	 }
       }
     }
   }
   a[u] = n+1;
   u++;
   c[n] = 1;
   v = n;
   if(n == end-1)
      flag1 = 1;
 }
  printf("\n\n\n\n\n\t   SHORTEST PATH BETWEEN NODE %d AND NODE %d",start,end);
  flag1=0;
  for(j=0;j<u;j++)
  {
    if(flag1 == 0 || a[j] == end)
    {
      temp[tp] = a[j];
      tp++;
    }
    if(a[j] == g+1)
       flag1=1;
  }
  printf("\n\n\n\n\t\t");
  for(j=0;j<tp;j++)
     printf("   %d",temp[j]);
  printf("\n\n\n\n\n\t\tWEIGHT OF THE GRAPH = %d",d[end-1]);
  getch();
 }
