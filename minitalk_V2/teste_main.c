# include <signal.h>
# include <unistd.h>
#include <stdio.h>

void sig_handler(int signal){
    write(1,"hello", 5);
    if (signal == SIGUSR1 || signal == SIGUSR2)
        write(1,"H", 1);
}

int main(){

    struct sigaction	sa;  
    sa.sa_flags = 0;
    sa.sa_handler = sig_handler;
    printf("pid numb: %i \n", getpid());
    sigaction(SIGUSR1, &sa, NULL);
    while (1){
        pause();
    }
}