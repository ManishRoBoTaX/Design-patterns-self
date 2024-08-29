#include<iostream>

using namespace std;

class pauseState;
class stopState;
class mediaPlayer;

class state {
public:
    virtual void play(mediaPlayer*) = 0;
    virtual void pause(mediaPlayer*) = 0;
    virtual void stop(mediaPlayer*) =0;
};

class mediaPlayer {
private:
    state *current;
public:
    mediaPlayer(state* current) : current(current) {}
    ~mediaPlayer() {
        delete current;
    }
    void setState(state* newstate){
        delete current;
        current = newstate;
    }

    void play(){
        current->play(this);
    }
    void pause() {
        current->pause(this);
    }
    void stop(){
        current->stop(this);
    }
};
class playState:public state {
public:
    void play(mediaPlayer* player) override{
        cout<<"Already Playing!!!\n";
    }
    void pause(mediaPlayer* player) override {
        cout<<"Music Paused!!!\n";
        player->setState((state*)(new pauseState()));
    }
    void stop(mediaPlayer* player) override{
        cout<<"Stopping Music!!!\n";
        player->setState((state*)(new stopState()));
    }
};


class pauseState:public state {
public:
    void play(mediaPlayer* player) override{
        cout<<"Playing Music!!!\n";
        player->setState(new playState());
    }
    void pause(mediaPlayer* player) override {
        cout<<"Already Paused!!!\n";
    }
    void stop(mediaPlayer* player) override{
        cout<<"Stopping Music!!!\n";
        player->setState((state*)(new stopState()));
    }
};

class stopState:public state {
public:
    void play(mediaPlayer* player) override{
        cout<<"Playing Musing!!!\n";
        player->setState(new playState());
    }
    void pause(mediaPlayer* player) override {
        cout<<"Music Stopped can't pause!!!\n";
    }
    void stop(mediaPlayer* player) override{
        cout<<"Already Stopped!!!\n";
    }
};

int main(){
    mediaPlayer *player = new mediaPlayer(new stopState());
    player->play();
    player->play();
    player->stop();
    player->pause();
    player->stop();
    player->play();

    delete player;
}