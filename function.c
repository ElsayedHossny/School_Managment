#include <stdio.h>
#include <stdlib.h>
#include"function.h"
#include"Console_color.h"


extern std_t school[100];
extern int NoOfStudent;
extern int choose;

/*****function of Color******/
void consoleColor(int foreGroundColor){
    //argument if change backGroundColor (,int backGroundColor)
    //int color = foreGroundColor+ 16*backGroundColor;
    //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),foreGroundColor);
}

/*****function of Check School_empty ******/
int School_empty(void){
    u8 empty;
    if(NoOfStudent<=0)
    {
        do
        {
            system("cls");
            consoleColor(4);
            printf("\n\n----School Is Empty----\n\n");
            consoleColor(5);
            printf("=======================\n");
            printf("Do you need Back [y/n] : ");
            scanf("%s",&empty);
        }
        while(empty == 'n'||empty == 'N');
    }
    else
    {
        return 1;
    }
    return 0;
}

/*****function print string******/
void string_print(char *str){
    for (int i=0; str[i] ; i++)
    {
        printf("%c", str[i]);
    }
}

/*****function scan string******/
void string_scan(char *str){
int i=0;
fflush(stdin);
scanf("%c",&str[i]);
while(str[i]!='\n'){
i++;
scanf("%c",&str[i]);
}

str[i]=0;

}

/*****function the start page ******/
void start(void){
consoleColor(4);
printf("\n-----SCHOOL-MANAGMENT-SYSTEM-----\n\n");
    consoleColor(6);
printf("[1] Add Student \n");
printf("[2] Edit Data Student \n");
printf("[3] Remove Student \n");
printf("[4] Search Student \n");
printf("[5] print School \n");
printf("[6] Sort School \n");
printf("[7] Exit \n\n");

}

/*****function  Add_student******/
void add_student(std_t *ps){
u8 another;
do{

        system("cls");
        consoleColor(4);
        printf("\n----ADD-STUDENT-MENU----\n\n");
        consoleColor(6);
        printf("Enter your name : ");
        string_scan(&ps[NoOfStudent].name);
        fflush(stdin);
        printf("Enter ID :");
        scanf("%d",&ps[NoOfStudent].id);
        fflush(stdin);
        printf("Enter Age :");
        scanf("%d",&ps[NoOfStudent].age);
        fflush(stdin);
        printf("Enter phone :");
        string_scan(&ps[NoOfStudent].phone);
        consoleColor(1);
        printf("\n=======================\n");
        printf("Student Store Successfuly .\n\n");
        NoOfStudent++;
        consoleColor(5);
        printf("=======================\n");
        printf("Do you want to add another [y/n] : ");
        scanf("%s", &another);
        consoleColor(2);

    }
while(another == 'y'||another == 'Y');

}

/*****function print student******/
void student_print(std_t s){


    printf("Name : ");
    string_print(s.name);
    printf("\nId : %d",s.id);
    printf("\nAge : %d",s.age);
    printf("\nPhone : ");
    string_print(s.phone);
    printf("\n=======================\n\n");
}

/*****function print school******/
void printf_school(std_t *psc){

u8 another;


do{
system("cls");
if(NoOfStudent==0){
    consoleColor(4);
    printf("\n----SCHOOL IS EMPTY----\n\n");

}else{
        consoleColor(4);
printf("\n----PRINT-STUDENT-IN-SCHOOL----\n\n");

for(int i=0;i<NoOfStudent;i++){
consoleColor(6);
student_print(psc[i]);
}
}

consoleColor(5);
printf("=======================\n");
printf("Do you need Back [y/n] : ");
scanf("%s",&another);

}while(another == 'n'||another == 'N');

}

/*****function Search_student******/
void Search_student(){
        u8 another;
    int empty;
   empty=School_empty();
   if(empty==1){
do{
system("cls");
int x,y;
char str[100];
 consoleColor(4);
printf("\n----Choose How To Search ----\n\n");
    consoleColor(6);
printf("1-ID  2-Name [1/2] : ");
    consoleColor(1);
scanf("%d",&x);
if(x==1){
    printf("=======================\n");
    printf("Enter ID  :");
    scanf("%d",&y);
    consoleColor(6);
    printf("=======================\n");
    Search_studentById(y,school);

}else{
    printf("=======================\n");
    printf("Enter Name  :");
    string_scan(str);
    consoleColor(6);
    printf("=======================\n");
    Search_studentByName(str ,school);
}
 consoleColor(5);
printf("=======================\n");
 printf("Do you want to Search another [y/n] : ");
 scanf("%s", &another);

}
while(another == 'y'||another == 'Y');
   }
}

