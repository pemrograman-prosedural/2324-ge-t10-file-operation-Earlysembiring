#include "dorm.h"
#include "gender.h"
#include "student.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 *
 */

Student new_student(const char *id, const char *name, unsigned short cohort, Gender gender, Dorm *dorm) {
	Student student;

	strncpy(student.id, id, sizeof(student.id) - 1);
	student.id[sizeof(student.id) - 1] = '\0';

	strncpy(student.name, name, sizeof(student.name) - 1);
	student.name[sizeof(student.name) - 1] = '\0';

	student.cohort = cohort;
	student.gender = gender;
	student.dorm = NULL;

	return student;
}

void print_student(const Student *student) {
	printf("%s|%s|%hu|%s\n", student->id, student->name, student->cohort, gender_tostr(student->gender));
}

void print_student_detailed(const Student *student) {
	printf("%s|%s|%hu|%s|", student->id, student->name, student->cohort, gender_tostr(student->gender));
    
	if (student->dorm) {
		printf("%s\n", student->dorm->name);
	} else {
		puts("unassigned");
	}
}
