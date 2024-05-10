#ifndef STUDENT_H
#define STUDENT_H

#include "dorm.h"
#include "gender.h"

/**
 * @brief define your structure, enums, globally accessible variables, and function prototypes here.
 * The actual function implementation should be defined in the corresponding source file.
 *
 */

typedef struct {
	char id[9];
	char name[128];
	unsigned short cohort;
	Gender gender;
	Dorm *dorm;
} Student;

Student new_student(const char *id, const char *name, unsigned short cohort, Gender gender, Dorm *dorm);
void print_student(const Student *student);
void print_student_detailed(const Student *student);

#endif