#include <iostream>
#include <string>
using namespace std;

// Class creation, get and set functions
class Check {
public:
    int CheckNum;
    std::string CheckMemo;
    float CheckAmount;

    int getCheckNum() const {
        return CheckNum;
    }
    std::string getCheckMemo() const {
        return CheckMemo;
    }
    float getCheckAmount() const {
        return CheckAmount;
    }

    void setCheckNum(int num) {
        CheckNum = num;
    }
    void setCheckMemo(std::string memo) {
        CheckMemo = memo;
    }
    void setCheckAmount(float amount) {
        CheckAmount = amount;
    }
    static int number;
    Check() : CheckNum(0), CheckMemo(""), CheckAmount(0) {
        number++;
    } // Constructor initialization and number incrimentation

};

//Checkbook class
class CheckBook {
public:

    static const int N=5;
    Check check[N]; //Array creation
    int checkLimit=N;
    double lastDeposit;

    int numOfChecks;
    static int allChecks;
    double balance;

    static int getallChecks() {
        return allChecks; //Get function
    }

    CheckBook() : balance(0), lastDeposit(0), numOfChecks(0) {} //Basic Constructor

    CheckBook(int initialBalance, int numOfChecks) : balance(initialBalance), numOfChecks(0) {}
    //Initialization list constructor

    void deposit(double amount) {
        balance += amount;  //Add and replace
    }

    void displayChecks() {
        std::cout << "Check History: ";
        for (int i = 0; i < numOfChecks; ++i) {
            std::cout << "Check #" << check[i].CheckNum << "\n Memo: "
            << check[i].CheckMemo << "\n Amount: " << check[i].CheckAmount << std::endl;
        } //Sets i to 0, repeates as long as i < numOfChecks is true, adds 1 each repetition
    }

    bool writeCheck(float amount) {
        if (numOfChecks < N && allChecks < 10 && balance > amount) {
            // Sets limit on check #s, all checks, and ensures there's enough money to pay the check

            std::cout << "Memo: ";
            std::getline(std::cin, check[numOfChecks].CheckMemo);

            check[numOfChecks].CheckAmount = amount;
            balance -= check[numOfChecks].CheckAmount;
            numOfChecks++;
            check[numOfChecks].CheckNum = check[numOfChecks].CheckNum + 1;

            return true;
        }

        return false;
    }
    };

int CheckBook::allChecks = 0; //Unfourtanatly I don't fully understand what I'm supposed to do with these
int Check::number = 0; // So I did this to make the program function


    int main() {

            CheckBook cb1(1000, 0), cb2(500, 0);
            for(int i=0; i<10;i++)
            {
                cb1.writeCheck(150);
                cb2.writeCheck(130);
            }
            cout<<"cb1 check details"<<endl;
            cb1.displayChecks();
            cout<<"cb2 check details"<<endl;
            cb2.displayChecks();
            cout<<cb1.getallChecks()<<endl;
            cout<<cb2.getallChecks()<<endl;


        return 0;
    }
