#include<iostream>
using namespace std;
int main(){
  int test[90000][90000];
  test[9999][9999]=0;
  cout<<test[9999][9999];
}
