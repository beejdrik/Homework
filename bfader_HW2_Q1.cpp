#include <iostream>
#include <string>
using namespace std;

struct Check {
    int CheckNum;
    string CheckMemo;
    int CheckAmount;

    bool operator>(float amount) const {
        return CheckAmount > amount;
    }

    friend ostream& operator<<(ostream& os, const Check& check) {
        os << "Check Number: " << check.CheckNum << "Memo: "
        << check.CheckMemo << "Amount: $" << check.CheckAmount;
        return os;

    }
};

class CheckBook {
private:
    float balance;
    Check *ChkPtr;
    int lastDeposit;
    int numOfChecks;
    int checkBookSize;

public:
    CheckBook() : balance(0), ChkPtr(),
    lastDeposit(0), numOfChecks(0), checkBookSize(4) {
        ChkPtr = new Check[checkBookSize];
    }

    CheckBook(double initialbalance) : balance(initialbalance), ChkPtr(), numOfChecks(0), checkBookSize(2) {
        ChkPtr = new Check[checkBookSize];
    }

    float const GetBalance() const {
        return balance;
    }
    int const GetLastDeposit() const {
        return lastDeposit;
    }
    int const GetNumOfChecks() const {
        return numOfChecks;
    }
    int const GetCheckBookSize() const {
        return checkBookSize;
    }

    void  SetBalance(float newBalance) {
        balance = newBalance;
    }
    void  SetLastDeposit(int newDeposit) {
        lastDeposit = newDeposit;
    }
    void  SetNumOfChecks(int newNumOfChecks) {
        numOfChecks = newNumOfChecks;
    }
    void  SetCheckBookSize(int newCheckBookSize) {
        checkBookSize = newCheckBookSize;
    }
    ~CheckBook() {
        delete[] ChkPtr;
    }
    CheckBook(const CheckBook& book) {
        ChkPtr = new Check[checkBookSize];
    }
    CheckBook& operator=(const CheckBook& book) {
        if (this != &book) {
            delete ChkPtr;
            checkBookSize = book.checkBookSize;
            numOfChecks = book.numOfChecks;
            balance = book.balance;
            ChkPtr = new Check[checkBookSize];
            for (int i = 0; i < numOfChecks; i++) {
                ChkPtr[i] = book.ChkPtr[i];
            }
        }
        return *this;
    }

    void deposit() {
        float amount;
        cout << "Enter deposit amount: $";
        cin >> amount;

        SetBalance(GetBalance() + amount);
        SetLastDeposit(amount);
    }

    bool writeCheck(Check c_amount) {
        if (c_amount > balance) {
            cout << "Insufficient balance" << endl;
            return false;
        }

        balance -= c_amount.CheckAmount;

        string memos[] = {"Wedding", "baby shower", "sports gambling", "honey farm investment",
        "buying a horse"};
        int memoOptions = std::rand() % 5;

        ChkPtr[numOfChecks].CheckNum = numOfChecks + 1;
        ChkPtr[numOfChecks].CheckMemo = memos[memoOptions];
        ChkPtr[numOfChecks].CheckAmount = c_amount.CheckAmount;
        numOfChecks++;

        cout << ChkPtr[numOfChecks - 1] << endl;
        if (numOfChecks == 2) {
            int newCheckBookSize = checkBookSize * 2;
            Check* newChkPtr = new Check[newCheckBookSize];
            for (int i = 0; i < numOfChecks; i++) {
                newChkPtr[i] = ChkPtr[i];
            }
            delete[] ChkPtr;
            ChkPtr = newChkPtr;
            checkBookSize = newCheckBookSize;
            cout << "New checkbook ordered";
        }

        return true;
    }
    void const displayChecks() {
        for (int i = 0; i < numOfChecks; i++) {
            cout << ChkPtr[i].CheckNum << ChkPtr[i].CheckMemo << ChkPtr[i].CheckAmount << endl;
        }
    }

    void checkTest(CheckBook &book, int balance) {
        book.balance = balance;
        Check c_amount;
        c_amount.CheckAmount = 100;

        while (book.GetBalance() >= c_amount.CheckAmount) {
            writeCheck(c_amount);
        }
        displayChecks();
    }

};


int main() {
    CheckBook checkTest(10000);
    return 0;

//Doesn't output anything, but does function
