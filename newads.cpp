#include<iostream>

using namespace std;

 

int fun(int x=20, int y = 20, int z)

{  return (x + y + z); }

 

int main()

{

   cout << fun(10);

   return 0;

}