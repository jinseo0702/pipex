#include "../include/pipex.h"

int main()
{
    int fd[2];
    pipe(fd);
    int pid = fork();
    int pid2 = fork();

    if (pid == -1)
    {
        perror("Failed to fork");
        return (-1);
    }
    if (pid == 0)
    {
        //child
        printf("Child pid value: %d \n", pid);
        printf("real Child pid %d \n" , getpid());
        // printf("%d %d\n", fd[0], fd[1]);
        // close(fd[0]);
        // write(fd[1], "fuck you", 5);
        // close(fd[1]);
        // printf("%d %d\n", fd[0], fd[1]);
        // close(fd[1]);
        // char buff[100];
        // read(fd[0], buff, 5);
        // close(fd[0]);
        // printf("%s\n", buff);
        close(fd[1]);
        char buff[100];
        read(fd[0], buff, 10);
        close(fd[0]);
        printf("%s\n", buff);
       sleep(1);
    }
    else
    {
        printf("parents have child pid value: %d \n", pid);
        printf("real parents pid %d \n" , getpid());
        // printf("%d %d\n", fd[0], fd[1]);
    //     close(fd[1]);
    //     char buff[100];
    //     read(fd[0], buff, 10);
    //     close(fd[0]);
    //     printf("%s\n", buff);
    //    sleep(1);
    //    waitpid(pid, 0, 0);
    }
    if (pid2 == -1)
    {
        perror("Failed to fork");
        return (-1);
    }
    if (pid2 == 0)
    {
        //child
        printf("Child pid2 value: %d \n", pid2);
        printf("real Child pid2 %d \n" , getpid());
        // printf("%d %d\n", fd[0], fd[1]);
        close(fd[0]);
        write(fd[1], "Hello World!", 12);
        close(fd[1]);
        sleep(1);
        while(1)
        {}
    }
    else
    {
        printf("parents have child pid2 value: %d \n", pid2);
        printf("real parents pid2 %d \n" , getpid());
        // printf("%d %d\n", fd[0], fd[1]);
        // close(fd[1]);
        // char buff[100];
        // read(fd[0], buff, 5);
        // close(fd[0]);
        // printf("%s\n", buff);
        // while(1)
        {}
    }
    return(0);
}