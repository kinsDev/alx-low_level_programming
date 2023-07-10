#include "main.h"

/**
 * _strlen - calculate the length of the string
 * @str: pointyer to the string
 * Return: Lenght of the string
 */

size_t _strlen(const char *str)
{
	size_t len = 0;

	while (str[len])
	{
		len++;
	}
	return len;
}

/**
 * append_text_to_file - Appends text to the end of a file.
 * @filename: Name of the file.
 * @text_content: Text content to add at the end of the file.
 *
 * Return: 1 on success, -1 on failure.
 */

int append_text_to_file(const char *filename, const char *text_content)
{
	int fd;
	ssize_t len;

	if (filename == NULL)
		return -1;

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return -1;

	if (text_content != NULL)
	{
		len = write(fd, text_content, _strlen(text_content));
		if (len == -1)
		{
			close(fd);
			return -1;
		}
	}

	close(fd);
	return 1;
}
