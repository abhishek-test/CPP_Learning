
#include <iostream>

using namespace std;

class PaymentMethod {
public:
    virtual void pay(double amount) = 0;
};

class CreditCard : public PaymentMethod {
public:
    void pay(double amount) override {
        std::cout << "Paid " << amount << " using CC" << std::endl;
    }
};

class UPI : public PaymentMethod {
public:
    void pay(double amount) override {
        std::cout << "Paid " << amount << " using UPI" << std::endl;
    }
};

void checkout(PaymentMethod *method, double amount) {
    method->pay(amount);
}

int main() {

    /*
    CreditCard cc;
    UPI upi;

    checkout(&cc, 100);
    checkout(&upi, 1000);
    */

   PaymentMethod *ptrCC = new CreditCard();
   PaymentMethod *ptrUPI = new UPI();

   checkout(ptrCC, 100);
   checkout(ptrUPI, 1000);

}