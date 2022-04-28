// Problem#: 17645
// Submission#: 4642239
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string>
using namespace std;

class Account {
private:
    int id;
    double balance, annualInterestRate;

public:
    Account(int ID = 0, double BALANCE = 0, double AnnualInterestRate = 0) {
        id = ID;
        balance = BALANCE;
        annualInterestRate = AnnualInterestRate;
    }
    int getId() const {
        return id;
    }
    double getBalance() const {
        return balance;
    }
    double getAnnualInterestRate() const {
        return annualInterestRate;
    }

    void setId(int ID) {
        id = ID;
    }
    void setBalance(double Balance) {
        balance = Balance;
    }
    void setAnnualInterestRate(double AnnualInterestRate) {
        annualInterestRate = AnnualInterestRate;
    }

    double getMonthlyInterestRate() const {
        return annualInterestRate / 12;
    }
    void withDraw(double amount) {
        balance -= amount;
        if (balance < 0) balance = 0;
    }
    void deposit(double amount) {
        balance += amount;
    }
};
