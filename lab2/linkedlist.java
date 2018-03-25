import java.io.*;
import java.util.*;

class objectstructure{
  int size;
  objectstructure(int size){
    this.size=size;
  }
}
class memorymanagement{

  public static void main(String args[]){
  int n;
  System.out.println("Enter the number of partitions that are present in the memory");
  Scanner sc = new Scanner(System.in);
  n=sc.nextInt();
  int[] a = new int[n];
  System.out.println("Enter the memory that can be allocated in each partition");
  int mem;
  mem=sc.nextInt();
  for(int i=0;i<n;i++){
    a[i]=mem;
  }

  System.out.println("Enter the pagesize that you want to set");
  int page;
  page=sc.nextInt();

  System.out.println("Enter the number of processes that you wanna allocate");
  int processnumber;
  processnumber=sc.nextInt();
  LinkedList[] processarray=new LinkedList[processnumber];
  int[] process2 = new int[processnumber];
  System.out.println("Enter the size of each process");
  for(int i=0;i<processnumber;i++){
    int temp=sc.nextInt();
    int partition =(int)(temp/page);
    LinkedList l = new LinkedList();
    for(int j=0;j<partition;j++){
      objectstructure o = new objectstructure(page);
      l.add(o);
      }

    int finalmem=0;
    finalmem = temp-(page*partition);
    if(finalmem!=0){
    objectstructure o = new objectstructure(finalmem);
    l.add(o);
    }
    process2[i]=temp;
    processarray[i]=l;
  }


    LinkedList[] allocated = new LinkedList[processnumber];
    for(int j=0;j<processnumber;j++){
      for(int k=0;k<n;k++){
        if(a[k]>=process2[j]){
          a[k]-=process2[j];
          process2[j]=0;
          break;
        }
        else{
          int count=0;
          int finalrest=0;
          count=(int)(process2[j]/page);
          finalrest=process2[j]-(count*page);
          if(processarray[j].size()>count){
            while(processarray[j].size()!=1){
              if(k<n){
                if(a[k]>=page){
                  a[k]-=page;
                  processarray[j].pop();
                }
                else{
                  k+=1;
                }
              }
              else{
                break;
              }
            }
            if(k<n){
              if(a[k]>=finalrest){
                a[k]-=finalrest;
                processarray[j].pop();
                break;
              }
              else{
                k=k+1;
                if(k<n){
                  a[k]-=finalrest;
                  processarray[j].pop();
                  break;
                }
                else{
                  break;
                }
              }
            }
          }
          else if(processarray[j].size()==count){
            while(processarray[j].size()!=0){
              if(k<n){
                if(a[k]>=page){
                  a[k]-=page;
                  processarray[j].pop();
                }
                else{
                  k+=1;
                }
              }
              else{
                break;
              }
            }
          }

        }
      }
    }

    for(int w=0;w<processnumber;w++){
      if(process2[w]==0 || processarray[w].size()==0){
        System.out.println("Process "+ (w+1) + " is allocated");
      }
      else if(processarray[w].size()!=0){
        System.out.println("Process "+ (w+1)+ "  number of pages whose allocation still left are " + processarray[w].size());
      }
    }
  }
}
