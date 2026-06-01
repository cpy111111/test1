/*dp 
n*m网格，数据-1/1构成，只能向下向右移动，求是否存在路径数据和为0

解：
(1,1)出发到(n,m)任何路径都恰好经过n+m-1个格子
每个格子值为 -1/1，必定偶数个格子满足和为0，
即：合法路径n+m为奇数 ，为偶return

判断是和否为0，寻找上界下界范围，是否包含0 
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
const int INFt = -(1LL << 60);
const int INFl = (1LL << 60);


void go(){
	int n,m;
    cin>>n>>m;

	vector< vector<int> >a(n+1, vector<int>(m+1));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j]; 
		}
	}
	//特判:合法路径n+m为奇数 ，为偶pass
	if((n+m)%2==0){
		cout<<"NO"<<endl;
		return;
	}
	vector<vector<int>> dpt(n + 1, vector<int>(m + 1, INFt));
    vector<vector<int>> dpl(n + 1, vector<int>(m + 1, INFl));
    
    dpt[1][1] = dpl[1][1] = a[1][1];
    
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i==1 && j==1)continue;//起点
			
			//向下走
			if(i>1){
				dpt[i][j] = max(dpt[i][j], dpt[i-1][j]+a[i][j]);
				dpl[i][j] = min(dpl[i][j], dpl[i-1][j]+a[i][j]);
			} 
			//右
			if(j>1){
				dpt[i][j] = max(dpt[i][j], dpt[i][j-1]+a[i][j]);
				dpl[i][j] = min(dpl[i][j], dpl[i][j-1]+a[i][j]);
			} 
		}
	}
	
	if(dpt[n][m] >= 0 && dpl[n][m]<=0){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
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


*/
