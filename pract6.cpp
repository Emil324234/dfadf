#include <iostream> 


class BankAccount
{
private:
    int accountNumber;
    double balance;
    double interestRate;

public:
    BankAccount(int Numberaccount, double balancee)
    {
        this->accountNumber = Numberaccount;
        this->balance = balancee;
        this->interestRate = 0.0;
    }

    void deposit(double amount)
    {
        if (amount > 0)
        {
            this->balance += amount;
            std::cout << "Successful deposit" << this->balance << std::endl;
        }
        else
        {
            std::cout << "no no no no" << std::endl;
        }
    }

    void withdraw(double amount)
    {
        if (amount > 0 && amount <= this->balance)
        {
            this->balance -= amount;
            std::cout << "Successful withdraw" << this->balance << std::endl;
        }
        else
        {
            std::cout << "no no no no" << std::endl;
        }
    }

    double getBalance() const
    {
        return this->balance;
    }

    double getInterest() const
    {
        double interest = this->balance * this->interestRate * (1.0 / 12.0);
        return interest;
    }

    void setInterestRate(double rate)
    {
        this->interestRate = rate;
    }

    int getAccountNumber() const
    {
        return this->accountNumber;
    }

    static bool transfer(BankAccount& from, BankAccount& to, double amount)
    {
        if (amount > 0 && amount <= from.balance)
        {
            from.withdraw(amount);
            to.deposit(amount);
            return true;
        }
        else
        {
            std::cout << "no no no no" << std::endl;
            return false;
        }
    }
};

int main()
{
    BankAccount firstaccount(123, 300);
    BankAccount secondaccount(567, 500);

    firstaccount.deposit(300);
    secondaccount.withdraw(100);
    firstaccount.setInterestRate(0.05);
    std::cout << "FirstAccount balance: " << firstaccount.getBalance() << std::endl;
    std::cout << "FirstAccount interest: " << firstaccount.getInterest() << std::endl;

    BankAccount::transfer(firstaccount, secondaccount, 150.0);

    return 0;
}