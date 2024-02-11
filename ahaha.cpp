#include<iostream>
#include<bits/stdc++.h>

using namespace std;
inta[1000],c;
void solve(){
    int n,i,m=0;
    int arr[1000]
    cin >> n ;
    if(!(n>=2 && n<=1000 && n%2==0))
    exit(0);
    c=0;
    for (i=0; i<n; ++i)
    {
        cin >> a[i];
        if(a[i]==1)
        c++;
        if(a[i]==0)
        m=i;
    }
    int dup=c;
    if(c%2==1 && c>n/2)
    {
        for(i=0;i<n;i++)
        {
            if(a[i])==1){
                dup--;
                
            }
            
            else if(a[i]==0)

        }
    }


    //cout << "\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t,i=1;
    cin >> t;
    if(!(t>=1 && t<=50))
    exit(0);
    while(t--){
        cout << "Case #" << i << ": ";
        solve();
        ++i;
    }
}