#define max_size 5
#define int_block 20

struct big_int{
    char str_num[100];
    long int num[int_block];
    char sign;
};

typedef struct big_int Big_int;

Big_int* add(Big_int* a,Big_int* b);

Big_int* create_big_int();

void print_value(Big_int* n);

Big_int* subtract(Big_int* a,Big_int* b);