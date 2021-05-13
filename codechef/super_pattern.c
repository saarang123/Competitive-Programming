#include <stdio.h>
int main(){
    for(int i=71;i>=65;i--)
    {
        for(char a = 65; a<= i; a++)
            printf("%c ", a);
        for(int j=i; j< 71; j++)
            printf("  ");
        for(int j=71; j>i; j--)
            printf("  ");
        for(char a = i; a>=65;a--)
            printf("%c ", a);
        printf("\n");
            
    }
}