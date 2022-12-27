#include <bits/stdc++.h>

namespace ecl
{
    class AutomataMachine
    {
    private:
        std::string result;
        std::unordered_map<char, bool> m;

    public:
        AutomataMachine() {}
        ~AutomataMachine() {}
        void reset()
        {
            result.clear();
            m.clear();
        }
        void input(char c)
        {
            if (m.find(c) == m.end())
            {
                m.insert(std::make_pair(c, true));
                result += c;
            }
        }
        std::string solve() { return result; }
    };
}

int main()
{
    std::string A, B;
    ecl::AutomataMachine machine;
    //A = "This is a sample test";
    //B = "to show you_How it works";
    std::getline(std::cin, A);
    std::getline(std::cin, B);
    for(int i = 0; i < A.length(); i++)
        machine.input(A[i]);
    for(int i = 0; i < B.length(); i++)
        machine.input(B[i]);
    std::cout << machine.solve();
    return 0;
}