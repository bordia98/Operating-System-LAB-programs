import java.util.*;

class processobject{
  // class to store the object of processobject
  int arrival;
  int id;
  int brusttime;
  int tot;
  int wait;
  int complete;
  processobject(int id,int arrival,int brusttime){
    this.id=id;
    this.arrival=arrival;
    this.brusttime=brusttime;
  }
}


class SJF {

  static processobject[] processarray;
  public static void main(String args[]){

    float avgwait=0;
    float avgTOT=0;
    System.out.println("Enter the number of process"); // taking the input of process
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int previoustimestamp =0;
    int previouscomplete=0;
    processarray = new processobject[n];
    // storing processid , arrival time and brusttime
    System.out.println("Enter the process arrival time  and brusttime of the process");
    for(int i=0;i<n;i++){
      int id = sc.nextInt();
      int a = sc.nextInt();
      int b = sc.nextInt();
      processobject o = new processobject(id,a,b);
      processarray[i]=o;
    }
    for(int i=0;i<n;i++){
      processobject g = processarray[i];
      // no waiting if there is no process
      if(g.arrival==previoustimestamp || g.arrival > previoustimestamp){
        g.wait = 0;
        previoustimestamp+=g.brusttime;
        if(g.arrival > previoustimestamp){
          previoustimestamp=g.arrival+g.brusttime;
        }
      }// else you have to wait
      else{
        g.wait = previoustimestamp-g.arrival;
        previoustimestamp+=g.brusttime;
      }
      g.tot= g.wait + g.brusttime;      // calculation of tot
      g.complete = g.tot + g.arrival;   // calculation of complete

      for(int j=i+1;j<n;j++){
        if(processarray[j].arrival < g.tot){
        for(int k= j+1 ; k<n;k++){
          if(processarray[k].arrival<g.tot ){
            if( processarray[k].brusttime< processarray[j].brusttime){
              processobject temp = processarray[k];
              processarray[k] = processarray[j];
              processarray[j]=temp;
            }
          }
          }
        }
      }
    }
    // for printing the table
    System.out.println("ID  Arrival   Brust time    CT    tot   wt  ");
    for( int i =0 ; i<n ;i++){
      System.out.println(processarray[i].id+"  " + processarray[i].arrival+"             "+processarray[i].brusttime+"         "+ processarray[i].complete+"     "+processarray[i].tot+"     "+processarray[i].wait );
      avgwait += processarray[i].wait;
      avgTOT += processarray[i].tot;
    }
    avgwait/=n;
    avgTOT/=n;

    System.out.println("Average waiting time " + avgwait);
    System.out.println("Average TOT   " + avgTOT);



  }


}
