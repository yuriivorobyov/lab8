

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
char* Change(char* dest, const char* str, char* t, int i)
{
    if (str[i] != 0)
    {
        if ((str[i] == '+' && str[i + 1] == '+')
            ||
            (str[i] == '-' && str[i + 1] == '-')
            ||
            (str[i] == '=' && str[i + 1] == '='))
        {
            strcat(t, "***");
            return Change(dest, str, t + 3, i + 2);
        }
        else
        {
            *t++ = str[i++];
            *t = '\0';
            return Change(dest, str, t, i);
        }
    }
    else
    {
        *t++ = str[i++];
        *t++ = str[i++];
        *t = '\0';
        return dest;
    }
}

int Count(char* s, const char* cs)
{
    int k = 0,
        pos = 0;
    char* t;
    while (t = strpbrk(s + pos, cs))
    {
        pos = t - s + 1;
        k++;
    }
    return k;
}

int main()
{
    char str[201];

    cout << "Enter string: ";
    cin.getline(str, 200); cout << endl;
    char cs[] = "+-=";
    cout << "calc " << Count(str, cs) << endl;
    cout << "Modified string (param) : " << str << endl;
    char* dest1 = new char[151];
    dest1[0] = '\0';
    char* dest2;
    dest2 = Change(dest1, str, dest1, 0);
    cout << "Modified string (result): " << dest2 << endl;
    return 0;
}