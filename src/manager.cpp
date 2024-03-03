#include "classes.hpp"

Manager ::Manager()
{
    this->total_number_days = "";
    this->total_amount = "";
    this->total_damage = "";
    this->current_rents = "";
    this->allowed_rents = "";
    this->sales = "";
}

Manager ::~Manager()
{
    // Destructor
}

Manager ::Manager(vector<string> data)
{
    open_cars_database();
    this->user_id = data[0];
    this->name = data[2];
    this->gender = data[3];
    this->age = data[4];
    this->email = data[5];
    this->phoneno = data[6];
    this->dl_number = data[7];
    vector<string> stored_data = get_saved_data(user_id);
    this->total_number_days = stored_data[0];
    this->total_amount = stored_data[1];
    this->total_damage = stored_data[2];
    this->current_rents = stored_data[3];
    this->allowed_rents = stored_data[4];
    this->sales = stored_data[5];
}

Manager ::Manager(const Manager &other)
{
    this->user_id = other.user_id;
    this->name = other.name;
    this->gender = other.gender;
    this->age = other.age;
    this->email = other.email;
    this->phoneno = other.phoneno;
    this->dl_number = other.dl_number;
    this->total_number_days = other.total_number_days;
    this->total_amount = other.total_amount;
    this->total_damage = other.total_damage;
    this->current_rents = other.current_rents;
    this->allowed_rents = other.allowed_rents;
    this->sales = other.sales;
}

void Manager ::list_cars()
{
    print("No.", "License Plate", "Maker", "Model", "onRent", "Rented To", "Per Day", "Per KM");
    cout << line_break;
    int count = 1;
    for (int i = 0; i < cars.size(); i++)
    {
        print(to_string((count)), cars[i].dl_number, cars[i].make, cars[i].model, cars[i].onRent, cars[i].renter_user_id, cars[i].base_charge, cars[i].km_charge);
        count++;
    }
}

void Manager ::add_customer()
{
    vector<vector<string>> users_list = read_csv("databases/customer.csv");
    string values[8];

    values[0] = "U" + to_string(stoi(users_list[(users_list.size() - 1)][0].substr(1, users_list[(users_list.size() - 1)][0].size() - 1)) + 1);
    cout << "| >> Enter your name: ";
    cin.ignore(1000, '\n');
    getline(cin, values[1]);
    while (values[1].length() < 3 || values[1].length() > 20)
    {
        cout << "| >> Invalid, enter again (Too Smol/Too Huge): ";
        getline(cin, values[1]);
    }
    cout << "| >> Enter your password: ";
    getline(cin, values[2]);
    while (values[2].length() < 5 || values[2].length() > 20)
    {
        cout << "| >> Choose a stronger password, between 5 and 20 characters: ";
        getline(cin, values[2]);
    }
    cout << "| >> Choose your gender (1: male, 2: female, 3: other): ";
    cin >> values[3];
    while (values[3] != "1" & values[3] != "2" & values[3] != "3")
    {
        cout << "| >> Invalid, enter again : ";
        cin >> values[3];
    }
    cout << "| >> Enter your age: ";
    cin >> values[4];
    while (values[4].length() < 1 || values[4].length() > 3 || !is_number(values[4]))
    {
        cout << "| >> Invalid, enter again : ";
        cin >> values[4];
    }
    cout << "| >> Enter your phone number: ";
    cin >> values[5];
    while (values[5].length() != 10 || !is_number(values[5]))
    {
        cout << "| >> Invalid, enter again : ";
        cin >> values[5];
    }
    cout << "| >> Enter your email: ";
    cin >> values[6];
    while (values[6].length() < 5 || values[6].length() > 30)
    {
        cout << "| >> Invalid, enter again : ";
        cin >> values[6];
    }
    cout << "| >> Enter your driving license number: ";
    cin >> values[7];
    while (values[7].length() < 5 || values[7].length() > 20)
    {
        cout << "| >> Invalid, enter again : ";
        cin >> dl_number;
    }

    vector<string> data;
    data.push_back(values[0]);
    data.push_back(values[2]);
    data.push_back(values[1]);
    data.push_back(values[3]);
    data.push_back(values[4]);
    data.push_back(values[5]);
    data.push_back(values[6]);
    data.push_back(values[7]);
    data.push_back("C");
    write_csv_line("databases/customer.csv", data);
    print("Registered successfully");
    print("Your user_id is: " + values[0]);
    print("Please remember it for future use");
    print("Added successfully");
    return;
    return;
}
void Manager ::add_employee()
{
    vector<vector<string>> users_list = read_csv("databases/employee.csv");
    string values[8];

    values[0] = "E" + to_string(stoi(users_list[(users_list.size() - 1)][0].substr(1, users_list[(users_list.size() - 1)][0].size() - 1)) + 1);
    cout << "| >> Enter your name: ";
    cin.ignore(1000, '\n');
    getline(cin, values[1]);
    while (values[1].length() < 3 || values[1].length() > 20)
    {
        cout << "| >> Invalid, enter again (Too Smol/Too Huge): ";
        getline(cin, values[1]);
    }
    cout << "| >> Enter your password: ";
    getline(cin, values[2]);
    while (values[2].length() < 5 || values[2].length() > 20)
    {
        cout << "| >> Choose a stronger password, between 5 and 20 characters: ";
        getline(cin, values[2]);
    }
    cout << "| >> Choose your gender (1: male, 2: female, 3: other): ";
    cin >> values[3];
    while (values[3] != "1" & values[3] != "2" & values[3] != "3")
    {
        cout << "| >> Invalid, enter again : ";
        cin >> values[3];
    }
    cout << "| >> Enter your age: ";
    cin >> values[4];
    while (values[4].length() < 1 || values[4].length() > 3 || !is_number(values[4]))
    {
        cout << "| >> Invalid, enter again : ";
        cin >> values[4];
    }
    cout << "| >> Enter your phone number: ";
    cin >> values[5];
    while (values[5].length() != 10 || !is_number(values[5]))
    {
        cout << "| >> Invalid, enter again : ";
        cin >> values[5];
    }
    cout << "| >> Enter your email: ";
    cin >> values[6];
    while (values[6].length() < 5 || values[6].length() > 30)
    {
        cout << "| >> Invalid, enter again : ";
        cin >> values[6];
    }
    cout << "| >> Enter your driving license number: ";
    cin >> values[7];
    while (values[7].length() < 5 || values[7].length() > 20)
    {
        cout << "| >> Invalid, enter again : ";
        cin >> dl_number;
    }

    vector<string> data;
    data.push_back(values[0]);
    data.push_back(values[2]);
    data.push_back(values[1]);
    data.push_back(values[3]);
    data.push_back(values[4]);
    data.push_back(values[5]);
    data.push_back(values[6]);
    data.push_back(values[7]);
    data.push_back("E");
    write_csv_line("databases/employee.csv", data);
    print("Registered successfully");
    print("Your user_id is: " + values[0]);
    print("Please remember it for future use");
    print("Added successfully");
    return;
}

