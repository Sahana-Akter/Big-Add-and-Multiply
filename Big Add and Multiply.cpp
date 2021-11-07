#include<bits/stdc++.h>
using namespace std;

string findSum(string str1, string str2)
{
    // jodi str2 is larger.
    if (str1.length() > str2.length())
        swap(str1, str2);

    // empty string for storing result
    string str;
    int n1 = str1.length(), n2 = str2.length();
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    int carry = 0;
    for (int i=0; i<n1; i++)
    {
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
    for (int i=n1; i<n2; i++)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
    if (carry)
        str.push_back(carry+'0');
    reverse(str.begin(), str.end());

    return str;
}
string multiplie(string a,int x)
{
    string mul_ans;
    int mul,carry=0;

    for(int i=a.size()-1; i>=0; i--)
    {
        mul=(x * (a[i]-'0'))+carry;
        mul_ans.push_back(mul%10 +'0');
        carry=mul/10;
    }

    if(carry>0) mul_ans.push_back(carry +'0');

    reverse( mul_ans.begin(), mul_ans.end());
    return  mul_ans;


}

int main()
{
    string str1,s,ans2;
    string str2 = "9999";
    cin>>str1;
    cout << findSum(str1, str2)<<endl;
   int x,k=1,f=0;

    for(int i=str2.size()-1; i>=0; i--)
    {
        x=str2[i]-'0';
        s=multiplie(str1,x);

        for(int j=1; j<k; j++)
        {
            s.push_back('0');
        }

        k++;

        ans2=  findSum(ans2,s);


    }
     cout<<ans2<<endl;

}

