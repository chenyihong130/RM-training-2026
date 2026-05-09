#include<iostream>
#include<string>
#include<fstream>
//写入循环问候的语句
std::string great[]=
{
    "今天很高兴见到你,",
    "热烈欢迎你的到来,",
    "很高兴见到你,",
    "欢迎来到我的世界,"
};
int len=sizeof(great)/sizeof(great[0]);
int read()
{
    std::ifstream fin("greet.txt");
    int num=0;
    if (fin)
        fin>>num;
    fin.close();
    return num;
}
void write(int num)
{
    std::ofstream fout("greet.txt");
    fout<<num;
    fout.close();
}
int main(int argc,char*argv[])
{
    int num=read();
    if(argc<2)
    {
        std::cout<<"请输入你的参数！"<<std::endl;
        return 1;
    }
    if(num>=len)
        num%=len;
    std::cout<<great[num]<<argv[1]<<std::endl;
    num++;
    write(num);
    return 0;
}