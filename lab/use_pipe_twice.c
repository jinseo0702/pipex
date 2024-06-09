#include "../include/pipex.h"
#include <string.h>

int main()
{
    int fd[2];

    pipe(fd);
    int pid = fork();
    if (pid == -1)
        perror("Faild fork retry execute program\n");
    if (pid == 0)
    {
        //  close(fd[1]);
        static char arr[1000000];
        printf("child pid == %d\n", getegid());
        read(fd[0], arr, 100);
        printf("child says %s", arr);
        close(fd[0]);
        int read_return = read(fd[0], arr, 10);
        printf("closefd[0] read return value is %d ", read_return);
        // while (1)
        // {}
        // write(fd[1], "Hello World\n", strlen("Hello World\n"));
        exit(0);
    }
    else
    {
        close(fd[0]);
        write(fd[1], "Hello child!!!\n", strlen("Hello child!!!\n"));
        close(fd[1]);
        printf("parents pid == %d\n", getegid());
        // sleep(1);
        waitpid(pid, 0, 0);
        // static char arr2[100];
        // read(fd[0], arr2, 100);
        // printf("parents says %s", arr2);
    }
    return (0);
}