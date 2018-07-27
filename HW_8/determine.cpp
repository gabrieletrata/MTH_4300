//****************************************
// determine.cpp
// Determines the winning candidate from file "hw6_input.txt"
//****************************************
// Name: Gabriel Etrata
// Class MTH 4300 Spring 2018
// Professor: Ivan Matic
// Homework_8
//****************************************
// @author Gabriel Etrata
// @author Ivan Matic
// @version 1.0
// @since 2018-05-03

#include <iostream>
#include <time.h>
#include <omp.h>
#include <map>
#include <string>
#include <fstream>

typedef long int myint;

//Politician class
class Politician{
private:
  myint voteCount = 0;
public:
  myint getNumOfVotes();
  void addVote();
};

myint Politician:: getNumOfVotes(){
  return voteCount;
}

void Politician::addVote(){
  voteCount+=1;
}

int getNextInteger(char * text, std::streampos size, std::streampos *pos){
  myint current = 0;
  myint mult = 1;
  while ((*pos < size) &&(text[*pos] != '-')&&(( text[*pos] < '0')||(text[*pos]>'9'))){
    *pos= (*pos)+((std::streampos)1);
  }
  if(text[*pos]=='-'){
    mult=-1;
    *pos= (*pos)+((std::streampos)1);
  }
  while ((*pos<size) &&(( text[*pos]>='0')&&(text[*pos]<='9'))){
    current = 10 * current;
    current += (int)(text[*pos]-'0');
    *pos=*pos+((std::streampos)1);
  }
  current *= mult;

  return current;
}

void readSequenceFromFile(std::string filename, myint** sequencePointer, myint *length){
  srand((unsigned)time(0));
  std::streampos size; std::streampos *position;
  position=new std::streampos;
  *position=0;
  char * memblock;
  std::ifstream ifile(filename,std::ios::in|std::ios:: binary|std::ios:: ate);
  if (ifile.is_open()){
    size = ifile.tellg();
    memblock = new char [size];
    ifile.seekg (0, std::ios:: beg);
    ifile.read (memblock, size);
    ifile.close();
    *length=getNextInteger(memblock,size,position);
    *sequencePointer = new myint[*length];
    myint i=0;myint cNum=0;
      while((i<*length)&&(cNum!=-9)){
        cNum=getNextInteger(memblock,size,position);
        if(cNum!=-9){
          (*sequencePointer)[i]=cNum;
          ++i;
        }
      }
      while(i<(*length)){
        (*sequencePointer)[i]=0;
        ++i;
      }
      delete[] memblock;
  }
  delete position;
}

//prints the results for politician_n
void printVoteCount(Politician p, int n){
  std::cout << "Candidate " << n << " has " << p.getNumOfVotes() <<  " votes." << std::endl;
}

void determineCandidateParallel(myint *x, myint n, myint *y){
  std::cout << "RUNNING PARALLEL PROGRAM" << std::endl;
  //start of determineCandidateParallel
  clock_t t;
  t = clock();
  Politician p0;
  Politician p1;
  Politician p2;
  Politician p3;
  Politician p4;
  Politician p5;
  Politician p6;
  Politician p7;
  Politician p8;
  Politician p9;

  myint numThreads;

  #pragma omp parallel
  //get number of threads (should be 4 on 2015 MBP with i5 Intel processor)
  {
      if(omp_get_thread_num() == 0){
        numThreads=omp_get_num_threads();
      }
  }

  #pragma omp parallel num_threads(numThreads)
    {
      myint myID = omp_get_thread_num();
      myint counter = 0;
      myint numJobs = n / numThreads+1;
      myint i,j;
      #pragma omp parallel for
      for(counter = 0; counter < numJobs; counter++){
        //ensures that only one thread at a time iterates through the sequence
        #pragma omp critical
        i = counter * numThreads + myID;
        if(i < n){
          y[i] = x[i];
            if(y[i] == 0){
              p0.addVote();
            }
            if(y[i] == 1){
              p1.addVote();
            }
            if(y[i] == 2){
              p2.addVote();
            }
            if(y[i] == 3){
              p3.addVote();
            }
            if(y[i] == 4){
              p4.addVote();
            }
            if(y[i] == 5){
              p5.addVote();
            }
            if(y[i] == 6){
              p6.addVote();
            }
            if(y[i] == 7){
              p7.addVote();
            }
            if(y[i] == 8){
              p8.addVote();
            }
            if(y[i] == 9){
              p9.addVote();
            }
          }
        }
    }
    #pragma omp barrier

  //Sorting the candidates from highest to lowest number of votes
  std::map<myint, std::string> poolOfCandidates;
  poolOfCandidates.insert(std::pair<myint, std::string>(p0.getNumOfVotes(), "Candidate 0"));
  poolOfCandidates.insert(std::pair<myint, std::string>(p1.getNumOfVotes(), "Candidate 1"));
  poolOfCandidates.insert(std::pair<myint, std::string>(p2.getNumOfVotes(), "Candidate 2"));
  poolOfCandidates.insert(std::pair<myint, std::string>(p3.getNumOfVotes(), "Candidate 3"));
  poolOfCandidates.insert(std::pair<myint, std::string>(p4.getNumOfVotes(), "Candidate 4"));
  poolOfCandidates.insert(std::pair<myint, std::string>(p5.getNumOfVotes(), "Candidate 5"));
  poolOfCandidates.insert(std::pair<myint, std::string>(p6.getNumOfVotes(), "Candidate 6"));
  poolOfCandidates.insert(std::pair<myint, std::string>(p7.getNumOfVotes(), "Candidate 7"));
  poolOfCandidates.insert(std::pair<myint, std::string>(p8.getNumOfVotes(), "Candidate 8"));
  poolOfCandidates.insert(std::pair<myint, std::string>(p9.getNumOfVotes(), "Candidate 9"));
  std::map<myint, std::string>::iterator itr;
  itr = poolOfCandidates.end();
  --itr;
  std::cout << "The winning candidate is " << itr->second << std::endl;

  //end of time for determineCandidateParallel
  t = clock() - t;

  std::cout << "Here are the results:" << std::endl;
  printVoteCount(p0, 0);
  printVoteCount(p1, 1);
  printVoteCount(p2, 2);
  printVoteCount(p3, 3);
  printVoteCount(p4, 4);
  printVoteCount(p5, 5);
  printVoteCount(p6, 6);
  printVoteCount(p7, 7);
  printVoteCount(p8, 8);
  printVoteCount(p9, 9);

  std::cout << "Time: " << t*1.0/CLOCKS_PER_SEC << " seconds" << std::endl;
  std::cout << "ENDING PARALLEL PROGRAM" << std::endl;
}

