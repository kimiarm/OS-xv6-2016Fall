
#include "types.h"
#include "stat.h"
#include "user.h"

#define N  30
void sanity(void){
int child_pid , wpid ;
int CID = -1 ; 
int counter ,i , j;  
int rTime[N],wTime[N];
int wsum0 = 0, wsum1 = 0, wsum2 = 0;
int tsum0 = 0, tsum1 = 0, tsum2 = 0;
int n0 = 0, n1 = 0, n2 = 0;
int wsumT = 0, tsumT = 0; 
int CIDs[N]; 
printf(1, "In parent (pid = %d) \n " , getpid());
for( counter = 0 ; counter<30 ; counter ++)
	{
		CID++ ;
		CIDs[counter] = CID ;
		if ( (child_pid = fork() ) == 0 )
			{
				if((CID%3)==0)
					{
						nice();
					}
			else	if((CID%3)==1)
					{
						nice();
						nice();
					}
				for(i = 0 ; i<500 ; i++)
					{

						//pid har farzand ra chap mikonad 


						getpid() ;
						printf(1 , "pid =%d    CID =%d\n", getpid(),CID);
						
					}

		exit() ;			
			}				
	}
for(j=0 ; j<30 ; j++)
	{
		wait2(&wTime[j],&rTime[j]);
	}

while( ( wpid = wait() ) > 0)
	{
		printf(1,"EXIT %d\n", wpid);
	}





for(j = 0 ; j<30 ; j++)
		printf(1 , "child %d :  r = %d   w=%d  \n ", CIDs[j],rTime[j],wTime[j]);




for( i = 0 ; i < 30 ; i++ )
	{

		//each child

		printf(1, "child %d : rtime = %d, wtime = %d, turnaroundtime = %d\n\n", CIDs[i], rTime[i], wTime[i], (rTime[i]+wTime[i]));

		wsumT += rTime[i];
		tsumT += rTime[i]+ wTime[i];

		if( CIDs[i] % 3 == 0 )
		{
			wsum1 +=wTime[i];
			tsum1 +=rTime[i] + wTime[i];
			n1++;
		}
		else if ( CIDs[i] % 3 == 1 )
		{
			wsum0 += wTime[i];
			tsum0 += rTime[i]+ wTime[i];
			n0++;
		}
		else 
		{
			wsum2 += wTime[i];
			tsum2 += rTime[i]+ wTime[i];
			n2++;
		}
	}

	//each queue

	printf(1, "priority 2 averag : turnedround = %d , waittime = %d\n\n\n", tsum2/n2, wsum2/n2);
	printf(1, "priority 1 averag : turnedround = %d , waittime = %d\n\n\n", tsum1/n1, wsum1/n1);
	printf(1, "priority 0 averag : turnedround = %d , waittime = %d\n\n\n", tsum0/n0, wsum0/n0);


	//total

	printf(1, "total averag : turnedround = %d , waittime = %d\n", tsumT/30, wsumT/30);


}

