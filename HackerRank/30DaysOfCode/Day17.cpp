#include <cmath>
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

class Calculator{
    public: 
    int power(int n, int p) {
        int number = 1;
        if(0 > n || 0 > p) {
          throw invalid_argument("n and p should be non-negative");
        } else {
            for(int i = 0; i < p; i++) {
            number *= n;
            }
        }
        return number;
    }
};
//Write your code here

int main()
{
    Calculator myCalculator=Calculator();
    int T,n,p;
    cin>>T;
    while(T-->0){
      if(scanf("%d %d",&n,&p)==2){
         try{
               int ans=myCalculator.power(n,p);
               cout<<ans<<endl; 
         }
         catch(exception& e){
             cout<<e.what()<<endl;
         }
      }
    }
    
}