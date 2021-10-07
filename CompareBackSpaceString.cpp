//ajisdbnmkzxc
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int slow = 0;
        string t1;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '#')
                slow = slow == 0 ? 0:slow - 1;
            else
                s[slow++] = s[i];
        }
        t1 = s.substr(0,slow);
        slow = 0;
        for(int i = 0; i < t.size(); i++)
        {
            if(t[i] == '#')
                slow = slow == 0 ? 0:slow - 1;
            else 
                t[slow++] = t[i];
        }
        string t2 = t.substr(0,slow);
        return t1 == t2;
    }
};
