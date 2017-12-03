#include<iostream>
using namespace std;

int main(){
  int n,k;
  //cin>>n>>k;
  n=4;k=4;
  int steps[100]={0};
  steps[n]=1;
  int position=n;
  while(position!=1){
    for(int i=1;i<=k;i++){
      if(position-i>=1){
          steps[position-i]=steps[position-i]+steps[position];
      }
    }
    position--;
    // for(int i=1;i<=n;i++){
    //   cout<<steps[i]<<" ";
    // }
    // cout<<endl;
  }
  cout<<steps[1];
}

