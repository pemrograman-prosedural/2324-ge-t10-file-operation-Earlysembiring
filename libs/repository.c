#include "repository.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 *
 */

void init_repo(Repository* repo) {
	repo->dorms = NULL;
	repo->num_dorms = 0;
	repo->students = NULL;
	repo->num_students = 0;
}

void destroy_repo(Repository *repo) {
if (repo == NULL) return;

	if (repo->dorms) {
		free(repo->dorms);
		repo->dorms = NULL;
	}

	if (repo->students) {
		free(repo->students);
		repo->students = NULL;
	}

	free(repo);
}

void add_dorm(Repository* repo, Dorm dorm) {
	Dorm* temp = realloc(repo->dorms, (repo->num_dorms + 1) * sizeof(Dorm));
	if (!temp) {
		perror("Failed to allocate memory");
		exit(EXIT_FAILURE);
	}
	repo->dorms = temp;

	repo->dorms[repo->num_dorms++] = dorm;
}

void add_student(Repository *repo, Student student) {
	Student* temp = realloc(repo->students, (repo->num_students + 1) * sizeof(Student));
	if (!temp) {
		perror("Failed to allocate memory");
		exit(EXIT_FAILURE);
	}
	repo->students = temp;

	repo->students[repo->num_students++] = student;
}

void assign_student(Repository *repo, const char *student_id, const char *dorm_name) {
	Student *student = NULL;
	Dorm *dorm = NULL;

	for (int i = 0; i < repo->num_students; i++) {
		if (strcmp(repo->students[i].id, student_id) == 0) {
			student = &repo->students[i];
			break;
		}
	}

	for (int i = 0; i < repo->num_dorms; i++) {
		if (strcmp(repo->dorms[i].name, dorm_name) == 0) {
			dorm = &repo->dorms[i];
			break;
		}
	}

	if (student && dorm) {
		if (dorm->gender == student->gender && dorm->capacity > dorm->num_residents) {
			student->dorm = dorm;
			dorm->num_residents++;
		}
	}
}

void move_student(Repository *repo, const char *student_id, const char *dorm_name) {
	Student *student = NULL;
	Dorm *old_dorm = NULL;
	Dorm *new_dorm = NULL;

	for (int i = 0; i < repo->num_students; i++) {
		if (strcmp(repo->students[i].id, student_id) == 0) {
			student = &repo->students[i];
			old_dorm = student->dorm;
			break;
		}
	}

	for (int i = 0; i < repo->num_dorms; i++) {
		if (strcmp(repo->dorms[i].name, dorm_name) == 0) {
			new_dorm = &repo->dorms[i];
			break;
		}
	}

	if (student && old_dorm && new_dorm) {
		if (new_dorm->gender == student->gender && new_dorm->capacity > new_dorm->num_residents) {
			student->dorm = new_dorm;
			old_dorm->num_residents--;
			new_dorm->num_residents++;
		}
	}
}

void load_dorms(Repository *repo, const char *filename) {
	FILE* file = fopen(filename, "r");
	if (!file) {
		perror("Unable to open the file");
		exit(EXIT_FAILURE);
	}

	char buffer[256];
	while (fgets(buffer, sizeof(buffer), file)) {
		buffer[strcspn(buffer, "\n")] = 0;

		char *name = strtok(buffer, "|");
		char *capacity = strtok(NULL, "|");
		char *gender_str = strtok(NULL, "|");

		if (name && capacity && gender_str) {
			Dorm dorm = new_dorm(name, (unsigned short) atoi(capacity), gender_str);
			add_dorm(repo, dorm);
		}
	}
	fclose(file);
}

void load_students(Repository *repo, const char *filename) {
	FILE *file = fopen(filename, "r");
	if (!file) {
		perror("Unable to open the file");
		exit(EXIT_FAILURE);
	}

	char buffer[256];
	while (fgets(buffer, sizeof(buffer), file)) {
		buffer[strcspn(buffer, "\n")] = 0;

		char *id = strtok(buffer, "|");
		char *name = strtok(NULL, "|");
		char *cohort = strtok(NULL, "|");
		char *gender_str = strtok(NULL, "|");

		if (id && name && cohort && gender_str) {
			Student student = new_student(id, name, (unsigned short) atoi(cohort), strto_gender(gender_str), NULL);
			add_student(repo, student);
		}
	}
	fclose(file);
}

void print_dorms(Dorm *dorms, unsigned short num_dorms) {
	for (unsigned short i = 0; i < num_dorms; i++) {
		print_dorm(&dorms[i]);
	}
}

void print_students(Student *students, unsigned short num_students) {
	for (unsigned short i = 0; i < num_students; i++) {
		print_student(&students[i]);
	}
}

void print_detailed_dorms(Dorm *dorms, unsigned short num_dorms) {
	for (unsigned short i = 0; i < num_dorms; i++) {
		print_dorm_detailed(&dorms[i]);
	}
}

void print_detailed_students(Student *students, unsigned short num_students) {
	for (unsigned short i = 0; i < num_students; i++) {
		print_student_detailed(&students[i]);
	}
}
 