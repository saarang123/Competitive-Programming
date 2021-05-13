#include <stdio.h>
/* Program to find sum of digits of a five digit number */
int main() {
    int no, sum;
    scanf("%d", &no);
    sum =(no)%10 + (no/10)%10 + (no/100)%10 + (no/1000)%10 + (no/10000)%10;
    printf("%d", sum);
	
}