void Manager ::remove_employee()
{
    cout << "| >> Enter user_id of the employee to be removed: ";
    string user_id;
    cin >> user_id;
    get_user_data();
    int i = 0;
    for (i = 0; i < users.size(); i++)
    {
        if (users[i].user_id == user_id)
        {
            if (users[i].type == "E")
            {
                users.erase(users.begin() + i, users.begin() + i + 1);
                write_user_data();
                print("Employee removed successfully");
                return;
            }
            else
            {
                print("User is not an employee");
                return;
            }
        }
    }
    if (i == users.size())
    {
        print("Employee not found.");
        return;
    }
}

void Manager ::remove_customer()
{
    cout << "| >> Enter user_id of the customer to be removed: ";
    string user_id;
    cin >> user_id;
    get_user_data();
    int i = 0;
    for (i = 0; i < users.size(); i++)
    {
        if (users[i].user_id == user_id)
        {
            if (users[i].type == "C")
            {
                users.erase(users.begin() + i, users.begin() + i + 1);
                write_user_data();
                print("Customer removed successfully");
                return;
            }
            else
            {
                print("User is not an customer");
                return;
            }
        }
    }
    if (i == users.size())
    {
        print("Customer not found.");
        return;
    }
}

void Manager ::add_car()
{
    Car car;
    vector<string> car_details = car.getcardetails();
    car.updatecardetails(car_details);
    car.writetocardatabase("databases/car.csv");
}

void Manager ::remove_car()
{
    cout << "| >> Enter License Plate Number of the car to be removed: ";
    string license_plate;
    cin >> license_plate;
    int i = 0;
    for (i = 0; i < cars.size(); i++)
    {
        if (cars[i].dl_number == license_plate)
        {
            if (cars[i].onRent == "y")
            {
                print("Car is currently rented, cannot be removed");
                return;
            }
            cars.erase(cars.begin() + i, cars.begin() + i + 1);

            vector<vector<string>> cars_list;
            for (int i = 0; i < cars.size(); i++)
            {
                cars_list.push_back(cars[i].cardetails());
            }
            write_csv("databases/car.csv", cars_list);
            print("Car removed successfully");
            return;
        }
    }
    if (i == cars.size())
    {
        print("Car not found");
    }
}

