#ifndef CARD_H_
#define CARD_H_
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
class abstr_card
{
protected:
    char name[30];
    int num;
    double interest;
    char password[7];
    bool valid;

public:
    abstr_card(const char *n, int no, const char *p, bool i = 1);
    abstr_card() {}
    void ShowData();
    bool deposit(double amount);
    bool withdraw(double amount);
    void changepassword(const char *p);
    bool isvalid() { return valid; }
    bool setvalid(bool i)
    {
        valid = i;
        return valid;
    }
    const char *getpassword() { return password; }
    const int getnum() { return num; }
    double getinterest() { return interest; }
};
class campus_card : public abstr_card
{
private:
    int bind[3];

public:
    campus_card(const char *n, int no, const char *p, bool i = 1);
    campus_card() {}
    void ShowData();
    bool binding(int num);
    bool debinding(int num);
    const int *getbind() { return bind; }
};
class bank_card : public abstr_card
{
private:
    int limit;

public:
    bank_card(const char *n, int no, const char *p, bool i = 1, int l = 0) : abstr_card(n, no, p, i), limit(l) {}
    bank_card() {}
    void ShowData();
    double maxium() { return limit + interest; }
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
    cout << "Password:" << password << endl;
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
void abstr_card::changepassword(const char *p)
{
    strcpy(password, p);
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