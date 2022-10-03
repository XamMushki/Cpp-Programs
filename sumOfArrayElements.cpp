#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter Array Size: ";
    cin>>n;
    int arr[n];

    //initialize array
    cout<<"Enter array elements: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    //sum
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        sum +=arr[i];
    }
    cout<<"Sum = "<<sum<<endl;
}
