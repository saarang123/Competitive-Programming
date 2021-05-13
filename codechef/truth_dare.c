#include <stdio.h>
int main(){
    int i = 0;
    while(i<20)
    {
        int user, comp;
        printf("Enter your choice(between 1-4): \n");
        scanf("%d", &user);
        i+=user;
        comp =4 - (i%4);
        printf("Computer plays %d \n", comp);
        i += comp;
        printf("Now total count is %d \n", i);
    }
    printf("Haha, you have to pick up the last stick. YOU LOSE! :D");
}