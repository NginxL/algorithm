#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

bool isoperator(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':
        case '*':
        case '/':
            return true;
        default:
            return false;
    }
}

int priority(char ch)
{
    switch(ch)
    {
        case '#':
            return -1;
        case '(':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default :
            return -1;
    }
}

bool isnum(double d)
{
	if (d == '+' || d == '-' || d == '*' || d == '/')
	{
		return false;
	}
	return true;
}

vector<double> postfix(string s)
{
    vector<double> v;
    stack<char> st;
    st.push('#');
    for(int i=0;i!=s.size();i++)
    {
        if(s[i]=='(')
        {
            st.push(s[i]);
        }
        else if(s[i]>='0' && s[i]<='9')
        {
            double sum1=0;
            while(s[i]>='0' && s[i]<='9')
            {
                sum1=sum1*10+s[i]-'0';
                i++;
            }
            if(s[i]=='.')
            {
                i++;
            }
            else
            {
                v.push_back(sum1);
                i--;
                continue;
            }
            int k=0;
            while(s[i]>='0' && s[i]<='9')
            {
                sum1=sum1*10+s[i]-'0';
                i++;
                k++;
            }
            while(k>0)
            {
                sum1=sum1/10;
                k--;
            }
            v.push_back(sum1);
            i--;
        }
        else if(s[i]==')')
        {
            while(st.empty()!='#')
            {
                char ch=st.top();
                if(ch=='(')
                {
                    st.pop();
                    break;
                }
                else
                {
                    v.push_back(ch);
                    st.pop();
                }
            }
        }
        else
        {
            char ch1=s[i];
            int pri1=priority(ch1);
            while(st.empty()!='#')
            {
                char ch2=st.top();
                int pri2=priority(ch2);
                if(pri1<=pri2)
                {
                    v.push_back(ch2);
                    st.pop();
                }
                else
                {
                    st.push(ch1);
                    break;
                }
            }
        }
    }
    while(st.top()!='#')
    {
        v.push_back(st.top());
        st.pop();
    }
    return v;
}

double postfix_value(vector<double> v)
{
	stack<double> st;
	for (int i = 0; i != v.size(); i++)
	{
		if (isnum(v[i]))
		{
			double num = v[i];
			st.push(num);
		}
		else
		{
			double num2 = st.top();
			st.pop();
			double num1 = st.top();
			st.pop();
			char ch = (char)v[i];
			switch (ch)
			{
			case '+':
				st.push((num1 + num2));
				break;
			case '-':
				st.push((num1 - num2));
				break;
			case '*':
				st.push((num1*num2));
				break;
			case '/':
				st.push((num1 / num2));
				break;
			default:
				break;
			}
		}
	}
	return st.top();
}

int main(int argc,char** argv)
{
    string s;
    vector<double> v;
    cout<<"please input a nifix expression: ";
    while(cin>>s)
    {
        v=postfix(s);
        cout<<"The postfix expression is: ";
        for(int i=0;i!=v.size();i++)
        {
            if(isnum(v[i]))
            {
                cout<<v[i];
            }
            else
            {
                cout<<(char(v[i]));
            }
        }
        cout<<endl;
        cout<<"The postfix expression value is: "<<postfix_value(v)<<endl;

        cout<<"please input a nifix expression again: ";
    }
    return 0;
}
