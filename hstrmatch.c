#include<stdio.h>
#include<stdlib.h>
#define MAX 128
int S[MAX], i, j, k;
void shiftTable(char p[]){
	int m=strlen(p);
	for(i=0; i<MAX; i++)
		S[i]=m;
	for(j=0; j<m-1; j++)
		S[p[j]]=m-1-j;
}
int horsepool(char p[], char t[]){
	int m=strlen(p);
	int n=strlen(t);
	i=m-1;
	while(i<n){
		int k=0;
		while((k<=m-1)&&(t[i-k]==p[m-1-k]))
			k=k+1;
		if(k==m)
			return i-m+1;
		else
			i=i+S[t[i]];
	}
	return -1;
}
void main(){
	char t[100], p[100];
	printf("Enter the test string.\n");
	gets(t);
	printf("Enter the pattern string.\n");
	gets(p);
	shiftTable(p);
	int pos=horsepool(p, t);
	if(pos>=0)
		printf("The pattern string is found from %d to %d in the test string.\n", pos+1, pos+1+strlen(p));
	else
		printf("The string is not found.\n");
}
