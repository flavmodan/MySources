#include<iostream>
#include<fstream>
#include<deque>
#include<string>


using namespace std;

bool colors[]={1,1,1,0,0,0,0,0,0,0,0};
int red_num=2;
int black_num=3;

bool appears(deque<int> sol,int k){
  for (auto i = 0; i < sol.size(); ++i) {
    if(k==sol[i])
      return true;
  }
  return false;

}

void count(deque<int> sol,int &red,int &black){
  red=0;
  for (auto i = 0; i < sol.size(); ++i) {
    if(colors[sol[i]]){
      red++;
    }
  }
  black=0;
  for (auto i = 0; i < sol.size(); ++i) {
    if(!colors[sol[i]]){
      black++;
    }
  }

}
deque<int> s;
int num=0;

void bkt(){
  for (auto i = 0; i < 11; i++) {
    if(!appears(s,i)){
      s.push_back(i);
      int red,black;
      count(s,red,black);
      //cout<<red<<" "<<black<<endl;
      if(s.size()<=red_num+black_num && red<=red_num && black<=black_num){
        if(red==red_num && black==black_num){
          cout<<num<<" : ";
          for (auto j = 0; j < s.size(); ++j) {
            cout<<s[j]<<" -> "<<colors[s[j]]<<" | ";
          }
          cout<<endl;
          num++;

        }
        bkt();
      }
      s.pop_back();
    }
  }

}

int main(){
  bkt();
  cout<<num;
}
