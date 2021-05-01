/* Do Programming Project 2 on page 611. You may watch the video note for
 * Programming Project 1 on page 611 to get some idea. Then try to finish
 * independently by complete this sample file.
 *
 * Author: Steve Ubert
 * Version: 2/3/2021
 */


#include <iostream>
using namespace std;

class CDAccount
{
public:

    CDAccount();
    CDAccount(double new_balance, double new_interest_rate, int new_term);
    double get_initial_balance() const;
    double get_balance_at_maturity() const;
    double get_interest_rate() const;
    int get_term() const;
    void input(istream& in);
    void output(ostream& out);

private:

    int dollar;
    int cent;
    double interest_rate;
    //  in months until maturity
    int term; 
};

int main()
// You implement the test code here
 // You may watch the video note to get the idea
 // notice that user will only enter balance as a double value
 // You may implement it as a menu oriented testing program
 // which be able to test constructors, methods of CDAccount class
{
    //created object
    CDAccount account;
    //getting input from user
    account.input(cin);
    //displaying the value
    account.output(cout);
  
}

// Implement the class definition here. Notice that the interfaces are the
// same as in Programming Project 1. However, the implementation will be
// different since the private information balance is stored differently
// for example, the input function will only read the balance, itnerest rate
// and term from the user. So it should be modified as following

//empty constructor
CDAccount::CDAccount() {
}

CDAccount::CDAccount(double new_balance, double new_interest_rate, int new_term)
{
    dollar = (int)new_balance;
    cent = (int)((new_balance - dollar) * 100);
    interest_rate = new_interest_rate / 100;
    term = new_term;
}

void CDAccount::input(istream& in)
{
    // get initial balance from user
    double balance;
    cout << "Enter balance : ";
    in >> balance; 


    // convert balance to dollars and cents since this is how balance stored

    // dollar is the interger part of balace
    dollar = (int)balance; 
    
    // cent is the fraction part * 100
    cent = (int)((balance - dollar) * 100); 
    

    // get interest rate from user
    cout << "Enter interest rate : ";
    in >> interest_rate; 
    
    //storing the interest as decimal
    interest_rate = interest_rate / 100;

    // get term from user
    cout << "Enter Term (in months): ";
    in >> term; 
    
}

double CDAccount::get_initial_balance() const
{
    return (double)((double)dollar + (double)((double)cent / 100.0));
}

double CDAccount::get_interest_rate() const
{
    return interest_rate;
}

double CDAccount::get_balance_at_maturity() const
{
    double amount = dollar + (cent / 100);
    return get_initial_balance() + amount * interest_rate * term;
}

int CDAccount::get_term() const
{
    return term;
}

void CDAccount::output(ostream& out)
{
    //This acts as the user interface
    out << "balance : " << get_initial_balance() << endl;
    out << "Interest Rate : " << get_interest_rate() << endl;
    out << "Term : " << get_term() << endl;
    out << "balance at matuarity : " << get_balance_at_maturity() << endl;
}

