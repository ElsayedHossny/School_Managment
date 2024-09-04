#include <stdio.h>
#include <stdlib.h>
#include"Console_color.h"
#include"function.h"

/******************************** Created_by_Elsayed_Hossny ***********************************/
std_t school[100]={};
int NoOfStudent=0;
int choose=0;

int main()
{


Read_File(school);

    while(choose!=7){
          system("cls");
          start();
          consoleColor(5);
          printf("=======================\n");
          printf("Choose : ");
          scanf("%d",&choose);
        switch(choose)
        {

        case 1:
            system("cls");
            add_student(school);
            break;
        case 2:
            system("cls");
            Edit_Student();
            break;
        case 3:
            system("cls");
            Remove_Student();
            break;
        case 4:
            system("cls");
            Search_student();
            break;
        case 5:
            system("cls");
            printf_school(school);
            break;
        case 6:
            system("cls");
            Sort_StudentById();
            break;
       default :
            system("cls");
            consoleColor(4);
            printf("\n----Good Day----\n\n");
            write_file(school);
            break;
        }
    }

    return 0;
}
