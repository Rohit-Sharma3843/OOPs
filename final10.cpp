// 10.	Implement a class Quadratic that represents degree two polynomials i.e.,
// polynomials of type ax2+bx+c. The class will require three data members corresponding
//  to a, b and c. Implement the following operations:
// a)	A constructor (including a default constructor which creates the 0 polynomial).
// b)	Overloaded operator+ to add two polynomials of degree 2.
// c)	Overloaded << and >> to print and read polynomials. To do this, 
// you will need to decide what you want your input and output format to look like.
// d)	A function eval that computes the value of a polynomial for a given value of x.
// e)	A function that computes the two solutions of the equation ax2+bx+c=0.

#include<iostream>
#include<math.h>
using namespace std;
class Quadratic{
    int a,b,c;
    public:
    Quadratic(){
        this->a=a;
        this->b=b;
        this->c=c;
    }
    Quadratic(int a,int b,int c){
        this->a=a;
        this->b=b;
        this->c=c;
    }
    friend ostream &operator<<(ostream&out,Quadratic &q){
        cout<<"("<<q.a<<"x^2)+("<<q.b<<"x)+("<<q.c<<")"<<endl;
        return out;
    }
    friend istream&operator>>(istream &in,Quadratic &q){
        cout<<"Enter the cofficient of x^2 in quadratic polynomial : ";
        cin>>q.a;
        cout<<"Enter the cofficient of x^2 in quadratic polynomial : ";
        cin>>q.b;
        cout<<"Enter the constant term in quadratic polynomial : ";
        cin>>q.c;
        return in;
    }
    Quadratic operator+(Quadratic &q){
        Quadratic ans;
        ans.a=this->a+q.a;
        ans.b=this->b+q.b;
        ans.c=this->c+q.c;
        return ans;
    }
    int evaluate(int x){
        int ans=this->a*pow(x,2)+this->b*x+this->c;
        return ans;
    }
    void solutions(){
        float d=pow(this->b,2)-4*this->a*this->c;
        if(d<0){
            cout<<"No real solutions exist for this quadratic equation."<<endl;
        }
        else if(b==0){
            cout<<"Solution of quadratic equation is : "<<-(this->b)/(2*this->a)<<endl;
        }
        else{
            cout<<"Solutions of quadratic equation are : "<<(-this->b+sqrt(d))/(2*this->a)
            <<" "<<(-this->b-sqrt(d))/(2*this->a)<<endl;
        }
    }
};
int main(){
  Quadratic q1,q2,q3;
  cin>>q1;
  cin>>q2;
  q3=q1+q2;
  cout<<q1;
  cout<<q2;
  cout<<q3;
  int value;
  cout<<"Enter the value at which you want to evaluate the quadratic polynomial 1 : ";
  cin>>value;
  cout<<"Answer of evaluation is : "<<q1.evaluate(value)<<endl;
  q1.solutions();
  q2.solutions();
  q3.solutions();
  return 0;
}