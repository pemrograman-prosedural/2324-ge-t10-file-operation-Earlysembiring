// 12S23018 - Early Sembiring
// 12S23027 - Amos Manurung

#include "./libs/repository.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 256
#define DELIMITER "#"

void sanitize(char *str);
void process_query(char *query, Repository *repo);

int main(void) {
	
	Repository *repo = malloc(sizeof(Repository));
	if (!repo) {
		perror("Failed to allocate memory for repository");
		return EXIT_FAILURE;
	}

	init_repo(repo);
	load_dorms(repo, "./storage/dorm-repository.txt");
	load_students(repo, "./storage/student-repository.txt");

	char query[SIZE];
	while (fgets(query, SIZE, stdin)) {
		sanitize(query);
		process_query(query, repo);
	}

	destroy_repo(repo);

	return 0;
}

void sanitize(char *str) {
	if (str) {
		str[strcspn(str, "\n")] = 0;
	}
}

void process_query(char *query, Repository *repo) {
	char* command = strtok(query, DELIMITER);
	if (!command) return;

	if (strcmp(command, "---") == 0) {
		exit(0);
	}

	if (strcmp(command, "dorm-print-all") == 0) {
		print_dorms(repo->dorms, repo->num_dorms);
		return;
	}
	
	if (strcmp(command, "student-print-all") == 0) {
		print_students(repo->students, repo->num_students);
		return;
	}

	if (strcmp(command, "dorm-print-all-detail") == 0) {
		print_detailed_dorms(repo->dorms, repo->num_dorms);
		return;
	}

	if (strcmp(command, "student-print-all-detail") == 0) {
		print_detailed_students(repo->students, repo->num_students);
		return;
	}

	if (strcmp(command, "dorm-add") == 0) {
		char* name = strtok(NULL, DELIMITER);
		char* capacity_str = strtok(NULL, DELIMITER);
		char* gender_str = strtok(NULL, DELIMITER);

		if (name && capacity_str && gender_str) {
			unsigned short capacity = (unsigned short) atoi(capacity_str);
			Dorm dorm = new_dorm(name, capacity, gender_str);
			add_dorm(repo, dorm);
		}
		return;
	}
	
	if (strcmp(command, "student-add") == 0) {
		char *id = strtok(NULL, DELIMITER);
		char *name = strtok(NULL, DELIMITER);
		char *cohort_str = strtok(NULL, DELIMITER);
		char *gender_str = strtok(NULL, DELIMITER);

		if (id && name && cohort_str && gender_str) {
			unsigned short cohort = (unsigned short) atoi(cohort_str);
			Student student = new_student(id, name, cohort, strto_gender(gender_str), NULL);
			add_student(repo, student);
		}
		return;
	}

	if (strcmp(command, "assign-student") == 0) {
		char *student_id = strtok(NULL, DELIMITER);
		char *dorm_name = strtok(NULL, DELIMITER);

		if (student_id && dorm_name) {
			assign_student(repo, student_id, dorm_name);
		}
		return;
	}
	
	puts("Unknown command");
}
