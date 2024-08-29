#include<iostream>

using namespace std;

class TV {
public:
    virtual void on() =0;
    virtual void off() = 0;
    virtual void changeChannel(int) = 0;
    virtual ~TV() = default;
};

class SonyTv : public TV {
public:
    void on() override {
        cout<<"SONY TV is ON!!!\n";
    }

    void off() override{
        cout<<"SONY TV is OFF!!!\n";
    }

    void changeChannel(int channel) override {
        cout<<"SONY TV channel changed to "<<channel<<endl;
    }
};

class SamsungTv : public TV {
public:
    void on() override {
        cout<<"SAMSUNG TV is ON!!!\n";
    }

    void off() override{
        cout<<"SAMSUNG TV is OFF!!!\n";
    }

    void changeChannel(int channel) override {
        cout<<"SAMSUNG TV channel changed to "<<channel<<endl;
    }
};

class Remote {
protected:
    TV* tv;
public:
    Remote(TV* tv) : tv(tv) {};
    virtual void tv_on(){
        tv->on();
    }
    virtual void tv_off() {
        tv->off();
    }
    virtual void setChannel(int channel){
        tv->changeChannel(channel);
    }
};

class AdvancedRemote:public Remote {
public:
    AdvancedRemote(TV *tv) : Remote(tv) {};
    void mute(){
        cout<<"TV is mute\n";
    }
};

int main() {
    SamsungTv stv;
    SonyTv sotv;
    Remote *r1 = new Remote(&stv);
    AdvancedRemote *r2 = new AdvancedRemote(&sotv);

    r1->tv_on();
    r1->setChannel(105);
    r1->tv_off();

    r2->tv_on();
    r2->setChannel(143);
    r2->mute();
    r2->tv_off();

    delete r1,r2;
}