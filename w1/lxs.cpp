#include<stdio.h>
struct lx
{
    char name[50];
    int age;
    char level;
};
int main()
{
    struct lx a[]=
    {
        {"张三",18,'C'},
        {"李四",20,'B'},
        {"王五",22,'A'}
    };
    int i;
    int n = sizeof(a)/sizeof(a[0]);
    for(i=n-1;i>0;i--)
    {
        if (a[i].level<a[i-1].level)
        {
            struct lx temp=a[i];
            a[i]=a[i-1];
            a[i-1]=temp;
        }   
    }
    printf("姓名：%s\n年龄：%d\n等级：%c\n",a[0].name,a[0].age,a[0].level);
    return 0;
}
