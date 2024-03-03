#include "classes.hpp"

Employee ::Employee()
{
    this->total_number_days = "0";
    this->total_amount = "0";
    this->total_damage = "0";
    this->current_rents = "0";
    this->allowed_rents = "5.0";
    this->sales = "0";
}

Employee ::~Employee()
{
    // Destructor
}

void Employee ::save_employee_data()
{
    vector<string> data;
    data.push_back(total_number_days);
    data.push_back(total_amount);
    data.push_back(total_damage);
    data.push_back(current_rents);
    data.push_back(allowed_rents);
    data.push_back(sales);
    write_csv_line_clear("data/" + user_id + "_data.csv", data);
}

Employee ::Employee(vector<string> data)
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

Employee ::Employee(const Employee &other)
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

void Employee ::return_car()
{
    cout << "| >> Enter License plate number: ";
    string car_id;
    cin >> car_id;
    for (int i = 0; i < cars.size(); i++)
    {
        if (cars[i].dl_number == car_id)
        {
            if (cars[i].onRent == "n")
            {
                print("Car is not booked");
                return;
            }
            else
            {
                cout << "| >> Enter end date: " << endl;
                Date eDate;
                Date sDate(cars[i].start_date);
                Date eDates(cars[i].end_date);
                eDate.getDate();
                eDate.saveDate();
                while (eDate.compareDate(eDates) == 0)
                {
                    print(">> Invalid Date.");
                    eDate.getDate();
                    eDate.saveDate();
                }
                cout << "| >> Enter miles driven: ";
                string miles_driven;
                cin >> miles_driven;
                while (!is_number(miles_driven))
                {
                    cout << "| >> Invalid, enter again : ";
                    cin >> miles_driven;
                }
                cout << "| >> Enter number of dents now: ";
                string dents;
                cin >> dents;
                while (stoi(dents) < stoi(cars[i].dents) || !is_number(dents))
                {
                    cout << "| >> Invalid, dents must be greater than original state: ";
                    cin >> dents;
                }
                cout << "| >> Enter number of scratches now, : ";
                string scratches;
                cin >> scratches;
                while (stoi(scratches) < stoi(cars[i].scratches) || !is_number(scratches))
                {
                    cout << "| >> Invalid, scratches must be greater than original state: ";
                    cin >> scratches;
                }
                cout << "| >> Enter tyre condition now (Scale of 0-100): ";
                string tyre_condition;
                cin >> tyre_condition;
                while (stoi(tyre_condition) > stoi(cars[i].tyre_condition) || !is_number(tyre_condition))
                {
                    cout << "| >> Invalid, tyre condition must be lesser than original state: ";
                    cin >> tyre_condition;
                }
                cout << "| >> Enter light condition now (Scale of 0-100): ";
                string light_condition;
                cin >> light_condition;
                while (stoi(light_condition) > stoi(cars[i].light_condition) || !is_number(light_condition))
                {
                    cout << "| >> Invalid, light condition must be lesser than original state: ";
                    cin >> light_condition;
                }

                int k;
                for (k = 0; k < users.size(); k++)
                {
                    if (users[k].user_id == cars[k].renter_user_id)
                    {
                        break;
                    }
                }
                Customer c(users[k].user_data());

                // Calculating the damage
                int damage = (stoi(dents) - stoi(cars[i].dents)) + (stoi(scratches) - stoi(cars[i].scratches));
                damage += -(stoi(tyre_condition) - stoi(cars[i].tyre_condition)) - (stoi(light_condition) - stoi(cars[i].light_condition));
                int temp = stoi(total_damage);
                temp += damage;
                c.total_damage = to_string(temp);

                // Updating the total number of days
                temp = stoi(total_number_days);
                temp += eDate.difference(sDate);
                c.total_number_days = to_string(temp);

                // Updating eligible rents
                float tempf = stof(allowed_rents);
                tempf = tempf - damage / 10.0 + 1.0;
                if (tempf < 0)
                {
                    tempf = 0;
                }
                c.allowed_rents = to_string(tempf);

                temp = stoi(current_rents);
                temp -= 1;
                c.current_rents = to_string(temp);
                c.write_user_data();

                // Updating car data
                cars[i].dents = dents;
                cars[i].scratches = scratches;
                cars[i].tyre_condition = tyre_condition;
                cars[i].light_condition = light_condition;

                string returning_user_id = cars[i].renter_user_id;

                vector<string> car_data;

                car_data.push_back(cars[i].dl_number);
                car_data.push_back(cars[i].start_date);
                car_data.push_back(eDate.stringdate);
                car_data.push_back(miles_driven);
                car_data.push_back(to_string(eDate.difference(sDate)));
                car_data.push_back(to_string(eDate.difference(eDates)));
                car_data.push_back(cars[i].base_charge);
                car_data.push_back(cars[i].km_charge);
                car_data.push_back(cars[i].late_charge.substr(0, cars[i].late_charge.length() - 1));
                car_data.push_back(cars[i].employee_user_id);

                string temps = to_string(stoi(cars[i].miles_driven) + stoi(miles_driven));

                cars[i].miles_driven = "" + temps;
                cars[i].onRent = "n";
                cars[i].start_date = "0";
                cars[i].end_date = "0";
                cars[i].renter_user_id = "0";
                cars[i].employee_user_id = "0";

                vector<vector<string>> cars_list;
                for (int i = 0; i < cars.size(); i++)
                {
                    cars_list.push_back(cars[i].cardetails());
                }
                write_csv("databases/car.csv", cars_list);
                write_csv_line("data/" + returning_user_id + "_dues.csv", car_data);
                print("Car returned successfully.");
                return;
            }
        }
    }
}

