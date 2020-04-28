/*=========================================================================*/
/*        ASSIGNMENT NO : 18                 SUBJECT : DSF                 */
/*        DATE OF COMPLETION : 9-4-03      CLASS   : SE IT                 */
/*=========================================================================*/
/* PROBLEM STATEMENT ::  INSERTION AND DELETION OF A RECORD FROM A DIRECT  */
/*                       ACCESS FILE USING CHAINING WITH OR WITHOUT        */
/*                       REPLACEMENT					   */
/*=========================================================================*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>


 typedef struct stud
 {
   int roll;
   char name[40];
   int marks;
   long int pos;
 }s;

/*    ***********  DECLARATION    OF    ALL    FUNCTIONS   ***********     */


 void add(FILE *fp);
 void search(FILE *fp);
 void display(FILE *fp);
 int deleten(FILE *fp);
 void  create(FILE *fp);
 int chain(int roll);


/*=========================================================================*/
/*	             START OF THE MAIN FUNCTION                            */
/*=========================================================================*/

 void main()
 {
   int k;
   FILE *fp;
   char choice;
   do
   {
    clrscr();
    printf("\n\n\t=======================================================");
    printf("\n\n\t              **********  MENU  ************");
    printf("\n\n\t=======================================================");
    printf("\n\n\n\n\n\t\t\t1> CREATION OF FILES ");
    printf("\n\n\t\t\t2> ADDITION OF MORE FILES ");
    printf("\n\n\t\t\t3> DELETION OF RECORDS");
    printf("\n\n\t\t\t4> SEARCHING FOR RECORDS");
    printf("\n\n\t\t\t5> DISPLAYING THE RECORDS");
    printf("\n\n\t\t\t6> EXIT    ");
    printf("\n\n\n\t\t\tENTER YOUR CHOICE : ");
    scanf("%c",&choice);
    switch(choice)
    {
     case '1':
	       clrscr();
	       printf("\n\n\t================================================");
	       printf("\n\n\t     ******   CREATION OF A FILE   ******\n\n\t");
	       printf("================================================\n\n");
	       create(fp);
	       break;

     case '2':
	      clrscr();
	      printf("\n\n\t================================================");
	      printf("\n\n\t    ******** ADDING  A RECORD ********\n\n\t");
	      printf("================================================\n\n");
	      add(fp);
	      getch();
	      break;
     case '3':
	      clrscr();
	      printf("\n\n\t================================================");
	      printf("\n\n\t    *******   DELETING A RECORD   ******\n\n\t");
	      printf("================================================\n\n");
	      k = deleten(fp);
	      if(k == -1)
	      {
		printf("\n\n\n\t\t  DELETION NOT SUCCESSFUL !!!");
		getch();
	      }
	      getch();
	      break;
     case '4':
	      clrscr();
	      printf("\n\n\t================================================");
	      printf("\n\n\t    *******   SEARCHING A RECORD   ******\n\n\t");
	      printf("================================================\n\n");
	      search(fp);
	      getch();
	      break;
     case '5':
	      clrscr();
	      printf("\n\n\t================================================");
	      printf("\n\n\t    ****** DISPLAYING THE RECORDS ******\n\n\t");
	      printf("================================================\n\n");
	      display(fp);
	      break;
     case '6':
	      break;

    }
   }while(choice!='6');
 }


