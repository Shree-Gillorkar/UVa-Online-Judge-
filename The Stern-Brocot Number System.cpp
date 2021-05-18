#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

string solve(int a, int b)
{
    int m1 = 0;
    int d1 = 1;
    int m2 = 1;
    int d2 = 0;
    string str = "";
    while (true)
    {
        if ((m1 + m2) * b > (d1 + d2) * a)
        {
            m2 += m1;
            d2 += d1;
            str += "L";
        }
        else //if ((m1 + m2) * b < (d1 + d2) * a)
        {
            m1 += m2;
            d1 += d2;
            str += "R";
        }
        if ((m1 + m2) == a && (d1 + d2) == b)
        {
            return str;
        }
        //cout << m1 + m2 << "|" << d1 + d2 << endl;
    }
}

int main(int argc, char* argv[])
{
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    int a, b;
    while (cin >> a >> b && (a != 1 || b != 1))
        cout << solve(a, b) << endl;
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}