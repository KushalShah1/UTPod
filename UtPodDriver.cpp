//
/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
#include "Song.h"
#include "UTPod.h"

using namespace std;

int main(int argc, char *argv[]){

    string temp;
    UtPod music= UtPod(512);

    ofstream myfile;
    myfile.open(argv[1], std::ios_base::app);
    while(temp!="-1"){
        getline(cin,temp);
        if(myfile.is_open() && temp!="-1")
            myfile<<temp<<endl;
    }
    myfile.close();
    ifstream inputFile(argv[1]);

    if(inputFile.is_open()){
        Song song;
        while(inputFile>>temp){
            song.setTitle(temp);
            inputFile>>temp;
            song.setArtist(temp);
            inputFile>>temp;
            song.setSize(stoi(temp));

            cout<<song.getTitle()<<" Success- "<<music.addSong(song)<<endl;
            cout<<"Remaining Memory- "<<music.getRemainingMemory()<<endl;
        }
        cout<<"-----------------------"<<endl;
        music.showSongList();
        cout<<"-----------------------"<<endl;
        music.shuffle();
        music.showSongList();
        cout<<"-----------------------"<<endl;
        music.sortSongList();
        music.showSongList();
        cout<<"-----------------------"<<endl;
        music.sortSongList();
        music.showSongList();
        cout<<"-----------------------"<<endl;
        music.removeSong(Song("Song","artist",32));
        music.removeSong(Song("Song","artist",32));
        music.removeSong(Song("Song","Artist",89));
        music.removeSong(Song("Bsong","ist",90));
        music.showSongList();
        cout<<"-----------------------"<<endl;
        music.shuffle();
        music.showSongList();
        cout<<"-----------------------"<<endl;
        music.clearMemory();
        music.sortSongList();
        music.shuffle();
        music.removeSong(Song("Bsong","ist",90));
        music.showSongList();
        cout<<"-----------------------"<<endl;
    }




}