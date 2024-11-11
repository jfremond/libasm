#include "libasm.h"

void	test_strlen(char *function_name, strlen_ptr f, const char *str)
{
	size_t	len = f(str);
	printf("Length of '%s' using" ORANGE " %s " RESET "is %zu.\n", str, function_name, len);
}

void	test_strcpy(char *function_name, strcpy_ptr f, char *dest, const char *src)
{
	dest = f(dest, src);
	printf("Using" ORANGE " %s " RESET "dest = '%s', src = '%s'\n", function_name, dest, src);
}

void	test_strcmp(char *function_name, strcmp_ptr f, const char *s1, const char *s2)
{
	int		res = f(s1, s2);
	printf("Using" ORANGE " %s " RESET "s1 = '%s', s2 = '%s', res = '%d'\n", function_name, s1, s2, res);
}

void	test_write(char *function_name, write_ptr f, int fd, const void *buf, size_t count)
{
	errno = 0;
	ssize_t	ret = f(fd, buf, count);
	printf("Value of errno set by " ORANGE "%s" RESET ": " "%d\n", function_name, errno);
	if (ret < 0)
		printf(RED "Error:" RESET " Invalid parameter given\n");
	else
		printf("Number of bytes written by " ORANGE "%s" RESET ": '%ld'\n", function_name, ret);
	if (fd > 1)
		close(fd);
}

void	test_read(char *function_name, read_ptr f, int fd, void *buf, size_t count)
{
	errno = 0;
	char	*tmp = buf;
	ssize_t	tmp_size = 0;
	ssize_t	ret;
	while ((ret = f(fd, tmp, count)) > 0)
	{
		tmp_size += ret;
		tmp[ret] = '\0';
		if (fd == 0)
			printf("%zd bytes read using" ORANGE " %s" RESET ": %s\n", ret, function_name, tmp);
	}
	if (ret < 0)
		printf(RED "Error:" RESET " Invalid parameter given\n");
	printf("Value of errno set by " ORANGE "%s" RESET ": " "%d\n", function_name, errno);
	printf("Number of bytes read by" ORANGE " %s" RESET ": %ld\n", function_name, tmp_size);
	if (fd > 1)
		close(fd);
}

void	test_strdup(char *function_name, strdup_ptr f, const char *s)
{
	char	*res = f(s);
	if (res)
	{
		printf("Using" ORANGE " %s" RESET ", res = '%s' and length of res = %ld\n", function_name, res, strlen(res));
		free(res);
	}
	else
		printf("Malloc failed.\n");
}
