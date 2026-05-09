#include<iostream>
int main(int argc,char*argv[])
{
    if (argc<2)
    {
        std::cout<<"请输入参数"<<std::endl;
        return 1;
    }
    std::cout<<"哈喽"<<argv[1]<<std::endl;
    return 0;
}
