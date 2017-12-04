#include<iostream>
#include<deque>
#include<math.h>

using namespace std;

int tr=9;
deque<int> primes;

bool prime(int n){
  if(n==2)
    return true;
  if(n%2==0)
    return false;
  if(n==3)
    return true;
  if(n%3==0)
    return false;
  for(int d=5;d<=int(sqrt(n));d+=2){
    if(n%d==0)
      return false;
  }
  return true;
}

void makePrimes(){
  for(int i=2;i<=tr;i++){
    if(prime(i)){
      primes.push_back(i);
    }
  }
}

int makeSum(deque<int> n){
  int sum=0;
  for(int i=0;i<n.size();i++){
    sum+=n[i];
  }
  return sum;
}
deque<int> sol;
void bkt(){
  for(int i=primes.size()-1;i>=0;i--){
    sol.push_back(primes[i]);
    if(makeSum(sol)<=tr){
      if(makeSum(sol)==tr){
        for(int j=0;j<sol.size();j++){
          cout<<sol[j]<<" ";
        }
        cout<<endl;
      }
      bkt();
    }
    sol.pop_back();
  }
}

int main(){
  makePrimes();
  bkt();
}
