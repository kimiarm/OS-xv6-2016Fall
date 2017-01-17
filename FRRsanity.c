#include "types.h"
#include "stat.h"
#include "user.h"

#define N  10
int main(void){
	int pid[N];
	for(int i = 0; i < N; i++){
		 pid[i] = fork();
		 if(pid[i] == 0)
			for(int i = 0; i < 1000; i++){
		
			}
		 
	}
	for(int i = 0; i < 10; i++)
		wait();
	exit();
	return 0;
}
