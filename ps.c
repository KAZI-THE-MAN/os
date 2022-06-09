#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
    //variable declare & initialize
    char pn[10][10],t[10];
    int art[10],et[10],pr[10],stt[10],wt[10],tat[10],ft[10];
    int totwt=0,tottat=0,i,j,num,temp;
    float awt=0,atat=0;
    //user input number of process
    printf("Enter the number of process: ");
    scanf("%d",&num);

    //user input using for loop
    for(i=0;i<num;i++)
    {
        printf("Enter the PName, Arrival Time, Execution Time & Priority; ");
        scanf("%s %d %d %d",pn[i],&art[i],&et[i],&pr[i]);
    }
    //Swapping using for loop
    for(i=0;i<num;i++)
    {
        for(j=0;j<num;j++)
        {
            if(pr[i]<pr[j])
            {
                //swapping priority
                temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;

                //swapping arrival Time
                temp = art[i];
                art[i] = art[j];
                art[j] = temp;

                //swapping execution Time
                temp = et[i];
                et[i] = et[j];
                et[j] = temp;

                //swapping PName
                strcpy(t,pn[i]);
                strcpy(pn[i],pn[j]);
                strcpy(pn[j],t);

            }
        }
    }
//loop using calculation
    for(i=0;i<num;i++)
    {
        if(i==0)
        {
            stt[i] = art[i];
            wt[i] = stt[i] - art[i];
            ft[i] = stt[i] + et[i];
            tat[i] = ft[i] - art[i];
        }
        else
        {
            stt[i] = ft[i-1];
            wt[i] = stt[i] - art[i];
            ft[i] = stt[i] + et[i];
            tat[i] = ft[i] - art[i];
        }
        //total calculation
        totwt += wt[i];
        tottat += tat[i];
    }
    //avarage waiting time & trun arround time
    awt = totwt/num;
    atat = tottat/num;

    printf("\nPName\tArrivalTime\tExecutionTime\tPriority\tWaitingTime\tTatTime\n");
    for(i=0;i<num;i++)
    {
        printf("\n%s\t%5d\t\t%5d\t\t%5d\t\t%5d\t\t%5d",pn[i],art[i],et[i],pr[i],wt[i],tat[i]);
    }
    printf("\nAvarge of Waiting Time: %f",awt);
    printf("\nAvarge Trun arround time: %f",atat);
    return 0;
}

