// Imagine a publishing company which does marketing
// for book and audio cassette versions. Create a class publication
// that stores the title (a string) and price (type float)
// of a publication. From this class derive two classes: book, which adds a page
// count (type int), and tape, which adds a playing time in minutes 
// (type float). Write a program that instantiates the book and tape class, allows user to 
// enter data and displays the data members. If an exception is caught, replace 
// all the data member values with zero values.
#include<iostream>
#include<typeinfo>
using namespace std;
class Publication{
    protected:
    string title;
    float price;
    public:
    Publication(){
        title="";
        price=0;
    }
};
class Book:public Publication{
    int page_count;
    public:
    Book(){
        title="";
        price=0;
        page_count=0;
    }
    Book(string title,float price,int page_count){
        this->title=title;
        this->price=price;
        this->page_count=page_count;
    }
    void display(){
        cout<<"Title : "<<this->title<<endl;
        cout<<"Price : "<<this->price<<endl;
        cout<<"Page Count : "<<this->page_count<<endl;
    }
};
class Tape:public Publication{
    float playing_time;
    public:
    Tape(){
        title="";
        price=0;
        playing_time=0;
    }
    Tape(string title,float price,float playing_time){
        this->title=title;
        this->price=price;
        this->playing_time=playing_time;
    }
    void display(){
        cout<<"Title : "<<this->title<<endl;
        cout<<"Price : "<<this->price<<endl;
        cout<<"Playing Time : "<<this->playing_time<<endl;        
    }
};
int main(){
  Book *b=new Book[10];
  Tape *t=new Tape[10];
  int choice,page,book_count=0,tape_count=0;
  float price,time;
  string name;
  while(1){
    cout<<"Enter your choice :\n1.Add book\n2.Add Tape\n3.Display books\n4.Display Tape\n";
    cout<<"5.Exit\n";
    cin>>choice;
    if(choice==1){
        
        try{
            cout<<"Enter the name of the book : ";
            cin>>name;
            cout<<"Enter the price of the book : ";
            cin>>price;
            cout<<"Enter the number of pages in the book ";
            cin>>page;
            if(price<0 && page<0){
                throw 1;
            }
        }
        catch(int a){
            name="";
            price=0;
            page=0;
        }
        b[book_count]=Book(name,price,page);
        book_count++;
    }
    else if(choice==2){
        try{
            cout<<"Enter the title of the tape : ";
            cin>>name;
            cout<<"Enter the price of the tape : ";
            cin>>price;
            cout<<"Enter the playing time of the tape : ";
            cin>>time;
            if(price<0 && page<0){
                throw 1;
            }
        }
        catch(int a){
            name="";
            price=0;
            time=0;
        }
        t[tape_count]=Tape(name,price,time);
        tape_count++;
    }
    else if(choice==3){
        for(int i=0;i<book_count;i++){
            cout<<"Details of book "<<i+1<<endl;
            b[i].display();
            cout<<endl;
        }
    }
    else if(choice==4){
        for(int i=0;i<tape_count;i++){
            cout<<"Deails of tape "<<i+1<<endl;
            t[i].display();
            cout<<endl;
        }
    }
    else{
        return 0;
    }
  }
  return 0;
}