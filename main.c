#include<stdio.h>
int i,T=0;//work as time flag
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
			WT[i]=-101;//process who have not arrived yet but data is 
		}                  //provided hence given negative priority so could not 
		else               //get a chance to run utill reach the arrival time 
		WT[i]=T-AT[i];
	}
}
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
	float p=pri[0];
	int loc=0;
	for(i=1;i<n;i++)
	{
		if(pri[i]>p)
		{
			p=pri[i];
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
void remoovep(float ar[],int index,int n)//for array of float type ie.priority
{
	for(i=index;i<n;i++)
	{
		ar[i]=ar[i+1];
	}
}
int main()
{
	int j,k,l,index,n;
	//*************************TAKING INFORMATION ABOUT PROCESSES****************
	printf("enter number of processes");
	scanf("%d",&n);
	int pno[n],BT[n],WT[n],AT[n],pro[n],Time[n];
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
	//***************Sorting according to arrival time**********************************	
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
	T=AT[0];
	for(i=1;i<n;i++)
	{
		if(AT[i]<T)
		{
			T=AT[i];
		}
	}
	if(T>0)
	{
	   for(k=0;k<T;k++)
    	    {
    		printf("\nTIME= %d",k);
    		sleep(1);
	    }
	}
	int n1=n;
	Time[0]=0;
	for(j=0;j<n1;j++)
	{
	    calcwt(AT,WT,n);
	    calcpriority(BT,WT,pri,n);	
	    index=max(pri,n);
    	    printf("\nexecuting p%d ........",pno[index]);
	    pro[j]=pno[index];
	    for(k=T;k<T+BT[index];k++)
    	       {
    		printf("\nTIME= %d",k);
    		sleep(1);
		}
	    printf("\nTIME= %d",T+BT[index]);
	    Time[j+1]=T+BT[index];
    	    T=T+BT[index];
	    remoove(pno,index,n);
	    remoove(BT,index,n);
	    remoove(WT,index,n);
	    remoovep(pri,index,n);
	    n=n-1;		
	}
	printf("\n");
        for(l=0;l<n1+1;l++)
         {
    	   for(k=0;k<(Time[l]-Time[l-1]);k++)
    	    {printf("--");}
    	   printf(" ");
        }  
	printf("\n");
	printf("|");
        for(l=1;l<n1+1;l++)
          {
    	    for(k=0;k<(Time[l]-Time[l-1])-1;k++)
    	      {printf(" ");}
    	    printf("P%d",pro[l-1]);
    	    for(k=0;k<(Time[l]-Time[l-1])-1;k++)
    	      {printf(" ");}
    	    printf("|");
          }
        printf("\n");
        for(l=0;l<n1+1;l++)
          {
    	    for(k=0;k<(Time[l]-Time[l-1]);k++)
    	      {printf("--");}
    	    printf(" ");
          }
       printf("\n");
       for(l=0;l<n1+1;l++)
         {
    	    for(k=0;k<(Time[l]-Time[l-1]);k++)
    	      {
		printf("  ");
	      }
	    printf("%d",Time[l]);
	    if(Time[l]>9)
	      {
		j=l;
		break;
	      }
	 }
       for(l=j+1;l<n1+1;l++)
         {
    	   for(k=0;k<(Time[l]-Time[l-1])-1;k++)
    	     {
		printf("  ");
	     }
	   printf("%d",Time[l]);
	}
       printf("\n");
       return 0;	
 }
