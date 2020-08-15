#include <iostream>
#include <map>
#include <list>
#include <fstream>
#include "json-develop/single_include/nlohmann/json.hpp"
using json = nlohmann::json;


namespace BU {
    struct bank{
        long CardNums;
        std::string password;
        std::string legalName;
        std::string accountType;
        int accountBal;
        std::list<std::string> recPayments;
        int accountNum;
        std::map<std::string, std::list<std::string>> transactions;
    };
}


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
    std::string password;
    std::string legalName;
    std::string accountType;
    int accountBal;
    std::list<std::string> recPayments;
    std::map<std::string, std::list<std::string>> transactions;
};


void from_json(const nlohmann::json& userAccount, Bank& bankUser) {
    userAccount.at("accountNumber").get_to(bankUser.CardNums);
    userAccount.at("password").get_to(bankUser.password);
    userAccount.at("legalName").get_to(bankUser.legalName);
    userAccount.at("accountType").get_to(bankUser.accountType);
    userAccount.at("accountBalance").get_to(bankUser.accountBal);
    userAccount.at("reoccurringPayments").get_to(bankUser.recPayments);
    userAccount.at("transactionHistory").get_to(bankUser.transactions);
}

template <typename T, size_t N>
void from_json(const nlohmann::json& userAccount, T (&t)[N]) {
    if (userAccount.size() > N) {
        throw std::runtime_error("JSON array too large");
    }
    size_t index = 0;
    for (auto& item : userAccount) {
        from_json(item, t[index++]);
    }
}

int main() {

    json userAccount;
    std::ifstream userAccountFile("/Users/ranvirsingh/Documents/GitHub/BankingApplication/userAccounts.json");
    userAccount = json::parse(userAccountFile);

    Bank parsed[2];
    from_json(userAccount, parsed);

    auto testDump = userAccount["members"].get<std::array<Bank, 2>>();


    std::cout << testDump;


    return 0;
}

