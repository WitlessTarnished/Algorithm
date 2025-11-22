#include<bits/stdc++.h>
using namespace std;

struct Job{
    string id;
    int profit;
    int deadline;
};



pair<vector<string>,int> jobSequencing(vector<Job> jobs){

    sort(jobs.begin(),jobs.end(),[](const Job &a, const Job &b) {
             return a.profit > b.profit;
         }); 

         int maxdead{};

         for(auto i : jobs){maxdead = max(maxdead,i.deadline);}

         int maxprofit{};

         vector<string> slot(maxdead,"");

           for(auto& i : jobs){

             for(int j = i.deadline-1; j >= 0; j--){

                if(slot[j] == ""){

                    slot[j]=i.id;
                    maxprofit += i.profit;
                    break;
                }
             }
           }
           return {slot,maxprofit};
}

int main() {

    vector<Job> jobs = {
        {"a", 100, 2},
        {"b", 19, 1},
        {"c", 27, 2},
        {"d", 25, 1},
        {"e", 15, 3}
    };

    auto result = jobSequencing(jobs);
    vector<string> seq = result.first;
    int profit = result.second;

    cout << "Job Sequence: ";
    for (auto &id : seq) cout << id << " ";
    cout << "\nTotal Profit: " << profit << "\n";

    return 0;
}
