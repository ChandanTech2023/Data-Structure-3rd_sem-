/*Author -> Chandan KUmar
Program for Array sorting using  Merge Sort 
*/
#include<iostream>
using namespace std;
void array(int arr[],int n){
    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }
}
void merge(int *arr,int s ,int e){
    int mid =(s+e)/2;
    int leng1=mid-s+1;
    int leng2=e-mid;
    //  after dividing create two array 
     int*first=new int[leng1];
     int*second=new int [leng2];
    //  Copy both  array value
    int k= s;   //Here k is mainArrayIndex
    for (int i = 0; i <=leng1; i++){
         first[i]=arr[k++];
    
    }
        k= mid+1;
    for (int i = 0; i <=leng2; i++){
         second[i]=arr[k++];
    
    }
    // Merge two sorted array 
    int index1=0;
    int index2=0;
    k=s;
    while (index1<leng1 && index2<leng2){
        if(first[index1]<second[index2]){
            arr[k++]=first[index1++];
        }
        else{
         arr[k++]=second[index2++];
        }
    }
    while (index1<leng1)
    {arr[k++]=first[index1++];
     
    }
    while (index2<leng2)
    { arr[k++]=second[index2++];

    }
    //Free  dynamc allacoted  memory 
    delete[]first;
    delete []second;
}

void mergesort(int *arr ,int s, int e ){
    // base case 
    if(s>=e){
        return;
    }
      int mid=(s+e)/2;
    //   Left part sort 
       mergesort(arr,s ,mid);
    //    Right part sort 
       mergesort(arr,mid+1,e);

    //    Merge both 
       merge(arr,s,e);

}
void display(int arr[],int n){
    for (int i = 0; i <n; i++)
    {
        cout<<arr[i]<<" ";
    }
}


int main(){
 int n;
 int*arr;
cout<<"Enter the size of array:"<<endl;
cin>>n;
arr=new int[n];
cout<<"Enter array element :";
array(arr,n);
cout<<"Display array is:";
display(arr,n);
cout<<endl;
cout<<"Sorted Array is:"<<endl;
mergesort(arr ,0,n-1);
 display(arr,n);
 return 0;
}

