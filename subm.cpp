#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

int main(){
  int n=10,m;
  
  double possible=log2(n);
  cout<<n<<endl;
  //cout<<possible;
  if(int(possible)==possible)
    m=possible;
  else
    m=int(possible)+1;
  //cout<<m;
  vector<vector<int> >subm(m);
  for(int i=0;i<m;i++){
    for(int j=1;j<n;j++){
      int candidate=j;
      candidate=candidate>>i;
      //cout<<candidate<<endl;
      if(candidate&1){
        subm[i].push_back(j);
        //cout<<j<<"in mat "<<i<<endl;
      }
    }
  }
  for(int i=0;i<subm.size();i++){
    cout<<i+1<<" : ";
    for(int j=0;j<subm[i].size();j++){
      cout<<subm[i][j]<<" ";
    }
    cout<<endl;
  }
}
