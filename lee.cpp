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
  fin>>Start.y>>Start.x>>Finish.y>>Finish.x;
  que.push_back(Start);
 
  for (auto i = 0; i < n; i++) {
    for (auto j = 0; j < m; j++) {
      fin>>map[i][j];
    }

  }
  int xDir[]={-1,1,1,-1,0,0,1,-1};
  int yDir[]={-1,1,-1,1,-1,1,0,0};

  bool found = false;

  while(que.size()>0 && !found){
    int currentX=que[0].x,currentY=que[0].y;
    int road = map[currentY][currentX];
    map[Start.y][Start.x]=-1;
    cout<<endl;
    for (auto i = 0; i < n; ++i) {
      for (auto j = 0; j < m; ++j) {
        cout<<map[i][j]<<" ";
      }
      cout<<endl;

    }

    for (auto i = 0; i < 8; ++i) {
      if(currentX+xDir[i]<m && currentX+xDir[i]>=0){
        if(currentY+yDir[i]<n && currentY+yDir[i]>=0){
          if(map[currentY+yDir[i]][currentX+xDir[i]]==0){
            map[currentY+yDir[i]][currentX+xDir[i]]=road+1;
            que.push_back(point{currentX+xDir[i],currentY+yDir[i]});
            if(currentX+xDir[i]==Finish.x && currentY+yDir[i]==Finish.y){
              found = true;
              cout<<road+1<<endl;;
              break;
            }
          }
        }
      }
    }
    que.pop_front();

  }

}
