#include "holberton.h"


/**
 * main - This is the main driver of program that handls argv 
 * return: 0
 */
int main(int argc, char **argv)
{
    int len1 = 0, len2 = 0;
    int *buffer, res;
    if(argc != 3 || checkIfNum(argv[1]) == -1 || checkIfNum(argv[2]) == -1) 
        Errorhandle(98);
    /*find the lenght of both strings if they are valid */
    len1 = getLen(argv[1]);
    len2 = getLen(argv[2]);

    buffer = myCalloc(len1 + len2, sizeof(int)); 
    printf("%d\n", *buffer);

    res = multiply(len1, len2, buffer, argv[1], argv[2]);
    /* calloc buffer with 0*/
    if(res == -1)
      Errorhandle(98);
    free(buffer);
}

/**
 * Errorhandle - This handles Error printing as well as exit status 98
 * @status: This is status code 98
 * 
 */
void Errorhandle(int status)
{
    int i = 0;
    char *err = "Error\n";
    while (err[i] != '\0')
    {
        _putchar(err[i]);
        i++;
    }
    exit(status);
}

/**
 * checkIfNum - This checks to see if number passed is all nums
 * 
 * @num: This is string rep of integer 
 * @return int 
 */
int checkIfNum(char *num)
{
    int len = getLen(num);

    for(int itr = 0; itr < len; itr++)
    {
        /*So soemthing*/
        if (num[itr] > '9' || num[itr] < '0')
        {
            return (-1);
        }

    }
    return (1);
}

/**
 * getlen - This gets the length of string 
 * @num: This is number in string format
 * 
 * @return -1 for failure 0 for success
 */
int getLen(char *num)
{
    int count = 0;
    
    for(int i = 0; num[i] != '\0'; i++, count++)
    {}
    return (count);
}

/**
 * myCalloc
 * 
 * @param nitems 
 * @param size 
 * @return char* 
 */
int *myCalloc(int nitems, int size)
{
 /*develop and initilize buffer to 0*/
 int *buff;

 if (!nitems || !size )
 {
     Errorhandle(98);
 }
 
 buff = malloc(sizeof(nitems * size));

 if (!buff)
 {
     Errorhandle(98);
 }
 for(int i = 0; i < nitems; i++)
 {
     buff[i] = 0;
 }
  return (buff);
}
/**
 * @brief 
 * 
 * @len1 
 * @len2 
 * @buff 
 * @return int 
 */
int multiply(int len1, int len2, int *buff, char *num1, char *num2 )
{
  int sum = 0, carry = 0, i, j, itr;

  /*Loop through len1 of str1 and str2 in a double forloop*/
  for(i = len1 - 1; i >= 0; i--)
  {
    int n1 = num1[i] - '0';

    for(j = len2 - 1; j >= 0; j--)
    {
      int n2 = num2[j] - '0';

      sum = n1 * n2 + buff[i + j - 1];

      carry = sum / 10;
      buff[i + j] = sum % 10;
    }
    if (carry > 0)
    {
      buff[i + j] = carry;
    }

  }
  while(buff[itr] != '\0')
  {
    if(buff[itr] == 0)
    {
      itr++;
    }
    else
    {
      _putchar(buff[itr] - '0');
    }
    itr++;
  }

  return (0);
}
