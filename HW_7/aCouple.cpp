//****************************************
// aCouple.cpp
//****************************************
// Name: Gabriel Etrata
// Class MTH 4300 Spring 2018
// Professor: Ivan Matic
// Homework_7
//****************************************
// @author Gabriel Etrata
// @author Ivan Matic
// @version 1.0
// @since 2018-04-24
#include <iostream>

bool isPrime(int n){
  if(n < 2) {return false;}
   if(n == 2) {return true;}
   if(n % 2 == 0) {return false;}
   for(int i = 3; (i*i) <= n; i++){
       if(n % i == 0) {return false;}
   }
   return true;
}

int main(){
  int a, p, q;
  std::cout << "Input 0 for p, or q at any time to exit the program." << std::endl;
  do{std::cout <<"Input a: ";
  std::cin >> a;
  if(a < 0 || a == 0){
    std::cout <<"a must be a positive integer." << std::endl;
    std::cout <<"Input a: ";
    std::cin >> a;
  }
      std::cout <<"Input p: ";
      std::cin >> p;
        if(p < 0){
          std::cout <<"p must be a positive integer." << std::endl;
          std::cout <<"Input p: ";
          std::cin >> p;
        }
      std::cout <<"Input q: ";
      std::cin >> q;
        if(q < 0){
          std::cout <<"q must be a positive integer." << std::endl;
          std::cout <<"Input a: ";
          std::cin >> q;
        }
        int num = ((p*p) + (q*q) + a);
      if(isPrime(num)){
        std::cout << "(" << p << "," << q << "), with a = " << a << " is a-couple." <<std::endl;
      }
      if(!(isPrime(num))){
        std::cout << "(" << p << "," << q << "), with a = " << a << " is not a-couple." <<std::endl;
      }
  }while(p != 0 || q != 0);
  std::cout << "Exiting the program." << std::endl;
  return 0;
}
