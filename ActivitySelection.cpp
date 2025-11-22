#include<bits/stdc++.h> 
using namespace std;

struct Activity{
    string id;
    int start;
    int finish;
};


void activitySelection(vector<Activity> activities){

    sort(activities.begin(), activities.end(), [](const Activity &a, const Activity &b)
         { return a.finish < b.finish; });

         vector<string> act(activities.size(),"");

         act.push_back(activities[0].id);
         int count = 1;
         int last_finish = activities[0].finish;

         for(int i = 1; i<activities.size();i++){
            if(activities[i].start >= last_finish){
                act.push_back(activities[i].id);
                last_finish = activities[i].finish;
                count++;
            }
         }
   for(auto& i : act){
    if(i != "") cout<<i<<" ";
   }
   cout<<endl;
   cout<<"Number of task: "<<count<<endl;
}

int main(){
    vector<Activity> activities{
        {"a", 1 , 4},
        {"b", 3 , 5},
        {"c", 0 , 6},
        {"d", 5 , 7},
        {"e", 8 , 9}
    };

    activitySelection(activities);
    
}

