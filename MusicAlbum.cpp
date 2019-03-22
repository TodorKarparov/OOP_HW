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

/*
void addSong(Song song), която добавя song към масива от песни. Ако капацитетът е достигнат,
масивът с песни да се преоразмери подходящ нов размер, след което да се добави песента.

void removeSongAtIndex(std::size_t index) // it can be int, but you need to check input for negative number,
която премахва песен пo подаден индекс

double totalLength() const, която връща общата дължите на албума

size_t [или int] countOfSongsOfGenre(Genre genre) [първо го реализирайте с char *], която връща броя песни, които са от даден жан(Genre e дефиниран от нас изброим тип, съдържащ възможните жанрове).

size_t countOfSongsOfArtist(char* name) , която връща броя на песни от даден албум с конкретен изпълнител (ЗАБЕЛЕЖКА: сравняват низове, а не равенство между указателите им)

size_t indexOfShortestSong(), която връща индекса на най - малката продължителност на песен
*/
class Song {

private:
char *name;
size_t nameLength;
char *singer;
size_t singerLength;
char *genre;
size_t genreLength;

unsigned int songLength;

public:
  Song(){
    name = NULL;
    singer = NULL;
    genre = NULL;
    songLength = 0;
  }
  Song(unsigned int n){
    name = NULL;
    singer = NULL;
    genre = NULL;
    songLength = n;
  }
  Song(const char x[], unsigned int n = 0){

    this->name =  new char [strlen(x)];

    for(int i = 0;i < strlen(x);i++){
      name[i] = x[i];
    }
    name[strlen(x)] = 0;
    nameLength = strlen(name);
    singer = NULL;
    genre = NULL;
    songLength = n;

 }
  Song(const char x[], const char x2[], unsigned int n = 0){
    name =  new char [strlen(x)];
    strcpy(name, x);
    nameLength = strlen(name);
    singer = new char [strlen(x2)+1];
    strcpy(singer, x2);
    singerLength = strlen(singer);
    genre = NULL;
    songLength = n;
 }
 Song(const char x[], const char x2[], const char x3[], unsigned int n = 0){
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
//COPY CONSTRUCTOR
  Song(const Song &src){

    if(src.name != NULL){
      this->name =  new char [strlen(src.name)+1];
      strcpy(this->name, src.name);
    } else {
      this->name = NULL;
    }

    if(src.singer != NULL){
      this->singer = new char [strlen(src.name)+1];
      strcpy(this->singer, src.singer);
    } else {
      this->singer = NULL;
    }

    if(src.genre != NULL){
      this->genre = new char [strlen(src.genre) + 1];
      strcpy(this->genre, src.genre);
    } else {
      this->genre = NULL;
    }

    this->songLength = src.songLength;

  }

  ~Song(){
    if(name != NULL){
      delete []name;
    }
    if(singer != NULL){
      delete []singer;
    }
    if(genre != NULL){
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
  if(name != NULL){
    char* newName = new char [strlen(this->name)];
    return newName;
  }
  return NULL;
}

char* getSinger()const{
  if(singer != NULL){
    char* newSinger = new char [strlen(this->name)];
    return newSinger;
  }
  return NULL;
}

char* getGenre()const{
  if(genre != NULL){
    char* newGenre = new char [strlen(this->name)];
    return newGenre;
  }
  return NULL;
}
unsigned int getSongLength(){
  return this->songLength;
}
void print(){
  if(this->name == NULL && this->singer == NULL && this->genre == NULL){
    cout << "No information available!";
  }
  if(this->name != NULL){
    cout << "Name: ";
    for(int i = 0;name[i] != 0;i++){
      cout << this->name[i];
    }
  }
  if(this->singer != NULL){
    cout << endl;
    cout << "Singer: ";
    for(int i = 0;singer[i] != 0;i++){
      cout << this->singer[i];
    }

  }
  if(this->genre != NULL){
    cout << endl;
    cout << "Genre: ";
    for(int i = 0;genre[i] != 0;i++){
      cout << this->genre[i];
    }
  }

}
//=====================================================================================

};

class MusicAlbum {
private:
Song *album;
size_t currentSize;
size_t currentCapacity;
size_t buffer;

public:
  MusicAlbum(){
    album = NULL;
    currentSize = 0;
    currentCapacity = 0;
    buffer = 50;
  }

  MusicAlbum(Song x[], int length = -1){
    if(length < 0){
      album = NULL;
      cout << "Invalid length!";
      currentSize = 0;
      currentCapacity = 0;
      buffer = 50;

      return;
    }

    album = new Song [length];
    for(int i = 0;i < length;i++){
      album[i] = x[i];
    }
    currentSize = length;
    currentCapacity = length;
    buffer = 50;
  }

  ~MusicAlbum(){
    if(album != NULL){
      delete []album;
    }
  }
//==============================================================================

  void addSong(Song song){
    if(currentSize == currentCapacity){
      Song *newAlbum = new Song [currentCapacity + buffer];

      for(int i = 0;i < currentSize;i++){
        newAlbum[i] = album[i];
      }
      newAlbum[currentSize] = song;
      currentSize++;
      return;
    }

    album[currentSize] = song;
    currentSize++;
  }

  void removeSongAtIndex(size_t index){
    if(album == NULL){
      cout << "Album empty!";
      return;
    }
    if(index >= currentSize){
      cout << "Invalid index!";
    }

    for(int i = index;i < currentSize-1;i++){
      album[i] = album[i+1];
    }
    currentSize--;
  }

  unsigned int totalLength()const{
    unsigned int length = 0;
    for(int i = 0;i < currentSize;i++){
      length = length + this->album[i]->getSongLength;
    }
    return length;
  }

  size_t  countOfSongsOfGenre(char x[]){
    size_t songCount = 0;
    for(int i = 0;i < currentSize;i++){
      if(strcmp(this->album[i].genre, x));
    }


    return songCount;
  }


};






int main(){
  Song a(10), b(20), c("disturbed", "David Draiman", "Power Metal", 300);

  c.print();

  return 0;
}
