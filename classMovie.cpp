#include <iostream>
#include <cstring>
using namespace std;

class Movie {
private:
  char *name;
  char *producer;
  size_t length;

public:
//====================================<C/D>=====================================
//defaultC
  Movie(){
    name = NULL;
    producer = NULL;
    length = 0;
  }

  //CC
  Movie(const Movie &obj){
    if(this == &obj){
      return;
    }
    if(obj.name != NULL){
      name = new char [strlen(obj.name)+1];
      strcpy(name, obj.name);
    } else {
      name = NULL;
    }

    if(obj.producer != NULL){
      producer = new char [strlen(obj.producer)+1];
      strcpy(producer, obj.producer);
    } else {
      producer = NULL;
    }
    length = obj.length;
  }

//init name,producer,length
  Movie(const char *x, const char *y, size_t n = 0){
    name = new char [strlen(x)+1];
    producer = new char [strlen(y)+1];
    strcpy(name,x);
    strcpy(producer,y);
    length = n;
  }
//
  Movie(const char *x, size_t n = 0){
    name = new char [strlen(x)];
    strcpy(name,x);
    length = n;
    producer = NULL;
  }

  Movie(size_t n = 0){
    length = n;
    name = NULL;
    producer = NULL;
  }

  ~Movie(){
    if(name != NULL){
      delete []name;
    }
    if(producer != NULL){
      delete []producer;
    }
  }
//==============================================================================
void operator=(const Movie &obj){
  if(this == &obj){
    return;
  }

  if(obj.name != NULL){
    name = new char [strlen(obj.name)+1];
    strcpy(name, obj.name);
  } else {
    name = NULL;
  }

  if(obj.producer != NULL){
    producer = new char [strlen(obj.producer)+1];
    strcpy(producer, obj.producer);
  } else {
    producer = NULL;
  }

  length = obj.length;

}



};




int main(){






  return 0;
}
