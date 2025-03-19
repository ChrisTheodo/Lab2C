#include <stdio.h>
#define N 10
int load(double x[N]);
int print(double x[N]);
double computeprod(double x[N]);
void printprod(double prod);

int main()
{
    double data[N];
    double prod = 1.0 ;

    load(data);
    print(data);
    prod = computeprod(data);
    printprod(prod);

    return 0;
}

int print(double x[N])
{
    int i;
    for (i = 0; i < N; i++)
    {
        printf(" %g ", x[i]);
    }

    return 0;
}

int load(double x[N])
{
    int i;
    for (i = 0; i < N; i++)
    {
        x[i] = ((double) i+N )  / N;
    }

    return 0;
}

double computeprod(double x[N]){
    double prod= 1.0;
    for (int i=0; i<N; i++){
        prod = prod * x[i];
    }
    return prod;
}

void printprod(double prod){
    printf("\nto ginomeno einai: %g", prod);
}