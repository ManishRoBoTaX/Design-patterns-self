#include <iostream>

using namespace std;

class logger {
    public:
    virtual void print() = 0;
};

class errorLogger : public logger {
    void print() {
        cout<<"Error Logged\n";
    }
};
class infoLogger : public logger {
    void print() {
        cout<<"Info Logged\n";
    }
};
class warnLogger : public logger {
    void print() {
        cout<<"Warning Logged\n";
    }
};

class createLooger{
    public:
    logger* create(string s) {
         if (s=="INFO")
            return new infoLogger();
        else if (s=="ERROR")
            return new errorLogger();
        else 
            return new warnLogger();
    }
};


int main () {
    logger *info, *error, *warn;
    createLooger *factory;
    info = factory->create("INFO");
    error = factory->create("ERROR");
    warn = factory->create("WARN");
    error->print();
    warn->print();
    info->print();
    return 0;
}