#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include "card.h"
#include "log.h"
using namespace std;                                               //My English is very rubbish
const double eps = 1e-5;                                           //So please ignore the spell and grammar mistakes
int LogIn(fstream &bank_obj, fstream &camp_obj, fstream &log_obj); //Log-In system
char bank_menu(int account);
char camp_menu(int account);
char bank_admin_menu();
char campus_admin_menu();
void BankDeposit(int account, fstream &bank_obj, fstream &camp_obj, fstream &log_obj);
void CampusDeposit(int account, fstream &bank_obj, fstream &camp_obj, fstream &log_obj); //Deposit by cash or Wechat,Alipay,etc
void DepositByBank(int account, fstream &bank_obj, fstream &camp_obj, fstream &log_obj); //Deposit by binded bank card
void Withdraw(int account, fstream &bank_obj, fstream &camp_obj, fstream &log_obj);
void Pay(int account, fstream &bank_obj, fstream &camp_obj, fstream &log_obj);
void Transfer(int account, fstream &bank_obj, fstream &camp_obj, fstream &log_obj);
void ChangeBankPassword(int account, fstream &bank_obj, fstream &camp_obj, fstream &log_obj);
void ChangeCampusPassword(int account, fstream &bank_obj, fstream &camp_obj, fstream &log_obj);
void ShowLogs(int account, fstream &bank_obj, fstream &camp_obj, fstream &log_obj);      //Show logs of itself
void ShowAllBankLogs(fstream &bank_obj, fstream &camp_obj, fstream &log_obj);            //For bank administrator,check all bank logs
void ShowAllCampusLogs(fstream &bank_obj, fstream &camp_obj, fstream &log_obj);          //For campus administrator,check all campus logs
void ShowCertainBankLogs(fstream &bank_obj, fstream &camp_obj, fstream &log_obj);        //For bank administrator,check one user's bank logs
void ShowCertainCampusLogs(fstream &bank_obj, fstream &camp_obj, fstream &log_obj);      //For campus administrator,check one user's bank logs
void BankDetails(int account, fstream &bank_obj, fstream &camp_obj, fstream &log_obj);   //For bank users,check his/her information
void CampusDetails(int account, fstream &bank_obj, fstream &camp_obj, fstream &log_obj); //For campus users,check his/her information
void BindCard(int account, fstream &bank_obj, fstream &camp_obj, fstream &log_obj);
void DebindCard(int account, fstream &bank_obj, fstream &camp_obj, fstream &log_obj);
void AddBankAccount(fstream &bank_obj, fstream &camp_obj, fstream &log_obj);      //For bank administrator,add a card manually
void AddCampusAccount(fstream &bank_obj, fstream &camp_obj, fstream &log_obj);    //For campus administrator,add a card manually
void DeleteBankAccount(fstream &bank_obj, fstream &camp_obj, fstream &log_obj);   //For bank administrator,delete a card manually
void DeleteCampusAccount(fstream &bank_obj, fstream &camp_obj, fstream &log_obj); //For campus administrator,delete a card manually
void PrintBankInfo(fstream &bank_obj, fstream &camp_obj, fstream &log_obj);       //For bank administrator,check one user's information
void PrintCampusInfo(fstream &bank_obj, fstream &camp_obj, fstream &log_obj);     //For campus administrator,check one user's information
void ChangeLimit(fstream &bank_obj, fstream &camp_obj, fstream &log_obj);         //For bank administrator,change one user's overdraft limit
void LoadBankAccount(fstream &bank_obj, fstream &camp_obj, fstream &log_obj);     //For bank administrator,add many cards automatically
void LoadCampusAccount(fstream &bank_obj, fstream &camp_obj, fstream &log_obj);   //For campus administrator,add many cards automatically
int GetInt(void);                                                                 //Get an interger and prevent illegal input
double GetDouble(void);                                                           //Get an double floating number and prevent illegal input
const char *GetPassword(void);
const char *SetPassword(void);
bool alldigit(const char *p); //Check whether a C-string is a pure digit string
bool confirm(void);           //Confirm the operation
void escape(void);            //Exit a function
void Star();                  //Print 60 asterisks
int main()
{
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.precision(2);
    fstream bank_obj("bank.txt", ios_base::in | ios_base::out | ios_base::binary); //Open files
    fstream camp_obj("campus.txt", ios_base::in | ios_base::out | ios_base::binary);
    fstream log_obj("log.txt", ios_base::in | ios_base::out | ios_base::binary);
    if (!bank_obj.is_open() || !camp_obj.is_open() || !log_obj.is_open()) //If the file can't be opened
    {
        cout << "Error in opening the file!\n";
        cout << "Program terminated.\n";
        exit(EXIT_FAILURE); //Terminate the program
    }
    bank_card bc;
    bank_obj.read((char *)(&bc), sizeof(bank_card));
    if (bank_obj.eof()) //If no bank administrator account,create one
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
    if (camp_obj.eof()) //If no campus administrator account,create one
    {
        cc = campus_card("Administrator", 44444444, "000000"); //My blessing :)
        camp_obj.clear();
        camp_obj.seekg(0);
        camp_obj.write((char *)(&cc), sizeof(campus_card));
        log ltemp(44444444, 28, 0, 0, 0);
        log_obj.seekg(0, ios_base::end);
        log_obj.write((char *)(&ltemp), sizeof(log));
    }
    int account;
    char ch;
    while (account = LogIn(bank_obj, camp_obj, log_obj)) //First,log-in
    {
        if (account == 88888888) //Bank Administrator
        {
            while ((ch = bank_admin_menu()) != 'q') //Get choice
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
                    ChangeLimit(bank_obj, camp_obj, log_obj);
                    break;
                case 'e':
                    LoadBankAccount(bank_obj, camp_obj, log_obj);
                    break;
                case 'f':
                    ChangeBankPassword(88888888, bank_obj, camp_obj, log_obj);
                    break;
                case 'g':
                    ShowLogs(88888888, bank_obj, camp_obj, log_obj);
                    break;
                case 'h':
                    ShowAllBankLogs(bank_obj, camp_obj, log_obj);
                    break;
                case 'i':
                    ShowCertainBankLogs(bank_obj, camp_obj, log_obj);
                    break;
                default:
                    cout << "Coming Soon~\n";
                }
            }
        }
        else if (account == 44444444) //Campus administrator
        {
            while ((ch = campus_admin_menu()) != 'q') //Get choice
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
        else if (account >= 50000000) //Bank card user
        {
            while ((ch = bank_menu(account)) != 'q') //Get choice
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
        else if (account >= 10000000) //Campus card user
        {
            while ((ch = camp_menu(account)) != 'q') //Get choice
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
        else //To get unexpected condition
            cout << "Error!\n";
    }
    cout << "Thanks for using the system!\n";
    cout << "Bye~\n";
    bank_obj.close(); //Close the files
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
        cin >> number;                                //Get number
        if (number >= 50000000 && number < 100000000) //Bank card
        {
            bank_card t;
            bank_obj.clear();
            bank_obj.seekg(0);
            while (bank_obj.read((char *)(&t), sizeof(bank_card))) //Find the user
                if (t.isvalid() && t.getnum() == number)           //Successfully find the user
                    break;
            if (t.getnum() == number) //Successfully find the user
            {
                pass = string(t.getpassword()); //Get the password
                break;
            }
            cout << "No found!\n"; //Failed to find the user
        }
        else if (number >= 10000000 && number < 100000000) //Campus card
        {
            campus_card t;
            camp_obj.clear();
            camp_obj.seekg(0);
            while (camp_obj.read((char *)(&t), sizeof(campus_card))) //Find the user
                if (t.isvalid() && t.getnum() == number)             //Successfully find the user
                    break;
            if (t.getnum() == number) //Successfully find the user
            {
                pass = string(t.getpassword()); //Get the password
                break;
            }
            cout << "No found!\n"; //Failed to find the user
        }
        else if (number == 0) //Exit the system
        {
            cout << "Exit the system!\n";
            return 0;
        }
        else //Invalid Number
            cout << "Invalid Number!\n";
    }
    if (number) //If you don't want to quit
    {
        cout << "Enter the password or enter \"quit\" to exit\n";
        string temp = "";
        while (1)
        {
            temp = GetPassword(); //Get the input
            if (temp == pass)     //If the password is right
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
    return number; //Return the account
}
char bank_menu(int account)
{
    Star();
    char v;
    cout << "Type:Bank Account\n";
    cout << "Account:" << account << endl;
    cout << "Choose Function:\n"; //Display choices
    cout << "A-Deposit\n";
    cout << "B-Withdraw\n";
    cout << "C-Transfer\n";
    cout << "D-Change Password\n";
    cout << "E-Show Details\n";
    cout << "F-Show Logs\n";
    cout << "Q-quit\n";
    cout << "Your Choice:";
    while ((v = tolower(cin.get())) && strchr("abcdefq", v) == NULL) //Check whether the choice is valid
    {
        cout << "Enter A~F or Q!";
        cin.ignore(999, '\n'); //Process the remaining input
    }
    cin.ignore(999, '\n'); //Process the remaining input
    return v;              //Return the choice
}
char camp_menu(int account)
{
    Star();
    char v;
    cout << "Type:Campus Account\n";
    cout << "Account:" << account << endl;
    cout << "Choose Function:\n"; //Display choices
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
    while ((v = tolower(cin.get())) && strchr("abcdefghq", v) == NULL) //Check whether the choice is valid
    {
        cout << "Enter A~H or Q!";
        cin.ignore(999, '\n'); //Process the remaining input
    }
    cin.ignore(999, '\n'); //Process the remaining input
    return v;              //Return the choice
}
char bank_admin_menu()
{
    Star();
    char v;
    cout << "Type:Bank Administrator\n";
    cout << "Account:88888888\n";
    cout << "Choose Function:\n"; //Display choices
    cout << "A-Add an account\n";
    cout << "B-Delete an account\n";
    cout << "C-Print information of one user\n";
    cout << "D-Change one user's overdraft limit\n";
    cout << "E-Load new account from file\n";
    cout << "F-Change Password\n";
    cout << "G-Show Logs\n";
    cout << "H-Show all bank logs\n";
    cout << "I-Print logs of one user\n";
    cout << "Q-quit\n";
    cout << "Your Choice:";
    while ((v = tolower(cin.get())) && strchr("abcdefghiq", v) == NULL) //Check whether the choice is valid
    {
        cout << "Enter A~H or Q!";
        cin.ignore(999, '\n'); //Process the remaining input
    }
    cin.ignore(999, '\n'); //Process the remaining input
    return v;              //Return the choice
}
char campus_admin_menu()
{
    Star();
    char v;
    cout << "Type:Campus Administrator\n";
    cout << "Account:44444444\n";
    cout << "Choose Function:\n"; //Display choices
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
    while ((v = tolower(cin.get())) && strchr("abcdefghq", v) == NULL) //Check whether the choice is valid
    {
        cout << "Enter A~H or Q!";
        cin.ignore(999, '\n'); //Process the remaining input
    }
    cin.ignore(999, '\n'); //Process the remaining input
    return v;              //Return the choice
}
void BankDeposit(int account, fstream &bank_obj, fstream &camp_obj, fstream &log_obj)
{
    Star();
    bank_card temp;
    bank_obj.clear();
    bank_obj.seekg(0);
    while (bank_obj.read((char *)(&temp), sizeof(bank_card))) //Find the account
        if (temp.isvalid() && temp.getnum() == account)
            break;
    cout << "Type:Bank Account\n";
    cout << "Account:" << account << endl;
    cout << "Function:Deposit\n";
    cout << "Current interest:" << temp.getinterest() << endl;
    cout << "Enter the amount you wants to deposit:";
    double amount;
    while ((amount = GetDouble()) < eps) //Amount should be positive
    {
        cout << "Money should be positive!\n";
        cout << "Enter the amount you wants to deposit:";
    }
    temp.deposit(amount); //Deposit the money
    bank_obj.clear();
    if (confirm()) //Are you sure?
    {
        bank_obj.seekg(-sizeof(bank_card), ios_base::cur);
        bank_obj.write((char *)(&temp), sizeof(bank_card)); //Write the data
        cout << "Succeess!\n";
        cout << "Interest:" << temp.getinterest() << endl;
        log ltemp(account, 1, 0, amount, temp.getinterest());
        log_obj.clear();
        log_obj.seekg(0, ios_base::end);
        log_obj.write((char *)(&ltemp), sizeof(log)); //Write the log
    }
    else //If you have regretted
        cout << "Cancelled\n";
    escape();
}
void CampusDeposit(int account, fstream &bank_obj, fstream &camp_obj, fstream &log_obj)
{
    Star();
    campus_card temp;
    camp_obj.clear();
    camp_obj.seekg(0);
    while (camp_obj.read((char *)(&temp), sizeof(campus_card))) //Find the account
        if (temp.isvalid() && temp.getnum() == account)
            break;
    cout << "Type:Campus Account\n";
    cout << "Account:" << account << endl;
    cout << "Function:Deposit\n";
    cout << "Current interest:" << temp.getinterest() << endl;
    cout << "Enter the amount you wants to deposit:";
    double amount;
    while ((amount = GetDouble()) < eps) //Amount should be positive
    {
        cout << "Money should be positive!\n";
        cout << "Enter the amount you wants to deposit:";
    }

    temp.deposit(amount); //Deposit the money
    camp_obj.clear();
    if (confirm()) //Are you sure?
    {
        camp_obj.seekg(-sizeof(campus_card), ios_base::cur);
        camp_obj.write((char *)(&temp), sizeof(campus_card)); //Write the data
        cout << "Success!\n";
        cout << "Interest:" << temp.getinterest() << endl;
        log ltemp(account, 10, 0, amount, temp.getinterest());
        log_obj.clear();
        log_obj.seekg(0, ios_base::end);
        log_obj.write((char *)(&ltemp), sizeof(log)); //Write the log
    }
    else //If you have regretted
        cout << "Cancelled\n";
    escape();
}
void DepositByBank(int account, fstream &bank_obj, fstream &camp_obj, fstream &log_obj)
{
    Star();
    campus_card temp;
    camp_obj.clear();
    camp_obj.seekg(0);
    while (camp_obj.read((char *)(&temp), sizeof(campus_card))) //Find the account
        if (temp.isvalid() && temp.getnum() == account)
            break;
    cout << "Type:Campus Account\n";
    cout << "Account:" << account << endl;
    cout << "Function:Deposit form bank card\n";
    cout << "Current interest:" << temp.getinterest() << endl;
    cout << "Enter the amount you wants to deposit:";
    double amount;
    while ((amount = GetDouble()) < eps) //Amount should be positive
    {
        cout << "Money should be positive!\n";
        cout << "Enter the amount you wants to deposit:";
    }
    camp_obj.clear();
    const int *bind = temp.getbind(); //Get the binded bank card
    int x;
    bank_card bktemp;
    for (x = 0; x < 3; x++) //Check if one card can afford the money
    {
        bank_obj.clear();
        bank_obj.seekg(0);
        while (bank_obj.read((char *)(&bktemp), sizeof(bank_card)))
            if (bind[x] && bktemp.isvalid() && bktemp.getnum() == bind[x]) //Find the bank card
                break;
        bank_obj.clear();
        if (bktemp.maxium() >= amount - eps) //Check if the card can afford the money
            break;
    }
    if (x != 3) //If there is one card can qualify the request
    {
        cout << "Using bank card:" << bind[x] << endl;
        if (confirm()) //Are you sure?
        {
            bktemp.withdraw(amount); //Withdraw from the bank card
            bank_obj.seekg(-sizeof(bank_card), ios_base::cur);
            bank_obj.write((char *)(&bktemp), sizeof(bank_card)); //Write the bank card data
            temp.deposit(amount);                                 //Deposit the money
            camp_obj.seekg(-sizeof(campus_card), ios_base::cur);
            camp_obj.write((char *)(&temp), sizeof(campus_card)); //Write the campus card data
            cout << "Success!\n";
            cout << "Interest:" << temp.getinterest() << endl;
            log ltemp(bktemp.getnum(), 6, account, -amount, bktemp.getinterest());
            log_obj.clear();
            log_obj.seekg(0, ios_base::end);
            log_obj.write((char *)(&ltemp), sizeof(log)); //Write the bank card log
            ltemp = log(account, 11, bktemp.getnum(), amount, temp.getinterest());
            log_obj.write((char *)(&ltemp), sizeof(log)); //Write the campus card log
        }
        else //If you have regretted
            cout << "Cancelled\n";
    }
    else //You have no card which can afford it!
        cout << "No card can be used!\n";
    escape();
}
void Withdraw(int account, fstream &bank_obj, fstream &camp_obj, fstream &log_obj)
{
    Star();
    bank_card temp;
    bank_obj.clear();
    bank_obj.seekg(0);
    while (bank_obj.read((char *)(&temp), sizeof(bank_card))) //Find the account
        if (temp.isvalid() && temp.getnum() == account)
            break;
    cout << "Type:Bank Account\n";
    cout << "Account:" << account << endl;
    cout << "Function:Withdraw\n";
    cout << "Current interest:" << temp.getinterest() << endl;
    cout << "Overdraft limit:" << temp.getlimit() << endl;
    cout << "Enter the amount you wants to withdraw:";
    double amount;
    while ((amount = GetDouble()) < eps) //Amount should be positive
    {
        cout << "Money should be positive!\n";
        cout << "Enter the amount you wants to withdraw:";
    }

    bank_obj.clear();
    if (temp.maxium() - amount > -eps) //If you have enough money
    {
        if (confirm()) //Are you sure?
        {
            temp.withdraw(amount); //Withdraw the money
            bank_obj.seekg(-sizeof(bank_card), ios_base::cur);
            bank_obj.write((char *)(&temp), sizeof(bank_card)); //Write the data
            cout << "Success!\n";
            cout << "Interest:" << temp.getinterest() << endl;
            log ltemp(account, 2, 0, -amount, temp.getinterest());
            log_obj.clear();
            log_obj.seekg(0, ios_base::end);
            log_obj.write((char *)(&ltemp), sizeof(log)); //Write the log
        }
        else //If you have regretted
            cout << "Cancelled\n";
    }
    else //You're too poor!
        cout << "You don't have enough money!\n";
    escape();
}
void Pay(int account, fstream &bank_obj, fstream &camp_obj, fstream &log_obj)
{
    Star();
    campus_card temp;
    camp_obj.clear();
    camp_obj.seekg(0);
    while (camp_obj.read((char *)(&temp), sizeof(campus_card))) //Find the account
        if (temp.isvalid() && temp.getnum() == account)
            break;
    cout << "Type:Campus Account\n";
    cout << "Account:" << account << endl;
    cout << "Function:Pay\n";
    cout << "Current interest:" << temp.getinterest() << endl;
    cout << "Enter the amount you wants to pay:";
    double amount;
    while ((amount = GetDouble()) < eps) //Amount should be positive
    {
        cout << "Money should be positive!\n";
        cout << "Enter the amount you wants to pay:";
    }
    camp_obj.clear();
    if (temp.getinterest() - amount > -eps) //If the money in the campus card is enough
    {
        if (confirm()) //Are you sure?
        {
            temp.withdraw(amount); //Withdraw the money
            camp_obj.seekg(-sizeof(campus_card), ios_base::cur);
            camp_obj.write((char *)(&temp), sizeof(campus_card)); //Write the data
            cout << "Success!\n";
            cout << "Interest:" << temp.getinterest() << endl;
            log ltemp(account, 12, 0, -amount, temp.getinterest());
            log_obj.clear();
            log_obj.seekg(0, ios_base::end);
            log_obj.write((char *)(&ltemp), sizeof(log)); //Write the log
        }
        else //If you have regretted
            cout << "Cancelled\n";
    }
    else //If the money in the campus caard is not enough
    {
        const int *bind = temp.getbind(); //Get the binded bank card
        int x;
        bank_card bktemp;
        for (x = 0; x < 3; x++) //Check if one card can afford the money
            if (bind[x])
            {
                bank_obj.clear();
                bank_obj.seekg(0);
                while (bank_obj.read((char *)(&bktemp), sizeof(bank_card))) //Find the bank card
                    if (bktemp.isvalid() && bktemp.getnum() == bind[x])
                        break;
                bank_obj.clear();
                if (bktemp.maxium() >= amount - temp.getinterest() - eps) //Check if the card can afford the money
                    break;
            }
        if (x != 3) //If there is one card can qualify the request
        {
            cout << "Using bank card:" << bind[x] << endl;
            if (confirm()) //Are you sure?
            {
                double trans = amount - temp.getinterest(); //Calculate how much should be withdrawn from bank card
                bktemp.withdraw(trans);                     //Withdraw from bank card
                bank_obj.seekg(-sizeof(bank_card), ios_base::cur);
                bank_obj.write((char *)(&bktemp), sizeof(bank_card)); //Write the bank card data
                temp.withdraw(temp.getinterest());                    //Withdraw from campus card
                camp_obj.seekg(-sizeof(campus_card), ios_base::cur);
                camp_obj.write((char *)(&temp), sizeof(campus_card)); //Write the campus card data
                cout << "Success!\n";
                cout << "Campus Interest:0.00\n";
                cout << "Bank Interest:" << bktemp.getinterest() << endl;
                log ltemp(bind[x], 6, account, -trans, bktemp.getinterest());
                log_obj.clear();
                log_obj.seekg(0, ios_base::end);
                log_obj.write((char *)(&ltemp), sizeof(log)); //Write the bank card log
                ltemp = log(account, 13, bind[x], trans, amount);
                log_obj.write((char *)(&ltemp), sizeof(log)); //Write the campus card log(in)
                ltemp = log(account, 12, 0, -amount, 0);
                log_obj.write((char *)(&ltemp), sizeof(log)); //Write the campus card log(out)
            }
            else //If you have regretted
                cout << "Cancelled\n";
        }
        else //You have no card which can afford it!
            cout << "You don't have enough money!\n";
    }
    escape();
}
void Transfer(int account, fstream &bank_obj, fstream &camp_obj, fstream &log_obj)
{
    Star();
    bank_card temp;
    bank_obj.clear();
    bank_obj.seekg(0);
    while (bank_obj.read((char *)(&temp), sizeof(bank_card))) //Find the account
        if (temp.isvalid() && temp.getnum() == account)
            break;
    cout << "Type:Bank Account\n";
    cout << "Account:" << account << endl;
    cout << "Function:Transfer\n";
    cout << "Current interest:" << temp.getinterest() << endl;
    cout << "Overdraft limit:" << temp.getlimit() << endl;
    cout << "Enter the account you wants to transfer into:"; //Get the target account
    int target;
    while ((target = GetInt()) < 10000000 || target >= 100000000 || target == account) //Check is the account is valid
    {
        cout << "Invalid number!\n";                             //If it is invalid
        cout << "Enter the account you wants to transfer into:"; //You shoould input it again
    }
    cout << "Enter the amount you wants to transfer:";
    double amount;
    while ((amount = GetDouble()) < eps) //Amount should be positive
    {
        cout << "Money should be positive!\n";
        cout << "Enter the amount you wants to transfer:";
    }
    bank_obj.clear();
    if (temp.maxium() - amount > -eps) //If you have enough money
    {
        if (target >= 50000000) //Transfer to bank account
        {
            size_t src_pos = bank_obj.tellg(); //Save the position
            bank_card tar;
            bank_obj.seekg(0);
            while (bank_obj.read((char *)(&tar), sizeof(bank_card))) //Find the target account
                if (tar.isvalid() && tar.getnum() == target)         //If found the account
                    break;
            if (bank_obj.eof()) //If failed to find the account
                cout << "Cannot find the target account!\n";
            else //If found the account
            {
                if (confirm()) //Are you sure?
                {
                    tar.deposit(amount); //Deposit money to the target account
                    bank_obj.seekg(-sizeof(bank_card), ios_base::cur);
                    bank_obj.write((char *)(&tar), sizeof(bank_card)); //Write the data
                    bank_obj.seekg(src_pos);                           //Back to the position
                    temp.withdraw(amount);                             //Withdraw money from the source account
                    bank_obj.seekg(-sizeof(bank_card), ios_base::cur);
                    bank_obj.write((char *)(&temp), sizeof(bank_card)); //Write the data
                    cout << "Success!\n";
                    cout << "Interest:" << temp.getinterest() << endl;
                    log ltemp(account, 3, target, -amount, temp.getinterest());
                    log_obj.clear();
                    log_obj.seekg(0, ios_base::end);
                    log_obj.write((char *)(&ltemp), sizeof(log)); //Write the source account log
                    ltemp = log(target, 7, account, amount, tar.getinterest());
                    log_obj.write((char *)(&ltemp), sizeof(log)); //Write the target account log
                }
                else //If you have regretted
                    cout << "Cancelled!\n";
            }
        }
        else //Transfer to campus account
        {
            campus_card tar;
            camp_obj.clear();
            camp_obj.seekg(0);
            while (camp_obj.read((char *)(&tar), sizeof(campus_card))) //Find the target account
                if (tar.isvalid() && tar.getnum() == target)           //If found the account
                    break;
            if (camp_obj.eof()) //If failed to find the account
                cout << "Cannot find the target account!\n";
            else //If found the account
            {
                if (confirm()) //Are you sure?
                {
                    tar.deposit(amount); //Deposit money to the target account
                    camp_obj.seekg(-sizeof(campus_card), ios_base::cur);
                    camp_obj.write((char *)(&tar), sizeof(campus_card)); //Write the data
                    temp.withdraw(amount);                               //Withdraw money from the source account
                    bank_obj.seekg(-sizeof(bank_card), ios_base::cur);
                    bank_obj.write((char *)(&temp), sizeof(bank_card)); //Write the data
                    cout << "Success!\n";
                    cout << "Interest:" << temp.getinterest() << endl;
                    log ltemp(account, 3, target, -amount, temp.getinterest());
                    log_obj.clear();
                    log_obj.seekg(0, ios_base::end);
                    log_obj.write((char *)(&ltemp), sizeof(log)); //Write the source account log
                    ltemp = log(target, 18, account, amount, tar.getinterest());
                    log_obj.write((char *)(&ltemp), sizeof(log)); //Write the target account log
                }
                else //If you have regretted
                    cout << "Cancelled!\n";
            }
        }
    }
    else //If you don't have enough money
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
    while (bank_obj.read((char *)(&temp), sizeof(bank_card))) //Find the account
        if (temp.isvalid() && temp.getnum() == account)
            break;
    bank_obj.clear();
    string old, t, n1, n2;
    old = temp.getpassword(); //Get the old password
    while (1)
    {
        cout << "Enter old password,\"quit\"to quit:\n";
        t = GetPassword(); //Get the input
        if (t == old)      //If the password is right
            break;
        else if (t == "quit") //If you want to quit
        {
            account = 0;
            break;
        }
        else //If you're wrong
            cout << "You're wrong!\n";
    }
    if (account) //If you don't want to quit
    {
        do
        {
            if (n1 != "")
                cout << "The two inputs are different!\n";
            cout << "Set the new password:\n";
            n1 = SetPassword();
            cout << "Confirm the new password:\n";
            n2 = SetPassword();
        } while (n1 != n2); //The two imputs should be same
        if (confirm())      //Are you sure?
        {
            temp.changepassword(n2.c_str()); //Change the password
            bank_obj.seekg(-sizeof(bank_card), ios_base::cur);
            bank_obj.write((char *)(&temp), sizeof(bank_card)); //Write the data
            cout << "Succeess!\n";
            log ltemp;
            if (account == 88888888)
                ltemp = log(account, 22, 0, 0, 0);
            else
                ltemp = log(account, 4, 0, 0, temp.getinterest());
            log_obj.clear();
            log_obj.seekg(0, ios_base::end);
            log_obj.write((char *)(&ltemp), sizeof(log)); //Write the log
        }
        else //If you have regretted
            cout << "Cancelled\n";
    }
    else //If you want to cancel
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
    while (camp_obj.read((char *)(&temp), sizeof(campus_card))) //Find the account
        if (temp.isvalid() && temp.getnum() == account)
            break;
    camp_obj.clear();
    string old, t, n1, n2;
    old = temp.getpassword(); //Get the old password
    while (1)
    {
        cout << "Enter old password,\"quit\"to quit:\n";
        t = GetPassword(); //Get the input
        if (t == old)      //If the password is right
            break;
        else if (t == "quit") //If you want to quit
        {
            account = 0;
            break;
        }
        else //If you're wrong
            cout << "You're wrong!\n";
    }
    if (account) //If you don't want to quit
    {
        do
        {
            if (n1 != "")
                cout << "The two input are different!\n";
            cout << "Set the new password:\n";
            n1 = SetPassword();
            cout << "Confirm the new password:\n";
            n2 = SetPassword();
        } while (n1 != n2); //The two imputs should be same
        if (confirm())      //Are you sure?
        {
            temp.changepassword(n2.c_str()); //Change the password
            camp_obj.seekg(-sizeof(campus_card), ios_base::cur);
            camp_obj.write((char *)(&temp), sizeof(campus_card)); //Write the data
            cout << "Succeess!\n";
            log ltemp;
            if (account == 44444444)
                ltemp = log(account, 27, 0, 0, 0);
            else
                ltemp = log(account, 14, 0, 0, temp.getinterest());
            log_obj.clear();
            log_obj.seekg(0, ios_base::end);
            log_obj.write((char *)(&ltemp), sizeof(log)); //Write the log
        }
        else //If you have regretted
            cout << "Cancelled\n";
    }
    else //If you want to cancel
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
    while (bank_obj.read((char *)(&temp), sizeof(bank_card))) //Find the account
        if (temp.isvalid() && temp.getnum() == account)       //If found
            break;
    bank_obj.clear();
    temp.ShowData(); //Show information of the account
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
    while (camp_obj.read((char *)(&temp), sizeof(campus_card))) //Find the account
        if (temp.isvalid() && temp.getnum() == account)         //If found
            break;
    camp_obj.clear();
    temp.ShowData(); //Show information of the account
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
    while (log_obj.read((char *)(&temp), sizeof(log))) //Scan the log file
        if (temp.num == account)                       //Find its log
            cout << temp.show() << endl;               //Print the log
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
    while (log_obj.read((char *)(&temp), sizeof(log))) //Scan the log file
        if (temp.num >= 50000000)                      //Find bank log
            cout << temp.show() << endl;               //Print the log
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
    while (log_obj.read((char *)(&temp), sizeof(log))) //Scan the log file
        if (temp.num < 50000000)                       //Find bank log
            cout << temp.show() << endl;               //Print the log
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
    while ((num = GetInt()) < 50000000 || num >= 100000000) //Check whether you can access the account
    {
        cout << "Account number should between 50000000 and 100000000!"; //If not
        cout << "Enter the bank account:";                               //You should enter it again
    }
    bank_card t;
    bank_obj.clear();
    bank_obj.seekg(sizeof(bank_card));
    while (bank_obj.read((char *)(&t), sizeof(bank_card))) //Find the account
    {
        if (t.isvalid() && t.getnum() == num) //If found the account
        {
            log_obj.clear();
            log_obj.seekg(0);
            log temp;
            while (log_obj.read((char *)(&temp), sizeof(log))) //Scan the log file
                if (temp.num == num)                           //Find its log
                    cout << temp.show() << endl;               //Print the log
            break;
        }
    }
    if (bank_obj.eof()) //If failed to find the account
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
    while ((num = GetInt()) < 10000000 || num >= 50000000) //Check whether you can access the account
    {
        cout << "Account number should between 10000000 and 50000000!"; //If not
        cout << "Enter the campus account:";                            //You should enter it again
    }
    campus_card t;
    camp_obj.clear();
    camp_obj.seekg(0);
    while (camp_obj.read((char *)(&t), sizeof(campus_card))) //Find the account
    {
        if (t.isvalid() && t.getnum() == num) //If found the account
        {
            log_obj.clear();
            log_obj.seekg(0);
            log temp;
            while (log_obj.read((char *)(&temp), sizeof(log))) //Scan the log file
                if (temp.num == num)                           //Find its log
                    cout << temp.show() << endl;               //Print the log

            break;
        }
    }
    if (camp_obj.eof()) //If failed to find the account
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
    while ((target = GetInt()) < 50000000 || target >= 100000000) //Check if the account is valid
    {
        cout << "Invalid number!\n";                    //If not
        cout << "Enter the account you wants to bind:"; //You should input it again
    }
    campus_card temp;
    bank_card tar;
    string pass;
    camp_obj.clear();
    camp_obj.seekg(0);
    while (camp_obj.read((char *)(&temp), sizeof(campus_card))) //Find the account
        if (temp.isvalid() && temp.getnum() == account)
            break;
    camp_obj.clear();
    const int *bind = temp.getbind();  //Get the binded bank card
    if (bind[0] && bind[1] && bind[2]) //If the campus card has binded 3 bank cards
        cout << "The campus card cannot bind new card!\n";
    else if (bind[0] == target || bind[1] == target || bind[2] == target) //If the bank card has been binded to the campus card
        cout << "The bank card has been binded to this card!\n";
    else //If the bank card is valid
    {
        bank_obj.clear();
        bank_obj.seekg(0);
        while (bank_obj.read((char *)(&tar), sizeof(bank_card))) //Find the bank account
            if (tar.isvalid() && tar.getnum() == target)         //If found the bank account
            {
                pass = tar.getpassword(); //Get the bank card's password
                break;
            }
        if (bank_obj.eof()) //If failed to find the bank account
            cout << "Cannot find the target account!\n";
        else //If found the bank account
        {
            cout << "Enter the password or enter \"quit\" to exit\n";
            string t = "";
            while (1)
            {
                t = GetPassword(); //Get the input
                if (t == pass)     //If the password is right
                    break;
                else if (t == "quit") //If you want to quit
                {
                    target = 0;
                    break;
                }
                else //If you're wrong
                    cout << "You're wrong!\n";
            }
            if (target && confirm()) //Are you sure?
            {
                temp.binding(target); //Bind the cards
                camp_obj.seekg(-sizeof(campus_card), ios_base::cur);
                camp_obj.write((char *)(&temp), sizeof(campus_card)); //Write the campus card data
                cout << "Success!\n";
                log ltemp(account, 15, target, 0, temp.getinterest());
                log_obj.clear();
                log_obj.seekg(0, ios_base::end);
                log_obj.write((char *)(&ltemp), sizeof(log)); //Write the bank card log
                ltemp = log(target, 8, account, 0, tar.getinterest());
                log_obj.write((char *)(&ltemp), sizeof(log)); //Write the campus card log
            }
            else //If you have regreted
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
    while (camp_obj.read((char *)(&temp), sizeof(campus_card))) //Find the account
        if (temp.isvalid() && temp.getnum() == account)
            break;
    camp_obj.clear();
    const int *bind = temp.getbind();    //Get the binded bank card
    cout << "The card you have binded:"; //Show the bank cards has been binded to the campus card
    bool i = 0;
    int x;
    for (x = 0; x < 3; x++)
        if (bind[x])
        {
            cout << bind[x] << " ";
            i = 1;
        }
    if (!i) //If no bank card has been binded to the campus card
        cout << "None\n";
    else //Otherwise
    {
        cout << endl;
        int target;
        cout << "Enter the account you wants to debind,0 to cancel:";
        while ((target = GetInt()) && target != bind[1] && target != bind[2] && target != bind[3]) //Check the input
        {
            cout << "Invalid card number!\n";                             //If the input isn't in the binding list
            cout << "Enter the account you wants to debind,0 to cancel:"; //You should input it again
        }
        if (target && confirm()) //Are you sure?
        {
            temp.debinding(target); //Debind the bank card
            camp_obj.seekg(-sizeof(campus_card), ios_base::cur);
            camp_obj.write((char *)(&temp), sizeof(campus_card)); //Write the campus card data
            cout << "Success!\n";
            log ltemp(account, 16, target, 0, temp.getinterest());
            log_obj.clear();
            log_obj.seekg(0, ios_base::end);
            log_obj.write((char *)(&ltemp), sizeof(log)); //Write the campus card log
            ltemp = log(target, 9, account, 0, tar.getinterest());
            log_obj.write((char *)(&ltemp), sizeof(log)); //Write the bank card log
        }
        else //If you have regretted
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
    while (num = GetInt()) //Get the account number
    {
        used = 0;
        if (num < 50000000 || num >= 100000000) //Check if the number is in the range
            cout << "Account number should between 50000000 and 100000000!\n";
        else
        {
            bank_obj.clear();
            bank_obj.seekg(0);
            while (bank_obj.read((char *)(&temp), sizeof(bank_card)))
            {
                if (temp.isvalid() && temp.getnum() == num) //Check if the number is used
                {
                    used = 1;
                    break;
                }
            }
            if (used) //If the number is used
                cout << "The number has been used!\n";
            else
                break;
        }
        cout << "Enter the bank account:";
    }
    cout << "Enter the user's name:";
    char name[30];
    cin.get(name, 30).get(); //Get the name
    char pass[7];
    strcpy(pass, SetPassword());          //Get the password
    cout << "Enter the overdraft limit:"; //Get the limit
    while ((lim = GetDouble()) < -eps)    //Limit can't be negative
    {
        cout << "Limit can't be negative!\n"; //Otherwise,you should enter it again
        cout << "Enter the overdraft limit:";
    }
    bank_card bc(name, num, pass, 1, lim); //Create the class
    if (confirm())                         //Are you sure?
    {
        bank_obj.clear(); // If you are sure
        bank_obj.seekg(0);
        while (bank_obj.read((char *)(&temp), sizeof(bank_card))) //Find a place to store it
        {
            if (!temp.isvalid()) //If there is a place in the middle
            {
                bank_obj.seekg(-sizeof(bank_card), ios_base::cur);
                bank_obj.write((char *)(&bc), sizeof(bank_card)); //Write it here
                break;
            }
        }
        if (bank_obj.eof()) //If there is no place in the middle
        {
            bank_obj.clear();
            bank_obj.write((char *)(&bc), sizeof(bank_card)); //Write it at the end
        }
        log ltemp(88888888, 19, num, 0, 0);
        log_obj.clear();
        log_obj.seekg(0, ios_base::end);
        log_obj.write((char *)(&ltemp), sizeof(log)); //Write the administrator log
        ltemp = log(num, 5, 0, 0, 0);
        log_obj.write((char *)(&ltemp), sizeof(log)); //Write the user log
        cout << "Success!\n";
    }
    else //If you have regretted
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
    while (num = GetInt()) //Get the account number
    {
        used = 0;
        if (num < 10000000 || num >= 50000000) //Check if the number is in the range
            cout << "Account number should between 10000000 and 50000000!";
        else
        {
            camp_obj.clear();
            camp_obj.seekg(0);
            while (camp_obj.read((char *)(&temp), sizeof(campus_card)))
            {
                if (temp.isvalid() && temp.getnum() == num) //Check if the number is used
                {
                    used = 1;
                    break;
                }
            }
            if (used) //If the number is used
                cout << "The number has been used!\n";
            else
                break;
        }
        cout << "Enter the campus account:";
    }
    cout << "Enter the user's name:";
    char name[30];
    cin.get(name, 30).get(); //Get the name
    char pass[7];
    strcpy(pass, SetPassword());        //Get the password
    campus_card bc(name, num, pass, 1); //Create the class
    if (confirm())                      //Are you sure?
    {
        camp_obj.clear(); //If you are sure
        camp_obj.seekg(0);
        while (camp_obj.read((char *)(&temp), sizeof(campus_card))) //Find a place to store it
        {
            if (!temp.isvalid()) //If there is a place in the middle
            {
                camp_obj.seekg(-sizeof(campus_card), ios_base::cur);
                camp_obj.write((char *)(&bc), sizeof(campus_card)); //Write it here
                break;
            }
        }
        if (camp_obj.eof()) //If there is no place in the middle
        {
            camp_obj.clear();
            camp_obj.write((char *)(&bc), sizeof(campus_card)); //Write it at the end
        }
        log ltemp(44444444, 24, num, 0, 0);
        log_obj.clear();
        log_obj.seekg(0, ios_base::end);
        log_obj.write((char *)(&ltemp), sizeof(log)); //Write the administrator log
        ltemp = log(num, 17, 0, 0, 0);
        log_obj.write((char *)(&ltemp), sizeof(log)); //Write the user log
        cout << "Success!\n";
    }
    else //If you have regretted
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
    while ((num = GetInt()) < 50000000 || num >= 100000000) //Get the account number
    {
        cout << "Account number should between 50000000 and 100000000!\n";
        cout << "Enter the bank account:"; //Check if the number is in the range
    }
    bank_card temp;
    bank_obj.clear();
    bank_obj.seekg(sizeof(bank_card));
    while (bank_obj.read((char *)(&temp), sizeof(bank_card))) //Search for the account
    {
        if (temp.isvalid() && temp.getnum() == num) //If it is found
        {
            temp.setvalid(0); //Set it invalid
            if (confirm())    //Are you sure?
            {
                bank_obj.seekg(-sizeof(bank_card), ios_base::cur);
                bank_obj.write((char *)(&temp), sizeof(bank_card)); //Write the bank card data
                campus_card cptemp;
                camp_obj.clear();
                camp_obj.seekg(0);
                log ltemp;
                log_obj.clear();
                log_obj.seekg(0, ios_base::end);
                while (camp_obj.read((char *)(&cptemp), sizeof(campus_card))) //Read the campus card
                    if (cptemp.isvalid())
                    {
                        const int *bind = cptemp.getbind();                     //Get the binded bank card
                        if (num == bind[0] || num == bind[1] || num == bind[2]) //If the campus card has binded to the deleted bank card
                        {
                            cptemp.debinding(num); //Debinding the card
                            camp_obj.seekg(-sizeof(campus_card), ios_base::cur);
                            camp_obj.write((char *)(&cptemp), sizeof(campus_card)); //Write the campus card data
                            ltemp = log(cptemp.getnum(), 16, num, 0, cptemp.getinterest());
                            log_obj.write((char *)(&ltemp), sizeof(log)); //Write the campus card log
                            ltemp = log(num, 9, cptemp.getnum(), 0, temp.getinterest());
                            log_obj.write((char *)(&ltemp), sizeof(log)); //Write the bank card log
                        }
                    }
                ltemp = log(88888888, 21, num, 0, 0);
                log_obj.write((char *)(&ltemp), sizeof(log)); //Write the bank administrator log
                cout << "Success!\n";
            }
            else //If you have regretted
                cout << "Cancelled\n";
            break;
        }
    }
    if (bank_obj.eof()) //If failed to find the account
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
    while ((num = GetInt()) < 10000000 || num >= 50000000) //Get the account number
    {
        cout << "Account number should between 10000000 and 50000000!";
        cout << "Enter the campus account:"; //Check if the number is in the range
    }
    campus_card temp;
    camp_obj.clear();
    camp_obj.seekg(sizeof(campus_card));
    while (camp_obj.read((char *)(&temp), sizeof(campus_card))) //Search for the account
    {
        if (temp.isvalid() && temp.getnum() == num) //If it is found
        {
            temp.setvalid(0); //Set it invalid
            if (confirm())    //Are you sure?
            {
                camp_obj.seekg(-sizeof(campus_card), ios_base::cur);
                camp_obj.write((char *)(&temp), sizeof(campus_card)); //Write the campus card data
                log ltemp(44444444, 26, num, 0, 0);
                log_obj.clear();
                log_obj.seekg(0, ios_base::end);
                log_obj.write((char *)(&ltemp), sizeof(log)); //Write the administrator log
                cout << "Success!\n";
            }
            else //If you have regretted
                cout << "Cancelled\n";
            break;
        }
    }
    if (camp_obj.eof()) //If failed to find the account
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
    while ((num = GetInt()) < 50000000 || num >= 100000000) //Get the account number
    {
        cout << "Account number should between 50000000 and 100000000!";
        cout << "Enter the bank account:"; //Check if the number is in the range
    }
    bank_card temp;
    bank_obj.clear();
    bank_obj.seekg(sizeof(bank_card));
    while (bank_obj.read((char *)(&temp), sizeof(bank_card))) //Search for the account
    {
        if (temp.isvalid() && temp.getnum() == num) //If it is found
        {
            temp.ShowData(); //Show its information
            break;
        }
    }
    if (bank_obj.eof()) //If failed to find the account
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
    while ((num = GetInt()) < 10000000 || num >= 50000000) //Get the account number
    {
        cout << "Account number should between 10000000 and 50000000!";
        cout << "Enter the campus account:"; //Check if the number is in the range
    }
    campus_card temp;
    camp_obj.clear();
    camp_obj.seekg(0);
    while (camp_obj.read((char *)(&temp), sizeof(campus_card))) //Search for the account
    {
        if (temp.isvalid() && temp.getnum() == num) //If it is found
        {
            temp.ShowData(); //Show its information
            break;
        }
    }
    if (camp_obj.eof()) //If failed to find the account
        cout << "No found!\n";
    escape();
}
void ChangeLimit(fstream &bank_obj, fstream &camp_obj, fstream &log_obj)
{
    Star();
    cout << "Type:Bank Administer\n";
    cout << "Account:88888888\n";
    cout << "Function:Change overdraft limit of a bank account\n";
    cout << "Enter the bank account:";
    int num;
    while ((num = GetInt()) < 50000000 || num >= 100000000) //Get the account number
    {
        cout << "Account number should between 50000000 and 100000000!";
        cout << "Enter the bank account:"; //Check if the number is in the range
    }
    bank_card temp;
    bank_obj.clear();
    bank_obj.seekg(sizeof(bank_card));
    while (bank_obj.read((char *)(&temp), sizeof(bank_card))) //Search for the account
    {
        if (temp.isvalid() && temp.getnum() == num) //If it is found
        {
            int nlim;
            cout << "The limit of the account:" << temp.getlimit() << endl;
            cout << "Enter the new limit:";
            while ((nlim = GetInt()) < 0) //Get the new limit
            {
                cout << "Limit can't be negative!\n"; //The limit can't be nagative
                cout << "Enter the new limit:";       //Otherwise you should enter it again
            }
            temp.changelimit(nlim); //Change the limit
            if (confirm())          //Are you sure?
            {
                bank_obj.seekg(-sizeof(bank_card), ios_base::cur);
                bank_obj.write((char *)(&temp), sizeof(bank_card)); //Write the data
                cout << "Success!\n";
                log ltemp(88888888, 30, num, 0, 0);
                log_obj.clear();
                log_obj.seekg(0, ios_base::end);
                log_obj.write((char *)(&ltemp), sizeof(log)); //Write the bank administrator log
                ltemp = log(num, 29, 0, 0, temp.getinterest());
                log_obj.write((char *)(&ltemp), sizeof(log)); //Write the bank user log
            }
            else //If you have regreted
                cout << "Cancelled!\n";
            break;
        }
    }
    if (bank_obj.eof()) //If failed to find the account
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
    cin >> name; //Get the filename
    char n[30], p[7];
    int acc, lim;
    bool used = 0;
    bank_card temp;
    log ltemp;
    log_obj.clear();
    log_obj.seekg(0, ios_base::end);
    ifstream fin(name.c_str(), ios_base::in); //Open the file
    if (fin.is_open())                        //If the file is opened
    {
        cout << "Successfully open the file!\n";
        while (fin.get(n, 30)) //Get the name
        {
            used = 0;
            fin >> acc >> lim >> p;                                                                //Get account number,overdraft limit and password
            if (acc < 100000000 && acc >= 50000000 && lim > -eps && strlen(p) == 6 && alldigit(p)) //Check whether the data is valid
            {
                bank_obj.clear(); //If the data is valid
                bank_obj.seekg(0);
                while (bank_obj.read((char *)(&temp), sizeof(bank_card))) //Check whether the account is used
                {
                    if (temp.isvalid() && temp.getnum() == acc) //If the account is used
                    {
                        used = 1;
                        break;
                    }
                }
                if (used) //If the account is used,failed to create the account
                    cout << "Failed to add user:" << n << endl;
                else
                {
                    temp = bank_card(n, acc, p, 1, lim); //Create the class
                    bank_obj.clear();
                    bank_obj.seekg(0, ios_base::end);
                    bank_obj.write((char *)(&temp), sizeof(bank_card)); //Write the data
                    cout << "Successfully add user:" << n << endl;
                    ltemp = log(88888888, 20, acc, 0, 0);
                    log_obj.write((char *)(&ltemp), sizeof(log)); //Write the bank administrator log
                    ltemp = log(acc, 5, 0, 0, 0);                 //
                    log_obj.write((char *)(&ltemp), sizeof(log)); //Write the bank card log
                }
                fin.get();
            }
            else //If the data is invalid
                cout << "Failed to add user:" << n << endl;
        }
        fin.close(); //Close the file
    }
    else //If failed to open the file
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
    cin >> name; //Get the filename
    char n[30], p[7];
    int acc;
    bool used;
    campus_card temp;
    log ltemp;
    log_obj.clear();
    log_obj.seekg(0, ios_base::end);
    ifstream fin(name.c_str(), ios_base::in); //Open the file
    if (fin.is_open())                        //If the file is opened
    {
        cout << "Successfully open the file!\n";
        camp_obj.clear();
        camp_obj.seekg(0, ios_base::end);
        while (fin.get(n, 30)) //Get the name
        {
            used = 0;
            fin >> acc >> p;                                                        //Get account numberand password
            if (acc < 50000000 && acc >= 10000000 && strlen(p) == 6 && alldigit(p)) //Check whether the data is valid
            {
                camp_obj.clear(); //If the data is valid
                camp_obj.seekg(0);
                while (camp_obj.read((char *)(&temp), sizeof(campus_card)))
                {
                    if (temp.isvalid() && temp.getnum() == acc) //If the account is used
                    {
                        used = 1;
                        break;
                    }
                }
                if (used) //If the account is used,failed to create the account
                    cout << "Failed to add user:" << n << endl;
                else
                {
                    camp_obj.clear();
                    camp_obj.seekg(0, ios_base::end);
                    temp = campus_card(n, acc, p, 1);                     //Create the class
                    camp_obj.write((char *)(&temp), sizeof(campus_card)); //Write the data
                    cout << "Successfully add user:" << n << endl;
                    ltemp = log(44444444, 25, acc, 0, 0);
                    log_obj.write((char *)(&ltemp), sizeof(log)); //Write the campus administrator log
                    ltemp = log(acc, 17, 0, 0, 0);
                    log_obj.write((char *)(&ltemp), sizeof(log)); //Write the campus card log
                }
                fin.get();
            }
            else //If the data is invalid
                cout << "Failed to add user:" << n << endl;
        }
        fin.close(); //Close the file
    }
    else //If failed to open the file
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
        cin.clear();               //Clear the failbit
        cin.ignore(999, '\n');     //Process the remaining input
        cout << "Enter a number:"; //You should enter the number again
        cin >> num;
    }
    cin.ignore(999, '\n'); //Process the remaining input
    return num;            //Return the valid input
}
double GetDouble(void)
{
    double num;
    cin >> num;
    while (cin.fail()) //If you enter an invalid input
    {
        cin.clear();               //Clear the failbit
        cin.ignore(999, '\n');     //Process the remaining input
        cout << "Enter a number:"; //You should enter the number again
        cin >> num;
    }
    cin.ignore(999, '\n'); //Process the remaining input
    return num;            //Return the valid input
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
    return temp.c_str();                 //Return the validinput as a TEMPORARY RVALUE
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
        system("stty echo");                                                              //Linux only.Cancel the hide of the input
        setvbuf(stdin, NULL, _IOFBF, 4096);                                               //Full buffer
        setvbuf(stdout, NULL, _IOFBF, 4096);                                              //Full buffer
    } while (temp.length() != 6 && temp.find_first_not_of("0123456789") == string::npos); //If the password isn't valid,you should enter again!
    return temp.c_str();                                                                  //Return the validinput as a TEMPORARY RVALUE
}
bool alldigit(const char *p)
{
    int x;
    for (x = 0; x < 6; x++) //We can sure that the length of the password is 6
        if (!isdigit(p[x]))
            return 0;
    return 1;
}
bool confirm(void)
{
    cout << "Do you confirm this operation?\n";
    cout << "Enter Y/y to confirm or other to cancel:";
    char ch = tolower(cin.get()); //Get the input
    cin.ignore(999, '\n');        //Process the remaining input
    if (ch == 'y')                //If confirmed
        return 1;                 //Return 1
    return 0;                     //Otherwise return 0
}
void escape(void)
{
    cout << "Press Enter to back to the main menu:";
    cin.ignore(999, '\n'); //Get enter and ignore the other input
}
void Star()
{
    for (int i = 0; i < 60; i++)
        cout << '*';
    cout << endl;
}