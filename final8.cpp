// Write C++ program using STL to add binary numbers (assume 
// one bit as one number); use STL stack.
#include<iostream>
#include<stack>
using namespace std;
string bool2str(bool b){
    if(b==1){
        return "1";
    }
    else if(b==0){
        return "0";
    }
}
int main(){
  stack<bool> num1;
  stack<bool> num2;
  int size1,size2;
  cout<<"Enter the number of bits in binary number 1 : ";
  cin>>size1;
  bool bit;
  for(int i=0;i<size1;i++){
    cout<<"Enter bit "<<i+1<<" : ";
    cin>>bit;
    num1.push(bit);
  }
  cout<<"Enter the number of bits in binary number 1 : ";
  cin>>size2;
  for(int i=0;i<size2;i++){
    cout<<"Enter bit "<<i+1<<" : ";
    cin>>bit;
    num2.push(bit);
  }
  stack<bool> num3;
  bool carry=0;
  while(!num1.empty()&&!num2.empty()){
    bool bit1=num1.top();
    bool bit2=num2.top();
    num1.pop();
    num2.pop();
    if(carry){
        if(bit1==0 && bit2==0){
            num3.push(1);
            carry=0;
        }
        else if((bit1==0 && bit2==1) ||(bit1==1 && bit2==0)){
            num3.push(0);
        }
        else if(bit1==1 && bit2==1){
            num3.push(1);
        }
    }
    else{
        if(bit1==0 && bit2==0){
            num3.push(0);
        }
        else if((bit1==0 && bit2==1) ||(bit1==1 && bit2==0)){
            num3.push(1);
        }
        else if(bit1==1 && bit2==1){
            num3.push(0);
            carry=1;
        }
    }
  }
  while(!num1.empty()){
    if(carry){
        if(num1.top()==1){
            num3.push(0);
        }
        else{
            num3.push(1);
            carry=0;
        }
    }
    else{
        num3.push(num1.top());
    }
    num1.pop();
  }
  while(!num2.empty()){
    if(carry){
        if(num2.top()==1){
            num3.push(0);
        }
        else{
            num3.push(1);
            carry=0;
        }
    }
    else{
        num3.push(num2.top());
    }
    num2.pop();
  }
  if(carry){
    num3.push(1);
  }
  string str;
  while(!num3.empty()){
    str+=bool2str(num3.top());
    num3.pop();
  }
  cout<<str<<endl;
  return 0;
}