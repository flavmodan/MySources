#include<iostream>
#include<math.h>
#include<vector>
#include<fstream>
using namespace std;

ifstream fin("multimi.in");
ofstream fout("multimi.out");

int main(){
  int n,m;
  fin>>n;
  double possible=log2(n);
  //cout<<n<<endl;
  //cout<<possible;
  if(int(possible)==possible)
    m=possible;
  else
    m=int(possible)+1;
  //cout<<m;
  vector<vector<int> >subm(m);
  for(int i=0;i<m;i++){
    for(int j=1;j<=n;j++){
      int candidate=j;
      candidate=candidate>>i;
      //cout<<candidate<<endl;
      if(candidate&1){
        subm[i].push_back(j);
        //cout<<j<<"in mat "<<i<<endl;
      }
    }
  }
  fout<<m<<endl;
  for(int i=subm.size()-1;i>=0;i--){
    //cout<<i+1<<" : ";
    for(int j=0;j<subm[i].size();j++){
      fout<<subm[i][j]<<" ";
    }
    fout<<endl;
  }
}
