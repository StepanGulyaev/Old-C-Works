#include <stdio.h>
#include <stdlib.h> 
#include <math.h>

int main ()
{
    double x,y;
    printf("Insert x\n");
    scanf("%lf", &x);
    printf("Insert y\n");
    scanf("%lf", &y);

    if ( (fabs(x) <= 1 && fabs(y)<=1) && (((( x >= 0 && y >= 0 ) || ( x <= 0 && y <= 0 )) && ( x*x + y*y >= 1)) || ((x >= 0 && y <= 0) && (y >= x-1)) || ((x <= 0 && y >= 0) && (y >= x+1) && (x*x + y*y <= 1)))  )
        {
        printf("Coordinates belong to the area");
        return 0;
        }
    printf("Coordinates don't belong to the area");
}