#ifndef PLAYER_H
#define PLAYER_H

#include <math.h>
#include <title.h>
#include <iostream>
#include <string>

class Player{
private:
    Title* titles;
    std::string music_files;
    bool schuffle;
    bool repeat;

public:
    Player();
    void directory();
    void play();
};

#endif // PLAYER_H
