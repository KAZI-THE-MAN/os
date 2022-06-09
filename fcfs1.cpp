#include <cstring>
#include<iostream>
using namespace std;

int main(){

    char pn[10][10],t[10];
    int arr[10],bur[10],star[10],finish[10],tat[10],wt[10],i,j,n,temp;
    int totwt=0,tottat=0;
    float awt,ata;
//clrscr();
    cout<<"Enter the number of processes:";
    cin>>n;

    for(i=0; i<n; i++){
        cout<<"Enter the Process Name, Arrival Time & Burst Time: ";
        cin>>pn[i]>>arr[i]>>bur[i];
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(arr[i]<arr[j]){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            temp=bur[i];
            bur[i]=bur[j];
            bur[j]=temp;
            strcpy(t,pn[i]);
            strcpy(pn[i],pn[j]);
            strcpy(pn[j],t);
            }
        }
    }
    for(i=0;i<n;i++){
        if(i==0)
            star[i]=arr[i];
        else
            star[i]=finish[i-1];
        wt[i]=star[i]-arr[i];
        finish[i]=star[i]+bur[i];
        tat[i]=finish[i]-arr[i];
    }



    cout<<"\nPName   Arrtime    Burtime  WaitTime    Start   TAT    Finish"<<endl;
    for(i=0; i<n; i++){
        cout<<pn[i]<<"\t"<<arr[i]<<"\t\t"<<bur[i]<<"\t"<<wt[i]<<"\t"<<star[i]<<"\t"<<tat[i]<<"\t"<<finish[i]<<"\n";
        totwt+=wt[i];
        tottat+=tat[i];
    }
    awt=(float)totwt/n;
    ata=(float)tottat/n;

   cout<<"Average waiting time is:"<< awt<<endl;
   cout<<"Average turnaround time is:"<< ata;



    return 0;
}
