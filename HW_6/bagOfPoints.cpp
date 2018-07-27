//****************************************
// bagOfPoints.cpp
// Will run and compile with
// memory leak issues
//****************************************
// Name: Gabriel Etrata
// Class MTH 4300 Spring 2018
// Professor: Ivan Matic
// Homework_6
//****************************************
// @author Gabriel Etrata
// @version 1.0
// @since 2018-03-23

#include <iostream>

using namespace std;

class bagOfPoints{
private:
  int numPoints;
  double* seqX;
  double* seqY;

public:
  bagOfPoints(const int& = 0);
  bagOfPoints(const bagOfPoints &);
  bagOfPoints(bagOfPoints&&);
  void operator = (const bagOfPoints &);
  void operator = (bagOfPoints&&);
  ~bagOfPoints();
  double getX(const int &) const;
  double getY(const int &) const;
  int getLength() const ;
  void setTerm(const int &, const double &, const double &);
  void setLength(const int &);
  void reflectPoints(const bagOfPoints &) const ;
};

//Constructor for class bagOfPoints
bagOfPoints::bagOfPoints(const int& k){
  numPoints = k;
  seqX = new double [k];
  seqY = new double [k];
}

//Getter method for x-coordinate at k-th index
double bagOfPoints::getX(const int& k) const{
  return seqX[k];
}

//Getter method for y-coordinate at k-th index
double bagOfPoints::getY(const int& k) const{
  return seqY[k];
}

//Getter method for length of the sequence
int bagOfPoints::getLength() const{
  return numPoints;
}

//Setter method for assigning term to sequence
void bagOfPoints::setTerm(const int &i, const double &x, const double &y){
  seqX[i] = x;
  seqY[i] = y;
}

//Setter method for assigning length of sequence
void bagOfPoints::setLength(const int &n){
  double *new_seqX = new double [n];
  double *new_seqY = new double [n];
  for(int i = 0; i < numPoints; i++){
      new_seqX[i] = seqX[i];
      new_seqY[i] = seqY[i];
  }
  if(seqX != nullptr){
    delete[] seqX;
  }
  if(seqY != nullptr){
    delete[] seqY;
  }
  seqX = new_seqX;
  seqY = new_seqY;
  numPoints = n;
}

//Copy constructor
bagOfPoints::bagOfPoints(const bagOfPoints& copyFrom){
  numPoints = copyFrom.getLength();
  //intialize needed array
  seqX = new double[numPoints];
  seqY = new double[numPoints];

  for(int i = 0; i < numPoints; i++){
  seqX[i] = copyFrom.getX(i);
  seqY[i] = copyFrom.getY(i);
  }
}

//Copy assignment constructor
void bagOfPoints::operator = (const bagOfPoints& copyFrom){
  if(seqX != nullptr){
    delete [] seqX;
  }
  if(seqY != nullptr){
    delete [] seqY;
  }
  numPoints = copyFrom.getLength();
  seqX = new double[numPoints];
  seqY = new double[numPoints];
  for(int i = 0; i < numPoints; i++){
    seqX[i] = copyFrom.getX(i);
    seqY[i] = copyFrom.getY(i);
  }
}

//Move constructor
bagOfPoints::bagOfPoints(bagOfPoints&& moveFrom){
  numPoints = moveFrom.getLength();
  seqX = moveFrom.seqX;
  seqY = moveFrom.seqY;
  moveFrom.seqX = nullptr;
  moveFrom.seqY = nullptr;
  moveFrom.numPoints = 0;
}

//Move assignment operator
void bagOfPoints::operator = (bagOfPoints&& moveFrom){
  if(seqX != nullptr){
    delete[] seqX;
  }
  if(seqY != nullptr){
    delete[] seqY;
  }
  numPoints = moveFrom.getLength();
  seqX = moveFrom.seqX;
  seqY = moveFrom.seqY;
  moveFrom.seqX = nullptr;
  moveFrom.seqY = nullptr;
  moveFrom.numPoints = 0;
}

//Destructor
bagOfPoints::~bagOfPoints(){
  if(seqX != nullptr){
  delete[] seqX;
  }
  if(seqY != nullptr){
  delete[] seqY;
  }
}

//Reflects points by negating it ***causes memory leak
void bagOfPoints::reflectPoints(const bagOfPoints& bag) const{
  bagOfPoints regBag = bag;
  for(int t = 0; t < getLength(); t++){
    regBag.seqX[t] = regBag.seqX[t] * (-1.0);
    regBag.seqY[t] = regBag.seqY[t] * (-1.0);
    seqX[t] = regBag.seqX[t];
    seqY[t] = regBag.seqY[t];
    }
  }

int main(){
  double x, y;
  int num;
  double *xCoord;
  double *yCoord;
  cout << "Input the number of points: ";
  cin >> num;
  xCoord = new double [num];
  yCoord = new double [num];
  for(int i = 0; i < num; i++){
      cout <<"Enter x-coordinate of point " <<  i + 1 << ": ";
      cin >> x;
      xCoord[i] = x;
      cout <<"Enter y-coordinate of point " <<  i + 1 << ": ";
      cin >> y;
      yCoord[i] = y;
  }

  //Initialize two objects
  bagOfPoints bP;
  bagOfPoints bP_Reflect;
  bP.setLength(num);
  for(int i = 0; i < num; i++){
    bP.setTerm(i, xCoord[i], yCoord[i]);
  }

  //Tester code
  cout << "Original point(s): " << endl;
  for(int i = 0; i < num; i++){
  cout << "(" << bP.getX(i) << "," <<  bP.getY(i) << ")" << endl;
  }

  //Tester code for reflection
  bP_Reflect.setLength(num);
  bP_Reflect.reflectPoints(bP);
  cout << "Reflected point(s): " << endl;
  for(int i = 0; i < num; i++){
  cout << "(" << bP_Reflect.getX(i) << "," << bP_Reflect.getY(i) << ")" << endl;
  }

  return 0;
}
