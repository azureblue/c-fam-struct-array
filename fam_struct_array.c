#include "fam_struct_array.h"

typedef struct {} * struct_ptr;

static int pad(size_t offset, int align)
{
    return (align - (offset % align)) % align;
}

void * fam_struct_create_array(size_t struct_size, size_t struct_alignment, size_t flexible_array_size, size_t length)
{
    size_t ptrs = sizeof(struct_ptr) * length;
    ptrs += pad(ptrs, struct_alignment);    
    
    size_t struct_with_fam = struct_size + flexible_array_size;
    struct_with_fam += pad(struct_with_fam, struct_alignment);
    
    size_t req_mem = ptrs + struct_with_fam * length;
    
    void * mem = fam_struct_array_alloc_function(req_mem);
    
    if (!mem)
        return NULL;
    
    for (int i = 0; i < length; i++) 
        ((struct_ptr *) mem)[i] = (struct_ptr) ((char *) mem + ptrs + (struct_with_fam * i));
    
    return mem;
}