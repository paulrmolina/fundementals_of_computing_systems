#include <stdio.h>
#include <stdlib.h>

int main( int argc, char **argv )
{
   int num       = 0;
   int counter   = 0;

   num = strtol( argv[1], NULL, 10 );

   while( num != 0 )
   {
      num = num * 4;
      num = num + 4;
      num = num / 2;
      num = num - 2;
      num = num / 2;
      num = num - 1;

      counter++;
   }

   printf( "%d\n", counter );

   return 0;
}
