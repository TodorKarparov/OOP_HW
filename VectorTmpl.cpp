#include <iostream>

using namespace std;

template<typename T>
class Vector{
private:
  T *arr;
  size_t size;
  size_t capacity;
  size_t buffer;


  void resize(){
    T *newArr = new T [capacity + buffer];
    capacity += buffer;
    for(size_t i = 0;i < size;i++){
      newArr[i] = arr[i];
    }
    if(arr != NULL){
      delete []arr;
    }
    arr = newArr;
  }

public:

//=====================================<C/D>====================================
  Vector(){
    arr = NULL;
    size = 0;
    capacity = 0;
    buffer = 50;
  }
  Vector(T *initArr, size_t newSize = 0){
    if(newSize == 0){
      return;
    }
    buffer = 50;
    capacity = newSize + buffer;
    arr = new T [newSize];
    for(size_t i = 0;i < newSize;i++){
      arr[i] = initArr[i];
    }

  }
  Vector(const Vector<T> &obj){
    if(obj.arr != NULL){
      arr = new T [obj.capacity];
      capacity = obj.capacity;
      size = obj.size;
      buffer = obj.buffer;
    } else {
      arr = NULL;
      capacity = obj.capacity;
      size = obj.size;
      buffer = obj.buffer;
    }
  }

  ~Vector(){
    if(arr != NULL){
      delete []arr;
    }
  }
//==============================================================================
size_t length()const{
  return this->size;
}

void push(T element){
  if(size == capacity){
    resize();
    arr[size] = element;
    size++;
  } else {
    arr[size] = element;
    size++;
  }
}

T pop(long long index){
  if(index < 0){
    return pop(0);
  }
  if(index ==  (size - 1)){
    T popped = arr[size - 1];
    size--;
    return popped;
  } else if (index >= size){
    cout << "Index out of bounds! Popped last." << endl;
    T popped = arr[size - 1];
    size--;
    return popped;
  } else {
    T popped = arr[index];
    for(size_t i = index;i < size-1;i++){
      arr[i] = arr[i+1];
    }
    size--;

    return popped;
  }
}

void operator= (const Vector<T> &obj){
  if(this == &obj){
    return;
  }

  while(capacity < obj.size){
    resize();
    capacity += buffer;
  }

  for(size_t i = 0;i < obj.size;i++){
    arr[i] = obj.arr[i];
  }
  size = obj.size;

}

T& operator[](size_t index)const{
  if(index >= size){
    cout << "Index out of bounds!"<< endl;
    return arr[0];
  }

  return arr[index];
}

Vector<T> operator+(const Vector<T> &obj){
  Vector newVector;
  newVector.size = obj.size + this-> size;
  newVector.capacity = obj.capacity + this -> capacity;
  newVector.buffer = this->buffer;
  newVector.arr = new T [newVector.capacity];

  for(size_t i = 0;i < this->size;i++){
    newVector.arr[i] = this->arr[i];
  }
  for(size_t i = 0;i < obj.size;i++){
    newVector.arr[this->size + i] = obj.arr[i];
  }
  return newVector;
}

void operator+=(const Vector<T> &obj){
  capacity += obj.capacity;
  T *newArr = new T [capacity];
  for(size_t i = 0;i < size;i++){
    newArr[i] = arr[i];
  }

  for(size_t i = 0;i < obj.size;i++){
    newArr[size + i] = obj.arr[i];
  }

  size += obj.size;
  delete []arr;
  arr = newArr;
}

void print()const{
  for(size_t i = 0;i < size;i++){
    cout << arr[i] << " ";
  }
}

};







int main(){
  // Vector<int> v;
  // int x;
  // v.push(20);
  // v.push(30);
  // v.push(40);
  // v.push(50);
  // v.push(60);
  // v.push(70);
  // Vector<int> v2;
  // v2 = v;
  // cout << "=======v2.pop(-1)=========" << endl;
  // cout << v2.pop(-1);
  // cout << endl;
  // cout << "=====v2.print()===========" << endl;
  // v2.print();
  // Vector<int> v3 = v + v2;
  // cout << "\n" << "================v3 = (v+v2).print()" << endl;
  // v3.print();
  // cout << "\n" << "==================v+=v2" << endl;
  // v += v2;
  // v.print();



  return 0;
}
