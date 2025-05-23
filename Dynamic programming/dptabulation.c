#include <iostream>
#include<vector>
using namespace std;





int solveusingtabulation(int capacity,int wt[],int profit[],int n){
    vector<vector<int>> dp(capacity+1,vector<int>(n+1,-1));
    
    for(int row = 0;row<=capacity;row++){
        dp[row][n] = 0;
    }
    for(int i = 0;i<=capacity;i++){
        for(int j =n-1;j>=0;j--){
            int include = 0;
            if(wt[j]<=i){
                include = profit[j]+dp[i-wt[j]][j+1];
            }
            int exclude = 0+dp[i][j+1];
            dp[i][j] = max(include,exclude);
        }
    }
    return dp[capacity][0];
}

int main() {
    
    
    int capacity = 6;
    int wt[] = {1,2,3};
    int profit[] = {10,15,40};
    
    int n = 3;
    
    int ans = solveusingtabulation(capacity,wt,profit,n);
    cout<<"max profit:"<<ans<<endl;


    return 0;
}

















