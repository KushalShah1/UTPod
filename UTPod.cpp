//
// Created by kusha on 10/23/2019.
//

#include "UTPod.h"
#include <iostream>
#include <ctime>

UtPod::UtPod() {
    memSize=MAX_MEMORY;
    songs=nullptr;
    srand(time(0));
}

UtPod::UtPod(int size) {
    if(size>MAX_MEMORY ||size<=0){
        memSize=MAX_MEMORY;
    } else
        memSize=size;
}

int UtPod::addSong(Song const &s) {
    if(getRemainingMemory()>=s.getSize()){
        SongNode *temp;
        temp = new SongNode;
        temp->s=s;
        temp->next=songs;
        songs=temp;
        return SUCCESS;
    }
    else
        return NO_MEMORY;
}
int UtPod::removeSong(Song const &s) {
    SongNode* temp=songs;
    SongNode* previousNode=songs;
    while(temp!=NULL){
        if(temp->s==s){
            cout<<temp->s.getArtist()<<endl;
            previousNode->next=temp->next;
            delete(temp);
            return SUCCESS;
        }
        previousNode=temp;
        temp=temp->next;
    }
    return NO_MEMORY;
}

void UtPod::showSongList() {
    SongNode* temp=songs;
    while(temp!=NULL){
        cout<<temp->s.getTitle()<<", "<<temp->s.getArtist()<<", "<<temp->s.getSize()<<endl;
        temp=temp->next;
    }
}
void UtPod::clearMemory() {
    SongNode* temp=songs;
    SongNode *nextNode=NULL;
    if(temp!=NULL) {
        nextNode = temp->next;
    }

    while(nextNode!=nullptr){
        delete(temp);
        temp=nextNode;
        nextNode=nextNode->next;
    }
    songs=NULL;
}
UtPod::~UtPod() {
    this->clearMemory();
}
int UtPod::getRemainingMemory() {
    int totalMem=0;
    for (SongNode* p= songs; p != NULL; p=p->next){
        totalMem+=p->s.getSize();
    }
    return memSize-totalMem;
}

void UtPod::shuffle(){
//count number of songs by traversing linked list (write a separate function that can be used for get remaining)
    SongNode* tempHead = songs;
    int songCount = 0;
    while(tempHead != NULL){
        //cout << tempHead->s << "\n";
        tempHead = tempHead->next;
        songCount++;
    }
//cout << songCount<<endl;
//idea is to have the rng get 2 nums b/w 1 and the num of songs
    for(int i = 0; i<(2*songCount);i++){
        int randNum1 = (rand()%songCount);
        int randNum2 = (rand()%songCount);
        SongNode* ptr1 = songs;
        SongNode* ptr2 = songs;
        while(randNum1>0){
            ptr1 = ptr1->next;
            randNum1--;
        }
        while(randNum2>0){
            ptr2 = ptr2->next;
            randNum2--;
        }
        ptr1->s.swap(ptr2->s);
    }
//add these nums to the head of the file to get to two diff songs
//swap the songs
//repeat 2x the num of songs

}

void UtPod::sortSongList() {
//idea is to have nested loops
//first song is smallest by default, traverse linked list to check if song x > s1 and swap if not
//once this is true, song 2 is smallest and repeat till the second last song

    SongNode* i = songs;
    while(i!=NULL){
        SongNode* j = i;
        SongNode* minimum= i;
        while(j!=NULL){
            if (minimum->s>j->s){
                minimum=j;
            }
            j=j->next;
        }
        i->s.swap(minimum->s);
        i=i->next;
    }
}




