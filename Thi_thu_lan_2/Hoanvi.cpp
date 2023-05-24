#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[15];

int giaithua(int a){
	int kq=1;
	for (int i=2; i<=a; i++){
		kq*=i;
	}
	return kq;
}

void printout(){
	for (int i=1; i<=n; i++){
		cout<<a[i]<<' ';
	}
	cout<<'\n';
}

void hoanvi(){
	int i=n-1;
	while (a[i]>a[i+1]){
		i--;
	}
	if (i>0){
		int j=n;
		while (a[j]<a[i]){
			j--;
		}
		
		swap(a[i], a[j]);
		int r=i+1, s=n;
		while (r<=s){
			swap(a[r], a[s]);
			r+=1;
			s-=1;
		}	
	}
}

void sinhfirst(){
	for (int i=0; i<=n; i++){
		a[i]=i;
	}
}

int main(){
	cin>>n>>m;
	sinhfirst();
	int nGT=giaithua(n);
	for (int i=1; i<=nGT; i++){
		if (i%m==0){
			printout();
		}
		hoanvi();
	}
}
