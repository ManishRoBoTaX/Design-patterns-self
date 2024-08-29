//Revise
#include<iostream>
#include<vector>

using namespace std;

class Order;

//observer interface
class Observer {
    public:
        virtual void update(Order* order) = 0;
};

//concrete observers
class Customer : public Observer {
private:
    string name;
public:
    Customer( string name) : name(name) {};
    void update(Order *order) ;
};

class Rider : public Observer {
private:
    string driver;
public:
    Rider( string driver) : driver(driver) {};
    void update(Order *order) ;
};


class Resturant : public Observer {
private:
    string rest_name;
public:
    Resturant( string rest_name) : rest_name(rest_name) {};
    void update(Order *order);
};

class CallCenter : public Observer {
private:
    string support;
public:
    CallCenter( string support) : support(support) {};
    void update(Order *order);
};

//subject

class Order {
private:
    int id;
    string status;
    vector<Observer*> observers;
public:
    Order(int id) : id(id), status("order Placed") {};
    int getId(){
        return id;
    }
    string getStatus(){
        return status;
    }
    void addObserver(Observer* observer){
        observers.push_back(observer);
    }
    void detachObserver(Observer* observer){
        for(auto it = observers.begin();it!=observers.end();it++)
            if (*it==observer){
                observers.erase(it);
                break;
            }
    }
    void notifyObservers(){
        for(auto it = observers.begin();it!=observers.end();it++)
            (*it)->update(this);
    }
    void setStatus(string newStatus){
        status = newStatus;
        notifyObservers();
    }
};
void Customer::update(Order *order) {
    cout<<"Hello "<<name<<"!, your order No. "<<order->getId()<<" is now "<<order->getStatus()<<endl;
}
void Rider::update(Order *order) {
    cout<<"Rider "<<driver<<", your order No. "<<order->getId()<<" is now "<<order->getStatus()<<endl;
}
void Resturant::update(Order *order) {
    cout<<"Resturant "<<rest_name<<", your order No. "<<order->getId()<<" is now "<<order->getStatus()<<endl;
}
void CallCenter::update(Order *order) {
    cout<<"Call Center "<<support<<", your order No. "<<order->getId()<<" is now "<<order->getStatus()<<endl;
}

int main(){
    Order order(143);

    Customer c1("Manish");
    Rider r1("Ankur");
    Resturant re1("Bhandara");
    CallCenter ca1("Jira");

    order.addObserver(&c1);
    order.addObserver(&r1);
    order.addObserver(&re1);
    order.addObserver(&ca1);
    order.notifyObservers();
    order.setStatus("Food is being Prepared!!");

    order.detachObserver(&ca1);

    order.setStatus("Food is Out for Delivery!!");
}
