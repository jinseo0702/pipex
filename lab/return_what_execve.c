#include "../include/pipex.h"

int main(int argc, char **argv /*char **envp*/)
{
    int a = 1;
    int b = 1;
    // char *const arr[] = { "ls", "-ail", NULL};
    // char *const brr[] = { "free", "-g", NULL};
    char *Hello = malloc(100);
    printf("current pid is : %d\n", getpid());
    int num = 1;
    while(1)
    {
        printf("if you want break put 1\n");
        scanf("%d", &num);
        if (num == 1)
            break ;
    }
    char *arr[]   = { "./Hello", NULL};
    char *envp[]   = {"~/Desktop/pipex/lab", NULL};
    if ((a = execve("./Hello", arr, envp)) == -1) {
        // ft_printf("execve return is == %d\n", a);
        // b = execve("/bin", arr, envp);
        // ft_printf("execve return is == %d\n", b);
        // execve("/bin/ls", arr, envp);
        // execve("/bin/free", brr, envp);
		perror("execve");
		return 1;
	}

    ft_printf("execve return is == %d\n", a);
    return (1);
}

/*이걸 실행해보면 알수 있는 내용은 execve함수는 실패를 하면 프로세스를 대체하지 않는다
하지만 execve함수가 옳바르게 실행이 된다면 원래가지고 있는 프로세스의 내용들은 대체가 된다.*/
//자식 프로세스는 부모 프로세스의 file descriptor의 복사본을 가집니다. 부모와 자식 프로세스의 file descriptor는 같은 파일을 가리킵니다.
// /proc/pid/staus 에서 execve실행후 달라지는 메모리환경을 볼수 있습니다.