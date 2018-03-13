#include<stdio.h>

void callfirstfit(int a[],int n,int b[],int m,int size){
    int allocated[m];
    int i,j;
    for(i=0;i<n;i++)
      printf("%d\n",a[i]);
    for(i=0;i<m;i++){
        allocated[i]=-1;
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(a[j]>=b[i]){
                allocated[i]=j+1;
                a[j]-=b[i];
                break;
            }
        }
    }

  printf("ProcessSize     startpoint     endpoint\n");
  printf("%d\t\t%d\t\t%d\n",(size/12),0,(size/12));
  printf("%d\t\t%d\t\t%d\n",(size/8),(size/4),((size/4)+(size/8)));
  printf("%d\t\t%d\t\t%d\n",(size/4),(size/2),((size/2)+(size/4)));

  int firstsize=size/12;
  int secondsize=(size/4)+(size/8);
  int thirdsize=(size/2)+(size/4);
  for(i=0;i<m;i++){
    if(allocated[i]==2){
      printf("%d\t\t%d\t\t%d\n",b[i],firstsize,firstsize+b[i]);
      firstsize+=b[i];
    }
    else if(allocated[i]==4){
      printf("%d\t\t%d\t\t%d\n",b[i],secondsize,secondsize+b[i]);
      secondsize+=b[i];
    }
    else if(allocated[i]==6){
      printf("%d\t\t%d\t\t%d\n",b[i],thirdsize,thirdsize+b[i]);
      thirdsize+=b[i];
    }
    else{
      printf("%d\t\txxxx\t\txxxx\n",b[i]);
    }
  }
}

void callbestfit(int a[],int n,int b[],int m,int size){
    int allocated[m];
    int i,j;
    for(i=0;i<m;i++){
        allocated[i]=-1;
    }
    int best;
    for(i=0;i<m;i++){
        best=-1;
        for(j=0;j<n;j++){
            int prevbest=-1;
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
        if(best!=-1){
        allocated[i]=(best+1);
        a[best]-=b[i];
      }
    }
    printf("ProcessSize     startpoint     endpoint\n");
    printf("%d\t\t%d\t\t%d\n",(size/12),0,(size/12));
    printf("%d\t\t%d\t\t%d\n",(size/8),(size/4),((size/4)+(size/8)));
    printf("%d\t\t%d\t\t%d\n",(size/4),(size/2),((size/2)+(size/4)));

    int firstsize=size/12;
    int secondsize=(size/4)+(size/8);
    int thirdsize=(size/2)+(size/4);
    for(i=0;i<m;i++){
      if(allocated[i]==2){
        printf("%d\t\t%d\t\t%d\n",b[i],firstsize,firstsize+b[i]);
        firstsize+=b[i];
      }
      else if(allocated[i]==4){
        printf("%d\t\t%d\t\t%d\n",b[i],secondsize,secondsize+b[i]);
        secondsize+=b[i];
      }
      else if(allocated[i]==6){
        printf("%d\t\t%d\t\t%d\n",b[i],thirdsize,thirdsize+b[i]);
        thirdsize+=b[i];
      }
      else{
        printf("%d\t\txxxx\t\txxxx\n",b[i]);
      }
    }
}

void callworstfit(int a[],int n,int b[],int m,int size){
    int allocated[m];
    int i,j;
    for(i=0;i<m;i++){
        allocated[i]=-1;
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
            a[index]-=b[i];
            allocated[i]=(index+1);
        }
    }
    printf("ProcessSize     startpoint     endpoint\n");
    printf("%d\t\t%d\t\t%d\n",(size/12),0,(size/12));
    printf("%d\t\t%d\t\t%d\n",(size/8),(size/4),((size/4)+(size/8)));
    printf("%d\t\t%d\t\t%d\n",(size/4),(size/2),((size/2)+(size/4)));

    int firstsize=size/12;
    int secondsize=(size/4)+(size/8);
    int thirdsize=(size/2)+(size/4);
    for(i=0;i<m;i++){
      if(allocated[i]==2){
        printf("%d\t\t%d\t\t%d\n",b[i],firstsize,firstsize+b[i]);
        firstsize+=b[i];
      }
      else if(allocated[i]==4){
        printf("%d\t\t%d\t\t%d\n",b[i],secondsize,secondsize+b[i]);
        secondsize+=b[i];
      }
      else if(allocated[i]==6){
        printf("%d\t\t%d\t\t%d\n",b[i],thirdsize,thirdsize+b[i]);
        thirdsize+=b[i];
      }
      else{
        printf("%d\t\txxxx\t\txxxx\n",b[i]);
      }
    }
}


int main(){
  int size;

  printf("Enter the total bulk size of space which is available\n");
  scanf("%d",&size);

  printf("The process which are currently running are ");

  printf("Process which are currently running  are  \n");
  printf("Process no      size         startpoint          endpoint\n");
  printf("1->\t\t%d\t\t%d\t\t%d\n",(size/12),0,(size/12));
  printf("2->\t\t%d\t\t%d\t\t%d\n",(size/8),(size/4),((size/4)+(size/8)));
  printf("3->\t\t%d\t\t%d\t\t%d\n",(size/4),(size/2),((size/2)+(size/4)));

  int a[6];
  a[0]=0;
  a[2]=0;
  a[4]=0;
  a[1]=((size/4)-(size/12));
  a[3]=((size/2)-(size/4)-(size/8));
  a[5]=((size)-(size/2)-(size/4));

  int choice=0;
  int m,i;
  printf("Enter the number of processes that you want to allocate\n");
  scanf(" %d",&m);
  int processarray[m];
  printf("Enter the size of each process\n");
  for(i=0;i<m;i++){
      scanf("%d",&processarray[i]);
  }
  int temp[6];
  for(i=0;i<6;i++){
    temp[i]=a[i];
  }
  while(choice!=4){
      printf("Select your choice\n");
      printf(" 1.) First fit\n");
      printf(" 2.)Best fit\n");
      printf(" 3.) Worst fit\n ");
      printf("4.)any other interger to exit\n");
      scanf(" %d",&choice);
      for(i=0;i<6;i++){
        a[i]=temp[i];
      }
      if(choice<=0 &&choice>=4){
          break;
      }
      else{
          if(choice==1){
              callfirstfit(a,6,processarray,m,size);
          }
          else if(choice==2){
              callbestfit(a,6,processarray,m,size);
          }
          else if(choice==3){
              callworstfit(a,6,processarray,m,size);
          }
      }

  }
  return 0;
}
