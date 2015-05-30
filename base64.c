/*
 * base64.c
 *
 *  Created on: Jan 15, 2015
 *      Author: ashton
 */

#include<stdio.h>
#include "hex.h"

//Holds the base64 table into a character array.
char base64Table[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
					   'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
					   'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
					   'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
					   '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',  '+', '/'};

#define INVALID_BASE64_CHARACTER 65

void encodeBuffer(int bytesRead, unsigned char buffer[], unsigned int *totalCharsPrinted)
{
	unsigned char sixBitChars[4];
	unsigned char base64Output[4]; //from base64 table

	//Fill empty space in buffer with 0s
	int i=0;
	for(i=bytesRead; i<3; i++)
	{
		buffer[i] = 0;
	}

	//Split 3 8-bit characters into 4 6-bit characters
	sixBitChars[0] = (buffer[0]&252)>>2;
	sixBitChars[1] = ((buffer[0]&3)<<4)|((buffer[1]&240)>>4);
	sixBitChars[2] = ((buffer[1]&15)<<2)|((buffer[2]&192)>>6);
	sixBitChars[3] = buffer[2]&63;

	//Get hold of Base64 equivalents
	int index = 0;
	for(i=0; i<4; i++)
	{
		index = sixBitChars[i];
		base64Output[i] = base64Table[index];
	}

	//Fill empty space in buffer with 0s
	for(i=bytesRead+1; i<4; i++)
	{
		base64Output[i] = '=';
	}

	//Print base64 equivalent characters
	for(i=0; i<4; i++)
	{
		printf("%c", base64Output[i]);

		if(++(*totalCharsPrinted)%64==0)
			printf("\n"); //leave a line after 64 characters have been printed.
	}
}

unsigned char findInArray(unsigned char base64Char) //Finds a value from the base64 table
{
	if(base64Char == '=')
		return 0;

	unsigned char index = 0;
	for(index=0; index<64; index++)
	{
		if(base64Table[index] == base64Char) //found the character in the base64 table.
			return index;
	}

	//If the character was not found in the base64 table.
	return INVALID_BASE64_CHARACTER;
}

int decodeBuffer(unsigned char buffer[]) //return 1 if decode successful, 2 if '=' sign encountered else return 0
{
	int start = 0, end = 3, lastBitIndex = 3, current = 0;
	unsigned char sixBitChars[4];
	unsigned char decodedOutput[3];

	while(end<=lastBitIndex) //process 4 bytes at a time
	{
		int i=0, decimalValue = INVALID_BASE64_CHARACTER;
		for(current = start; current<=end; current++)
		{
			//Find the decimal values from ASCII values using the Base64 table
			decimalValue = findInArray(buffer[current]);
			if(decimalValue == INVALID_BASE64_CHARACTER)
				return 0;
			else
				sixBitChars[i++] = decimalValue;
		}

		//Get back the 3 bytes from the 4 6-bit numbers
		decodedOutput[0] = (sixBitChars[0]<<2)|(sixBitChars[1]>>4);
		decodedOutput[1] = (sixBitChars[1]<<4)|(sixBitChars[2]>>2);
		decodedOutput[2] = (sixBitChars[2]<<6)|(sixBitChars[3]);

		i=0;
		for(i=0; i<3; i++)
			if(buffer[i+1]!='=')
			{
				printf("%c", decodedOutput[i]);
			}
			else
			{
				return 2; //To signal to the caller that the file can no further be decoded.
			}

		start = current;
		end += 4;
	}

	return 1;
}


void readFromInputAndEncode(FILE* file)
{
	unsigned char buffer[3];
	unsigned int totalCharsPrinted = 0;

	int bytesRead = 0;
	do
	{
		bytesRead = fread(buffer, sizeof(char), 3, file); //read 3 bytes at a time

		if(bytesRead == 0)
			break;

		encodeBuffer(bytesRead, buffer, &totalCharsPrinted);
	}
	while(bytesRead == 3);
	printf("\n");
}

void readFromInputAndDecode(FILE* file)
{
	unsigned char buffer[4];
	unsigned int bytesRead = 0;
	unsigned char character = '\n';
	unsigned int index = 0;

	do
	{
		bytesRead = fread(&character, sizeof(char), 1, file); //read 1 character at a time

		if(bytesRead == 0)
			break;

		if(character == '\n') //ignore newline characters in the base64 encoded file
			continue;
		else
		{
			buffer[index] = character; //add character to buffer
			index += 1;
		}

		if(index == 4) //process 4 characters at a time
		{
			index = 0;

			int wasSuccessful = decodeBuffer(buffer);

			if(wasSuccessful == 0) //0 means decode was not successful
			{
				fprintf(stderr, "*Unable to decode the file.*\n");
				break;
			}
			if(wasSuccessful == 2) //1 means '=' was encountered while trying to decode the data that means the file has reached the end.
			{
				break;
			}
		}
	}
	while(bytesRead == 1);

	if(index!=0)
	{
		fprintf(stderr, "\n*The number of bytes in the file is not a multiple of 4. Hence it is not a valid base64 format. No further decoding can be done.*\n");
	}
}

void encodeToBase64(char filename[])
{
	if(!filename)
	{
		readFromInputAndEncode(stdin);
	}
	else
	{
		FILE *file;
		file = fopen(filename, "rb"); //read in binary mode.

		if(file==NULL)
		{
			fprintf(stderr, "Unable to open the file specified. Please check the filename.\n");
		}
		else
		{
			readFromInputAndEncode(file);
			fclose(file);
		}
	}
}

void decodeFromBase64(char filename[])
{
	if(!filename)
	{
		readFromInputAndDecode(stdin);
	}
	else
	{
		FILE *file;
		file = fopen(filename, "rb");

		if(file==NULL)
		{
			fprintf(stderr, "Unable to open the file specified. Please check the filename.\n");
		}
		else
		{
			readFromInputAndDecode(file);
			fclose(file);
		}
	}
}
