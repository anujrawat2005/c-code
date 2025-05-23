#include <iostream>
#include<vector>
using namespace std;







int solveusingtabulationSO2(int capacity,int wt[],int profit[],int n){
    vector<int> next(capacity+1,0);
    
    for(int j =n-1;j>=0;j--){
        for(int i =capacity;i>=0;i--){
            int include = 0;
            if(wt[j]<=i){
                include = profit[j]+next[i-wt[j]];
            }
            int exclude = 0+next[i];
            next[i] = max(include,exclude);
        }
    }
    return next[capacity];
}


int main() {
    
    int capacity =50;
    int wt[] = {10,20,30};
    int profit[] = {60,100,120};
    int  n = 3;
    vector<vector<int>>dp(capacity,vector<int>(n+1,-1));
    int ans = solveusingtabulationSO2(capacity,wt,profit,n);
    cout<<"Max profit:"<<ans<<endl;
    

    return 0;
}