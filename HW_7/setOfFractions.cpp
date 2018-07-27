//****************************************
// setOfFractions.cpp
//****************************************
// Name: Gabriel Etrata
// Class MTH 4300 Spring 2018
// Professor: Ivan Matic
// Homework_7
//****************************************
// @author Gabriel Etrata
// @author Ivan Matic
// @version 1.0
// @since 2018-04-23
#include <iostream>
typedef long int myint;

//Fraction class
class Frac{
private:
  myint num;
  myint den;
public:
  Frac(const myint& =0, const myint& =1);
  Frac(const Frac&);
  void operator=(const Frac&);
  bool operator==(const Frac&);
  myint getNum() const;
  myint getDen() const;
  void setNum(const myint &);
  void setDen(const myint &);
  myint operator<(const Frac &) const;
  myint operator>(const Frac &) const;
};

//Default constructor
Frac::Frac(const myint& _num, const myint &_den){
  num = _num;
  den = _den;
  if(den == 0){num = 0;den = 1;}
  if(den<0){num *= -1;den *= -1;}
}

//Copy constructor
Frac::Frac(const Frac& _copyFrom){
  num = _copyFrom.getNum();
  den = _copyFrom.getDen();
}

//Getter method to return fraction's numerator
myint Frac::getNum() const{return num;}
//Getter method to return fraction's denominator
myint Frac::getDen() const{return den;}
//Setter method for return fraction's numerator
void Frac::setNum(const myint & _n){num = _n;}
//Setter method for return fraction's denominator
void Frac::setDen(const myint & _d){
  den = _d;
  if(den == 0){num = 0;den = 1;}
  if(den < 0){num *= -1; den *= -1;}
}

//Overloaded assignment operator (=) for Frac class
void Frac::operator=(const Frac & _copyFrom){
  den = _copyFrom.getDen();
  num = _copyFrom.getNum();
}

//Overloaded comparison operator (==) for Frac class
bool Frac::operator==(const Frac &i){
  return (den == i.getDen() && num == i.getNum());
}

//Overloaded less than operator (<) for Frac class
myint Frac::operator<(const Frac & _cW) const{
  if(num * _cW.getDen() < den * _cW.getNum()){
    return 1;
  }
    return 0;
}

//Overloaded greater than operator (>) for Frac class
myint Frac::operator>(const Frac &_cW) const{
  if(num * _cW.getDen() > den * _cW.getNum()){
    return 1;
  }
  return 0;
}

//TNode (Binary Tree Node) class
class TNode{
public:
  Frac value;
  TNode * lChild;
  TNode * rChild;
  TNode();
};

//Default constructor
TNode::TNode(){
  lChild = nullptr;
  rChild = nullptr;
}

//Inserts fraction into Tree
void insert(TNode*& root, const Frac& fr){
  if(root == nullptr){
    root = new TNode;
    root->value = fr;
  }
  else{
    if(fr < root->value){insert(root->lChild, fr);}
    if(fr > root->value){insert(root->rChild, fr);}
  }
}

void insert(TNode*& root, const int& b,const int&c=1){
  Frac fr(b,c);
  insert(root,fr);
}

//Deletes node from Tree
void deleteNode(TNode*& root){
  if(root != nullptr){
    if(root->lChild != nullptr){
      TNode *helper = root->lChild;
      if(helper->rChild != nullptr){
        TNode *h2 = helper->rChild;
        while(h2->rChild != nullptr){
          helper = helper->rChild;
          h2 = h2->rChild;
        }
        root->value = h2->value;
        if(h2->lChild == nullptr){
          delete h2;
          helper->rChild = nullptr;
        }
        else{
          deleteNode(h2);
        }
      }
      else{
        root->value = helper->value;
        if(helper->lChild == nullptr){
          delete helper;
          root->lChild = nullptr;
        }
        else{
          deleteNode(helper);
        }
      }
    }
    else{
      if(root->rChild != nullptr){
        TNode *helper = root->rChild;
        if(helper->lChild != nullptr){
          TNode *h2 = helper->lChild;
          while(h2->lChild != nullptr){
            helper = helper->lChild;
            h2 = h2->lChild;
          }
          root->value = h2->value;
          if(h2->rChild == nullptr){
            delete h2;
            helper->lChild = nullptr;
          }
          else{
            deleteNode(h2);
          }
        }
        else{
          root->value = helper->value;
          if(helper->rChild == nullptr){
            delete helper;
            root->rChild = nullptr;
          }
          else{
            deleteNode(helper);
          }
        }
      }
      else{
        delete root;
        root = nullptr;
      }
    }
  }
}

