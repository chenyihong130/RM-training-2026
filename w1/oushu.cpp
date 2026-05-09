#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
void output(int len,int arr[])
{
    cout<<"数组元素：";
    for(int i=0;i<len;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int main()
{
    int arr[rand()%10+10];
    srand(time(0));
    int len = sizeof(arr)/sizeof(arr[0]);
    int sum=0,cnt=0;
    for(int i=0;i<len;i++)
    {
        arr[i] = rand()%100;
    }
    output(len,arr);
    for(int i=0;i<len;i++)
    {
        if(arr[i]%2==0)
        {
            sum += arr[i];
            cnt++;
        }
    }
    cout<<"偶数个数："<<cnt<<endl;
    cout<<"偶数总和："<<sum;
    return 0;
}
