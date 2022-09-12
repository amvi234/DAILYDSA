bool canConstruct(string ransomNote, string magazine)
{
    if (ransomNote.size() == 1 && magazine.size() == 1)
    {
        if (ransomNote[0] != magazine[0])
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    map<char, int> m;
    for (int i = 0; i < ransomNote.size(); i++)
    {
        m[ransomNote[i]]++;
    }
    map<char, int> m1;
    for (int i = 0; i < magazine.size(); i++)
    {
        m1[magazine[i]]++;
    }
    int flag = 1;

    for (int i = 0; i < ransomNote.size(); i++)
    {
        if (m[ransomNote[i]] <= m1[ransomNote[i]])
        {
            continue;
        }
        else
        {
            flag = 0;
            break;
        }
    }

    if (flag == 1)
    {
        return 1;
    }
    return 0;
}
