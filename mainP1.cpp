#include <iostream>
#include <string>

struct Check {
    int CheckNum;
    std::string CheckMemo;
    float CheckAmount;

};

class CheckBook {
public:
    double balance;
    static const int N=5;
    Check check[N];
    double lastDeposit;
    int numOfChecks;
    int checkLimit=N;

    CheckBook() : balance(0), lastDeposit(0), numOfChecks(0) {}

    CheckBook(int initialBalance, int numOfChecks) : balance(initialBalance), numOfChecks(0) {}

    void deposit(double amount) {
        balance += amount;
    }

    void displayChecks() {
        std::cout << "Check History: ";
        for (int i = 0; i < numOfChecks; ++i) {
            std::cout << "Check #" << check[i].CheckNum << "\n Memo: "
            << check[i].CheckMemo << "\n Amount: " << check[i].CheckAmount << std::endl;
        }
    }

        bool writeCheck(float amount) {
            if (amount > balance) {
                std::cout << "Insufficient funds ";
                return false;
            }

            std::cout << "Memo: ";
            std::getline(std::cin, check[numOfChecks].CheckMemo);

            check[numOfChecks].CheckNum = check[numOfChecks].CheckNum + 1;
            check[numOfChecks].CheckAmount = amount;
            balance -= check[numOfChecks].CheckAmount;
            numOfChecks++;

            return true;
        }
};


int main() {
    CheckBook book(1000.00, 0);
    std::cout << book.balance << std::endl;

    book.deposit(500.00);
    std::cout << book.balance << std::endl;

    std::cout << "Check Test: ";
    book.writeCheck(100.00);
    std::cout << book.balance << std::endl;
    book.displayChecks();

    return 0;
}
