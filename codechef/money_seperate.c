#include <stdio.h>
/* Program to take money as input and seperate it into the various kinds of notes */
int main() {
    int c, h, t, f;
    scanf("%d", &c);
    h = c/100;
    c = c%100;
    f = c/50;
    c = c%50;
    t = c/10;
    printf("the number of 100 notes is %d \n",h);
    printf("the number of 50 notes is %d \n",f);
    printf("the number of 10 notes is %d \n",t);
}
