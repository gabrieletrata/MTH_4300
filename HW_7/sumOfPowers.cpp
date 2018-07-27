//****************************************
// sumOfPowers.cpp
// Program will compile, but runs into seg fault problem
//****************************************
// Name: Gabriel Etrata
// Class MTH 4300 Spring 2018
// Professor: Ivan Matic
// Homework_7
//****************************************
// @author Gabriel Etrata
// @author Ivan Matic
// @version 1.0
// @since 2018-04-25
#include <iostream>
#include <set>

std::set<int> setOfNums;

/**Computes an integer to the
  n-th power.
    @param base the base of the power
    @param n the degree of the power

    @return result the result of the
    base raised to the n-th power
*/
int power(int base, int n){
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
  int counter = 0;
  if(x == 0){
    setOfNums.insert(counter);
  }
  i++;
  //The difference between the sum and iterated value to the n-th power
  int diff = (x - power(i, n));

  //Initiates the recursion for the (i+1)-th step and returns the result.
  return sumOfPowers(diff, n, i + 1);
}

/**Counts the number of compositions that the
  sum can be written as.
  @param x the sum
  @param n the n-th power of distinct positive integers
*/
void numOfCompositions(int x, int n){
  int i = 0;
    sumOfPowers(x, n, i);
}

//Initializes the program and prompts user input
int main(){
  int n, a;
  std::cout << "Input n: ";
  std::cin >> n;
  std::cout <<"Input alpha: ";
  std::cin >> a;
  numOfCompositions(n, a);
  std::set<int>::iterator it = setOfNums.begin();
    std::cout<<*it<<std::endl;

  return 0;
}
