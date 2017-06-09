/*
*  Author : pritish.thakkar 
*  Problem Link : https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/tutorial/
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

map<ll, vii> adj;

void solve(){
    ll n,m;
    cin >> n >> m;
    ll i;
    rep(i,m){
        ll x, y, weight;
        cin >> x >> y >> weight;
        adj[x].pb(ii(y, weight));
        adj[y].pb(ii(x, weight)); // comment it for directed graph ! xD
    }
    
    // 1-based indexing of graph
    /************************************
          DIJKSTRA ALGORITHM
    ************************************/
    
    ll source = 1;
    priority_queue<ll, vii, greater<ii> > pq;
    pq.push(ii(0LL, source));
    vector<ll> dist(n+1, inf);
    dist[source] = 0;
    while(!pq.empty()){
        ii node = pq.top();
        pq.pop();
        ll d = node.fr;
        ll u = node.sc;
        if(d != dist[u])
            continue;
        for(vii::iterator it = adj[u].begin() ; it != adj[u].end() ; it++){
            ll v = it->fr;
            ll weight = it->sc;
            if(dist[v] > dist[u] + weight){
                dist[v] = dist[u] + weight;
                pq.push(ii(dist[v], v));
            }
        }
    }
    
    /*****************   ENDS *******************/
    
    //____________________________________________________
    
    for(int i = 2 ; i <= n ; i ++){
        printf("%lld ", dist[i]);
    }
}

//______________________________________________________________________________________________________________

int main(int argc, char *argv[]){
    std::ios::sync_with_stdio(0);
    solve();    
}
 
 
