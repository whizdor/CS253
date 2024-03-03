#ifndef CLASSES_HPP
#define CLASSES_HPP
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <climits>
#include <cfloat>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <list>
#include <array>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <iterator>
#include <ctime>
#include <tuple>
#include <numeric>
#include <chrono>
using namespace std;
string line_break = "------------------------------------------------------------------------------------------\n";

class Car
{
public:
    // Attributes
    string dl_number;
    string make;
    string model;
    string year;
    string seats;
    string power_source;
    string transmission;
    string dents;
    string scratches;
    string tyre_condition;
    string light_condition;
    string miles_driven;
    string onRent;
    string start_date;
    string end_date;
    string renter_user_id;
    string employee_user_id;
    string base_charge;
    string km_charge;
    string late_charge;

    // Methods
    Car();
    Car(vector<string> data);
    ~Car();
    Car(const Car &other);

    vector<string> getcardetails();
    vector<string> cardetails();
    void printcardetails();
    void updatecardetails(vector<string> data);
    void updatecardetails();
    void writetocardatabase(string filename);
};

class Date
{
public:
    int date;
    int month;
    int year;
    time_t t;
    char stringdate[80];

    Date();
    Date(string a);
    void confirmDate();
    void getDate();
    void printDate();
    void saveDate();
    int difference(const Date &d);
    int compareDate(const Date &d);
};

class User
{
private:
    string password;

public:
    string user_id;
    string name;
    string gender;
    string age;
    string email;
    string phoneno;
    string dl_number;
    string type;

    // Methods
    User();
    User(vector<string> data);
    int validate(string a);
    void update_password(string a);
    void get_user_data();
    void write_user_data();
    vector<string> user_data();
    void login();
    int isUser(string a);
    void registeration();
};

vector<User> users;

class Customer : public User
{
public:
    // Attributes
    string total_number_days;
    string total_amount;
    string total_damage;
    string current_rents;
    string allowed_rents;
    vector<Car> cars;

    // Methods
    Customer();
    Customer(vector<string> data);
    ~Customer();
    Customer(const Customer &other);

    vector<string> get_saved_data(string user_id);
    int check_eligibility();
    void save_customer_data();
    void open_cars_database();
    void search_cars();
    void view_rented_cars();
    void update_customer();
    void view_bill(vector<string> data);
    void book_car(int);
    void book_car();
    void list_cars();
    void view_dues();
    void clear_dues();
    void car_details();
    void return_car();
    void CustomerMenu();
    void logout();
};

class Employee : public Customer
{
public:
    string sales;

    Employee();
    Employee(vector<string> data);
    Employee(string user_id);
    ~Employee();
    Employee(const Employee &other);

    void save_employee_data();
    void view_dues();
    void clear_dues();
    void update_car_details();
    void update_employee();
    void fix_car();
    void EmployeeMenu();
    void return_car();
    void logout();
};

class Manager : public Employee
{
public:
    Manager();
    Manager(vector<string> data);
    ~Manager();
    Manager(const Manager &other);

    void list_cars();

    void list_employee();
    void search_employee();
    void add_employee();
    void remove_employee();
    void update_employee();

    void add_car();
    void remove_car();

    void list_customer();
    void search_customer();
    void add_customer();
    void remove_customer();
    void update_customer();

    void logout();
    void manager_menu();
};

Date date;

void print(string);
void print(string, string);
void print(string, string, string, string);
void print(string, string, string, string, string, string, string, string);

vector<string> split(string);
vector<vector<string> > read_csv(string);
vector<vector<string> > read_customers_db();
void write_csv_line(string, vector<string>);
void write_csv_line_clear(string, vector<string>);
void write_csv(string, vector<vector<string> >);

void Clear()
{
#if defined _WIN32
    system("cls");
    // clrscr(); // including header file : conio.h
#elif defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    // std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences
#elif defined(__APPLE__)
    system("clear");
#endif
}

bool is_number(const std::string &s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it))
        ++it;
    return !s.empty() && it == s.end();
}

#endif