// Write C++ program using STL for sorting and searching user defined 
// records such as personal records (Name, DOB, Telephone number etc.) using 
// vector container. 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
template<typename t>
void print(vector<t> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

class one{
  public:
  int d1;
  int d2;
  one(int d1,int d2){
    this->d1=d1;
    this->d2=d2;
  }
};

bool comp(one a,one b){
  if (a.d1<b.d1) return true;
  if (a.d1>b.d1) return false;
  if (a.d2<b.d2) return true;
  if (a.d2>b.d2) return false;
  return true;
}

int main(){
  one o1(1,10);
  one o2(2,0);
  one o3(1,4);
  one o4(4,2);
  one o5(2,4);
  one o6(4,8);
  vector<one> v={o1,o2,o3,o4,o5,o6};
  sort(v.begin(),v.end(),comp);
  for (int i=0;i<v.size();i++){
    cout<<v[i].d1<<" "<<v[i].d2<<endl;
  }
  auto g=lower_bound(v.begin(),v.end(),o3,comp);
  bool b=(g!=v.end() && g->d2==o3.d2);
  cout<<g->d2<<endl;
  cout<<b<<endl;
  return 0;
}