/*-------------------------------------------------------------------------*/
/*       FUNCTION :   CREATE()                                             */
/*       OBJECTIVE :  TO CREATE A NEW FILE                                 */
/*       PARAMETERS : FILE POINTER FP                                      */
/*       RETURN TYPE : VOID      					   */
/*-------------------------------------------------------------------------*/

 void create(FILE *fp)
 {
    char c,filename[12],name[30],name1[30];
    long int store,store1,store2,store3,store4,pos1;
    int k,m,l,marks1,marks,roll1,roll,i;
    s temp;
    printf("\n\n\n\n\t\t ENTER FILENAME  : ");
    flushall();
    gets(filename);

    if((fp=fopen(filename,"wb")) == NULL)
    {
      printf("\n\n\n\t\t ERROR IN OPENING THE FILE  !!!");
      getch();
      return;
    }
    for(i = 0;i < 20;i++)
    {
     temp.pos = -1;
     temp.roll = 0;
     fwrite(&temp,sizeof(s),1,fp);
    }
    fclose(fp);
    if((fp=fopen(filename,"rb+"))==NULL)
    {
     printf("\n\n\n\t\t  ERROR IN OPENING THE FILE  !!!");
     getch();
     return;
    }
    do{
       clrscr();
       printf("\n\n\t================================================");
       printf("\n\n\t    *******   STUDENT RECORD ENTRY   ******\n\n\t");
       printf("================================================\n\n");
       printf("\n\n\n\n\t\t NAME OF THE STUDENT : ");
       flushall();
       gets (name);
       printf("\n\n\n\t\t ROLL NUMBER : ");
       scanf("%d",&roll);
       k = chain(roll);
       printf("\n\n\n\t\t TOTAL : ");
       scanf("%d",&marks);

       fseek(fp,k*sizeof(s),0);
       store = ftell(fp);
       fread(&temp,sizeof(s),1,fp);

       if(temp.roll == 0)
       {
	fseek(fp,-(long)sizeof(s),1);
	temp.roll=roll;
	temp.marks=marks;
	temp.pos=-1;
	strcpy(temp.name,name);
	fwrite(&temp,sizeof(s),1,fp);
       }
       else
       {
	l = chain(temp.roll);

	if(l == k)
	{
	 while(temp.roll != 0)
	    fread(&temp,sizeof(s),1,fp);
	 fseek(fp,-(long)sizeof(s),1);
	 store1=ftell(fp);
	 temp.roll=roll;
	 temp.marks=marks;
	 temp.pos = -1;
	 strcpy(temp.name,name);
	 fwrite(&temp,sizeof(s),1,fp);
	 fseek(fp,k*sizeof(s),0);
	 fread(&temp,sizeof(s),1,fp);
	 while(temp.pos != -1);
	 {
	  fseek(fp,temp.pos,0);
	  fread(&temp,sizeof(s),1,fp);
	 }

	 fseek(fp,-(long)sizeof(s),1);
	 temp.pos = store1;
	 fwrite(&temp,sizeof(s),1,fp);
	}
	else
	{
	 roll1 = temp.roll;
	 marks1 = temp.marks;
	 pos1 = temp.pos;
	 strcpy(name1,temp.name);
	 while(temp.roll != 0)
	 {
	  fread(&temp,sizeof(s),1,fp);
	 }
	 if(temp.roll == 0)
	 {
	   fseek(fp,-(long)sizeof(s),1);
	   store3 = ftell(fp);
	   temp.roll = roll1;
	   temp.marks = marks1;
	   temp.pos = pos1;
	   strcpy(temp.name,name1);
	   fwrite(&temp,sizeof(s),1,fp);
	   fseek(fp,store,0);
	   temp.roll = roll;
	   temp.marks = marks;
	   strcpy(temp.name,name);
	   temp.pos = -1;
	   fwrite(&temp,sizeof(s),1,fp);
	 }
	 fseek(fp,l*sizeof(s),0);
	 fread(&temp,sizeof(s),1,fp);
	 while(temp.pos != store)
	 {
	  fseek(fp,temp.pos,0);
	  fread(&temp,sizeof(s),1,fp);
	 }

	 fseek(fp,-(long)sizeof(s),1);
	 temp.pos = store3;
	 fwrite(&temp,sizeof(s),1,fp);
	}
       }
       printf("\n\n\n\t\t DO YOU WANT TO CONTINUE (Y/N)  : ");
       flushall();
       scanf("%c",&c);
      }while(c == 'y' || c == 'Y');
     fclose(fp);
 }

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   ADD()                                                */
/*       OBJECTIVE :  TO ADD RECORDS IN THE FILE                           */
/*       PARAMETERS : FILE POINTER FP                                      */
/*       RETURN TYPE : VOID      					   */
/*-------------------------------------------------------------------------*/

 void add(FILE *fp)
 {
  char c,filename[12],name[30],name1[30];
  long int store,store1,store2,store3,store4,pos1;
  int k,m,l,marks,roll,marks1,roll1,i;
  s temp;
  printf("\n\n\n\n\t\t ENTER THE FILENAME  : ");
  flushall();
  gets(filename);

  if((fp=fopen(filename,"rb+"))==NULL)
  {
    printf("\n\n\n\t\t ERROR OPENING THE FILE  !!!");
    return;
  }
  do{
     clrscr();
     printf("\n\n\t================================================");
     printf("\n\n\t    *******   TO INSERT A RECORD   ******\n\n\t");
     printf("================================================\n\n");
     printf("\n\n\n\n\t\t NAME OF THE STUDENT :");
     flushall();
     gets(name);
     printf("\n\n\n\t\t ROLL NUMBER :");
     scanf("%d",&roll);
     k=chain(roll);
     printf("\n\n\n\t\t TOTAL :");
     scanf("%d",&marks);
     fseek(fp,k*sizeof(s),0);
     store=ftell(fp);
     fread(&temp,sizeof(s),1,fp);
     if(temp.roll==0)
     {
       fseek(fp,-(long)sizeof(s),1);
       temp.roll=roll;
       temp.marks=marks;
       temp.pos=-1;
       strcpy(temp.name,name);
       fwrite(&temp,sizeof(s),1,fp);
     }
     else
     {
      l=chain(temp.roll);
      if(l==k)
	{
	  while(temp.roll!=0)
	    fread(&temp,sizeof(s),1,fp);
	  fseek(fp,-(long)sizeof(s),1);
	  store1=ftell(fp);
	  temp.roll=roll;
	  temp.marks=marks;
	  temp.pos=-1;
	  strcpy(temp.name,name);
	  fwrite(&temp,sizeof(s),1,fp);
	  fseek(fp,k*sizeof(s),0);
	  fread(&temp,sizeof(s),1,fp);
	  while(temp.pos != -1)
	  {
	    fseek(fp,temp.pos,0);
	    fread(&temp,sizeof(s),1,fp);
	  }
	  fseek(fp,-(long)sizeof(s),1);
	  temp.pos=store1;
	  fwrite(&temp,sizeof(s),1,fp);
	}
      else
      {
       roll1=temp.roll;
       marks1=temp.marks;
       pos1=temp.pos;
       strcpy(name1,temp.name);
       while(temp.roll!=0)
       {
	 fread(&temp,sizeof(s),1,fp);
       }
      if(temp.roll==0)
      {
	fseek(fp,-(long)sizeof(s),1);
	store3 = ftell(fp);
	temp.roll = roll1;
	temp.marks = marks1;
	temp.pos = pos1;
	strcpy(temp.name,name1);
	fwrite(&temp,sizeof(s),1,fp);
	fseek(fp,store,0);
	temp.roll = roll;
	temp.marks = marks;
	strcpy(temp.name,name);
	temp.pos=-1;
	fwrite(&temp,sizeof(s),1,fp);
      }
      fseek(fp,l*sizeof(s),0);
      fread(&temp,sizeof(s),1,fp);
      while(temp.pos != store)
      {
       fseek(fp,temp.pos,0);
       fread(&temp,sizeof(s),1,fp);
      }

      fseek(fp,-(long)sizeof(s),1);
      temp.pos = store3;
      fwrite(&temp,sizeof(s),1,fp);
     }
    }
    printf("\n\n\n\t\t DO YOU WANT TO CONTINUE [Y/N]  : ");
    flushall();
    scanf("%c",&c);
  }while(c=='y'||c=='Y');
  fclose(fp);
 }

