#include "../include/pipex.h"

int main(int argc, char **argv, char **envp)
{
    int a = 1;
    int b = 1;
    char *const arr[] = { "ls", "-l", NULL};
    char *const brr[] = { "free", "-g", NULL};
    char *Hello = malloc(100);
    if ((a = execve("/bin", arr, envp)) == -1) {
        ft_printf("execve return is == %d\n", a);
        b = execve("/bin", arr, envp);
        ft_printf("execve return is == %d\n", b);
        execve("/bin/ls", arr, envp);
        execve("/bin/free", brr, envp);
		perror("execve");
		return 1;
	}

    ft_printf("execve return is == %d\n", a);
}

/*이걸 실행해보면 알수 있는 내용은 execve함수는 실패를 하면 프로세스를 대체하지 않는다
하지만 execve함수가 옳바르게 실행이 된다면 원래가지고 있는 프로세스의 내용들은 대체가 된다.*/
//자식 프로세스는 부모 프로세스의 file descriptor의 복사본을 가집니다. 부모와 자식 프로세스의 file descriptor는 같은 파일을 가리킵니다.