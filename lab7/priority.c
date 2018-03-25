#include <stdlib.h>
#include <stdio.h>


struct processobject {
	int arrival;
	int id;
	int priority;
	int brusttime;
	int tot;
	int wait;
	int complete;
};

void sortarrivaltime(struct processobject* arrivalarray[],int n){
	int i,j;
	for(i=0;i<n-1;i++){
		for(j=0;j<(n-i-1);j++){
			if( arrivalarray[j]->arrival > arrivalarray[j+1]->arrival)
			{
				
				struct processobject* temp = arrivalarray[j];
				arrivalarray[j] = arrivalarray[j+1];
				arrivalarray[j+1] = temp;
			}
		}
	}
}

void sortonbasisofpriority(struct processobject* arrivalarray[],int n){
	int i,j;
	for(i=0;i<n-1;i++){
		for(j=0;j<(n-i-1);j++){
			if( arrivalarray[j]->priority < arrivalarray[j+1]->priority)
			{
				struct processobject* temp = arrivalarray[j];
				arrivalarray[j] = arrivalarray[j+1];
				arrivalarray[j+1] = temp;
			}
		}
	}	
}

int check(int j,struct processobject* arrivalarray[],int n){
	int i=0;
	printf("%d value of j\n", j );
	for(i=j+1;i<n;i++){
		if(arrivalarray[i]->priority > arrivalarray[j]->priority){
			//printf("%d ---------------------\n",i);
			return i;
		}
	}
	return j;
}

int main(){
	int n;
	printf("Enter the number of processes\n");
	scanf("%d",&n);
	struct processobject* processes[n];
	struct processobject* processesonarrivaltime[n];
	float avgwait,avgTOT;
	avgwait=avgTOT=0;
	int previoustimestamp=0;
	int previouscomplete=0;
	int brusttime[n];

	printf("Enter the id ,arrival time ,the brust time and priority of the processes\n");
	int i;
	for(i=0;i<n;i++){
		struct processobject* temp = (struct processobject*)malloc(sizeof(struct processobject));
		int id,a,b,p;
		scanf("%d %d %d %d",&id,&a,&b,&p);
		temp->id = id;
		temp->arrival = a;
		temp->brusttime = b;
		temp->priority = p;
	    brusttime[i]=b;
		processes[i]=temp;
		processesonarrivaltime[i] = temp;
	}
	sortarrivaltime(processesonarrivaltime,n);
	int flag=1;
	int flag2 = 1;
	int k=0;
	int index=0;
	while(flag!=0){
			printf("%d value of k\n", k);
			index = check(k,processesonarrivaltime,n);
			if(index > k){
				//printf(" %d flag " , flag);
				//printf("Bhavya\n");
				previoustimestamp += processesonarrivaltime[index]->arrival - processesonarrivaltime[k]->arrival;
				if( previoustimestamp >= (processesonarrivaltime[k]->brusttime + processesonarrivaltime[k]->arrival)){
					processesonarrivaltime[k]->brusttime = 0;
					processesonarrivaltime[k]->complete = processesonarrivaltime[k]->brusttime + processesonarrivaltime[k]->arrival;
					k = index;
				}
				else{
					processesonarrivaltime[k]->brusttime -=(processesonarrivaltime[index]->arrival- processesonarrivaltime[k]->arrival); 
					k = index;
				}
			}else{
				//printf(" %d flag " , k);
				//printf("%d +++++++++++++++++\n",index );
				previoustimestamp += processesonarrivaltime[index]->arrival- processesonarrivaltime[k]->arrival;
				processesonarrivaltime[k]->brusttime -=(processesonarrivaltime[index]->arrival- processesonarrivaltime[k]->arrival); 					
				//printf("index = %d why it is ending here \n", index);
				flag=0;
				sortonbasisofpriority(processesonarrivaltime,n);
			}
	}

	for(i=0;i<n;i++){
		if(processesonarrivaltime[i]->brusttime!=0){
			printf("%d $$$$ %d\n", processesonarrivaltime[i]->id , processesonarrivaltime[i]->brusttime);
			previoustimestamp+=processesonarrivaltime[i]->brusttime;
			processesonarrivaltime[i]->complete = previoustimestamp;
		}
	}

	sortarrivaltime(processesonarrivaltime,n);

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


