/*
 ============================================================================
 Name        : hw1.c
 Author      : Ashton Mendes
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Custom header files.
#include "hex.h"
#include "base64.h"

int main(int argc, char*argv[])
{
	//argv[0] is always the filename. Actual arguments begin from argv[1] onwards. Hence argc-1.
	int numOfArgs = argc - 1;

	//Checking the number of arguments provided.
	if(numOfArgs <= 0)
	{
		fprintf(stderr, "Please enter commandline arguments. The syntax is as follows: \n ./hw1 hexdump [file] \n ./hw1 enc-base64 [file] \n ./hw1 dec-base64 [file]\n");
		return EXIT_FAILURE;
	}
	else if(numOfArgs > 2)
	{
		fprintf(stderr, "Too many commandline arguments. The syntax is as follows: \n ./hw1 hexdump [file] \n ./hw1 enc-base64 [file] \n ./hw1 dec-base64 [file]\n");
		return EXIT_FAILURE;
	}

	//Checking which command is being invoked.
	if(strcmp(argv[1],"hexdump")==0)
	{
		hexdump(argv[2]);
	}
	else if(strcmp(argv[1], "enc-base64")==0)
	{
		encodeToBase64(argv[2]);
	}
	else if(strcmp(argv[1], "dec-base64")==0)
	{
		decodeFromBase64(argv[2]);
	}
	else //Incorrect syntax.
	{
		fprintf(stderr, "Please check the arguments provided. The correct syntax is as follows: \n ./hw1 hexdump [file] \n ./hw1 enc-base64 [file] \n ./hw1 dec-base64 [file]\n");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}


