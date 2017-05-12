#include "cstring"
#include "iomanip"
#include "Account.h"
using namespace std;
namespace sict{
  Account::Account(){
    _name[0] = 0;
    _balance = 0;
  }
  Account::Account(double balance){
    _name[0] = 0;
    _balance = balance;
  }

  Account::Account(const char name[], double balance){
    strncpy(_name, name, 40);
    _name[40] = 0;
    _balance = balance;
  }
  Account& Account::operator=(const Account& C){// :operator=
 if (this != &C){
 _balance = C._balance;
 }
 return *this;
  }
  Account::~Account(){
  }
  double Account::balance()const{
 return _balance;
  }
  Account Account::operator+(const Account& C)const{// operator+
 Account sum(_balance + C._balance);
 return sum;
  }
  double& operator+=(double& value, const Account& C){// operator+=
 value += C._balance;
 return value;
  }
  Account& Account::operator+=(const Account& C){
 _balance = C._balance;
 return *this;
  }
  ostream& operator<<(ostream& os, const Account C){// operator<<
 C.display();
 return os;
  }
  void Account::display()const{
    cout << _name << ": $" << setprecision(2) << fixed << _balance;
  }

}