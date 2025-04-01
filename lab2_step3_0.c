#include <stdio.h>
#define rightTemp -5.0
#define leftTemp 4.0
#define topTemp 2.0 
#define bottomTemp 3.0
#define rows 10
#define columns 20

void reset();
double getCornerTemp(double firstSide, double secondSide);
void printArray(double temps[columns][rows]);
double getTemp(double num, double left, double right, double top, double bottom);
void timeChange(double temps[columns][rows], int time);

int main(void){
    double temps[columns][rows];

    reset(temps);
    printArray(temps);
    for (int time=1; time<2; time++){
        timeChange(temps, time);
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
    for (int xrow=1; xrow<rows-2; xrow++){
        for (int xcolumn=1; xcolumn<columns-2; xcolumn++){
            temps[xcolumn][xrow] = 0.0;
        }
    }
    temps[0][0] = getCornerTemp(topTemp, leftTemp);
    temps[columns-1][0] = getCornerTemp(topTemp, rightTemp);
    temps[0][rows-1] = getCornerTemp(bottomTemp, leftTemp);
    temps[columns-1][rows-1] = getCornerTemp(bottomTemp, rightTemp);
}

void printArray(double temps[columns][rows]){
    for (int xrow=0; xrow<rows; xrow++){
        for (int xcolumn=0; xcolumn<columns; xcolumn++){
            printf("%.1f ", temps[xcolumn][xrow]);    
        }
        printf("\n");
    }
}

double getTemp(double num, double left, double right, double top, double bottom){
    printf("getTemp");
    return 0;
}

void timeChange(double temps[columns][rows], int time){
    printf("timeChange");
}