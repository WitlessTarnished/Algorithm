#include<iostream>
using namespace std;

void insertionSort(int* arr, int size){

    for(int i=1;i<size;i++){
        int j = i-1;
        int x = arr[i];

        while (j >=0 and arr[j]>x)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=x;
        
    }
}
int main(){

    int arr[] {2,5,7,3,6,8,3};

    insertionSort(arr,size(arr));

    for(auto x: arr){
        cout<<x<<" ";
    }

}