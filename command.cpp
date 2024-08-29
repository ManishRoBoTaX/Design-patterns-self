#include<iostream>
#include<vector>

using namespace std;

//command Interface
class command {
public:
    virtual void execute() = 0;
};

class Light {
public:
    void lightOn() {
        cout<<"Light ON!!!\n";
    }
    void lightOff() {
        cout<<"Light OFF!!!\n";
    }
};

class turnLightOn : public command {
private:
    Light *light;
public:
    turnLightOn(Light *light) : light(light) {};
    void execute () override{
        light->lightOn();
    }
};

class turnLightOff : public command {
private:
    Light *light;
public:
    turnLightOff(Light *light) : light(light) {};
    void execute () override{
        light->lightOff();
    }
};

class Switch {
private:
    vector<command*> commands;
public:
    void addCommand(command* Command){
        commands.push_back(Command);
    }
    void process(){
        commands.back()->execute();
        commands.pop_back();
    }
};

int main(){
    Light *l;
    turnLightOn* on = new turnLightOn(l);
    turnLightOff* off = new turnLightOff(l);

    Switch s;
    s.addCommand(off);
    s.addCommand(on);

    s.process();
    s.process();

    delete l;
    delete on;
    delete off;
}