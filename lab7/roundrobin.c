#include <stdlib.h>
#include <stdio.h>


struct processobject {
	int arrival;
	int id;
	int brusttime;
	int tot;
	int wait;
	int complete;
};


int main(){

	int n;
	printf("Enter the number of processes\n");
	scanf("%d",&n);
	struct processobject* processes[n];
	float avgwait,avgTOT;
	avgwait=avgTOT=0;
	int previoustimestamp=0;
	int previouscomplete=0;
  int brusttime[n];

	printf("Enter the id ,arrival time and the brust time of the processes\n");
	int i;
	for(i=0;i<n;i++){
		struct processobject* temp = (struct processobject*)malloc(sizeof(struct processobject));
		int id,a,b;
		scanf("%d %d %d",&id,&a,&b);
		temp->id = id;
		temp->arrival = a;
		temp->brusttime = b;
    brusttime[i]=b;
		processes[i]=temp;
	}

  printf("Enter the value of timequanta \n");
  int quanta;
  scanf("%d",&quanta);
  int flag=1;
  while(flag!=0){
    int flag2=0;
    for(i=0;i<n;i++){
      if(processes[i]->brusttime!=0){
        if(processes[i]-> brusttime <= quanta){
          previoustimestamp += processes[i]->brusttime;
          processes[i]->brusttime=0;
          processes[i]->complete = previoustimestamp;
        }
        else{
          processes[i]->brusttime-=quanta;
          previoustimestamp+=quanta;
          flag2=1;
          processes[i]->complete = previoustimestamp;
        }
      }
    }
    if(flag2!=1){
      flag=0;
    }
  }
  printf("Id\tArrivaltime\tbrusttime \t CT \t TOT \t WT \n");
  	for( i = 0 ; i < n ; i++ ){
      processes[i]->brusttime = brusttime[i];
      processes[i]->tot  = processes[i]->complete - processes[i]->arrival;
      processes[i]->wait = processes[i]->tot - processes[i]->brusttime;
  		printf("%d\t%d\t\t%d\t\t%d\t%d\t%d\n",processes[i]->id,processes[i]->arrival,processes[i]->brusttime,processes[i]->complete,processes[i]->tot,processes[i]->wait);
  		avgwait+=processes[i]->wait;
  		avgTOT += processes[i]->tot;
  	}
  	avgwait/=n;
  	avgTOT/=n;
  	printf("\nAverage waiting time = %f\n",avgwait);
  	printf("Average TOT = %f \n",avgTOT);
  	return 0;
}
