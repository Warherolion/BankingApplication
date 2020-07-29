#include <iostream>
#include <map>
#include <list>
#include "json-develop/single_include/nlohmann/json.hpp"
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
    long CardNums;
    string password;
    string legalName;
    string accountType;
    int accountBal;
    list<string> recPayments;
    int accountNum;
    map<string, list<string>> transactions;
};

bool userLogged = false;



void login(){

}
void AdminLogin(){

}
//Used if userLogged is false meaning the user is logged out
int loginMenu(){
    int userChoice;
    cout << "You are not logged in, please pick on of the options below" << endl;
    cout << "1. Bank user login" << endl;
    cout << "2. Bank representative login" << endl;

    cout << "Please enter a selection: ";
    cin >> userChoice;


    try {
        if (userChoice == 1){
            login();
        }else if (userChoice == 2){
            AdminLogin();
        } else {
            cout << "Please enter a valid entry";
            cin >> userChoice;
        }
    } catch (...) {
        cout << "Please enter a valid input";
    }

    return userChoice;
}

//Used if the user has logged in
void userMenu(){

}

void loggedCheck(){
    if (!userLogged){
        loginMenu();
    }else if (userLogged){
        userMenu();
    }
}

int main() {
    loggedCheck();
    return 0;
}

