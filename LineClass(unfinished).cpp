#include <iostream>
using namespace std;

template <typename T>
T abs(T x){
  if (x < 0){
    return -x;
  }
  return x;
}

struct Point{


  Point operator-(const Point &other){

    Point newPoint;
    newPoint.x = abs(this->x - other.x);
    newPoint.y = abs(this->y - other.y);

    return newPoint;
  }

  bool operator==(const Point &other){
    return (this->x == other.x) && (this->y == other.y);
  }

  int x;
  int y;
};

class Line{
public:
  Point X;
  Point Y;

  bool checkParallel(const Line &obj){
     return abs((this->X.y - this->Y.y)/(this->X.x - this->Y.x)) == abs((obj.X.y - obj.Y.y)/(obj.X.x - obj.Y.x));
  }

  bool pointInLine(Point A){
    abs((this->X.y - this->Y.y)/(this->X.x - this->Y.x)) == abs((obj.X.y - obj.Y.y)/(obj.X.x - obj.Y.x))
  }
};




int main(){
  Line t, s;
  t.X.x = 3;
  t.X.y = 2;
  t.Y.x = 10;
  t.Y.y = 23;
  s.X.x = 3;
  s.X.y = 4;
  s.Y.x = 12;
  s.Y.y = 25;

  cout << t.checkParallel(s);

  return 0;
}
