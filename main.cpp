#include <iostream>
#include <map>
#include <list>
using namespace std;


/*
 * based on bank application idea from the internet,
 *  Plan -> Require authentication or master password for managing accounts, or individual account login key
 *  menu has all the options for people loging into individual accounts this includes, Create new account etransfer,
 *  and other related things, this is all based of arrays and structures for c++
 * All the aspects that go into a bank account:
 * userName (string) and password (string), legal name (string), account number (int), Account Type [chequing or savings] (String), Account balance [total and divided over accounts]
 * Active reoccurring payments (), bank card numbers with related type and name (list), transaction history (hashmap),
 *
*/

struct Bank{
    string userName;
    string password;
    string legalName;
    int accountNum;
    string accountType;
    map<string, int> accountBal;
    list<string> recPayments;
    map<string, int> CardNums;
    map<string, list<string>> transactions;
};

map<int, Bank> AccountMap;

int main() {




    return 0;
}

void createNewAccount(){
    cout << "Please enter your user name" << endl;

    



    AccountMap.size();


}