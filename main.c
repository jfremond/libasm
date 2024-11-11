#include "libasm.h"

int main()
{
	printf(LIME "-------------------- STRLEN --------------------" RESET_ENDL);
	const char	*str;

	printf(CYAN "-------------------- EMPTY STRING --------------------" RESET_ENDL);
	str = "";
	test_strlen("strlen", strlen, str);
	test_strlen("ft_strlen", ft_strlen, str);
	write(1, "\n", 1);

	printf(CYAN "-------------------- SHORT STRING --------------------" RESET_ENDL);
	str = "Lorem ipsum dolor sit amet, consectetur tincidunt.";
	test_strlen("strlen", strlen, str);
	test_strlen("ft_strlen", ft_strlen, str);
	write(1, "\n", 1);

	printf(CYAN "-------------------- LONG STRING --------------------" RESET_ENDL);
	str = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Phasellus cursus libero augue, a malesuada orci semper a. Nulla in fermentum ligula, vitae dictum mi. Mauris bibendum vestibulum ultrices. Nunc finibus faucibus magna, id tincidunt nunc pellentesque eu. Nulla ac ante tempus, ultrices urna eu, porttitor est. Ut in ipsum scelerisque, tristique erat vel, faucibus justo. Praesent non aliquet dolor, a dignissim leo. Sed euismod gravida erat, vel maximus diam. Pellentesque in nisi in lorem ornare laoreet.\nSuspendisse nec purus orci. Sed hendrerit vehicula tellus, ac tristique dui tristique in. Fusce eleifend a augue sit amet cursus. Curabitur in felis blandit, tempor erat vel, dapibus lectus. Phasellus ornare bibendum massa nec auctor. Nunc vulputate orci nec sem dignissim, at placerat nisi dapibus. Aenean odio felis, egestas in erat a, mollis convallis ipsum. Mauris augue libero, lacinia non dui eu, sodales convallis mi. Quisque a enim felis. Integer blandit est ac sapien orci aliquam.";
	test_strlen("strlen", strlen, str);
	test_strlen("ft_strlen", ft_strlen, str);
	write(1, "\n", 1);

	printf(LIME "-------------------- STRCPY --------------------" RESET_ENDL);
	char		dest[500];
	const char	*src;

	printf(CYAN "-------------------- EMPTY STRING --------------------" RESET_ENDL);
	src = "";
	test_strcpy("strcpy", strcpy, dest, src);
	test_strcpy("ft_strcpy", ft_strcpy, dest, src);
	write(1, "\n", 1);

	printf(CYAN "-------------------- SHORT STRING --------------------" RESET_ENDL);
	src = "Lorem ipsum dolor sit amet, consectetur tincidunt.";
	test_strcpy("strcpy", strcpy, dest, src);
	test_strcpy("ft_strcpy", ft_strcpy, dest, src);
	write(1, "\n", 1);

	printf(CYAN "-------------------- LONG STRING --------------------" RESET_ENDL);
	src = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vestibulum volutpat nunc lacus, et placerat tellus posuere luctus. Nulla efficitur quam id turpis pellentesque, a dignissim velit venenatis. Aliquam et mauris dui. Sed congue accumsan enim, non tristique quam gravida at. Etiam at turpis eget lorem convallis mattis. Integer eu mollis massa. Praesent auctor feugiat tortor, ac rhoncus nulla placerat pharetra. Nulla semper ullamcorper ante, id elementum mauris. Curabitur tempor elit non justo.";
	test_strcpy("strcpy", strcpy, dest, src);
	test_strcpy("ft_strcpy", ft_strcpy, dest, src);
	write(1, "\n", 1);

	printf(LIME "-------------------- STRCMP --------------------" RESET_ENDL);
	const char	*s1;
	const char	*s2;

	printf(CYAN "-------------------- S1 == S2 --------------------" RESET_ENDL);
	s1 = "hello";
	s2 = "hello";
	test_strcmp("strcmp", strcmp, s1, s2);
	test_strcmp("ft_strcmp", ft_strcmp, s1, s2);
	write(1, "\n", 1);

	printf(CYAN "-------------------- S1 < S2 --------------------" RESET_ENDL);
	s1 = "hello";
	s2 = "motorist";
	test_strcmp("strcmp", strcmp, s1, s2);
	test_strcmp("ft_strcmp", ft_strcmp, s1, s2);
	write(1, "\n", 1);

	printf(CYAN "-------------------- S1 > S2 --------------------" RESET_ENDL);
	s1 = "organise";
	s2 = "hello";
	test_strcmp("strcmp", strcmp, s1, s2);
	test_strcmp("ft_strcmp", ft_strcmp, s1, s2);
	write(1, "\n", 1);

	printf(LIME "-------------------- WRITE --------------------" RESET_ENDL);
	int		write_fd;
	int		ft_write_fd;
	void	*buf;
	size_t	count;

	printf(CYAN "-------------------- INVALID FD --------------------" RESET_ENDL);
	write_fd = -1;
	ft_write_fd = -1;
	buf = PINK "hello\n" RESET;
	count = strlen(buf);
	test_write("write", write, write_fd, buf, count);
	test_write("ft_write", ft_write, ft_write_fd, buf, count);
	write(1, "\n", 1);

	printf(CYAN "-------------------- STANDARD OUTPUT --------------------" RESET_ENDL);
	write_fd = 1;
	ft_write_fd = 1;
	buf = "hello\n";
	count = strlen(buf);
	test_write("write", write, write_fd, buf, count);
	test_write("ft_write", ft_write, ft_write_fd, buf, count);
	write(1, "\n", 1);

	printf(CYAN "-------------------- EMPTY STRING --------------------" RESET_ENDL);
	write_fd = open("write.txt", O_WRONLY | O_CREAT, 0664);
	ft_write_fd = open("ft_write.txt", O_WRONLY | O_CREAT, 0664);
	buf = "";
	count = strlen(buf);
	test_write("write", write, write_fd, buf, count);
	test_write("ft_write", ft_write, ft_write_fd, buf, count);
	write(1, "\n", 1);

	printf(CYAN "-------------------- SMALL STRING --------------------" RESET_ENDL);
	write_fd = open("write.txt", O_WRONLY | O_CREAT, 0664);
	ft_write_fd = open("ft_write.txt", O_WRONLY | O_CREAT, 0664);
	buf = "Nam pellentesque, ligula non maximus efficitur, tellus nulla semper mi, eu vulputate metus nulla sit.\n";
	count = strlen(buf);
	test_write("write", write, write_fd, buf, count);
	test_write("ft_write", ft_write, ft_write_fd, buf, count);
	write(1, "\n", 1);

	printf(CYAN "------------- LONG STRING ------------\n" RESET);
	write_fd = open("write.txt", O_WRONLY | O_APPEND, 0664);
	ft_write_fd = open("ft_write.txt", O_WRONLY | O_APPEND, 0664);
	buf = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.\nNulla sodales felis justo, dapibus vestibulum eros lobortis at.\nSed et risus mi. Proin ac finibus enim.\nSed interdum tortor elit, pulvinar rutrum ligula tristique sit amet.\nMaecenas dictum mauris in aliquet dapibus.\nDonec imperdiet mi vel mi molestie, nec pretium quam varius.\nNulla id hendrerit ex. Quisque mattis diam lacus, in lacinia erat vestibulum ut.\nSuspendisse potenti. Etiam id cursus risus.\nDuis nec cursus turpis, vel rutrum neque.\nPraesent fringilla, justo at gravida congue, risus lectus ultricies sem, nec pharetra magna turpis vitae nibh.\nUt eget tellus ut lacus luctus elementum. Etiam consectetur lobortis ex.\nMauris scelerisque, eros vel porta suscipit, orci ante rhoncus arcu, nec malesuada ex quam a felis.\nSed tristique nisi nulla, ut placerat mauris ornare nec.\nEtiam sagittis posuere nulla, nec vulputate ex.\nDonec at viverra libero. Curabitur sed odio sit amet neque accumsan ullamcorper.\n";
	count = strlen(buf);
	test_write("write", write, write_fd, buf, count);
	test_write("ft_write", ft_write, ft_write_fd, buf, count);
	write(1, "\n", 1);

	printf(LIME "-------------------- READ --------------------" RESET_ENDL);
	char	empty_buffer[0];
	char	small_buffer[10];
	char	big_buffer[1000];
	int		read_fd;
	int		ft_read_fd;
	printf(CYAN "-------------------- INVALID FD --------------------" RESET_ENDL);
	read_fd = -1;
	ft_read_fd = -1;
	test_read("read", read, read_fd, small_buffer, sizeof(small_buffer));
	test_read("ft_read", ft_read, ft_read_fd, small_buffer, sizeof(small_buffer));
	write(1, "\n", 1);

	printf(CYAN "-------------------- STANDARD INPUT --------------------" RESET_ENDL);
	read_fd = 0;
	ft_read_fd = 0;
	test_read("read", read, read_fd, small_buffer, sizeof(small_buffer));
	write(1, "\n", 1);
	test_read("ft_read", ft_read, ft_read_fd, small_buffer, sizeof(small_buffer));
	write(1, "\n", 1);

	printf(CYAN "-------------------- EMPTY BUFFER --------------------" RESET_ENDL);
	read_fd = open("write.txt", O_RDONLY, 0664);
	ft_read_fd = open("ft_write.txt", O_RDONLY, 0664);
	test_read("read", read, read_fd, empty_buffer, sizeof(empty_buffer));
	test_read("ft_read", ft_read, ft_read_fd, empty_buffer, sizeof(empty_buffer));
	write(1, "\n", 1);

	printf(CYAN "-------------------- SMALL BUFFER --------------------" RESET_ENDL);
	read_fd = open("write.txt", O_RDONLY, 0664);
	ft_read_fd = open("ft_write.txt", O_RDONLY, 0664);
	test_read("read", read, read_fd, small_buffer, sizeof(small_buffer));
	test_read("ft_read", ft_read, ft_read_fd, small_buffer, sizeof(small_buffer));
	write(1, "\n", 1);
	
	printf(CYAN "-------------------- BIG BUFFER --------------------" RESET_ENDL);
	read_fd = open("write.txt", O_RDONLY, 0664);
	ft_read_fd = open("ft_write.txt", O_RDONLY, 0664);
	test_read("read", read, read_fd, big_buffer, sizeof(big_buffer));
	test_read("ft_read", ft_read, ft_read_fd, big_buffer, sizeof(big_buffer));
	write(1, "\n", 1);

	printf(LIME "-------------------- STRDUP --------------------" RESET_ENDL);
	const char	*s;

	printf(CYAN "-------------------- EMPTY STRING --------------------" RESET_ENDL);
	s = "";
	test_strdup("strdup", strdup, s);
	test_strdup("ft_strdup", ft_strdup, s);
	write(1, "\n", 1);

	printf(CYAN "-------------------- SMALL STRING --------------------" RESET_ENDL);
	s = "hello";
	test_strdup("strdup", strdup, s);
	test_strdup("ft_strdup", ft_strdup, s);
	write(1, "\n", 1);

	printf(CYAN "-------------------- LONG STRING --------------------" RESET_ENDL);
	s = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Mauris scelerisque nisl at ligula elementum efficitur. Proin eget rutrum diam. Maecenas malesuada purus quam. Nulla magna augue, accumsan id porta vel, finibus eget lorem. Nullam rhoncus ante eget lobortis ornare. Aliquam congue enim eu ipsum consequat malesuada. Donec consectetur, ante eu.";
	test_strdup("strdup", strdup, s);
	test_strdup("ft_strdup", ft_strdup, s);
	write(1, "\n", 1);

	return (0);
}
