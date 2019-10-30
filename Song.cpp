//
// Created by kusha on 10/23/2019.
//

#include "Song.h"

//default constructor
Song::Song(){
    size= 0;
}
//intializes song with a title,artist, and size
Song::Song(string _title, string _artist, int _size) {
    title=_title;
    artist=_artist;
    size=_size;
}
//returns the artist
string Song::getArtist() const {
    return artist;
}
//returns the title
string Song::getTitle() const {
    return title;
}
//returns the size
int Song::getSize() const {
    return size;
}
//sets the title
void Song::setTitle(string _title) {
    title=_title;
}
//sets the artist
void Song::setArtist(string _artist) {
    artist=_artist;
}
//sets the size
void Song::setSize(int _size) {
    size=_size;
}
//compares 2 songs by artist then title, then size
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
//compares 2 songs by artist then title, then size
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
//compares 2 songs and checks if their are the same
bool Song::operator==(Song const &song) {
    return (artist == song.artist) && (title == song.title) && (size == song.size);
}
//Swaps the values of 2 songs
void Song::swap(Song &s2) {
    Song temp=s2;
    s2=*this;
    *this=temp;
}
Song::~Song() = default;


