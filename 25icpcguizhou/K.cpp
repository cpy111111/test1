/*
给定n个字符串，每次查询i字符串和翻转后的j字符串的最长公共前缀。
解：
存储每个字符串的翻转前后的前缀哈希值，
然后查询的时候二分长度判断是否匹配即可。 
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef unsigned long long ull;
const ull B = 131;

void go(){
    int n,m;cin>>n>>m;
    vector<string>a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    
    int mlen=0;
    for(int i=1;i<=n;i++){
    	mlen = max(mlen,(int)a[i].size());
	}
	
//	vector<ull>p(mlen+1);
//	p[0]=1;
//	for(int i=1;i<=mlen;i++){
//		p[i] = p[i-1]*B;
//	}
	
	vector< vector<ull> >h1(n+1),h2(n+1);
	for(int i=1;i<=n;i++){
		int len = a[i].size();
		h1[i].resize(len+1);
		h2[i].resize(len+1);
		h1[i][0] = 0;
		h2[i][0] = 0;
		
		for(int j=0;j<len;j++){
			h1[i][j+1] = h1[i][j]*B + (ull)a[i][j];
			h2[i][j+1] = h2[i][j]*B + (ull)a[i][len-1-j];
		}
	}
	
	while(m--){
		int t1,t2;cin>>t1>>t2;
		int cnt=0;
		int len1 = a[t1].size();
		int len2 = a[t2].size();
		
		int l=0,r = min(len1,len2);
		while(l<r){
			int mid = (l+r+1)>>1;
			if(h1[t1][mid] == h2[t2][mid]){
				l=mid;
			}else{
				r = mid-1;
			}
		}
		cout<<l<<endl;
	}
 }

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);	
        go();
    return 0;
}


/*
in:
3 3
ABCBC
BBCBA
DACBB
1 2
2 3
1 3 

out:
4
3
0 
*/
