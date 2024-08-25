#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

class Account {
private:
    string lastName;
    int accountNumber;
    double interestRate;
    double deductionRate;
    double balance;
    static int accountCount;

public:
    Account(string ln, int accNum, double intRate, double dedRate, double bal)
        : lastName(ln), accountNumber(accNum), interestRate(intRate), deductionRate(dedRate), balance(bal) {
        accountCount++;
    }

    ~Account() {
        accountCount--;
    }

    string getLastName() const { return lastName; }
    int getAccountNumber() const { return accountNumber; }
    double getInterestRate() const { return interestRate; }
    double getDeductionRate() const { return deductionRate; }
    double getBalance() const { return balance; }
    static int getAccountCount() { return accountCount; }

    void setLastName(const string& ln) { lastName = ln; }
    void setInterestRate(double rate) { interestRate = rate; }
    void setDeductionRate(double rate) { deductionRate = rate; }
    void setBalance(double bal) { balance = bal; }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "Недостатньо коштів на рахунку." << endl;
        }
    }

    void applyInterest() {
        balance += balance * (interestRate / 100);
    }

    double convertToDollars(double exchangeRate) const {
        return balance / exchangeRate;
    }

    double convertToEuros(double exchangeRate) const {
        return balance / exchangeRate;
    }

    string balanceInWords() const {
        ostringstream oss;
        oss << fixed << setprecision(2) << balance;
        return oss.str() + " гривень";
    }
};

int Account::accountCount = 0;

int main() {
    Account acc1("Shevchenko", 123456, 5.0, 2.0, 10000.0);
    
    cout << "Прізвище власника: " << acc1.getLastName() << endl;
    cout << "Номер рахунку: " << acc1.getAccountNumber() << endl;
    cout << "Сума на рахунку: " << acc1.getBalance() << " грн" << endl;

    acc1.deposit(2000.0);
    cout << "Після поповнення, сума на рахунку: " << acc1.getBalance() << " грн" << endl;

    acc1.withdraw(1500.0);
    cout << "Після зняття, сума на рахунку: " << acc1.getBalance() << " грн" << endl;

    acc1.applyInterest();
    cout << "Після нарахування відсотків, сума на рахунку: " << acc1.getBalance() << " грн" << endl;

    double dollarRate = 36.5;  // умовний курс гривні до долара
    cout << "Сума в доларах: " << acc1.convertToDollars(dollarRate) << " USD" << endl;

    double euroRate = 39.2;  // умовний курс гривні до євро
    cout << "Сума в євро: " << acc1.convertToEuros(euroRate) << " EUR" << endl;

    cout << "Сума прописом: " << acc1.balanceInWords() << endl;

    cout << "Кількість створених об'єктів Account: " << Account::getAccountCount() << endl;

    return 0;
}
