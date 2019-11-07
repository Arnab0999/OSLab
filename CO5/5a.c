#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

void fork_example()
{
    if(fork()==0){
        sleep(5);
        char *args[]={"./catT.sh",NULL};
        printf("In child process, id: %d\n",getpid());
        execlp("/bin/ps","ps",NULL);
        execlp("fork5","./catT.sh",NULL);
    }
    else
    {
        sleep(5);
        printf("In parent process, id: %d\n",getpid());
        execlp("/bin/ps","ps",NULL);
    }
    
}
int main()
{
    fork_example();
    return 0;
}
