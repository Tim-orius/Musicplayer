#include "player.h"

Player::Player(){
    this->repeat = 0;
}

void Player::set_music_files(const std::string &param_music_files){
    std::cout << param_music_files << std::endl;

    this->music_files = param_music_files;

    DIR* dir;
    int i = 0;
    struct dirent *ent;
    if ((dir = opendir (this->music_files.c_str())) != NULL) {
        while ((ent = readdir (dir)) != NULL) {
            if (!(ent->d_name[0]=='.')){
                this->filenames.push_back(ent->d_name);
                ++i;
            }
        }
        closedir (dir);
    }

    this->ammount = i;
    this->titles = new Title*[this->ammount];
    for(int j=0; j<this->filenames.size(); ++j){
        this->titles[j] = new Title(this->filenames[j]);
    }
}

void Player::play_new(std::string play_title){
    if(play_title == "None"){
        if(this->shuffle){
            srand(time(0));
            this->track_no = rand()%this->ammount;
        } else {
            this->track_no = ++this->track_no;
        }
        //mciSendString("open \""+this->music_files+this->titles[this->track_no]+"\" type mpegvideo alias mp3", NULL, 0, NULL);
    } else {
        //mciSendString("open \""+this->music_files+play_title+"\" type mpegvideo alias mp3", NULL, 0, NULL);
        std::cout << play_title << std::endl;
    }
    std::cout << "Open file" << std::endl;
    this->play();
}

void Player::play(){
    //mciSendString("play mp3", NULL, 0, NULL);
    std::cout << "Play" << std::endl;
}

void Player::pause(){
    //mciSendString("pause mp3", NULL, 0, NULL);
    std::cout << "Pause" << std::endl;
}

void Player::close(){
    //mciSendString("close mp3", NULL, 0, NULL);
    std::cout << "Close" << std::endl;
}
