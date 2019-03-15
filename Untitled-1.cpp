#include <iostream>
#include <cstring>
using namespace std;

/*
Реализирайте клас Song, представляващ песен от даден албум. В този клас да се съдържа информация за:

    име
    изпълнител
    жанр
    продължителност

Внимание: изберете подходящи типове за отделните член-данни, като имате в предвид, че тези от тях които са символни низове трябва да имат произволна дължина
*/

class Song {

private:
char *name;
size_t nameLength;
char *singer;
size_t singerLength;
char *genre;
size_t genreLength;

unsigned short songLength;

public:
    Song(){
        name = nullptr;
        singer = nullptr;
        genre = nullptr;
        songLength = 0;
    }

    Song(const char x[], unsigned short n = 0){

        this->name =  new char [strlen(x)];

        for(int i = 0;i < strlen(x);i++){
            name[i] = x[i];
        }
        name[strlen(x)] = 0;
        nameLength = strlen(name);
        singer = nullptr;
        genre = nullptr;
        songLength = n;

 }
     Song(const char x[], const char x2[], unsigned short n = 0){
        name =  new char [strlen(x)];
        strcpy(name, x);
        nameLength = strlen(name);
        singer = new char [strlen(x2)+1];
        strcpy(singer, x2);
        singerLength = strlen(singer);
        genre = nullptr;
        songLength = n;
 }
    Song(const char x[], const char x2[], const char x3[], unsigned short n = 0){
        name =  new char [strlen(x)+1];
        strcpy(name, x);
        nameLength = strlen(name);
        singer = new char [strlen(x2)+1];
        strcpy(singer, x2);
        singerLength = strlen(singer);
        genre = new char [strlen(x3) + 1];
        strcpy(genre, x3);
        genreLength = strlen(genre);
        songLength = n;

 }

     ~Song(){
        if(name != nullptr){
            delete []name;
        }
        if(singer != nullptr){
            delete []singer;
        }
        if(genre != nullptr){
            delete []genre;
        }
    }
//====================================================================================

    operator< (const Song &other)const{
        return this->songLength < other.songLength;
    }

    operator> (const Song &other)const{
        return this->songLength > other.songLength;
    }

    operator<= (const Song &other)const{
        return !(this->songLength > other.songLength);
    }

    operator>= (const Song &other)const{
        return !(this->songLength < other.songLength);
    }

    operator== (const Song &other)const{
        return this->songLength == other.songLength;
    }

    operator!= (const Song &other)const{
        return this->songLength != other.songLength;
    }


//=====================================================================================

char* getName()const{
    if(name != nullptr){
        char* newName = new char [strlen(this->name)];
        return newName;
    }
    return nullptr;
}

char* getSinger()const{
    if(singer != nullptr){
        char* newSinger = new char [strlen(this->name)];
        return newSinger;
    }
    return nullptr;
}

char* getGenre()const{
    if(genre != nullptr){
        char* newGenre = new char [strlen(this->name)];
        return newGenre;
    }
    return nullptr;
}
//=====================================================================================

// void pushName(const char x[]){
//     char* newName = new char [strlen(x) + strlen(this->name)];
//     strcpy(newName, name);
//     strcat(newName, x);
//     delete []name;
//     name = newName;
// }

};

class MusicAlbum {
private:
Song *album;
size_t currentSize;
size_t currentCapacity;

public:
    MusicAlbum(){
        album = nullptr;
        currentSongNum = 0;
        currentCapacity = 0;
    }
    
    MusicAlbum(Song x[], int length = -1){
        if(length < 0){
            album = nullptr;
            cout << "Invalid length!";
            return;
        } 

        album = new Song [length];
        for(int i = 0;i < length;i++){
            album[i] = x[i];
        }

    }
    
};






int main(){



    return 0;
}
