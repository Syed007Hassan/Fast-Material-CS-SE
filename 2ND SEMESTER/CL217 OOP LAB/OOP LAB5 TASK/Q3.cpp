#include <iostream>

using namespace std;

class Account{
	private:
		int account_no;
		double account_bal;
		int security_code;
	public:
		input() {
			account_no=1;
			account_bal=6000;
			security_code=2975;
		}
		acc()
		{
			cout << "\nAccount Number: " << account_no;
			cout << "\nAccount Balance: " << account_bal;
			cout << "\nSecurity Code: " << security_code;
		}	
};

main()
{
	Account a;
	a.input();
	a.acc();
}
