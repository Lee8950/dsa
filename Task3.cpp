#include <bits/stdc++.h>

namespace ecl{
    char *match(const char *s, char ch1, char ch2)
    {
        char *i = const_cast<char*>(s) - 1;
        while(*(++i)!=ch1);
        char *m = i;
        while((*m!=ch2)&&(*m!='\0'))
            std::cout << *m++;
        std::cout << *m;
        return i;
    }
}

int main()
{
    std::string str;
    char c1, c2;
    std::cin >> str >> c1 >> c2;
    ecl::match(str.c_str(), c1, c2);
    return 0;
}