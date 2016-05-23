#ifndef FAM_STRUCT_ARRAY_H
#define FAM_STRUCT_ARRAY_H

#include <stdalign.h>
#include <stddef.h>

#define fam_struct_array_alloc_function m_alloc
extern void * fam_struct_array_alloc_function(size_t);

#define allocate_structs(struct_type, flexible_array_size, length)                                                                    \
    fam_struct_create_array(sizeof(struct_type), alignof(struct_type), flexible_array_size, length)

void * fam_struct_create_array(size_t struct_size, size_t struct_alignment, size_t flexible_array_size, size_t length);

#endif /* FAM_STRUCT_ARRAY_H */

