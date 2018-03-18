#include<iostream>
using namespace std;
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
int main()
{
	int j,k;
	//*************************TAKING INFORMATION ABOUT PROCESSES****************
	cout<<"enter number of processes";
	cin>>n;
	int pno[n],BT[n],WT[n],pri[n];
	for(i=0;i<n;i++)
	{
		pno[i]=i+1;
	}
	for(i=0;i<n;i++)
	{
		cout<<"enter burst time for P"<<i+1;
		cin>>BT[i];
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
		cout<<"\nP"<<pno[i]<<"bt="<<BT[i];		
	}
	calcwt(BT,WT,n);
	for(i=0;i<n;i++)
	{
		cout<<"\nwt"<<WT[i];		
	}
	
	return 0;	
}
