#include "classes.hpp"

Car::~Car()
{
    // Destructor
}

Car::Car()
{
    this->dl_number = "";
    this->make = "";
    this->model = "";
    this->year = "";
    this->seats = "";
    this->power_source = "";
    this->transmission = "";
    this->dents = "";
    this->scratches = "";
    this->tyre_condition = "";
    this->light_condition = "";
    this->miles_driven = "";
    this->onRent = "";
    this->start_date = "";
    this->end_date = "";
    this->renter_user_id = "";
    this->employee_user_id = "";
    this->base_charge = "";
    this->km_charge = "";
    this->late_charge = "";
}

Car::Car(vector<string> data)
{
    this->dl_number = data[0];
    this->make = data[1];
    this->model = data[2];
    this->year = data[3];
    this->seats = data[4];
    this->power_source = data[5];
    this->transmission = data[6];
    this->dents = data[7];
    this->scratches = data[8];
    this->tyre_condition = data[9];
    this->light_condition = data[10];
    this->miles_driven = data[11];
    this->onRent = data[12];
    this->start_date = data[13];
    this->end_date = data[14];
    this->renter_user_id = data[15];
    this->employee_user_id = data[16];
    this->base_charge = data[17];
    this->km_charge = data[18];
    this->late_charge = data[19];
}

Car::Car(const Car &other)
{
    this->dl_number = other.dl_number;
    this->make = other.make;
    this->model = other.model;
    this->year = other.year;
    this->seats = other.seats;
    this->power_source = other.power_source;
    this->transmission = other.transmission;
    this->dents = other.dents;
    this->scratches = other.scratches;
    this->tyre_condition = other.tyre_condition;
    this->light_condition = other.light_condition;
    this->miles_driven = other.miles_driven;
    this->onRent = other.onRent;
    this->start_date = other.start_date;
    this->end_date = other.end_date;
    this->renter_user_id = other.renter_user_id;
    this->employee_user_id = other.employee_user_id;
    this->base_charge = other.base_charge;
    this->km_charge = other.km_charge;
    this->late_charge = other.late_charge;
}

vector<string> Car::getcardetails()
{
    vector<string> car;
    string car_id, maker, model, make_year, seats, power_source, transmission, dents, scratches, tyre_condition, lights, miles_driven, _onRent, _startday, _endday, _manager_id, _user_id, base_charge, charge_perkm, fine_perday;
    cout << "| >> Enter License plate number: ";
    cin >> car_id;
    car.push_back(car_id);
    cout << "| >> Enter maker : ";
    cin >> maker;
    car.push_back(maker);
    cout << "| >> Enter model : ";
    cin >> model;
    car.push_back(model);
    cout << "| >> Enter make_year : ";
    cin >> make_year;
    while (!is_number(make_year))
    {
        cout << "| >> Invalid Input, retry, : ";
        cin >> make_year;
    }
    car.push_back(make_year);
    cout << "| >> Enter seats : ";
    cin >> seats;
    while (!is_number(seats))
    {
        cout << "| >> Invalid Input, retry, : ";
        cin >> seats;
    }
    car.push_back(seats);
    cout << "| >> Enter power_source ('P' : Petrol, 'D' : Diesel, 'E' : Electric): ";
    cin >> power_source;
    while (power_source != "P" && power_source != "D" && power_source != "E")
    {
        cout << "| >> Invalid Input, retry, : ";
        cin >> power_source;
    }
    car.push_back(power_source);
    cout << "| >> Enter transmission ('A' : Automatic, 'M' : Manual): ";
    cin >> transmission;
    while (transmission != "A" && transmission != "M")
    {
        cout << "| >> Invalid Input, retry, : ";
        cin >> transmission;
    }
    car.push_back(transmission);
    cout << "| >> Enter dents: ";
    cin >> dents;
    while (!is_number(dents))
    {
        cout << "| >> Invalid Input, retry, : ";
        cin >> dents;
    }
    car.push_back(dents);
    cout << "| >> Enter scratches: ";
    cin >> scratches;
    while (!is_number(scratches))
    {
        cout << "| >> Invalid Input, retry, : ";
        cin >> scratches;
    }
    car.push_back(scratches);
    cout << "| >> Enter tyre_condition : ";
    cin >> tyre_condition;
    while (!is_number(tyre_condition))
    {
        cout << "| >> Invalid Input, retry, : ";
        cin >> tyre_condition;
    }
    car.push_back(tyre_condition);
    cout << "| >> Enter lights: ";
    cin >> lights;
    while (!is_number(lights))
    {
        cout << "| >> Invalid Input, retry, : ";
        cin >> lights;
    }
    car.push_back(lights);
    cout << "| >> Enter miles_driven : ";
    cin >> miles_driven;
    while (!is_number(miles_driven))
    {
        cout << "| >> Invalid Input, retry, : ";
        cin >> miles_driven;
    }
    car.push_back(miles_driven);
    cout << "| >> Enter _onRent (y/n): ";
    cin >> _onRent;
    while (_onRent != "y" && _onRent != "n")
    {
        cout << "| >> Invalid Input, retry, : ";
        cin >> _onRent;
    }
    car.push_back(_onRent);
    if (_onRent == "y")
    {
        cout << "| >> Enter _startday: ";
        cin >> _startday;
        cout << "| >> Enter _endday: ";
        cin >> _endday;
        cout << "| >> Enter customer_user_id: ";
        cin >> _user_id;
        User userr;
        while (userr.isUser(_user_id) != 3)
        {
            cout << "| >> Invalid User, enter again : ";
            cin >> _user_id;
        }
        cout << "| >> Enter employee_user_id: ";
        cin >> _manager_id;
        while (userr.isUser(_manager_id) != 2 && userr.isUser(_user_id) != 1)
        {
            cout << "| >> Invalid User, enter again : ";
            cin >> _manager_id;
        }
    }
    else
    {
        _startday = "0";
        _endday = "0";
        _user_id = "0";
        _manager_id = "0";
    }
    car.push_back(_startday);
    car.push_back(_endday);
    car.push_back(_user_id);
    car.push_back(_manager_id);
    cout << "| >> Enter base_charge: ";
    cin >> base_charge;
    while (!is_number(base_charge))
    {
        cout << "| >> Invalid Input, retry, : ";
        cin >> base_charge;
    }
    cout << "| >> Enter charge_perkm: ";
    cin >> charge_perkm;
    while (!is_number(charge_perkm))
    {
        cout << "| >> Invalid Input, retry, : ";
        cin >> charge_perkm;
    }
    cout << "| >> Enter fine_perday: ";
    cin >> fine_perday;
    while (!is_number(fine_perday))
    {
        cout << "| >> Invalid Input, retry, : ";
        cin >> fine_perday;
    }
    car.push_back(base_charge);
    car.push_back(charge_perkm);
    car.push_back(fine_perday);
    return car;
}

