#include<stdio.h>
int i,n;
void swap(int *x,int *y)
{
 int z;
 z=*x;
 *x=*y;
 *y=z;  
}
//***************************function to calculate waiting time***************
void calcwt(int BT[],int WT[],int n)
{
	WT[0]=0;
	for(i=0;i<n-1;i++)
	{
		WT[i+1]=BT[i]+WT[i];
	}
}
//******************************************************************************
//*************************function to calculate priority***********************
void calcpriority(int BT[],int WT[],int pri[],int n)
{
	for(i=0;i<n;i++)
	{
		pri[i]=(int)((WT[i]*10)/BT[i]);
	}	
}
//**********************function to remove executed process**********************
void remoove(int ar[])
{
	for(i=0;i<n;i++)
	{
		ar[i]=ar[i+1];
	}
}
int main()
{
	int j,k;
	//*************************TAKING INFORMATION ABOUT PROCESSES****************
	printf("enter number of processes");
	scanf("%d",&n);
	int pno[n],BT[n],WT[n],pri[n];
	for(i=0;i<n;i++)
	{
		pno[i]=i+1;
	}
	for(i=0;i<n;i++)
	{
		printf("enter burst time for P%d ",i+1);
		scanf("%d",&BT[i]);
	}
	//*****************************************************************************
	//***************SCHEDULING SHORTEST JOB NEXT**********************************	
	for(i=0;i<n;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
        {
            if(BT[j]<BT[k])
                k=j;
        } 
        swap(&pno[i],&pno[k]);
        swap(&BT[i],&BT[k]);
    }
    for(i=0;i<n;i++)
	{	
	    printf("\nP %d bt %d",pno[i],BT[i]);		
	}
	calcwt(BT,WT,n);
	for(i=0;i<n;i++)
	{
		printf("\nwt %d",WT[i]);		
	}
	printf("\nEXECUTING P%d ......................",pno[0]);	
	//*****************************************************************************
	while(n>0)
	{
	    remoove(pno);
	    remoove(BT);
	    remoove(WT);
	    remoove(pri);
	    n=n-1;
	    calcpriority(BT,WT,pri,n);	/////////////////////////////////////////////////////////////
	 for(i=0;i<n;i++)
	{
		printf("\nP%d priority=%d",pno[i],pri[i]);		
	}
	printf("\nEXECUTING P%d ......................",pno[0]);
    }	
	return 0;	
}
