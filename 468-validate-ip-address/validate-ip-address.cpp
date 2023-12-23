class Solution {
public:

    bool helper(char ch){
        if(!((ch>='0' && ch<='9') || (ch>='a' && ch<='f') || (ch>='A' && ch<='F'))) return false;
        return true;
    }
    bool validateIPv6(string str){
        int n=str.length();
        if(n>4 || n==0) return false;
        for(int i=0;i<n;i++){
            if(!helper(str[i])) return false;
        }
        return true;
    }

    bool checkIPv6(string s, int n, int idx,int cnt){
        if(cnt>7) return false;
        if(cnt==7) return validateIPv6(s.substr(idx));
        if(idx==n) return cnt==7;
        for(int i=idx;i<n;i++){
            if(s[i]==':'){
                int len = i-idx;
                string sub = s.substr(idx,len);
                if(validateIPv6(sub)){
                    return checkIPv6(s,n,i+1,cnt+1);
                }
                else return false;
            }
        }
        return false;
    }

    bool validateIPv4(string str){
        int n=str.length(),num=0;
        if(n>3 || n==0) return false;
        if(n>1 && str[0]=='0') return false;
        for(int i=0;i<n;i++){
            if(str[i]<'0' || str[i]>'9') return false;
            num = num*10+(str[i]-'0');
        }
        if(num>=0 && num<=255) return true;
        return false;
    }

    bool checkIPv4(string s, int n, int idx,int cnt){
        if(cnt>3) return false;
        if(cnt==3) return validateIPv4(s.substr(idx));
        if(idx==n) return cnt==3;
        for(int i=idx;i<n;i++){
            if(s[i]=='.'){
                int len = i-idx;
                string sub = s.substr(idx,len);
                if(validateIPv4(sub)){
                    cout<<sub<<endl;
                    return checkIPv4(s,n,i+1,cnt+1);
                }
                else return false;
            }
        }
        return false;
    }

    string validIPAddress(string queryIP) {
        int n=queryIP.size();
        if(checkIPv4(queryIP,n,0,0)) return "IPv4";
        if(checkIPv6(queryIP,n,0,0)) return "IPv6";
        return "Neither";
    }
};