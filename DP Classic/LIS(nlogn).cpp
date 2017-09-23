#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define inf 1000000009
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
	// int start = clock();
	freopen("input.in" , "r" , stdin);
	//LIS
	ll t;
	t = 1;
	while(t --){
		ll a[111111];
		ll n = 0;
		while(cin >> a[n++]);
		vector<ll> v;
		int index[n];
		int pre[n] = {-1};
		for(int i= 0 ; i < n ; i ++){
			if(v.empty()){
				v.pb(a[i]);
				index[v.size() - 1] = i;
				pre[i] = -1;
			}else{
				if(v[v.size() - 1]  < a[i]){
					v.pb(a[i]);
					index[v.size() - 1] = i;
					pre[i] = index[v.size()-2];
				}

				else{
					int pos = upper_bound(v.begin() , v.end() , a[i]) - v.begin();
					v[pos] = a[i];	
					index[pos] = i;			
					pre[i] = index[pos-1];
				}
			}
			// cout << v[v.size() - 1] << " " << pre[i] << " " << index[v.size() - 1] << endl;
		}
		cout << v.size() << endl;
		cout << "-\n";
		int j = index[v.size() - 1];
		stack<int> st;
		while(j != -1){
			st.push(a[j]);
			j = pre[j];
		}
		while(!st.empty()){
			cout << st.top() << "\n";
			st.pop();
		}

	}
	// cout << n;
	// int stop = clock();
	// cout << (stop - start) / 1000.0000<< endl;
}
