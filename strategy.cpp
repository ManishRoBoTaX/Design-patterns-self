#include<iostream>

using namespace std;

class paymentStrategy {
public:
    virtual ~paymentStrategy() = default;
    virtual void pay(int amt) = 0;
};

class cardPayment: public paymentStrategy {
public:
    void pay(int amt) override {
        cout<<"Card Payment of amount $"<<amt<<endl;
    }
};

class upiPayment: public paymentStrategy {
public:
    void pay(int amt) override {
        cout<<"UPI Payment of amount $"<<amt<<endl;
    }
};

class cart {
private:
    paymentStrategy *strategy;
public:
    cart() : strategy(nullptr) {};

    void setPaymetStrategy(paymentStrategy *strategy) {
        this->strategy = strategy;
    }

    void checkout(int amount) const {
        if (strategy)
            strategy->pay(amount);
        else    
            cout<<"Payment Mentoh Not Selected \n";
    }
};

int main() {
    cart shoppingCart ;

    shoppingCart.setPaymetStrategy(new upiPayment());
    shoppingCart.checkout(100);

    shoppingCart.setPaymetStrategy(new cardPayment());
    shoppingCart.checkout(700);

    return 0;
}