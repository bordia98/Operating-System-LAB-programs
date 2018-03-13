import java.util.*;
class processstruct                                     // Structure of the HashMap
{
    HashMap<Integer, Integer> a;                      // HAshmap
    int pagen;
    int frame;
}
class pagination                    // main classs
{
    static int allocate(int pnum,int[] mem)       // function for allocating memory
    {
        for(int i=0;i<100;i++)
        {
            if(mem[i]==0)
            {
                mem[i]=pnum+1;
                return i;
            }
        }
        return -1;
    }
    public static void main(String args[])
    {
        Scanner s=new Scanner(System.in);
        boolean flag=true;
        int framesize=20;         //predefinded frame size
        int pnum=0;
        int mem[]=new int[100];
        processstruct[] processstructes=new processstruct[100];     // Process structure that HAshmap
        for(int i=0;i<100;i++)
        {
            mem[i]=0;
            processstructes[i]=new processstruct();
        }
        while(flag)
        {
            System.out.println("1. Add proc\n2. Kill proc\n3. List proc\n4. Exit");   // giving options what to do
            System.out.println("Enter your option:");
            int option=s.nextInt();
            switch(option)
            {
                case 1:
                System.out.println("Enter processstruct size:");
                int psize=s.nextInt();          // taking the pagesize
                int fno=(int)Math.ceil((float)psize/((float)framesize));    // counting the number of frames required
                HashMap<Integer, Integer> t=new HashMap<Integer, Integer>();
                int page_no=1;
                int x=allocate(pnum,mem);
                if(x==-1)             // checking fill or not
                {
                    System.out.println("mem full! No more processstructes!");
                }
                else
                {
                    t.put(page_no++,x);               // if not fill then doing the allocation
                    for(;page_no<=fno;page_no++)
                    {
                        x=allocate(pnum,mem);
                        t.put(page_no,x);
                    }
                    processstructes[pnum].frame=fno;
                    processstructes[pnum].pagen=pnum+1;
                    processstructes[pnum++].a=t;
                }
                break;
                case 2:
                System.out.println("Enter processstruct number:");  // for replacing just replace the process which we had allocated by 0
                int pagen=s.nextInt();                              //0 in the space means it is free
                if(pagen>=100||pagen<=0)
                    System.out.println("No such processstruct!");
                else
                {
                    if(processstructes[pagen-1].a==null)
                        System.out.println("No such processstruct!");
                    else
                    {
                        HashMap<Integer,Integer> temp;
                        temp=processstructes[pagen-1].a;
                        for(int i=1;i<=processstructes[pagen-1].frame;i++)
                        {
                            if(temp.get(i)!=-1)
                                mem[temp.get(i)]=0;
                        }
                        processstructes[pagen-1].a=null;
                        System.out.println("processstruct killed!");
                    }
                }
                break;
                case 3:         // iterating and printing the dataset
                    for(int p=0;p<100;p++)
                    {
                        HashMap<Integer,Integer> temp=processstructes[p].a;
                        if(temp!=null)
                        {
                            System.out.println("processstruct "+processstructes[p].pagen);
                            for(int i=1;i<=processstructes[p].frame;i++)
                                System.out.println("Page "+i+"\n"+(processstructes[p].a.get(i)+1));
                        }
                    }

                break;
                case 4:
                flag=false;
                break;
                default:System.out.println("Invalid option!");
            }
        }
    }
}
