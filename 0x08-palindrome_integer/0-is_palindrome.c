#include "palindrome.h"

/**
*is_palindrome - checks unsigned long int for integer
*@n: This the int that is checked
*Return: 0 if not a palindrome and 1 if is a palindrome
*/
int is_palindrome(unsigned long n)
{
	int rem;
	int reversed = 0;
	int original;

	original = n;

	while (n != 0)
	{
		rem = n % 10;
		reversed = reversed * 10 + rem;
		n /= 10;
	}

	if (original == reversed)
		return (1);

	else
		return (0);
}