/*-------------------------------------------------------------------------*/
/*       FUNCTION :    CHAIN()                                             */
/*       OBJECTIVE :   TO GET THE ADDRESS OF THE CHAIN                     */
/*       PARAMETERS :  ROLL NO OF STUDENT                                  */
/*       RETURN TYPE : INTEGER      					   */
/*-------------------------------------------------------------------------*/

 int chain(int roll)
 {
   int k;
   k = roll % 20;
   return(k);
 }

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   DISPLAY()                                            */
/*       OBJECTIVE :  TO DISPLAY ALL THE RECORDS IN THE FILE               */
/*       PARAMETERS : FILE POINTER FP                                      */
/*       RETURN TYPE : VOID      					   */
/*-------------------------------------------------------------------------*/

 void display(FILE *fp)
 {
   s temp;
   int i=0;
   char filename[12];
   printf("\n\n\n\n\t\t ENTER THE NAME OF THE FILE : ");
   fflush(stdin);
   gets(filename);
   if((fp=fopen(filename,"rb"))==NULL)
   {
    printf("\n\n\n\t\t ERROR OPENING THE FILE !!! ");
    getch();
    return;
   }
   while(!feof(fp))
   {
     fread(&temp,sizeof(s),1,fp);
     if(temp.roll!=0)
     {
       if(i==2)
       {
	 i=0;
	 clrscr();
       }
      printf("\n\n ");
      printf("\n\n\t\t NAME        :  %s",temp.name);
      printf("\n\n\t\t ROLL NUMBER :  %d",temp.roll);
      printf("\n\n\t\t TOTAL       :  %d",temp.marks);
      i++;
      getch();
     }
   }
   fclose(fp);
 }

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   SEARCH()                                             */
/*       OBJECTIVE :  TO SEARCH THE RECORD IN THE FILE                     */
/*       PARAMETERS : FILE POINTER FP                                      */
/*       RETURN TYPE : VOID      					   */
/*-------------------------------------------------------------------------*/

 void search(FILE *fp)
 {
   s temp;
   int rno,k;
   char filename[12];
   printf("\n\n\n\t\t ENTER THE NAME OF THE FILE : ");
   fflush(stdin);
   gets(filename);
   if((fp=fopen(filename,"rb"))==NULL)
   {
    printf("\n\n\n\t\t ERROR OPENING THE FILE !!!");
    getch();
    return;
   }
   printf("\n\n\n\t\t ENTER THE ROLL NUMBER TO BE SEARCHED : ");
   scanf("%d",&rno);
   k=chain(rno);
   fseek(fp,k*sizeof(s),0);
   fread(&temp,sizeof(s),1,fp);

   if(temp.roll==rno)
   {
    printf("\n\n\n\n\t\t THE RECORD IS PRESENT & THE DETAILS ARE  : ");
    printf("\n\n\n\n\t\t NAME       :%s",temp.name );
    printf("\n\n\n\t\t ROLL NUMBER:%d",temp.roll  );
    printf("\n\n\n\t\t TOTAL      :%d",temp.marks);
    getch();
   }
   else
   {
     while(temp.pos != -1)
     {
       fseek(fp,temp.pos,0);
       fread(&temp,sizeof(s),1,fp);
       if(temp.roll == rno)
	  break;
     }
      if(temp.roll == rno)
      {
	 printf("\n\n\n\n\t\t THE RECORD IS PRESENT & THE DETAILS ARE: ");
	 printf("\n\n\n\t\t NAME       :%s",temp.name );
	 printf("\n\n\n\t\t ROLL NUMBER:%d",temp.roll  );
	 printf("\n\n\n\t\t MARKS      :%d",temp.marks);
	 getch();
      }
      else
      {
	printf("\n\n\n\n\t");
	printf("=====================================================");
	printf("\n\n\t\t     FILE NOT FOUND !!! \n\n\n\t");
	printf("=====================================================");
	getch();
      }
   }
   fclose(fp);
 }


