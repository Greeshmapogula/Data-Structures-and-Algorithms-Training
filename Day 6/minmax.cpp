#include<iostream>
using namespace std;

int DAC_Max(int *A, int index, int size){
	int max;
	if (index >= size-2){
		if (A[index] > A[index+1])
			return A[index];
		else
			return A[index+1];
	}
	
	max = DAC_Max(A, index+1, size);
	
	if (A[index]> max)
		return A[index];
	else
		return max;
}

int main(){
	
	int max, N;
	
	int A[] = { 70, 50, 80, 140, 12, 14, 250};
	
	max = DAC_Max(A, 0, 7);
	
	cout<<max<<"\n";
	
	return 0;
}
