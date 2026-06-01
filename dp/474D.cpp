/*
构造长度为 n 的红白花序列，要求白花只能连续出现 k 朵。
求：长度在 [a,b] 范围内的合法序列总数。

解：
情况1：最后一朵是红花，前面n-1朵合法 
情况2：最后一组是k朵白花，前面n-k朵合法
即：dp[n]=dp[n-1]+dp[n-k]

求合法串个数-->前缀和;
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
const int MOD = 1000000007;

ll dp[N];
ll sum[N];
 
void go(){
	int t,k;cin>>t>>k;
    
    dp[0]=1;
    
    for(int i=1;i<N;i++){
    	dp[i] = dp[i-1];
    	if(i-k>=0){
    		dp[i] = (dp[i] + dp[i-k])%MOD;
		}
	}
	
	for(int i=1;i<N;i++){
		sum[i] = (sum[i-1] + dp[i])%MOD;
	}
	
	while(t--){
		int a,b;cin>>a>>b;
		ll ans = (sum[b]-sum[a-1]+MOD)%MOD;
		cout<<ans<<endl;
	}
 }

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
        go();
    return 0;
}


/*


*/
