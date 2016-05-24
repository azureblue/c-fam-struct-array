#include "fam_struct_array.h"

typedef struct {} * struct_ptr;

static inline size_t pad(size_t offset, size_t align)
{
    return offset + (~offset & (align - 1)) + 1;
}

static inline void * offset(void * ptr, size_t offset)
{
    return (char *) ptr + offset;
}

void * fam_struct_create_array(size_t struct_size, size_t struct_alignment, size_t flexible_array_size, size_t length)
{
    size_t ptrs_size = pad(sizeof(struct_ptr) * length, struct_alignment);
    size_t struct_with_fam_size = pad(struct_size + flexible_array_size, struct_alignment);
    
    size_t req_mem_size = ptrs_size + struct_with_fam_size * length;
    
    void * mem = fam_struct_array_alloc_function(req_mem_size);
    
    if (!mem)
        return NULL;
    
    for (int i = 0; i < length; i++) 
        ((struct_ptr *) mem)[i] = offset(mem, ptrs_size + (struct_with_fam_size * i));
    
    return mem;
}
