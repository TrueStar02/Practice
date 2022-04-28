#ifndef LOG_H_
#define LOG_H_
#include <iostream>
#include <sstream>
#include <ctime>
using namespace std;
class log
{
public:
    time_t tm;
    int num;
    int target;
    int type;
    double delta;
    double remain;
    log() {}
    log(int n, int tp, int tar, double d, double r) : num(n), type(tp), target(tar), delta(d), remain(r) { tm = time(0); }
    string show();
};
string log::show()
{
    ostringstream strout;
    strout.setf(ios_base::fixed, ios_base::floatfield);
    strout.precision(2);
    strout << ctime(&tm);
    switch (type)
    {
    case 1:
        strout << "Bank card:" << num << " Deposit RMB" << delta << " Interest:" << remain;
        break;
    case 2:
        strout << "Bank card:" << num << " Withdraw RMB" << -delta << " Interest:" << remain;
        break;
    case 3:
        strout << "Bank card:" << num << " Transfer RMB" << -delta << " To " << target << " Interest:" << remain;
        break;
    case 4:
        strout << "Bank card:" << num << " Change the password";
        break;
    case 5:
        strout << "Bank card:" << num << " is created";
        break;
    case 6:
        strout << "Bank card:" << num << " is withdrawn RMB" << -delta << " By " << target << " Interest:" << remain;
        break;
    case 7:
        strout << "Bank card:" << num << " is transferred RMB" << delta << " By " << target << " Interest:" << remain;
        break;
    case 8:
        strout << "Bank card:" << num << " is binded to " << target;
        break;
    case 9:
        strout << "Bank card:" << num << " is debinded to " << target;
        break;
    case 10:
        strout << "Campus card:" << num << " Deposit RMB" << delta << " Interest:" << remain;
        break;
    case 11:
        strout << "Campus card:" << num << " Deposit RMB" << delta << " From " << target << " Interest:" << remain;
        break;
    case 12:
        strout << "Campus card:" << num << " Pay RMB" << -delta << " Interest:" << remain;
        break;
    case 13:
        strout << "Campus card:" << num << " Get RMB" << delta << " From " << target << " Interest:" << remain;
        break;
    case 14:
        strout << "Campus card:" << num << " Change the password";
        break;
    case 15:
        strout << "Campus card:" << num << " bind card " << target;
        break;
    case 16:
        strout << "Campus card:" << num << " debind card " << target;
        break;
    case 17:
        strout << "Campus card:" << num << " is created";
        break;
    case 18:
        strout << "Campus card:" << num << " is transferred RMB" << delta << " By " << target << " Interest:" << remain;
        break;
    case 19:
        strout << "Bank Administrator create an account " << target << " Manually";
        break;
    case 20:
        strout << "Bank Administrator create an account " << target << " Automatically";
        break;
    case 21:
        strout << "Bank Administrator delete an account " << target;
        break;
    case 22:
        strout << "Bank Adminitrator Change the password";
        break;
    case 23:
        strout << "Bank Adminitrator account is created";
        break;
    case 24:
        strout << "Campus Administrator create an account " << target << " Manually";
        break;
    case 25:
        strout << "Campus Administrator create an account " << target << " Automatically";
        break;
    case 26:
        strout << "Campus Administrator delete an account " << target;
        break;
    case 27:
        strout << "Campus Adminitrator Change the password";
        break;
    case 28:
        strout << "Campus Adminitrator account is created";
        break;
    }
    return strout.str();
}
#endif