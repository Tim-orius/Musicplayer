#ifndef PLAYER_H
#define PLAYER_H

#include <math.h>
#include <title.h>
#include <iostream>
#include <string>
#include <vector>
#include <dirent.h>
#include <cstdlib>
//#include <windows.h>

class Player{
private:
    std::string music_files;
    std::vector<std::string> filenames;

    int track_no;

    bool shuffle;
    bool repeat;

public:
    Player();
    Title **titles;
    int ammount;
    void set_music_files(const std::string& param_music_files);
    void play();
    void pause();
    void play_new();
    void close();
};

#endif // PLAYER_H
