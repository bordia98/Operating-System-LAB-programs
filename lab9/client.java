import java.rmi.*;  
import java.util.Scanner;
class MyClient{  
	public static void main(String args[]){  
		try{  
			Adder stub=(Adder)Naming.lookup("rmi://localhost:5000/sonoo");  
			System.out.println("Enter two integeal numbers you want to add");
			int a, b;
			Scanner sc = new Scanner(System.in);
			a = sc.nextInt();
			b = sc.nextInt();
			System.out.println("The sum of two numbers is :");
			System.out.println(stub.add(a,b));  
		}catch(Exception e){
			System.out.println("Exception caused while running");
		}	  
	}  
}  
