// Parent

#include "types.h" 
#include "user.h"
#include "syscall.h"
#include "traps.h"

int getppid2(void) { 
	int ppid ;
	asm volatile ("int %1" : "=a" (ppid): "i" (T_SYSCALL), "a" ( SYS_getppid ) ) ;
	return ppid ;
}


int main(void) {

int ChildPid = fork ();
if (ChildPid < 0)
	printf (1 ,"Fork failed %d\n" ,ChildPid );
else if (ChildPid > 0) {

printf(1, "I am the parent. My pid is %d, child id is %d\n", getpid () , ChildPid );
wait ();
} else {
printf(1, "I am the child. My pid is %d, my parent id is %d\n",getpid () ,getppid2 ());
}

exit();

}




