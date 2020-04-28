/*=========================================================================*/
/*        ASSIGNMENT NO : 17                 SUBJECT : DSF                 */
  /*        DATE OF COMPLETION : 4-4-03      CLASS   : SE IT                 */
/*=========================================================================*/
/* PROBLEM STATEMENT ::  WRITE A PROGRAM TO IMPLEMENT SIMPLE INDEX FILE    */
/*=========================================================================*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct stud
{
 char name[20];
 int score1,score2,score3,roll;
 float total,percent;
};

/*    ***********  DECLARATION    OF    ALL    FUNCTIONS   ***********     */

void create(FILE *fp,FILE *ip);
void insert(FILE *);
void display(FILE *);
int search(FILE *,FILE *,char filename[10]);
void deleter(FILE *,FILE *ip,char filename[10]);
void modify(FILE *fp,FILE *ip,char filename[10]);
void sort(FILE *fp);
void index(FILE *fp,FILE *ip,char filename[10]);
void display_one(stud temp,int pos);
void append(FILE *fp,FILE *ip);
void line();
int us;

/*=========================================================================*/
/*	             START OF THE MAIN FUNCTION                            */
/*=========================================================================*/

 void main(void)
 {
   stud temp;
   FILE *fp,*ip;
   int c,i,flag,no,temp1,num;
   char choice,filename[10];
   do
   {
    clrscr();
    printf("\n\n\t=======================================================");
    printf("\n\n\t              **********  MENU  ************");
    printf("\n\n\t=======================================================");
    printf("\n\n\n\n\n\t\t\t1> CREATE ");
    printf("\n\n\t\t\t2> DISPLAY ");
    printf("\n\n\t\t\t3> INSERT ");
    printf("\n\n\t\t\t4> DELETE ");
    printf("\n\n\t\t\t5> MODIFY ");
    printf("\n\n\t\t\t6> SEARCH");
    printf("\n\n\t\t\t7> EXIT    ");
    printf("\n\n\n\t\t\tENTER YOUR CHOICE : ");
    scanf("%c",&choice);
    switch(choice)
    {
     case '1':
	       clrscr();
	       printf("\n\n\t================================================");
	       printf("\n\n\t     ******   CREATION OF A FILE   ******\n\n\t");
	       printf("================================================\n\n");
	       create(fp,ip);
	       break;

     case '2':
	      clrscr();
	      printf("\n\n\t================================================");
	      printf("\n\n\t    ******** DISPLAYING THE FILE ********\n\n\t");
	      printf("================================================\n\n");
	      display(fp);
	      getch();
	      break;
     case '3':
	      clrscr();
	      printf("\n\n\t================================================");
	      printf("\n\n\t    *******   TO INSERT A RECORD   ******\n\n\t");
	      printf("================================================\n\n");
	      append(fp,ip);
	      getch();
	      break;
     case '4':
	      clrscr();
	      printf("\n\t========================================================");
	      printf("\n\n\t          OPERATION TO DELETE THE FILE !! \n");
	      printf("\n\t========================================================\n");
	      printf("\n\n\n\n\t  ENTER THE FILE TO BE DELETED : ");
	      scanf("%s",&filename);
	      deleter(fp,ip,filename);
	      getch();
	      break;
     case '5':
	      clrscr();
	      printf("\n\n\t================================================");
	      printf("\n\n\t    ****** MODIFICATION OF FILES ******\n\n\t");
	      printf("================================================\n\n");
	      printf("\n\n\t  ENTER THE NAME OF THE FILE TO BE MODIFIED : ");
	      scanf("%s",&filename);
	      modify(fp,ip,filename);
	      break;
     case '6':
	      clrscr();
	      printf("\n\n\t================================================");
	      printf("\n\n\t   *********  SEARCHING OPERATION  *********\n");
	      printf("\n\t================================================");
	      printf("\n\n\n\n\t ENTER THE FILE NAME TO BE SEARCHED :: ");
	      fflush(stdin);
	      scanf("%s",&filename);
	      search(fp,ip,filename);
	      getch();
	      break;

     case '7':
	      exit(1);
  }
 }while(choice!='7');
}


