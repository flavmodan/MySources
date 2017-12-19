#include <iostream>
using namespace std;

long long int fact[1000],invfact[1000];

int p;

void makeFact(int n){
  fact[0]=1;
  for (auto i = 1; i <=n; ++i) {
    fact[i]=i*fact[i-1];
  }
}

int power(int base ,int exponenet){
  if(exponenet==0)
    return 1;
  if(exponenet%2==1){
    return base*power(base,exponenet-1);
  }else{
    int pow=power(base,exponenet/2);
    return pow*pow;
  }
}

void makeInvFact(){
  invfact[p-1]=power(fact[p-1],p-2);
  for (auto i = p-2; i >= 0; i--) {
    invfact[i]=1/invfact[i+1]*(i+1)%p;
  }

}

int comb(int n,int  m){

}
