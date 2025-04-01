#include <stdio.h>
#define rightTemp -5.0
#define leftTemp 4.0
#define topTemp 2.0 
#define bottomTemp 3.0
#define rows 10
#define columns 20

void reset();
double getCornerTemp(double firstSide, double secondSide);
void printDoubleArray(double temps[columns][rows]);
double getTemp(double array[columns][rows], int xrow, int xcolumn);
void copyArray(double array[columns][rows], double newArray[columns][rows]);
void timeChange(double temps[columns][rows], int time);
void makeNormalizedArray(double array[columns][rows], int normalizedArray[columns][rows]);
void printIntArray(int array[columns][rows]);

int main(void){
    double temps[columns][rows];
    int normalizedTemps[columns][rows];

    reset(temps);
    printf("time: 0\n");
    printDoubleArray(temps);
    makeNormalizedArray(temps, normalizedTemps);
    printIntArray(normalizedTemps);

    for (int time=1; time<2; time++){
        printf("\ntime: %d\n", time);
        timeChange(temps, time);
        printDoubleArray(temps);
        makeNormalizedArray(temps, normalizedTemps);
        printIntArray(normalizedTemps);
    }
     
    return 0;
}

double getCornerTemp(double firstSide, double secondSide){
    return (firstSide+secondSide)/2;
}

void reset(double temps[columns][rows]){
    for (int xcolumn=1; xcolumn<columns-1; xcolumn++){
        temps[xcolumn][0] = topTemp;
    } 
    for (int xcolumn=1; xcolumn<columns-1; xcolumn++){
        temps[xcolumn][rows-1] = bottomTemp;
    }
    for (int xrow=1; xrow<rows-1; xrow++){
        temps[0][xrow] = leftTemp;
    }
    for (int xrow=1; xrow<rows-1; xrow++){
        temps[columns-1][xrow] = rightTemp;
    }
    for (int xrow=1; xrow<rows-1; xrow++){
        for (int xcolumn=1; xcolumn<columns-1; xcolumn++){
            temps[xcolumn][xrow] = 1.0;
        }
    }
    temps[0][0] = getCornerTemp(topTemp, leftTemp);
    temps[columns-1][0] = getCornerTemp(topTemp, rightTemp);
    temps[0][rows-1] = getCornerTemp(bottomTemp, leftTemp);
    temps[columns-1][rows-1] = getCornerTemp(bottomTemp, rightTemp);
}

void printDoubleArray(double temps[columns][rows]){
    for (int xrow=0; xrow<rows; xrow++){
        for (int xcolumn=0; xcolumn<columns; xcolumn++){
            if (temps[xcolumn][xrow]<0){printf(" %.2f", temps[xcolumn][xrow]);}
            else {printf("  %.2f", temps[xcolumn][xrow]);}    
        }
        printf("\n");
    }
}

double getTemp(double array[columns][rows], int xrow, int xcolumn){
    double x = 0.1*(array[xcolumn-1][xrow-1]+array[xcolumn-1][xrow]+array[xcolumn-1][xrow+1]+array[xcolumn][xrow-1]+2*array[xcolumn][xrow]+array[xcolumn][xrow+1]+array[xcolumn+1][xrow-1]+array[xcolumn+1][xrow]+array[xcolumn+1][xrow+1]);
    return x;
}

void copyArray(double array[columns][rows], double newArray[columns][rows]){
    for(int i=0;i<columns;i++){
    for(int j=0;j<rows;j++){
        newArray[i][j] = array[i][j];}}
}

void timeChange(double temps[columns][rows], int time){
    double oldTemps[columns][rows];
    copyArray(temps, oldTemps);
    for (int xcolumn=1; xcolumn<time+1; xcolumn++){
        for (int xrow=1; xrow<rows-1; xrow++){
            temps[xcolumn][xrow] = getTemp(oldTemps, xrow, xcolumn); 
            if (xrow==9){break;}           
        }
        if (xcolumn==9){break;}
    }
    for (int xcolumn=columns-2; xcolumn>time; xcolumn--){
        for (int xrow=1; xrow<rows-1; xrow++){
            temps[xcolumn][xrow] = getTemp(oldTemps, xrow, xcolumn);
            if (xrow==9){break;}      
        }
        if (xcolumn==1){break;}
    }

}

void makeNormalizedArray(double array[columns][rows], int normalizedArray[columns][rows]){
    for (int xcolumn=0; xcolumn<columns; xcolumn++){
        for (int xrow=0; xrow<rows; xrow++){
            if (array[xcolumn][xrow]<0){normalizedArray[xcolumn][xrow] = array[xcolumn][xrow]+4.49;}
            else {normalizedArray[xcolumn][xrow] = array[xcolumn][xrow]+5.5;}
        }
    }
}

void printIntArray(int array[columns][rows]){
    for (int xrow=0; xrow<rows; xrow++){
        for (int xcolumn=0; xcolumn<columns; xcolumn++){
            printf("  %d", array[xcolumn][xrow]);
        }
        printf("\n");
    }
}
