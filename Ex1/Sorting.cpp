#include<iostream>
#include<fstream>
#include<time.h>
#include<stdlib.h>
#include<iomanip>
using namespace std;

long int count=0;

void InsertionSort(int *a,int n)
{
	int i,j,key;
	for(j=1;j<=n-1;j++)
	{
		i = j-1;
		key = a[j];
		
		while(i>=0 && a[i]>key)
		{
			count++;
			a[i+1] = a[i];
			i = i-1;		
		}
		count++;
				
		a[i+1] = key;
	}
}

void Merge(int a[], int p, int q, int r)
{
	int n1,n2;

	n1 = q-p+1;
	n2 = r-q;
	
	int *L, *R;
	
	L = new int[n1+1];
	R = new int[n2+1];
	
	for(int i=0,j=0,k=p;k<=r;k++)
	{
		count++;
		if(k<=q)
		{
			L[i] = a[k];
			i++;			
		}
		else
		{
			R[j] = a[k];
			j++;
		}
	}
	
	L[n1] = 99999;
	R[n2] = 99999;
	
	for(int i=0,j=0,k=p;k<=r;k++)
	{
		count++;
		if(L[i]<R[j])
		{
			a[k] = L[i];
			i++;			
		}
		else
		{
			a[k] = R[j];
			j++;
		}
	}
	
	delete(L);
	delete(R);
}

void MergeSort(int a[], int p, int r)
{
	if(p>=r)
		return;
	int m;
	m = (p+r)/2;
	count++;
	MergeSort(a,p,m);
	MergeSort(a,m+1,r);
	Merge(a,p,m,r);
}

int main()
{
	
	ofstream outf;
	ifstream inf;

	clock_t st,end;
	double etime;

	int n;
	int *a;
	
	cout<<"\nEnter n:";
	cin>>n;
	
	a = new int [n];


	srand((long int)clock());
	
	//Loading numbers to input file
	outf.open("in.txt");
	for(int i=0;i<n;i++)
	{
		outf<<"\t"<<rand()%n;
	}
	outf.close();
	
	//Insertion Sort
	
	//Reading input in array from input file
		
	inf.open("in.txt");		
	for(int i=0;i<n;i++)
	{
		inf>>a[i];
	}
	inf.close();
	
	
	
	/*	cout<<"\nBefore Sorting: \n";
	for(int i=0;i<n;i++)
	{
		cout<<"\t"<<a[i];
	}
*/

	
	st = clock();
	
	count = 0;
	InsertionSort(a,n);
	
	end = clock();
	
	etime = (double)(end-st)/CLOCKS_PER_SEC;

/*	cout<<"\n\nAfter Sorting: \n";
	for(int i=0;i<n;i++)
	{
		cout<<"\t"<<a[i];
	}
*/

	//Writing sorted numbers to output file
	outf.open("InsertOut.txt");
	for(int i=0;i<n;i++)
	{
		outf<<"\t"<<a[i];
	}
	outf.close();
	
	cout<<"\n\nInsertion Sort:";
	cout<<"\nTotal Active Operations: "<<count;
	cout<<"\nExecution Time: "<<showpoint<<setprecision(8)<<etime<<" Seconds\n";
	

	//Merge Sort
	
	//Reading input in array from input file
		
	inf.open("in.txt");		
	for(int i=0;i<n;i++)
	{
		inf>>a[i];
	}
	inf.close();
	
	
	
	/*	cout<<"\nBefore Sorting: \n";
	for(int i=0;i<n;i++)
	{
		cout<<"\t"<<a[i];
	}
*/

	
	st = clock();
	
	count=0;
	MergeSort(a,0,n-1);
	
	end = clock();
	
	etime = (double)(end-st)/CLOCKS_PER_SEC;

/*	cout<<"\n\nAfter Sorting: \n";
	for(int i=0;i<n;i++)
	{
		cout<<"\t"<<a[i];
	}
*/

	//Writing sorted numbers to output file
	outf.open("MergeOut.txt");
	for(int i=0;i<n;i++)
	{
		outf<<"\t"<<a[i];
	}
	outf.close();
	
	cout<<"\n\nMerge Sort:";
	cout<<"\nTotal Active Operations: "<<count;
	cout<<"\nExecution Time: "<<showpoint<<setprecision(8)<<etime<<" Seconds\n";
	
	
	
	delete(a);
}

