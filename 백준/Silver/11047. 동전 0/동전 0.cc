#include <iostream>
using namespace std;
int coin[10]{};
int main(){
	int n,k,a=0;cin>>n>>k;
	for(int i=0;i<n;++i){
		int t;cin>>t;
		coin[i]=t;}
	n--;
	while(k!=0){
		if(k>=coin[n]){
			k-=coin[n];
			a++;}
        else{
		    n--;}
	}
	cout << a;return 0;
}