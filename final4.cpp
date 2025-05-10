// Write a C++ program that creates an output file, writes information 
// to it, closes the file and open it again as an input file and 
// read the information from the file.
#include<iostream>
#include<fstream>
using namespace std;
int main(){
  fstream final1;
  final1.open("final4.txt",ios::out);
  cout<<"Enter the content you want to write on the file or enter -1 to exit :\n";
  string s;
  while(1){
    getline(cin,s);
    if(s=="-1"){break;}
    final1<<s<<endl;
  }
  final1.close();
  fstream final2;
  final2.open("final4.txt",ios::in);
  cout<<"The contents of file are : "<<endl;
  char a[50];
  while(final2){
    final2.getline(a,50);
    cout<<a<<endl;
  }
  final2.close();
  return 0;
}