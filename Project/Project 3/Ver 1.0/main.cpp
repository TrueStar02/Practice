#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include <cstdio>
#include "card.h"
#include "log.h"
using namespace std;
const double eps = 1e-5;
int LogIn(fstream &bank_obj, fstream &camp_obj, fstream &log_obj);
char bank_menu(int account);
char camp_menu(int account);
char bank_admin_menu();
char campus_admin_menu();
void BankDeposit(int account, fstream &bank_obj, fstream &camp_obj, fstream &log_obj);
void CampusDeposit(int account, fstream &bank_obj, fstream &camp_obj, fstream &log_obj);
void DepositByBank(int account, fstream &bank_obj, fstream &camp_obj, fstream &log_obj);
void Withdraw(int account, fstream &bank_obj, fstream &camp_obj, fstream &log_obj);
void Pay(int account, fstream &bank_obj, fstream &camp_obj, fstream &log_obj);
void Transfer(int account, fstream &bank_obj, fstream &camp_obj, fstream &log_obj);
void ChangeBankPassword(int account, fstream &bank_obj, fstream &camp_obj, fstream &log_obj);
void ChangeCampusPassword(int account, fstream &bank_obj, fstream &camp_obj, fstream &log_obj);
void ShowLogs(int account, fstream &bank_obj, fstream &camp_obj, fstream &log_obj);
void ShowAllBankLogs(fstream &bank_obj, fstream &camp_obj, fstream &log_obj);
void ShowAllCampusLogs(fstream &bank_obj, fstream &camp_obj, fstream &log_obj);
void ShowCertainBankLogs(fstream &bank_obj, fstream &camp_obj, fstream &log_obj);
void ShowCertainCampusLogs(fstream &bank_obj, fstream &camp_obj, fstream &log_obj);
void BankDetails(int account, fstream &bank_obj, fstream &camp_obj, fstream &log_obj);
void CampusDetails(int account, fstream &bank_obj, fstream &camp_obj, fstream &log_obj);
void BindCard(int account, fstream &bank_obj, fstream &camp_obj, fstream &log_obj);
void DebindCard(int account, fstream &bank_obj, fstream &camp_obj, fstream &log_obj);
void AddBankAccount(fstream &bank_obj, fstream &camp_obj, fstream &log_obj);
void AddCampusAccount(fstream &bank_obj, fstream &camp_obj, fstream &log_obj);
void DeleteBankAccount(fstream &bank_obj, fstream &camp_obj, fstream &log_obj);
void DeleteCampusAccount(fstream &bank_obj, fstream &camp_obj, fstream &log_obj);
void PrintBankInfo(fstream &bank_obj, fstream &camp_obj, fstream &log_obj);
void PrintCampusInfo(fstream &bank_obj, fstream &camp_obj, fstream &log_obj);
void LoadBankAccount(fstream &bank_obj, fstream &camp_obj, fstream &log_obj);
void LoadCampusAccount(fstream &bank_obj, fstream &camp_obj, fstream &log_obj);
int GetInt(void);
double GetDouble(void);
const char *GetPassword(void);
const char *SetPassword(void);
bool confirm(void);
void escape(void);
void Star();
int main()
{
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.precision(2);
    fstream bank_obj("bank.txt", ios_base::in | ios_base::out | ios_base::binary);
    fstream camp_obj("campus.txt", ios_base::in | ios_base::out | ios_base::binary);
    fstream log_obj("log.txt", ios_base::in | ios_base::out | ios_base::binary);
    bank_card bc;
    bank_obj.read((char *)(&bc), sizeof(bank_card));
    if (bank_obj.eof())
    {
        bc = bank_card("Administrator", 88888888, "000000");
        bank_obj.clear();
        bank_obj.seekg(0);
        bank_obj.write((char *)(&bc), sizeof(bank_card));
        log ltemp(88888888, 23, 0, 0, 0);
        log_obj.seekg(0, ios_base::end);
        log_obj.write((char *)(&ltemp), sizeof(log));
    }
    campus_card cc;
    camp_obj.read((char *)(&cc), sizeof(campus_card));
    if (camp_obj.eof())
    {
        cc = campus_card("Administrator", 44444444, "000000");
        camp_obj.clear();
        camp_obj.seekg(0);
        camp_obj.write((char *)(&cc), sizeof(campus_card));
        log ltemp(44444444, 28, 0, 0, 0);
        log_obj.seekg(0, ios_base::end);
        log_obj.write((char *)(&ltemp), sizeof(log));
    }
    int account;
    char ch;
    while (account = LogIn(bank_obj, camp_obj, log_obj))
    {
        if (account == 88888888)
        {
            while ((ch = bank_admin_menu()) != 'q')
            {
                switch (ch)
                {
                case 'a':
                    AddBankAccount(bank_obj, camp_obj, log_obj);
                    break;
                case 'b':
                    DeleteBankAccount(bank_obj, camp_obj, log_obj);
                    break;
                case 'c':
                    PrintBankInfo(bank_obj, camp_obj, log_obj);
                    break;
                case 'd':
                    LoadBankAccount(bank_obj, camp_obj, log_obj);
                    break;
                case 'e':
                    ChangeBankPassword(88888888, bank_obj, camp_obj, log_obj);
                    break;
                case 'f':
                    ShowLogs(88888888, bank_obj, camp_obj, log_obj);
                    break;
                case 'g':
                    ShowAllBankLogs(bank_obj, camp_obj, log_obj);
                    break;
                case 'h':
                    ShowCertainBankLogs(bank_obj, camp_obj, log_obj);
                    break;
                default:
                    cout << "Coming Soon~\n";
                }
            }
        }
        else if (account == 44444444)
        {
            while ((ch = campus_admin_menu()) != 'q')
            {
                switch (ch)
                {
                case 'a':
                    AddCampusAccount(bank_obj, camp_obj, log_obj);
                    break;
                case 'b':
                    DeleteCampusAccount(bank_obj, camp_obj, log_obj);
                    break;
                case 'c':
                    PrintCampusInfo(bank_obj, camp_obj, log_obj);
                    break;
                case 'd':
                    LoadCampusAccount(bank_obj, camp_obj, log_obj);
                    break;
                case 'e':
                    ChangeCampusPassword(44444444, bank_obj, camp_obj, log_obj);
                    break;
                case 'f':
                    ShowLogs(44444444, bank_obj, camp_obj, log_obj);
                    break;
                case 'g':
                    ShowAllCampusLogs(bank_obj, camp_obj, log_obj);
                    break;
                case 'h':
                    ShowCertainCampusLogs(bank_obj, camp_obj, log_obj);
                    break;
                default:
                    cout << "Coming Soon~\n";
                }
            }
        }
        else if (account >= 50000000)
        {
            while ((ch = bank_menu(account)) != 'q')
            {
                switch (ch)
                {
                case 'a':
                    BankDeposit(account, bank_obj, camp_obj, log_obj);
                    break;
                case 'b':
                    Withdraw(account, bank_obj, camp_obj, log_obj);
                    break;
                case 'c':
                    Transfer(account, bank_obj, camp_obj, log_obj);
                    break;
                case 'd':
                    ChangeBankPassword(account, bank_obj, camp_obj, log_obj);
                    break;
                case 'e':
                    BankDetails(account, bank_obj, camp_obj, log_obj);
                    break;
                case 'f':
                    ShowLogs(account, bank_obj, camp_obj, log_obj);
                    break;
                default:
                    cout << "Coming Soon~\n";
                }
            }
        }
        else if (account >= 10000000)
        {
            while ((ch = camp_menu(account)) != 'q')
            {
                switch (ch)
                {
                case 'a':
                    CampusDeposit(account, bank_obj, camp_obj, log_obj);
                    break;
                case 'b':
                    DepositByBank(account, bank_obj, camp_obj, log_obj);
                    break;
                case 'c':
                    Pay(account, bank_obj, camp_obj, log_obj);
                    break;
                case 'd':
                    BindCard(account, bank_obj, camp_obj, log_obj);
                    break;
                case 'e':
                    DebindCard(account, bank_obj, camp_obj, log_obj);
                    break;
                case 'f':
                    ChangeCampusPassword(account, bank_obj, camp_obj, log_obj);
                    break;
                case 'g':
                    CampusDetails(account, bank_obj, camp_obj, log_obj);
                    break;
                case 'h':
                    ShowLogs(account, bank_obj, camp_obj, log_obj);
                    break;
                default:
                    cout << "Coming Soon~\n";
                }
            }
        }
        else
            cout << "Error!\n";
    }
    cout << "Thanks for using the system!\n";
    cout << "Bye~\n";
    bank_obj.close();
    camp_obj.close();
    log_obj.close();
    return 0;
}
int LogIn(fstream &bank_obj, fstream &camp_obj, fstream &log_obj)
{
    Star();
    cout << "Log in\n";
    char ch;
    string pass;
    int number;
    while (1)
    {
        cout << "Please Enter the user number,0 to quit\n";
        cin >> number;
        if (number >= 50000000)
        {
            bank_card t;
            bank_obj.clear();
            bank_obj.seekg(0);
            while (bank_obj.read((char *)(&t), sizeof(bank_card)))
                if (t.isvalid() && t.getnum() == number)
                    break;
            if (t.getnum() == number)
            {
                pass = string(t.getpassword());
                break;
            }
            cout << "No found!\n";
        }
        else if (number >= 10000000)
        {
            campus_card t;
            camp_obj.clear();
            camp_obj.seekg(0);
            while (camp_obj.read((char *)(&t), sizeof(campus_card)))
                if (t.isvalid() && t.getnum() == number)
                    break;
            if (t.getnum() == number)
            {
                pass = string(t.getpassword());
                break;
            }
            cout << "No found!\n";
        }
        else if (number == 0)
        {
            cout << "Exit the system!\n";
            return 0;
        }
        else
            cout << "Invalid Number!\n";
    }
    if (number)
    {
        cout << "Enter the password or enter \"quit\" to exit\n";
        string temp = "";
        while (1)
        {
            temp = GetPassword();
            if (temp == pass) //If the password is right
                break;
            else if (temp == "quit") //If you want to quit
            {
                number = 0;
                break;
            }
            else //If you're wrong
                cout << "You're wrong!\n";
        }
    }
    return number;
}
char bank_menu(int account)
{
    Star();
    char v;
    cout << "Type:Bank Account\n";
    cout << "Account:" << account << endl;
    cout << "Choose Function:\n";
    cout << "A-Deposit\n";
    cout << "B-Withdraw\n";
    cout << "C-Transfer\n";
    cout << "D-Change Password\n";
    cout << "E-Show Details\n";
    cout << "F-Show Logs\n";
    cout << "Q-quit\n";
    cout << "Your Choice:";
    while ((v = tolower(cin.get())) && strchr("abcdefq", v) == NULL)
    {
        cout << "Enter A~F or Q!";
        cin.ignore(999, '\n');
    }
    cin.ignore(999, '\n');
    return v;
}
char camp_menu(int account)
{
    Star();
    char v;
    cout << "Type:Campus Account\n";
    cout << "Account:" << account << endl;
    cout << "Choose Function:\n";
    cout << "A-Deposit by cash\n";
    cout << "B-Deposit by bank card\n";
    cout << "C-Pay\n";
    cout << "D-Bind bank card\n";
    cout << "E-Debind bank card\n";
    cout << "F-Change Password\n";
    cout << "G-Show Details\n";
    cout << "H-Show Logs\n";
    cout << "Q-quit\n";
    cout << "Your Choice:";
    while ((v = tolower(cin.get())) && strchr("abcdefghq", v) == NULL)
    {
        cout << "Enter A~H or Q!";
        cin.ignore(999, '\n');
    }
    cin.ignore(999, '\n');
    return v;
}
char bank_admin_menu()
{
    Star();
    char v;
    cout << "Type:Bank Administrator\n";
    cout << "Account:88888888\n";
    cout << "Choose Function:\n";
    cout << "A-Add an account\n";
    cout << "B-Delete an account\n";
    cout << "C-Print information of one user\n";
    cout << "D-Load new account from file\n";
    cout << "E-Change Password\n";
    cout << "F-Show Logs\n";
    cout << "G-Show all bank logs\n";
    cout << "H-Print logs of one user\n";
    cout << "Q-quit\n";
    cout << "Your Choice:";
    while ((v = tolower(cin.get())) && strchr("abcdefghq", v) == NULL)
    {
        cout << "Enter A~H or Q!";
        cin.ignore(999, '\n');
    }
    cin.ignore(999, '\n');
    return v;
}
char campus_admin_menu()
{
    Star();
    char v;
    cout << "Type:Campus Administrator\n";
    cout << "Account:44444444\n";
    cout << "Choose Function:\n";
    cout << "A-Add an account\n";
    cout << "B-Delete an account\n";
    cout << "C-Print information of one user\n";
    cout << "D-Load new account from file\n";
    cout << "E-Change Password\n";
    cout << "F-Show Logs\n";
    cout << "G-Show all campus logs\n";
    cout << "H-Print logs of one user\n";
    cout << "Q-quit\n";
    cout << "Your Choice:";
    while ((v = tolower(cin.get())) && strchr("abcdefghq", v) == NULL)
    {
        cout << "Enter A~H or Q!";
        cin.ignore(999, '\n');
    }
    cin.ignore(999, '\n');
    return v;
}
void BankDeposit(int account, fstream &bank_obj, fstream &camp_obj, fstream &log_obj)
{
    Star();
    cout << "Type:Bank Account\n";
    cout << "Account:" << account << endl;
    cout << "Function:Deposit\n";
    cout << "Enter the amount you wants to deposit:";
    double amount;
    bank_card temp;
    while ((amount = GetDouble()) < eps)
    {
        cout << "Money should be positive!\n";
        cout << "Enter the amount you wants to deposit:";
    }
    bank_obj.clear();
    bank_obj.seekg(0);
    while (bank_obj.read((char *)(&temp), sizeof(bank_card)))
        if (temp.getnum() == account)
            break;
    temp.deposit(amount);
    bank_obj.clear();
    if (confirm())
    {
        bank_obj.seekg(-sizeof(bank_card), ios_base::cur);
        bank_obj.write((char *)(&temp), sizeof(bank_card));
        cout << "Succeess!\n";
        cout << "Interest:" << temp.getinterest() << endl;
        log ltemp(account, 1, 0, amount, temp.getinterest());
        log_obj.clear();
        log_obj.seekg(0, ios_base::end);
        log_obj.write((char *)(&ltemp), sizeof(log));
    }
    else
        cout << "Cancelled\n";
    escape();
}
void CampusDeposit(int account, fstream &bank_obj, fstream &camp_obj, fstream &log_obj)
{
    Star();
    cout << "Type:Campus Account\n";
    cout << "Account:" << account << endl;
    cout << "Function:Deposit\n";
    cout << "Enter the amount you wants to deposit:";
    double amount;
    campus_card temp;
    while ((amount = GetDouble()) < eps)
    {
        cout << "Money should be positive!\n";
        cout << "Enter the amount you wants to deposit:";
    }
    camp_obj.clear();
    camp_obj.seekg(0);
    while (camp_obj.read((char *)(&temp), sizeof(campus_card)))
        if (temp.getnum() == account)
            break;
    temp.deposit(amount);
    camp_obj.clear();
    if (confirm())
    {
        camp_obj.seekg(-sizeof(campus_card), ios_base::cur);
        camp_obj.write((char *)(&temp), sizeof(campus_card));
        cout << "Success!\n";
        cout << "Interest:" << temp.getinterest() << endl;
        log ltemp(account, 10, 0, amount, temp.getinterest());
        log_obj.clear();
        log_obj.seekg(0, ios_base::end);
        log_obj.write((char *)(&ltemp), sizeof(log));
    }
    else
        cout << "Cancelled\n";
    escape();
}
void DepositByBank(int account, fstream &bank_obj, fstream &camp_obj, fstream &log_obj)
{
    Star();
    cout << "Type:Campus Account\n";
    cout << "Account:" << account << endl;
    cout << "Function:Deposit\n";
    cout << "Enter the amount you wants to deposit:";
    double amount;
    campus_card temp;
    while ((amount = GetDouble()) < eps)
    {
        cout << "Money should be positive!\n";
        cout << "Enter the amount you wants to deposit:";
    }
    camp_obj.clear();
    camp_obj.seekg(0);
    while (camp_obj.read((char *)(&temp), sizeof(campus_card)))
        if (temp.getnum() == account)
            break;
    camp_obj.clear();
    const int *bind = temp.getbind();
    int x;
    bank_card bktemp;
    for (x = 0; x < 3; x++)
    {
        bank_obj.clear();
        bank_obj.seekg(0);
        while (bank_obj.read((char *)(&bktemp), sizeof(bank_card)))
            if (bind[x] && bktemp.getnum() == bind[x])
                break;
        bank_obj.clear();
        if (bktemp.maxium() >= amount - eps)
            break;
    }
    if (x != 3)
    {
        cout << "Using bank card:" << bind[x] << endl;
        if (confirm())
        {
            bktemp.withdraw(amount);
            bank_obj.seekg(-sizeof(bank_card), ios_base::cur);
            bank_obj.write((char *)(&bktemp), sizeof(bank_card));
            temp.deposit(amount);
            camp_obj.seekg(-sizeof(campus_card), ios_base::cur);
            camp_obj.write((char *)(&temp), sizeof(campus_card));
            cout << "Success!\n";
            cout << "Interest:" << temp.getinterest() << endl;
            log ltemp(account, 11, bktemp.getnum(), amount, temp.getinterest());
            log_obj.clear();
            log_obj.seekg(0, ios_base::end);
            log_obj.write((char *)(&ltemp), sizeof(log));
            ltemp = log(bktemp.getnum(), 6, account, -amount, bktemp.getinterest());
            log_obj.write((char *)(&ltemp), sizeof(log));
        }
        else
            cout << "Cancelled\n";
    }
    else
        cout << "No card can be used!\n";
    escape();
}
void Withdraw(int account, fstream &bank_obj, fstream &camp_obj, fstream &log_obj)
{
    Star();
    cout << "Type:Bank Account\n";
    cout << "Account:" << account << endl;
    cout << "Function:Withdraw\n";
    cout << "Enter the amount you wants to withdraw:";
    double amount;
    bank_card temp;
    while ((amount = GetDouble()) < eps)
    {
        cout << "Money should be positive!\n";
        cout << "Enter the amount you wants to withdraw:";
    }
    bank_obj.clear();
    bank_obj.seekg(0);
    while (bank_obj.read((char *)(&temp), sizeof(bank_card)))
        if (temp.getnum() == account)
            break;
    bank_obj.clear();
    if (temp.maxium() - amount >= -eps)
    {
        if (confirm())
        {
            temp.withdraw(amount);
            bank_obj.seekg(-sizeof(bank_card), ios_base::cur);
            bank_obj.write((char *)(&temp), sizeof(bank_card));
            cout << "Success!\n";
            cout << "Interest:" << temp.getinterest() << endl;
            log ltemp(account, 2, 0, -amount, temp.getinterest());
            log_obj.clear();
            log_obj.seekg(0, ios_base::end);
            log_obj.write((char *)(&ltemp), sizeof(log));
        }
        else
            cout << "Cancelled\n";
    }
    else
        cout << "You don't have enough money!\n";
    escape();
}
void Pay(int account, fstream &bank_obj, fstream &camp_obj, fstream &log_obj)
{
    Star();
    cout << "Type:Campus Account\n";
    cout << "Account:" << account << endl;
    cout << "Function:Pay\n";
    cout << "Enter the amount you wants to pay:";
    double amount;
    campus_card temp;
    while ((amount = GetDouble()) < eps)
    {
        cout << "Money should be positive!\n";
        cout << "Enter the amount you wants to pay:";
    }
    camp_obj.clear();
    camp_obj.seekg(0);
    while (camp_obj.read((char *)(&temp), sizeof(campus_card)))
        if (temp.getnum() == account)
            break;
    camp_obj.clear();
    if (temp.getinterest() - amount > -eps)
    {
        if (confirm())
        {
            temp.withdraw(amount);
            camp_obj.seekg(-sizeof(campus_card), ios_base::cur);
            camp_obj.write((char *)(&temp), sizeof(campus_card));
            cout << "Success!\n";
            cout << "Interest:" << temp.getinterest() << endl;
            log ltemp(account, 12, 0, -amount, temp.getinterest());
            log_obj.clear();
            log_obj.seekg(0, ios_base::end);
            log_obj.write((char *)(&ltemp), sizeof(log));
        }
    }
    else
    {
        const int *bind = temp.getbind();
        int x;
        bank_card bktemp;
        for (x = 0; x < 3; x++)
        {
            bank_obj.clear();
            bank_obj.seekg(0);
            while (bank_obj.read((char *)(&bktemp), sizeof(bank_card)))
                if (bind[x] && bktemp.getnum() == bind[x])
                    break;
            bank_obj.clear();
            if (bktemp.maxium() >= amount - temp.getinterest() - eps)
                break;
        }
        if (x != 3)
        {
            cout << "Using bank card:" << bind[x] << endl;
            if (confirm())
            {
                double trans = amount - temp.getinterest();
                bktemp.withdraw(trans);
                bank_obj.seekg(-sizeof(bank_card), ios_base::cur);
                bank_obj.write((char *)(&bktemp), sizeof(bank_card));
                temp.withdraw(temp.getinterest());
                camp_obj.seekg(-sizeof(campus_card), ios_base::cur);
                camp_obj.write((char *)(&temp), sizeof(campus_card));
                cout << "Success!\n";
                cout << "Campus Interest:0.00\n";
                cout << "Bank Interest:" << bktemp.getinterest() << endl;
                log ltemp(bind[x], 6, account, -trans, bktemp.getinterest());
                log_obj.clear();
                log_obj.seekg(0, ios_base::end);
                log_obj.write((char *)(&ltemp), sizeof(log));
                ltemp = log(account, 13, bind[x], trans, amount);
                log_obj.write((char *)(&ltemp), sizeof(log));
                ltemp = log(account, 12, 0, -amount, 0);
                log_obj.write((char *)(&ltemp), sizeof(log));
            }
            else
                cout << "Cancelled\n";
        }
        else
            cout << "You don't have enough money!\n";
    }
    escape();
}
void Transfer(int account, fstream &bank_obj, fstream &camp_obj, fstream &log_obj)
{
    Star();
    cout << "Type:Bank Account\n";
    cout << "Account:" << account << endl;
    cout << "Function:Transfer\n";
    cout << "Enter the account you wants to transfer into:";
    int target;
    while ((target = GetInt()) < 10000000 || target >= 100000000 || target == account)
    {
        cout << "Invalid number!\n";
        cout << "Enter the account you wants to transfer into:";
    }
    cout << "Enter the amount you wants to withdraw:";
    double amount;
    bank_card temp;
    while ((amount = GetDouble()) < eps)
    {
        cout << "Money should be positive!\n";
        cout << "Enter the amount you wants to withdraw:";
    }
    bank_obj.clear();
    bank_obj.seekg(0);
    while (bank_obj.read((char *)(&temp), sizeof(bank_card)))
        if (temp.getnum() == account)
            break;
    bank_obj.clear();
    if (temp.maxium() - amount > -eps)
    {
        if (target >= 50000000)
        {
            size_t src_pos = bank_obj.tellg();
            bank_card tar;
            bank_obj.seekg(0);
            while (bank_obj.read((char *)(&tar), sizeof(bank_card)))
                if (tar.isvalid() && tar.getnum() == target)
                    break;
            if (bank_obj.eof())
                cout << "Cannot find the target account!\n";
            else
            {
                if (confirm())
                {
                    tar.deposit(amount);
                    bank_obj.seekg(-sizeof(bank_card), ios_base::cur);
                    bank_obj.write((char *)(&tar), sizeof(bank_card));
                    bank_obj.seekg(src_pos);
                    temp.withdraw(amount);
                    bank_obj.seekg(-sizeof(bank_card), ios_base::cur);
                    bank_obj.write((char *)(&temp), sizeof(bank_card));
                    cout << "Success!\n";
                    cout << "Interest:" << temp.getinterest() << endl;
                    log ltemp(account, 3, target, -amount, temp.getinterest());
                    log_obj.clear();
                    log_obj.seekg(0, ios_base::end);
                    log_obj.write((char *)(&ltemp), sizeof(log));
                    ltemp = log(target, 7, account, amount, tar.getinterest());
                    log_obj.write((char *)(&ltemp), sizeof(log));
                }
                else
                    cout << "Cancelled!\n";
            }
        }
        else
        {
            campus_card tar;
            camp_obj.clear();
            camp_obj.seekg(0);
            while (camp_obj.read((char *)(&tar), sizeof(campus_card)))
                if (tar.isvalid() && tar.getnum() == target)
                    break;
            if (camp_obj.eof())
                cout << "Cannot find the target account!\n";
            else
            {
                if (confirm())
                {
                    tar.deposit(amount);
                    bank_obj.seekg(-sizeof(campus_card), ios_base::cur);
                    bank_obj.write((char *)(&tar), sizeof(campus_card));
                    temp.withdraw(amount);
                    bank_obj.seekg(-sizeof(bank_card), ios_base::cur);
                    bank_obj.write((char *)(&temp), sizeof(bank_card));
                    cout << "Success!\n";
                    cout << "Interest:" << temp.getinterest() << endl;
                    log ltemp(account, 3, target, -amount, temp.getinterest());
                    log_obj.clear();
                    log_obj.seekg(0, ios_base::end);
                    log_obj.write((char *)(&ltemp), sizeof(log));
                    ltemp = log(target, 18, account, amount, tar.getinterest());
                    log_obj.write((char *)(&ltemp), sizeof(log));
                }
                else
                    cout << "Cancelled!\n";
            }
        }
    }
    else
        cout << "You don't have enough money!\n";
    escape();
}
void ChangeBankPassword(int account, fstream &bank_obj, fstream &camp_obj, fstream &log_obj)
{
    Star();
    if (account == 88888888)
        cout << "Type:Bank Administrator\n";
    else
        cout << "Type:Bank Account";
    cout << "Account:" << account << endl;
    cout << "Function:Change password\n";
    bank_card temp;
    bank_obj.clear();
    bank_obj.seekg(0);
    while (bank_obj.read((char *)(&temp), sizeof(bank_card)))
        if (temp.getnum() == account)
            break;
    bank_obj.clear();
    string old, t, n1, n2;
    old = temp.getpassword();
    while (1)
    {
        cout << "Enter old password,\"quit\"to quit:\n";
        t = GetPassword();
        if (t == old) //If the password is right
            break;
        else if (t == "quit") //If you want to quit
        {
            account = 0;
            break;
        }
        else //If you're wrong
            cout << "You're wrong!\n";
    }
    if (account)
    {
        do
        {
            if (n1 != "")
                cout << "The two input are different!\n";
            cout << "Set the new password:\n";
            n1 = SetPassword();
            cout << "Confirm the new password:\n";
            n2 = SetPassword();
        } while (n1 != n2);
        if (confirm())
        {
            temp.changepassword(n2.c_str());
            bank_obj.seekg(-sizeof(bank_card), ios_base::cur);
            bank_obj.write((char *)(&temp), sizeof(bank_card));
            cout << "Succeess!\n";
            log ltemp;
            if (account == 88888888)
                ltemp = log(account, 22, 0, 0, 0);
            else
                ltemp = log(account, 4, 0, 0, temp.getinterest());
            log_obj.clear();
            log_obj.seekg(0, ios_base::end);
            log_obj.write((char *)(&ltemp), sizeof(log));
        }
        else
            cout << "Cancelled\n";
    }
    else
        cout << "Cancelled\n";
    escape();
}
void ChangeCampusPassword(int account, fstream &bank_obj, fstream &camp_obj, fstream &log_obj)
{
    Star();
    if (account == 44444444)
        cout << "Type:Campus Administrator\n";
    else
        cout << "Type:Campus Account";
    cout << "Account:" << account << endl;
    cout << "Function:Change password\n";
    campus_card temp;
    camp_obj.clear();
    camp_obj.seekg(0);
    while (camp_obj.read((char *)(&temp), sizeof(campus_card)))
        if (temp.getnum() == account)
            break;
    camp_obj.clear();
    string old, t, n1, n2;
    old = temp.getpassword();
    while (1)
    {
        cout << "Enter old password,\"quit\"to quit:\n";
        t = GetPassword();
        if (t == old) //If the password is right
            break;
        else if (t == "quit") //If you want to quit
        {
            account = 0;
            break;
        }
        else //If you're wrong
            cout << "You're wrong!\n";
    }
    if (account)
    {
        do
        {
            if (n1 != "")
                cout << "The two input are different!\n";
            cout << "Set the new password:\n";
            n1 = SetPassword();
            cout << "Confirm the new password:\n";
            n2 = SetPassword();
        } while (n1 != n2);
        if (confirm())
        {
            temp.changepassword(n2.c_str());
            camp_obj.seekg(-sizeof(campus_card), ios_base::cur);
            camp_obj.write((char *)(&temp), sizeof(campus_card));
            cout << "Succeess!\n";
            log ltemp;
            if (account == 44444444)
                ltemp = log(account, 27, 0, 0, 0);
            else
                ltemp = log(account, 14, 0, 0, temp.getinterest());
            log_obj.clear();
            log_obj.seekg(0, ios_base::end);
            log_obj.write((char *)(&ltemp), sizeof(log));
        }
        else
            cout << "Cancelled\n";
    }
    else
        cout << "Cancelled\n";
    escape();
}
void BankDetails(int account, fstream &bank_obj, fstream &camp_obj, fstream &log_obj)
{
    Star();
    cout << "Type:Bank Account\n";
    cout << "Account:" << account << endl;
    cout << "Function:Show information\n";
    bank_card temp;
    bank_obj.clear();
    bank_obj.seekg(0);
    while (bank_obj.read((char *)(&temp), sizeof(bank_card)))
        if (temp.getnum() == account)
            break;
    bank_obj.clear();
    temp.ShowData();
    escape();
}
void CampusDetails(int account, fstream &bank_obj, fstream &camp_obj, fstream &log_obj)
{
    Star();
    cout << "Type:Campus Account\n";
    cout << "Account:" << account << endl;
    cout << "Function:Show information\n";
    campus_card temp;
    camp_obj.clear();
    camp_obj.seekg(0);
    while (camp_obj.read((char *)(&temp), sizeof(campus_card)))
        if (temp.getnum() == account)
            break;
    camp_obj.clear();
    temp.ShowData();
    escape();
}
void ShowLogs(int account, fstream &bank_obj, fstream &camp_obj, fstream &log_obj)
{
    Star();
    if (account == 88888888)
        cout << "Type:Bank Administer\n";
    else if (account == 44444444)
        cout << "Type:Campus Administer\n";
    else if (account >= 50000000)
        cout << "Type:Bank Account\n";
    else
        cout << "Type:Campus Account\n";
    cout << "Account:" << account << endl;
    cout << "Function:Show Logs\n";
    log_obj.clear();
    log_obj.seekg(0);
    log temp;
    while (log_obj.read((char *)(&temp), sizeof(log)))
    {
        if (temp.num == account)
            cout << temp.show() << endl;
    }
    escape();
}
void ShowAllBankLogs(fstream &bank_obj, fstream &camp_obj, fstream &log_obj)
{
    Star();
    cout << "Type:Bank Administer\n";
    cout << "Account:88888888\n";
    cout << "Function:Show all bank logs\n";
    log_obj.clear();
    log_obj.seekg(0);
    log temp;
    while (log_obj.read((char *)(&temp), sizeof(log)))
    {
        if (temp.num >= 50000000)
            cout << temp.show() << endl;
    }
    escape();
}
void ShowAllCampusLogs(fstream &bank_obj, fstream &camp_obj, fstream &log_obj)
{
    Star();
    cout << "Type:Campus Administer\n";
    cout << "Account:44444444\n";
    cout << "Function:Show all campus logs\n";
    log_obj.clear();
    log_obj.seekg(0);
    log temp;
    while (log_obj.read((char *)(&temp), sizeof(log)))
    {
        if (temp.num < 50000000)
            cout << temp.show() << endl;
    }
    escape();
}
void ShowCertainBankLogs(fstream &bank_obj, fstream &camp_obj, fstream &log_obj)
{
    Star();
    cout << "Type:Bank Administer\n";
    cout << "Account:88888888\n";
    cout << "Function:Print logs of a bank account\n";
    cout << "Enter the bank account:";
    int num;
    while ((num = GetInt()) < 50000000 || num >= 100000000)
    {
        cout << "Account number should between 50000000 and 100000000!";
        cout << "Enter the bank account:";
    }
    bank_card t;
    bank_obj.clear();
    bank_obj.seekg(sizeof(bank_card));
    while (bank_obj.read((char *)(&t), sizeof(bank_card)))
    {
        if (t.isvalid() && t.getnum() == num)
        {
            log_obj.clear();
            log_obj.seekg(0);
            log temp;
            while (log_obj.read((char *)(&temp), sizeof(log)))
            {
                if (temp.num == num)
                    cout << temp.show() << endl;
            }
            break;
        }
    }
    if (bank_obj.eof())
        cout << "No found!\n";
    escape();
}
void ShowCertainCampusLogs(fstream &bank_obj, fstream &camp_obj, fstream &log_obj)
{
    Star();
    cout << "Type:Campus Administer\n";
    cout << "Account:44444444\n";
    cout << "Function:Print logs of a campus account\n";
    cout << "Enter the campus account:";
    int num;
    while ((num = GetInt()) < 10000000 || num >= 50000000)
    {
        cout << "Account number should between 10000000 and 50000000!";
        cout << "Enter the campus account:";
    }
    campus_card t;
    camp_obj.clear();
    camp_obj.seekg(0);
    while (camp_obj.read((char *)(&t), sizeof(campus_card)))
    {
        if (t.isvalid() && t.getnum() == num)
        {
            log_obj.clear();
            log_obj.seekg(0);
            log temp;
            while (log_obj.read((char *)(&temp), sizeof(log)))
            {
                if (temp.num == num)
                    cout << temp.show() << endl;
            }
            break;
        }
    }
    if (camp_obj.eof())
        cout << "No found!\n";
    escape();
}
void BindCard(int account, fstream &bank_obj, fstream &camp_obj, fstream &log_obj)
{
    Star();
    cout << "Type:Campus Account\n";
    cout << "Account:" << account << endl;
    cout << "Function:Bind bank card\n";
    cout << "Enter the account you wants to bind:";
    int target;
    while ((target = GetInt()) < 50000000 || target >= 100000000)
    {
        cout << "Invalid number!\n";
        cout << "Enter the account you wants to bind:";
    }
    campus_card temp;
    bank_card tar;
    string pass;
    camp_obj.clear();
    camp_obj.seekg(0);
    while (camp_obj.read((char *)(&temp), sizeof(campus_card)))
        if (temp.getnum() == account)
            break;
    camp_obj.clear();
    const int *bind = temp.getbind();
    if (bind[0] && bind[1] && bind[2])
        cout << "The campus card cannot bind new card!\n";
    else if (bind[0] == target || bind[1] == target || bind[2] == target)
        cout << "The bank card has been binded to this card!\n";
    else
    {
        bank_obj.clear();
        bank_obj.seekg(0);
        while (bank_obj.read((char *)(&tar), sizeof(bank_card)))
            if (tar.isvalid() && tar.getnum() == target)
            {
                pass = tar.getpassword();
                break;
            }
        if (bank_obj.eof())
            cout << "Cannot find the target account!\n";
        else
        {
            cout << "Enter the password or enter \"quit\" to exit\n";
            string t = "";
            while (1)
            {
                t = GetPassword();
                if (t == pass) //If the password is right
                    break;
                else if (t == "quit") //If you want to quit
                {
                    target = 0;
                    break;
                }
                else //If you're wrong
                    cout << "You're wrong!\n";
            }
            if (target && confirm())
            {
                temp.binding(target);
                camp_obj.seekg(-sizeof(campus_card), ios_base::cur);
                camp_obj.write((char *)(&temp), sizeof(campus_card));
                cout << "Success!\n";
                log ltemp(account, 15, target, 0, temp.getinterest());
                log_obj.clear();
                log_obj.seekg(0, ios_base::end);
                log_obj.write((char *)(&ltemp), sizeof(log));
                ltemp = log(target, 8, account, 0, tar.getinterest());
                log_obj.write((char *)(&ltemp), sizeof(log));
            }
            else
                cout << "Cancelled\n";
        }
    }
    escape();
}
void DebindCard(int account, fstream &bank_obj, fstream &camp_obj, fstream &log_obj)
{
    Star();
    cout << "Type:Campus Account\n";
    cout << "Account:" << account << endl;
    cout << "Function:Debind bank card\n";
    campus_card temp;
    bank_card tar;
    string pass;
    camp_obj.clear();
    camp_obj.seekg(0);
    while (camp_obj.read((char *)(&temp), sizeof(campus_card)))
        if (temp.getnum() == account)
            break;
    camp_obj.clear();
    const int *bind = temp.getbind();
    cout << "The card you have binded:";
    bool i = 0;
    int x;
    for (x = 0; x < 3; x++)
        if (!bind[x])
        {
            cout << bind[x] << " ";
            i = 1;
        }
    if (!i)
        cout << "No card has been binded!\n";
    else
    {
        cout << endl;
        int target;
        cout << "Enter the account you wants to debind,0 to cancel:";
        while ((target = GetInt()) && target != bind[1] && target != bind[2] && target != bind[3])
        {
            cout << "Invalid card number!\n";
            cout << "Enter the account you wants to debind,0 to cancel:";
        }
        if (target && confirm())
        {
            temp.debinding(target);
            camp_obj.seekg(-sizeof(campus_card), ios_base::cur);
            camp_obj.write((char *)(&temp), sizeof(campus_card));
            cout << "Success!\n";
            log ltemp(account, 16, target, 0, temp.getinterest());
            log_obj.clear();
            log_obj.seekg(0, ios_base::end);
            log_obj.write((char *)(&ltemp), sizeof(log));
            ltemp = log(target, 9, account, 0, tar.getinterest());
            log_obj.write((char *)(&ltemp), sizeof(log));
        }
        else
            cout << "Cancelled\n";
    }
    escape();
}
void AddBankAccount(fstream &bank_obj, fstream &camp_obj, fstream &log_obj)
{
    Star();
    cout << "Type:Bank Administer\n";
    cout << "Account:88888888\n";
    cout << "Function:Add a bank account\n";
    cout << "Enter the bank account:";
    int num, lim;
    bank_card temp;
    bool used = 0;
    while (num = GetInt())
    {
        used = 0;
        if (num < 50000000 || num >= 100000000)
            cout << "Account number should between 50000000 and 100000000!\n";
        else
        {
            bank_obj.clear();
            bank_obj.seekg(0);
            while (bank_obj.read((char *)(&temp), sizeof(bank_card)))
            {
                if (temp.isvalid() && temp.getnum() == num)
                {
                    used = 1;
                    break;
                }
            }
            if (used)
                cout << "The number has been used!\n";
            else
                break;
        }
        cout << "Enter the bank account:";
    }
    cout << "Enter the user's name:";
    char name[30];
    cin.get(name, 30).get();
    char pass[7];
    strcpy(pass, SetPassword());
    cout << "Enter the overdraft limit:";
    while ((lim = GetDouble()) < -eps)
    {
        cout << "Limit can't be negative!\n";
        cout << "Enter the overdraft limit:";
    }
    bank_card bc(name, num, pass, 1, lim);
    if (confirm())
    {
        bank_obj.clear();
        bank_obj.seekg(0);
        while (bank_obj.read((char *)(&temp), sizeof(bank_card)))
        {
            if (!temp.isvalid())
            {
                bank_obj.seekg(-sizeof(bank_card), ios_base::cur);
                bank_obj.write((char *)(&bc), sizeof(bank_card));
                break;
            }
        }
        if (bank_obj.eof())
        {
            bank_obj.clear();
            bank_obj.write((char *)(&bc), sizeof(bank_card));
        }
        log ltemp(88888888, 19, num, 0, 0);
        log_obj.clear();
        log_obj.seekg(0, ios_base::end);
        log_obj.write((char *)(&ltemp), sizeof(log));
        ltemp = log(num, 5, 0, 0, 0);
        log_obj.write((char *)(&ltemp), sizeof(log));
        cout << "Success!\n";
    }
    else
        cout << "Cancelled\n";
    escape();
}
void AddCampusAccount(fstream &bank_obj, fstream &camp_obj, fstream &log_obj)
{
    Star();
    cout << "Type:Campus Administer\n";
    cout << "Account:44444444\n";
    cout << "Function:Add a campus account\n";
    cout << "Enter the campus account:";
    int num;
    campus_card temp;
    bool used;
    while (num = GetInt())
    {
        used = 0;
        if (num < 10000000 || num >= 50000000)
            cout << "Account number should between 10000000 and 50000000!";
        else
        {
            camp_obj.clear();
            camp_obj.seekg(0);
            while (camp_obj.read((char *)(&temp), sizeof(campus_card)))
            {
                if (temp.isvalid() && temp.getnum() == num)
                {
                    used = 1;
                    break;
                }
            }
            if (used)
                cout << "The number has been used!\n";
            else
                break;
        }
        cout << "Enter the campus account:";
    }
    cout << "Enter the user's name:";
    char name[30];
    cin.get(name, 30).get();
    char pass[7];
    strcpy(pass, SetPassword());
    campus_card bc(name, num, pass, 1);
    if (confirm())
    {
        camp_obj.clear();
        camp_obj.seekg(0);
        while (camp_obj.read((char *)(&temp), sizeof(campus_card)))
        {
            if (!temp.isvalid())
            {
                camp_obj.seekg(-sizeof(campus_card), ios_base::cur);
                camp_obj.write((char *)(&bc), sizeof(campus_card));
                break;
            }
        }
        if (camp_obj.eof())
        {
            camp_obj.clear();
            camp_obj.write((char *)(&bc), sizeof(campus_card));
        }
        log ltemp(44444444, 24, num, 0, 0);
        log_obj.clear();
        log_obj.seekg(0, ios_base::end);
        log_obj.write((char *)(&ltemp), sizeof(log));
        ltemp = log(num, 17, 0, 0, 0);
        log_obj.write((char *)(&ltemp), sizeof(log));
        cout << "Success!\n";
    }
    else
        cout << "Cancelled\n";
    escape();
}
void DeleteBankAccount(fstream &bank_obj, fstream &camp_obj, fstream &log_obj)
{
    Star();
    cout << "Type:Bank Administer\n";
    cout << "Account:88888888\n";
    cout << "Function:Delete a bank account\n";
    cout << "Enter the bank account:";
    int num, lim;
    while ((num = GetInt()) < 50000000 || num >= 100000000)
    {
        cout << "Account number should between 50000000 and 100000000!\n";
        cout << "Enter the bank account:";
    }
    bank_card temp;
    bank_obj.clear();
    bank_obj.seekg(sizeof(bank_card));
    while (bank_obj.read((char *)(&temp), sizeof(bank_card)))
    {
        if (temp.isvalid() && temp.getnum() == num)
        {
            bank_obj.seekg(-sizeof(bank_card), ios_base::cur);
            temp.setvalid(0);
            if (confirm())
            {
                bank_obj.write((char *)(&temp), sizeof(bank_card));
                campus_card cptemp;
                camp_obj.clear();
                camp_obj.seekg(0);
                log ltemp;
                log_obj.clear();
                log_obj.seekg(0, ios_base::end);
                while (camp_obj.read((char *)(&cptemp), sizeof(campus_card)))
                {
                    const int *bind = cptemp.getbind();
                    if (num == bind[0] || num == bind[1] || num == bind[2])
                    {
                        cptemp.debinding(num);
                        camp_obj.seekg(-sizeof(campus_card), ios_base::cur);
                        camp_obj.write((char *)(&cptemp), sizeof(campus_card));
                        ltemp = log(cptemp.getnum(), 16, num, 0, cptemp.getinterest());
                        log_obj.write((char *)(&ltemp), sizeof(log));
                        ltemp = log(num, 9, cptemp.getnum(), 0, temp.getinterest());
                        log_obj.write((char *)(&ltemp), sizeof(log));
                    }
                }
                ltemp = log(88888888, 21, num, 0, 0);
                log_obj.write((char *)(&ltemp), sizeof(log));
                cout << "Success!\n";
            }
            else
                cout << "Cancelled\n";
            break;
        }
    }
    if (bank_obj.eof())
        cout << "No found!\n";
    escape();
}
void DeleteCampusAccount(fstream &bank_obj, fstream &camp_obj, fstream &log_obj)
{
    Star();
    cout << "Type:Campus Administer\n";
    cout << "Account:44444444\n";
    cout << "Function:Delete a campus account\n";
    cout << "Enter the campus account:";
    int num, lim;
    while ((num = GetInt()) < 10000000 || num >= 50000000)
    {
        cout << "Account number should between 10000000 and 50000000!";
        cout << "Enter the campus account:";
    }
    campus_card temp;
    camp_obj.clear();
    camp_obj.seekg(sizeof(campus_card));
    while (camp_obj.read((char *)(&temp), sizeof(campus_card)))
    {
        if (temp.isvalid() && temp.getnum() == num)
        {
            camp_obj.seekg(-sizeof(campus_card), ios_base::cur);
            temp.setvalid(0);
            if (confirm())
            {
                camp_obj.write((char *)(&temp), sizeof(campus_card));
                log ltemp(44444444, 26, num, 0, 0);
                ;
                log_obj.clear();
                log_obj.seekg(0, ios_base::end);
                log_obj.write((char *)(&ltemp), sizeof(log));
                cout << "Success!\n";
            }
            else
                cout << "Cancelled\n";
            break;
        }
    }
    if (camp_obj.eof())
        cout << "No found!\n";
    escape();
}
void PrintBankInfo(fstream &bank_obj, fstream &camp_obj, fstream &log_obj)
{
    Star();
    cout << "Type:Bank Administer\n";
    cout << "Account:88888888\n";
    cout << "Function:Print information of a bank account\n";
    cout << "Enter the bank account:";
    int num;
    while ((num = GetInt()) < 50000000 || num >= 100000000)
    {
        cout << "Account number should between 50000000 and 100000000!";
        cout << "Enter the bank account:";
    }
    bank_card temp;
    bank_obj.clear();
    bank_obj.seekg(sizeof(bank_card));
    while (bank_obj.read((char *)(&temp), sizeof(bank_card)))
    {
        if (temp.isvalid() && temp.getnum() == num)
        {
            temp.ShowData();
            break;
        }
    }
    if (bank_obj.eof())
        cout << "No found!\n";
    escape();
}
void PrintCampusInfo(fstream &bank_obj, fstream &camp_obj, fstream &log_obj)
{
    Star();
    cout << "Type:Campus Administer\n";
    cout << "Account:44444444\n";
    cout << "Function:Print information of a campus account\n";
    cout << "Enter the campus account:";
    int num;
    while ((num = GetInt()) < 10000000 || num >= 50000000)
    {
        cout << "Account number should between 10000000 and 50000000!";
        cout << "Enter the campus account:";
    }
    campus_card temp;
    camp_obj.clear();
    camp_obj.seekg(0);
    while (camp_obj.read((char *)(&temp), sizeof(campus_card)))
    {
        if (temp.isvalid() && temp.getnum() == num)
        {
            temp.ShowData();
            break;
        }
    }
    if (camp_obj.eof())
        cout << "No found!\n";
    escape();
}
void LoadBankAccount(fstream &bank_obj, fstream &camp_obj, fstream &log_obj)
{
    Star();
    cout << "Type:Bank Administer\n";
    cout << "Account:88888888\n";
    cout << "Function:Load new user from a file\n";
    cout << "You should enter the file like this:\n";
    cout << "Luo Jun\n";
    cout << "99999999 2000 888888\n";
    cout << "Enter the filename:";
    string name;
    cin >> name;
    char n[30], p[7];
    int acc, lim;
    bool used = 0;
    bank_card temp;
    log ltemp;
    log_obj.clear();
    log_obj.seekg(0, ios_base::end);
    ifstream fin(name.c_str(), ios_base::in);
    if (fin.is_open())
    {
        cout << "Successfully open the file!\n";
        while (fin.get(n, 30))
        {
            used = 0;
            fin >> acc >> lim >> p;
            if (acc < 100000000 && acc >= 50000000 && lim > -eps && strlen(p) == 6)
            {
                bank_obj.clear();
                bank_obj.seekg(0);
                while (bank_obj.read((char *)(&temp), sizeof(bank_card)))
                {
                    if (temp.isvalid() && temp.getnum() == acc)
                    {
                        used = 1;
                        break;
                    }
                }
                if (used)
                    cout << "Failed to add user1:" << n << endl;
                else
                {
                    temp = bank_card(n, acc, p, 1, lim);
                    bank_obj.clear();
                    bank_obj.seekg(0, ios_base::end);
                    bank_obj.write((char *)(&temp), sizeof(bank_card));
                    cout << "Successfully add user:" << n << endl;
                    ltemp = log(88888888, 20, acc, 0, 0);
                    log_obj.write((char *)(&ltemp), sizeof(log));
                    ltemp = log(acc, 5, 0, 0, 0);
                    log_obj.write((char *)(&ltemp), sizeof(log));
                }
                fin.get();
            }
            else
                cout << "Failed to add user:" << n << endl;
        }
        fin.close();
    }
    else
        cout << "Failed to open the file!\n";
    cin.ignore(999, '\n');
    escape();
}
void LoadCampusAccount(fstream &bank_obj, fstream &camp_obj, fstream &log_obj)
{
    Star();
    cout << "Type:Canpus Administer\n";
    cout << "Account:44444444\n";
    cout << "Function:Load new user from a file\n";
    cout << "You should enter the file like this:\n";
    cout << "Luo Jun\n";
    cout << "22222222 888888\n";
    cout << "Enter the filename:";
    string name;
    cin >> name;
    char n[30], p[7];
    int acc;
    bool used;
    campus_card temp;
    log ltemp;
    log_obj.clear();
    log_obj.seekg(0, ios_base::end);
    ifstream fin(name.c_str(), ios_base::in);
    if (fin.is_open())
    {
        cout << "Successfully open the file!\n";
        camp_obj.clear();
        camp_obj.seekg(0, ios_base::end);
        while (fin.get(n, 30))
        {
            used = 0;
            fin >> acc >> p;
            if (acc < 50000000 && acc >= 10000000 && strlen(p) == 6)
            {
                camp_obj.clear();
                camp_obj.seekg(0);
                while (camp_obj.read((char *)(&temp), sizeof(campus_card)))
                {
                    if (temp.isvalid() && temp.getnum() == acc)
                    {
                        used = 1;
                        break;
                    }
                }
                if (used)
                    cout << "Failed to add user:" << n << endl;
                else
                {
                    camp_obj.clear();
                    camp_obj.seekg(0, ios_base::end);
                    temp = campus_card(n, acc, p, 1);
                    camp_obj.write((char *)(&temp), sizeof(campus_card));
                    cout << "Successfully add user:" << n << endl;
                    ltemp = log(44444444, 25, acc, 0, 0);
                    log_obj.write((char *)(&ltemp), sizeof(log));
                    ltemp = log(acc, 17, 0, 0, 0);
                    log_obj.write((char *)(&ltemp), sizeof(log));
                }
                fin.get();
            }
            else
                cout << "Failed to add user:" << n << endl;
        }
        fin.close();
    }
    else
        cout << "Failed to open the file!\n";
    cin.ignore(999, '\n');
    escape();
}
int GetInt(void)
{
    int num;
    cin >> num;
    while (cin.fail()) //If you enter an invalid input
    {
        cin.clear();
        cin.ignore(999, '\n');
        cout << "Enter a number:";
        cin >> num;
    }
    cin.ignore(999, '\n');
    return num;
}
double GetDouble(void)
{
    double num;
    cin >> num;
    while (cin.fail()) //If you enter an invalid input
    {
        cin.clear();
        cin.ignore(999, '\n');
        cout << "Enter a number:";
        cin >> num;
    }
    cin.ignore(999, '\n');
    return num;
}
const char *GetPassword(void)
{
    char ch;
    string temp;
    temp = "";
    cout << "Enter the password:";
    setvbuf(stdin, NULL, _IONBF, 0);     //No buffer
    setvbuf(stdout, NULL, _IONBF, 0);    //No buffer
    system("stty -echo");                //Linux only.hide the input
    while ((ch = cin.get()) && ch != 10) //read chars and output *
    {
        temp += ch;
        cout.put('*');
    }
    cout << endl;
    system("stty echo");                 //Linux only.Cancel the hide of the input
    setvbuf(stdin, NULL, _IOFBF, 4096);  //Full buffer
    setvbuf(stdout, NULL, _IOFBF, 4096); //Full buffer
    return temp.c_str();
}
const char *SetPassword(void)
{
    char ch;
    string temp;
    do
    {
        temp = "";
        cout << "Enter the password(The length is 6):";
        setvbuf(stdin, NULL, _IONBF, 0);     //No buffer
        setvbuf(stdout, NULL, _IONBF, 0);    //No buffer
        system("stty -echo");                //Linux only.hide the input
        while ((ch = cin.get()) && ch != 10) //read chars and output *
        {
            temp += ch;
            cout.put('*');
        }
        cout << endl;
        system("stty echo");                 //Linux only.Cancel the hide of the input
        setvbuf(stdin, NULL, _IOFBF, 4096);  //Full buffer
        setvbuf(stdout, NULL, _IOFBF, 4096); //Full buffer
    } while (temp.length() != 6 && temp.find_first_not_of("0123456789") == string::npos);
    return temp.c_str();
}
bool confirm(void)
{
    cout << "Do you confirm this operation?\n";
    cout << "Enter Y/y to confirm or other to cancel:";
    char ch = tolower(cin.get());
    cin.ignore(999, '\n');
    if (ch == 'y')
        return 1;
    return 0;
}
void escape(void)
{
    cout << "Press Enter to back to the main menu:";
    cin.ignore(999, '\n');
}
void Star()
{
    for (int i = 0; i < 60; i++)
        cout << '*';
    cout << endl;
}