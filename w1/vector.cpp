#include<iostream>
#include<vector>
using namespace std ;
int main ()
{
    vector <int> v ;
    for (int i=0;i<10;i++)
    {
        v.push_back(i+1);
    }
    for (vector<int>::iterator it=v.begin();it!=v.end();++it)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    for(int j=0;j<size(v);j++)
    {
        if(v[j]%2==0)
        {
            v.erase(v.begin()+j);
        }
    }
    for (vector<int>::iterator it=v.begin();it!=v.end();++it)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    cout<<"Size of vector is "<<size(v)<<endl;
    return 0;
}