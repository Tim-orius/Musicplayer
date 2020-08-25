#include "title.h"

Title::Title(std::string title){
    this->file_name = title;

    int filter = 0;
    std::string space_filter = "";
    for(int i=0; i<title.length(); ++i){
        if(title.at(i) == '-' && space_filter == " " && filter == 0){
            filter = 1;
            space_filter = "";
            ++i;
        } else {
            if(filter == 1){
                this->song_title = this->song_title + title.at(i);
            } else {
                if(title.at(i) == ' '){
                    space_filter = space_filter + ' ';
                } else {
                    this->song_author = this->song_author + space_filter + title.at(i);
                }
            }
        }
    }
}
