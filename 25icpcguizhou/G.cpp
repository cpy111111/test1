/*多测 
一组有序数组，每个数对应一个值;
要求： 按值的大小升序遍历，问一共遍历几次；
思路： 将idx和数值存入结构体，值升序排序；
for循环遍历，比较idx大小，记录cnt（即重复遍历次数） 

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 


struct node{
	int id,x;
};

bool cnp(node a,node b){
	return a.x<b.x;
}
void go(){
    int n;cin>>n;
    vector<node>a(n);
    for(int i=0;i<n;i++){
    	a[i].id = i;
    	cin>>a[i].x;
	}
	sort(a.begin(),a.end(),cnp);
	int cnt=0;
	for(int i=0;i<n-1;i++){
		if(a[i].id>a[i+1].id)cnt++;
	}
	
	cout<<cnt+1<<endl;
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
2
5
1 5 2 3 4
6
5 2 4 3 1 6

out:
2
4
*/
