#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void BestFITmem(int m,int block[],int n,int process[]){
  int allocation[n];
  int arblock[m];
  for(int x=0;x<m;x++){
    arblock[x]=block[x];
  }
  int arprocess[n];
  for(int u=0;u<n;u++){
    arprocess[u]=process[u];
  }
  memset(allocation,-1,sizeof(allocation));
  for(int i=0;i<n;i++){
    int best=-1;
    for(int j=0;j<m;j++){
      if(arblock[j]>=arprocess[i]){
        if(best==-1){
          best=j;
        }
        else if(arblock[best]>arblock[j]){
          best=j;
        }
      }
    }
    if(best!=-1){
      allocation[i]=best;
      arblock[best]=arblock[best]-arprocess[i];
    }
  }
  printf("BESTFIt\n");
  printf("\n process No. \t Process Size\t Block No.\n");
  for(int r=0;r<n;r++){
    printf(" %d\t\t%d\t\t",r+1,arprocess[r] );
    if(allocation[r]!=-1){
      printf("%d",allocation[r]+1);
    }
    else{
      printf("Not allocated");
    }
    printf("\n");
  }
}
void FirstFitmem(int m,int block[],int n,int process[]){
  int allocation[n];
  int block1[m];
  for(int y=0;y<m;y++){
    block1[y]=block[y];
  }
  int process1[n];
  for(int c=0;c<n;c++){
    process1[c]=process[c];
  }
  memset(allocation,-1,sizeof(allocation));
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(block1[j]>=process1[i]){
        allocation[i]=j;
        block1[j]-=process1[i];
        break;
      }
    }
  }
  printf("FIRSTFIT\n");
  printf("\n process No. \t Process Size\t Block No.\n");
  for(int r=0;r<n;r++){
    printf(" %d\t\t%d\t\t",r+1,process1[r] );
    if(allocation[r]!=-1){
      printf("%d",allocation[r]+1);
    }
    else{
      printf("Not allocated");
    }
    printf("\n");
  }
}
void WORSTFITmem(int m,int block[],int n,int process[]){
  int allocation[n];
  int copyblock[m];
  int copyprocess[n];
  for(int i=0;i<m;i++){
    copyblock[i]=block[i];
  }
  for(int j=0;j<n;j++){
    copyprocess[j]=process[j];
  }
  memset(allocation,-1,sizeof(allocation));
  for(int i=0;i<n;i++){
    int worst=-1;
    for(int j=0;j<m;j++){
      if(copyblock[j]>=copyprocess[i]){
        if(worst==-1){
          worst=j;
        }
        else if(copyblock[worst]<copyblock[j]){
          worst=j;
        }
    }
  }
    if(worst!=-1){
      allocation[i]=worst;
      copyblock[worst]=copyblock[worst]-copyprocess[i];
    }

}
  printf("Worst FIT\n");
  printf("\n process No. \t Process Size\t Block No.\n");
  for(int r=0;r<n;r++){
    printf(" %d\t\t%d\t\t",r+1,copyprocess[r] );
    if(allocation[r]!=-1){
      printf("%d",allocation[r]+1);
    }
    else{
      printf("Not allocated");
    }
    printf("\n");
  }
}
int main(){
  int memblock;
  printf("Enter the no of memory blocks\n");
  scanf("%d",&memblock);
  int memw[memblock];
  int i;
  printf("Enter the sizes of the memory %d blocks \n",memblock);
  for(i=0;i<memblock;i++){
    scanf("%d",&memw[i]);
  }
  int proce;
  printf("Enter the no of processes\n");
  scanf("%d",&proce);
  int process[proce];
  int j;
  for(j=0;j<proce;j++){
    scanf("%d",&process[j]);
  }
  BestFITmem(memblock,memw,proce,process);
  WORSTFITmem(memblock,memw,proce,process);
  FirstFitmem(memblock,memw,proce,process);
  return 0;
}
