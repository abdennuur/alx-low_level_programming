#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Read text file and print it to POSIX stdout
 * @filename: ptr to the name of file.
 * @letters: nbr of letters the
 *  function should read and print
 *
 * Return: If the function fails or filename is NULL - 0
 * O/w - the actual nbr of bytes the function can read and print
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	 ssize_t op, rd, wr;
	char *buffer;

	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer ==  NULL)
		return (0);

	op = open(filename, O_RDONLY);
	rd = read(op, buffer, letters);
	wr = write(STDOUT_FILENO, buffer, rd);

	if (op == -1 || rd == -1 || wr == -1 || wr != rd)
	{
		free(buffer);
		return (0);
	}

	free(buffer);
	close(op);

	return (wr);

}
