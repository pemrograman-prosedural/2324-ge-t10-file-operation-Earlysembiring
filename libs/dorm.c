#include "dorm.h"
#include "gender.h"

#include <stdio.h>
#include <string.h> 

/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 *
 */

Dorm new_dorm(const char *name, unsigned short capacity, const char *gender_str) {
	Dorm dorm;

	strncpy(dorm.name, name, sizeof(dorm.name) - 1);
	dorm.name[sizeof(dorm.name) - 1] = '\0';

	dorm.capacity = capacity;
	dorm.gender = strto_gender(gender_str);
	dorm.num_residents = 0;

	return dorm;
}

void print_dorm(const Dorm *dorm) {
	printf("%s|%hu|%s\n", dorm->name, dorm->capacity, gender_tostr(dorm->gender));
}

void print_dorm_detailed(const Dorm *dorm) {
	printf("%s|%hu|%s|%hu\n", dorm->name, dorm->capacity, gender_tostr(dorm->gender), dorm->num_residents);
}
