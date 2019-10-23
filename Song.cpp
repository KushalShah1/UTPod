//
// Created by kusha on 10/23/2019.
//

#include "Song.h"


Song::Song(){
    size= 0;
}
Song::Song(string _title, string _artist, int _size) {
    title=_title;
    artist=_artist;
    size=_size;
}
string Song::getArtist() const {
    return artist;
}
string Song::getTitle() const {
    return title;
}
int Song::getSize() const {
    return size;
}

void Song::setTitle(string _title) {
    title=_title;
}
void Song::setArtist(string _artist) {
    artist=_artist;
}
void Song::setSize(int _size) {
    size=_size;
}
bool Song::operator<(Song const &song) {
    if(artist.compare(song.getArtist())<0){
        return true;
    }
    else if( artist==song.getArtist()){
        if(title.compare(song.getTitle())<0){
            return true;
        }
        else if (title==song.getTitle()) {
            return size < song.getSize();
        }
        else
            return false;
    }
    else
        return false;
}
bool Song::operator>(Song const &song) {
    if(artist.compare(song.getArtist())>0){
        return true;
    }
    else if( artist==getArtist()){
        if(title.compare(song.getTitle())>0){
            return true;
        }
        else if (title==song.getTitle()) {
            return size > song.getSize();
        }
        else
            return false;
    }
    else
        return false;
}
bool Song::operator==(Song const &song) {
    return (artist == song.getArtist()) && (title == song.getTitle()) && (size == song.getSize());
}
Song::~Song() = default;


