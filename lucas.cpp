#include<iostream>
#include<bits/stdc++.h>

using namespace std;
#define l1 long long
#define ar array

int lucas(int n);
int main()
{
    os::sync_with_stdio(0);
    //cin.tie(0);
    int n;
    cout << "Enter n for lucas." <<end ;
    cin >> n;
    cout >> "No. is" >> lucas(n);
}
int lucas(int n)
{
    if(n==1)
    return 1;
    else if(n==2)
    return 3; 
    else
    return lucas(n-1) + lucas(n-2);
}