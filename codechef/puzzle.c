#include "stdio.h"

int aresame(int A[][4], int B[][4]) 
{ 
    int i, j; 
    for (i = 0; i < 4; i++) 
        for (j = 0; j < 4; j++) 
            if (A[i][j] != B[i][j]) 
                return 0; 
    return 1; 
} 
int main()
{
    static int soln[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,0 }};
    static int l [4][4] = {{1,2,4, 8}, {5,6,3,12}, {9,10,7,0}, {13,14,11, 15}};
    int i=2,j=3,count = 0;
    for(int p=0;p<4;p++)
        {
            for(int q=0;q<4;q++)
                if(soln[p][q]==0)
                    printf("   ");
                else
                    printf("%d  ", soln[p][q]);
            printf("\n");
	}
    printf("-----------------------------------------------------------------------\n");
    for(int p=0;p<4;p++)
        {
            for(int q=0;q<4;q++)
                if(l[p][q]==0)
                    printf("    ");
                else
                    printf("%d  ", l[p][q]);
            printf("\n");
        }
    printf("-----------------------------------------------------------------------\n");
    while(! aresame(soln, l))
    {
	char user;
	printf("Enter U, D, L, or R: \n");
	scanf("%c \n", &user);
	if (user=='R') /*Right key*/
	{
            l[i][j] = l[i][j+1];
	    l[i][j+1] = 0;
	    j+=1;
	}
	else if(user=='L') /*Left key*/
	{
	    l[i][j]=l[i][j-1];
            l[i][j-1] = 0;
	    j-=1;
	}
	else if(user=='U') /*Up key*/
	{
	    l[i][j] = l[i-1][j];
 	    l[i-1][j] = 0;
	    i-=1;
	}
	else if(user=='D') /*Down key*/
	{
	    l[i][j] = l[i+1][j];
	    l[i+1][j] = 0;
	    i+=1;
	}
	count+=1;
	for(int p=0;p<4;p++)
        {
            for(int q=0;q<4;q++)
		if(l[p][q]==0)
		    printf("   ");
		else
		    printf("%d  ", l[p][q]);
	    printf("\n");
	}
     printf("-----------------------------------------------------------------------\n");
     }
     printf("Puzzle solved in %d moves. \n", count);
}