#include"main.h"

/**
 *append_text_to_file - append txt in the end of file
 *@filename: a ptr to the name of file
 *@text_content: str to add to the end of the file
 *
 *Return: If the function fail or filename is NULL -> -1
 *	  if the file does not exist the user lacks write permissions -> -1
 *	  otherwise -> 1
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int op, wr, lent = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (lent = 0; text_content[lent];)
			lent++;
	}

	op = open(filename, O_WRONLY | O_APPEND);
	wr = write(op, text_content, lent);

	if (op == -1 || wr == -1)
		return (-1);

	close(op);

	return (1);
}
