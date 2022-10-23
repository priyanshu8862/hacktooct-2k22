 bool checkIPV4(string& s){
        s += '.';  
        
        stringstream ss(s);
        string str;
        int n_mark{};
        while(getline(ss, str, '.')){
            
            if(str.size()<1 or str.size()>3)
                return false;
            for(char IP: str){
                if(IP >='0' && IP<='9')
                    continue;
                else
                    return false;
            }
            if((str[0]=='0' and str[1]=='0') or (str[0]=='0' and (str[1] >='1' && str[1]<='9')))
                return false;
            if(stoi(str) > 255)
                return false;
            n_mark++;
        }
        if(n_mark!=4)
            return false;
        return true;
    }
    bool checkIPV6(string& s){
        s += ':';
        stringstream ss(s);
        string str;
        int n_mark{};
        while(getline(ss, str, ':')){
            if(str.size()<1 or str.size()>4)
                return false;
            
            for(char IP: str){
                if((IP >='0' && IP<='9') || (IP>='a' && IP<='f') || (IP>='A' && IP<='F'))
                    continue;
                else
                    return false;
            }
            
            n_mark++;
        }
        if(n_mark!=8)
            return false;
        return true;
    }
public:
    string validIPAddress(string queryIP) {
        for(char ch: queryIP){
            if(ch=='.'){
                if(checkIPV4(queryIP))
                    return "IPv4";
                return "Neither";
            }else if(ch==':'){
                if(checkIPV6(queryIP))
                    return "IPv6";
                return "Neither";
            }
        }
        return "Neither";
    }
