#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1010

void solve(){
    string s,t;cin>>s>>t;
    int len = s.size();
    int len2 = t.size();
    set<pair<char,char>>a;a.clear();
    set<pair<char,char>>d;d.clear();
    vector<int>b(26,0);vector<int>c(26,0);
    
    
    for(int i=0;i<len-1;i++){
    	int idx=s[i]-'a';
    	if(b[idx]!=0){
    		continue;
		}else
		b[idx]++;
    	for(int j=i+1;j<len;j++){
    		a.insert({s[i],s[j]});
		}
	}
	for(int i=0;i<len2-1;i++){
		int idx=t[i]-'a';
    	if(c[idx]!=0){
    		continue;
		}else
		c[idx]++;
    	for(int j=i+1;j<len2;j++){
    		d.insert({t[i],t[j]});
		}
	}
//	for(auto it1:a){
//		for(auto it2:d){
//			if(it1.first == it2.first&& it1.second==it2.second){
//				cout<<it1.first<<it1.second<<endl;
//				return;
//			}
//		}
//	}
	for(auto it:a){
		if(d.count(it)){
			cout<<it.first<<it.second<<endl;
				return;
		}
	}
	
	cout<<"HENG!"<<endl;
 }

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
   	int t;
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}
