/*
要求：子数组和 = 子数组长度
思路：
暴力： b[i]-b[j-1]==i-j+1
-->b[i]-i == b[j-1]-(j-1)-->f[i]=b[i]-i
unordered_map无序存储，计数； 
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 1010

void go(){
	int cnt=0;
    int n;cin>>n;
    vector<int>a(n+1);
    vector<int>b(n+1,0);
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	b[i] = b[i-1]+a[i];
	}
//	for(int i=1;i<=n;i++){
//    	cout<<"a"<<a[i]<<" "<<b[i];
//	}
//	for(int i=1;i<=n;i++){
//		if(a[i]==1)cnt++;
//		if(b[i]==i)cnt++;
//		for(int j=1;j<=i;j++){
//			if(b[i]-b[j-1]==i-j+1)cnt++;
//			//cout<<i<<" "<<"cha:"<<b[i]-b[j];
//		}
//	}
	unordered_map<int,int>mp;
	mp.reserve(n * 2);         // 防止 rehash 提升速度
    mp.max_load_factor(0.7);
	mp[0]=1;
	for(int i=1;i<=n;i++){
		int tmp =b[i]-i;
		cnt+=mp[tmp];
		mp[tmp]++;
	}
	cout<<cnt<<endl;
 }

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
   	int t;
    cin >> t;
    while(t--){
        go();
    }
    
    return 0;
}


/*
in:
1
3
1 2 0

out:
3

*/
