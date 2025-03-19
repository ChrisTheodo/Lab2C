#include <stdio.h>
#define N 10

int main()
{
    int i;
    double data[N];
    double prod = 1.0;

    for (i = 0; i < N; i++)
    {
        data[i] = ((double) i+N ) / N;
        prod = prod * data[i];  //ypologismos ginomenou
    }

    printf("\n%g\n", prod);

    return 0;
}