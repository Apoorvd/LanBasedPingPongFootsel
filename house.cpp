#include<iostream>
#include<bits/stdc++.h>

using namespace std;
#define l1 long long
#define ar array

int n,a[10000],u[10000],v[10000];

void solve(){
    cin >> n ;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    for (int i=0; i<n-1; ++i)
    {
        cint >> u[i] >> v[i];
    }
    for 

    cout << 0 << "\n";
}
int binarySearch(int arr[], int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
        // If the element is present at the middle 
        // itself 
        if (arr[mid] == x) 
            return mid; 
  
        // If element is smaller than mid, then 
        // it can only be present in left subarray 
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 
  
        // Else the element can only be present 
        // in right subarray 
        return binarySearch(arr, mid + 1, r, x); 
    } 
  
    // We reach here when element is not 
    // present in array 
    return -1; 
} 
int main(){
    ios::sync_with_stdio(0);
    //cin.tie(0);

    int t,i=1;
    cin >> t;
    while(t--){
        cout << "Case #" << i << ": ";
        solve();
        ++i;
    }
}