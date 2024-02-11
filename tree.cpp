#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int a[100000],c;
void nully(int &a, int j , int n)
{
    c++;
    int i;
    for(i=n-1; i>j ; i++)
    {
        a[i]=a[j];
    }
    return;
}
bool areSame(int &a,int n) 
{ 
    unordered_map<int,int> m;//hash map to store the frequency od every 
                             //element 
      
    for(int i=0;i<n;i++) 
       m[a[i]]++; 
       
    if(m.size()==1) 
       return true; 
    else 
       return false; 
} 
void solve(){
    int n,i,j=0;
    cin >> n ;
    if(!(n>=1))
    exit(0);
    c=0;
    for (i=0; i<n; ++i)
        cin >> a[i];
    sort(a,a+n);
    for(i=0; i<n; ++i)
    {
        if(a[n-1]==a[n-i])
        continue;
        else
        {j=i; nully(a[0], j, n) ;}
    }
    if(areSame(a[0],n)&& a[0]>0)
    c++;
    cout << c <<"\n";


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