//
//
#include "types.h"
#include "stat.h"
#include "user.h"

#define P 50

void Gsanity(void){
   // int status;
    int pid = getpid();
    printf(1, "Father pid is %d\n", pid);
    sleep(1000);
    fork();
    pid = getpid();
    for (int i = 0; i < P; i++) {
        printf(2, "process %d is printing for the %d time\n", pid, i);
    }
   
        wait();

    
}

int main (void){
    Gsanity();
    exit();
}
