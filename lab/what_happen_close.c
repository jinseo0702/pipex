#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	(void)argc;
	int fd = open(argv[1], O_RDONLY);
	printf("not close fd is %d\n", fd);
	close(fd);
	printf("close fd is %d\n", fd);
	return (0);
}
