#include <iostream>
#include <vector>

using namespace std;

const int& medain(vector<int>& a,int left,int right)
{
	int medain=(left+right)/2;

	if(a[medain]<a[left])
	{
		swap(a[medain],a[left]);
	}
	if(a[right]<a[left])
	{
		swap(a[left],a[right]);
	}
	if(a[right]<a[medain])
	{
		swap(a[right],a[medain]);
	}

	swap(a[medain],a[right-1]);
	return a[right-1];
}

void quickSort(vector<int>& a,int left,int right)
{
	if(left<right)
	{
		int pivot=medain(a,left,right);
		int i=left;
		int j=right-1;
		while(i<j){
			while(a[++i]<pivot){}
			while(a[--j]>pivot){}
			if(i<j)
			{
				swap(a[i],a[j]);
			}
		}
		if(j+1==i)
		{
			swap(a[i],a[right-1]);
		}
		quickSort(a,left,i-1);
		quickSort(a,i+1,right);
	}
}

void quickSort(vector<int>& a)
{
	quickSort(a,0,a.size()-1);
}

int main(int argc,char** argv)
{
	vector<int> a;
	int temp;
	while(cin>>temp)
	{
		a.push_back(temp);
	}
	quickSort(a);
	for(int i=0;i!=a.size()-1;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<a[a.size()-1]<<endl;
	return 0;
}
