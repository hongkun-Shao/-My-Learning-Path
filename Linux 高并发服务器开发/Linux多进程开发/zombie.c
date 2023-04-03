#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>


//使得父进程无限循环，子进程结束之后也无法回收，使其变为僵尸进程
int main() {

    // 创建子进程
    pid_t pid = fork();

    // 判断是父进程还是子进程
    if(pid > 0) 
    {
        while(1) 
        {
            printf("i am parent process, pid : %d, ppid : %d\n", getpid(), getppid());
            sleep(1);
        }

    } 
    else if(pid == 0) 
    {
        // 当前是子进程
        printf("i am child process, pid : %d, ppid : %d\n", getpid(),getppid());
       
    }

    // for循环
    for(int i = 0; i < 3; i++) 
    {
        printf("i : %d , pid : %d\n", i , getpid());
    }

    return 0;
}