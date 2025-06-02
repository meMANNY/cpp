//<---VIVEK NISHAD --->// 
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using vi = vector<int>;
using vl = vector<ll>;
using v2d = vector<vector<ll>>;
using sed = set<ll>;
#define v2d(n, m, val) vector<vector<ll>>(n, vector<ll>(m, val))
#define intest(b) while(t--)
#define ini(a,b) for(int i=(a);i<=(b);i++)
#define inn(e,f) for(int n=e;n>=f;n--)
#define INF INT_MAX
#define LLINF LLONG_MAX
#define mod 1000000007
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define ff first
#define ss second
#ifndef ONLINE_JUDGE
    #define dbg(x) cout << #x << " = " << x << endl;
#else
    #define dbg(x)
#endif
ll power(ll a,ll b){
    if(b==0) return 1;
    ll res = power(a, b / 2);
    if(b % 2 == 0) return res * res;
    return a * res * res;
}
vector<ll> sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    vector<ll> prime;
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) prime.push_back(i);
    }
    return prime;
}
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define l '\n'
int main(){
    FAST;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t; cin >> t; intest(t)
    {  
     
        ll n; cin>>n;
        vl arr(n);
        vector<pair<ll,ll>>vp;
        ini(0,n-1){cin>>arr[i];
         vp.push_back({arr[i],i});
        }
        vl ans(n+1);
        ans[0]=(n+1)/2;
       
sort(all(vp));

int i=1,k=1;
for (int  j =vp.size()-1;j>=0;j--)
{
   
if(j%2==0 ){ ans[vp[j].second+1]=ans[0]+i;i++;}
else { ans[vp[j].second+1]=ans[0]-k;k++;}



}
ll ans1=0;
int o=0;
for (auto x:ans)
{

    if(x!=ans[0]){
    ans1+= 2*arr[o]*(abs(x-ans[0]));o++;
}



    
}

cout<<ans1<<l;
for (int  m = 0; m<=n; m++)
{
  cout<<ans[m]<<" ";
}
cout<<l;


    
    }
}