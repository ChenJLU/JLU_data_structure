#include <iostream>
#include <time.h>
using namespace std;
int times;
inline void swap(int *a,int *b)
{
  *a+=*b,*b=*a-*b,*a=*a-*b;
  times++;
}
void adj(int num[],int fa,int end)
{
  int son=fa*2;
  while(son<=end)
  {
    if(son+1<=end && num[son+1]>num[son])
      son++;
    if(num[fa]<num[son])
    {
      swap(num+fa,num+son);
      fa=son,son=fa*2;
    }
    else
      return;
  }
}

void heap_sort(int num[],int n)
{
  for(int i=n/2;i>=1;i--)
    adj(num,i,n);
  for(int i=n;i>=2;i--)
  {
    swap(num+1,num+i);
    adj(num,1,i-1);
  }
}
int main()
{

  int n,num[900000];
  int tot_times;
  cin>>n;
  freopen("/Users/davidparker/desktop/sort.out","w",stdout);

  for(int k=1;k<=10;k++)
  {
    cout<<"##################################"<<endl;
    times=0;
    for(int i=1;i<=n;i++)
      num[i]=rand()%1000000+10;
    for(int i=1;i<=n;i++)
      cout<<num[i]<<" ";
    cout<<endl;
    cout<<"____________________"<<endl;

    cout<<"+_+"<<clock()<<endl;
    heap_sort(num,n);
    cout<<"+_+"<<clock()<<endl;


    for(int i=1;i<=n;i++)
      cout<<num[i]<<" ";
    cout<<endl;
    tot_times+=times;
    cout<<"共进行  "<<times<<"  次比较"<<endl;
  }

  cout<<endl<<endl<<"平均进行  "<<tot_times/10<<"  次比较"<<endl;

  fclose(stdin);
  return 0;

}
