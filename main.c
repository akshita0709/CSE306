#include<stdio.h>
int i,T=0;
void swap(int *x,int *y)
{
 int z;
 z=*x;
 *x=*y;
 *y=z;  
}
//***************************function to calculate waiting time***************
void calcwt(int AT[],int WT[],int n)
{
	for(i=0;i<n;i++)
	{
		if (AT[i]>T)
		{
			WT[i]=-100;
		}
		else
		WT[i]=T-AT[i];
	}
}
//******************************************************************************
//*************************function to calculate priority***********************
void calcpriority(int BT[],int WT[],float pri[],int n)
{
	for(i=0;i<n;i++)
	{
		pri[i]=(1+WT[i])/BT[i];
	}	
}
int max(float pri[],int n)
{
	int p=pri[0],loc=0;
	for(i=1;i<n;i++)
	{
		if(pri[i]>p)
		{
			loc=i;
		}
	}
	return loc;
	
}
//**********************function to remove executed process**********************
void remoove(int ar[],int index,int n)
{
	for(i=index;i<n;i++)
	{
		ar[i]=ar[i+1];
	}
}
void remoovep(float ar[],int index,int n)
{
	for(i=index;i<n;i++)
	{
		ar[i]=ar[i+1];
	}
}
int main()
{
	int j,k,index,n;
	//*************************TAKING INFORMATION ABOUT PROCESSES****************
	printf("enter number of processes");
	scanf("%d",&n);
	int pno[n],BT[n],WT[n],AT[n];
	float pri[n];
	for(i=0;i<n;i++)
	{
		pno[i]=i+1;
	}
	for(i=0;i<n;i++)
	{
		printf("enter burst time for P%d ",i+1);
		scanf("%d",&BT[i]);
	}
	for(i=0;i<n;i++)
	{
		printf("enter arrival time for P%d ",i+1);
		scanf("%d",&AT[i]);
	}
	//*****************************************************************************
	//***************SCHEDULING SHORTEST JOB NEXT**********************************	
	for(i=0;i<n;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
        {
            if(AT[j]<AT[k])
                k=j;
        } 
        swap(&pno[i],&pno[k]);
        swap(&BT[i],&BT[k]);
	swap(&AT[i],&AT[k]);
    }
    for(i=0;i<n;i++)
	{	
	    printf("\nP %d bt %d",pno[i],BT[i]);		
	}
	T=AT[0];
	for(i=1;i<n;i++)
	{
		if(AT[i]<T)
		{
			T=AT[i];
		}
	}
	int n1=n;
	for(j=0;j<n;j++)
	{
		calcwt(AT,WT,n);
	    calcpriority(BT,WT,pri,n);
	    printf("\nP %d wt %d pri %f",pno[j],WT[j],pri[j]);	
	    index=max(pri,n);
    	printf("\nexecuting p%d ........",pno[index]);
    	T=T+BT[index];
	    remoove(pno,index,n);
	    remoove(BT,index,n);
	    remoove(WT,index,n);
	    remoovep(pri,index,n);
	    n=n-1;		
	}
	return 0;	
}
