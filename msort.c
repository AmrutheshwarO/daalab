#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void combine(int a[], int low, int mid, int high){
	static int b[1000000];
	int k=low, i=low, j=mid+1;
	while(i<=mid&&j<=high){
		if(a[i]<=a[j])
			b[k++]=a[i++];
		else
			b[k++]=a[j++];
	}
	while(i<=mid)
		b[k++]=a[i++];
	while(j<=high)
		b[k++]=a[j++];
	for(k=low; k<=high; k++)
		a[k]=b[k];
}
void mergesort(int a[], int l, int h){
	int m=(l+h)/2;
	static int b[1000000];
	if(l<h){
		mergesort(a, l, m);
		mergesort(a, m+1, h);
		combine(a, l, m, h);
	}
}
void main(){
	static int a[1000000];
	int n, i, l, h, r;
	clock_t start, end;
	double tt;
	printf("Enter the number of elements.\n");
	scanf("%d", &n);
	for(i=0; i<n; i++){
		r=rand();
		a[i]=r;
	}
	l=0;
	h=n-1;
	start=clock();
	mergesort(a, l, h);
	end=clock();
	tt=(double)(end-start)/CLOCKS_PER_SEC;
	printf("Time taken= %lf\n", tt);
}
