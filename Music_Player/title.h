#ifndef TITLE_H
#define TITLE_H

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>

class Title{
private:

public:
    std::string song_title;
    std::string song_author;
    std::string file_name;
    Title(std::string title);
    int play();
};

#endif // TITLE_H
