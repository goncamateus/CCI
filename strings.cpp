#include <iostream>
#include <string.h>
#include <vector>

// exercise 1.1
bool is_unique(std::string str)
{
    if (str.length() > 128)
        return false;
    bool char_set[128];
    for (int i = 0; i < 128; i++)
        char_set[i] = false;
    for (auto i = str.begin(); i != str.end(); i++)
    {
        int v = (*i);
        if (!char_set[v])
            char_set[v] = true;
        else
            return false;
    }
    return true;
}

bool is_unique_optim(std::string str)
{
    int checker = 0;
    for (auto i = str.begin(); i != str.end(); i++)
    {
        int v = (*i) - 'a';
        if ((checker & (1 << v)) > 0)
            return false;
        else
            checker |= (1 << v);
    }
    return true;
}

// exercise 1.2
bool permutation(std::string str1, std::string str2)
{
    if (str1.length() != str2.length())
        return false;
    int char_set[128];
    for (int i = 0; i < 128; i++)
        char_set[i] = 0;
    for (auto i = str1.begin(); i != str1.end(); i++)
    {
        int v = (*i);
        char_set[v]++;
    }
    for (auto i = str2.begin(); i != str2.end(); i++)
    {
        int v = (*i);
        char_set[v]--;
        if (char_set[v] < 0)
            return false;
    }
    return true;
}

// exercise 1.3
std::string URLify(std::string str, int len)
{
    int spacecount = 0, i = 0, index;
    for (; i < len; i++)
    {
        if (str[i] == ' ')
            spacecount++;
    }
    index = len + spacecount * 2;
    if (len < str.length())
        str[len] = '\0';
    for (i = len; i >= 0; i--)
    {
        if (str[i] == ' ')
        {
            str[index - 1] = '0';
            str[index - 2] = '2';
            str[index - 3] = '%';
            index = index - 3;
        }
        else
        {
            str[index - i] = str[i];
            index--;
        }
    }
    return str;
}

int main()
{
    std::string str1 = "ab ba", str2 = "abba";
    std::cout << URLify(str1, 5) << std::endl;
    return 0;
}