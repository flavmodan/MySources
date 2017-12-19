#include<iostream>
#include<fstream>
#include<cmath>
#include<deque>

using namespace std;

ifstream fin("dijkstra.in");

bool connecting[100][100];
int cost[100],n,cost_per_edge[100][100];
bool visited[100];

int main(){
  int p;
  fin>>n>>p;
  int b,e,c;
  while(fin>>b>>e>>c){
    connecting[b][e]=true;
    cost_per_edge[b][e]=c;
  }
  
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(!connecting[i][j])
        cost_per_edge[i][j]=INFINITY;
    }
  }
  // for(int i=1;i<=n;i++){
  //   for(int j=1;j<=n;j++)
  //     cout<<cost_per_edge[i][j]<<" ";
  //   cout<<endl;
  // }
  for(int i=1;i<=n;i++){
    cost[i]=INFINITY;
  }
  cost[p]=0;
  deque<int> nodes;
  nodes.push_back(p); 
  while(nodes.size()>0){
    for(int i=1;i<=n;i++)
      cout<<cost[i]<<" ";
    cout<<" : ";
    // cout<<endl;
    for(int i=0;i<nodes.size();i++){
      cout<<nodes[i]<<" ";
    }
    cout<<endl;
    for(int i=1;i<=n;i++){
      if(connecting[nodes[0]][i]){
        if(cost[i]>cost[nodes[0]]+cost_per_edge[nodes[0]][i]){
          cost[i]=cost[nodes[0]]+cost_per_edge[nodes[0]][i];
        }
      }
    }
    visited[nodes[0]]=true;
    int min=100,minPoz=-1;
    for(int i=1;i<=n;i++){
      if(min>cost[i] && !visited[i]){
        min=cost[i];
        minPoz=i;
      }
    }
    nodes.pop_front();
    if(minPoz>0)
      nodes.push_back(minPoz);
  }
  for(int i=1;i<=n;i++)
    if(cost[i]==INFINITY)
      cout<<"-1";
    else
      cout<<cost[i]<<" ";


}
