#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__
#include <iostream>

namespace sict{
  class Account{
    char _name[41];
    double _balance;
  public:
    Account();
    Account(const char name[], double balance = 0.0);
    Account(double balance);
~Account();
Account& operator=(const Account& C);
Account operator+(const Account& C)const;
Account& operator+=(const Account& C);
friend double& operator+=(double& value, const Account& C);
void display()const;
double balance()const;
  };
  double& operator+=(double& value, const Account& C);
  std::ostream& operator<<(std::ostream& os, const Account C);
};

#endif