//Maximum Sub-Array - Comparison of brute-force method & divide & conquer methods
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<time.h>
#include<iomanip>

using namespace std;

long int count=0;

struct SubArray
{
	int low, high;
	double sum;
	
	SubArray()
	{}
	
	SubArray(int l, int h, double s)
	{
		low = l;
		high = h;
		sum = s;
	}
};

SubArray MaxCrossingSubArray(double *a,int low, int mid, int high)
{
	double leftSum, rightSum, Sum;
	int maxLeft, maxRight;

	leftSum = -99999;
	Sum = 0;
	
	for(int i=mid;i>=low;i--)
	{
		count++;
		Sum = Sum + a[i];
		if(Sum > leftSum)
		{
			leftSum = Sum;
			maxLeft = i;
		}
	}
	
	rightSum = -99999;
	Sum = 0;
	
	for(int i=mid+1;i<=high;i++)
	{
		count++;
		Sum = Sum + a[i];
		if(Sum > rightSum)
		{
			rightSum = Sum;
			maxRight = i;
		}
	}
	
	return SubArray(maxLeft,maxRight,leftSum+rightSum);
}

SubArray MaximumSubArrayDC(double *a, int low, int high)
{
	SubArray leftSubArray, rightSubArray, crossSubArray;
	
	
	if(low == high)
	{
		return SubArray(low,high,a[low]);
	}
	
	int mid;
	
	count++;
	mid = (low+high)/2;
	leftSubArray = MaximumSubArrayDC(a, low, mid);
	rightSubArray = MaximumSubArrayDC(a, mid+1, high);
	crossSubArray = MaxCrossingSubArray(a,low,mid,high);
	
	//Finding max between the three
	if(leftSubArray.sum>=rightSubArray.sum)
	{
		if(leftSubArray.sum>=crossSubArray.sum)
		{
			return leftSubArray;
		}
		else
		{
			return crossSubArray;
		}
	}
	else
	{
		if(rightSubArray.sum>=crossSubArray.sum)
		{
			return rightSubArray;
		}
		else
		{
			return crossSubArray;
		}
	}
	
	
	
}	
	
SubArray MaximumSubArrayBF(double *a, int low, int high)
{
	double maxSum,Sum;
	int left,right;
	
	maxSum = a[low];
	left = 0;
	right = 0;
	
	for(int i=low;i<=high;i++)
	{
		Sum = 0;
		for(int j=i;j<=high;j++)
		{
			count++;
			Sum = Sum + a[j];
			if(Sum>maxSum)
			{
				maxSum = Sum;
				left = i;
				right = j;
			}
		}
	}
	
	return SubArray(left,right,maxSum);
}

int main()
{
	cout<<showpoint<<setprecision(12);
	
	int n;
	double *a;

	cout<<"\nEnter n: ";
	cin>>n;
		
	a = new double[n];
	
	ofstream outf;
	ifstream inf;
	
	srand((long int)clock());
	
	//Loading numbers to input file
	outf.open("in.txt");
	for(int i=0;i<n;i++)
	{
		if(rand()%2==0)
			outf<<"\t"<<(rand()%(n*2))*-1;
		else
			outf<<"\t"<<rand()%(n*2);
	}
	outf.close();
	
	//Reading input in array from input file
		
	inf.open("in.txt");		
	for(int i=0;i<n;i++)
	{
		inf>>a[i];
	}
	inf.close();
	
	
	SubArray max;

	//Brute-Force Method
	count = 0;
	max = MaximumSubArrayBF(a,0,n-1);

	cout<<"\n\nBrute-Force Method: ";
	cout<<"\nMaximum Sub Array: ("<<max.low<<", "<<max.high<<", "<<max.sum<<")";
	cout<<"\nTotal Active Operations: "<<count;

	//Divide-and-Conquer Approach
	count = 0;
	max = MaximumSubArrayDC(a,0,n-1);
	
	cout<<"\n\nDivide-and-Conquer Approach: ";
	cout<<"\nMaximum Sub Array: ("<<max.low<<", "<<max.high<<", "<<max.sum<<")";
	cout<<"\nTotal Active Operations: "<<count;
	
}

