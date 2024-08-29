#include<iostream>

using namespace std;
//modern interface
class IPrinter{
public:
    virtual void print(string data) = 0;
    virtual ~IPrinter() = default;
};
//legacey interface
class oldPrinter{
public:
    void oldPrint(string data) {
        cout<<"Printing Old : "<<data<<endl;
    }
};

//adapter interface which makes legacy compatible with modern

class printerAdapter:public IPrinter{
private:
    oldPrinter *old;
public:
    printerAdapter(oldPrinter* old) : old(old) {}
    void print(string data) override{
        old->oldPrint(data);
    }
};

void clientCode(IPrinter* printer){
    printer->print("Printing Data");
}

int main(){
    oldPrinter old;
    printerAdapter printer(&old);

    clientCode(&printer);
}