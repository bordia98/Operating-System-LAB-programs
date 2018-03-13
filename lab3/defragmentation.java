import java.util.Scanner;
import java.util.LinkedList;
import java.io.*;

class struct{
  int size;
  int startpoint;
  int endpoint;
  struct(int size){
    this.size=size;
    this.startpoint=startpoint;
    this.endpoint=endpoint;
  }
}


class partitioning{
  public static void main(String args[]){

    LinkedList<Integer> store = new LinkedList<>();
    System.out.println("Enter the size of the memory");
    int size;
    Scanner sc = new Scanner(System.in);
    size=sc.nextInt();
    int choice;
    do{
    System.out.println("Select the choice");
    System.out.println("1.)Add process");
    System.out.println("2.)Remove process");
    System.out.println("3.)show running process");
    System.out.println("4.)Exit");
    choice=sc.nextInt();

    switch(choice){
      case 1:{
        System.out.println("Enter the process size");
        int prosize;
        prosize=sc.nextInt();
        if(size>=prosize)
            { size-=prosize;
              store.add(prosize);
            }
        else{
          System.out.println("Memory outflow");
        }
        break;
      }
      case 2: {
        System.out.println("Enter the process index that you want to remove");
        int proindex;
        proindex=sc.nextInt();
        if(proindex>=0&&proindex<store.size()){
          int prosize = store.get(proindex);
          size+=prosize;
          store.remove(proindex);
          System.out.println("size = "+ size);
        }
        else{
          System.out.println("There no process of this index");
        }
        break;
      }
      case 3:{
        int startingpoint=0;
        int endingpoint=0;
        if(store.size()>=0){
          System.out.println("ProcessIndex\tStarting Point\tEnding Point\tProcess Size");
          for(int i=0;i<store.size();i++){
            endingpoint+=store.get(i);
            System.out.println(i+"\t\t"+startingpoint+"\t\t"+endingpoint+"\t\t"+store.get(i));
            startingpoint+=store.get(i);
          }
        System.out.println("");
        }
        System.out.println("The memory available : "+size);
        break;
      }
      case 4:
      {
        System.exit(0);
        break;
      }
      default :{
        System.out.println("You have entered wrong choice");
        System.out.println("Come Back !! Again");
        }
      }
    }while(choice>0&&choice<=4);
  }

}
