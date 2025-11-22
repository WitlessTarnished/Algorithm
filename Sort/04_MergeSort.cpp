#include<iostream>
using namespace std;

void merge(int* arr,int low, int mid,int high){
    int i= low,j= mid+1 ,k=0, temp[high-low+1];

    while (i <= mid and j<=high){
        if(arr[i]<arr[j]){
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
        }
    }
   while(i<= mid) temp[k++] = arr[i++];
   while(j<= high) temp[k++] = arr[j++];

   for(int l = low; l<=high;l++) arr[l]=temp[l-low];
}

void mergeSort(int* arr, int low, int high){
  int mid;
  if(low<high){
    mid = (low+high)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
  }
}

int main(){

    int arr[] {2,5,7,3,6,8,3};

   mergeSort(arr,0,6);

    for(auto x: arr){
        cout<<x<<" ";
    }

}