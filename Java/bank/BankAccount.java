package Java.bank;

public class BankAccount {
	private String accountHolder;
	private double balance;
	
	public BankAccount() {
		
	}
	
	public BankAccount(String accountHolder) {
		if(accountHolder == null) {
			System.out.println("Enter a new accountHolder!");
			return;
		}
		setAccountHolder(accountHolder);
		setBalance(0);
		System.out.println("Create account success, Welcome "+getAccountHolder());
	}
	
	public BankAccount(String accountHolder, double balance) {
		if(accountHolder == null) {
			System.out.println("Enter a new accountHolder!");
			return;
		}
		setAccountHolder(accountHolder);
		setBalance(balance);
		System.out.println("Create account success, Welcome "+getAccountHolder());
	}
	
	public String getAccountHolder() {
		if(this.accountHolder == null) {
			System.out.println("You shuld create account first");
			return "";
		}
		return accountHolder;
	}
	public double getBalance() {
		if(this.accountHolder == null) {
			System.out.println("You shuld create account first");
			return 0;
		}
		return balance;
	}
	
	private void setAccountHolder(String accountHolder) {
		this.accountHolder = accountHolder;
	}
	private void setBalance(double balance) {
		if(balance < 0) {
			System.out.println("Plese enter a valid data!");
			return;
		}
		this.balance = balance;
	}
	
	public void deposit(double amount) {
		if(this.accountHolder == null) {
			System.out.println("You shuld create account first");
			return;
		}
		if(amount <= 0) {
			System.out.println("Plese enter a valid data!");
			return;
		}
		System.out.println("Deposit "+amount+" Bath success");
		this.balance+=amount;
	}
	
	public double withdraw(double amount) {
		if(this.accountHolder == null) {
			System.out.println("You shuld create account first");
			return 0;
		}
		if(amount <= 0) {
			System.out.println("Plese enter a valid data!");
			return 0;
		}
		if(this.balance - amount < 0) {
			System.out.println("You have a money just"+getBalance());
			return 0;
		}
		this.balance-=amount;
		System.out.println("Withdraw "+amount+" Bath success");
		return amount;
	}
	
	public void showInfo() {
		if(this.accountHolder == null) {
			System.out.println("You shuld create account first");
			return;
		}
		System.out.println("AccountHolder Name: "+getAccountHolder());
		System.out.println("Balance: "+getBalance()+" Bath");
	}
}

