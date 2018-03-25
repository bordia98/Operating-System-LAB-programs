import java.rmi.*;  

interface Adder extends Remote{  

	public int add(int x,int y)throws RemoteException;  
}  
