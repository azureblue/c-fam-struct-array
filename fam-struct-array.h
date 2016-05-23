#ifndef FAM_STRUCT_ARRAY_H
#define FAM_STRUCT_ARRAY_H

#include <stdlib.h>

#define fam_struct_array_alloc_function malloc

void * create_struct_array(size_t struct_size, size_t flexible_array_size, size_t length);

#endif /* FAM_STRUCT_ARRAY_H */

