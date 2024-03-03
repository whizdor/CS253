#include "classes.hpp"

void print(string a)
{
    int n = a.length();
    cout << "| ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
        if (a[i] == '\n')
        {
            break;
        }
    }
    for (int i = 0; i < 88 - n; i++)
    {
        cout << " ";
    }
    cout << "|";
    cout << endl;
}

void print(string a, string b)
{
    int n = a.length();
    cout << "| ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
        if (a[i] == '\n')
        {
            break;
        }
    }
    for (int i = 0; i < 38 - n; i++)
    {
        cout << " ";
    }
    cout << b;
    for (int i = 0; i < 50 - b.length(); i++)
    {
        cout << " ";
    }
    cout << "|";
    cout << endl;
}

void print(string d, string a, string b, string c)
{
    cout << "| ";
    if (d.length() > 3)
    {
        d = d.substr(0, 1);
        d = d + "..";
    }
    cout << d;
    for (int i = 0; i < 3 - d.length(); i++)
    {
        cout << " ";
    }
    cout << "| ";
    if (a.length() > 10)
    {
        a = a.substr(0, 8);
        a = a + "..";
    }
    cout << a;
    for (int i = 0; i < 10 - a.length(); i++)
    {
        cout << " ";
    }
    cout << "| ";
    if (b.length() > 41)
    {
        b = b.substr(0, 39);
        b = b + "..";
    }
    cout << b;
    for (int i = 0; i < 41 - b.length(); i++)
    {
        cout << " ";
    }
    cout << "| ";
    if (c.length() > 28)
    {
        c = c.substr(0, 26);
        c = c + "..";
    }
    cout << c;
    for (int i = 0; i < 28 - c.length(); i++)
    {
        cout << " ";
    }
    cout << "|";
    cout << endl;
}

void print(string a, string b, string c, string d, string e, string f, string g, string h)
{
    cout << "| ";
    if (a.length() > 3)
    {
        a = a.substr(0, 1);
        a = a + "..";
    }
    cout << a;
    for (int i = 0; i < 3 - a.length(); i++)
    {
        cout << " ";
    }
    cout << "| ";
    if (b.length() > 14)
    {
        b = b.substr(0, 12);
        b = b + "..";
    }
    cout << b;
    for (int i = 0; i < 14 - b.length(); i++)
    {
        cout << " ";
    }
    cout << "| ";
    if (c.length() > 12)
    {
        c = c.substr(0, 10);
        c = c + "..";
    }
    cout << c;
    for (int i = 0; i < 12 - c.length(); i++)
    {
        cout << " ";
    }
    cout << "| ";
    if (d.length() > 9)
    {
        d = d.substr(0, 7);
        d = d + "..";
    }
    cout << d;
    for (int i = 0; i < 10 - d.length(); i++)
    {
        cout << " ";
    }
    cout << "| ";
    if (e.length() > 6)
    {
        e = e.substr(0, 4);
        e = e + "..";
    }
    cout << e;
    for (int i = 0; i < 6 - e.length(); i++)
    {
        cout << " ";
    }
    cout << "| ";
    if (f.length() > 7)
    {
        f = f.substr(0, 5);
        f = f + "..";
    }
    cout << f;
    for (int i = 0; i < 7 - f.length(); i++)
    {
        cout << " ";
    }
    cout << "| ";
    if (g.length() > 10)
    {
        g = g.substr(0, 8);
        g = g + "..";
    }
    cout << g;
    for (int i = 0; i < 11 - g.length(); i++)
    {
        cout << " ";
    }
    cout << "| ";
    if (h.length() > 10)
    {
        h = h.substr(0, 8);
        h = h + "..";
    }
    cout << h;
    for (int i = 0; i < 11 - h.length(); i++)
    {
        cout << " ";
    }
    cout << "|";
    cout << endl;
}