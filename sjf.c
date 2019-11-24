#include<stdio.h>
int sort(int a[],int n)
{
    int temp=0,i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
int main(){
    int n,i,p[20],bt[20],wt[20],tat[20];
    float twt=0,ttat=0,awt,atat;
    printf("Enter the no: of processes:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        p[i]=i+1;
        printf("Enter the burst time of p[%d]:",i+1);
        scanf("%d",&bt[i]);
    }
    sort(bt,n);
    wt[0]=0;
    tat[0]=bt[0];
    for(i=0;i<n;i++)
    {
        wt[i]=tat[i-1];
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
