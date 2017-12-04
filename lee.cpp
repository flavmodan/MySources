#include<iostream>
#include<fstream>
#include<deque>
using namespace std;

ifstream fin("lee_mat.in");

struct point
{
  int x,y;
};

int main(){
  int map[100][100]={0};
  int n,m;
  fin>>n>>m;
  deque<point> que;
  point Start,Finish;
  fin>>Start.x>>Start.y>>Finish.x>>Finish.y;
  que.push_back(Start);
  for (auto i = 0; i < n; ++i) {
    for (auto j = 0; j < m; ++j) {
      fin>>map[i][j];
    }

  }
  

}
