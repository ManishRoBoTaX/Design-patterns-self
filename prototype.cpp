#include<iostream>

using namespace std;

//abstract class
class prototype {
public:
    virtual prototype* clone() = 0; //virtual prototype function
    virtual void display() = 0;
};

//concrete 1
class book : public prototype {
private:
    string name;
    double price;
public:
    book(string name, double price) : name(name) , price(price) {}

    prototype* clone() override{
        return new book(*this);
    }

    void display() override{
        cout<<"---------------\n";
        cout<<"Book Name : "<<name<<endl;
        cout<<"Book Price : "<<price<<endl;
        cout<<"----------------\n";
        cout<<endl;
    }
};

//concrete 2
class perfume : public prototype {
private:
    string name;
    double price;
    double quantity;
public:
    perfume(string name, double price, double quantity) : name(name) , price(price) , quantity(quantity) {}

    prototype* clone() override{
        return new perfume(*this);
    }

    void display() override{
        cout<<"---------------\n";
        cout<<"Perfume Name : "<<name<<endl;
        cout<<"Perfume Price : "<<price<<endl;
        cout<<"Perfume quantity : "<<quantity<<"ml"<<endl;
        cout<<"----------------\n";
        cout<<endl;
    }
};

int main() {
    book *b1 =  new book("Learning C", 110.99);
    perfume *p1 = new perfume("davidOff", 5999, 125.0);
    p1->display();
    b1->display();
    book *b2 = b1->clone();
    prototype *p2 = p1->clone();
    b2->display();
    p2->display();
    delete p1;
    delete p2;
    delete b1;
    delete b2;
}