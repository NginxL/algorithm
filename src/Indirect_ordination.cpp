#include <iostream>
#include <vector>

using namespace std;

void swap1(int* &a,int* &b)
{
    int* temp=a;
    a=b;
    b=temp;
}

int* medain(vector<int* >& a,int left,int right)
{
    int medain=(left+right)/2;
    if(*a[medain]< *a[left])
    {
        swap1(a[medain],a[left]);
    }
    if(*a[left]>*a[right])
    {
        swap1(a[left],a[right]);
    }
    if(*a[medain]>*a[right])
    {
        swap1(a[medain],a[right]);
    }
    swap1(a[medain],a[right-1]);
    return a[right-1];
}

void quicksort(vector<int* >& a,int left,int right)
{
    if(left<right)
    {
        int* pivot=medain(a,left,right);
        int i=left;
        int j=right-1;
        while(i<j)
        {
            while(*a[++i]<*pivot){}
            while(*a[--j]>*pivot){}
            if(i<j)
            {
                swap1(a[i],a[j]);
            }
        }
        if(j+1==i)
        {
            swap1(a[i],a[right-1]);
        }
        quicksort(a,left,i-1);
        quicksort(a,i+1,right);
    }
}

void quicksort(vector<int* >& v)
{
    quicksort(v,0,v.size()-1);
}

void largeObjectSort(vector<int>& v)
{
    vector<int* > a(v.size());
    for(int i=0;i!=v.size();i++)
    {
        a[0]=&v[0];
    }
    quicksort(a);

    for(int i=0;i!=v.size();i++)
    {
        if(a[i]!=&v[i])
        {
            int nextj;
            int temp=v[i];
            int j;
            for(j=i;a[j]!=&v[i];j=nextj)
            {
                nextj=a[j]-&v[0];
                v[j]=*a[j];
                a[j]=&v[j];
            }
            v[j]=temp;
            a[j]=&v[j];
        }
    }
}

void print(vector<int>& v)
{
    for(int i=0;i!=v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(int argc,char** argv)
{
    vector<int> v;
    int temp;
    for(int i=9;i!=0;i--)
    {
        v.push_back(i);
    }

    largeObjectSort(v);

    print(v);

    return 0;
}
