#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "请输入一个整数：";
    cin >> num; 
    if (num > 0)
    {
        cout << "这是正数" << endl;
    }
    else if (num < 0)
    {
        cout << "这是负数" << endl;
    }
    else
    {
        cout << "数字为0" << endl;
    }

    return 0;
}