//SetOfFractions class
class SetOfFractions{
private:
  TNode* root;
public:
  SetOfFractions();
  SetOfFractions(const SetOfFractions & );
  SetOfFractions(SetOfFractions &&);
  void operator=(const SetOfFractions &);
  void operator=(SetOfFractions &&);
  myint isElement(const Frac &) const;
  void insertInS(const Frac &);
  void printAllFractions() const;
  ~SetOfFractions();
};

//Default constructor
SetOfFractions::SetOfFractions(){
  root = nullptr;
}

//Copy constructor
SetOfFractions::SetOfFractions(const SetOfFractions & copyFrom){
  TNode* tempRoot = root;
  tempRoot = copyFrom.root;
}

//Copy assignment operator
void SetOfFractions::operator=(const SetOfFractions & copySet){
  if(root != nullptr){
    delete[] root;
  }
  root = copySet.root;
}

//Move constructor
SetOfFractions::SetOfFractions(SetOfFractions && moveFrom){
  root = moveFrom.root;
}

//Move assignment operator
void SetOfFractions::operator=(SetOfFractions && moveFrom){
  root = moveFrom.root;
}

//Checks if el is an element of the set
myint SetOfFractions::isElement(const Frac & el) const{
  TNode* temp = root;
     while (temp != nullptr) {
       if (temp->value == el) {
         std::cout << "This fraction is already an element of the set!" << std::endl;
         return 1;
       }
       else {
        /*Checks if the element is greater than the root value and if so,
          the element is placed into the right child of the root,
          the element is placed into the left child of the root otherwise
        */
        if (el > temp->value) {
            temp = temp->rChild;
        }
        else {
            temp = temp->lChild;
        }
      }
    }
  return 0;
}

//Inserts a fracation (fr) in the set, if it is not in there already
void SetOfFractions::insertInS(const Frac & fr){
  if(isElement(fr) == 0){
    insert(root, fr);
  }
}

//Prints all fractions of the set
void SetOfFractions::printAllFractions() const{
  //Checks if the set is empty
  if(root == nullptr){
  std::cout << "The set is empty!";
  }
  else{
  //Checks if the set contains element(s)
  if(root != nullptr){
      /*Temporary pointer for root, so the last element
        of the set is printed out
      */
      TNode* tempRoot = root;
      std::cout << (tempRoot->value).getNum();
      std::cout << "/";
      std::cout << (tempRoot->value).getDen();
      std::cout << " ";

      /*Checks if the left child of the root contains elements and if so,
        prints out its element(s)
      */
      if(tempRoot->lChild != nullptr){
      std::cout << (tempRoot->lChild->value).getNum();
      std::cout << "/";
      std::cout << (tempRoot->lChild->value).getDen();
      std::cout << " ";
      }

      /*Checks if the right child of the root contains elements and if so,
        prints out its element(s)
      */
      if(tempRoot->rChild != nullptr){
      std::cout << (tempRoot->rChild->value).getNum();
      std::cout << "/";
      std::cout << (tempRoot->rChild->value).getDen();
      std::cout << " ";
     }
    }
  }
}

//Destructor
SetOfFractions::~SetOfFractions(){
  if(root != nullptr){
    delete [] root;
  }
}

//Main function
//Prompts user input
int main(){
  myint a,b,c;
  Frac tempFr;
  SetOfFractions setF;
  a = 1;

  //Checks if user has decided to exit the program or not
  while(a!= 0){
    std::cout<<"Choose one of: 0 (exit), 1 (add), 2 (check for element), ";
    std::cout<<"or 3 (print all)"<<std::endl;
    std::cin>>a;
      //If user selects option to add fraction
      if(a == 1){
        std::cout<< "Insertion.";
        std::cout<< "What are the numerator and denominator?" << std::endl;
        std::cout << "Numerator: ";
        std::cin >> b;
        std::cout << "Denominator: ";
        std::cin >> c;
        tempFr.setNum(b);
        tempFr.setDen(c);
        setF.insertInS(tempFr);
      }
      //If user selects option to check for an element in the set
      if(a == 2){
        std::cout<<"Checking for element.";
        std::cout<< "What are the numerator and denominator?" << std::endl;
        std::cout << "Numerator: ";
        std::cin >> b;
        std::cout << "Denominator: ";
        std::cin >> c;
        tempFr.setNum(b);
        tempFr.setDen(c);
        std::cout << setF.isElement(tempFr) << std::endl;
      }
      //If user selects option to print all fractions of the set
      if(a == 3){
        std::cout<<"Printing all fractions."<<std::endl;
        setF.printAllFractions();
        std::cout<<std::endl;
      }
  }
  std::cout << "Exiting the program.";
  std::cout << std::endl;
  return 0;
}
