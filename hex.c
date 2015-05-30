/*
 * hex.c
 *
 *  Created on: Jan 15, 2015
 *      Author: ashton
 */

#include<stdio.h>
#include<string.h>

//function prototypes
unsigned char printAsciiValue(unsigned char);
void readFromInputAndProcess(FILE*);

void hexdump(char filename[])
{
	if(!filename) //filename not provided, read from stdin
	{
		readFromInputAndProcess(stdin);
	}
	else
	{
		FILE *file;
		file = fopen(filename, "rb"); //read from file

		if(file==NULL)
		{
			fprintf(stderr, "Unable to open the file specified. Please check the filename.\n");
		}
		else
		{
			readFromInputAndProcess(file);
			fclose(file);
		}
	}
}

void readFromInputAndProcess(FILE* file)
{
	unsigned char buffer[16]; //buffer to read in 16 bytes at a time.
	int bytesRead = 0;
	unsigned int addressCounter = 0;

	do
	{
		bytesRead = fread(buffer, sizeof(char), 16, file); //Read 16 bytes at a time into the buffer.

		if(bytesRead == 0)
			break;

		//Print address
		printf("%06x: ", addressCounter);
		addressCounter = addressCounter + bytesRead; //increment address by 16.

		//Print the 16 bytes
		int i=0;
		for(i=0; i<16; i++)
		{
			if(i<bytesRead)
				printf("%02x ", buffer[i]);
			else
				printf("-- "); //if there are fewer than 16 bytes in a line

			//Extra space AFTER the 8th byte
			if(i==7)
				printf(" ");
		}

		printf(" "); //Extra space after all 16 bytes have been printed.

		//Now to print the ASCII equivalents
		i=0;
		for(i=0; i<16; i++)
		{
			if(i<bytesRead)
				printf("%c", printAsciiValue(buffer[i]));
			else
				printf(" "); //if there are fewer than 16 bytes in a line
		}

		printf("\n");
	}
	while(bytesRead == 16);
}

unsigned char printAsciiValue(unsigned char character) //different printable characters to output.
{
	if(character >= 32 && character <= 126)
		return character;
	if(character <= 31 || character == 127)
		return '.';
	if(character >= 128)
		return '~';
	return ' '; //this condition should never occur
}
