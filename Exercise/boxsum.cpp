#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
   int s1,s2,s3,s4,s5,s6;
   int t1,t2;
   vector<int> ans;

   while(true)
   {
      cin >> s1 >> s2 >> s3 >> s4 >> s5 >> s6;
      if(s1+s2+s3+s4+s5+s6==0) break;
      ans.push_back(s6);//6*6
      ans.at(ans.size()-1)+=s5;//5*5
      if((s1-=s5*11)<0) s1=0;//5*5+1*1
      ans.at(ans.size()-1)+=s4;//4*4
      t1=s4*20;
      if(s2>=s4*5) t1=0,s2-=s4*5;//4*4+2*2 
      else
      {
         t1=s2*4,s2=0;
         if(s1>=t1) s1-=t1,t1=0;//4*4+2*2+1*1 
         else t1-=s1,s1=0;
      }
      ans.at(ans.size()-1)+=(s3/4),s3%=4;//3*3 
      if(s3)
      {
         ans.at(ans.size()-1)++;
         t1=36-s3*9,t2=(3-s3)*2+1;
         if(s2>=t2) s2-=t2,t1-=t2*4;//3*3+2*2 
         else t1-=s2*4,s2=0;
         if(s1>=t1) s1-=t1,t1-=s1;//3*3+2*2+1*1 
         else t1-=s1,s1=0;
      }
      ans.at(ans.size()-1)+=s2/4,s2%=9;//2*2 
      if(s2)
      {
         ans.at(ans.size()-1)++;
         t1=36-s2*4;
         if(s1>=t1) s1-=t1,t1-=s1;//2*2+1*1 
         else t1-=s1,s1=0;
      }
      ans.at(ans.size()-1)+=s1/36+(s1%36!=0);//1*1 
   }

   for(int i=0;i<ans.size();cout<<ans.at(i)<<endl,i++);

   return 0;
}
