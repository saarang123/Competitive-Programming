#include <stdio.h>
/*Program to print reverse of a five digit number*/
int main() {
    int no;
    scanf("%d", &no);
    printf("%d",(no%10));
    printf("%d",(no/10)%10);
    printf("%d",(no/100)%10);
    printf("%d",(no/1000)%10);
    printf("%d",(no/10000)%10);
}