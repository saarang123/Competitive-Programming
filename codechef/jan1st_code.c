#include <stdio.h>
/* Program to find day of Jan 1st of given year. Not for leap yrs */
main() {
    int yr, d, old = 1899;
    scanf("%d", &yr);
    d = yr - old;
    d = d%7;
    if (d==1)
        printf("Tuesday");
    else if (d==0)
        printf("Monday");
    else if (d==2)
        printf("Wednesday");
    else if (d==3)
        printf("Thurday");
    else if (d==4)
        printf("Friday");
    else if (d==5)
        printf("Saturday");
    else
        printf("Sunday");
}