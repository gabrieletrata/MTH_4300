// modSeq.cpp
// compile with
// c++ -o mS modSeq.cpp
// execute with
// ./mS

// Problem:
// Create the function fun2 whose
// input is a sequence of length n.
// The function should modify the sequence
// by replacing every term greater than 5
// with three terms equal to 5.

#include<iostream>
using namespace std;
void fun2(double** pSeq, int* aOL){
// Hunt for every seq
// and replace it by
// *pSeq
// just as we did with n -> *aOL

	// Step 1: Figure out newLen
	int newLen=*aOL;
	int i,j;
	for(i=0;i<*aOL;++i){
		if( (*pSeq)[i]>5.0){
			newLen +=2;
		}
	}
	// Step 2: Allocate the memory
	double* newSeq;
	newSeq=new double[newLen];
	// Step 3: Update the terms of seq
	j=0;
	for(i=0;i<*aOL;++i){
		if((*pSeq)[i]>5.0){
			for(int k=0;k<3;++k){
				newSeq[j]=5.0;++j;
			}
		}
		else{
			newSeq[j]=(*pSeq)[i];++j;
		}
	}
	//Step 4: Update the length
	*aOL=newLen;
	//Step 5: Free the memory of old
	delete[] (*pSeq);
	//Step 6: Re-wire the seq
	(*pSeq)=newSeq;
}
/**int main(){
	int n;
	double* seqA;
	cin>>n;
	seqA=new double[n];
	for(int i=0;i<n;++i){
		cin>>seqA[i];
	}

	fun2(&seqA, &n);

	cout<<"New length is "<<n<<endl;
	cout<<"Printing the result:";
	for(int i=0;i<n;++i){
		cout<<seqA[i]<<" ";
	}
	cout<<endl;
	delete[] seqA;
	return 0;
}**/
