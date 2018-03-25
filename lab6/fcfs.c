#include<stdio.h>
#include<stdlib.h>

struct processobject {
	int arrival;
	int id;
	int brusttime;
	int tot;
	int wait;
	int complete;
};

void sortingonarrivaltime(struct processobject* processarray[] , int n){

	int i,j;
	for(i=0;i<n;i++){
		for(j=1;j<(n-i);j++){
			if( processarray[i]->arrival > processarray[j]->arrival){
				struct processobject* temp2;
				temp2 = processarray[i];
				processarray[i]=processarray[j];
				processarray[j]=temp2;
			}
		}
	}
}

int main(){
	
	int n;
	printf("Enter the number of processes\n");
	scanf("%d",&n);
	struct processobject* processes[n];
	float avgwait,avgTOT;
	avgwait=avgTOT=0;
	int previoustimestamp=0;
	int previouscomplete=0;

	printf("Enter the id ,arrival time and the brust time of the processes\n");
	int i;
	for(i=0;i<n;i++){
		struct processobject* temp = (struct processobject*)malloc(sizeof(struct processobject));
		int id,a,b;
		scanf("%d %d %d",&id,&a,&b);
		temp->id = id;
		temp->arrival = a;
		temp->brusttime = b;
		processes[i]=temp;
	}

	sortingonarrivaltime(processes,n);

	for(i=0;i<n;i++){
		struct processobject* g = processes[i];
		if(g->arrival==previoustimestamp || g->arrival > previoustimestamp){
			g->wait =0;
			previoustimestamp+=g->brusttime;
			if(g->arrival > previoustimestamp){
				previoustimestamp = g->arrival + g->brusttime;	
			}
		}
		else{
			g->wait = previoustimestamp - g->arrival;
			previoustimestamp += g->brusttime;
		}
		g->tot = g->wait + g->brusttime;
		g->complete = g->tot + g->arrival;
	}

	printf("Id\tArrivaltime\tbrusttime \t CT \t TOT \t WT \n");
	for( i = 0 ; i < n ; i++ ){
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
