#include<iostream>
#include<mutex>

using namespace std;

class singleton{
private:
    singleton(){
        cout<<"Instance created\n";
    };
public:
    static singleton* inst;
    static mutex mtx;
    static singleton* getInstance(){
        if (inst==nullptr){
            inst = new singleton();
        }
        return inst;
    }
        static singleton* getInstanceTS(){
        if (inst==nullptr){
            lock_guard<mutex> lock(mtx);
            if (inst==nullptr)
                inst = new singleton();
        }
        return inst;
    }
};

singleton *singleton::inst = nullptr;
mutex singleton::mtx; 

int main(){
    singleton *s1 = singleton::getInstance();
    singleton *s2 = singleton::getInstance();
    if (s1==s2)
        cout<<"Pass\n";
    else    
        cout<<"Failed\n";
    singleton *s3 = singleton::getInstance();
    singleton *s4 = singleton::getInstance();
    if (s3==s4)
        cout<<"Thread safe Pass\n";
    else    
        cout<<"Thread Safe Failed\n";
    delete s1, s2, s3, s4;
}