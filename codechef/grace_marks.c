#include <stdio.h>

int main() 
{
	int c, f;
	printf("Enter class: \n");
	scanf("%d", &c);
	printf("Enter no. of failed subjects: \n");
	scanf("%d", &f);
	switch(c)
	{   
	    case 1:
	        if(f>3)
	            printf("No grace marks for you");
	        else
	            printf("You get 5 grace marks per subject :D ");
	        break;
	    case 2:
	        if(f>2)
	            printf("No grace marks for you");
	        else
	            printf("You get 4 grace marks per subject :D ");
	        break;
	    case 3:
	        if(f>1)
	            printf("No grace marks for you");
	        else
	            printf("You get 5 grace marks for the one subject you failed :D ");
	        break;
	    default:
	        printf("Wrong input for class");
	}
}