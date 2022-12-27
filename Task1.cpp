#include <bits/stdc++.h>

namespace ecl{
    void strmcpy(char *t, int m, char *s)
    {
        char *c = t;
        int size = 0;
        while(*(c++)!='\0')size++;
        c = s;
        for(int i = m - 1; i < size; i++)
            *(c++) = t[i];
        *c = '\0';
    }
}

int main()
{
    char *t = "happy new year";
    char *s = new char[100];
    ecl::strmcpy(t,7,s);
    return 0;
}