void determineCandidateRegular(myint *x, myint n, myint *y)
{
  std::cout << "RUNNING REGULAR PROGRAM" << std::endl;
  //start of determineCandidateRegular
  clock_t t;
  t = clock();
  Politician p_0;
  Politician p_1;
  Politician p_2;
  Politician p_3;
  Politician p_4;
  Politician p_5;
  Politician p_6;
  Politician p_7;
  Politician p_8;
  Politician p_9;


  //iterates through the sequence of votes
  for(myint i = 0; i < n; i++){
    y[i]=x[i];
    if(y[i] == 0){
      p_0.addVote();
    }
    if(y[i] == 1){
      p_1.addVote();
    }
    if(y[i] == 2){
      p_2.addVote();
    }
    if(y[i] == 3){
      p_3.addVote();
    }
    if(y[i] == 4){
      p_4.addVote();
    }
    if(y[i] == 5){
      p_5.addVote();
    }
    if(y[i] == 6){
      p_6.addVote();
    }
    if(y[i] == 7){
      p_7.addVote();
    }
    if(y[i] == 8){
      p_8.addVote();
    }
    if(y[i] == 9){
      p_9.addVote();
    }
  }

  //Sorting the candidates from highest to lowest number of votes
  std::map<myint, std::string> poolOfCandidates;
  poolOfCandidates.insert(std::pair<myint, std::string>(p_0.getNumOfVotes(), "Candidate 0"));
  poolOfCandidates.insert(std::pair<myint, std::string>(p_1.getNumOfVotes(), "Candidate 1"));
  poolOfCandidates.insert(std::pair<myint, std::string>(p_2.getNumOfVotes(), "Candidate 2"));
  poolOfCandidates.insert(std::pair<myint, std::string>(p_3.getNumOfVotes(), "Candidate 3"));
  poolOfCandidates.insert(std::pair<myint, std::string>(p_4.getNumOfVotes(), "Candidate 4"));
  poolOfCandidates.insert(std::pair<myint, std::string>(p_5.getNumOfVotes(), "Candidate 5"));
  poolOfCandidates.insert(std::pair<myint, std::string>(p_6.getNumOfVotes(), "Candidate 6"));
  poolOfCandidates.insert(std::pair<myint, std::string>(p_7.getNumOfVotes(), "Candidate 7"));
  poolOfCandidates.insert(std::pair<myint, std::string>(p_8.getNumOfVotes(), "Candidate 8"));
  poolOfCandidates.insert(std::pair<myint, std::string>(p_9.getNumOfVotes(), "Candidate 9"));

  std::map<myint, std::string>::iterator itr;
  itr = poolOfCandidates.end();
  --itr;
  std::cout << "The winning candidate is " << itr->second << std::endl;

  //end of determineCandidateRegular
  t = clock() - t;

  //print the results of the election
  std::cout << "Here are the results:" << std::endl;
  printVoteCount(p_0, 0);
  printVoteCount(p_1, 1);
  printVoteCount(p_2, 2);
  printVoteCount(p_3, 3);
  printVoteCount(p_4, 4);
  printVoteCount(p_5, 5);
  printVoteCount(p_6, 6);
  printVoteCount(p_7, 7);
  printVoteCount(p_8, 8);
  printVoteCount(p_9, 9);

  std::cout << "Time: " << t*1.0/CLOCKS_PER_SEC << " seconds" << std::endl;
  std::cout << "END OF REGULAR PROGRAM" << std::endl;
}

int main(){
  myint *x;
  myint n;
  readSequenceFromFile("hw6_input.txt", &x , &n);
  myint *y;
  y = new myint[n];

  determineCandidateRegular(x, n ,y);
  determineCandidateParallel(x, n, y);

    //free the memory
    delete[] x;
    delete[] y;
    return 0;
}
