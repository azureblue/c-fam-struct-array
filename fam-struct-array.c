#include "fam-struct-array.h"

typedef struct {} * struct_ptr;

static int padding(size_t offset, int align)
{
    return (align - (offset % align)) % align;
}

void * create_struct_array(size_t struct_size, size_t flexible_array_size, size_t length)
{
    size_t ptrs = sizeof(struct_ptr) * length;
    ptrs += padding(ptrs, struct_size);    
    
    size_t struct_with_fam = struct_size + flexible_array_size;
    struct_with_fam += padding(struct_with_fam, struct_size);
    
    size_t req_mem = ptrs + struct_with_fam * length;
    
    void * mem = fam_struct_array_alloc_function(req_mem);
    
    for (int i = 0; i < length; i++) 
        ((struct_ptr *) mem)[i] = (struct_ptr) ((char *) mem + ptrs + (struct_with_fam * i));
    
    return mem;
}