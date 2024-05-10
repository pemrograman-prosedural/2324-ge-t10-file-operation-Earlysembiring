#ifndef GENDER_H
#define GENDER_H

/**
 * @brief define your structure, enums, globally accessible variables, and function prototypes here.
 * The actual function implementation should be defined in the corresponding source file.
 *
 */

typedef enum {
	GENDER_NA,
	GENDER_MALE,
	GENDER_FEMALE
} Gender;

const char* gender_tostr(Gender gender);
Gender strto_gender(const char* gender_str);

#endif