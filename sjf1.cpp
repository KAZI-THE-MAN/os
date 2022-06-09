#include <cstring>
#include<iostream>
using namespace std;

int main(){

    int et[20],at[10],n,i,j,temp,st[10],ft[10],wt[10],ta[10];
    int totwt=0,totta=0;
    float awt,ata;
    char pn[10][10],t[10];

    cout<<"Enter the number of processes:";
    cin>>n;


    for(i=0; i<n; i++){
        cout<<"Enter process name, arrival time & execution time:";
        cin>>pn[i]>>at[i]>>et[i];
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(et[i]<et[j]){
                temp=at[i];
                at[i]=at[j];
                at[j]=temp;
                temp=et[i];
                et[i]=et[j];
                et[j]=temp;
                strcpy(t,pn[i]);
                strcpy(pn[i],pn[j]);
                strcpy(pn[j],t);
            }
        }
    }
    for(i=0;i<n;i++){
        if(i==0)
            st[i]=at[i];
        else
            st[i]=ft[i-1];
        wt[i]=st[i]-at[i];
        ft[i]=st[i]+et[i];
        ta[i]=ft[i]-at[i];
        totwt+=wt[i];
        totta+=ta[i];
    }
    awt=(float)totwt/n;
    ata=(float)totta/n;

    cout<<"Pname\tarrivaltime\texecutiontime\twaitingtime\t\ttatime"<<endl;
    for(i=0; i<n; i++){
        cout<<pn[i]<<"\t\t"<<at[i]<<"\t\t"<<et[i]<<"\t\t"<<wt[i]<<"\t\t"<<ta[i]<<"\n";
    }

   cout<<"Average waiting time is:"<< awt<<endl;
   cout<<"Average turnaround time is:"<< ata;



return 0;
}
