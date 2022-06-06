//Radix Sort
#include<iostream>
#include<fstream>
#include<time.h>
#include<stdlib.h>
#include<iomanip>
#include<cmath>

using namespace std;

long int count=0;

//Extracting 'i'th digit from a number 'x'
int GetDigit(int x,int i)
{
	int d;
	x = x / pow(10,i-1);
	d = x % 10;
	return d;
}

//Stable sort
void CountingSort(int *a, int *b, int n, int k, int d)
{
	//n - size of a
	//k - counting sort property - maximum element value - here, 0 to 9
	//d - digit: sorting to be done on which digit(d)
	
	int *c;
	
	int s;
	
	c = new int[k+1];
	
	for(int i=0;i<=k;i++)
	{
		count++;
		c[i] = 0;
	}
	
	for(int i=1;i<=n;i++)
	{
		count++;
		s = GetDigit(a[i],d);
		c[s] += 1; 
	}
	for(int i=1;i<=k;i++)
	{
		count++;
		c[i] += c[i-1];
	}
	
	for(int i=n;i>=1;i--)
	{
		count++;
		s = GetDigit(a[i],d);
		b[c[s]] = a[i];
		c[s] -= 1;
	}
		
	delete(c);
}

void RadixSort(int *a, int n, int d)
{
	int *b;
	b = new int[n+1];
	
	for(int i=1;i<=d;i++)
	{
		CountingSort(a,b,n,9,i);
		for(int j=1;j<=n;j++)
			a[j] = b[j];
	}
	
	delete(b);
}

int main()
{
	cout<<showpoint<<setprecision(12);
	
	ofstream outf;
	ifstream inf;

	clock_t st,end;
	double etime;

	int n;
	int *a;
	
	cout<<"\nEnter n:";
	cin>>n;


//Counting the maximum number of digits. Max value is n-1
	int tmp=n-1,d=0;
	while(tmp!=0)
	{
		d++;
		tmp/=10;
	}
	
//Or we can read it from user
//	cout<<"\nEnter Maximum Number of Digits(d): ";
//	cin>>d;
 
	a = new int [n+1];


	srand((long int)clock());
	
	int k;
	//Loading numbers to input file
	outf.open("in.txt");
	for(int i=0;i<n;i++)
	{
		k=rand()%((int)pow(10,d));
		outf<<"\t"<<k;
	}
	outf.close();
	
	//Radix Sort
	
	//Reading input in array from input file
		
	inf.open("in.txt");		
	for(int i=1;i<=n;i++)
	{
		inf>>a[i];
	}
	inf.close();
	
	
	st = clock();
	
	count = 0;
	RadixSort(a,n,d);
	
	end = clock();
	
	etime = (double)(end-st)/CLOCKS_PER_SEC;

	//Writing sorted numbers to output file
	outf.open("RadixOut.txt");
	for(int i=1;i<=n;i++)
	{
		outf<<"\t"<<a[i];
	}
	outf.close();
	
	cout<<"\nRadix Sort:";
	cout<<"\nTotal Active Operations: "<<count;
	cout<<"\nExecution Time: "<<etime<<" Seconds\n";
	

	delete(a);

}

