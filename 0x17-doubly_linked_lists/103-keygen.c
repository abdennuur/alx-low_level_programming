#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * main - generate key depends on username for crackme5
 * @argc: nbr of args passed
 * @argv: args passed to main
 *
 * Return: 0 -> success, 1 -> error
 */
int main(int argc, char *argv[])
{
	unsigned int ix, bi;
	size_t ln, ad;
	char *l = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	char p[7] = "      ";

	if (argc != 2)
	{
		printf("Correct usage: ./keygen5 username\n");
		return (1);
	}
	ln = strlen(argv[1]);
	p[0] = l[(ln ^ 59) & 63];
	for (ix = 0, ad = 0; ix < ln; ix++)
		ad += argv[1][ix];
	p[1] = l[(ad ^ 79) & 63];
	for (ix = 0, bi = 1; ix < ln; ix++)
		bi *= argv[1][ix];
	p[2] = l[(bi ^ 85) & 63];
	for (bi = argv[1][0], ix = 0; ix < ln; ix++)
		if ((char)bi <= argv[1][ix])
			bi = argv[1][ix];
	srand(bi ^ 14);
	p[3] = l[rand() & 63];
	for (bi = 0, ix = 0; ix < ln; ix++)
		bi += argv[1][ix] * argv[1][ix];
	p[4] = l[(bi ^ 239) & 63];
	for (bi = 0, ix = 0; (char)ix < argv[1][0]; ix++)
		bi = rand();
	p[5] = l[(bi ^ 229) & 63];
	printf("%s\n", p);
	return (0);
}
