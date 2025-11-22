#include<iostream>
using namespace std;

void selectionSort(int *arr, int size)
{
    int i, j, k;
    for (i = 0; i <= size - 1; i++)
    {
        for (j = k = i; j < size; j++)
        {
            if (arr[j] < arr[k])  k = j;
              
        }
        swap(arr[i], arr[k]);
    }                       
}

int main(){

    int arr[] {2,5,7,3,6,8,3};

    selectionSort(arr,size(arr));

    for(auto x: arr){
        cout<<x<<" ";
    }

}