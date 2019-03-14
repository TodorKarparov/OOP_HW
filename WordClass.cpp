#include <iostream>
#include <cstring>
using namespace std;


class Word{
private:

  char word[20];

public:
  //default
  Word(){
    for(int i = 0;i <= 20;i++){
      this -> word[i] = 0;
    }
  }

//init
  Word(const char x[]){
    int length = strlen(x);
    for(int i = 0;i < length;i++){
      this-> word[i] = x[i];
    }
    this->word[length] = 0;
  }
  char operator[] (int i){
    return this->word[i];
  }

//==============================================================================

  Word operator+ (const char x[]){
    int length;
    for(length = 0;this->word[length] != 0;length++){}

    if(length < 20){
      Word newWord;
      for(int i = 0;i < length;i++){
        newWord.word[i] = this->word[i];
      }
      newWord.word[length] = x[0];
      newWord.word[length+1] = 0;
      return newWord;

    } else {

      return *this;

    }
  }

  void operator+= (const char x[]){
    int length;
    for(length = 0;this->word[length] != 0;length++){}

    if(length < 20){
      this->word[length] = x[0];
      this->word[length+1] = 0;
    } else {

      return;

    }
  }

  bool operator< (const Word &obj){
    if(strlen(this->word) > strlen(obj.word)){
      return false;
    }

    for(int i = 0;this->word[i] != 0 && obj.word[i] != 0;i++){
      if(this->word[i] < obj.word[i]){
        return true;
      }
    }
    if(strlen(this->word) < strlen(obj.word)){
      return true;
    }

    return false;
  }

  bool operator== (const Word &obj){
    if(strlen(this->word) != strlen(obj.word)){
      return false;
    }
    for(int i = 0;this->word[i] != 0 && obj.word[i] != 0;i++){
      if(this->word[i] != obj.word[i]){
        return false;
      }
    }

    return true;
  }

  void print(){
    for(int i = 0;this->word[i] != 0;i++){
      cout << this->word[i];
    }
  }

  int length(){
    return strlen(this->word);
  }
};
