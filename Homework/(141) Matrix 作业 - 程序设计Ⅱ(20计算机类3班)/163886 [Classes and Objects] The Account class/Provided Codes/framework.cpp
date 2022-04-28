#include <iomanip>
#include <iostream>

#include "source.h"
using namespace std;
void print(const Account& account) {
    cout << "Account ID " << account.getId()
         << fixed << setprecision(2)
         << ", Balance " << account.getBalance() << ", Monthly Interest Rate " << account.getMonthlyInterestRate() << endl;
}
int main() {
    Account a, b;
    print(a);

    b.setId(1122);
    b.setBalance(20000.0);
    b.setAnnualInterestRate(4.5);
    print(b);

    return 0;
}