void Manager ::update_employee()
{
    cout << "| >> Enter user_id of the employee to be updated: ";
    string user_id;
    cin >> user_id;
    get_user_data();
    int i = 0;
    for (i = 0; i < users.size(); i++)
    {
        if (users[i].user_id == user_id)
        {
            if (users[i].type == "E")
            {
                int choice;
                do
                {
                    cout << line_break;
                    print("Parameters to update.");
                    print("1. Name");
                    print("2. Gender");
                    print("3. Age");
                    print("4. Mobile Number");
                    print("5. email");
                    print("6. Driving License Number");
                    print("7. Save and Exit");

                    cout << "| >> Enter your choice: ";
                    if (!(cin >> choice))
                    {
                        cin.clear();                                                   // clears the error state
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // remove the bad input from the buffer
                        print("Invalid Choice");
                    }
                    else
                    {
                        string inp;
                        if (choice == 1)
                        {
                            cout << "| >> Enter your name: ";
                            cin.ignore(1000, '\n');
                            getline(cin, inp);
                            while (inp.length() < 3 || inp.length() > 20)
                            {
                                cout << "| >> Invalid, enter again (Too Smol/Too Huge): ";
                                getline(cin, inp);
                            }
                            users[i].name = inp;
                        }
                        else if (choice == 2)
                        {
                            cout << "| >> Choose your gender (1: male, 2: female, 3: other): ";
                            cin >> inp;
                            while (inp != "1" & inp != "2" & inp != "3")
                            {
                                cout << "| >> Invalid, enter again : ";
                                cin >> inp;
                            }
                            users[i].gender = inp;
                        }
                        else if (choice == 3)
                        {
                            cout << "| >> Enter your age: ";
                            cin >> inp;
                            while (inp.length() < 1 || inp.length() > 3 || !is_number(inp))
                            {
                                cout << "| >> Invalid, enter again : ";
                                cin >> inp;
                            }
                            users[i].age = inp;
                        }
                        else if (choice == 4)
                        {
                            cout << "| >> Enter your phone number: ";
                            cin >> inp;
                            while (inp.length() != 10 || !is_number(inp))
                            {
                                cout << "| >> Invalid, enter again : ";
                                cin >> inp;
                            }
                            users[i].phoneno = inp;
                        }
                        else if (choice == 5)
                        {
                            cout << "| >> Enter your email: ";
                            cin >> inp;
                            while (inp.length() < 5 || inp.length() > 30)
                            {
                                cout << "| >> Invalid, enter again : ";
                                cin >> inp;
                            }
                            users[i].email = inp;
                        }
                        else if (choice == 6)
                        {
                            cout << "| >> Enter your driving license number: ";
                            cin >> inp;
                            while (inp.length() < 5 || inp.length() > 20)
                            {
                                cout << "| >> Invalid, enter again : ";
                                cin >> inp;
                            }
                            users[i].dl_number = inp;
                        }
                        else if (choice == 7)
                        {
                            break;
                        }
                        else
                        {
                            print("Invalid choice");
                            cout << line_break;
                        }
                    }

                } while (choice != 7);
                write_user_data();
            }
            else
            {
                print("User is not an employee");
                return;
            }
        }
    }
    if (i == users.size())
    {
        print("Employee not found");
        return;
    }
}

