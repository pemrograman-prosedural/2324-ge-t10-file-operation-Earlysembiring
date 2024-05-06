// 12S23018 - Early Sembiring
// 12S23027 - Amos Manurung


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./libs/dorm.h"
#include "./libs/student.h"
#include "./libs/repository.h"
#define _SIZE 255

int main(int _argc, char **_argv) 
{
    Dorm *dorms = (Dorm*) malloc(1 * sizeof(Dorm));
    Student *students = (Student*) malloc(1 * sizeof(Student));
    unsigned short totalDorm = 0;
    unsigned short totalStudent = 0;
    char line[_SIZE];
    char* token;
    char* delim = "#"; 
    char* comand; 
