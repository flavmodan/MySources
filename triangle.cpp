#include<iostream>
#include<fstream>
using namespace std;

ifstream fin("triangle.in");

int main(){
  int tri[100][100]={0},sums[100][100]={0};
  int n;
  fin>>n;
  for(int i=0;i<n;i++){
    for(int j=0;j<=i;j++){
      fin>>tri[i][j];
    }
  }
  for(int i=0;i<n;i++){
    sums[n-1][i]=tri[n-1][i];
  }
  for(int i=n-1;i>0;i--){
    for(int j=0;j<i;j++){
      int el=max(sums[i][j],sums[i][j+1]);
      sums[i-1][j]=el+tri[i-1][j];
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<=i;j++){
      cout<<sums[i][j]<<" ";
    }
    cout<<endl;
  }
  int row=0;
  int maxpos=0;
  cout<<endl;
  while(row<n-1){
    cout<<tri[row][maxpos]<<" ";
    if(sums[row+1][maxpos]<=sums[row+1][maxpos+1]){
      maxpos++;
    }
    row++;
  }
  cout<<tri[row][maxpos]<<" ";
}