/*-------------------------------------------------------------------------*/
/*       FUNCTION :   CREATE()                                             */
/*       OBJECTIVE :  TO CREATE A NEW FILE                                 */
/*       PARAMETERS : FILE POINTER,INDEX FILE POINTER                      */
/*       RETURN TYPE : VOID      					   */
/*-------------------------------------------------------------------------*/

  void create(FILE *fp,FILE *ip)
  {
     char filename[10];
     fseek(fp,0,SEEK_END);
     printf("\n\n\n\n\t  ENTER THE NAME OF THE FILE : ");
     flushall();
     gets(filename);
     if((fp = fopen(filename,"wb++")) == NULL)
     {
       printf("\n\n\n\n\t  ERROR IN OPENING THE FILE IN WRITE MODE !!!");
       return;
     }
     insert(fp);
     fclose(fp);
     if((fp = fopen(filename,"rb++"))==NULL)
     {
       printf("\n\n\n\n\t  ERROR IN OPENING THE FILE IN WRITE MODE !!!");
       return;
     }
     sort(fp);
     index(fp,ip,filename);
   }

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   INSERT()                                             */
/*       OBJECTIVE :  TO INSERT RECORDS IN THE FILE                        */
/*       PARAMETERS : FILE POINTER                                         */
/*       RETURN TYPE : VOID      					   */
/*-------------------------------------------------------------------------*/

  void insert(FILE *fp)
  {
     stud temp;
     int cnt=0,i=1;                     /* DECLARATION OF LOCAL VARIABLES */
     char ans,ch;
     fseek(fp,0,SEEK_END);
     do                             /* START OF DO-WHILE LOOP */
     {
      clrscr();                     /* CLEARING THE SCREEN */
      cnt++;
      printf("\n\n\t");
      printf("--------------------------------------------------------\n\n\t");
      printf("  ********** ENTER THE MARKS FOR STUDENT %d ***********\n\n",cnt);
      printf("\t--------------------------------------------------------\n\n");
      printf("\n\n\t####### RECORD OF STUDENTS MARKS IN THE EXAMINATION #######\n\n\n");
  /*--------------- ACCEPTING VALUES OF STRUCTURE ELEMENTS ----------------- */
      printf("\n\n\n\t RECORD NO :  %d",i);
      printf("\n\n\n\t ENTER THE NAME OF THE STUDENT : ");
      fflush(stdin);
      scanf("%s",temp.name);
      printf("\n\n\t ENTER THE ROLL NO OF THE STUDENT : ");
      scanf("%d",&temp.roll);
      printf("\n\n\t MARKS IN MATHEMATICS -3 = ");
      fflush(stdin);
      scanf("%2d",&temp.score1);
      printf("\n\n\t MARKS IN PHYSICS = ");
      fflush(stdin);
      scanf("%2d",&temp.score2);
      printf("\n\n\t MARKS IN CHEMISTRY = ");
      fflush(stdin);
      scanf("%2d",&temp.score3);
      printf("\n\n\txxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
      fwrite(&temp,sizeof(stud),1,fp);
      printf("\n\n\n\n\t DO YOU WANT TO INSERT ANOTHER RECORD (Y/N)....");
      fflush(stdin);
      ans=getche();
      us++,i++;
     }while(ans=='y'|| ans=='Y');     /* END OF DO-WHILE LOOP */
     fclose(fp);
  }

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   INDEX()                                              */
/*       OBJECTIVE :  TO ENTER THE RECORD ADDRESS IN THE INDEX FILE        */
/*       PARAMETERS : FILE POINTER,INDEX FILE POINTER,FILENAME             */
/*       RETURN TYPE : VOID      					   */
/*-------------------------------------------------------------------------*/

  void index(FILE *fp,FILE *ip,char filename[10])
  {
    int key;
    stud temp;
    if((fp = fopen(filename,"rb++"))== NULL)
    {
      printf("\n\n\n\t  ERROR IN OPENING THE FILE  !!!");
      return;
    }
    if((ip = fopen("index.file","wb++"))== NULL)
    {
      printf("\n\n\n\t  ERROR IN OPENING THE FILE  !!!");
      return;
    }
    while(!feof(fp))
    {
      fread(&temp,sizeof(stud),1,fp);
      key = temp.roll;
      fwrite(&key,sizeof(int),1,ip);
    }
    fclose(fp);
    fclose(ip);
  }

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   SORT()                                               */
/*       OBJECTIVE :  TO SORT THE RECORDS INSERTED IN THE FILE             */
/*       PARAMETERS : FILE POINTER                                         */
/*       RETURN TYPE : VOID      					   */
/*-------------------------------------------------------------------------*/

  void sort(FILE *fp)
  {
    stud temp1,temp2;
    int size = 0,i,j;
    while(!feof)
    {
      fread(&temp1,sizeof(stud),1,fp);
      size++;
    }
    size = size-2;
    for(i=0;i<size+1;i++)
    {
      for(j=i+1;j<size+1;j++)
      {
	fseek(fp,i*(sizeof(stud)),0);
	fread(&temp1,sizeof(stud),1,fp);
	fseek(fp,j*(sizeof(stud)),0);
	fread(&temp2,sizeof(stud),1,fp);
	if(temp1.roll > temp2.roll)
	{
	  fseek(fp,i*(sizeof(stud)),0);
	  fwrite(&temp2,sizeof(stud),1,fp);
	  fseek(fp,j*(sizeof(stud)),0);
	  fwrite(&temp1,sizeof(stud),1,fp);
	}
      }
    }
    fclose(fp);
  }

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   DISPLAY()                                            */
/*       OBJECTIVE :  TO DISPLAY ALL THE RECORDS IN THE FILE               */
/*       PARAMETERS : FILE POINTER                                         */
/*       RETURN TYPE : VOID      					   */
/*-------------------------------------------------------------------------*/

 void display(FILE *fp)
 {
  stud temp;
  char filename[10];
  int tot,i = 1;                   /* DECLARATION OF LOCAL VARIABLES */
  float avg;
  printf("\n\n\n\n\t  ENTER THE NAME OF THE FILE : ");
  scanf("%s",&filename);
  if((fp = fopen(filename,"rb++"))==NULL)
  {
    printf("\n\n\n\t  ERROR IN OPENING THE FILE IN WRITE MODE !!!");
    return;
  }
  fread(&temp,sizeof(stud),1,fp);
  while(!feof(fp))                   /* START OF WHILE LOOP */
  {
    clrscr();
    if(temp.roll != -1)
    {
      printf("\n\n\n\t\b\b\b\b");
      printf("=====================================================\n\n");
      printf("\t\b\b\b### RECORD OF STUDENTS MARKS IN THE EXAMINATION ###");
      printf("\n\n\n\t\t  RECORD NO :  %d",i);
      printf("\n\n\n\t\b\b\b\b");
      printf("-----------------------------------------------------");
      printf("\n\t\tNAME       ROLL NO        ");
      printf("\n\t\b\b\b\b");
      printf("-----------------------------------------------------\n\n");
      printf("\t        %s           %d  \n\n\n\t\b\b\b\b",temp.name,temp.roll);
      printf("=====================================================\n\n");
      printf("\n                MARKS OBTAINED\n\n\t\b\b\b\b");
      printf("=====================================================\n");
      printf("\n\n\n\tSUBJECT 1 = %d ",temp.score1);
      printf("\n\n\tSUBJECT 2  = %d ",temp.score2);
      printf("\n\n\tSUBJECT 3  = %d \n\n\n\t\b",temp.score3);
      printf("\b\b\b=====================================================");
      tot=0;
      tot=temp.score1+temp.score2+temp.score3;
      printf("\n\n\tTOTAL :: %d",tot);
      printf("\n");
      avg=0;
      avg=tot/3.0;
      printf("\n\n\tPERCENTAGE :: %f",avg);
      printf("\n\n\n\t");
      if(avg>=66)
		printf("RESULT :: FIRST CLASS WITH DISTINCTION ");
      if(avg<66&&avg>=60)
		printf("RESULT :: FIRST CLASS ");
      if(avg<60&&avg>=55)
		printf("RESULT :: HIGHER SECOND CLASS ");
      if(avg<55&&avg>=50)
		printf("RESULT :: SECOND CLASS ");
      if(avg<50&&avg>=40)
		printf("RESULT :: PASS CLASS ");
      if(avg<40)
		printf("RESULT :: FAIL ");
      printf("\n\n\t\b");
      printf("\b\b\b=====================================================");
      printf("\n\n\n\n\n\t PRESS ANY KEY TO CONTINUE......");
      getch();
    }
    else
       i++;
    fread(&temp,sizeof(stud),1,fp);
  }
    fclose(fp);
 }

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   DISPLAY_ONE()                                        */
/*       OBJECTIVE :  TO DISPLAY A SINGLE RECORD IN THE FILE               */
/*       PARAMETERS : FILE POINTER,POSITION OF THE RECORD IN THE FILE      */
/*       RETURN TYPE : VOID      					   */
/*-------------------------------------------------------------------------*/

 void display_one(stud temp,int pos)
 {
   int tot,no,key;              /* DECLARATION OF LOCAL VARIABLES */
   char filename[10];
   float avg;
   clrscr();
   printf("\n\n\n\t\b\b\b\b");
   printf("-----------------------------------------------------");
   printf("\n\t\tNAME       ROLL NO        ");
   printf("\n\n\n\t\t  RECORD NO :  %d",pos);
   printf("\n\t\b\b\b\b");
   printf("-----------------------------------------------------\n\n");
   printf("\t        %s           %d  \n\n\n\t\b\b\b\b",temp.name,temp.roll);
   printf("=====================================================\n\n");
   printf("\n                MARKS OBTAINED\n\n\t\b\b\b\b");
   printf("=====================================================\n");
   printf("\n\n\n\tSUBJECT 1 = %d ",temp.score1);
   printf("\n\n\tSUBJECT 2  = %d ",temp.score2);
   printf("\n\n\tSUBJECT 3  = %d \n\n\n\t\b",temp.score3);
   printf("\b\b\b=====================================================");
   tot=0;
   tot=temp.score1+temp.score2+temp.score3;
   printf("\n\n\tTOTAL :: %d",tot);
   printf("\n");
   avg=0;
   avg=tot/3.0;
   printf("\n\n\tPERCENTAGE :: %f",avg);
   printf("\n\n\n\t");
   if(avg>=66)
      printf("RESULT :: FIRST CLASS WITH DISTINCTION ");
   if(avg<66&&avg>=60)
      printf("RESULT :: FIRST CLASS ");
   if(avg<60&&avg>=55)
      printf("RESULT :: HIGHER SECOND CLASS ");
   if(avg<55&&avg>=50)
      printf("RESULT :: SECOND CLASS ");
   if(avg<50&&avg>=40)
      printf("RESULT :: PASS CLASS ");
   if(avg<40)
      printf("RESULT :: FAIL ");
   printf("\n\n\t\b");
   printf("\b\b\b=====================================================");
   printf("\n\n\n\n\n\t PRESS ANY KEY TO CONTINUE......");
   getch();
 }

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   SEARCH()                                             */
/*       OBJECTIVE :  TO SEARCH THE RECORD IN THE FILE                     */
/*       PARAMETERS : FILE POINTER,INDEX FILE POINTER,FILENAME             */
/*       RETURN TYPE : VOID      					   */
/*-------------------------------------------------------------------------*/

  int search(FILE *fp,FILE *ip,char filename[10])
  {
     stud temp;                    /* DECLARATION OF LOCAL VARIABLES */
     int tot,no,flag=0,key,pos=0,rollno,ret;
     float avg;
     if((fp = fopen(filename,"rb++"))==NULL)
     {
      printf("\n\n\n\n\t ERROR IN OPENING THE FILE IN WRITE MODE !!!");
      ret  = 0;
     }
     printf("\n\n\n\t ENTER THE ROLL NO OF THE RECORD TO SEARCH :: ");
     fflush(stdin);
     scanf("%d",&rollno);
     if((ip = fopen("index.file","rb++"))==NULL)
     {
      printf("\n\n\n\n\t ERROR IN OPENING THE FILE IN WRITE MODE !!!");
      ret = 0;
     }
     while((flag==0) && (!feof(ip)))     /* START OF WHILE LOOP */
     {
      fread(&key,sizeof(int),1,ip);
      if(key == rollno)
	flag = 1;
      pos++;
     }
     pos--;
     if(flag == 1)
     {
       fseek(fp,pos*(sizeof(temp)),0);
       fread(&temp,sizeof(temp),1,fp);
       display_one(temp,pos);
       ret = pos;
     }
     if(flag==0)
     {
       printf("\n\n\n\t");
       printf("=====================================================");
       printf("\n\n\t\t     FILE NOT FOUND !!! \n\n\n\t");
       printf("=====================================================");
       fclose(fp);
       fclose(ip);
       ret = -1;
     }
     return(ret);
  }

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   DELETER()                                            */
/*       OBJECTIVE :  TO DELETE A FILE OR A PARTICULAR RECORD IN THE FILE  */
/*       PARAMETERS : FILE POINTER,INDEX FILE POINTER,FILENAME             */
/*       RETURN TYPE : VOID      					   */
/*-------------------------------------------------------------------------*/

 void deleter(FILE *fp,FILE *ip,char filename[10])
 {
  stud temp;
  int tot,no,flag=0,key,pos=0,rollno;
  char ans,ch;
  printf("\n\n\n\t  ENTER TO DELETE THE FILE OR ONLY ONE RECORD : [F/R] : ");
  ch = getch();
  if((fp = fopen(filename,"rb++"))==NULL)
  {
    printf("\n\n\n\n\n\t  ERROR IN OPENING THE FILE IN WRITE MODE !!!");
    return;
  }
  if(ch=='r' || ch=='R')
  {
    printf("\n\n\n\n\t  ENTER THE ROLL NO OF STUDENT");
    printf("\n\n\n\t  WHOSE RECORD YOU WANT TO DELETE :: ");
    fflush(stdin);
    scanf("%d",&rollno);
    if((ip = fopen("index.file","rb++"))==NULL)
    {
     printf("\n\n\n\n\n\t  ERROR IN OPENING THE FILE IN WRITE MODE !!!");
     return;
    }
    while((flag==0) && (!feof(ip)))     /* START OF WHILE LOOP */
    {
     fread(&key,sizeof(int),1,ip);
     if(key == rollno)
       flag = 1;
     pos++;
    }
    pos--;
    if(pos == -1)
    {
     printf("\n\n\n\t=====================================================");
     printf("\n\n\n\t     FILE NOT FOUND !!! ");
     printf("\n\n\n\t=====================================================");
    }
    else if(pos != -1)
    {
     fclose(fp);
     fclose(ip);
     if((fp = fopen(filename,"rb++"))== NULL)
     {
       printf("\n\n\n\t  ERROR IN OPENING THE FILE  !!!");
       return;
     }
     fseek(fp,pos*(sizeof(temp)),0);
     fread(&temp,sizeof(temp),1,fp);
     temp.roll = -1;
     fseek(fp,pos*(sizeof(temp)),0);
     fwrite(&temp,sizeof(temp),1,fp);
     fclose(fp);
     printf("\n\n\n\n\n\t\tTHE RECORDS DELETED SUCCESSFULLY !!!!");
     if((fp = fopen(filename,"rb++"))== NULL)
     {
       printf("\n\n\n\t ERROR IN OPENING THE FILE  !!!");
       return;
     }
     sort(fp);
     index(fp,ip,filename);
     fclose(fp);
    }
  }
  else if(ch=='F' || ch=='f')
    remove(filename);
 }

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   APPEND()                                             */
/*       OBJECTIVE :  TO APPEND A RECORD IN THE FILE                       */
/*       PARAMETERS : FILE POINTER,INDEX FILE POINTER                      */
/*       RETURN TYPE : VOID      					   */
/*-------------------------------------------------------------------------*/

void append(FILE *fp,FILE *ip)
 {
   char filename[10];
   printf("\n\n\n\n\t  ENTER THE NAME OF THE FILE TO APPEND : ");
   flushall();
   scanf("%s",&filename);
   if((fp = fopen(filename,"ab")) == NULL)
   {
     printf("\n\n\n\t  ERROR IN OPENING THE FILE !!!");
     return;
   }
   printf("\n\n\n\t  APPENDING THE FILE !!!");
   getch();
   insert(fp);
   fclose(fp);
   if((fp = fopen(filename,"rb+")) == NULL)
   {
     printf("\n\n\n\t  ERROR IN OPENING THE FILE !!!");
     return;
   }
   sort(fp);
   index(fp,ip,filename);
 }

/*-------------------------------------------------------------------------*/
/*       FUNCTION :   MODIFY()                                             */
/*       OBJECTIVE :  TO MODIFY A PARTICULAR THE RECORD IN THE FILE        */
/*       PARAMETERS : FILE POINTER                                         */
/*       RETURN TYPE : VOID      					   */
/*-------------------------------------------------------------------------*/

 void modify(FILE *fp,FILE *ip,char filename[10])
 {
  stud temp;
  int tot,no,flag=0,key,pos=0,rollno;
  char ans;
  if((fp = fopen(filename,"rb++"))==NULL)
  {
    printf("\n\n\n\n\n\t  ERROR IN OPENING THE FILE IN WRITE MODE !!!");
    return;
  }
  printf("\n\n\n\n\t  ENTER THE ROLL NO OF STUDENT");
  printf("\n\n\n\t  WHOSE RECORD YOU WANT TO MODIFY :: ");
  fflush(stdin);
  scanf("%d",&rollno);
  if((ip = fopen("index.file","rb++"))==NULL)
  {
    printf("\n\n\n\n\t  ERROR IN OPENING THE FILE IN WRITE MODE !!!");
    return;
  }
  while((flag==0) && (!feof(ip)))     /* START OF WHILE LOOP */
  {
    fread(&key,sizeof(int),1,ip);
    if(key == rollno)
       flag = 1;
    pos++;
  }
  pos--;
  if(pos == -1)
  {
   printf("\n\n\n\t=====================================================");
   printf("\n\n\n\t     FILE NOT FOUND !!! ");
   printf("\n\n\n\t=====================================================");
  }
  else if(pos != -1)
  {
    fclose(fp);
    fclose(ip);
    do
    {
      if((fp = fopen(filename,"rb++"))==NULL)
      {
	printf("\n\n\n\n\t  ERROR IN OPENING THE FILE IN WRITE MODE !!!");
	return;
      }
      printf("\n\n\n\t  ENTER THE RECORD  !!!");
      fflush(stdin);
      printf("\n\n\n\t  ENTER THE NAME OF STUDENT > ");
      scanf("%s",temp.name);
      printf("\n\n\t  ENTER THE ROLL NO OF THE STUDENT > ");
      scanf("%d",&temp.roll);
      printf("\n\n\t  ENTER THE MARKS IN SUBJECT 1 > ");
      scanf("%d",&temp.score1);
      printf("\n\n\t  ENTER THE MARKS IN SUBJECT 2 > ");
      scanf("%d",&temp.score2);
      printf("\n\n\t  ENTER THE MARKS IN SUBJECT 3 > ");
      scanf("%d",&temp.score3);
      fseek(fp,pos*sizeof(temp),0);
      fwrite(&temp,sizeof(temp),1,fp);
      printf("\n\n\n\n\t\t  RECORDS SUCCESSFULLY ADDED !!!!");
      fclose(fp);
      printf("\n\n\n\n");
      printf("\t  WANT TO MODIFY ANOTHER RECORD (Y/N) :: ");
      fflush(stdin);
      ans=getche();
    }while(ans=='y' || ans=='Y');
  }
 }
/*-------------------------------------------------------------------------*/
/*       FUNCTION :   LINE()                                               */
/*       OBJECTIVE :  TO PRINT A LINE                                      */
/*       PARAMETERS : VOID                                                 */
/*-------------------------------------------------------------------------*/

  void line(void)
  {
    int i;                            /* DECLARATION OF LOCAL VARIABLES */
    printf("\n");
    for(i=0;i<20;i++)
    {
      printf("-");
    }
  }

/*--------------------------------------------------------------------------*/
/*          *+*+*+*+*+*+*+*+  END OF THE PROGRAM  *+*+*++*+*+*+*+*+         */
/*--------------------------------------------------------------------------*/
