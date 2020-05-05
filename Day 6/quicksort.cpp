#include<iostream>
using namespace std;

void swap(int* a, int* b){
	int t = *a;
	*a = *b;
	*b = t;
}

int Partition(int *Arr, int start, int end){
	int pivot = Arr[end];
	int partitionIndex = start;
	for (int i=start; i<end; i++){
		if (Arr[i]<=pivot){
			swap(Arr[i], Arr[partitionIndex]);
			partitionIndex++;
		}
	}
	swap(Arr[partitionIndex], Arr[end]);
	return partitionIndex;
}

void QuickSort(int *Arr, int start, int end){
	if (start < end){
		int partitionIndex = Partition(Arr, start, end);
		QuickSort(Arr, start, partitionIndex-1);
		QuickSort(Arr, partitionIndex+1, end);
	}
}

int main(){
	
	int Arr[] = {9, 8, 7, 6,5 ,4 ,3, 2, 1};
	for (int i=0; i<=8; i++) cout<<Arr[i]<<" ";
	cout<<"\n";
	
	QuickSort(Arr, 0, 8);
	
	for (int i=0; i<=8; i++) cout<<Arr[i]<<" ";
	
	return 0;
}
