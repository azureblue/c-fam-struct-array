#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>

#include "fam_struct_array.h"

void * m_alloc(size_t size)
{
    return malloc(size);
}

struct fam_struct
{
    int len;
    double data[];
};

int main()
{
    int ar_length = 100;
    int fam_length = 127;
    
    struct fam_struct ** ar = allocate_structs(struct fam_struct, fam_length, ar_length);
    
    for (int i = 0; i < ar_length; i++)
    {
        assert((uintptr_t)ar[i] % (uintptr_t) (alignof (struct fam_struct)) == 0);
        ar[i]->len = fam_length;
    }
    
    free(ar);
}