#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
char* Change(char* str)
{
    if (strlen(str) < 3)
        return str;
    char* tmp = new char[strlen(str) * 3 / 2 + 1];
    char* t = tmp;
    tmp[0] = '\0';
    int i = 0;
    while (str[i] != 0)
    {
        if ((str[i] == '+' && str[i + 1] == '+')
            ||
            (str[i] == '-' && str[i + 1] == '-')
            ||
            (str[i] == '=' && str[i + 1] == '='))
        {

            strcat(t, "***");
            t += 3;
            i += 2;
        }
        else
        {
            *t++ = str[i++];
            *t = '\0';
        }
    }
    *t++ = str[i++];
    *t++ = str[i++];
    *t = '\0';
    strcpy(str, tmp);
    return tmp;
}



int Count(const char* str)
{
    int k = 0;
    for (int i = 0; i < strlen(str); i++)
        if (str[i] == '+' || str[i] == '-' || str[i] == '=')
            k++;
    return k;
}



int main()
{
    char str[201];
    cout << "Enter string: ";
    cin.getline(str, 200); cout << endl;
    cout << "calc " << Count(str) << endl;
    cout << "Modified string (param) : " << str << endl;
    char* dest = new char[151];
    dest = Change(str);
    cout << "Modified string (result): " << dest << endl;
    return 0;
}