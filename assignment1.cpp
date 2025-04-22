#include<iostream>
using namespace std;
struct transaction
{
	string type; //deposit or withdraw
	int amount;
	int balance_after;	
};
int main()
{
	int current_balance = 1000;
	int choice,amount;
	int ans = 1;
	int transaction_count=0;
	struct transaction history[100];
	do
	{
		cout<<"\nBank Menu";
		cout<<"\n1. Check Balance";
		cout<<"\n2. Deposit";
		cout<<"\n3. Withdraw";
		cout<<"\n4. Transaction";
		cout<<"\n5. Exit";
		cout<<"\nEnter your choice :";
		cin>>choice;
		
		switch(choice)
		{
			case 1:	cout<<"\nCurrent Balance :$"<<current_balance<<endl;
					break;
			case 2:	cout<<"\nEnter deposit amount :$";
					cin>>amount;
					current_balance += amount;
					history[transaction_count++] = {"Deposit",amount,current_balance};
					cout << "\nDeposit successful. New balance: $" << current_balance << endl;
					break;
			case 3:	cout<<"\nEnter withdrawal amount :$";
					cin>>amount;
					if(current_balance >= amount)
					{
						current_balance -= amount;
						history[transaction_count++] = {"Withdraw",amount,current_balance};
						cout << "Withdrawal successful. New balance: $" << current_balance << endl;
					}
					else
						cout<<"\nInsufficient balance";	
					break;
			case 4: cout << "\nTransaction History:";
	                if (transaction_count == 0) {
	                    cout << "\nNo transactions yet."<<endl;
	                } else {
	                    for (int i = 0; i < transaction_count; ++i) {
	                        cout << "\n" << i + 1 << ". " << history[i].type
	                             << " of " << history[i].amount
	                             << ", Balance after: " << history[i].balance_after<<endl;
	                    }
	                }
	                break;		
			case 5:	cout<<"\nYou have exited..."<<endl;
					break;
			default :cout<<"\nInvalid choice. Please try again"<<endl;
		}
		
	}while(choice <= 4);
	return 0;
}
