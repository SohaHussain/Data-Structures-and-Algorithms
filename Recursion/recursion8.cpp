// find sum of all digits of a number

#include<bits/stdc++.h>
using namespace std;

int sumn(int n)
{
  if(n<10)
  return n;
  return sumn(n/10)+n%10;
}
int main()
{
  int n;
  cin>>n;
  cout<<sumn(n);
  return 0;
}