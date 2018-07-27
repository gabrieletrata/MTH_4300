//****************************************
// problem1.cpp
// Computes the sum of number of divisors
// for a positive integer, n.
//****************************************
// Name: Gabriel Etrata
// Class MTH 4300 Spring 2018
// Professor: Ivan Matic
// Homework_3
//****************************************
// @author Gabriel Etrata
// @version 1.0
// @since 2018-02-21

#include <iostream>

/**Determines the number of divisors for n
    @param n the positive integer n

    @return num the number of divisors
*/
int numOfDivisors(int n){
  int num = 0;
  for(int i = 1; i <= n; i++){
    if(n % i == 0){
      num += 1;
    }
  }
  return num;
}

//Initializes the program and prompts user input.
int main(){
    //The positive integer n.
    int n;

    //Keeps track of which divisors to sum.
    int sumCounter = 0;
    std::cout << "Input n: ";
    std::cin >> n;
    for(int i = 0; i <= n; i++){
      sumCounter += numOfDivisors(i);
    }
    std::cout << "d(" << n << ") = " << sumCounter << std::endl;
  return 0;
}
