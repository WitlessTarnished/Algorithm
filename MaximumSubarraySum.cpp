#include<iostream>
#include<vector>
using namespace std;

int maxSubarraySum(vector<int> &arr){
    int res = arr[0];

    for (int i = 0; i < arr.size(); i++)
    {
        int currentSum = 0;

        for ( int j = i; j < arr.size(); j++)
        {
            currentSum += arr[j];
             res = max(res,currentSum);
        }
       
    }
    return res;
   
}
int main(){
    vector<int> arr{2, 3, -8, 7, -1, 2, 3};
    cout<<maxSubarraySum(arr);
}