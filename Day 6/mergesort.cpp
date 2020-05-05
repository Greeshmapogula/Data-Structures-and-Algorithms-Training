#include<iostream>
using namespace std;

void merge(int *Arr, int start, int mid, int end){
	int temp[end-start+1];
	
	int i=start, j=mid+1, k=0;
	
	while(i<=mid && j<=end){
		
		if (Arr[i]<Arr[j]){
			temp[k] = Arr[i];
			i++;
			k++;
		}
		
		else{
			temp[k] = Arr[j];
			j++;
			k++;
		}
	}
	
	while(i<=mid){
		temp[k] = Arr[i];
		i++;
		k++;
	}
	
	while(j<=end){
		temp[k] = Arr[j];
		j++;
		k++;
	}
	
	for (i=start; i<=end; i++){
		Arr[i] = temp[i-start];
	}
}

void MergeSort(int *Arr, int start, int end){
	if (start < end){
		int mid = (start+end)/2;
		MergeSort(Arr, start, mid);
		MergeSort(Arr, mid+1, end);
		merge(Arr, start, mid, end);
	}
}

int main(){
	
	int Arr[] = {9, 8, 7, 6,5 ,4 ,3, 2, 1};
	for (int i=0; i<=8; i++) cout<<Arr[i]<<" ";
	cout<<"\n";
	
	MergeSort(Arr, 0, 8);
	
	for (int i=0; i<=8; i++) cout<<Arr[i]<<" ";
	
	return 0;
}
