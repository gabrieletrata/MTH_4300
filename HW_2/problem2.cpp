//****************************************
// problem2.cpp
// Determines a non-negative integer x for an equation of the form:
// (ax + b) % m = c, given m, a, b, and c.
//****************************************
// Name: Gabriel Etrata
// Class MTH 4300 Spring 2018
// Professor: Ivan Matic
// Homework_2
//****************************************
// @author Gabriel Etrata
// @version 1.0
// @since 2018-02-14

#include<iostream>

/**Initializes the program and prompts user input.
*/
int main(){
  int m, a, b, c, x;
  //Prompts user to input coefficients.
  std::cout << "Input m, a, b, c." << std::endl;
  std::cin >> m >> a >> b >> c;

  //Finds a solution for x that satisfies the equation in the range R_k = [0, m].
  for(int k = 0; k < m; k++){
    x = (m*k + c - b)/a;
    if((a * x + b) % m == c){
    std::cout << x << std::endl;
    } else if(x < 0){
        std::cout << "There is no such x." << std::endl;
      }
  }

  return 0;
}
