/*
*  Author : pritish.thakkar 
*  Given array is given as {0,0,0,0,.....}
*  2 Queries : 
*  1. Update range i to j by adding k
*  2. Output sum of elements in range i to j
*/

#include<bits/stdc++.h>
#define         pb                      push_back
#define         mkp                     make_pair
#define         inf                     1000000007
#define         rep(i,n)                for(int i=0;i<n;i++)
#define         fr                      first
#define         sc                      second
#define         clr(a)                  memset(a,0LL,sizeof a);
#define         pi                      3.141592653589793
#define         gc                      getchar
#define         all(v)                  v.begin(), v.end()
#define         filein                  freopen("input.in" , "r" , stdin)
#define         fileout                 freopen("output.in" , "w" , stdout)
#define         TEST                    ll t; cin >> t; while(t--)
#define         NTEST                   ll t; t = 1;    while(t--)
using           namespace               std;

typedef         unsigned long long      ull;
typedef         long long               ll;
typedef         vector<ll>              vi;
typedef         pair<ll,ll>             ii;
typedef         vector<ii>              vii;
typedef         set<ll>::iterator       sit;
typedef         map<ll,ll>::iterator    mit;
typedef         vector<int>::iterator   vit;

template<class T>inline bool read(T &x){int c=gc();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=gc();}for(x=0;~c&&'0'<=c&&c<='9';c=gc())x=x*10+c-'0';x*=sgn;return ~c;}

//_____________________________

bool isUpper(char c) {return (c >= 'A' && c <= 'Z');}
bool isLower(char c) {return (c >= 'a' && c <= 'z');}
bool iplpha(char c) {return (c >= 'A' && c <= 'Z')||(c >= 'a' && c <= 'z');}
bool iplnum(char c) {return (c >= 'A' && c <= 'Z')||(c >= 'a' && c <= 'z')||(c >= '0' && c <= '9');}
char toUpper(char c){return isUpper(c)?c:c-'a'+'A';}
char toLower(char c){return isLower(c)?c:c+'a'-'A';}
template<typename t> t gcd(t a, t b){return ((b == 0) ? a : gcd(b, a%b));} 
template<typename t> t lcm(t a, t b){return (a * (b / gcd(a, b)));}

ll modpow(ll base, ll expo, ll mod){
    base  = base % mod;
    ll ret = 1LL;while(expo > 0){
        if(expo & 1LL){ret =( ret * base) % mod;}
        base = (base * base )% mod;expo >>= 1LL;
    }
    return ret;
}

bool p[10000001];
vi primes;
void sieve(ll n){
    memset(p,1,sizeof p);
    p[0] = p[1] = 0;
    for(int i = 2 ; i <= sqrt(n) ; i++){
        if(p[i]){
            for(int j = i * i ; j < n ; j+=i){p[j] = 0;}
        }
    }
    for(int i = 2 ; i <= n ; i ++){if(p[i]){primes.pb(i);}}
}

bool isPrime(ll n){
    if(n < 1000001){
        return p[n];
    }
    ll ans = 0;
    for(int i= 0 ; i < primes.size() && primes[i] * primes[i] <= n  ; i ++){
        if(n % primes[i] == 0){return 0;}
    }return 1;
}

ll phi(ll n){
    ll ans = n;
    vi v;
    v.clear();
    for(int i = 0; i < primes.size() && primes[i] * primes[i] <= n; i ++){
        if(n % primes[i] == 0){
            v.push_back(primes[i]);
            while(n % primes[i] == 0){
                n /= primes[i];
            }
        }
    }
    if(n != 1){
        v.push_back(n);}
    for(int i = 0 ; i < v.size() ; i ++){
        ans = ans - ans / v[i];
    }
    return ans;
}

ull nCr(ll n, ll r){
    if(r > n / 2){
        r = n - r;
    }
    ull ret = 1;
    for(ll i = 1 ; i<= r ; i ++){
        ret *=  (n - r + i);
        ret /= i;
    }
    return ret;
}

//__________________________________

const ll N = 1e5;
ll n, q;
ll a[N];
ll tree[N * 4];
ll lazy[N * 4];


void reset(){
    memset(a,    0, sizeof (a));
    memset(tree, 0, sizeof(tree));
    memset(lazy, 0, sizeof(lazy));
}

void update(ll left, ll right, ll index, ll lo, ll hi, ll val){
    if(lazy[index]){
        tree[index] += (right - left + 1) * lazy[index];
        if(left != right){
            lazy[index * 2 + 1] += lazy[index];
            lazy[index * 2 + 2] += lazy[index];
        }
        lazy[index] = 0;
    }
    if(left > hi  || right < lo || left > right){
        return;
    }
    if(left >= lo and right <= hi){
        tree[index] += (right - left + 1) * val;
        if(left != right){
            lazy[index * 2 + 1] += val;
            lazy[index * 2 + 2] += val;
        }
        return;
    }
    int mid = (left + right) / 2;
    update(left, mid, index * 2 + 1, lo, hi, val);
    update(mid + 1, right, index * 2 + 2, lo, hi, val);
    tree[index] = tree[index * 2 + 1] + tree[index * 2 + 2];

}

ll query(ll left, ll right, ll index, ll lo, ll hi){
    if(lazy[index]){
        tree[index] += (right - left + 1) * lazy[index];
        if(left != right){
            lazy[index * 2 + 1] += lazy[index];
            lazy[index * 2 + 2] += lazy[index];
        }
        lazy[index] = 0;
    }
    if(left > hi  || right < lo || left > right){
        return 0;
    }
    if(left >= lo and right <= hi){
        return tree[index];
    }
    int mid = (left + right) / 2;
    ll L = query(left, mid, index * 2 + 1, lo, hi);
    ll R = query(mid + 1, right, index * 2 + 2, lo, hi);
    return (L + R);
}

void solve(){
    TEST{
        cin >> n >> q;
        reset();
        while(q--){
            short flag;
            ll lo, hi;
            cin >> flag >> lo >> hi;
            hi --;
            lo --;
            if(flag == 0){
                ll val;
                cin >> val;
                update(0, n-1, 0, lo, hi, val);
            }else{
                cout << query(0, n-1, 0, lo, hi) << endl;
            }
        }
    }

}

//________________________________

int main(int argc, char *argv[]){
    std::ios::sync_with_stdio(0);
    // filein; fileout;
    solve();
}
