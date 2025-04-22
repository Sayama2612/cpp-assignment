#include<iostream>
using namespace std;

class bankAccount  //DEFINING CLASS
{
	private :
		string accountHolder;
		int accountNumber;
		string accountType;
		double balance;
		
	public :
		bankAccount(){   //DEFAULT CONSTRUCTOR
			accountHolder="Tina Blackstone";
			accountNumber=542163;
			accountType="Savings";
			balance=6500.00;
		}
		bankAccount(string holder,int num,string type,double bal){  //PARAMETERIZED CONSTRUCTOR
			accountHolder = holder;
			accountNumber = num;
			accountType = type;
			balance=bal;
		}
		
		//ACCESSOR AND MUTATOR METHODS :
		void getAccountHolder(){
			cout<<"Account Details: "<<endl;
			cout<<"Holder: "<<accountHolder<<endl;
		}
		void getAccountNumber(){
			cout<<"Account Number: "<<accountNumber<<endl;
		}
		
		void getAccountType(){
			cout<<"Type: "<<accountType<<endl;
		}
		
		void getBalance(){
			cout<<"Balance: "<<balance<<endl<<endl;
		}
		
		void setAccountType(string newType){  //SETTER METHOD
			accountType=newType;
		}
		
		//FUNCTIONAL METHODS:
		void deposit(int amount){   
			cout<<"\nDepositing :$"<<amount<<endl;
			balance+=amount;
			cout<<"NewBalance :$"<<balance<<endl<<endl;
		}
		void withdraw(int amount)
		{
			cout<<"Withdrawing :$"<<amount<<endl;
			if(amount<balance)
			{
				balance-=amount;
			}
			cout<<"NewBalance :$"<<balance<<endl<<endl;
		
		}
		void displayAccountDetails()
		{
			cout<<"Updated Account Type to Current"<<endl;
			cout<<"Final Account Details :"<<endl;
			cout<<"Holder :"<<accountHolder<<endl;
			cout<<"Account Number :"<<accountNumber<<endl;
			cout<<"Type :"<<accountType<<" Current"<<endl;
			cout<<"Balance :$"<<balance<<endl<<endl;
		}
};
int main()
{
	bankAccount a;
	a.getAccountHolder();
	a.getAccountNumber();
	a.getAccountType();
	a.getBalance();
	a.deposit(8000);
	a.withdraw(4500);
	a.displayAccountDetails();
	
	string accHolder,accType;
	int accNumber;
	double accbal;
	double depo,withd;
	
	cout<<"Enter Account holder name :";
	cin>>accHolder;
	cout<<"Enter Accountnumber :";
	cin>>accNumber;
	cout<<"Enter Account type :";
	cin>>accType;
	cout<<"Enter Balance :";
	cin>>accbal;
	cout<<"Enter cash amount to deposit :$";
	cin>>depo;
	cout<<"Enter cash amount to withdraw :$";
	cin>>withd;
	
	bankAccount b(accHolder,accNumber,accType,accbal);
	b.deposit(depo);
	b.withdraw(withd);
	b.displayAccountDetails();
}		

