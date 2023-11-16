#include<bits/stdc++.h>
using namespace std;
struct processes{
int id;
int at;
int bt;
int ct;
int tat;
int wt;

bool compare(processes a , processes b){
    return (a.at<b.at);
}
};


int main()
{
int n;
cout<<"Enter The no.of Process"<<endl;
cin>>n;

vector<processes>process(n);

cout<<"Enter the arrival time and burst time : "<<endl;
for(int i=0;i<n;i++){
    process[i].id = i+1;
    cin>>process[i].at>>process[i].bt;
}

sort(process.begin(),process.end(),compare);
vector<pair<int,int>>p(n);
for(int i=0;i<n;i++){
    p.push_back({process[i].id,i});
}


int current_time = 0;

vector<processes>readyqueue;
vector<processes>completion;
vector<int>order;
for(int i=0;i<n;i++){
    if(process[i].at == current_time){
          readyqueue.push_back(process[i]);
    }
    else{
        order.push_back(-1);
    }
}






return 0 ;
}