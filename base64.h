/*
 * base64.h
 *
 *  Created on: Jan 15, 2015
 *      Author: ashton
 */

#ifndef BASE64_H_
#define BASE64_H_

void encodeToBase64(char[]);
void decodeFromBase64(char[]);
void encodeBuffer(int, unsigned char, unsigned int*);
unsigned char findInArray(unsigned char);
void decodeBuffer(int, unsigned char);
void encodeToBase64(char[]);
void decodeFromBase64(char[]);
void readFromInputAndEncode(FILE*);
void readFromInputAndDecode(FILE*);

#endif /* BASE64_H_ */
