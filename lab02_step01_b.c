#include <stdio.h>
#define N 10
#define M 3

int main()
{
    int i,j;
    double data[N][M];
    double prod = 1.0;

    for (i = 0; i < N; i++)
    {
        for (j=0; j<M; j++){
            data[i][j] = ((double) i*j+1) / N;
            prod = prod * data[i][j];   //ypologismos ginomenou
            printf("%g ", data[i][j]);   //ektyposh stoixeiou
        }
        printf("\n");   //allagh grammhs pinaka
    }

    printf("\nto ginomeno einai: %g\n", prod);

    return 0;
}