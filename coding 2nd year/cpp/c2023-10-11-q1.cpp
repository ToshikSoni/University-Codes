#include <iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> v={15,13,12,14,16,8,6,4,10,30};
    for(int i=0;i<v.size();i++)
    {
        int count=1;
        for(int j=i-1;j>=0;j--)
        {
            if(v[j]<=v[i])
                count++;
            else
                break;
        }
        cout<<count<<'\t';
    }
}   