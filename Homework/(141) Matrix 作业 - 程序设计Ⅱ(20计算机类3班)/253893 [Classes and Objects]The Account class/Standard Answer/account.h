class Account {
private:
    int id;
    double balance, annualInterestRate;

public:
    Account() {
        id = 0;
        balance = 0;
        annualInterestRate = 0;
    }

    int getId() {
        return id;
    }

    double getBalance() {
        return balance;
    }

    double getAnnualInterestRate() {
        return annualInterestRate;
    }

    void setId(int id) {
        this->id = id;
    }

    void setBalance(double balance) {
        this->balance = balance;
    }
    void setAnnualInterestRate(double annualInterestRate) {
        this->annualInterestRate = annualInterestRate;
    }

    double getMonthlyInterestRate() {
        return annualInterestRate / 12.0;
    }

    void withDraw(double withDraw) {
        balance -= withDraw;
    }

    void deposit(double deposit) {
        balance += deposit;
    }
};