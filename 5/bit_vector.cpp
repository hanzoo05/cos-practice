#include <cstdio>
#include <cstdlib>
#include <cstring>

#define BIT_VECTOR_LENGTH 4
#define MSB_INDEX BIT_VECTOR_LENGTH - 1
#define LSB_INDEX 0
#define true 1
#define false 0

void print_command(char *argv[]);
int check_validity(char *input);
void init_bit_vector(char *input, char *bv);
void print_bit_vector(char *bv);

unsigned int b2u(char *bv);
int b2s(char *bv);
int b2o(char *bv);
int b2t(char *bv);

int main(int argc, char *argv[])
{
    char bv1[BIT_VECTOR_LENGTH];
    char bv2[BIT_VECTOR_LENGTH];

    if (argc != 3)
    {
        printf("Error: invalid number of arguments\n");
        print_command(argv);
    }

    if (!(check_validity(argv[1]) && check_validity(argv[2])))
    {
        printf("Error: invalid arguments\n");
        print_command(argv);
    }

    init_bit_vector(argv[1], bv1);
    init_bit_vector(argv[2], bv2);
    print_bit_vector(bv1);
    printf(" -B2U: %u\n", b2u(bv1));
    printf(" -B2S: %u\n", b2s(bv1));
    printf(" -B2O: %u\n", b2o(bv1));
    printf(" -B2T: %u\n", b2t(bv1));   
    print_bit_vector(bv2);        
    printf(" -B2U: %u\n", b2u(bv2));
    printf(" -B2S: %u\n", b2s(bv2));
    printf(" -B2O: %u\n", b2o(bv2));
    printf(" -B2T: %u\n", b2t(bv2));

    return 0;
}

void print_command(char *argv[])
{
    printf("Command: %s <first bit vector> <second bit vector>\n", argv[0]);
    printf("Example: %s 0110 1000\n", argv[0]);
    exit(1);
}

int check_validity(char *input)
{
    // ./bitvector 011 1111 (must be an error)
    // ./bitvector 2222 1111 (must be an error)
    // ./bitvector 0000 1111 (must not be an error)

    int len, ret;
    ret = true;

    // 1. The length of the input must be identical to BIT_VECTOR_LENGTH
    len = strlen(input);
    if (len != BIT_VECTOR_LENGTH)
        ret = false;

    // 2. The bits must be either 0 or 1
    int i;
    for (i = 0; i < len; i++)
    {
        if (!(input[i] == '0' || input[i] == '1'))
        {
            ret = false;
            break;
        }
    }
    return ret;
}

void init_bit_vector(char *input, char *bv)
{
    // "0101" -> bv[0] = 1, bv[1] = 0, bv[2] = 1, bv[3] = 0 
    char c;
    int i, len;
    len = strlen(input);

    for (i=0; i<len; i++)
    {
        c = input[i];
        if (c == '0')
            bv[MSB_INDEX-i] = 0;
        else
            bv[MSB_INDEX-i] = 1;
    }
}

void print_bit_vector(char *bv)
{
    int i;
    
    printf("Bit Vector: ");
    for(i = MSB_INDEX; i>=LSB_INDEX; i--)
        printf("%d", bv[i]);
    printf("\n");
}

int exp(int b, int e)
{
    int i, ret;
    ret = 1;
    for (i=0; i<e; i++)
        ret *= b;
    return ret;
}

unsigned int b2u(char *bv)
{
    unsigned int ret;
    ret = 0;
    int i;

    for (i=LSB_INDEX; i<=MSB_INDEX; i++)
        ret += bv[i] * exp(2,i);
    return ret;
}

int b2s(char *bv)
{
    int i, sign, ret;
    ret = 0;
    sign = exp(-1, bv[MSB_INDEX]);

    for (i=LSB_INDEX; i<MSB_INDEX; i++)
        ret += bv[i] * exp(2, i);
    ret *= sign;
    return ret;
}

int b2o(char *bv)
{
    int ret;
    ret = 0;
    return ret;
}

int b2t(char *bv)
{
    int ret;
    ret = 0;
    return ret;
}