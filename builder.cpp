#include<iostream>
#include<string>

using namespace std;

//Product
class tataCar {
public:
    string engine;
    string wheels;
    string color;
    bool adas;
    int airbag;

    void display(){
        cout<<"---Car Specifications---\n";
        cout<<"Engine : "<<engine<<endl;
        cout<<"Wheels : "<<wheels<<endl;
        cout<<"Colour : "<<color<<endl;
        cout<<"Has ADAS : "<<adas<<endl;
        cout<<"Airbags : "<<airbag<<endl;
        cout<<"------------------------\n";
    }

};

//Abstract Builder
class tataCarBuilder {
protected:
    tataCar car;
public:
    virtual void buildEngine() = 0;
    virtual void buildWheels() = 0;
    virtual void setColor() = 0;
    virtual void setAdas() = 0;
    virtual void setAirbags() = 0;

    tataCar getCar() {
        return car;
    }
};

//concrete Builder 1
class altrozBuilder : public tataCarBuilder {
public:
    void buildEngine() override {
        car.engine = "V4";
    }
    void buildWheels() override {
        car.wheels = "CEAT";
    }
    void setColor() override {
        car.color = "Black";
    }
    void setAdas() override {
        car.adas = false;
    }
    void setAirbags() override {
        car.airbag = 2;
    }
}; 

//Concrete builder 2
class safariBuilder : public tataCarBuilder {
public:
    void buildEngine() override {
        car.engine = "V8";
    }
    void buildWheels() override {
        car.wheels = "MRF";
    }
    void setColor() override {
        car.color = "Army";
    }
    void setAdas() override {
        car.adas = true;
    }
    void setAirbags() override {
        car.airbag = 6;
    }
};

//Builder Director
class tataCarDirector {
public:
    tataCar buildCar(tataCarBuilder &builder) {
        builder.buildEngine();
        builder.buildWheels();
        builder.setColor();
        builder.setAdas();
        builder.setAirbags();
        return builder.getCar();
    }
};

int main() {
    tataCarDirector Director;
    altrozBuilder aBuild;
    tataCar altroz = Director.buildCar(aBuild);
    safariBuilder sBuild;
    tataCar safari = Director.buildCar(sBuild);
    altroz.display();
    cout<<endl;
    safari.display();
}