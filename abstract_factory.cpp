#include<iostream>
#include<string>
using namespace std;

// Abstract Products
class car{
public:
    virtual void drive() = 0;
};

class truck{
public:
    virtual void drive() = 0;
};

class bus{
public:
    virtual void drive() = 0;
};

//Concrete Products
class tataCar : public car {
public:
    void drive() override{
        cout<<"Driving TATA Car\n";
    }
};

class tataTruck : public truck {
public:
    void drive() override{
        cout<<"Driving TATA Truck\n";
    }
};

class tataBus : public bus {
public:
    void drive() override{
        cout<<"Driving TATA Bus\n";
    }
};

class volvoCar : public car {
public:
    void drive() override{
        cout<<"Driving Volvo Car\n";
    }
};

class volvoTruck : public truck {
public:
    void drive() override{
        cout<<"Driving Volvo Truck\n";
    }
};

class volvoBus : public bus {
public:
    void drive() override{
        cout<<"Driving Volvo Bus\n";
    }
};

//Abstract Factory
class vehicleFactory{
public:
    virtual bus* createBus() = 0;
    virtual car* createCar() = 0;
    virtual truck* createTruck() = 0;

    static vehicleFactory* createFactory(string company);
    /*{
        if (company == "TATA") {
            return new TataFactory();
        } else if (company == "Volvo") {
            return new volvoFactory();
        } else 
            return nullptr;
    }*/
};

//concrete Factory
class TataFactory : public vehicleFactory {
public:
    bus* createBus() override {
        return new tataBus();
    }
    truck* createTruck() override {
        return new tataTruck();
    }
    car* createCar() override {
        return new tataCar();
    }
};

class volvoFactory : public vehicleFactory {
public:
    bus* createBus() override {
        return new volvoBus();
    }
    truck* createTruck() override {
        return new volvoTruck();
    }
    car* createCar() override {
        return new volvoCar();
    }
};

vehicleFactory* vehicleFactory::createFactory(string company){
    if (company == "TATA") {
        return new TataFactory();
    } else if (company == "Volvo") {
        return new volvoFactory();
    } else 
        return nullptr;
}

int main(){
    vehicleFactory *volvoF = vehicleFactory::createFactory("Volvo");
    vehicleFactory *TataF = vehicleFactory::createFactory("TATA");
    car* Car = volvoF->createCar();
    Car->drive();
    delete Car;
    delete volvoF;
    delete TataF;.
}