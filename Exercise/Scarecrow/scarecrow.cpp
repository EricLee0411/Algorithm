#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main(void)
{
   int n;
   cin >> n;
   vector<int> ans;

   while(--n>=0)
   {
      int i,sum=0;
      cin >> i;
      vector<char> f;
      f.resize(i);

      while(--i>=0)
         cin >> f.at(f.size()-i-1);

      for(int j=0;j<f.size();j++)
      {
         if(f.at(j)=='.')
         {
            j+=2;
            sum++;
         }
      }

      ans.push_back(sum);
   }

   for(int i=0;i<ans.size();cout<<"Case "<<i+1<<": "<<ans.at(i)<<endl,i++);

   return 0;
}
