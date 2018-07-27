//****************************************
// recursiveFunction.cpp
// Input consists of integers n >= 0, p >= 2, and a > 0.
// Returns f(n) using a recursion for f(0) = a
// and f(n+1) = f((n)^2 + f(n) + 1) % p
//****************************************
// Name: Gabriel Etrata
// Class MTH 4300 Spring 2018
// Professor: Ivan Matic
// Homework_5
//****************************************
// @author Gabriel Etrata
// @version 1.0
// @since 2018-03-14
#include <iostream>

using namespace std;

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

/**Recursively computes the next term.
  @param a the zero-th term
  @param p p for the recursiveFunction
  @param n the input for f(n)
*/
int recursion(int a, int * p, int n){
  while(n != 0){
  int nextTerm = (pow(a, 2) + a + 1) % *p;
    return recursion(nextTerm, p, (n - 1));
  }
}

int main(){
  int n, p, a;
  cout << "Input p: ";
  cin >> p;
  cout << "Input a: ";
  cin >> a;

  cout << "Input n: ";
  cin >> n;

  int * pP;
  pP = &p;
  cout << "f(" << n << ") = " << recursion(a, pP, n) << endl;

  return 0;
}
