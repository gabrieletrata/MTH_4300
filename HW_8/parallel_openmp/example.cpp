// example.cpp
// compile with
// c++ -o ex example.cpp -std=c++11 -fopenmp
// execute with
// ./ex

// Problem: Given two sequences seq1 and seq2, create the sequence seq3 that
// satisfies:
// seq3[i] = seq1[i]^seq2[i]
// Calculations are to be performed modulo p.


#include<iostream>
#include<omp.h>
#include "timer4300.cpp"
typedef long int myint;

void funPowerS(myint* seq1, myint* seq2,
              myint* seq3, const myint &len,
              const myint &p){
  myint i,j;
  for(i=0;i<len;++i){
    seq3[i]=1;
    for(j=0;j<seq2[i];++j){
      seq3[i] *= seq1[i];
      seq3[i] = seq3[i]%p;
    }
  }
}

void funPowerP(myint* seq1, myint* seq2,
                myint* seq3, const myint &len,
                const myint &p){
    myint numberOfThreads;
    #pragma omp parallel
    {
      if(omp_get_thread_num()==0){
        numberOfThreads=omp_get_num_threads();
      }
    }
    #pragma omp parallel num_threads(numberOfThreads)
    {
      myint myId=omp_get_thread_num();
      myint counter=0;
      myint numberOfJobs= len/ numberOfThreads+1;
      myint i,j;
      for(counter=0;counter<numberOfJobs;++counter){
        i=counter * numberOfThreads + myId;
        if(i<len){
          //seq3[i]=seq1[i]^seq2[i]
          seq3[i]=1;
          for(j=0;j<seq2[i];++j){
            seq3[i] *= seq1[i];
            seq3[i] %= p;
          }
        }
      }
    }
    #pragma omp barrier

}



myint firstOMPExample(){

  myint numberOfThreads;

  #pragma omp parallel
  {
    numberOfThreads=omp_get_num_threads();
  }

  #pragma omp parallel num_threads(numberOfThreads)
  {
    myint myNumber;
    myNumber=omp_get_thread_num();
    std::cout<<"I am No. "<<myNumber<<std::endl;
  }
  return numberOfThreads;
}

int main(){

  myint *s1, *s2,*s3;
  myint n,p;
  std::cout<<"What are n and p? ";
  std::cin>>n>>p;
  std::cout<<"Enter first 5 terms (10 numbers in total). I'll take ";
  std::cout<<"care for the rest. "<<std::endl;
  s1=new myint[n]; s2=new myint[n];
  s3=new myint[n];
  myint i;
  Timer4300 tm;
  for( i=0;i<5;++i){
    std::cin>>s1[i]>>s2[i];
  }
  i=5;
  //3 3 2 5 7 2 4 4 6 3

  while(i<n){
    s1[i]=s1[i-5];
    s2[i]=s2[i-5];
    ++i;
  }
  std::cout<<"Calling the non-parallel function"<<std::endl;
  tm.start();
  funPowerS(s1,s2,s3,n,p);
  tm.end();
  std::cout<<"Function finished in "<<tm.getTime()<<" miliseconds."<<std::endl;
  for(i=0;i<10;++i){
    std::cout<<s3[i]<<" ";
  }
  std::cout<<std::endl;

  std::cout<<"Calling the parallel function"<<std::endl;
  tm.start();
  funPowerP(s1,s2,s3,n,p);
  tm.end();
  std::cout<<"Parallel function finished in "<<tm.getTime()<<" miliseconds."<<std::endl;
  for(i=0;i<10;++i){
    std::cout<<s3[i]<<" ";
  }
  std::cout<<std::endl;


  delete[] s1; delete[] s2; delete[] s3;
  return 0;
}
