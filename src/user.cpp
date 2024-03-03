#include "classes.hpp"

User::User()
{
    user_id = "";
    name = "";
    password = "";
    gender = "";
    age = "";
    email = "";
    phoneno = "";
    dl_number = "";
    type = "";
}

User::User(vector<string> data)
{
    user_id = data[0];
    password = data[1];
    name = data[2];
    gender = data[3];
    age = data[4];
    phoneno = data[5];
    email = data[6];
    dl_number = data[7];
    type = data[8];
}

void User ::get_user_data()
{
    users.clear();
    vector<vector<string>> users_list = read_customers_db();
    for (int i = 0; i < users_list.size(); i++)
    {
        User usr(users_list[i]);
        users.push_back(usr);
    }
}

vector<string> User ::user_data()
{
    vector<string> data;
    data.push_back(user_id);
    data.push_back(password);
    data.push_back(name);
    data.push_back(gender);
    data.push_back(age);
    data.push_back(phoneno);
    data.push_back(email);
    data.push_back(dl_number);
    data.push_back(type);
    return data;
}

void User ::write_user_data()
{
    vector<vector<string>> customer_list;
    vector<vector<string>> employee_list;
    vector<vector<string>> manager_list;
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].type == "C")
            customer_list.push_back(users[i].user_data());
        else if (users[i].type == "E")
            employee_list.push_back(users[i].user_data());
        else if (users[i].type == "M")
            manager_list.push_back(users[i].user_data());
    }
    write_csv("databases/customer.csv", customer_list);
    write_csv("databases/employee.csv", employee_list);
    write_csv("databases/manager.csv", manager_list);
}

int User ::validate(string a)
{
    if (a == this->password)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void User::update_password(string a)
{
    this->password = a;
}

int User ::isUser(string a)
{
    get_user_data();
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].user_id == a)
        {
            if (users[i].type == "M")
                return 1;
            else if (users[i].type == "E")
                return 2;
            else if (users[i].type == "C")
                return 3;
        }
    }
    return 0;
}
void User ::registeration()
{
    vector<vector<string>> users_list = read_csv("databases/customers.csv");
    user_id = "U" + to_string(stoi(users_list[(users_list.size() - 1)][0].substr(1, users_list[(users_list.size() - 1)][0].size() - 1)) + 1);
    cout << "| >> Enter your name: ";
    cin.ignore(1000, '\n');
    getline(cin, name);
    while (name.length() < 3 || name.length() > 20)
    {
        cout << "| >> Invalid, enter again (Too Smol/Too Huge): ";
        getline(cin, password);
    }
    cout << "| >> Enter your password: ";
    getline(cin, password);
    while (password.length() < 5 || password.length() > 20)
    {
        cout << "| >> Choose a stronger password, between 5 and 20 characters: ";
        getline(cin, password);
    }
    cout << "| >> Choose your gender (1: male, 2: female, 3: other): ";
    cin >> gender;
    while (gender != "1" & gender != "2" & gender != "3")
    {
        cout << "| >> Invalid, enter again : ";
        cin >> gender;
    }
    cout << "| >> Enter your age: ";
    cin >> age;
    while (age.length() < 1 || age.length() > 3 || !is_number(age))
    {
        cout << "| >> Invalid, enter again : ";
        cin >> age;
    }
    cout << "| >> Enter your phone number: ";
    cin >> phoneno;
    while (phoneno.length() != 10 || !is_number(phoneno))
    {
        cout << "| >> Invalid, enter again : ";
        cin >> phoneno;
    }
    cout << "| >> Enter your email: ";
    cin >> email;
    while (email.length() < 5 || email.length() > 30)
    {
        cout << "| >> Invalid, enter again : ";
        cin >> email;
    }
    cout << "| >> Enter your driving license number: ";
    cin >> dl_number;
    while (dl_number.length() < 5 || dl_number.length() > 20)
    {
        cout << "| >> Invalid, enter again : ";
        cin >> dl_number;
    }

    vector<string> data;
    data.push_back(user_id);
    data.push_back(password);
    data.push_back(name);
    data.push_back(gender);
    data.push_back(age);
    data.push_back(phoneno);
    data.push_back(email);
    data.push_back(dl_number);
    data.push_back("C");
    write_csv_line("databases/customers.csv", data);
    print("Registered successfully");
    print("Your user_id is: " + user_id);
    print("Please remember it for future use");
    print("Please login to continue");
    print("Press 1 to login or 0 to exit");
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        login();
    }
    else
    {
        return;
    }
    return;
}

void User ::login()
{
    cout << line_break;
    cout << "| >> Enter your user_id: ";
    cin >> user_id;
    get_user_data();
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].user_id == user_id)
        {
            cout << "| >> Enter your password: ";
            cin >> password;
            if (users[i].password == password)
            {
                print("Logged in successfully");
                if (users[i].type == "C")
                {
                    Customer customer(users[i].user_data());
                    customer.CustomerMenu();
                }
                else if (users[i].type == "E")
                {
                    Employee employee(users[i].user_data());
                    employee.EmployeeMenu();
                }
                else if (users[i].type == "M")
                {
                    Manager manager(users[i].user_data());
                    manager.manager_menu();
                }
                return;
            }
            else
            {
                cout << "| >> Invalid password, press 1 to try again or 0 to exit : ";
                int choice = 1;
                do
                {
                    if (!(cin >> choice))
                    {
                        cin.clear();                                                   // clears the error state
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // remove the bad input from the buffer
                        print("Invalid Choice");
                    }
                    else
                    {
                        cout << "| Re-enter your password: ";
                        cin >> password;
                        if (users[i].password == password)
                        {
                            print("Logged in successfully");
                            if (users[i].type == "C")
                            {
                                Customer customer(users[i].user_data());
                                customer.CustomerMenu();
                            }
                            else if (users[i].type == "E")
                            {
                                Employee employee(users[i].user_data());
                                employee.EmployeeMenu();
                            }
                            else if (users[i].type == "M")
                            {
                                Manager manager(users[i].user_data());
                                manager.manager_menu();
                            }
                            return;
                        }
                        else
                        {
                            cout << "| >> Invalid password, press 1 to try again or 0 to exit : ";
                        }
                    }
                } while (choice != 0);
                return;
            }
        }
    }
    print("Invalid User");
    cout << "| >> Press 1 to try again or 0 to exit: ";
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        login();
    }
    else
    {
        return;
    }
    return;
}
