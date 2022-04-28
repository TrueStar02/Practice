#ifndef CARD_H_
#define CARD_H_
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
class abstr_card
{
protected:
    char name[30]; //The name of the owner
    int num;       //The card number,10000000~49999999 are campus card.50000000~99999999 are bank card
    double interest;
    char password[7];
    bool valid; //Is it valid?

public:
    abstr_card(const char *n, int no, const char *p, bool i = 1); //Useful constructor
    abstr_card() {}                                               //Default constructor
    void ShowData();                                              //Print the user information
    bool deposit(double amount);
    bool withdraw(double amount);
    void changepassword(const char *p) { strcpy(password, p); }
    bool isvalid() { return valid; }
    bool setvalid(bool i);
    const char *getpassword() { return password; }
    const int getnum() { return num; }
    double getinterest() { return interest; }
};
class campus_card : public abstr_card
{
private:
    int bind[3]; //You can bind at most 3 bank cards

public:
    campus_card(const char *n, int no, const char *p, bool i = 1); //Useful constructor
    campus_card() {}                                               //Default constructor
    void ShowData();                                               //Print the user information
    bool binding(int num);                                         //Bind a bank card
    bool debinding(int num);                                       //Debind a bank card
    const int *getbind() { return bind; }                          //Get a pointer to the bank card has been binded
};
class bank_card : public abstr_card
{
private:
    int limit; //Overdraft limit

public:
    bank_card(const char *n, int no, const char *p, bool i = 1, int l = 0) : abstr_card(n, no, p, i), limit(l) {} //Useful constructor
    bank_card() {}                                                                                                //Default constructor
    void ShowData();                                                                                              //Print the user information
    double maxium() { return limit + interest; }
    int getlimit() { return limit; } //Get the maxium money can be used
    void changelimit(int i) { limit = i; }
};
abstr_card::abstr_card(const char *n, int no, const char *p, bool i) : num(no), interest(0), valid(i)
{
    strcpy(name, n);
    strcpy(password, p);
}
void abstr_card::ShowData()
{
    cout << "Account Number:" << num << endl;
    cout << "Name:" << name << endl;
    cout << "Interest:" << interest << endl;
}
bool abstr_card::deposit(double amount)
{
    if (amount > 0)
    {
        interest += amount;
        return 1;
    }
    else
        return 0;
}
bool abstr_card::withdraw(double amount)
{
    interest -= amount;
    return 1;
}
bool abstr_card::setvalid(bool i)
{
    valid = i;
    return valid;
}
campus_card::campus_card(const char *n, int no, const char *p, bool i) : abstr_card(n, no, p, i)
{
    bind[0] = bind[1] = bind[2] = 0;
}
void campus_card::ShowData()
{
    abstr_card::ShowData();
    cout << "Binding:";
    bool i = 0;
    int x;
    for (x = 0; x < 3; x++)
        if (bind[x])
        {
            cout << bind[x] << " ";
            i = 1;
        }
    if (!i)
        cout << "None";
    cout << endl;
}
bool campus_card::binding(int num)
{
    int x;
    for (x = 0; x < 3; x++)
        if (!bind[x])
        {
            bind[x] = num;
            return 1;
        }
    return 0;
}
bool campus_card::debinding(int num)
{
    int x;
    for (x = 0; x < 3; x++)
        if (bind[x] == num)
        {
            bind[x] = 0;
            return 1;
        }
    return 0;
}
void bank_card::ShowData()
{
    abstr_card::ShowData();
    cout << "Overdraft limit:" << limit << endl;
}
#endif