#include"windows.h"

#define u8 char


typedef struct {
char name[20];
int id;
int age;
char phone[11];

}std_t;

int School_empty(void);

void Read_File(std_t *school);
void write_file(std_t *school);

void start(void);
void string_scan(char *str);
void string_print(char *str);
void add_student(std_t *ps);
void printf_school(std_t *psc);
void student_print(std_t s);
void Search_student();
int Search_studentById(int id,std_t *psc);
char string_compareNotcaseSenstive(char *str1,char *str2);
int Search_studentByName(char*str ,std_t *psc);

void Sort_StudentById();
void array_BubbleSort1(std_t *arr);
void array_BubbleSort2(std_t *arr);

void Edit_Student();
void start1(void);
void Edit_Student_fun(std_t *ps);

void Remove_Student();
void Remove_Student_fun(int loc);


