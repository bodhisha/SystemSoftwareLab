#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,i,p[20],bt[20],wt[20],tat[20],bt_rem[20],t=0;
    float twt=0,ttat=0,awt,atat;
    printf("Enter the no: of processes:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        p[i]=i+1;
        printf("Enter the burst time of p[%d]:",i+1);
        scanf("%d",&bt[i]);
    }
    for (i=0;i<n;i++)
    {
        bt_rem[i]=bt[i];
        wt[i]=0;
    }
    while(1)
    {
        int done=1;
        for(i=0;i<n;i++)
        {
            if(bt_rem[i]>0)
            {
                done=0;
                if(bt_rem[i]>2)
                {
                    t=t+2;
                    bt_rem[i]=bt_rem[i]-2;
                }
                else
                {
                    t=t+bt_rem[i];
                    wt[i]=t-bt[i];
                    bt_rem[i]=0;
                }
                
            }
        }
        if(done==1)
            break;
    }
    
    for(i=0;i<n;i++)
    {
        tat[i]=wt[i]+bt[i];
    }
    for(i=0;i<n;i++)
    {
        twt=twt+wt[i];
        ttat=ttat+tat[i];
    }
    atat=ttat/n;
    awt=twt/n;
    printf("\nProcess\tBT\tWT\tTAT\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\n",p[i],bt[i],wt[i],tat[i]);
    }
    printf("avg WT=%0.2f",awt);
    printf("avg TAT=%0.2f",atat);
}
