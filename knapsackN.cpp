#include<bits/stdc++.h> 
using namespace std;

struct Item{
    double value, weight;
};

double knapsack(double& W, vector<Item>& items){

    sort(items.begin(),items.end(),[](Item x1, Item x2){
         double n1 = x1.value/x1.weight;
         double n2 = x2.value/x2.weight;
         return n1>n2;
    });

   double maxvalue{};

    for(auto& item: items){
        if(W == 0) break;

        if(item.weight <= W){
        maxvalue += item.value;
        W -= item.weight;
        }
        else{
            double fraction = W/item.weight;
            maxvalue += fraction * item.value;
            W = 0; 
        }
    }

    return maxvalue;
}   


int main(){
    double n, W;
    cout << "Enter number of items: ";
    cin >> n;
    
    vector<Item> items(n);

    cout << "Enter values and weights:\n";

    for(int i = 0; i<n ; i++){
        cin>>items[i].value>>items[i].weight;
    }

     cout << "Enter capacity of knapsack: ";
    cin >> W;

     cout << "Maximum value in Knapsack = " <<knapsack(W,items);
}