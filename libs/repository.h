#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "dorm.h"
#include "gender.h"
#include "student.h"

/**
 * @brief define your structure, enums, globally accessible variables, and function prototypes here.
 * The actual function implementation should be defined in the corresponding source file.
 *
 */

typedef struct {
	Dorm* dorms;
	unsigned short num_dorms;
	Student* students;
	unsigned short num_students; 
} Repository;

void init_repo(Repository *repo);
void destroy_repo(Repository *repo);
void load_dorms(Repository *repo, const char *filename);
void load_students(Repository *repo, const char *filename);
void add_dorm(Repository *repo, Dorm dorm);
void add_student(Repository *repo, Student student);
void assign_student(Repository *repo, const char *student_id, const char *dorm_name);
void move_student(Repository *repo, const char *student_id, const char *dorm_name);
void print_dorms(Dorm *dorms, unsigned short num_dorms);
void print_students(Student *students, unsigned short num_students);
void print_detailed_dorms(Dorm *dorms, unsigned short num_dorms);
void print_detailed_students(Student *students, unsigned short num_students);

#endif