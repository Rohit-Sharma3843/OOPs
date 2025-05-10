// Implement a class Complex which represents the Complex Number data 
// type. Implement the following 1. Constructor (including a 
// default constructor which creates the complex number 0+0i). 
// Overloaded operator+ to add two complex numbers.
// Overloaded operator* to multiply two complex numbers.
// Overloaded << and >> to print and read Complex Numbers.
#include<iostream>
using namespace std;
class Complex{
    int real,comp;
    public:
    Complex(){
        this->real=0;
        this->comp=0;
    }
    Complex(int real,int comp){
        this->real=real;
        this->comp=comp;
    }
    Complex operator+(Complex c){
        Complex ans;
        ans.real=this->real+c.real;
        ans.comp=this->comp+c.comp;
        return ans;
    }
    Complex operator*(Complex c){
        Complex ans;
        ans.real=this->real*c.real-this->comp*c.comp;
        ans.comp=this->real*c.comp+this->comp*c.real;
        return ans;
    }
    friend ostream &operator<<(ostream &out,Complex &c){
        if(c.comp>=0){
            cout<<c.real<<"+"<<c.comp<<"i"<<endl;
        }
        else{
            cout<<c.real<<c.comp<<"i"<<endl;
        }
        return out;
    }
    friend istream &operator>>(istream &in,Complex &c){
        cout<<"Enter the real and imaginary part of complex number : \n";
        cin>>c.real>>c.comp;
        return in;
    }
};
int main(){
  Complex c1,c2,c3,c4;
  cin>>c1>>c2;
  c3=c1+c2;
  c4=c1*c2;
  cout<<c3; 
  cout<<c4;
  return 0;
}