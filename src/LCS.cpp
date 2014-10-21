#include <iostream>
#include <string>

using namespace std;

void LCS(string str1,string str2)
{
	int len1=str1.size();
	int len2=str2.size();

	int* temp=new int[len2+1];
	for(int i=0;i<len2;i++)
	{
		temp[i]=0;
	}
	int max_len=0;
	int pos;
	for(int i=0;i<len1;i++)
	{
		for(int j=len2;j>0;j--)
		{
			if(str1[i]==str2[j-1])
			{
				temp[j]=temp[j-1]+1;
				if(temp[j]>max_len)
				{
					max_len=temp[j];
					pos=j-1;
				}
			}
			else
			{
				temp[j]=0;
			}
		}
	}
	cout<<"LCS length is: "<<max_len<<endl;
	cout<<"LCS is: ";
	for(int i=pos-max_len+1,j=0;j!=max_len;j++,i++)
	{
		cout<<str2[i];
	}
	cout<<endl;
}

int main(int argc,char** argv)
{
	cout<<"please input str1 and str2:"<<endl;
	string str1,str2;
	while(cin>>str1>>str2)
	{
		LCS(str1,str2);
	}
	return 0;
}