void Employee ::view_dues()
{
    vector<vector<string>> user_dues = read_csv("data/" + user_id + "_dues.csv");
    if (user_dues.size() == 0)
    {
        print("No dues to show");
    }
    else
    {
        print("No", "License Plate", "Start Date", "End Date", "Day", "KM", "Fine", "Total");
        for (int i = 0; i < user_dues.size(); i++)
        {
            int base_cost = stoi(user_dues[i][4]) * stoi(user_dues[i][6]);
            int km_cost = 0;
            if (stoi(user_dues[i][3]) > 100)
            {
                km_cost = (stoi(user_dues[i][3]) - 100) * stoi(user_dues[i][7]) / 20;
            }
            int fine = stoi(user_dues[i][5]) * stoi(user_dues[i][8]);
            int total = base_cost + km_cost + fine;
            total = total * 0.85;
            if (user_dues[i].size() == 10)
            {
                user_dues[i].push_back(to_string(base_cost));
                user_dues[i].push_back(to_string(km_cost));
                user_dues[i].push_back(to_string(fine));
                user_dues[i].push_back(to_string(total));
            }
            else
            {
                user_dues[i][10] = to_string(base_cost);
                user_dues[i][11] = to_string(km_cost);
                user_dues[i][12] = to_string(fine);
                user_dues[i][13] = to_string(total);
            }
            print(to_string(i + 1), user_dues[i][0], user_dues[i][1], user_dues[i][2], user_dues[i][10], user_dues[i][11], user_dues[i][12], user_dues[i][13]);
        }
        write_csv("data/" + user_id + "_dues.csv", user_dues);
    }
}

void Employee ::clear_dues()
{
    view_dues();
    vector<vector<string>> user_dues = read_csv("data/" + user_id + "_dues.csv");
    if (user_dues.size() == 0)
    {
        return;
    }
    cout << "| >> Enter index number to clear dues: ";
    int index;
    cin >> index;
    while (index > user_dues.size() || index < 1)
    {
        cout << "| >> Invalid, enter again: ";
        cin >> index;
    }
    // Update the total amount for user parameters.
    int temp = stoi(total_amount);
    temp += stoi(user_dues[index - 1][13]);
    total_amount = to_string(temp);

    float tempf = stof(allowed_rents);
    tempf = tempf + stoi(user_dues[index - 1][13]) / 100000.0;
    allowed_rents = to_string(tempf);
    cout << "| >> Do you want a detailed bill (y/n): ";
    char choice;
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
        view_bill(user_dues[index - 1]);
    }
    user_dues.erase(user_dues.begin() + index - 1);
    write_csv("data/" + user_id + "_dues.csv", user_dues);
}

