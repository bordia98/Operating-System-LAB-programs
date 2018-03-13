#include<stdio.h>
#include<stdlib.h>

void allocate(int,int);
void makeheap(int);
void releasememory(int);
void printbuddytree(int,int);
int checker(int);
int treenodescalculator(int,int);

int budddytree[5050];
int i,j,k;

void allocate(int totalmemory,int process_size)														// take two parameters and check whether space available or not		
{
       int flevel=0,size;
	     size=totalmemory;
       if(process_size>totalmemory)// || process_size<=2)             // size of process should not be less then 2 minimum block we have considered of two
		   {         printf("Invalid req!\n");
		            return;
	     }
	      while(1){
		         if(process_size<=size && process_size>=(size/2))			// Finding the level in graph where to place
			          break;
		        else{
			          size/=2;
			          flevel++;
		            }
	       }
	for(i=treenodescalculator(2,flevel)-1;i<=(treenodescalculator(2,flevel+1)-2);i++)				// Putting the value in that level
		    if(budddytree[i]==0 && checker(i)){										// checking that the slot is empty or not
			       budddytree[i]=process_size;											// If it is  empty then assign
			       makeheap(i);
			       printf("Done!\n");
			       break;
		    }
	      if(i==treenodescalculator(2,flevel+1)-1){									// else pop not enough space
		         printf("No enough Memory");
	          }
}

void makeheap(int buddynode)															// Checking the buddy array empty
{
	while(buddynode!=0)
	{
		buddynode=buddynode%2==0?(buddynode-1)/2:buddynode/2;
		budddytree[buddynode]=1;
	}
}
int checker(int buddynode)														//	( selecting two nodes of one)
{
	while(buddynode!=0)
	{
		buddynode=buddynode%2==0?(buddynode-1)/2:buddynode/2;
		if(budddytree[buddynode]>1)
			return 0;
	}
	return 1;
}
void releasememory(int process_size)										// Releasing the memory whenever that process size first encounter
{
	int buddynode=0;
	while(1)
	{
		if(budddytree[buddynode]==process_size)
			break;
		else
			buddynode++;
	}
	budddytree[buddynode]=0;
	while(buddynode!=0)
	{
		if(budddytree[buddynode%2==0?buddynode-1:buddynode+1]==0 && budddytree[buddynode]==0)
		{
			budddytree[buddynode%2==0?(buddynode-1)/2:buddynode/2]=0;
			buddynode=buddynode%2==0?(buddynode-1)/2:buddynode/2;
		}
		else break;
	}
}
int treenodescalculator(int x,int y)							// Calculates the total number of tree node which are previous 
{
	int z,ans;
	if(y==0) return 1;
	ans=x;
	for(z=1;z<y;z++)
		ans*=x;
	return ans;
}
void printbuddytree(int totalmemory,int buddynode)				//	Printing of the buddy tree
{
	int var=0,lowerbound,upperbound,tab;
	if(buddynode==0)
		var=1;
	else if(buddynode%2==0)
		var=budddytree[(buddynode-1)/2]==1?1:0;
	else
		var=budddytree[buddynode/2]==1?1:0;
	if(var)
	{
		lowerbound=upperbound=tab=0;
		while(1)
		{
			if(buddynode>=lowerbound && buddynode<=upperbound)
				break;
			else
			{
				tab++;
				printf("       ");
				lowerbound=upperbound+1;
				upperbound=2*upperbound+2;
			}
		}
		printf(" %d ",totalmemory/treenodescalculator(2,tab));
		if(budddytree[buddynode]>1)
			printf("---> Allocated %d\n",budddytree[buddynode]);
		else if(budddytree[buddynode]==1)
			printf("---> Divided\n");
		else printf("---> Free\n");
		printbuddytree(totalmemory,2*buddynode+1);
		printbuddytree(totalmemory,2*buddynode+2);
	}
}
int main()
{
	int totalmemory=512,processsize;
  int x;
  do
  {
    printf("0. Exit\n1. Allocate\n2. Free \n3.Show Allocation\n");
    scanf("%d",&x);
    if(x>0 && x<4){
      if( x == 1){
                      printf("Size : ");
                      scanf("%d",&processsize);
                      allocate(totalmemory,processsize);
                }
      if( x == 2){
                      printf("Size : ");
                      scanf("%d",&processsize);
                      releasememory(processsize);
                    }
    if( x==3){
                      printbuddytree(totalmemory,0);
                    }
        }
      }while(x>0 && x <=3);
}
