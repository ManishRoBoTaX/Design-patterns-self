#include <iostream>

using namespace std;

class vehicle {
public:
    virtual void display() = 0;
};

class car : public vehicle{
public:
    void display() override {
        cout<<"This is a CAR\n";
    }
};

class bike : public vehicle{
public:
    void display() override {
        cout<<"This is a BIKE\n";
    }
};

class bus : public vehicle{
public:
    void display() override {
        cout<<"This is a BUS\n";
    }
};

class vehicleFactory {
public:
    virtual vehicle* create() = 0;
};

class carFactory:public vehicleFactory {
public:
    vehicle* create(){
        return new car;
    }
};

class bikeFactory:public vehicleFactory {
public:
    vehicle* create(){
        return new bike;
    }
};

class busFactory:public vehicleFactory {
public:
    vehicle* create(){
        return new bus;
    }
};

int main() {
    vehicleFactory* CarFactory = new carFactory();
    vehicleFactory* BikeFactory = new bikeFactory();
    vehicleFactory* BusFactory = new busFactory();

    vehicle* Car = CarFactory->create();
    vehicle* Bus = BusFactory->create();
    vehicle* Bike = BikeFactory->create();

    Bike->display();
    Bus->display();
    Car->display();

    delete CarFactory;
    delete BikeFactory;
    delete BusFactory;
    delete Car;
    delete Bike;
    delete Bus;
}