#include <stdio.h>
#define N 10
#define M 3
int load(double x[N][M]);
int print(double x[N][M]);
double computeprod(double x[N][M]);
void printprod(double prod);
void transpose(double x[N][M], double xt[M][N]);

int main()
{
    double data[N][M];
    double dataT[M][N];
    double prod = 1.0 ;

    load(data);
    print(data);
    prod = computeprod(data);
    printprod(prod);

    transpose(data, dataT);

    return 0;
}

int print(double x[N][M])
{
    int i,j;
    for (i = 0; i < N; i++)
    {
        for (j=0; j<M; j++)
            printf("%g ", x[i][j]);
        printf("\n");
    }

    return 0;
}

int load(double x[N][M])
{
    int i,j;
    for (i = 0; i < N; i++)
    {
        for (j=0; j<M; j++){
            x[i][j] =  ((double) i*j+1)/N;
        }
            
    }

    return 0;
}

double computeprod(double x[N][M]){
    double prod= 1.0;
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            prod = prod * x[i][j];
        }
    }
    return prod;
}

void printprod(double prod){
    printf("\nto ginomeno einai: %g\n", prod);
}

void transpose(double x[N][M], double xt[M][N]){
    for (int i=0;i<M; i++){
        for (int j=0; j<N; j++){
            xt[i][j] = x[j][i];
        }
    }
    for (int i=0;i<M; i++){
        for (int j=0; j<N; j++){
            printf("%g ", xt[i][j]);
        }
        printf("\n");
    }
    
}