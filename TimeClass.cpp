#include <iostream>
using namespace std;

template <typename T>
T abs(T x){
  if(x < 0){
    return -x;
  }
  return x;
}

class Time {

  public:
    //operators
    Time operator* (int x){
      Time newTime;
      newTime.hour = ((this->hour * x)%24 + (this->minutes * x)/60)%24;
      newTime.minutes = (this->minutes * x)%60;
      return newTime;
    }

    Time operator- (const Time &obj){
      Time newTime;
      newTime.hour = abs(this->hour - obj.hour) - (this->minutes < obj.minutes);
      newTime.minutes = (this->minutes - obj.minutes + 60)%60;
      return newTime;
    }

    Time operator+ (const Time &obj){
      Time newTime;
      newTime.hour = (this->hour + obj.hour + (this->minutes + obj.minutes)/60)%24;
      newTime.minutes = (this->minutes + obj.minutes)%60;
      return newTime;
    }

    bool operator< (const Time  &obj){
      bool res;
      if(this->hour < obj.hour){
        return true;
      }
      if(this->hour == obj.hour){
        if(this -> minutes < obj.minutes){
          return true;
        }
      }
      return false;
    }
    bool operator> (const Time  &obj){
      if(obj.hour < this->hour){
        return true;
      }
      if(obj.hour == this->hour){
        if(obj.minutes < this->minutes){
          return true;
        }
      }
      return false;
    }
    //=================================================================


    char timeOfDay[10];
    int hour;
    int minutes;

    //==========================<methods>===============================
    void setTime(unsigned int hour, unsigned int minutes){
      bool correct;
      do{
        correct = true;
        cout << "Hour: ";
        cin >> this->hour;
        cout << "Minutes: ";
        cin >> this->minutes;
        if(this->hour > 23 || this->minutes > 59){
          correct = false;
          cout << "Wrong format!" << endl;
        }
      } while(!correct);
    }

    void addMinutes(){
      unsigned int x;
      cout << "Enter amnount of minutes to add: ";
      cin >> x;
      this->hour += (this->minutes + x)/60;
      this->minutes = (this->minutes+x)%60;
      if(this->hour > 23){
        this->hour %= 24;
      }
    }

    void printTime(){

      if(this->hour < 10){

        if(this->minutes < 10){
          cout << "0" << this->hour << ":" << "0" << this->minutes << endl;
        } else {
          cout << "0" << this->hour << ":" << this->minutes << endl;
        }

      } else {

        if(this->minutes < 10){
          cout << this->hour << ":" << "0" << this->minutes << endl;
        } else {
          cout << this->hour << ":" << this->minutes << endl;
        }

      }
    }

    void minutesPast(){
      cout << "Minutes since the start of the day: "
           << (this->hour)*60 + this->minutes << "min." << endl;
    }
};

// template <typename T>
// bool ordered(T arr[], size_t length){
//   for(int i = 0;i < length-1;i++){
//     if(arr[i] >= arr[i+1]){
//       return false;
//     }
//   }
//   return true;
// }

// typedef double (*DoubleFunctionWithDoubleParameter)(double x);
//
// double f1 (double x){
//   return x*5;
// }
// double f2 (double x){
//   return x/5;
// }
// double f3 (double x){
//   return x+5;
// }
// double f4 (double x){
//   return x-5;
// }
// double f5 (double x){
//   return x*x;
// }



int main(){
  
  Time t, s, sum, diff;
  t.setTime(t.hour, t.minutes);
  t.printTime();
  s.setTime(s.hour, s.minutes);
  s.printTime();

  cout << "first time is later: " << (t > s) << endl;
  cout <<"first time is earlier: " << (t < s) << endl;

  sum = t + s;
  diff = t-s;

  //t+s is already a class
  cout << endl << "=====<sum>=====" << endl;
  (t+s).printTime();
  sum.printTime();
  cout << endl << "=====<difference>=====" << endl;
  (t-s).printTime();
  diff.printTime();
  cout << endl << "=====<multi>=====" << endl;
  (t*5).printTime();

  // t.addMinutes();
  // t.printTime();
  // t.minutesPast();
  // DoubleFunctionWithDoubleParameter functions[5] = {
  //   f1,
  //   f2,
  //   f3,
  //   f4,
  //   f5a
  // };

  return 0;
}
