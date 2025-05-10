// Write a program in C++ to use map associative container. The keys will be the 
// names of states, and the values will be the Covid19 Patient Count of the states. 
// When the program runs, the user is prompted to type the name of a state. The 
// program then looks in the map, using the state name as an index, and 
// returns the patients of the state.#include<iostream>
#include<iostream>
#include<map>
using namespace std;
int main(){
  map<string,long long int> m;
  int states;
  string name;
  long long int patients;
  cout<<"Enter the total number of states : ";
  cin>>states;
  for(int i=0;i<states;i++){
    cout<<"Enter the name of state "<<i+1<<" : \n";
    cin>>name;
    cout<<"Enter the patients of "<<name<<"\n";
    cin>>patients;
    m.insert(pair<string,long long int>(name,patients));
  }
  map<string,long long int>::iterator i;
  for(i=m.begin();i!=m.end();i++){
    cout<<"State : "<<(*i).first<<" Patients : "<<(*i).second<<endl;
  }
  string s;
  while(1){
    cout<<"Enter the state whose population you want to know or enter -1 to exit: ";
    cin>>s;
    if(s=="-1"){
        break;
    }
    i=m.begin();
    while(i!=m.end() && (*i).first!=s){
        i++;
    }
    cout<<"The population of "<<s<<" is : "<<(*i).second<<endl;
  }
  return 0;
}