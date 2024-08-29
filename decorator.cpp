#include<iostream>

using namespace std;

//component interface
class Beverage {
public:
    virtual string getDescription() = 0;
    virtual double cost() = 0;
    virtual ~Beverage() = default;
};
//concrete interface
class Espresso : public Beverage {
public:
    string getDescription() override{
        return "Espresso";
    }
    double cost() override {
        return 1.69;
    }
};

//Decorator interface
class BeverageDecorator:public Beverage{
protected:
    Beverage *bev;
public:
    BeverageDecorator(Beverage* bev) : bev(bev) {};
};

//concrete decorator
class Milk: public BeverageDecorator {
public:
    Milk(Beverage* bev) : BeverageDecorator(bev) {};
    string getDescription() override{
        return bev->getDescription() + " + Milk";
    }

    double cost() override {
        return 0.3 + bev->cost();
    }
};
class Sugar: public BeverageDecorator {
public:
    Sugar(Beverage* bev) : BeverageDecorator(bev) {};
    string getDescription() override{
        return bev->getDescription() + " + Sugar";
    }

    double cost() override {
        return 0.1 + bev->cost();
    }
};
class Mocha: public BeverageDecorator {
public:
    Mocha(Beverage* bev) : BeverageDecorator(bev) {};
    string getDescription() override{
        return bev->getDescription() + " + Mocha";
    }

    double cost() override {
        return 0.4 + bev->cost();
    }
};

int main() {
    Beverage* b1 = new Espresso();
    b1 = new Milk(b1);
    b1 = new Sugar(b1);
    b1 = new Mocha(b1);

    cout<<b1->getDescription()<<endl;
    cout<<b1->cost()<<endl;

    delete b1;

}