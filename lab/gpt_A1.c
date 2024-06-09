#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    pid_t pid;
    char buffer[100];

    // 파이프 생성
    if (pipe(fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // 프로세스 분기
    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { // 자식 프로세스
        // 쓰기 끝을 닫지 않음 (fd[1])
        // fd[1]을 닫아야 하는데 닫지 않음

        // 읽기 시도
        int bytesRead = read(fd[0], buffer, sizeof(buffer));
        if (bytesRead == -1) {
            perror("read");
        } else if (bytesRead == 0) {
            printf("자식 프로세스: EOF를 만남\n");
        } else {
            buffer[bytesRead] = '\0';
            printf("자식 프로세스가 읽음: %s\n", buffer);
        }

        // 읽기 끝을 닫음
        close(fd[0]);
    } else { // 부모 프로세스
        // 읽기 끝을 닫지 않음 (fd[0])
        // fd[0]을 닫아야 하는데 닫지 않음

        // 쓰기 시도
		close(fd[0]);
        if (write(fd[1], "안녕하세요!", strlen("안녕하세요!")) == -1) {
            perror("write");
        }
		waitpid(pid, 0, WNOHANG);
		int a = 0;
		while(1)
		{
			scanf("%d", &a);
			if (a == 1)
				break ;
		}
		while(1)
		{
			scanf("%d", &a);
			if (a == 2)
				break ;
		}
        // 쓰기 끝을 닫지 않음
        // close(fd[1]); // 의도적으로 닫지 않음
    }

    return 0;
}

