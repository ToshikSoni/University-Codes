import java.io.*;
import java.util.*;

class Account implements Serializable {
    private int acNo;
    private String acName;
    private double bal;

    public Account(int accountNumber, String accountHolderName, double balance) {
        this.acNo = accountNumber;
        this.acName = accountHolderName;
        this.bal = balance;
    }

    public int getAcNo() {
        return acNo;
    }

    public String getAcName() {
        return acName;
    }

    public double getBal() {
        return bal;
    }

    public void deposit(double amount) {
        bal += amount;
    }

    public void withdraw(double amount) {
        if (bal < amount) {
            System.out.println("Insufficient funds");
            return;
        }
        bal -= amount;
    }
}

class Bank implements Serializable {
    private ArrayList<Account> accounts;

    public Bank() {
        accounts = new ArrayList<Account>();
    }

    public void createAccount(int acNo, String acName, double bal) {
        Account account = new Account(acNo, acName, bal);
        accounts.add(account);
    }

    public Account findAccount(int acNo) {
        for (Account account : accounts)
            if (account.getAcNo() == acNo)
                return account;
        return null;
    }

    public void deposit(int acNo, double amount) {
        Account account = findAccount(acNo);
        if (account != null)
            account.deposit(amount);
        else
            System.out.println("Account not found");
    }

    public void withdraw(int acNo, double amount) {
        Account account = findAccount(acNo);
        if (account != null)
            account.withdraw(amount);
        else
            System.out.println("Account not found");
    }

    public void viewBalance(int anNo) {
        Account account = findAccount(anNo);
        if (account != null)
            System.out.println("Account balance: " + account.getBal());
        else
            System.out.println("Account not found");
    }

    public void saveToFile(String filename) throws IOException {
        ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(filename));
        oos.writeObject(accounts);
        oos.close();
    }

    public void loadFromFile(String filename) throws IOException, ClassNotFoundException {
        ObjectInputStream ois = new ObjectInputStream(new FileInputStream(filename));
        accounts = (ArrayList<Account>) ois.readObject();
        ois.close();
    }
}

public class neww {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Bank bank = new Bank();
        int choice = 0;

        do {
            System.out.print(
                    "1. Create account\n2. Deposit funds\n3. Withdraw funds\n4. View balance\n5. Save accounts to file\n6. Load accounts from file\n0. Exit\nEnter choice: ");
            choice = scanner.nextInt();
            switch (choice) {
                case 1:
                    System.out.print("Enter account number: ");
                    int acNo = scanner.nextInt();
                    System.out.print("Enter account holder name: ");
                    String acNmae = scanner.next();
                    System.out.print("Enter initial balance: ");
                    double bal = scanner.nextDouble();
                    bank.createAccount(acNo, acNmae, bal);
                    break;
                case 2:
                    System.out.print("Enter account number: ");
                    acNo = scanner.nextInt();
                    System.out.print("Enter deposit amount: ");
                    double depAmt = scanner.nextDouble();
                    bank.deposit(acNo, depAmt);
                    break;
                case 3:
                    System.out.print("Enter account number: ");
                    acNo = scanner.nextInt();
                    System.out.print("Enter withdrawal amount: ");
                    double drawAmt = scanner.nextDouble();
                    bank.withdraw(acNo, drawAmt);
                    break;
                case 4:
                    System.out.print("Enter account number: ");
                    acNo = scanner.nextInt();
                    bank.viewBalance(acNo);
                    break;
                case 5:
                    try {
                        System.out.print("Enter filename to save accounts to: ");
                        String filename = scanner.next();
                        bank.saveToFile(filename);
                        System.out.println("Accounts saved to " + filename);
                    } catch (Exception e) {
                        System.out.println(e);
                    }
                    break;
                case 6:
                    try {
                        System.out.print("Enter filename to load accounts from: ");
                        String filename = scanner.next();
                        bank.loadFromFile(filename);
                        System.out.println("Accounts loaded from " + filename);
                    } catch (Exception e) {
                        System.out.println(e);
                    }
                    break;
                case 0:
                    System.out.println("Exiting program");
                    break;
                default:
                    System.out.println("Invalid choice");
                    break;
            }
        } while (choice != 0);
    }
}