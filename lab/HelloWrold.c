#include "../include/pipex.h"

int main(int argc, char **argv)
{
    // printf ("%d\n", getpid());
    // int a = 1;
    // char *str = malloc(100);
    // while(1)
    // {
    //     scanf("%d", &a);
    //     if (a == 2)
    //         exit(1);
    // }
    /*int a = 1;
    printf("Hello Wrold!\n");
    while (1)
    {
        scanf ("%d", &a);
        if (a == 3)
            break ;
    }
	*/
	if (argc != 2)
	{
		write(2, "error", 5);  
		perror("NOT form input line");
		exit(2);
	}
	int fd = open(argv[1], O_RDONLY);
	int a = 0;
	printf("pid == %d\n", getpid());
	while(1)
	{
		printf("if you want break put 1");
		scanf("%d", &a);
		if (a == 1)
			break;
	}
	close(a);
	close(2);
	int b = 0;
	while(1)
	{
		printf("if you want break put 1");
		scanf("%d", &b);
		if (b == 1)
			break;
	}
    return (1);
}
