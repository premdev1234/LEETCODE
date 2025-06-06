class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int count1 =0;
        int count2 =0;
        int bucket_1 =- 2;
        int bucket_2 =- 2;
        int maxi = 0;
        for ( int i =0 ;i<fruits.size();i++ ){
            if ( bucket_1 ==-2 || fruits[bucket_1] == fruits[i]  ){
               bucket_1 = i ;
               count1++; 
            }
            else if ( bucket_2 ==-2 || fruits[bucket_2] == fruits[i]  ){
               bucket_2 = i ;
               count2++; 
            }
            else {
                 if ( bucket_1 > bucket_2 ){
                    count1 = bucket_1 -bucket_2 ;
                    bucket_2 =i ;
                    count2=1 ;
                 }
                 else {
                    count2 =bucket_2 - bucket_1 ;
                    bucket_1 =i ;
                    count1=1 ;
                 }
            }
            maxi = max(maxi,count1+count2);
        }
        return maxi ;
    }
};
