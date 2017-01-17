#include "types.h"
#include "stat.h"
#include "user.h"

#define N  10
#define P 1000


void
printChild()
{
  int i;
  int pid= getpid();
  for (i=0;i<P;i++)
     printf(2, "child %d prints for the %d time\n",pid ,i);
}

void
RRsanity(void)
{
  int wTime[N];
  int rTime[N];
  int pid[N];
int turn[N];
  int i, pidTemp,wTimeTemp, rTimeTemp;

  for(i=0;i<N;i++)
  {
    pidTemp = fork();
    if(pidTemp == 0)
    {
      printChild();
      exit();      
    }
  }

  for(i=0; i<N; i++)
  {

    pid[i] = wait2(&wTimeTemp,&rTimeTemp);
    wTime[i]=wTimeTemp;
    rTime[i]=rTimeTemp;
    turn[i]=wTimeTemp+rTimeTemp;
  }    
  
  for(i=0; i<N; i++)
  {
    printf(1, "child %d: wait time = %d, running time = %d, turnaround time = %d\n",pid[i],wTime[i],rTime[i], turn[i]);
  }     

}
int
main(void)
{
  RRsanity();
  exit();
}
