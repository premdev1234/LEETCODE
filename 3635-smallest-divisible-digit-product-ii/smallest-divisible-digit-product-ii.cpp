class Solution {
public:
int count(long long vl){
    int ct=0;
    for(int i=9;i>1;i--){
        while(vl%i==0){
            vl/=i;
            ct++;
        }
    }
    if(vl>1)return INT_MAX;
    return ct;
}
string lexSmallestString(long long t,int ct){
    string ans(ct,' ');
    ct--;
    for(int i=9;i>1;i--){
        while(t%i==0){
            ans[ct--]='0'+i;
            t/=i;
        }
    }
    return ans;
}

bool canCreateGreaterWithRest(string &num,int ind,long long vl){
    int ct=0,n=num.size();
    vector<int> tp(10);
    for(int i=9;i>1;i--){
        while(vl%i==0){
            tp[i]++;
            vl/=i;
            ct++;
        }
    }
    int extraSpaces=n-ind-ct;
    tp[8]+=tp[2]+tp[4];
    tp[2]=0;
    tp[4]=0;
    tp[9]+=tp[3]+extraSpaces;
    tp[3]=0;

    for(int i=9;i>=1;i--){
        while(ind<n&&tp[i]>0){
            if(i>num[ind]-'0')return true;
            if(i<num[ind]-'0')return false;
            ind++;
            tp[i]--;
        }
    }
    return true;
}
    string smallestNumber(string num, long long t) {
        int n=num.size();
        int factcount=count(t);
        if(factcount==INT_MAX)return "-1";
        if(factcount>num.length()){
            return lexSmallestString(t,factcount);
        }
        long long l=0,h=n,vl=-1,ans=-1;
        while(l<=h){
            long long mid=(l+h)/2;
            long long crt=t;
            bool zeroEncountered=false;
            for(int i=0;i<mid;i++){
                if(num[i]=='0'){
                    h=i;
                    zeroEncountered=true;
                    break;
                }
                crt/=gcd(crt,num[i]-'0');
            }
            if(zeroEncountered)continue;
            bool possible=false;
            if(mid==n){
                if(crt==1)return num;
            }
            else{
                for(int i=max(1,num[mid]-'0');i<10;i++){
                    long long newT=crt/gcd(crt,i);
                    int postionsRequired=count(newT);
                    if(postionsRequired<=n-mid-1&&(i>num[mid]-'0'||canCreateGreaterWithRest(num,mid+1,newT))){
                        vl=i;
                        possible=true;
                        break;
                    }
                }
            }
            if(possible){
                l=mid+1;
                ans=mid;
            }
            else{
                h=mid-1;
            }
        }
        long long crt=t;
        if(ans==-1){
            num='0'+num;
            int ind=n;
            for(int j=9;j>0;j--){
                while(ind>ans&&crt%j==0){
                    num[ind--]='0'+j;
                    crt/=j;
                }
            }
            return num;
        }
        num[ans]='0'+vl;
        for(int i=0;i<=ans;i++){
            if(num[i]=='0')continue;
            crt/=gcd(crt,num[i]-'0');
        }
        int ind=n-1;
        for(int j=9;j>0;j--){
            while(ind>ans&&crt%j==0){
                num[ind--]='0'+j;
                crt/=j;
            }
        }
        return num;
    }
};