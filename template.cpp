#include<iostream>
using namespace std;
//template interface
class game {
public:
    void play() {
        startGame();
        playTurn();
        endGame();
    }

    virtual void startGame() {
        cout<<"STARTING GAME!!!\n";
    }
    virtual void playTurn() = 0;
    virtual void endGame() {
        cout<<"ENDING GAME!!!\n";
    }
    virtual ~game() = default;
};
//concrete template
class chess : public game {
public:
    void startGame() override {
        cout<<"STARTING GAME CHESS!!!\n";
    }
    void playTurn() override {
        cout<<"PLAY YOUR TURN \n";
    }

    void endGame() override {
        cout<<"EXITING CHESS GAME!!!\n";
    }
};

class minesweeper : public game {
public:
    void startGame() override {
        cout<<"STARTING GAME MINESWEEPER!!!\n";
    }
    void playTurn() override {
        cout<<"PLAY YOUR TURN \n";
    }

    void endGame() override {
        cout<<"EXITING MINESWEEPER GAME!!!\n";
    }
};

int main() {
    chess *c1 = new chess();
    minesweeper *m1 = new minesweeper();

    c1->play();
    m1->play();

    delete c1,m1;
}