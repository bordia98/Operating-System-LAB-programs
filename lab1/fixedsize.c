#include<stdio.h>

void callfirstfit(int a[],int n,int b[],int m,int available[]){
    int allocatedlist[m];
    int i,j;
    for(i=0;i<m;i++){
        allocatedlist[i]=-1;
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(a[j]>=b[i]){
                allocatedlist[i]=j+1;
                available[j]=a[j]-b[i];
                a[j]=0;
                break;
            }
        }
    }
    printf("ProcessNumber  ProcessSize  Allocated partition to process  \n");
    for(i=0;i<m;i++){
        printf("%d\t\t%d\t\t",(i+1),b[i]);
        if(allocatedlist[i]!=-1){
            printf("%d\n",allocatedlist[i]);
        }
        else{
            printf("Not allocated\n");
        }
    }
    printf( "Block Number   Internal Fragmentation\n");
    for ( i=0 ; i<n ; i++){
      if(a[i]==0){
        if(available[i]!=0){
          printf("%d\t\t%d\n",i+1,available[i] );
        }
      }
    }
}

void callbestfit(int a[],int n,int b[],int m,int available[]){
    int allocatedlist[m];
    int i,j;
    for(i=0;i<m;i++){
        allocatedlist[i]=-1;
    }
    int best;
    for(i=0;i<m;i++){
        best=-1;
        for(j=0;j<n;j++){
            int prevbest;
            if(a[j]>=b[i]){
                prevbest=j;
            }
            if(best==-1){
                best=prevbest;
            }
            else{
                if(a[best]>a[prevbest]){
                    best=prevbest;
                }
            }
        }
        allocatedlist[i]=(best+1);
        available[best]=a[best]-b[i];
        a[best]=0;
    }
    printf("ProcessNumber  ProcessSize  Allocated partition to process\n");
    for(i=0;i<m;i++){
        printf("%d\t\t%d\t\t",(i+1),b[i]);
        if(allocatedlist[i]!=-1){
            printf("%d\n",allocatedlist[i]);
        }
        else{
            printf("Not allocated\n");
        }
    }
    printf( "Block Number   Internal Fragmentation\n");
    for ( i=0 ; i<n ; i++){
      if(a[i]==0){
        if(available[i]!=0){
          printf("%d\t\t%d\n",i+1,available[i] );
        }
      }
    }

}

void callworstfit(int a[],int n,int b[],int m,int available[]){
    int allocatedlist[m];
    int i,j;
    for(i=0;i<m;i++){
        allocatedlist[i]=-1;
    }

    int largest;
    for(i=0;i<m;i++){
        largest=-1;
        int index=-1;
        for(j=0;j<n;j++){
            if(largest==-1){
                largest=a[j];
                index=j;
            }
            else{
                if(largest<a[j]){
                    largest=a[j];
                    index=j;
                }
            }
        }
        if(largest>b[i]){
            available[index]=a[index]-b[i];
            a[index]=0;
            allocatedlist[i]=(index+1);
        }
    }
    printf("ProcessNumber  ProcessSize  Allocated partition to process\n");
    for(i=0;i<m;i++){
        printf("%d\t\t%d\t\t",(i+1),b[i]);
        if(allocatedlist[i]!=-1){
            printf("%d\n",allocatedlist[i]);
        }
        else{
            printf("Not allocated\n");
        }
    }
    printf( "Block Number   Internal Fragmentation\n");
    for ( i=0 ; i<n ; i++){
      if(a[i]==0){
        if(available[i]!=0){
          printf("%d\t\t%d\n",i+1,available[i] );
        }
      }
    }
}


int main(){
    int n;
    printf("Enter the number of partitions\n");
    scanf("%d",&n);
    int i;
    int a[n];
    int temp[n];
    int available[n];
    printf("Start entering the size of each partition\n");
    for(i=0;i<n;i++)
      {  scanf(" %d",&a[i]);
        temp[i]=a[i];
      }
    int choice=0;
    int m;
    printf("Enter the number of processes that you want to allocate\n");
    scanf(" %d",&m);
    int processarray[m];
    printf("Enter the size of each process\n");
    for(i=0;i<m;i++){
        scanf("%d",&processarray[i]);
    }
    while(choice!=4){
        printf("Select your choice\n");
        printf(" 1.) First fit\n");
        printf(" 2.)Best fit\n");
        printf(" 3.) Worst fit\n ");
        printf("4.)any other interger to exit\n");
        scanf(" %d",&choice);
        for(i=0;i<n;i++){
          a[i]=temp[i];
          available[i]=a[i];
        }
        if(choice<=0 &&choice>=4){
            break;
        }
        else{
            if(choice==1){
                callfirstfit(a,n,processarray,m,available);
            }
            else if(choice==2){
                callbestfit(a,n,processarray,m,available);
            }
            else if(choice==3){
                callworstfit(a,n,processarray,m,available);
            }
        }

    }
    return 0;
}
