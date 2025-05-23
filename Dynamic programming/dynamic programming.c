// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;





int solveusingmemo(int capacity,int wt[],int profit[],int index,int n,vector<vector<int>> &dp){
    if(index>=n){
        return 0;
    }
    if(dp[capacity][index]!=-1){
        return dp[capacity][index];
    }
    int include = 0;
    if(wt[index]<=capacity){
        include = profit[index]+solveusingmemo(capacity-wt[index],wt,profit,index+1,n,dp);
    }
    int exclude = 0+solveusingmemo(capacity,wt,profit,index+1,n,dp);
    
    dp[capacity][index] = max(include,exclude);
    return dp[capacity][index];
}

















int main() {
    int capacity = 50;
    int wt[] = {10,20,30};
    int profit[] = {60,100,120};
    int index=  0;
    int n =  3;
    
    vector<vector<int>>dp(capacity+1,vector<int>(n+1,-1));
    int ans = solveusingmemo(capacity,wt,profit,index,n,dp);
    cout<<"Max profit:"<<ans<<endl;
    
    
    

    return 0;
}





