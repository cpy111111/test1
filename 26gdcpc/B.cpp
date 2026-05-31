#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1010

void solve(){
    int t;cin>>t;
    while(t--){
    	int x;cin>>x;
    	if(x==0){
    		cout<<0<<endl;
    		return;
		}
		
		ll m=(ll)sqrt((long double)x);
		
		while(m*m>x)m--;
		while((m+1) * (m+1) <=x) m++;
	}
 }

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
   
        solve();
    
    
    return 0;
}
