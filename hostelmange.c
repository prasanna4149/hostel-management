#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<stdbool.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DOB_LENGTH 20
#define MAX_STUDENTS 100    
#define MAX_NAME_LENGTH 50
#define MAX_DOB_LENGTH 20
#define MAX_LINE 20000
#define MAX_ROOMS 50
#define MAX 100
#define MAX_DOB_LEN 10 // Maximum length of a valid date of birth string
void gotoxy(int ,int );void login();void exi(); void stu_dent();void admin();void parent();void admin_features();void add();void view_all();void edit();void fees();void room();void cleaning();void feedback();void attendence();void food();void v_rcomplaint();void deleterec(); void new();void display();void add_fees(); void update();void empty(); void food();void menu(); void student_features(); void view_d(); void v_attendence(); void food_d();void a_complaint(); void g_feedback(); void g_feedback();void v_roomclean(); void parent_features(); void view_dp();void vp_attendence(); void dp_complaint(); void gp_feedback(); void fees_d(); void view_de(); void new_P();char ch[10][130]={"monday","tuesday","wednesday","thursday","friday","saturday"}; void days();void add_attendence();void view_attendence();void new_p(); void deta(); void edit();
char name[32][100]={'\0'};
char number[32][2]={'\0'};
int num1[32]={0};
int trno;
void attendence();int rem();
void name_number(int add_attendence,char numstr[100]);
void add_attendence();
int read_number(int trno);
void read_name(int trno);
void view_attendence();
void status_1(int trno);void view_empty_rooms();
struct Room {
    int room_number;
    int is_occupied;
};
int is_valid_email(char *email) {
    char *at = strchr(email, '@');
    char *dot = strchr(email, '.');
    return (at != NULL && dot != NULL && at < dot);
}
bool is_valid_dob(char *dob) {
    if (strlen(dob) != MAX_DOB_LEN) {
        return false;
    }
    int day, month, year;
    if (sscanf(dob, "%2d/%2d/%4d", &day, &month, &year) != 3) {
        return false;
    }
    if (day < 1 || day > 31 || month < 1 || month > 12) {
        return false;
    }
    return true;
}

