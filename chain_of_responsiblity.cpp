#include<iostream>

using namespace std;

enum msg_level {
    INFO,
    DEBUG,
    ERROR
};

class Logger {
private:
    Logger* next;
public:
    Logger() : next(nullptr) {};
    void setNext(Logger* next){
        this->next=next;
    }
    void Log(msg_level level, string msg) {
        if (canHandle(level)){
            this->write(msg);
        } else if (next!=nullptr){
            next->Log(level,msg);
        }
    }
protected:
    virtual bool canHandle(msg_level level) = 0;
    virtual void write(string msg) = 0;
};

class infoLogger : public Logger {
protected:
    bool canHandle(msg_level level) override {
        if (level==INFO)
            return true;
        return false;
    }

    void write(string msg) override {
        cout<<"INFO : "<<msg<<endl;
    }
};

class debugLogger : public Logger {
protected:
    bool canHandle(msg_level level) override {
        if (level==DEBUG)
            return true;
        return false;
    }

    void write(string msg) override {
        cout<<"DEBUG : "<<msg<<endl;
    }
};

class errorLogger : public Logger {
protected:
    bool canHandle(msg_level level) override {
        if (level==ERROR)
            return true;
        return false;
    }

    void write(string msg) override {
        cout<<"ERROR : "<<msg<<endl;
    }
};

int main() {
    Logger *info = new infoLogger();
    Logger *debug = new debugLogger();
    Logger *error = new errorLogger();

    info->setNext(debug);
    debug->setNext(error);

    info->Log(INFO,"This is Info Logger");
    info->Log(DEBUG,"This is Debug Logger");
    info->Log(ERROR,"This is Error Logger");

    delete info, debug, error;
}