#include<iostream>
using namespace std;
 
int partition(int* arr, int low, int high){
    int pivot = arr[high];
    int i = low-1;

    for(int j = low ; j<high; j++){
        if(arr[j] < pivot){
            swap(arr[++i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
   return i+1;
}
void quickSort(int* arr, int low, int high){
       if (low < high){
        int p = partition(arr,low,high);
        quickSort(arr,low,p-1);
        quickSort(arr,p+1,high);
       }
}

int main(){

    int arr[] {2,5,7,3,6,8,3};

    quickSort(arr,0,size(arr)-1);

    for(auto x: arr){
        cout<<x<<" ";
    }

}