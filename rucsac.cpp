#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;
ifstream fin("rucsac.in");

vector<int> weights;

int main(){
  int maxWeight;
  int m[100000][10000];
  int n;
  vector<int> weights;
  vector<int> values;
  fin>>n>>maxWeight;
  for (auto i = 0; i < n; ++i) {
    int v,w;
    fin>>w>>v;
    weights.push_back(w);
    values.push_back(v);
  }
  // for (auto i = 0; i < weights.size(); ++i) {
  //   cout<<weights[i]<<endl;
  // }


  for(int j=0;j<maxWeight;j++){
    m[0][j]=0;
  }
  for(int i=1;i<n;i++){
    for (auto j = 0; j < maxWeight; j++) {
      if(weights[i]>j){
        m[i][j]=m[i-1][j];
      }else{
        m[i][j]=max (m[i-1][j],m[i-1][j-weights[i]]+values[i]);
      }
    }
  }
  // for (auto i = 0; i < n; ++i) {
  //   for (auto j = 0; j < maxWeight; ++j) {
  //     cout<<m[i][j]<<" ";
  //   }
  //   cout<<endl;

  // }
  cout<<m[n-1][maxWeight-1]<<endl;


}
