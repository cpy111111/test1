#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1010

void solve(){
    int n;cin>>n;
    string s;cin>>s;
    map<int,int>mp;
    for(int i=0;i<n;i++){
    	int x = s[i]-'0';
    	mp[x]++;
	}
	if(mp.size()>1){
		int len=n-1;
		while(len--){
			cout<<"&";
		}
	}else{
		if(mp[1]!=0){
			cout<<"^";
			int len=n-2;
			while(len--){
				cout<<"&";
			}
		}else{
			int len=n-1;
			while(len--){
				cout<<"&";
			}
		}
	}
    
 }

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
   	
        solve();
    
    
    return 0;
}
