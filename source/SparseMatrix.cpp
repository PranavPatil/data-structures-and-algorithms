/*=========================================================================*/
/*        DATE OF COMPLETION : 2-2-03      CLASS   : SE IT                 */
/*=========================================================================*/
/* PROBLEM STATEMENT ::  REPRESENT SPARSE MATRIX USING ARRAY AND PERFORM   */
/*                       MATRIX ADDITION OR SIMPLE AND FAST TRANSPOSE      */
/*=========================================================================*/
#include<stdio.h>
#include<conio.h>
#include<process.h>
#define SIZE 10

typedef struct sparse
{
 int row,col,val;
}spr;

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   READMAT()                                            */
/*       OBJECTIVE :  TO ACCEPT MATRIX                                     */
/*       PARAMETERS : INT ARRAY , INT , INT                                */
/*-------------------------------------------------------------------------*/
void readmat(int a[][SIZE],int m,int n)
{
  int i,j;
  for(i=0;i<n;i++)
  {
    for(j=0;j<m;j++)
    {
     scanf("%d",&a[i][j]);
    }
  }
}
/*          *************** FUNCTION TO PRINT LINE ***************         */
void line(void)
{
 printf("\n     ==============================================================\n");
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   MAKESPARSE()                                            */
/*       OBJECTIVE :  TO MAKE SPARSE MATRIX                                */
/*       PARAMETERS : INT ARRAY , INT , INT , STRUCT                       */
/*-------------------------------------------------------------------------*/
makesparse(int a[][SIZE],int m,int n,spr s1[])
{
  int i,j,k=1,w=0;
  for(i=0;i<n;i++)
    for(j=0;j<m;j++)
      if(a[i][j]!=0)
      {
	s1[k].row=i;
	s1[k].col=j;
	s1[k].val=a[i][j];
	k++,w++;
      }
  s1[0].row=m;
  s1[0].col=n;
  s1[0].val=w;
  return(k);
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   DISPLAY_SPR()                                        */
/*       OBJECTIVE :  TO DISPLAY SPARSE MATRIX                             */
/*       PARAMETERS : STRUCT , INT                                         */
/*-------------------------------------------------------------------------*/
void display_spr(spr s[],int n)
{
 int i;
 printf("\n\n\t    ===========================\n\n");
 printf("\t       ROW     COL     VAL\n\n");
 printf("\t    ===========================\n\n");
 for(i=0;i<n;i++)
 {
  printf("\t\t%d\t%d\t%d\n\n",s[i].row,s[i].col,s[i].val);
 }
 printf("\t    ===========================\n\n");
}
/*      *************** DECLARATION OF ALL FUNCTIONS ***************       */

void transpose(spr s1[]);
void fasttranspose(spr s1[]);
void add(int n1,int n2,spr s1[],spr s2[]);

/*=========================================================================*/
/*	    START OF THE MAIN FUNCTION                                     */
/*=========================================================================*/
void main(void)
{
  int a[SIZE][SIZE],b[SIZE][SIZE],i,j,k,m,n,n1,n2,n3,ch;
  spr s1[SIZE],s2[SIZE];
  do
  {
   clrscr();
   line();
   printf("\n\n\t\t\t## ENTER THE MATRIX A ##\n\n");
   line();
   printf("\n\n\n\t    SIZE OF MATRIX A :");
   scanf("%d %d",&n,&m);
   printf("\n\n\n\t    PLEASE INPUT THE MATRIX :");
   readmat(a,m,n);
   n1=makesparse(a,m,n,s1);
   printf("\n\n");
   line();
   printf("\n\n\n\t\t     ****   MATRIX  A   ****\n\n");
   line();
   printf("\n\n\n");
   display_spr(s1,n1);
   getch();
   clrscr();
   line();
   printf("\n\n\t\t\t## ENTER THE MATRIX B ##\n\n");
   line();
   printf("\n\n\n\t    SIZE OF MATRIX B :");
   scanf("%d %d",&n,&m);
   printf("\n\n\t    PLEASE INPUT THE MATRIX :");
   readmat(b,m,n);
   n2=makesparse(b,m,n,s2);
   line();
   printf("\n\n\n\t\t     ****   MATRIX  B   ****\n\n");
   line();
   printf("\n\n\n");
   display_spr(s2,n2);
   getch();
   do
   {
    clrscr();
    line();
    printf("\n\n\t\t    ************** MENU **************\n\n");
    line();
    printf("\n\n\n\t   1:  ADD");
    printf("\n\n\t   2:  SIMPLE TRANSPOSE");
    printf("\n\n\t   3:  FAST TRANSPOSE");
    printf("\n\n\t   4:  EXIT");
    printf("\n\n\n\t   ENTER YOUR CHOICE :  ");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
	      add(n1,n2,s1,s2);
	      break;
      case 2:
	      clrscr();
	      line();
	      printf("\n\n\t    TRANSPOSE OF MATRIX\n\n");
	      line();
	      transpose(s1);
	      transpose(s2);
	      getch();
	      break;
      case 3:
	      clrscr();
	      line();
	      printf("\n\n\t     FAST TRANSPOSE OF MATRIX\n\n");
	      line();
	      fasttranspose(s1);
	      getch();
	      fasttranspose(s2);
	      getch();
	      break;
      case 4:
	      exit(0);
	      break;
     default:
	      printf("\n\n\tERROR IN THE INPUT !!");
	      getch();
	      break;
    }
   }while(ch!=4);
  }while(ch==5);
   getch();
}

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   STACKOP()                                            */
/*       OBJECTIVE :  TO PERFORM ADDITION OF SPARSE MATRICES               */
/*       PARAMETERS : INT , INT , STRUCT ,STRUCT                           */
/*-------------------------------------------------------------------------*/
 void add(int n1,int n2,spr s1[],spr s2[])
 {
    int i1,i2,i3,n3;
    spr s3[SIZE];
    i1=i2=i3=1;
    s3[0].row=s1[0].row>s2[0].row ? s1[0].row:s2[0].row;
    s3[0].col=s1[0].col>s2[0].col ? s1[0].col:s2[0].col;
    while(i1<n1 && i2<n2)
    {
     if(s1[i1].row==s2[i2].row)
     {
      if(s1[i1].col==s2[i2].col)
      {
       s3[i3].row=s1[i1].row;
       s3[i3].col=s1[i1].col;
       s3[i3].val=s1[i1].val + s2[i2].val;
       i3++,i2++,i1++;
      }
      else if(s1[i1].col<s2[i2].col)
      {
       s3[i3].row=s1[i1].row;
       s3[i3].col=s1[i1].col;
       s3[i3].val=s1[i1].val;
       i1++,i3++;
      }
      else if(s1[i1].col>s2[i2].col)
      {
       s3[i3].row=s2[i2].row;
       s3[i3].col=s2[i2].col;
       s3[i3].val=s2[i2].val;
       i3++,i2++;
      }
     }
     else
     {
      if(s1[i1].row<s2[i2].row)
      {
       s1[i3].row=s2[i1].row;
       s1[i3].col=s2[i1].col;
       s1[i3].val=s2[i1].val;
       i3++,i1++;
      }
      if(s1[i1].row>s2[i2].row)
      { s3[i3].row=s2[i2].row;
	s3[i3].col=s2[i2].col;
	s3[i3].val=s2[i2].val;
	i2++,i3++;
      }
     }
    }
     while(i2<n2)
     {
      s3[i3].row=s2[i2].row;
      s3[i3].col=s2[i2].col;
      s3[i3].val=s2[i2].val;
      i2++,i3++;
     }
     while(i1<n1)
     {
      s3[i3].row=s1[i1].row;
      s3[i3].col=s1[i1].col;
      s3[i3].val=s1[i1].val;
      i1++,i3++;
     }
     n3=i3;
     s3[0].val=n3-1;
     printf("\n\n\t  ADDED MATRIX = \n");
     display_spr(s3,n3);
     flushall();
     getch();
     return;
 }

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   TRANSPOSE()                                          */
/*       OBJECTIVE :  TO FIND TRANSPOSE OF SPARSE MATRIX                   */
/*       PARAMETERS : STRUCTURE SPR D[]                                    */
/*-------------------------------------------------------------------------*/
 void transpose(spr d[])
 {
   int g=0,i,j;
   spr f[SIZE];
   for(i=0;i<d[0].col+1;i++)
   {
    for(j=0;j<d[0].val+1;j++)
    {
     if(d[j].col==i)
     {
      f[g].col=d[j].row;
      f[g].row=d[j].col;
      f[g].val=d[j].val;
      g++;
     }
    }
   }
   printf("\n\n\n\t   ROW\tCOLUMN\tVALUE\n\n\n");
   for(i=0;i<3;i++)
    printf("\t   %d",i+1);
printf("\n\n\t==============================\n\n");
    for(i=0;i<1;i++)
     printf("\n\n     %d",i);
    printf("\t   %d",d[0].row);
    printf("\t   %d",d[0].col);
    printf("\t   %d",d[0].val);
    for(i=0;i<d[0].val;i++)
    {
     printf("\n\n     %d",i+1);
     printf("\t   %d",f[i].row);
     printf("\t   %d",f[i].col);
     printf("\t   %d",f[i].val);
    }
    printf("\n\n");
 }

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   FASTTRANSPOSE()                                      */
/*       OBJECTIVE :  TO FIND FAST TRANSPOSE                               */
/*       PARAMETERS : STRUCTURE SPR C[]                                    */
/*-------------------------------------------------------------------------*/
void fasttranspose(spr c[])
 {
  static int cnt[10];
  static int pos[10];
  int p,i,j;
  spr f[SIZE];
  for(i=0;i<c[0].val+1;i++)
   cnt[c[i].col]++;
   printf("\n\n\tTHE COUNT AND THE POSITION ARRAYS ARE :");
   printf("\n\n\n\tCNT[COL] :");
   for(i=0;i<c[0].col;i++)
    printf("%2d",cnt[i]);
   for(i=0;i<c[0].col;i++)
   {
     pos[i] = pos[i-1] + cnt[i-1];
     pos[0]=0;
   }
   printf("\t\tPOS[COL] : ");
   for(i=0;i<c[0].col;i++)
    printf("%2d",pos[i]);
   for(i=0;i<c[0].val+1;i++)
   {
       p = pos[c[i].col];
      f[p].col=c[i].row;
      f[p].row=c[i].col;
      f[p].val=c[i].val;
      pos[c[i].col]++;
   }
   printf("\n\n\n\n\t   ROW\tCOLUMN\tVALUE\n\n\n");
   for(i=0;i<3;i++)
    printf("\t   %d",i+1);
   printf("\n\n\t==============================\n\n");
   for(i=0;i<1;i++)
     printf("\n\n     %d",i);
   printf("\t   %d",c[0].row);
   printf("\t   %d",c[0].col);
   printf("\t   %d",c[0].val);
   for(i=0;i<c[0].val;i++)
   {
     printf("\n\n     %d",i+1);
     printf("\t   %d",f[i].row);
     printf("\t   %d",f[i].col);
     printf("\t   %d",f[i].val);
   }
   printf("\n\n");
   line();
   printf("\n\n");
   flushall();
 }
/*=========================================================================*/
/*                     END      OF     THE      PROGRAM                    */
/*=========================================================================*/
