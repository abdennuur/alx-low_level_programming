#include "main.h"
/**
 * create_file - create array of chars and initializes.
 *
 * @text_content: is a NULL terminated str to write to file
 * @filename: is the name of file to create
 *
 * Return: 1 -> success, -1 -> fail
 */
int create_file(const char *filename, char *text_content)
{
	int op, wr, lent = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (lent = 0; text_content[lent];)
			lent++;
	}

	op = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	wr = write(op, text_content, lent);

	if (op == -1 || wr == -1)
		return (-1);

	close(op);

	return (1);
}
