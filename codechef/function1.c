#include <stdio.h>

main( )
{
    float square ( float );
    float a, b ;
    printf ( "\nEnter any number " ) ;
    scanf ( "%f", &a ) ;
    b = square ( a ) ;
    printf ( "\nSquare of %f is %f", a, b ) ;
}
float square ( float x )
{
    float y ;
    y = x * x ;
    return ( y );
}