int Search_studentByName(char*str ,std_t *psc){
    char x=0 ,flag=0;
    for(int i=0; i< NoOfStudent ; i++)
    {
        x = string_compareNotcaseSenstive(psc[i].name , str);
        if(x==1)
        {
           student_print(psc[i]);
           flag=1;
           return i;
           break;
        }else{
        flag=0;
        }
    }
if(flag==0){
    printf("This Name Don't Exist.\n");
    printf("=======================\n");
    return -1;
}
}

char string_compareNotcaseSenstive(char *str1,char *str2){
    int x=0;
    for(int i=0; str1[i]||str2[i]; i++)
    {

        if(str1[i]!=str2[i])
        {
            if(str1[i]>='A' && str1[i]<='Z')
            {
                x=str1[i]-'A'+'a';
                if(x!=str2[i])
                {
                    return 0;
                }
            }
            else if(str2[i]>='A' && str2[i]<='Z')
            {
                x=str2[i]-'A'+'a';
                if(x!=str1[i])
                {
                    return 0;
                }
            }
            else
            {
                return 0;
            }
        }
}
    return 1;
}

int Search_studentById(int id,std_t *psc){
  int flag=0;
for(int i=0;i<NoOfStudent;i++){

    if(psc[i].id == id){
        flag=i;
        student_print(psc[i]);
        flag=1;
        return i;
        break;
    }else{
    flag=0;
    }
}
if(flag==0){
    printf("This ID Don't Exist.\n");
    printf("=======================\n");
    return -1;
}
}

/*****function Sort_School******/
void Sort_StudentById(){
    u8 another;
     int empty;
   empty=School_empty();
   if(empty==1){
do{
system("cls");
int x;
char z;
 consoleColor(4);
printf("\n----Choose How To Sort----\n\n");
      consoleColor(6);
printf(" 1-Big To Small  2-Small To Big  : ");
scanf("%d",&x);
 consoleColor(7);
if(x==1){
    printf("\n=======================\n");
    array_BubbleSort1(school);
}else{
    printf("\n=======================\n");
    array_BubbleSort2(school);
}
printf("Do you want print Student [y/n]: ");
scanf("%s",&z);
if(z == 'y'||z == 'Y'){
    printf_school(school);
}else{
     consoleColor(5);
    printf("\n=======================\n");
    printf("Do you Want To Sort Again [y/n] : ");
    scanf("%s",&another);
}
}
while(another == 'y'||another == 'Y');

}}

void array_BubbleSort1(std_t *arr){
// big to small

    int i,j, sortflag;
    std_t temp;
    for(i=0; i<NoOfStudent; i++)
    {
        sortflag=1;
        for(j=0; j<NoOfStudent-1-i; j++)
        {

            if(arr[j].id < arr[j+1].id)
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                sortflag=0;
            }
        }
        if(sortflag)
        {
            break;
        }
    }


}

void array_BubbleSort2(std_t *arr){
// small to big
    int i,j, sortflag;
    std_t temp;
    for(i=0; i<NoOfStudent; i++)
    {
        sortflag=1;
        for(j=0; j<NoOfStudent-1-i; j++)
        {

            if(arr[j].id > arr[j+1].id)
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                sortflag=0;
            }
        }
        if(sortflag)
        {
            break;
        }
    }
    //printf_school(school);

}

/*****function Edit_Student******/
void Edit_Student(){
    u8 another;
     int empty;
   empty=School_empty();
   if(empty==1){
do{
system("cls");
int x,y,loc;
char str[100];
 consoleColor(4);
printf("\n----Choose How To Search Student To Edit ----\n\n");
    consoleColor(6);
printf("1-ID  2-Name [1/2] : ");
    consoleColor(1);
scanf("%d",&x);
if(x==1){
    printf("=======================\n");
    printf("Enter ID  :");
    scanf("%d",&y);
     consoleColor(6);
    printf("=======================\n");
    loc=Search_studentById(y,school);

}else{
    printf("=======================\n");
    printf("Enter Name  :");
    string_scan(str);
     consoleColor(6);
    printf("=======================\n");
    loc=Search_studentByName(str ,school);
}
 consoleColor(5);
 printf("Are you sure you want to Edit the student data? [y/n] : ");
 scanf("%s", &another);
 if(another == 'y' || another == 'Y'){
    Edit_Student_fun(&school[loc]);
 }
 printf("=======================\n");
 printf("Do you want to Edit Student another [y/n] : ");
 scanf("%s", &another);

}
while(another == 'y'||another == 'Y');

}}

