/*
*
*  Created By : Pritish Thakkar 
*  Hackerrank : ma5terdrag0n
*  CodeChef : solo_loser
*  Hackerearth : pritish9
*------------------------------------
*  OS : Ubuntu 16.04
*  Language : CPP14
*  Editor : Sublime Text 3
*  C++ compiler : g++
*
*/
#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define inf 1000000007
#define fr first
#define sc second
#define eps 1e-9
#define sz(x) x.size()
#define sni(x) scanf("%d",&x)
#define snl(x) scanf("%lld", &x)
#define snc(x) scanf("%c", &c);
#define rep(n) for(int i = 0 ; i < n ;i ++)
#define repc(i, n) for(int i = 0 ; i < n ; i ++)
#define FOR(i, x, y) for(int i = x ; i < y ; i ++)
#define DEC(i, x, y) for(int i = x ; i >= y ; i --)
#define all(v) v.begin(), v.end()
#define min3(a, b, c) min(a, min(b,c))
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

bool isUpper(char c) {return (c >= 'A' && c <= 'Z');}
bool isLower(char c) {return (c >= 'a' && c <= 'z');}
bool iplpha(char c) {return (c >= 'A' && c <= 'Z')||(c >= 'a' && c <= 'z');}
bool isnum(char c){return (c >= '0' and c <= '9');}
bool isalnum(char c) {return (c >= 'A' && c <= 'Z')||(c >= 'a' && c <= 'z')||(c >= '0' && c <= '9');}
char toUpper(char c){return isUpper(c)?c:c-'a'+'A';}
char toLower(char c){return isLower(c)?c:c+'a'-'A';}
bool isvowel(char c){c = toLower(c); return (c == 'a' or c == 'e' or c == 'i' or c == 'i' or c == 'o' or c == 'u');}
template<typename t> t gcd(t a, t b){return ((b == 0) ? a : gcd(b, a%b));} 
template<typename t> t lcm(t a, t b){return (a * (b / gcd(a, b)));}
template <typename T> T modpow(T base, T exp, T modulus) {base %= modulus;T result = 1;while (exp > 0) {if (exp & 1) result = (result * base) % modulus;base = (base * base) % modulus;exp >>= 1;}return result;}
string toLowerCase(string s){rep(s.size()){if(!isLower(s[i])){s[i] = toLower(s[i]);}}return s;}
string toUpperCase(string s){rep(s.size()){s[i] = toUpper(s[i]);}return s;}
template<typename T> void cumulative(T *a, T *b, T n){rep(n){i ? b[i] = b[i-1] + a[i] : b[i] = a[i];}}
bool ispal(string s){ll lo, hi;lo = 0;hi = s.length()-1;while(lo <= hi){if(s[lo] != s[hi]){return 0;}lo++;--hi;}return 1;}
template<class T >string toString(T n){string v = "";while(n){v.pb(n % 10 + '0');n /= 10;}reverse(all(v));return v;}

//--------------------------------------------------------------------

const int MAXN = 1e2;


struct node{
  node * left, * right;
  ll val;
  node(){

  }
  node(node *l, node *r, ll v){
    left = l;
    right = r;
    val = v;
  }
};


node *version[MAXN];
ll arr[MAXN];

void build(node * n, ll lo, ll hi){
  if(lo == hi){
    n->val = arr[lo];
    return;
  }
  ll mid = (lo + hi) >> 1;
  n->left = new node(NULL, NULL, 0);
  n->right = new node(NULL, NULL, 0);
  build(n->left, lo, mid);
  build(n->right, mid+1, hi);
  n->val = n->left->val + n->right->val;
}

void upgrade(node *prev, node *curr, ll lo, ll hi, ll idx, ll value){
  if(idx > hi or idx < lo or lo > hi){
    return;
  }
  if(lo == hi){
    curr->val = value;
    return;
  }
  ll mid = (lo + hi) >> 1;
  if(idx <= mid){
    curr->right = prev->right;
    curr->left = new node(NULL, NULL, 0);
    upgrade(prev->left, curr->left, lo, mid, idx, value);
  }else{
    curr->left = prev->left;
    curr->right = new node(NULL, NULL , 0);
    upgrade(prev->right, curr->right, mid + 1, hi, idx, value);  
  }
  curr->val = curr->left->val + curr->right->val;
}

ll query(node* curr, ll lo, ll hi, ll left, ll right){
  if(left <= lo and right >= hi){
    return curr->val;
  }
  if(left > hi or right < lo){
    return 0;
  }
  ll mid = (lo + hi) >> 1;
  ll foo, bar;
  foo = query(curr->left, lo, mid , left, right);
  bar = query(curr->right, mid+1, hi, left, right);
  return foo + bar;
}

void solve(){
    int A[] = {1,2,3,4,5};
    int n = sizeof(A)/sizeof(int);
 
    for (int i=0; i<n; i++) 
       arr[i] = A[i];
 
    // creating Version-0
    node* root = new node(NULL, NULL, 0);
    build(root, 0, n-1);
 
    // storing root node for version-0
    version[0] = root;
    cout << query(version[0], 0, n-1, 0, 3) << endl;
    // // upgrading to version-1
    version[1] = new node(NULL, NULL, 0);
    upgrade(version[0], version[1], 0, n-1, 4, 1);
 
    // upgrading to version-2
    version[2] = new node(NULL, NULL, 0);
    upgrade(version[1],version[2], 0, n-1, 2, 10);
 
    cout << "In version 1 , query(0,4) : ";
    cout << query(version[1], 0, n-1, 0, 4) << endl;
 
    cout << "In version 2 , query(3,4) : ";
    cout << query(version[2], 0, n-1, 3, 4) << endl;
 
    cout << "In version 0 , query(0,3) : ";
    cout << query(version[0], 0, n-1, 0, 3) << endl;
}


int main(){
    std::ios::sync_with_stdio(0);
    // int start = clock();
    #ifdef ONLINE_JUDGE
    #else
      freopen("input.in" , "r" , stdin);
      // freopen("output.txt", "w", stdout);
    #endif
    solve();
    // cout << n;
    // int stop = clock();
    // cout << (stop - start) / 1000.0000<< endl;
}



