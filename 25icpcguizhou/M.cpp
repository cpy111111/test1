/*
纯模拟，注意数据单位！ 
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1010

void go(){
	int cnt=0;
    int pos=0;
    vector<int>a(26);
    for(int i=0;i<26;i++){
    	cin>>a[i];
	}
	string s;
	cin>>s;
	int now=0;
	for(int i=0;i<s.size();i++){
		int x=a[s[i]-'a'];//坐标x 
		int len1 = abs(now-x)*10;
		int tmp1 = now*10+1+(1000-x)*10;
		int tmp2 = (1000-now)*10+1+x*10;
		int len2 = min(tmp1,tmp2);
		if(len1 <= len2){
			cnt+=len1;
		}else{
			cnt+=len2;
		}
		now = x;
//		cout<<"X:"<<x<" ";
//		cout<<"len"<<len1<<" "<<len2<<"\n";
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
999 2 3 4 5 22 23 24 25 26 11 12 13 14 15 16 17 18 19 20 21 6 7 8 9 10
abcda

out:
113

*/