void start1(void){
        consoleColor(4);
printf("\n-----Edit DATA OF Student-----\n\n");
    consoleColor(6);
printf("[1] Student Name \n");
printf("[2] Student ID \n");
printf("[3] Student Age  \n");
printf("[4] Student Phone  \n");
}

void Edit_Student_fun(std_t *ps){
      u8 another;
   do{
    system("cls");
    fflush(stdin);
    start1();
    int op;
    consoleColor(5);
    printf("\n=======================\n");
    printf("Choose : ");
    scanf("%d",&op);
  consoleColor(7);
switch(op){

case 1: printf("\n=======================\n");
        printf("Enter New name : ");
         string_scan(&ps->name);
         break;
case 2: printf("\n=======================\n");
        printf("Enter New ID :");
        scanf("%d",&ps->id);
        break;
case 3: printf("\n=======================\n");
        printf("Enter New Age :");
        scanf("%d",&ps->age);
        break;
case 4 :printf("\n=======================\n");
        printf("Enter New phone :");
         string_scan(&ps->phone);
         break;
 default :printf("\n=======================\n");
          printf("no Edit");
            break;
}
printf("\n=======================\n");
 printf("Do you want to Edit another part [y/n] : ");
 scanf("%s", &another);
 printf("\n");
 consoleColor(5);

}
while(another == 'y'||another == 'Y');

}

/*****function Remove_Student******/
void Remove_Student(){
    u8 another;
     int empty;
   empty=School_empty();
   if(empty==1){
do{
system("cls");
int x,y,loc;
char str[100];
consoleColor(4);
printf("\n----Choose How To Search Student To Remove ----\n");
consoleColor(6);
printf("\n1-ID  2-Name [1/2] : ");
consoleColor(7);
scanf("%d",&x);
printf("\n");
if(x==1){
    printf("=======================\n");
    printf("Enter ID  : ");
    scanf("%d",&y);
    printf("\n=======================\n");
    loc=Search_studentById(y,school);

}else{
    printf("=======================\n");
    printf("Enter Name  :");
    string_scan(str);
    printf("\n=======================\n");
    loc=Search_studentByName(str ,school);
}
if(loc != -1){
 consoleColor(6);
 printf("Are you sure you want to Remove this student ? [y/n] : ");
 scanf("%s", &another);
 if(another == 'y' || another == 'Y'){
    Remove_Student_fun(loc);
 }

}
consoleColor(5);
printf("\n=======================\n");
printf("Do you want to  Remove another Student [y/n] : ");
scanf("%s", &another);

}
while(another == 'y'||another == 'Y');

}}

void Remove_Student_fun(int loc){
    std_t temp;

    for(int i=loc ;i<NoOfStudent;i++){

                temp=school[i];
                school[i]=school[i+1];
                school[i+1]=temp;
    }
    NoOfStudent--;

}

/*****function FileStream (in/out)******/
void write_file(std_t *school){

FILE *file;
  file = fopen("file.txt", "w");
  if (file == NULL)
  {
    printf("Error opening file.\n");
    return 1;
  }


  for (int i = 0; i < NoOfStudent; i++)
  {

    fprintf(file,
            "%s,%d,%d,%s\n",
            school[i].name,
            school[i].id,
            school[i].age,
            school[i].phone);

    if (ferror(file))
    {
      printf("Error writing to file.\n");
      return 1;
    }
  }

  fclose(file);
  consoleColor(4);
  printf("Student in School Now = ");
  printf("[%d]\n\n", NoOfStudent);

  consoleColor(5);
}

void Read_File(std_t *school){
   FILE *file;
    file = fopen("file.txt", "r");


    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    int read = 0;
    int records = 0;

    do
    {
        read = fscanf(file,
                      "%49[^,] , %d , %d , %s\n",
            &school[records].name,
            &school[records].id,
            &school[records].age,
            &school[records].phone);

        if (read == 4) records++;

        if (read != 4 && !feof(file))
        {
            printf("File format incorrect.\n");
            return 1;
        }

        if (ferror(file))
        {
            printf("Error reading file.\n");
            return 1;
        }
    }
    while (!feof(file));

    fclose(file);
    NoOfStudent=records;
}