void Manager ::update_customer()
{
    cout << "| >> Enter user_id of the customer to be updated: ";
    string user_id;
    cin >> user_id;
    int i = 0;
    get_user_data();
    for (i = 0; i < users.size(); i++)
    {
        if (users[i].user_id == user_id)
        {
            if (users[i].type == "C")
            {
                int choice;
                do
                {
                    cout << line_break;
                    print("Parameters to update.");
                    print("1. Name");
                    print("2. Gender");
                    print("3. Age");
                    print("4. Mobile Number");
                    print("5. email");
                    print("6. Driving License Number");
                    print("7. Save and Exit");

                    cout << "| >> Enter your choice: ";
                    if (!(cin >> choice))
                    {
                        cin.clear();                                                   // clears the error state
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // remove the bad input from the buffer
                        print("Invalid Choice");
                    }
                    else
                    {
                        string inp;
                        if (choice == 1)
                        {
                            cout << "| >> Enter your name: ";
                            cin.ignore(1000, '\n');
                            getline(cin, inp);
                            while (inp.length() < 3 || inp.length() > 20)
                            {
                                cout << "| >> Invalid, enter again (Too Smol/Too Huge): ";
                                getline(cin, inp);
                            }
                            users[i].name = inp;
                        }
                        else if (choice == 2)
                        {
                            cout << "| >> Choose your gender (1: male, 2: female, 3: other): ";
                            cin >> inp;
                            while (inp != "1" & inp != "2" & inp != "3")
                            {
                                cout << "| >> Invalid, enter again : ";
                                cin >> inp;
                            }
                            users[i].gender = inp;
                        }
                        else if (choice == 3)
                        {
                            cout << "| >> Enter your age: ";
                            cin >> inp;
                            while (inp.length() < 1 || inp.length() > 3 || !is_number(inp))
                            {
                                cout << "| >> Invalid, enter again : ";
                                cin >> inp;
                            }
                            users[i].age = inp;
                        }
                        else if (choice == 4)
                        {
                            cout << "| >> Enter your phone number: ";
                            cin >> inp;
                            while (inp.length() != 10 || !is_number(inp))
                            {
                                cout << "| >> Invalid, enter again : ";
                                cin >> inp;
                            }
                            users[i].phoneno = inp;
                        }
                        else if (choice == 5)
                        {
                            cout << "| >> Enter your email: ";
                            cin >> inp;
                            while (inp.length() < 5 || inp.length() > 30)
                            {
                                cout << "| >> Invalid, enter again : ";
                                cin >> inp;
                            }
                            users[i].email = inp;
                        }
                        else if (choice == 6)
                        {
                            cout << "| >> Enter your driving license number: ";
                            cin >> inp;
                            while (inp.length() < 5 || inp.length() > 20)
                            {
                                cout << "| >> Invalid, enter again : ";
                                cin >> inp;
                            }
                            users[i].dl_number = inp;
                        }
                        else if (choice == 7)
                        {
                            break;
                        }
                        else
                        {
                            print("Invalid choice");
                            cout << line_break;
                        }
                    }

                } while (choice != 7);
                write_user_data();
            }
            else
            {
                print("User is not an Customer");
                return;
            }
        }
    }
    if (i == users.size())
    {
        print("Customer not found");
        return;
    }
}

void Manager ::manager_menu()
{
    cout << line_break;
    int choice = 0;
    cout << "Welcome " << this->name << "!" << endl;
    do
    {
        cout << line_break;
        print(" 1. View Cars");
        print(" 2. Detailed Car Information");
        print(" 3. Search and Book Car");
        print(" 4. Book Car");
        print(" 5. View Booked Cars");
        print(" 6. View Dues");
        print(" 7. Clear Dues");
        print(" 8. Return Car");
        print(" 9. Add Employee");
        print(" 10. Remove Employee");
        print(" 11. Update Employee");
        print(" 12. Add Customer");
        print(" 13. Remove Customer");
        print(" 14. Update Customer");
        print(" 15. Add Car");
        print(" 16. Remove Car");
        print(" 17. Update Car Details");
        print(" 18. Fix Car");
        print(" 0. LogOut");
        print("");
        cout << "| >> Enter your choice: ";
        if (!(cin >> choice))
        {
            cin.clear();                                                   // clears the error state
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // remove the bad input from the buffer
            print("Invalid Choice");
        }
        else
        {
            switch (choice)
            {
            case 1:
                list_cars();
                break;
            case 2:
                car_details();
                break;
            case 3:
                search_cars();
                break;
            case 4:
                book_car();
                break;
            case 5:
                view_rented_cars();
                break;
            case 6:
                view_dues();
                break;
            case 7:
                clear_dues();
                break;
            case 8:
                return_car();
                break;
            case 9:
                add_employee();
                break;
            case 10:
                remove_employee();
                break;
            case 11:
                update_employee();
                break;
            case 12:
                add_customer();
                break;
            case 13:
                remove_customer();
                break;
            case 14:
                update_customer();
                break;
            case 15:
                add_car();
                break;
            case 16:
                remove_car();
                break;
            case 17:
                update_car_details();
                break;
            case 18:
                fix_car();
                break;
            case 0:
                logout();
                break;
            default:
                cout << "Invalid choice" << endl;
            }
        }
    } while (choice != 0);
}

void Manager ::logout()
{
    save_employee_data();
    vector<vector<string>> cars_list;
    for (int i = 0; i < cars.size(); i++)
    {
        cars_list.push_back(cars[i].cardetails());
    }
    write_csv("databases/car.csv", cars_list);
    print("Data Updated");
    print("Logged out Successfully");
}