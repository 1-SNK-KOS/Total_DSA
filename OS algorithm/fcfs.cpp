#include<bits/stdc++.h>
using namespace std;
bool compare(vector<int> &a, vector<int> &b){
    return (a[1]<b[1]);
}


void findtime(vector<vector<int>> &process){
 int time = 0;
 for(int i=0;i<process.size();i++){
    if(process[i][1] <= time){
         process[i][3] = time + process[i][2]; 
         process[i][5] = process[i][3] - process[i][1];
         process[i][4] = process[i][5] - process[i][2]; 
         time = process[i][3];
    }
    else{
     time = process[i][1]; 
    }
 }
}

int main()
{
    int n=0;
    cout<<"Enter no.of process : "<<endl;
    cin>>n;
vector<vector<int>>process(n,vector<int>(6,0)); // 0->processid 1->at 2->bt 3->ct 4->wt 5->tat

for(int i=0;i<n;i++){
    process[i][0] = i+1;
    cin>>process[i][1]>>process[i][2];
}
sort(process.begin(),process.end(),compare);

findtime(process);
int waiting_time = 0;
int tat_time = 0;
cout<<"ProcessId\t"<<"At\t\t"<<"BT\t\t"<<"CT\t\t"<<"WT\t\t"<<"TAT\t\t"<<endl;
for(int i=0;i<n;i++){
    waiting_time+=process[i][4];
    tat_time+=process[i][5];

    cout<<"p"<<process[i][0]<<"\t\t"<<process[i][1]<<"\t\t"<<process[i][2]<<"\t\t"<<process[i][3]<<"\t\t"<<process[i][4]<<"\t\t"<<process[i][5]<<endl;
}
cout<<"Average waiting time : "<<(float)waiting_time/n<<endl;
cout<<"Average tat time : "<<(float)tat_time/n<<endl;

cout<<"GANN CHART "<<endl<<"|";
for(int i=0;i<n;i++){
    cout<<"p"<<process[i][0]<<"|";
}
cout<<endl;
cout<<"0 ";
for(int i=0;i<n;i++){
    cout<<process[i][3]<<"  ";
}

return 0 ;
}