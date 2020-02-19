#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void quicksort(int A[10000000], int low, int high){
  	int i=low, j=high, pivot=low, temp;
	if(low<high){
		while(i<j){
			while(A[i]<=A[pivot]&&i<high)
				i++;
			while(A[j]>A[pivot])
				j--;
			if(i<j){
				temp=A[i];
				A[i]=A[j];
				A[j]=temp;
			}
		}
		temp=A[pivot];
		A[pivot]=A[j];
		A[j]=temp;
		quicksort(A,low,j-1);
		quicksort(A,j+1,high);
	}
}
void main(){
	int i, n;
	static int A[1000000];
	clock_t start, end;
	double tt;
	printf("Enter the number of elements:\t");
	scanf("%d", &n);
	//printf("Enter the elements.\n");
	for(i=0; i<n; i++)
		A[i]=rand();
	start=clock();
	quicksort(A, 0, n-1);
	end=clock();
	tt=(double)(end-start)/CLOCKS_PER_SEC;
	//printf("Order of Sorted elements: ");
	//for(i=0;i<n;i++)
	//	printf(" %d",A[i]);
	printf("Time taken=%lf\n", tt);
}
