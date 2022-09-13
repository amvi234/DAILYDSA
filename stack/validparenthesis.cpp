class Solution
{
public:
    bool isValid(string s)
    {
        if (s == "")
        {
            return 1;
        }
        if (s.length() == 1)
        {
            return 0;
        }
        int flag = 1;
        stack<char> a;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                a.push(s[i]);
                continue;
            }
            else
            {
                flag = 0;
                if (a.empty())
                {
                    return 0;
                }
                char ch = a.top();
                if (ch == '(' && s[i] != ')')
                {
                    return 0;
                }
                else if (ch == '{' && s[i] != '}')
                {
                    return 0;
                }
                else if (ch == '[' && s[i] != ']')
                {
                    return 0;
                }
                else
                {
                    a.pop();
                }
            }
        }
        if (flag == 1)
        {
            return 0;
        }
        if (!a.empty())
        {
            return 0;
        }
        return 1;
    }
};