#include <bits/stdc++.h>

namespace ecl
{
    class KMP
    {
    private:
        int *next;
        int size;
        std::string pattern;

    public:
        KMP() : next(nullptr), size(0) {}
        ~KMP()
        {
            if (next != nullptr)
                delete[] next;
            size = 0;
        }
        KMP(std::string pat)
        {
            size = pat.length();
            next = new int[size];
            pattern = pat;
            int j = -1;
            next[0] = j;
            for (int i = 0; i < pattern.length(); i++)
            {
                while (j >= 0 && (pattern[j + 1] != pattern[i]))
                    j = next[j];
                if (pattern[j + 1] == pattern[i])
                    j++;
                next[i] = j;
            }
        }
        void set(std::string pat)
        {
            size = pat.length();
            if (next != nullptr)
                delete[] next;
            next = new int[size];
            pattern = pat;
            int j = -1;
            next[0] = j;
            for (int i = 0; i < pattern.length(); i++)
            {
                while (j >= 0 && (pattern[j + 1] != pattern[i]))
                    j = next[j];
                if (pattern[j + 1] == pattern[i])
                    j++;
                next[i] = j;
            }
        }
        std::string::const_iterator match(std::string &str)
        {
            if (size == 0)
                return std::string::const_iterator(str.end());
            int j = -1;
            for (int i = 0; i < str.length(); i++)
            {
                while (j >= 0 && (str[i] != pattern[j + 1]))
                    j = next[j];
                if (str[i] == pattern[j + 1])
                    j++;
                if (j == size - 1)
                    return std::string::const_iterator(str.begin() + i - size + 1);
            }
            return std::string::const_iterator(str.end());
        }
    };
}

int main()
{
    std::string a, b;
    ecl::KMP kmp;
    std::cin >> a >> b;
    //a = "abcd";
    //b = "cdabcdab";
    int a_length = a.length();
    for (int i = 1; i < (b.length() / a_length) + 2; i++, a = a + a)
    {
        kmp.set(b);
        if (kmp.match(a) != a.end())
        {
            std::cout << i;
            break;
        }
    }
    if (kmp.match(a) == a.end())
        std::cout << -1;
    return 0;
}