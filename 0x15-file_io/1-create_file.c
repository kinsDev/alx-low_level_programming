/*
 * File: modified_create_file.c
 * Author: Your Name
 * Description: A modified version of create_file function to create a file and write content.
 * Original source: [Provide original source if applicable]
 */

#include "main.h"

/**
 * create_file - Creates a file and writes content to it.
 * @filename: The name of the file to create.
 * @text_content: The content to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */

int create_file(const char *filename, char *text_content)
{
	int file_descriptor, bytes_written, content_length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (content_length = 0; text_content[content_length]; content_length++);
	}

	file_descriptor = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	bytes_written = write(file_descriptor, text_content, content_length);

	if (file_descriptor == -1 || bytes_written == -1)
		return (-1);

	close(file_descriptor);

	return (1);
}
