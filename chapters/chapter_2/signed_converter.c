#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT        2147483647 // Max 32 bit integer input
#define MAX_INPUT_LENGTH 10         // Max length of the user input
#define MAX_BIN_SIZE     32         // Max length of the binary representation
#define BASE_CHAR        '0'         // To conver character correctly

void printArray( char binaryRepresentation[], unsigned int length )
{
   int x;

   for( x = 0; x < length; x++ )
   {
      printf( "%c", binaryRepresentation[x] );
   }

   printf( "\n" );
}
void AddOneToOnesComplement( char binaryRepresentation[], unsigned int length )
{ 
   char carryOver = '1';
   char temp;
   int  x;

   for( x = length; x > 0; x-- )
   {
      temp = binaryRepresentation[x - 1];
      
      if( carryOver == '1' && temp == '1' )
      {
         binaryRepresentation[x - 1] = '0';
         carryOver = '1'; // carry over
      }
      else if ( carryOver == '1' && temp == '0' )
      {
         binaryRepresentation[x - 1] = '1';
         carryOver = '0';
      }
      else
      {
         // do nothing, the value will stay the same
      }
   }
}

// FUNCTION NAME: ConvertToOnesComplement
// 
// Description:
// Will take in a binary representation of an unsigned value and change it
// to a One's Complement value (all bits flipped)
//
// Input:
// Name: binaryRepresentation 
// Type: char
// Description: the binary representation to be manipulated as a character
// array
// 
// Name: length
// Type: unsigned int
// Description: the length of the binary representation
void ConvertToOnesComplement( char binaryRepresentation[], unsigned int length )
{
   int x;

   for( x = 0; x < length; x++ )
   {
      binaryRepresentation[x] = binaryRepresentation[x] == '0' ? '1' : '0';
   }
}

// FUNCTION NAME: ConvertToTwosComplement
//
// Description:
// Will take in a binary representation of an unsigned value and change it
// to a Two's Complement value (all bits flipped and add 1)
//
// Input:
// Name: binaryRepresentation
// Type: char
// Description: the binary representation to be manipulated as a character
// array
//
// Name: length
// Type: unsigned int
// Description: the length of the binary representation
void ConvertToTwosComplement( char binaryRepresentation[], unsigned int length )
{
   ConvertToOnesComplement( binaryRepresentation, length );
   //printf( "Printing after converting to One's Complement:\n" );
   //printArray( binaryRepresentation, length );
   //printf ( "\n" );
   AddOneToOnesComplement( binaryRepresentation, length );
}

void ConvertToBinary( char binaryRepresentation[], int numToConvert, unsigned int sizeOfBinRep )
{
   int x, placeValue;

   //printf( "num to convert: %d\n", numToConvert % 2 );

   // convert values right to left 
   for( int x = sizeOfBinRep; x > 0; x-- )
   {
      placeValue = numToConvert % 2 ? 1 : 0; 
      numToConvert /= 2;

      binaryRepresentation[x - 1] = placeValue + BASE_CHAR;
   }
}

void ConvertAndPrint( int num )
{
   char binaryRepresentation[MAX_BIN_SIZE];
   unsigned int length = sizeof( binaryRepresentation ) / sizeof( binaryRepresentation[0] );

   ConvertToBinary( binaryRepresentation, num, length );
   //printf( "Printing after converting to binary:\n" );
   //printArray( binaryRepresentation, length );
   //printf( "\n" );
   ConvertToTwosComplement( binaryRepresentation, length );


   printArray( binaryRepresentation, length );
   //printf( "\n" );
}

int main( int argc, char **argv )
{
   int num = 0;

   num = strtol( argv[1], NULL, MAX_INPUT_LENGTH ); 

   //printf( "%d\n", num );

   ConvertAndPrint( num );

   return 0;
}
