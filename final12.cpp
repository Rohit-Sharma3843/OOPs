// Write a Menu Driven program for File Encryption & Decryption. Your 
// program should work like a filter, reading the contents of one file, 
// modifying the data into a code, and then writing the coded contents out to 
// a second file. The second file will be a version of the first file, but 
// written in a secret code & vice-versa.
#include<iostream>
#include<fstream>
using namespace std;
int main(){
  fstream file1,file2,file3;
  file1.open("final12_in.txt",ios::in);
  file2.open("final12_out.txt",ios::out);
  char c[50];
  string s;
  
  while(file1){
    file1.getline(c,50);
    s=c;
    for(int i=0;i<s.length();i++){
        char encrypt=s[i]-1;
        file2<<encrypt;
    }
  }
  file1.close();
  file2.close();
  file3.open("final12_out.txt",ios::in);
  while(file3){
    file3.getline(c,50);
    s=c;
    for(int i=0;i<s.length();i++){
        cout<<(char)(s[i]+1);
    }
  }
  file3.close();
  return 0;
}