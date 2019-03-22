#include <iostream>
#include <cstring>
using namespace std;
/*Имате да изградите система за обработка на текущата информация в магазин за анаболни продукти.
  Имате клас Product, който съдържа:

    Име на продукта
    Срок на годност в дни
    Процент мазнини, ако няма мазнини, тогава 0%
    Дали е хранителна стока или не е
    Цена на продукта

    Реализирайте клас Store, който съдържа:

    Общ брой текущи продукти
    Продуктите в магазина
    текущ оборот на магазина

Освен това, напишете следните функции:

    Конструктори както и селектори и мутатори за съответните полета на двата класа

*/
bool compare (char*, char*);

class Product {
private:

  char* name;
  size_t expirationDays;
  short fatPercent;
  bool food;
  double price;

//friend class Store;
//==============================================================================

public:

  Product(const char* str){
    int i;
    for(i = 0;str[i] != 0;i++){
    }

    this->name = new char[i];
  }

//mutators
  // void set_name(){
  //   cin.getline(this->name, 100);cin.ignore();
  // }

  void set_expirationDays(size_t x){
    this->expirationDays = x;
  }

  void set_fatPercent(short x){
    this->fatPercent = x;
  }
  void set_food(bool x){
    this->food = x;
  }
  void set_price(double x){
    this->price = x;
  }

//accessors
  char* get_name(){
    char* name_cpy = new char [100];
    strcpy(name_cpy, this->name);
    return name_cpy;
  }

  size_t get_expirationDays(){
    return  this->expirationDays;
  }

  short get_fatPercent(){
    return this->fatPercent;
  }

  bool get_food(){
    return this->food;
  }

  double get_price(){
    return this->price;
  }

//==============================================================================
  void printStats(){
    for(int i = 0; name[i] != 0;i++){
      cout << this->name[i];
    }
    cout << endl << "Days until expiration: " << this -> expirationDays << endl;
    cout <<"Fat percentage: " << fatPercent <<endl;
    if(this->food){
      cout <<"This product is for consumption." << endl;
    } else {
      cout << "This product is not for consumption." << endl;
    }
    cout << "Price: " << this->price;

  }
  ~Product(){
    delete []name;
  }

};



class Store{
public:

  Store(size_t n = 100){
    this->products = new Product* [n];
    this->numbeOfProducts = n;

    //setting all pointers to NULL
    for(size_t i = 0;i < 0;i++){
      this->products[i] = NULL;
    }
  }

//==============================================================================

  Product** products;
  size_t numbeOfProducts;
  double currentProfit;

//==============================================================================

//Фукция за търсене на продукт по име
Product* search(char* searchWord){

  for(size_t i = 0; i < numbeOfProducts; i++){
    if(compare(this->products[i]->get_name(), searchWord)){
      return this->products[i];
    }
  }

  return NULL;
}

//Функция за търсене на продукт с най-малко мазнини
Product* leastFat(){
  Product* currentBest = NULL;
  short currentMin = 100;
  for(size_t i = 0;i < numbeOfProducts;i++){
    if(this->products[i]->get_fatPercent() < currentMin){
      currentMin = this->products[i]->get_fatPercent();
      currentBest = this->products[i];
    }
  }

  return currentBest;
}

// Функция за продажба на продукт
void sell(size_t productIndex){
  if(this->products[productIndex] == NULL){
    cout << "Product not found!";
    return;
  }

  for(size_t i = productIndex;i < numbeOfProducts-1;i++){
    this->products[i] = this->products[i+1];
  }

  delete this->products[numbeOfProducts];
}


// Функция за изчисляване на загубите от развалени стоки, като приемате,
// че стоки чиито срок на годност е под 6 дни е рисков и го броим.
double losses(){
  double currentLoss = 0;
  for(size_t i = 0;i < numbeOfProducts;i++){
    if(this->products[i]->get_expirationDays() < 6){
      currentLoss += this->products[i]->get_price();
    }
  }

  return currentLoss;
}

//==============================================================================

  ~Store(){
    for(size_t i = 0;i < numbeOfProducts;i++){
      delete[] this->products[i];
    }
    delete this->products;
  }
};




int main(){
  char name[10] = {"Creatine"};
  Product a1(name);

  a1.printStats();
  return 0;
}

bool compare (char* str1, char* str2){
  for(size_t i = 0; str1[i] != 0 && str2[i] != 0; i++){
    if((str1[i] != str2[i]) ||
      (str1[i+1] == 0 && str2[i+1] != 0) ||
      (str1[i+1] != 0 && str2[i+1] == 0))
      {
      return false;
    }
  }

  return true;
}