void Car::updatecardetails(vector<string> data)
{
    this->dl_number = data[0];
    this->make = data[1];
    this->model = data[2];
    this->year = data[3];
    this->seats = data[4];
    this->power_source = data[5];
    this->transmission = data[6];
    this->dents = data[7];
    this->scratches = data[8];
    this->tyre_condition = data[9];
    this->light_condition = data[10];
    this->miles_driven = data[11];
    this->onRent = data[12];
    this->start_date = data[13];
    this->end_date = data[14];
    this->renter_user_id = data[15];
    this->employee_user_id = data[16];
    this->base_charge = data[17];
    this->km_charge = data[18];
    this->late_charge = data[19];
}
vector<string> Car::cardetails()
{
    vector<string> car;
    car.push_back(this->dl_number);
    car.push_back(this->make);
    car.push_back(this->model);
    car.push_back(this->year);
    car.push_back(this->seats);
    car.push_back(this->power_source);
    car.push_back(this->transmission);
    car.push_back(this->dents);
    car.push_back(this->scratches);
    car.push_back(this->tyre_condition);
    car.push_back(this->light_condition);
    car.push_back(this->miles_driven);
    car.push_back(this->onRent);
    car.push_back(this->start_date);
    car.push_back(this->end_date);
    car.push_back(this->renter_user_id);
    car.push_back(this->employee_user_id);
    car.push_back(this->base_charge);
    car.push_back(this->km_charge);
    car.push_back(this->late_charge);
    return car;
}

void Car::printcardetails()
{
    print("License plate number: ", dl_number);
    print("Maker: ", make);
    print("Model: ", model);
    print("Year: ", year);
    print("Seats: ", seats);
    if (power_source == "P")
    {
        print("Power Source: ", "Petrol");
    }
    else if (power_source == "D")
    {
        print("Power Source: ", "Diesel");
    }
    else if (power_source == "E")
    {
        print("Power Source: ", "Electric");
    }
    if (transmission == "A")
    {
        print("Transmission: ", "Automatic");
    }
    else if (transmission == "M")
    {
        print("Transmission: ", "Manual");
    }
    print("Dents: ", dents);
    print("Scratches: ", scratches);
    print("Tyre Condition: ", tyre_condition);
    print("Light Condition: ", light_condition);
    print("Miles Driven: ", miles_driven);
    print("On Rent: ", onRent);
    print("Start Date: ", start_date);
    print("End Date: ", end_date);
    print("Base Charge (per day, 100 km): ", base_charge);
    print("KM Charge (per 20 kms): ", km_charge);
    print("Late Charge: ", to_string(stoi(late_charge)));
}

void Car::writetocardatabase(string filename)
{
    vector<string> car;
    car.push_back(this->dl_number);
    car.push_back(this->make);
    car.push_back(this->model);
    car.push_back(this->year);
    car.push_back(this->seats);
    car.push_back(this->power_source);
    car.push_back(this->transmission);
    car.push_back(this->dents);
    car.push_back(this->scratches);
    car.push_back(this->tyre_condition);
    car.push_back(this->light_condition);
    car.push_back(this->miles_driven);
    car.push_back(this->onRent);
    car.push_back(this->start_date);
    car.push_back(this->end_date);
    car.push_back(this->renter_user_id);
    car.push_back(this->employee_user_id);
    car.push_back(this->base_charge);
    car.push_back(this->km_charge);
    car.push_back(this->late_charge);
    write_csv_line(filename, car);
}