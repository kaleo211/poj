#include<iostream>
using namespace std;
int p[100000];
int main()
{
 int i,a,b,num,t=0;
 bool flag;
 while(cin>>a>>b)
 {
   t++;
   for(i=0;i<100000;i++) p[i]=-1;
   if(a==-1) break;
   flag=true;
   if(a==b) flag=false;//以自己为父节点不是树
   p[b]=a;
   p[a]=0;
   if(a==0)//空树是树
   {
    cout<<"Case "<<t<<" is a tree."<<endl;
    continue;
   }
   while(cin>>a>>b)
   {
    if(a==0) break;
    if(p[b]>0||a==b) flag=false;//b有两个父节点(或与父节点有两个边）不是树，b以自己为父节点不是树
    p[b]=a;
    if(p[a]==-1) p[a]=0;//a暂时没有父节点，标记为根节点
   }
   if(flag)
   {
    for(i=0,num=0;i<100000;i++)//找根节点的数目
     if(p[i]==0) num++;
    if(num!=1)
     flag=false;
   }
   if(flag)
    cout<<"Case "<<t<<" is a tree."<<endl;
   else
    cout<<"Case "<<t<<" is not a tree."<<endl;
 }
 return 0;
}