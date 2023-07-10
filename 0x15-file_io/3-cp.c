#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * check_arguments - checks for the correct number of arguments
 * @argc: number of arguments
 *
 * Return: void
 */
void check_arguments(int argc)
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
}

/**
 * check_read - checks if file_from can be read
 * @check: check if true or false
 * @file: file_from name
 * @fd_from: file descriptor of file_from, or -1
 *
 * Return: void
 */
void check_read(ssize_t check, char *file, int fd_from)
{
	if (check == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
		if (fd_from != -1)
			close(fd_from);
		exit(98);
	}
}

/**
 * check_write - checks if file_to can be written
 * @check: check if true or false
 * @file: file_to name
 * @fd_to: file descriptor of file_to, or -1
 *
 * Return: void
 */
void check_write(ssize_t check, char *file, int fd_to)
{
	if (check == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		if (fd_to != -1)
			close(fd_to);
		exit(99);
	}
}

/**
 * check_close - checks if file descriptor was closed properly
 * @check: check if true or false
 * @fd: file descriptor
 *
 * Return: void
 */
void check_close(int check, int fd)
{
	if (check == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - copies the content of a file to another file.
 * @argc: number of arguments passed
 * @argv: array of pointers to the arguments
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to, close_to, close_from;
	ssize_t lenr, lenw;
	char buffer[1024];
	mode_t file_perm = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

	check_arguments(argc);

	// Open file_from for reading
	fd_from = open(argv[1], O_RDONLY);
	check_read((ssize_t)fd_from, argv[1], -1);

	// Create and open file_to for writing
	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, file_perm);
	check_write((ssize_t)fd_to, argv[2], fd_from);

	lenr = 1024;
	while (lenr == 1024)
	{
		// Read from file_from
		lenr = read(fd_from, buffer, 1024);
		check_read(lenr, argv[1], fd_from);

		// Write to file_to
		lenw = write(fd_to, buffer, lenr);
		if (lenw != lenr)
			lenw = -1;
		check_write(lenw, argv[2], fd_to);
	}

	// Close file descriptors
	close_to = close(fd_to);
	close_from = close(fd_from);
	check_close(close_to, fd_to);
	check_close(close_from, fd_from);

	return (0);
}
