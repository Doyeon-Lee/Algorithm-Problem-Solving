#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

bool solution(string s)
{
    int p = count(s.begin(), s.end(), 'p') + count(s.begin(), s.end(), 'P');
    int y = count(s.begin(), s.end(), 'y') + count(s.begin(), s.end(), 'Y');
    return p == y ? true : false;
}