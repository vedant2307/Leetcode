class Solution {
public:
    bool isPalindrome(string str){
        int i=0,j=str.size()-1;
        while(i<j && str[i]==str[j]) i++, j--;
        return i>=j;
    }
    string firstPalindrome(vector<string>& words) {
        for(auto it:words) if(isPalindrome(it)) return it;
        return "";
    }
};