/*-------------------------------------------------------------------------*/
/*       FUNCTION :   DELETEN()                                            */
/*       OBJECTIVE :  TO DELETE A FILE OR A PARTICULAR RECORD IN THE FILE  */
/*       PARAMETERS : FILE POINTER FP                                      */
/*       RETURN TYPE : INTEGER      					   */
/*-------------------------------------------------------------------------*/

 int deleten(FILE *fp)
 {
    s temp;
    int rno,k,ret=0;
    char c,filename[12];
    printf("\n\n\n\n\t\t ENTER THE NAME OF THE FILE  :");
    fflush(stdin);
    gets(filename);
    if((fp=fopen(filename,"rb+")) == NULL)
    {
     printf("\n\n\n\t\t ERROR OPENING THE FILE !!! ");
     getch();
     return(-1);
    }
    printf("\n\n\n\t\t ENTER THE ROLL NUMBER TO BE DELETED  : ");
    scanf("%d",&rno);
    k = chain(rno);
    fseek(fp,k*sizeof(s),0);
    fread(&temp,sizeof(s),1,fp);

    if(temp.roll == rno)
    {
     printf("\n\n\n\n\t\t\tTHE ROLL NUMBER IS FOUND AND THE DETAILS ARE : ");
     printf("\n\n\n\t\t\tNAME         : %s",temp.name);
     printf("\n\n\n\t\t\tROLL NUMBER    : %d",temp.roll);
     printf("\n\n\n\t\t\tMARKS          : %d",temp.marks);
     printf("\n\n\n\t\t\tDELETE (Y/N)  : ");
     fflush(stdin);
     scanf("%c",&c);
     if(c == 'y'  ||  c == 'Y')
     {
       fseek(fp,-(long)sizeof(s),1);
       temp.roll = 0;
       fwrite(&temp,sizeof(s),1,fp);
     }
     printf("\n\n\t\t\t    RECORDS SUCCESSFULLY DELETED !!!");
     getch();
     fclose(fp);
     ret = 0;
    }
    else
    {
      while(temp.roll != rno)
      {
	fseek(fp,temp.pos,0);
	fread(&temp,sizeof(s),1,fp);
	if(temp.pos == -1)
	  break;
      }
      if(temp.roll == rno)
      {
	printf("\n\n\n\n\t\t\tTHE ROLL NO IS FOUND AND THE DATAILS ARE : ");
	printf("\n\n\n\t\t\tNAME            : %s");
	printf("\n\n\n\t\t\tROLL NUMBER      : %d");
	printf("\n\n\n\t\t\tMARKS         : %d");
	printf("\n\n\n\t\t\tDELETE (Y/N) : %d");
	fflush(stdin);
	scanf("%c",&c);
	if( c == 'y' || c == 'Y')
	{
	  fseek(fp,-(long)sizeof(s),1);
	  temp.roll = 0;
	  fwrite(&temp,sizeof(s),1,fp);
	  printf("\n\n\n\t\t\t   RECORDS SUCCESSFULLY DELETED !!!");
	  getch();
	  fclose(fp);
	  ret = 0;
	}
      }
    }
    if(temp.pos == -1)
    {
      printf("\n\n\n\n\t");
      printf("=====================================================");
      printf("\n\n\t\t     FILE NOT FOUND !!! \n\n\n\t");
      printf("=====================================================");
      fclose(fp);
      ret = -1;
    }
    return(ret);
 }

/*--------------------------------------------------------------------------*/
/*          *+*+*+*+*+*+*+*+  END OF THE PROGRAM  *+*+*++*+*+*+*+*+         */
/*--------------------------------------------------------------------------*/
