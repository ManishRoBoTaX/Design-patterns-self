#include<iostream>

using namespace std;

class Amplifier {
public:
    void on () {
        cout<<"Amplifier ON!!!\n";
    }
    void setVolume(int vol) {
        cout<<"Amplifier Volume "<<vol<<endl;
    }
    void off() {
        cout<<"Amplifier switching OFF!!!\n";
    }
};

class DVDPlayer {
public:
    void on() {
        cout<<"DVD Player ON!!!\n";
    }
    void PlayMovie(string movie){
        cout<<"Playing Movie : " <<movie<<endl;
    }
    void off(){
        cout<<"DVD Player switching OFF!!!\n";
    }
};

class Projector{
public:
    void on(){
        cout<<"Projector ON!!!\n";
    }
    void wideMode(){
        cout<<"Pjoector mode changed to Wide\n";
    }
    void off(){
        cout<<"Projector switching OFF!!!\n";
    }
};

class moviePlayer{
private:
    Amplifier *amp;
    DVDPlayer *dvd;
    Projector* proj;
public:
    moviePlayer(Amplifier* amp, DVDPlayer* dvd, Projector* proj) :
    amp(amp) , dvd(dvd) , proj(proj) {};
    void watchmovie(string movie){
        cout<<"Starting Movie Player\n";
        amp->on();
        dvd->on();
        proj->on();
        amp->setVolume(10);
        dvd->PlayMovie(movie);
        proj->wideMode();
    }
    void endMovie(){
        cout<<"Closing Movie Player\n";
        proj->off();
        dvd->off();
        amp->off();
        cout<<"ENDED!!!\n";
    }
};

int main() {
    Amplifier *amp = new Amplifier();
    DVDPlayer *dvd = new DVDPlayer();
    Projector *proj = new Projector();

    moviePlayer MoviePlayer(amp,dvd,proj);

    MoviePlayer.watchmovie("DEADPOOL");
    MoviePlayer.endMovie();
    delete amp, dvd, proj;
}