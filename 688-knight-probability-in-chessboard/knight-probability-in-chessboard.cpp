class Solution {
public:

double dp[26][26][101];
    double total_prob(int i,int j,int k,int n){

        if(i<0 || j<0 || i>=n || j>=n ) return 0.0;
        if(k<=0) return 1.0;
        if(dp[i][j][k] > -0.1) return dp[i][j][k];
        double a=total_prob(i+1,j+2,k-1,n)*(0.125);//done
        double a_= total_prob(i+1,j-2,k-1,n)*(0.125); //done

        double b=total_prob(i-1,j+2,k-1,n)*(0.125);//done
        double b_=total_prob(i-1,j-2,k-1,n)*(0.125); //dpne

        double c= total_prob(i+2,j+1,k-1,n)*(0.125);//done
        double c_=total_prob(i+2,j-1,k-1,n)*(0.125);//done

        double d=total_prob(i-2,j+1,k-1,n)*(0.125); //done
        double d_=total_prob(i-2,j-1,k-1,n)*(0.125); //done
    return dp[i][j][k]=a+b+c+d+a_+b_+c_+d_;
    }

    double knightProbability(int n, int k, int row, int column) {

       memset(dp,-1,sizeof(dp)); 
        return total_prob(column,row,k,n);
        

    }
};