#include<iostream>

#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){

  ll t;
//
  cin>>t;

  while(t--){

    ll n,k;

    cin>>n>>k;

    vector<ll>v(n);

    vector<vector<ll>>all(k+1);

    for(ll i=0;i<n;i++){

      cin>>v[i];

      all[v[i]].push_back(i);

    }

    ll ans=LLONG_MAX;

    for(ll i=0;i<=k;i++){

      if(!all[i].empty()){

        ll first=all[i][0];

        ll second=LLONG_MIN;

        //cout<<i<<endl;

        for(ll j=1;j<all[i].size();j++){

          ll dis=all[i][j]-all[i][j-1]-1;

          //cout<<dis<<endl;

          if(dis>first){

            second=first;

            first=dis;

          }

          else if(dis<=first&&dis>second){

            second=dis;

          }

        }

        ll dis=n-all[i][all[i].size()-1]-1;

        if(dis>first){

          second=first;

          first=dis;

        }

        else if(dis<=first&&dis>second){

          second=dis;

        }

        //cout<<first<<" "<<second<<endl;

        first=first/2;

        ll temp=max(first,second);

        ans=min(ans,temp);

      }

    }

    cout<<ans<<endl;

  }

}