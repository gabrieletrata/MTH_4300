//****************************************
// problem2.cpp
// Given two positive integers x, n:
// determines the number of ways in which
// x can be written as the sum of perfect N-th
// powers of distinct positive integers.
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

/**Computes an integer to the
  n-th power.
    @param base the base of the power
    @param n the degree of the power

    @return result the result of the
    base raised to the n-th power
*/
int pow(int base, int n){
    int result = 1;

    if(base == 1){
      return 1;
    }
    if(base == 0){
      return 0;
    }

    for(int i = 0; i < n; i++){
      result *= base;
    }
    return result;
}

/**Computes the number of compositions in
  a recursive manner.
  @param x the sum, a positive integer x
  @param n the n-th power of disinct positive integers
  @param i the i-th iteration of the recursion
*/
int sumOfPowers(int x, int n, int i){
  //The difference between the sum and iterated value to the n-th power
  int diff = (x - pow(i, n));

  //If difference is equal to 0,
  //then increase the count by 1
  if(diff == 0){
    return 1;
  }
  //If difference is less than 0,
  //don't increase the count
  if(diff < 0){
    return 0;
  }

  //Initiates the recursion for the (i+1)-th step and returns the result.
  //Sums two cases:
  //First case considers the current iteration
  //Second case considers the previous iteration
  //Therefore their sum will be the total number of valid compositions
  return sumOfPowers(diff, n, i + 1) + sumOfPowers(x, n, i + 1);
}

/**Counts the number of compositions that the
  sum can be written as.
  @param x the sum
  @param n the n-th power of distinct positive integers
*/
int numOfCompositions(int x, int n){
  int i = 1;
    return sumOfPowers(x, n, i);
}

//Initializes the program and prompts user input
int main(){
  int x;
  int n;
  std::cout << "Input the sum and power: ";
  std::cin >> x >> n;
  std::cout << "Number of compositions: " << numOfCompositions(x, n) << std::endl;

  return 0;
}
