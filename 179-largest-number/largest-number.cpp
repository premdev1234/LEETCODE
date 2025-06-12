class Solution {
public:
    static bool comparator(string&a,string&b)
    {
        return a+b>b+a;
    }
    string largestNumber(vector<int>& nums) {
     vector<string> numberString;
     for(int i=0;i<nums.size();i++) 
     {
        numberString.push_back(to_string(nums[i]));
     }  
     sort(numberString.begin(),numberString.end(),comparator);

     if(numberString[0]=="0")
       return "0";

     string result="";

     for(auto it:numberString)
     {
        result+=it;
     }  
     return result;
    }
};