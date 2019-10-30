//
// Created by kusha on 10/23/2019.
//

#include "UTPod.h"
#include <iostream>
#include <ctime>
//Default constructor
//set the memory size to MAX_MEMORY
UtPod::UtPod() {
    memSize=MAX_MEMORY;
    songs=nullptr;
    srand(time(0));
}
//Constructor with size parameter
//The user of the class will pass in a size.
//If the size is greater than MAX_MEMORY or less than or equal to 0,
//set the size to MAX_MEMORY.
UtPod::UtPod(int size) {
    if(size>MAX_MEMORY ||size<=0){
        memSize=MAX_MEMORY;
    } else
        memSize=size;
}
/* FUNCTION - int addSong
       * attempts to add a new song to the UtPod
           o returns a 0 if successful
           o returns -1 if not enough memory to add the song

       precondition: s is a valid Song

       input parms -a song

       output parms - a success validation int
      */
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
/* FUNCTION - int removeSong
       * attempts to remove a song from the UtPod
       * removes the first instance of a song that is in the the UtPod multiple times
           o returns 0 if successful
           o returns -1 if nothing is removed


         input parms -Song

         output parms -success validation integer
      */

int UtPod::removeSong(Song const &s) {
    SongNode* temp=songs;
    SongNode* previousNode=songs;
    while(temp!=NULL){
        if(temp->s==s){
            if(temp==songs){
                songs=temp->next;
            }
            else
                previousNode->next=temp->next;
            delete(temp);
            return SUCCESS;
        }
        previousNode=temp;
        temp=temp->next;
    }
    return NO_MEMORY;
}
/* FUNCTION - void showSongList
       * prints the current list of songs in order from first to last to standard output
       * format - Title, Artist, size in MB (one song per line)

         input parms -none

         output parms -outputs to console all the songs
      */
void UtPod::showSongList() {
    SongNode* temp=songs;
    while(temp!=NULL) {
        cout << temp->s.getTitle() << ", " << temp->s.getArtist() << ", " << temp->s.getSize() << endl;
        temp = temp->next;
    }
}
/* FUNCTION - void clearMemory
   * clears all the songs from memory

     input parms -none

     output parms -none
  */
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
//Destructor clears the linked list
UtPod::~UtPod() {
    this->clearMemory();
}


/* FUNCTION - int getRemainingMemory
 *  returns the amount of memory available for adding new songs

   input parms -none

   output parms -returns amount of memory left
*/
int UtPod::getRemainingMemory() {
    int totalMem=0;
    for (SongNode* p= songs; p != NULL; p=p->next){
        totalMem+=p->s.getSize();
    }
    return memSize-totalMem;
}
/* FUNCTION - void shuffle
       *  shuffles the songs into random order
          o will do nothing if there are less than two songs in the current list

         input parms -none

         output parms -none
      */

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
        SongNode* minimun= i;
        while(j!=NULL){
            if (minimun->s<j->s){
                minimun=j;
            }
            j=j->next;
        }
        i->s.swap(minimun->s);
        i=i->next;
    }
}




