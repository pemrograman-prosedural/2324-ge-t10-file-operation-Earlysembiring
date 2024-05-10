#ifndef DORM_H
#define DORM_H

#include "gender.h"

/**
 * @brief define your structure, enums, globally accessible variables, and function prototypes here.
 * The actual function implementation should be defined in the corresponding source file.
 *
 */

typedef struct {
	char name[16];
	unsigned short capacity;
	Gender gender;
	unsigned short num_residents;
} Dorm;

Dorm new_dorm(const char *name, unsigned short capacity, const char *gender_str);
void print_dorm(const Dorm *dorm);
void print_dorm_detailed(const Dorm *dorm);

#endif