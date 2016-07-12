# c-fam-struct-array
Allocating memory for multiple structs with flexible array member in a single memory block.

```C
struct struct_with_fam
{
    int x;
    int y;
    double data[];
};

int fam_length = 20;
int ar_length = 10;

struct struct_with_fam ** ar = allocate_structs(struct struct_with_fam, fam_length, ar_length);

for (int i = 0; i < ar_length; i++)
{
    ar[i]->x = i;
    ar[i]->y = 0;
}

...

free(ar);

```
