#include "classes.hpp"
Date::Date()
{
    this->t = time(0);
    strftime(this->stringdate, 80, "%m-%d-%Y", localtime(&t));
}

Date ::Date(string s)
{
    struct tm *tm = localtime(&t);
    tm->tm_mday = (s[0] - '0') * 10 + (s[1] - '0');
    tm->tm_mon = (s[3] - '0') * 10 + (s[4] - '0') - 1;
    tm->tm_year = (s[6] - '0') * 1000 + (s[7] - '0') * 100 + (s[8] - '0') * 10 + (s[9] - '0') - 1900;
    this->t = mktime(tm);
    strftime(this->stringdate, 80, "%d-%m-%Y", gmtime(&t));
}

void Date::getDate()
{
    const int MAXLEN = 80;
    char s[MAXLEN];
    time_t t = time(0);
    struct tm *tm = localtime(&t);
    int truth = 1;
    print("Press Enter to Continue.");
    cin.ignore(1000, '\n');
    do
    {
        truth = 1;
        while (1)
        {
            cout << "| >> Enter date in format dd-mm-yyyy: ";
            cin.getline(s, MAXLEN);
            if (strlen(s) != 10)
            {
                print("Invalid Date Format");
                continue;
            }
            if (s[2] != '-' || s[5] != '-')
            {
                print("Invalid Date Format");
                continue;
            }
            if (s[0] < '0' || s[0] > '3' || s[1] < '0' || s[1] > '9' || s[3] < '0' || s[3] > '1' || s[4] < '0' || s[4] > '9' || s[6] < '0' || s[6] > '9' || s[7] < '0' || s[7] > '9' || s[8] < '0' || s[8] > '9' || s[9] < '0' || s[9] > '9')
            {
                print("Invalid Date Format");
                continue;
            }
            if (s[0] == '3' && s[1] > '1')
            {
                print("Invalid Date Format");
                continue;
            }
            if (s[3] == '1' && s[4] > '2')
            {
                print("Invalid Date Format");
                continue;
            }
            break;
        }
        tm->tm_mday = (s[0] - '0') * 10 + (s[1] - '0');
        tm->tm_mon = (s[3] - '0') * 10 + (s[4] - '0') - 1;
        tm->tm_year = (s[6] - '0') * 1000 + (s[7] - '0') * 100 + (s[8] - '0') * 10 + (s[9] - '0') - 1900;
        if (tm->tm_mday == 29)
        {
            if (tm->tm_mon == 1)
            {
                if (tm->tm_year % 4 == 0)
                {
                }
                else
                {
                    truth = 0;
                    print("Invalid Date.");
                    continue;
                }
            }
        }
        if (mktime(tm) == this->t)
        {
            truth = 0;
            print("Invalid Date.");
            continue;
        }
    } while (mktime(tm) == this->t || truth == 0);
    this->t = mktime(tm);
    // strftime(this->stringdate, 80, "%d-%m-%Y", gmtime(&t));
    // cout << "| >> Date set to : " << this->stringdate << endl;
}
void Date ::saveDate()
{
    strftime(this->stringdate, 80, "%d-%m-%Y", gmtime(&t));
}
int Date ::compareDate(const Date &d)
{
    if (this->t > d.t)
        return 1;
    else
        return 0;
}

int Date ::difference(const Date &d)
{
    int diff = this->t - d.t;
    return diff / (60 * 60 * 24);
}
void Date ::confirmDate()
{
    printDate();
    cout << "| >> Is this the correct date? (y: Yes, n: No) : ";
    char ap;
    cin >> ap;
    if (ap == 'n' || ap == 'n')
    {
        getDate();
    }
}

void Date ::printDate()
{
    strftime(this->stringdate, 80, "%d-%m-%Y", gmtime(&t));
    print("Today's System Date is set to : ", this->stringdate);
}
