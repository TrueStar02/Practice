#include "account.h"

#include <iostream>
using namespace std;
int main() {
    Account account = Account();
    int id, op;
    cin >> id;
    account.setId(id);
    double x;
    cout << account.getId() << endl;
    while (cin >> op) {
        if (op < 4) cin >> x;
        switch (op) {
        case 0:  // withdraw
            account.withDraw(x);
            break;
        case 1:  //deposit
            account.deposit(x);
            break;
        case 2:  //setAnnualInterestRate
            account.setAnnualInterestRate(x);
            break;
        case 3:  //setBalance
            account.setBalance(x);
            break;
        case 4:  //getAnnualInterestRate
            cout << account.getAnnualInterestRate() << endl;
            break;
        case 5:  //getMonthlyInterestRate
            cout << account.getMonthlyInterestRate() << endl;
            break;
        }
        cout << account.getBalance() << endl;
    }
}