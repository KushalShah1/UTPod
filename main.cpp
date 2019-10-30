#include <iostream>
#include "Song.h"
#include "UTPod.h"

int main1() {
    Song arr[20];
    arr[0]= Song("Africa", "Toto",31);
    arr[1]= Song("Africa", "Shakira",24);
    arr[2]= Song("Africa", "Shakira",24);
    arr[3]= Song("Old Town Road", "Billy",2);
    arr[4]= Song("Breathin", "Ariana Grande",800);
    arr[5]= Song("Circus", "Britney",234);
    arr[6]= Song("Thriller", "MJ",22);
    arr[7]= Song("Purple Rain", "Prince",11);

    UtPod music= UtPod();
    for(int i=0;i<8;i++){
        int temp= music.addSong(arr[i]);
        cout <<temp<<endl;
        cout<<music.getRemainingMemory()<<endl;
    }
    music.showSongList();
    cout<<"sort"<<endl;
    music.sortSongList();
    music.showSongList();
    cout<<"suffle"<<endl;
    music.shuffle();
    music.showSongList();
    cout<<"Remove toto"<<endl;
    music.removeSong(Song("Africa","Toto",31));
    music.showSongList();
    cout<<"clear"<<endl;
    music.clearMemory();
    cout<<"hi"<<endl;
    music.showSongList();
    return 0;
}