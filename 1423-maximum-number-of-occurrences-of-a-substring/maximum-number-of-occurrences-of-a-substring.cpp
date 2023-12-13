class Solution {
public:
    const int mod=1e9+7;
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        map<int,int> freq;
        vector<int> count(26,0);
        int l=0;
        int ans=0;
        int noOfLetter=0;
        long hash_curr=0;
        long pow=1;
        for(int i=0;i<minSize-1;i++){
            pow=(pow*53)%mod;
        }
        for(int r=0;r<s.size();r++){
            count[s[r]-'a']++;
            if(count[s[r]-'a']==1){
                noOfLetter++;
            }
            if((r-l+1)>minSize){
                hash_curr=((hash_curr-(s[l]-'a'+1)*pow)%mod +mod)%mod;
                count[s[l]-'a']--;
                if(count[s[l]-'a']==0){
                   noOfLetter--; 
                }
                l++;
            }
            hash_curr=((hash_curr*53)%mod+ (s[r]-'a'+1))%mod;
            if((noOfLetter<=maxLetters) && (r-l+1)==minSize){
                ans=max(ans,++freq[hash_curr]);
            }
        }
        return ans;
    }
};