void Employee ::update_employee()
{
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
                    print("2. Password");
                    print("3. Gender");
                    print("4. Age");
                    print("5. Mobile Number");
                    print("6. email");
                    print("7. Driving License Number");
                    print("8. Save and Exit");

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
                            cout << "| >> Enter your name: " << endl;
                            cout << "| >> (Press Enter to Continue) " << endl;
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
                            cout << "| >> Enter your password: " << endl;
                            cout << "| >> (Press Enter to Continue) " << endl;
                            cin.ignore(1000, '\n');
                            getline(cin, inp);
                            while (inp.length() < 5 || inp.length() > 20)
                            {
                                cout << "| >> Choose a stronger password, between 5 and 20 characters: ";
                                getline(cin, inp);
                            }
                            users[i].update_password(inp);
                        }
                        else if (choice == 3)
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
                        else if (choice == 4)
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
                        else if (choice == 5)
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
                        else if (choice == 6)
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
                        else if (choice == 7)
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
                        else if (choice == 8)
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
                print("User is not an Employee");
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

void Employee ::update_car_details()
{
    cout << "| Enter License plate number : ";
    string car_id;
    cin >> car_id;
    for (int i = 0; i < cars.size(); i++)
    {
        if (cars[i].dl_number == car_id)
        {
            cout << line_break;
            cars[i].printcardetails();
            cout << line_break;
            int choice;
            do
            {
                print("Conditions to update.");
                print("1. Dents");
                print("2. Scratches");
                print("3. Tyre Condition");
                print("4. Light Condition");
                print("5. Save and Exit");

                cout << "| >> Enter your choice : ";

                if (!(cin >> choice))
                {
                    cin.clear();                                                   // clears the error state
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // remove the bad input from the buffer
                    print("Invalid Choice");
                }
                else
                {
                    string condition;
                    if (choice == 1)
                    {
                        cout << "| >> Enter the condition of the dents : ";
                        cin >> condition;
                        while (is_number(condition) == false || stoi(condition) < 0)
                        {
                            cout << "| >> Invalid, enter again : ";
                            cin >> condition;
                        }
                        cars[i].dents = condition;
                    }
                    else if (choice == 2)
                    {
                        cout << "| >> Enter the condition of the scratches : ";
                        cin >> condition;
                        while (is_number(condition) == false || stoi(condition) < 0)
                        {
                            cout << "| >> Invalid, enter again : ";
                            cin >> condition;
                        }
                        cars[i].scratches = condition;
                    }
                    else if (choice == 3)
                    {
                        cout << "| >> Enter the condition of the tyres on a scale of 1-100 : ";
                        cin >> condition;
                        while (is_number(condition) == false || stoi(condition) < 0 || stoi(condition) > 100)
                        {
                            cout << "| >> Invalid, enter again : ";
                            cin >> condition;
                        }
                        cars[i].tyre_condition = condition;
                    }
                    else if (choice == 4)
                    {
                        cout << "| >> Enter the condition of the lights on a scale of 1-100 : ";
                        cin >> condition;
                        while (is_number(condition) == false || stoi(condition) < 0 || stoi(condition) > 100)
                        {
                            cout << "| >> Invalid, enter again : ";
                            cin >> condition;
                        }
                        cars[i].light_condition = condition;
                    }
                    else if (choice == 5)
                    {
                        break;
                    }
                    else
                    {
                        print("Invalid choice");
                        cout << line_break;
                    }
                }

            } while (choice != 5);
        }
    }
    print("Car Not Found");
}

void Employee ::fix_car()
{
    cout << "| Enter License plate number : ";
    string car_id;
    cin >> car_id;
    for (int i = 0; i < cars.size(); i++)
    {
        if (cars[i].dl_number == car_id)
        {
            cars[i].dents = "0";
            cars[i].scratches = "0";
            cars[i].tyre_condition = "100";
            cars[i].light_condition = "100";
            print("Car Fixed");
            return;
        }
    }
    print("Car Not Found");
    return;
}

void Employee ::logout()
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

void Employee ::EmployeeMenu()
{
    cout << line_break;
    int choice = 0;
    print("Welcome " + this->name + "!");
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
        print(" 9. Update Car Details");
        print("10. Fix Car");
        print("11. Update Profile");
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
                update_car_details();
                break;
            case 10:
                fix_car();
                break;
            case 11:
                update_employee();
                break;
            case 0:
                logout();
                break;
            default:
                cout << "| Invalid choice" << endl;
            }
        }
    } while (choice != 0);
}
