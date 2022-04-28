class Account
{   private:
        int id;
        double balance;
        double annualInterestRate;
    public:
        Account():id(0),balance(0),annualInterestRate(0){}
         void setId(int x){id=x;}
        void setBalance(double x){balance=x;}
         void setAnnualInterestRate(double x){annualInterestRate=x;}
         int getId()const{return id;}
       double getBalance()const{return balance;}
        double getMonthlyInterestRate() const{return annualInterestRate/12;}
        void withDraw(double x)  {balance-=x;}
        void deposit(double x)  {balance+=x;}
};