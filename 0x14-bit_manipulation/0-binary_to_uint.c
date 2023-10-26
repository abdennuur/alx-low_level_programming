#include "main.h"
/**
 * binary_to_uint - convert binary to unsigned int
 * @b: binary nbr as string
 *
 * Return: Converted value
 */
unsigned int binary_to_uint(const char *b)
{
unsigned int d = 0;
int st_len = 0, b = 1;

if (!check_valid_string(b))
return (0);

while (b[st_len] != '\0')
st_len++;

while (st_len)
{
d += ((b[st_len - 1] - '0') * b);
b *= 2;
st_len--;
}
return (d);
}

/**
 * check_valid_string - check if string has only 0 and 1
 * @b: str be checked
 *
 * Return: 1 if string valid, 0 otherwise
 */
int check_valid_string(const char *b)
{
if (b == NULL)
return (0);

while (*b)
{
if (*b != '1' && *b != '0')
return (0);
b++;
}
return (1);
}
