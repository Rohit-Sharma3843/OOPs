// Write C++program to count Letters, Words & Lines from the file.
// Write C++ program for calculation of file size.
#include<iostream>
#include<fstream>
using namespace std;
int main(){
  fstream file;
  file.open("final9.txt",ios::in);
  int words=0,letters=0,line=0;
  char c[100];
  while(file){
    file.getline(c,100);
    line+=1;
    string str=c;
    cout<<"line no "<<line<<endl;
    for(int i=0;i<str.length();i++){
        if(str[i]==' '){
      cout<<i<<" ";
            words++;
        }
        letters+=1;
    }
    words++;
  }
  cout<<"Lines : "<<line<<endl;
  cout<<"Words : "<<words<<endl;
  cout<<"Letters : "<<letters<<endl;
  return 0;
}