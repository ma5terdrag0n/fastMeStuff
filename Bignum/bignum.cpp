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
#define     pi                      3.141592653589793
#define     gc                      getchar

using       namespace               std;

typedef     unsigned long long      ull;
typedef     long long               ll;
typedef     vector<ll>              vi;
typedef     pair<ll,ll>             ii;
typedef     vector<ii>              vii;
typedef     set<ll>::iterator       sit;
typedef     map<ll,ll>::iterator    mit;
typedef     vector<int>::iterator   vit;

template<class T>inline bool read(T &x){int c=gc();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=gc();}for(x=0;~c&&'0'<=c&&c<='9';c=gc())x=x*10+c-'0';x*=sgn;return ~c;}

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

bool p[1000001];
vi primes;
void sieve(){memset(p,1,sizeof p);p[0] = p[1] = 0;
    for(int i = 2 ; i <= sqrt(1000001) ; i++){if(p[i]){for(int j = i * i ; j < 1000001 ; j+=i){p[j] = 0;}}}
    for(int i = 2 ; i <= 1000000 ; i ++){if(p[i]){primes.pb(i);}}}

bool isPrime(ll n){if(n < 1000001){return p[n];}ll ans = 0;for(int i= 0 ; i < primes.size() && primes[i] * primes[i] <= n  ; i ++){if(n % primes[i] == 0){return 0;}}return 1;}
 
//______________________________

class Bignum;
void multiply(Bignum *x, Bignum *y, int *c, int& sc, bool decimal);
int multiplyUtil(int *a, int sizeA, int *b, int sizeB, int *product);
void multiply(Bignum *a, Bignum *b, int *c, int& sc, bool decimal);
int addUtil(int *x, int sa, int *y, int sb, int *c);
class Bignum{
public:
    int ar[1000], rtt, sizE;
    Bignum(){
        rtt = sizE = 0;
    }
    Bignum(string s, bool decimal = false){
        conv(s,ar,rtt,decimal);
    }
    Bignum(int *a, int n){
        for(int i = 0 ; i  < n ; i ++){
            ar[i] = a[i];
        }
    }
    void conv(string s, int *a, int& raiseToTen, bool decimal = false){
        if(!decimal){
            for(int i = 0 ; i < s.size() ; i ++){
                a[i] = s[i] - '0';
            }
            raiseToTen = 0;
            sizE = s.size();
        }else{
            bool done = 0;
            raiseToTen = 0;
            for(int i = 0 ; i < s.size() ; i ++){
                if(s[i] == '.'){
                    done = 1;
                }else{
                    
                    if(done){
                        raiseToTen++;
                        a[i-1] = s[i] - '0';
                    }else{
                        a[i] = s[i] - '0';
                    }
                }
            }

            sizE = s.size()-1;
        }
    }
    friend void multiply(Bignum *x, Bignum *y , int *c, int& sc, bool decimal);
    friend void add(Bignum *x, Bignum *y, int *c, int& sc, bool decimal);
};

void add(Bignum *a, Bignum *b, int *c, int& sc, bool decimal = 0){
    int sa, sb;
    sa = a->sizE, sb = b->sizE;
    if(decimal){
        sa--,--sb;
    }
    sc = addUtil(a->ar, sa, b->ar, sb, c);
}

int addUtil(int *x, int sa, int *y, int sb, int *c){    
    int start = 0, sz = 0, carry = 0;
    sa--,--sb;
    for(;sa >= 0 && sb >= 0 ; sa--,--sb){
        int temp = c[start];
        c[start] = (temp + carry + x[sa] + y[sb]) % 10;
        carry = (carry + temp + x[sa] + y[sb]) / 10;
        start++;
    }
    while(sa >= 0){
        int temp = c[start];
        c[start] = (temp + carry + x[sa]) % 10;
        carry    = (carry + temp + x[sa]) / 10;
        sa--;
        start++;
    }
    while(sb >= 0){
        int temp = c[start];
        c[start] = (temp + carry + y[sb]) % 10;
        carry = (carry + temp + y[sb]) / 10;
        sb--;
        start++;
    }
    while(carry){
        int temp = c[start];
        c[start] = (temp + carry) % 10;
        carry = (carry + temp) / 10;
        start++;
    }
    reverse(c,c + start);
    return start;
}

void multiply(Bignum *a, Bignum *b, int *c, int& sc, bool decimal = 0){
    int sa, sb;
    sa = a->sizE, sb = b->sizE;
    if(decimal){
        sa--,--sb;
    }
    sc = multiplyUtil(a->ar, sa, b->ar, sb, c);
}


int multiplyUtil(int *a, int sizeA, int *b, int sizeB, int *product){
    int counter = 0;
    int sz = 0;
    for(int i = sizeB-1 ; i >= 0 ; i --){
        int carry = 0;
        int start = counter;
        counter++;
        for(int j = sizeA-1 ; j >= 0 ; j --){
            int xess = product[start];
            product[start] = (xess + b[i] * a[j] + carry) % 10;
            carry = ( xess + b[i] * a[j] + carry) / 10;
            start++;  
        }
        
        while(carry){
            int xess = product[start];
            product[start] = (xess + carry) % 10;
            carry = (xess + carry) / 10;
            start++;
        }
        sz = max(sz, start);
    }
    reverse(product, product + sz);
    return sz;
}

void solve(){
    Bignum *b1 = new Bignum("1111111111111111");
    Bignum *b2 = new Bignum("2222222222222222");
    int c[1000] = {0};
    int n = 0;
    add(b1, b2, c, n);
    for(int i = 0 ; i < n ; i ++){
        cout<< c[i] ;
    }cout << endl;
    memset(c,0,sizeof(c));
    multiply(b1, b2, c, n);
    for(int i = 0 ; i < n ; i ++){
        cout<< c[i] ;
    }
}

//___________________________
int main(int argc, char *argv[]){
    std::ios::sync_with_stdio(0);
    solve();
}
 
 
 
/*  OUTPUT :
  3333333333333333
  2469135802469135308641975308642
*/
