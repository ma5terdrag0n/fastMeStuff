/*
*  ________________________________________
*      | |     / / 
*      | |    / /   Pritish Thakkar !
*  ____|_|_ _/_/___________________________
*      | |  / /   
*      | | / /      Dream Big ! Work Hard !  
*  ____|_|/_/______________________________
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
#define         fileout                 freopen("output.out" , "w" , stdout)
#define         test                    ll t; cin >> t; while(t--)
#define         ntest                   ll t; t = 1;    while(t--)
#define         sz(x)                   x.size()
#define         pass                    {}

using           namespace               std;

typedef         unsigned long long      ull;
typedef         long long               ll;

//__________________________________

ll dp[2][2];
ll ans[2][2];
void mulpro(ll F[2][2], ll M[2][2])
{
  int x =  (F[0][0]*M[0][0] % inf + F[0][1]*M[1][0] % inf) % inf;
  int y =  (F[0][0]*M[0][1] % inf + F[0][1]*M[1][1] % inf) % inf;
  int z =  (F[1][0]*M[0][0] % inf + F[1][1]*M[1][0] % inf) % inf;
  int w =  (F[1][0]*M[0][1] % inf + F[1][1]*M[1][1] % inf) % inf;
 
  F[0][0] = ( x + inf ) % inf;
  F[0][1] = ( y + inf ) % inf;
  F[1][0] = ( z + inf ) % inf;
  F[1][1] = ( w + inf ) % inf;
}

void multiply(ll n){
    ans[0][0] = ans[1][0] = ans[0][1] = 1;
    ans[1][1] = 0;
    while(n > 0){
        if(n & 1){
            mulpro(ans, dp);
        }    
        mulpro(dp, dp);
        n /= 2;
    }
}


void solve(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        dp[0][0] = dp[1][0] = dp[0][1] = 1;
        dp[1][1] = 0;
        multiply(n);
        cout << ans[0][0] << endl; 
    }

}
 
//________________________________

int main(int argc, char *argv[]){
    std::ios::sync_with_stdio(0);
    // filein; 
    // fileout;
    solve();
}
 
