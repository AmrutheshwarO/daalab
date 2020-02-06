#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main(){
	int a[1000000], n, i, j, r, temp;
	clock_t start, end;
	double tt;
	printf("Enter the number of elements.\n");
	scanf("%d", &n);
	for(i=0; i<n; i++){
		r=rand();
		a[i]=r;
	}
	start=clock();
	for(i=0; i<n; i++)
		for(j=0; j<=n-i-1; j++)
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
	end=clock();
	tt=(double)(end-start)/CLOCKS_PER_SEC;
	printf("Time taken= %lf\n", tt);
}
