#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define RED			"\033[38;2;255;0;0m"
#define GREEN		"\033[38;2;0;255;0m"
#define BLUE		"\033[38;2;0;0;255m"
#define YELLOW		"\033[38;2;255;255;0m"
#define CYAN		"\033[38;2;0;255;255m"
#define MAGENTA		"\033[38;2;255;0;255m"
#define ORANGE		"\033[38;2;255;165;0m"
#define PINK		"\033[38;2;255;105;180m"
#define LIME		"\033[38;2;191;255;50m"
#define PURPLE		"\033[38;2;138;43;226m"
#define RESET		"\033[0m"
#define RESET_ENDL	"\033[0m\n"

typedef size_t	(*strlen_ptr)(const char *str);
typedef char *	(*strcpy_ptr)(char *dest, const char *src);
typedef int		(*strcmp_ptr)(const char *s1, const char *s2);
typedef ssize_t	(*write_ptr)(int fd, const void *buf, size_t count);
typedef ssize_t	(*read_ptr)(int fd, void *buf, size_t count);
typedef char *	(*strdup_ptr)(const char *s);

void	test_strlen(char *function_name, strlen_ptr f, const char *str);
void	test_strcpy(char *function_name, strcpy_ptr f, char *dest, const char *src);
void	test_strcmp(char *function_name, strcmp_ptr f, const char *s1, const char *s2);
void	test_write(char *function_name, write_ptr f, int fd, const void *buf, size_t count);
void	test_read(char *function_name, read_ptr f, int fd, void *buf, size_t count);
void	test_strdup(char *function_name, strdup_ptr f, const char *s);

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dest, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fd, const void *buf, size_t count);
ssize_t	ft_read(int fd, void *buf, size_t count);
char	*ft_strdup(const char *s);
