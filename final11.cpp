// Write C++ Program with base class convert declares two variables, 
// val1 and val2, which hold the initial and converted values, respectively. 
// It also defines the functions getinit () & getconv (), which return the 
// initial value and the converted value. These elements of convert are fixed 
// and applicable to all derived classes that will inherit convert. However, the 
// function that will actually perform the conversion, compute (), is a pure 
// virtual function that must be defined by the classes derived from convert. The 
// specific nature of compute () will be determined by what type of conversion 
// is taking place. (Hint: Pure Virtual Function)
#include<iostream>
using namespace std;
class convert{
    protected:
    int val1,val2;
    public:
    virtual void compute()=0;
    virtual void display()=0;
};
class temperature:public convert{
    public:
    temperature(){
        val1=0;
        val2=0;
    }
    temperature(int val1){
        this->val1=val1;
    }
    int getinit(){
        return val1;
    }
    int getconv(){
        return val2;
    }
    void compute(){
        val2=this->val1+273;
    }
    void display(){
        cout<<"The temperature "<<this->val1<<"C in kelvin is : "<<this->val2<<"K"<<endl;
    }
};
class dist:public convert{
    public:
    dist(){
        this->val1=0;
        this->val2=0;
    }
    dist(int val1){
        this->val1=val1;
    }
    int getinit(){
        return val1;
    }
    int getconv(){
        return val2;
    }
    void compute(){
        val2=1600*val1;
    }
    void display(){
        cout<<"The distance "<<this->val1<<" miles in metres is : "<<this->val2<<"m."<<endl;
    }
};
class data:public convert{
    public:
    data(){
        this->val1=0;
        this->val2=0;
    }
    data(int val1){
        this->val1=val1;
    }
    int getinit(){
        return val1;
    }
    int getconv(){
        return val2;
    }
    void compute(){
        val2=val1*1024;
    }
    void display(){
        cout<<this->val1<<"MB is equal to "<<this->val2<<" KB"<<endl;
    }
};
int main(){
  temperature t1(10);
  t1.compute();
  t1.display();
  data d(10);
  d.compute();
  d.display();
  dist d1(12);
  d1.compute();
  d1.display();
  return 0;
}