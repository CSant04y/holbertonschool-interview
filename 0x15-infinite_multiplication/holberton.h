#ifndef _HOLBERTON_H
#define _HOLBERTON_H
/* ======= libraries =======*/
#include <stdio.h>
#include <stdlib.h>

/* ======= Prototypes =======*/
int _putchar(char c);
void Errorhandle(int status);
int checkIfNum(char *num);
int getLen(char *num);
int *myCalloc(int nitems, int size);
int multiply(int len1, int len2, int *buff, char *num1, char *num2 );

#endif /*_HOLBERTON_H*/
