// Write a function template selection Sort. Write a program that 
// inputs, sorts and outputs an integer array and a float array.
#include<iostream>
using namespace std;
template<class t>
void selection_sort(t *arr,int size){
    int min;
    for(int i=0;i<size;i++){
        min=i;
        for(int j=i;j<size;j++){
            if(arr[min]>arr[j]){
                min=j;
            }
        }
        swap(arr[min],arr[i]);
    }
}
template<class T>
void print(T *arr,int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
  int m,n;
  cout<<"Enter the size of the array you want to sort : ";
  cin>>m;
  int *arr=new int[m];
  for(int i=0;i<m;i++){
    cout<<"Enter the element "<<i+1<<" of the array : ";
    cin>>arr[i];
  }
  selection_sort(arr,m);
  cout<<"Sorted integer array is : ";
  print(arr,m);
  delete []arr;
  cout<<"Enter the size of the float array you want to sort : ";
  cin>>n;
  float *arr2=new float[n];
  for(int i=0;i<n;i++){
    cout<<"Enter the element "<<i+1<<" of the array you want to sort : ";
    cin>>arr2[i];
  }
  selection_sort(arr2,n);
  cout<<"The sorted array is : ";
  print(arr2,n);
  delete []arr2;
  return 0;
}