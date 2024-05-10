#include "gender.h"

#include <string.h>

/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 *
 */

const char* gender_tostr(Gender gender) {
	switch (gender) {
		case GENDER_MALE: return "male";
		case GENDER_FEMALE: return "female";
		default: return "N/A";
	}
}

Gender strto_gender(const char* gender_str) {
	if (strcasecmp(gender_str, "male") == 0) {
		return GENDER_MALE;
	} else if (strcasecmp(gender_str, "female") == 0) {
		return GENDER_FEMALE;
	} else {
		return GENDER_NA;
	}
}
