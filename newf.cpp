#include<iostream>
#include<bits/stdc++.h>

using namespace std;
#define l1 long long
#define ar array

int n,b,a[10000];

boolean coprime(int a, int b) { 
      
    if ( __gcd(a, b) == 1) 
        return true;      
    else 
        return false;  
} 

void solve(){
    cin >> n >> b;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    sort(a,a+n);
    int ans=0;
    for (int i=0; i<n; ++i)
    {
        if(b>=a[i]){
        b-=a[i];
        ++ans;}
    }
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        solve();
        ++i;
    }
}