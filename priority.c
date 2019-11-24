#include<stdio.h>
int sort(int a[],int b[],int c[],int n)
{
    int temp=0,temp1=0,temp2=0,i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                temp1=b[j];
                b[j]=b[j+1];
                b[j+1]=temp1;
                temp2=c[j];
                c[j]=c[j+1];
                c[j+1]=temp2;
            }
        }
    }
}
int main(){
    int n,i,p[20],bt[20],wt[20],tat[20],priority[20];
    float twt=0,ttat=0,awt,atat;
    printf("Enter the no: of processes:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        p[i]=i+1;
        printf("Enter the burst time of p[%d]:",i+1);
        scanf("%d",&bt[i]);
        printf("Enter priority");
        scanf("%d",&priority[i]);
    }
    sort(priority,bt,p,n);
    wt[0]=0;
    tat[0]=bt[0];
    for(i=1;i<n;i++)
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
    printf("\nProcess\tpriority\tBT\tWT\tTAT\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t%d\t\t%d\t%d\t%d\n",p[i],priority[i],bt[i],wt[i],tat[i]);
    }
    printf("avg WT=%0.2f",awt);
    printf("avg TAT=%0.2f",atat);
}
