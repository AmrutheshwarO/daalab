#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main(){
	int a[1000000], n, i, j, temp, r;
	clock_t start, end;
	double tt;
	printf("Enter the number of elements.\n");
	scanf("%d", &n);
	for(i=0; i<n;  i++){
		r=rand();
		a[i]=r;
	}
	start=clock();
	for(i=0; i<n; i++)
		for(j=i+1; j<n; j++)
			if(a[j]>a[i]){
				temp=a[j];
				a[j]=a[i];
				a[i]=temp;
			}
	end=clock();
	tt=(double)(end-start)/CLOCKS_PER_SEC;
	printf("Time taken= %lf\n", tt);
}
