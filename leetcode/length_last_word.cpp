class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int count = 0;
        bool flag = false;
        for(int i=0;i<strlen(s);i++)
        {
            if(flag && s[i]!=' ')
            {
                count=0;
                flag = false;
            }
            
            if(s[i]==' ')
                flag = true;
            else
                count++;
        }
        
        return count;
    }
};
