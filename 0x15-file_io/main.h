#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

ssize_t read_textfile(const char *filename, size_t letters);
int _putchar(char c);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
int openSourceFile(const char *filename);
int openDestinationFile(const char *filename);
int copyFile(int source_fd, int dest_fd);
void closeFiles(int source_fd, int dest_fd);

#endif
