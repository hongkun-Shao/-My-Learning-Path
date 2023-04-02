/*  
    #include <unistd.h>
    int execl(const char *path, const char *arg, ...);
        - 参数：
            - path:需要指定的执行的文件的路径或者名称
                a.out /home/nowcoder/a.out 推荐使用绝对路径
                ./a.out hello world

            - arg:是执行可执行文件所需要的参数列表
                第一个参数一般没有什么作用，为了方便，一般写的是执行的程序的名称
                从第二个参数开始往后，就是程序执行所需要的的参数列表。
                参数最后需要以NULL结束（哨兵）

        - 返回值：
            只有当调用失败，才会有返回值，返回-1，并且设置errno
            如果调用成功，没有返回值。

*/

/*
    此代码中我们fork一个子进程，并在子进程中使用execl函数调用ps aux指令(进程)，我们可以看到一个结果就是父进程的代码正常执行
    而子进程执行ps aux，不执行原来的代码。
*/

#include <unistd.h>
#include <stdio.h>

int main() {


    // 创建一个子进程，在子进程中执行exec函数族中的函数
    pid_t pid = fork();

    if(pid > 0) {
        // 父进程
        printf("i am parent process, pid : %d\n",getpid());
        sleep(1);
    }else if(pid == 0) {
        // 子进程
        // execl("hello","hello",NULL);

        execl("/bin/ps", "ps", "aux", NULL); //调用/bin/ps 下的ps aux指令(进程)
        perror("execl");

        //正常来说，后面的代码不会执行，因为已经被替代了
        printf("i am child process, pid : %d\n", getpid());

    }

    for(int i = 0; i < 3; i++) {
        printf("i = %d, pid = %d\n", i, getpid());
    }


    return 0;
}