package Java.bank;

public class Main {

	public static void main(String[] args) {
		BankAccount ac1 = new BankAccount("Ac01", 10);
		ac1.showInfo();
		
		ac1.deposit(100.25);
		System.out.println("Balance"+ac1.getBalance());
		
		ac1.withdraw(20);
		System.out.println("Balance"+ac1.getBalance());
		
		ac1.showInfo();
		
//		BankAccount ac2 = new BankAccount("Ac02");
//		ac2.showInfo();
//		
//		ac2.deposit(100);
//		System.out.println("Balance"+ac2.getBalance());
//		
//		ac2.withdraw(20);
//		System.out.println("Balance"+ac2.getBalance());
//		
//		ac2.showInfo();
	}

}
