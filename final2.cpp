// Develop an object-oriented program in C++ to create a 
// database of student information system containing the following 
// information: Name, Roll number, Class, division, Date of Birth, 
// Blood group, Contact address, telephone number, driving license no. and 
// other. Construct the database with suitable member functions for initializing 
// and destroying the data viz constructor, default constructor, copy 
// constructor, destructor, static member functions, friend class, this 
// pointer, inline code and dynamic memory allocation operators-new and delete.
#include<iostream>
#include<iomanip>
using namespace std;
class fr;
class student{
    static int count;
    friend class fr;
    string name;
    int roll;
    string clas;
    char division;
    string dob;
    string blood_gp;
    string address;
    string telephone;
    string driving;
    public:
    student(){
        this->name="";
        this->roll=0;
        this->clas="";
        this->division='n';
        this->dob="";
        this->blood_gp="";
        this->address="";
        this->telephone="";
        this->driving="";
        count+=1;
    }
    student(string name,int roll,string clas,char division,string dob,string glood_gp,
    string address,string telephone,string driving){
        this->name=name;
        this->roll=roll;
        this->clas=clas;
        this->division=division;
        this->dob=dob;
        this->blood_gp=blood_gp;
        this->address=address;
        this->telephone=telephone;
        this->driving=driving;
    }
    student(student &s){
        this->name=s.name;
        this->roll=s.roll;
        this->clas=s.clas;
        this->division=s.division;
        this->dob=s.dob;
        this->blood_gp=s.blood_gp;
        this->address=s.address;
        this->telephone=s.telephone;
        this->driving=s.driving;
    }
    ~student(){
        count--;
    }
    static int get_count(){
        return count;
    }
};
int student::count=0;
class fr{
    public:
    void display(student s){
        cout<<"Name : "<<s.name<<endl;
        cout<<"Roll : "<<s.roll<<endl;
        cout<<"Class : "<<s.clas<<endl;
        cout<<"Division : "<<s.division<<endl;
        cout<<"Date of birth : "<<s.dob<<endl;
        cout<<"Blood Group : "<<s.blood_gp<<endl;
        cout<<"Address : "<<s.address<<endl;
        cout<<"Telephone : "<<s.telephone<<endl;
        cout<<"Driving license no. : "<<s.driving<<endl;
    }
};
int main(){
  student*s=new student[10];
  int choice;
  fr f;
  string blood_gp,name,clas,dob,address,driving;
  string telephone;
  int roll,entries=0;
  char division;
  while(true){
    cout<<"Enter your choice : \n1.Enter Student\n2.Display Last Student\n";
    cout<<"3.Display Database\n4.Exit\n";
    cin>>choice;
    if(choice==1){
        cout<<"Enter the name of student : ";
        cin>>name;
        cout<<"Enter the roll number : ";
        cin>>roll;
        cout<<"Enter the class of the student : ";
        cin>>clas;
        cout<<"Enter the division : ";
        cin>>division;
        cout<<"Enter the date of birth of student : ";
        cin>>dob;
        cout<<"Enter the blood group : ";
        cin>>blood_gp;
        cout<<"Enter the address of the student : ";
        cin>>address;
        cout<<"Enter the telephone number : ";
        cin>>telephone;
        cout<<"Enter the driving license number : ";
        cin>>driving;
        s[entries]=student(name,roll,clas,division,dob,blood_gp,address,telephone,driving);
        entries+=1;
    }
    else if(choice==2){
        cout<<setw(10)<<"Details of last student : \n";
        f.display(s[entries-1]);
    }
    else if(choice==3){
        for(int j=0;j<entries;j++){
            cout<<endl<<endl;
            cout<<setw(10)<<"Details of student "<<j+1<<" : \n";
            f.display(s[j]);
            cout<<endl;
        }
    }
    else{
        delete []s;
        return 0;
    }
  }
  return 0;
}