void main()
{   printf("<-------------------------------------->\n");
    printf("<--:Student Record Management System:-->\n");
    printf("<-------------------------------------->\n");
    login();
    return;
}
void login()
{
 int choice;
  printf("1. admin login \n");
   printf("2. student login \n");
    printf("3. parent login \n");
    printf("enter your choice:");
    scanf("%d",&choice);
    switch(choice)
    {
     case 1:admin();
     break;

     case 2:stu_dent();
     break;
     case 3:parent();
     break;
     default: printf("invalid choice");
}
return;
}
void admin()
{
 char user[20]="admin";
 char pass[20]="admin123";
 char user_name[20],password[20];
 printf("Enter admin username :");
 scanf("%s",user_name);
 printf("Enter admin password :");
 scanf("%s",password);
 if(strcmp(user_name, user) == 0 && strcmp(password, pass) == 0) 
 {printf("Login Successful! !!\n\n");
 admin_features();}
  else
  {
   printf("Login Unsuccessfull !! \nYou are redirected to admin login page again.\n\n");
   admin();
   
  }
  return ;
}
typedef struct
 {
    char name[MAX_NAME_LENGTH];
    char dob[MAX_DOB_LENGTH];
    char id[10];
} student;
int readstudents(student students[]) {
    FILE *fp;
    int count = 0;

    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

   while (fscanf(fp, "%s %s %s", &students[count].id, students[count].name, students[count].dob) != EOF) {
        count++;
    }

    fclose(fp);

    return count;
}
void stu_dent()
{
 student students[MAX_STUDENTS];
 int count, i;
 char name[MAX_NAME_LENGTH], dob[MAX_DOB_LENGTH],id[10];
 // read student data from file
 count = readstudents(students);
 // get student ID, name, and dob from user
    printf("Enter student id: ");
    scanf("%s", id);
    printf("Enter student name : ");
    scanf("%s", name);
    printf("Enter student dob : ");
    scanf("%s", dob);

    // find student in list
     for (i = 0; i < count; i++)
     {
      if (strcmp(students[i].id ,id) == 0 && strcmp(students[i].name, name) == 0 && strcmp(students[i].dob, dob) == 0) 
      {
       // login successful, print welcome message and exit
       printf("Login successful! Welcome, %s.\n", students[i].name);
       student_features();
       return;
      }
    }


    // login failed, print error message and exit
    printf("Invalid ID, name, or dob.\n");
    stu_dent();
    return ;
}
typedef struct
 {
    char name[MAX_NAME_LENGTH];
    char dob[MAX_DOB_LENGTH];
} Parent;
int readParents(Parent parents[]) {
    FILE *fp;
    int count = 0;

    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fscanf(fp, "%s %s",parents[count].name, parents[count].dob) != EOF) {
        count++;
    }

    fclose(fp);

    return count;
}
void parent()
{
    Parent parents[MAX_STUDENTS];
    int count, i, id;
    char name[MAX_NAME_LENGTH], dob[MAX_DOB_LENGTH];

    // read student data from file
    count = readParents(parents);

    // get student ID, name, and dob from user
    printf("Enter student id: ");
    scanf("%s", name);
    printf("Enter student name : ");
    scanf("%s", dob);

    // find student in list
    for (i = 0; i < count; i++) {
        if (strcmp(parents[i].name, name) == 0 && strcmp(parents[i].dob, dob) == 0) {
            // login successful, print welcome message and exit
            printf("Login successful! Welcome\n");
            parent_features();
            return;
        }
    }

    // login failed, print error message and exit
    printf("Invalid ID, name, or dob.\n");
    parent();
    return ;
}
void admin_features()
{
    int choice;
    printf("\n\n<--:admin MENU:-->\n\n");
    printf("Enter appropriate number to perform following task.\n\n");
    printf("||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("|||| 1 : Add new student.     ||||||||||||||\n");
    printf("|||| 2 : View all student details.    ||||||\n");
    printf("|||| 3 : edit student information.   |||||||\n");
    printf("|||| 4 : remove student.    ||||||||||||||||\n");
    printf("|||| 5 : fees details.    ||||||||||||||||||\n");
    printf("|||| 6 : room details.    ||||||||||||||||||\n");
    printf("|||| 7 : view feedback.    |||||||||||||||||\n");
    printf("|||| 8 : add attendence.    ||||||||||||||||\n");
    printf("|||| 9 : food services.    |||||||||||||||||\n");
    printf("|||| 10 : view and reply complaint.    |||||\n");
    printf("|||| 11 : go to main menu.    ||||||||||||||\n");
    printf("|||| 12 : exit.    |||||||||||||||||||||||||\n");
    printf("||||||||||||||||||||||||||||||||||||||||||||\n");

    printf("\nEnter your choice.\n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        add();
        break;

    case 2:
        view_all();
        break;

    case 3:
        edit();
        break;

    case 4:
        rem();
        break;

    case 5:
        fees();
        break;

    case 6:
        room();
        break;
    
    
    
    case 7:
        feedback();
        break;

    case 8:
        add_attendence();
        break;

    case 9:
        menu();
        break;

    case 10:
        v_rcomplaint();
        break;

    case 11:
        exi();
        break;

    case 12:
        cleaning();
        break;

    default:
        printf("Invalid Choice.");
    }
}
void add()
{
 // Get student details
 char roll [5];char name[100];char dob[16];char age[3];char phno[12];char mail[20];char room[20];
 FILE *fptr;int i;
 fptr = fopen("students.txt","a");
 if(fptr == NULL)
 {
  printf("Error 404 !! FILE NOT FOUND !!\n");   
  exit(1);             
 }
  printf("Enter student roll : \t");
  scanf("%s",roll);
  fprintf(fptr,"%s\t",roll);
  printf("Enter student NAME : \t");
  scanf("%s",name);
  fprintf(fptr,"%s\t",name);
  printf("Enter student DOB : \t");
  scanf("%s",dob);
  if (!is_valid_dob(dob)) {
       printf("Invalid date of birth format.\n");
        add();
        return ;
    }
    fprintf(fptr,"%s\t",dob);
    printf("Enter student AGE : \t");
    scanf("%s",age);
    fprintf(fptr,"%s\t",age);
    printf("Enter Your PHONE NO. : \n");
    scanf("%s",phno);
   for (i = strlen(phno); i != 10;)
   {
    printf("Enter PHONE NO. again : \n");
    scanf("%s", phno);}
    if(strlen(phno)==10){
    fprintf(fptr,"%s\t/t",phno);

  }

    printf("Enter student E-MAIL : \t");
    scanf("%s",mail);
    if (!is_valid_email(mail)) {
        printf("Invalid email format.\n");
        add();
        return ;
        
    }

    fprintf(fptr,"%s\t",mail);
    
    printf("add student room no : ");
    scanf("%s",room);
    fprintf(fptr,"%s\n",room);
    printf("\n\n\n\n ");
    
    fclose(fptr);
    admin_features();
    return;
}
void view_all()
{
    FILE* ptr;
	char ch;
	ptr = fopen("students.txt", "r");

	if (NULL == ptr) {
		printf("file can't be opened \n");
	}
     printf("------------------------------------------------------------------------------\n");
      printf("roll no\tNAME\tPASSWORD\tDOB\t\tPHONE NO.\t MAIL\t\tAGE\n");
      printf("------------------------------------------------------------------------------\n");
	do {
		ch = fgetc(ptr);
		printf("%c", ch);
	} while (ch != EOF);
	fclose(ptr);
    admin_features();
	return ;
}
 
void edit()
{int lno, ctr = 0;
   char ch;
   
   FILE *fptr1, *fptr2;
   char str[MAX], temp[] = "temp.txt"; 
   fptr1 = fopen("students.txt", "r");
   if (!fptr1) 
   {
    printf(" File not found or unable to open the input file!!\n");
    return ;
   }
    fptr2 = fopen(temp, "w");
    if (!fptr2) 
	{
     printf("Unable to open a temporary file to write!!\n");
     fclose(fptr1);
     return ;
    }
     printf("input roll no of student you want to edit : ");
     scanf("%d", &lno);
     while (!feof(fptr1)) 
     {
      strcpy(str,"\0");
      fgets(str, MAX, fptr1);
      if (!feof(fptr1)) 
      {
       ctr++;
       if (ctr != lno) 
       {
        fprintf(fptr2, "%s", str);
       }
      }
    }
     fclose(fptr1);
     fclose(fptr2);
     remove("students.txt");  		
     rename(temp, "students.txt"); 	
     fptr1=fopen("students.txt","r"); 
     ch=fgetc(fptr1); 
     fclose(fptr1);
     add();
     return ;
}
int rem()
{
   int lno, ctr = 0;
   char ch;
   
   FILE *fptr1, *fptr2;
   char str[MAX], temp[] = "temp.txt";
   printf("\nremove student  :\n");
   printf("-----------------------------------------\n"); 
   fptr1 = fopen("students.txt", "r");
   if (!fptr1) 
   {
    printf(" File not found or unable to open the input file!!\n");
    return 0;
   }
    fptr2 = fopen(temp, "w");
    if (!fptr2) 
	{
     printf("Unable to open a temporary file to write!!\n");
     fclose(fptr1);
     return 0;
    }
     printf("input roll no of student you want to remove : ");
     scanf("%d", &lno);
     while (!feof(fptr1)) 
     {
      strcpy(str,"\0");
      fgets(str, MAX, fptr1);
      if (!feof(fptr1)) 
      {
       ctr++;
       if (ctr != lno) 
       {
        fprintf(fptr2, "%s", str);
       }
      }
    }
     fclose(fptr1);
     fclose(fptr2);
     remove("students.txt");  		
     rename(temp, "students.txt"); 	
     fptr1=fopen("students.txt","r"); 
     ch=fgetc(fptr1); 
     printf("student removed succesfully"); 
     fclose(fptr1);
     admin_features();
     return 0;
}
void fees()
{
    int choice;
    printf("choose option\n");
    printf("1. display new payments with student name.\n");
    printf("2. add update.\n");
    printf("3. fee details.\n");
    printf("Enter your choice.\n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        new();
        break;
    case 2:
        add_fees();
        break;

    case 3:
         deta();
    default:
        printf("Invalid Choice.");
    }
}
void new()
{ 
	FILE* ptr;
	char ch;
	ptr = fopen("fees.txt", "r");

	if (NULL == ptr) {
		printf("file can't be opened \n");
	}
     
    printf("==============================================================================\n");
	printf("  roll no     student name          transition id \n");
    printf("==============================================================================\n");

	do {
		ch = fgetc(ptr);
		printf("%c", ch);
	} while (ch != EOF);
	fclose(ptr);
admin_features();
	return ;
}
void add_fees()
{
    char roll [20];char id[20];char rollno[3];char remaning[20];
   FILE *fptr;
   fptr = fopen("feesd.txt","a");

   if(fptr == NULL)
   {
      printf("Error 404 !! FILE NOT FOUND !!\n");   
      exit(1);             
   }
    printf("enter student roll no:");
    scanf("%s",roll);
    fprintf(fptr,"%s\t",roll);
    printf("Enter student name: \t");
    scanf("%s",rollno);
    fprintf(fptr,"%s\t",rollno);
    printf("Enter total paid amount : \t");
    scanf("%s",id);
    fprintf(fptr,"%s\t",id);
    printf("Enter remaining amount: \t");
    scanf("%s",remaning);
    fprintf(fptr,"%s\n ",remaning);

      fclose(fptr);
   admin_features();
   return;
}
void deta()
{
    FILE* ptr;
	char ch;
	ptr = fopen("feesd.txt", "r");

	if (NULL == ptr) {
		printf("file can't be opened \n");
	}
    printf("==============================================================================\n");
	printf("  roll no     student name          paid    remaning \n");
    printf("==============================================================================\n");

	do {
		ch = fgetc(ptr);
		printf("%c", ch);
	} while (ch != EOF);
	fclose(ptr);
admin_features();
	return ;

}
void room()
{
    int choice;
    printf("choose option\n");
    printf("***************************************\n");
    printf("*** 1. display room prices.    ********\n");
    printf("*** 2. update price.      *************\n");
    printf("*** 3. display empty room.    *********\n");
    printf("***************************************\n");
    printf("Enter your choice.\n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        display();
        break;
    case 2:
        update();
        break;
    case 3:
        empty();
        break;
    default:
        printf("Invalid Choice.");
    }

}
void display()
{
    FILE*fptr;
	char ch;
	fptr = fopen("roomprice.txt", "r");

	if (NULL ==fptr) {
		printf("file can't be opened \n");
	}
    printf("=====================================================================\n");
	printf("4 sitting\t""3 sittting\t""2 sitting\t""single sitting\t""\n");
    printf("=====================================================================\n");

	do {
		ch = fgetc(fptr);
		printf("%c", ch);
	} while (ch != EOF);
	fclose(fptr);
    admin_features();
	return ;
}
void update()
{char four [10];char three[20];char two[10];char single[20];
    FILE*fptr;
   fptr = fopen("roomprice.txt","w");

   if(fptr == NULL)
   {
      printf("Error 404 !! FILE NOT FOUND !!\n");   
      exit(1);             
   }
    printf("Enter 4 sitting price : \t");
    scanf("%s",four);
    fprintf(fptr,"%s\t\t",four);
    printf("Enter 3 sitting : \t");
    scanf("%s",three);
    fprintf(fptr,"%s\t\t",three);
    printf("Enter 2 sitting : \t");
    scanf("%s",two);
    fprintf(fptr,"%s\t\t",two);
    printf("Enter single sitting price : \t");
    scanf("%s",single);
    fprintf(fptr,"%s\t\t",single);
    fclose(fptr);
    admin_features();
   return;
}
void empty()
{

// initialize the list of rooms
    struct Room rooms[MAX_ROOMS] = {
        {1, 0},
        {2, 1},
        {3, 0},
        // add other rooms here
    };
    int num_rooms = 3;

    // view empty rooms
    view_empty_rooms(rooms, num_rooms);


    

    return;

}
void view_empty_rooms(struct Room rooms[], int num_rooms) 
{
    printf("Empty rooms:\n");
    for (int i = 0; i < num_rooms; i++) {
        if (!rooms[i].is_occupied) {
            printf("Room number: %d\n", rooms[i].room_number);
            // print other details about the room here
        }
    }
}
void feedback()
{
    FILE* ptr;
	char ch;
	ptr = fopen("feedback.txt", "r");

	if (NULL == ptr) {
		printf("file can't be opened \n");
	}
    printf("=====================================================================\n");
	printf("student name\t\t\t\t""feedback\t\t\t\t"    "\n");
    printf("=====================================================================\n");

	do {
		ch = fgetc(ptr);
		printf("%c", ch);
	} while (ch != EOF);
	fclose(ptr);
    admin_features();
	return ;
}
void add_attendence()

{
   

    int i=0;
    char numstr[100];
system("cls");
printf("||||||||||||||||||||||||||||||||| HOSTEL MANAGMENT SYSTEM ||||||||||||||||||||||||||\n\n\n");
days();
printf("Enter the day number : ");
scanf("%d",&trno);
system("cls");
printf("||||||||||||||||||||||||||||||||||||       Add attedence |||||||||||||||||||||||||||||||||||||\\n\n\n");
printf("your day is %d ********** %s",trno,ch[trno-1]);
status_1(trno);
 FILE *f1, *fopen();//for reading the seats from the user.
 char str1[80]="32",str2[4],str3[4];
 int seat1,seat2,add_attendence
=0;
if(trno == 1)
{
 f1 = fopen("tr1.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
}else if(trno == 2)
{
 f1 = fopen("tr2.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
}else if(trno == 3)
{
 f1 = fopen("tr3.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
}
else if(trno == 4)
{
 f1 = fopen("tr4.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
}
else if(trno == 5)
{
 f1 = fopen("tr5.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
}
seat1=atoi(str1);//covert the string into number
if(seat1 <= 0)
{
 printf("There is no blank seat in this attendence ");
}else
{
printf("\n\n\n\t\t\t\tAbsent students : %d\n",seat1);
printf("\n\t\t\t\tNumber of students : ");
scanf("%d",&add_attendence);
printf("\n");

seat1=seat1-add_attendence;
itoa(trno,numstr,10);
name_number(add_attendence,numstr);
itoa(seat1, str1, 10);
if(trno == 1)
{
 f1 = fopen("tr1.txt","w");
 fputs(str1,f1);
 fclose(f1);
}
else if(trno == 2)
{
 f1 = fopen("tr2.txt","w");
 fputs(str1,f1);
  fclose(f1);
}
else if(trno == 3)
{
 f1 = fopen("tr3.txt","w");
 fputs(str1,f1);
  fclose(f1);
}
else if(trno == 4)
{
 f1 = fopen("tr4.txt","w");
 fputs(str1,f1);
  fclose(f1);
}
else if(trno == 5)
{
 f1 = fopen("tr5.txt","w");
 fputs(str1,f1);
 fclose(f1);
 admin_features();
}
}
}
void name_number(int add_attendence,char numstr[100])
{
char tempstr[100],tempstr1[12]="status",tempstr2[12]="number";
int number;
    FILE *a,*b;
    int i=0;
   strcat(numstr,".txt");
   strcat(tempstr1,numstr);
   strcat(tempstr2,numstr);
   a = fopen(tempstr1,"a");//for open the file to write the name in the file
   b = fopen(tempstr2,"a");//for open the file for writing the number in the file
for(i=0; i<add_attendence; i++)//for entering the person name and seat number in the file
{
    printf("============================Enter attendence  %d============================\n\n\n",i+1);
      printf("\t\t\t\tEnter roll no : ");
      scanf("%d",&number);
      printf("\t\t\t\tEnter P if present : ");
      scanf("%s",name[number-1]);
    printf("\n======================================================================================================\n\n");
    printf("\n");
      itoa(number, tempstr, 10);
      fprintf(a,"%s ",name[number-1]);
      fprintf(b,"%s ",tempstr);

}
fclose(a);
fclose(b);
}
int read_number(int trno)//for putting the numeric value in the array
{
char tempstr[100],tempstr2[12]="number";
FILE *a,*b;
char numstr[100];
int i=0,j=0,k;
itoa(trno,numstr,10);
strcat(numstr,".txt");
strcat(tempstr2,numstr);
a = fopen(tempstr2,"a+");//for open the file to write the name in the file
   while(!feof(a))
   {
      number[i][j] = fgetc(a);

      if(number[i][j] == ' ')
      {
          j=0;
          i++;
      }
      else
      {
      j++;
      }
   }
   k=i;
   for(i=0; i<k; i++)
   {
       num1[i] = atoi(number[i]);
   }
   fclose(a);
   return k;
}

void read_name(int trno)//for putting the numeric value in the array
{
char tempstr1[12]="status";
FILE *b;
char numstr[100];
int i=0,j=0,k=0;
itoa(trno,numstr,10);
strcat(numstr,".txt");
strcat(tempstr1,numstr);
b = fopen(tempstr1,"a+");//for open the file to write the name in the file
   while(!feof(b))
   {
      name[i][j] = fgetc(b);

      if(name[i][j] == ' ')
      {
          j=0;
          i++;
      }
      else
      {
        j++;
      }

   }
   name[i][j]='\0';
   k=i;
   fclose(b);
}
void menu()
{
 int a;
 char roll [50];char name[50];char dob[50];char age[50];char phno[50];char mail[50];char room[50];
   FILE *fptr;
   fptr = fopen("food.txt","a");
   printf("monday\n");
   printf("tuesday\n");
   printf("wednesday\n");
   printf("thursday\n");
   printf("friday\n");
   printf("saturday\n");
   printf("sunday\n");
 printf("Enter choice: ");
 scanf("%d",&a);

 switch(a)
 {
 case 1 : printf("Enter monday menu :\n");
          food();
 case 2 : printf("Enter tuesday menu : ");
        food();
 case 3 : printf("Enter wednesday menu : ");
        food();
case 4 : printf("Enter thursday menu : ");
        food();
case 5 : printf("Enter thursday menu : ");
        food();
case 6 : printf("Enter friday menu : ");
        food();
case 7 : printf("Enter saturday menu : ");
        food();
case 8 : printf("Enter sunday menu : ");
        food();

 }
 return;
}
void food() 
{
    // Get student details
   char bre_ak [50];char lunch[50];char dinner[50];
   FILE *fptr;
   fptr = fopen("food.txt","a");

   if(fptr == NULL)
   {
      printf("Error 404 !! FILE NOT FOUND !!\n");   
      exit(1);             
   }
    printf("Enter breakfast : \t");
    scanf("%s",bre_ak);
    fprintf(fptr,"%s\t",bre_ak);
    printf("Enter lunch : \t");
    scanf("%s",lunch);
    fprintf(fptr,"%s\t",lunch);
    printf("Enter dinner : \t");
    scanf("%s",dinner);
    fprintf(fptr,"%s\n",dinner);
    fclose(fptr);

   return;
}
void student_features()
{
  int choice;
  printf("\n\n<--: student MENU:-->\n"); 

  printf("\nEnter appropriate number to perform following task.\n");
  printf("|||||||||||||||||||||||||||||||||||||||||\n");
  printf("||||1. view details   |||||||||||||||||||\n");
  printf("||||2. view attendence   ||||||||||||||||\n");
  printf("||||3. food detail    |||||||||||||||||||\n");
  printf("||||4. add complaints    ||||||||||||||||\n");
  printf("||||5. give feedback    |||||||||||||||||\n");
  printf("||||6 : go to main menu.    |||||||||||||\n");
  printf("||||7 : exit.    ||||||||||||||||||||||||\n");
  printf("|||||||||||||||||||||||||||||||||||||||||\n"); 
  printf("Enter your choice.\n");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1:
    view_d();
    break;

    case 2:
    view_attendence();
    break;

    case 3:
    food_d();
    break;

    case 4:
    a_complaint();
    break;

    case 5:
    g_feedback();
    break;

    case 6:
     exi();
        break;

    case 7:
        cleaning();
        break;

    default:
        printf("Invalid Choice.");
  }
}
void view_d()
{

  FILE *file;
  char buffer[MAX_LINE];
  int read_line = 0,a;
  printf("Enter student roll no. : ");
  scanf("%d", &read_line);
  file = fopen("students.txt", "r");
  if (file == NULL)
  {
    printf("Error opening file.\n");
    return;
  }
  bool keep_reading = true;
  int current_line = 1;
  do 
  {
    fgets(buffer, MAX_LINE, file);
    if (feof(file))
    {
      keep_reading = false;
      printf("Couldn't find student details with s.no %d.\n", read_line);
    }
    else if (current_line == read_line)
    {
      keep_reading = false;
      printf("student Details : \n");
      printf("------------------------------------------------------------------------------\n");
      printf("roll no \tNAME\tDOB\tage\tPHONE NO.\t MAIL\t\t room no\n");
      printf("------------------------------------------------------------------------------\n");
      printf("%s", buffer);
    }
    current_line++;

  } while (keep_reading);
  fclose(file);
  student_features();
  return;
}
 void food_d()
 {
    FILE* ptr;
	char ch;
	ptr = fopen("food.txt", "r");

	if (NULL == ptr) {
		printf("file can't be opened \n");
	}
    printf("======================================\n");
	printf("breakfast  lunch  dinner \n");
    printf("======================================\n");

	do {
		ch = fgetc(ptr);
		printf("%c", ch);
	} while (ch != EOF);
	fclose(ptr); 
    student_features();
}
void a_complaint()
{
    char roll [5];char complaint[200];
   FILE *fptr;
   fptr = fopen("complaints.txt","a");

   if(fptr == NULL)
   {
      printf("Error 404 !! FILE NOT FOUND !!\n");   
      exit(1);             
   }
    printf("Enter student roll : \t");
    scanf("%s",roll);
    fprintf(fptr,"%s\t",roll);
    printf("use _ instead of space\n");
    printf("Enter complaint: \t");
    scanf("%s",complaint);
    fprintf(fptr,"%s\n",complaint);
    
    
    fclose(fptr);
    student_features();
   return;
}
void g_feedback()
{
    char roll [5];char feedback[200];
   FILE *fptr;
   fptr = fopen("feedback.txt","a");
   if(fptr == NULL)
   {
      printf("Error 404 !! FILE NOT FOUND !!\n");   
      exit(1);             
   }
    printf("Enter student roll : \t");
    scanf("%s",roll);
    fprintf(fptr,"%s\t",roll);
    printf("use _ instead of space\n");
    printf("Enter feedback : \t");
    scanf("%s",feedback);
    fprintf(fptr,"%s\n",feedback);
    
    
    fclose(fptr);
    student_features();
   return;
}
void parent_features()
{
    int choice;
  printf("\n\n<--:parent MENU:-->");  
  printf("Enter appropriate number to perform following task.\n");
  printf("|||||||||||||||||||||||||||||||||||\n");
  printf("|||| 1. view details   ||||||||||||\n");
  printf("|||| 2. view attendence   |||||||||\n");
  printf("|||| 3. add complaint    ||||||||||\n");
  printf("|||| 4. give feedback    ||||||||||\n");
  printf("|||| 5. fees details    |||||||||||\n");
  printf("||||6 : go to main menu.    |||||||\n");
  printf("||||7 : exit.    ||||||||||||||||||\n");
  printf("|||||||||||||||||||||||||||||||||||\n");
  printf("Enter your choice.\n");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1:
    view_dp();
    break;

    case 2:
    view_attendence();
    break;

    case 3:
     a_complaint();
    break;

    case 4:
    g_feedback();
    break;

    case 5:
    fees_d();
    break;

    case 6:
     exi();
        break;

    case 7:
        cleaning();
        break;

    default:
        printf("Invalid Choice.");
  }

}
void view_dp()
{ FILE *file;
  char buffer[MAX_LINE];
  int read_line = 0,a;
  printf("Enter student roll no. : ");
  scanf("%d", &read_line);
  file = fopen("students.txt", "r");
  if (file == NULL)
  {
    printf("Error opening file.\n");
    return;
  }
  bool keep_reading = true;
  int current_line = 1;
  do 
  {
    fgets(buffer, MAX_LINE, file);
    if (feof(file))
    {
      keep_reading = false;
      printf("Couldn't find Customer details with s.no %d.\n", read_line);
    }
    else if (current_line == read_line)
    {
      keep_reading = false;
      printf("Customer Details : \n");
      printf("------------------------------------------------------------------------------\n");
      printf("roll no\tNAME\tPASSWORD\tDOB\t\tPHONE NO.\t MAIL\t\tAGE\n");
      printf("------------------------------------------------------------------------------\n");
      printf("%s", buffer);
    }
    current_line++;

  } while (keep_reading);
  fclose(file);
  parent_features();
  return;}
void dp_complaint()
  {
     char roll [5];char complaint[200];
   FILE *fptr;
   fptr = fopen("complaints.txt","a");

   if(fptr == NULL)
   {
      printf("Error 404 !! FILE NOT FOUND !!\n");   
      exit(1);             
   }
    printf("Enter student roll : \t");
    scanf("%s",roll);
    fprintf(fptr,"%s\t",roll);
    printf("use _ instead of space\n");
    printf("Enter complaint: \t");
    scanf("%s",complaint);
    fprintf(fptr,"%s\n",complaint);
    
    
    fclose(fptr);
    parent_features();
   return;
  }
void gp_feedback()
   {
    char roll [5];char feedback[200];
   FILE *fptr;
   fptr = fopen("feedback.txt","a");
   if(fptr == NULL)
   {
      printf("Error 404 !! FILE NOT FOUND !!\n");   
      exit(1);             
   }
    printf("Enter student roll : \t");
    scanf("%s",roll);
    fprintf(fptr,"%s\t",roll);
    printf("use _ instead of space\n");
    printf("Enter feedback : \t");
    scanf("%s",feedback);
    fprintf(fptr,"%s\t",feedback);
    
    
    fclose(fptr);
    parent_features();
   return;
   }
void fees_d()
{int choice; 
  printf("Enter appropriate number to perform following task.\n");
  printf("*************************\n");
  printf("*** 1. view previous  ***\n");
  printf("*** 2. new payement   ***\n"); 
  printf("*************************\n");
  printf("Enter your choice.\n");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1:
    view_de();
    break;

    case 2:
    new_p();
    break;
    default:
        printf("Invalid Choice.");
  } }
void view_de()

{
   FILE *file;
  char buffer[MAX_LINE];
  int read_line = 0,a;
  printf("Enter student roll no. : ");
  scanf("%d", &read_line);
  file = fopen("feesd.txt", "r");
  if (file == NULL)
  {
    printf("Error opening file.\n");
    return;
  }
  bool keep_reading = true;
  int current_line = 1;
  do 
  {
    fgets(buffer, MAX_LINE, file);
    if (feof(file))
    {
      keep_reading = false;
      printf("Couldn't find student details with s.no %d.\n", read_line);
    }
    else if (current_line == read_line)
    {
      keep_reading = false;
      printf("student Details : \n");
      printf("------------------------------------------------------------------------------\n");
      printf("roll no  name  payement done  remaining payement \n");
      printf("------------------------------------------------------------------------------\n");
      printf("%s", buffer);
    }
    current_line++;

  } while (keep_reading);
  fclose(file);
  printf("\n\nWant to find another student details ?  Press 1\n");
  printf("otherwise to return to  login Press 2 \n");
  scanf("%d",&a);
  if(a==1)
  {fees_d();}
  else
  {parent_features();}
  return;
}
void new_p()
{
    char roll [5];char name[20];char dob[10];
   FILE *fptr;
   fptr = fopen("fees.txt","a");

   if(fptr == NULL)
   {
      printf("Error 404 !! FILE NOT FOUND !!\n");   
      exit(1);             
   }
    printf("Enter student roll : \t");
    scanf("%s",roll);
    fprintf(fptr,"%s\t",roll);
    printf("Enter student NAME : \t");
    scanf("%s",name);
    fprintf(fptr,"%s\t",name);
    printf("Enter transition id : \t");
    scanf("%s",dob);
    fprintf(fptr,"%s\t",dob);
    
    fclose(fptr);
    parent_features();
   return;
}
void days()
{
    system("cls");
    printf("\n\n\n");
    printf("=========================================== hostel management system============================================\n\n\n");
    printf("\t\t\t\t\t[1]  =>  %s\n",ch[0]);
    printf("\n");
    printf("\t\t\t\t\t[2]  =>  %s\n",ch[1]);
    printf("\n"); 
	printf("\t\t\t\t\t[3]  =>  %s\n",ch[2]);
    printf("\n"); 
	printf("\t\t\t\t\t[4]  =>  %s\n",ch[3]);
    printf("\n"); 
	printf("\t\t\t\t\t[5]  =>  %s\n",ch[4]);
}
void view_attendence()
{
 int x;
system("cls");
printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("|||                             attendence                             |||\n");
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n\n");  
      int i,trno,index=0,j;
     
    printf("Enter the day : ");
    scanf("%d",&trno);
    j=read_number(trno);
    read_name(trno);
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("||                                      day : %s                                               ||\n",ch[trno-1]);
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n\n");
    char tempname[33][10]={"E","E","E","E","E","E","E","E","E","E","E","E","E","E","E","E","E","E","E","E","E","E","E","E","E","E","E","E","E","E","E","E","E"};
    for(i=0; i<j; i++)
    {
        strcpy(tempname[num1[i]],name[i]);
    }
    for(i=0; i<8; i++)
    {
        printf("\t\t\t\t");
        for(j=0; j<4; j++)
            {
        printf("%d.%s\t",index+1,tempname[index+1]);
        index++;
            }
            printf("\n");
    }
    printf("Enter 1 to return to user interface.");
    scanf("%d",&x);
    if(x==1)
    {login();}
    }
void status_1(int trno)
{
    printf("Your Bus Number is %d ********** %s",trno,ch[trno-1]);
    system("cls");
    printf("=========================================== hostel management SYSTEM ============================================\n\n\n");
    int i,index=0,j;
    j=read_number(trno);
    read_name(trno);
    char tempname[33][10]={"Ab","Ab","Ab","Ab","Ab","Ab","Ab","Ab","Ab","Ab","Ab","Ab","Ab","Ab","Ab","Ab","Ab","Ab","Ab","Ab","Ab","Ab","Ab","Ab","Ab","Ab","Ab","Ab","Ab","Ab","Ab","Ab","Ab"};
    for(i=0; i<j; i++)
    {
        strcpy(tempname[num1[i]],name[i]);
    }
    for(i=0; i<8; i++)
    {
        printf("\t\t\t\t");
        for(j=0; j<4; j++)
            {
        printf("%d.%s\t",index+1,tempname[index+1]);
        index++;
            }
            printf("\n");
}
}
void exi()
{ login();
}
void v_rcomplaint()
{
     FILE* ptr;
	char ch;
	ptr = fopen("complaints.txt", "r");

	if (NULL == ptr) {
		printf("file can't be opened \n");
	}

	printf("roll no                              complaints                 \n");
    printf("==============================================================================\n");

	do {
		ch = fgetc(ptr);
		printf("%c", ch);
	} while (ch != EOF);
	fclose(ptr);
    admin_features();
}
void cleaning()
{
    printf("*************************\n");
    printf("****** thank you ********\n");
    printf("*************************\n");
}