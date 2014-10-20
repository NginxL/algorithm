#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& a,vector<int>& tempArray,int leftstart,int rightstart,int rightend)
{
	int leftend=rightstart-1;
	int numElement=rightend-leftstart+1;
	int temppos=leftstart;
	while(leftstart<=leftend && rightstart<=rightend)
	{
		if(a[leftstart]<a[rightstart])
		{
			tempArray[temppos]=a[leftstart];
			leftstart++;
			temppos++;
		}
		else
		{
			tempArray[temppos]=a[rightstart];
			rightstart++;
			temppos++;
		}
	}
	while(leftstart<=leftend)
	{
		tempArray[temppos]=a[leftstart];
		temppos++;
		leftstart++;
	}
	while(rightstart<=rightend)
	{
		tempArray[temppos]=a[rightstart];
		temppos++;
		rightstart++;
	}
	for(int i=0;i!=numElement;i++)
	{
		a[rightend]=tempArray[rightend];
		rightend--;
	}
}

void mergeSort(vector<int>& a,vector<int>& tempArray,int left,int right)
{
	if(left<right)
	{
		int center=(left+right)/2;
		mergeSort(a,tempArray,left,center);
		mergeSort(a,tempArray,center+1,right);
		merge(a,tempArray,left,center+1,right);
	}
}

void mergeSort(vector<int>& a)
{
	vector<int> tempArray(a.size());
	mergeSort(a,tempArray,0,a.size()-1);
}

int main(int argc,char** argv)
{
	vector<int> a;
	int temp;
	while(cin>>temp)
	{
		a.push_back(temp);
	}
	mergeSort(a);
	for(int i=0;i!=a.size()-1;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<a[a.size()-1]<<endl;
	return 0;
}
