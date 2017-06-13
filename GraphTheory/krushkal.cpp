
/*
*  Author : pritish.thakkar 
*/

#include<bits/stdc++.h>
#define     pb                      push_back
#define     mkp                     make_pair
#define     inf                     1000000007
#define     rep(i,n)                for(int i=0;i<n;i++)
#define     fr                      first
#define     sc                      second
#define     clr(a)                  memset(a,0LL,sizeof a);
#define     WHITE                   0
#define     BLACK                   1
#define     pi                      3.141592653589793

using       namespace               std;

typedef     unsigned long long      ull;
typedef     long long               ll;
typedef     vector<ll>              vi;
typedef     pair<ll,ll>             ii;
typedef     vector<ii>              vii;
typedef     set<ll>::iterator       sit;
typedef     map<ll,ll>::iterator    mit;
typedef     vector<int>::iterator   vit;

//_____________________________

bool isUpper(char c) {return (c >= 'A' && c <= 'Z');}
bool isLower(char c) {return (c >= 'a' && c <= 'z');}
bool iplpha(char c) {return (c >= 'A' && c <= 'Z')||(c >= 'a' && c <= 'z');}
bool iplnum(char c) {return (c >= 'A' && c <= 'Z')||(c >= 'a' && c <= 'z')||(c >= '0' && c <= '9');}
char toUpper(char c){return isUpper(c)?c:c-'a'+'A';}
char toLower(char c){return isLower(c)?c:c+'a'-'A';}
ll hcf(ll a,ll b){return ((b == 0) ? a : hcf(b, a%b));} 
ll modpow(ll base, ll expo, ll mod){base  = base % mod;ll ret = 1LL;while(expo > 0){if(expo & 1LL){ret =( ret * base) % mod;}base = (base * base )% mod;expo >>= 1LL;}return ret;}
 
//______________________________

vector<pair<ll, ii> > v; // Edge List
ll parent[3001]; // change this acc to number of nodes in a graph
int mst_count;

ll findSet(ll x){
    return (parent[x] == x) ? x : (parent[x] = findSet(parent[x]));
}

bool isSameSet(ll a, ll b){
    return ( findSet(a) == findSet(b));
}

void _union_(ll a, ll b){
    parent[findSet(a)] = findSet(b); 
}


void solve(){
    ll n, m;
    cin >> n >> m;
    

    while(m -- ){
        ll x, y, r;
        cin >> x >> y >> r;
        x --, y --;
        v.pb(mkp(r , ii(x, y)));
    }
    
    //**********MST - Krushkal************
    sort(v.begin(), v.end());
    
    for(int i = 0 ; i < n ; i ++){
        parent[i] = i;
    }
    mst_count = 0;
    int index = 0;
    while(index < v.size()){
        pair<int, ii > front = v[index++];
        if(!isSameSet(front.sc.sc, front.sc.fr)){
            mst_count += (front.fr);
            _union_(front.sc.fr, front.sc.sc);
        }
    }

    cout << mst_count << endl;
    //*************************************


}

//______________________________________________________________________________________________________________
int main(int argc, char *argv[]){
    std::ios::sync_with_stdio(0);
    solve();
    // freopen(argv[1] , "r" , stdin);
    // freopen("output.out" , "w" , stdout);
}
 
 
