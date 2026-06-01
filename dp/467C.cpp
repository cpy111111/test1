/*
从固定序列中选 k 个不重叠的、长度为 m 的连续区间，使和最大

转移方程：
不选：dp[i][j] = dp[i-1][j];
选：dp[i][j] = max(dp[i-1][j], dp[i - m][j - 1] + sum)
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
const int INF = -(1LL << 60);  // 约等于 -1e18


void go(){
    int n,m,k;
    int sum=0;
    cin>>n>>m>>k;
	vector<int>a(n+1),b(n+1);
	vector< vector<int> >dp(n+1,vector<int>(k+1,INF));

	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i] = b[i-1]+a[i];
	} 
	//前i个位置，已经选了j个区间 
	for(int i=0;i<=n;i++)dp[i][0]=0;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			if(i>=m){
				int sum = b[i]-b[i-m];
				dp[i][j] = max(dp[i-1][j], dp[i-m][j-1]+sum);
			}else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	
	cout<<dp[n][k]<<endl;
 }

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);   	
        go();
    return 0;
}


/*


*/
