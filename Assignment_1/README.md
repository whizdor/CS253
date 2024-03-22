# Rental System

## Description

This is a car rental system that allows users to view, rent and return car. It leverages CSV files (comma-separated values) for data persistence, ensuring reliable storage and retrieval of car rental data.

## Installation

1. Clone the repository: `git clone https://github.com/whizdor/CS253_Assignment_1.git`
2. Compile the application using ` g++ --std=c++17 main.cpp -o main`
3. Run it by typing in `./main` on the terminal.

To kill the program use `Ctrl+C` on a linux based terminal.

## File Structure

The project follows the following file structure:

- `main.cpp`: The main source code file for the car rental system, which is responsible for inter-linking the various clasess and functions used througout the application.
- `src/`

  - `user.cpp` : This file contains functions that allow users to either login into thier respective classes, or register as a `customer`.
  - `classes.hpp` : This file defines all the classes used in this application, that includes, `Car`, `Customer`, `Employee`, `Manager` and a few auxillary functions to handle print and database operations.
  - `<classes>.cpp` : These files contain the functions relevant to their classes for better code organistion.
  - `print.cpp` : This file consists of four overloaded print functions. Each function takes different combinations of string arguments and prints them in a formatted table-like structure. It code uses loops and conditional statements to ensure proper formatting and alignment of the printed output.
  - `date.cpp` : Defines the `Date` Class, used for all time manipulations.
  - `database.cpp` : Helper functions to communicate with the csv databases, according to the location provided in the input.

- `databases/`
  - `cars.csv`: A CSV file that stores information about available cars.
  - `customer.csv`: A CSV file that stores information about registered customers.
  - `employee.csv`: A CSV file that stores information about registered customers.
  - `manager.csv`: A CSV file that stores information about manager customers.
- `data/`
  - This folder contains individual files for every user, which has information regarding their `dues` and `attributes` which help the program determing the number of cars they can further book.

## `Car` Class

The Car class has several member variables that represent different attributes of a car, such as license plate number, make, model, year, seats, power source, transmission, dents, scratches, and more. These variables store the details of a car object.

### Constructor

- The default constructor initializes all the member variables with empty values.
- The second constructor takes a vector of strings as input and assigns the values from the vector to the member variables. This constructor is useful for creating a car object with pre-existing data.
- The third constructor is a copy constructor that creates a new car object by copying the values from another car object.

### Functions

- `getcardetails` : It function prompts the user to enter various details of a car and validates the user input and stores the entered values in the member variables of the car object. Finally, it returns a vector containing all the car details.
- `updatecardetails` : It takes a vector of strings as input and updates the member variables of the car object with the values from the vector.
- `cardetails` function returns a vector containing all the car details stored in the member variables of the car object.
- `printcardetails` function prints the car details to the console. It uses conditional statements to display the power source and transmission in a more readable format.
- `writetocardatabase` function creates a vector containing all the car details and then calls a helper function `write_csv_line` to write the vector as a line in the CSV file.

## `Date` Class

The `Date` class provides functionality for handling dates in a specific format (`dd-mm-yyyy`). It includes the following member functions:

- `getDate()`: Prompts the user to enter a date and validates the input according to the specified format.
- `printDate()`: Prints the current system date in the format `dd-mm-yyyy`.

The class utilizes the `struct tm` type from the C++ standard library to represent dates. It also uses the `strftime` and `gmtime` functions to format and retrieve the system date, respectively. The class ensures that the entered date is valid and handles leap years correctly.

## `User` Class

### Attributes

- `dl_number`: Driver's license number
- `make`: Car make
- `model`: Car model
- `year`: Car year
- `seats`: Number of seats in the car
- `power_source`: Power source of the car
- `transmission`: Transmission type of the car
- `dents`: Presence of dents on the car
- `scratches`: Presence of scratches on the car
- `tyre_condition`: Condition of the car's tires
- `light_condition`: Condition of the car's lights
- `miles_driven`: Number of miles driven by the car
- `onRent`: Indicates if the car is currently on rent
- `start_date`: Start date of the car rental period
- `end_date`: End date of the car rental period
- `renter_user_id`: User ID of the renter
- `employee_user_id`: User ID of the employee
- `base_charge`: Base charge for renting the car
- `km_charge`: Charge per kilometer driven
- `late_charge`: Late charge for returning the car late

### Functions

This file includes three relevant function implementations: `get_user_data()`, `user_data()`, and `login()`.

- `get_user_data()`: This function is responsible for retrieving user data from a database and populating the `users` vector with `User` objects. It performs the following steps:

  - Clears the `users` vector to ensure it is empty before populating it.
  - Calls the `read_customers_db()` function to retrieve a list of user data from a database. The returned data is a 2D vector, where each inner vector represents the data for a single user.
  - Iterates over the `users_list` vector and creates a new `User` object for each user's data. The `User` object is initialized using the `User(vector<string> data)` constructor, which takes a vector of strings representing the user's data.
  - Adds the newly created `User` object to the `users` vector.

- `user_data()`: This function returns a vector of strings representing the data of a `User` object. It simply creates a new vector, adds the user's data fields (`user_id`, `password`, `name`, etc.) to the vector, and then returns it.

- `login()`: This function handles the user login process. It prompts the user to enter their `user_id` and password, validates the input against the stored user data, and performs the appropriate actions based on the user's type (customer, employee, or manager).

## `Customer` Class

The `Customer` class is a derived class from the `User` base class, which means it inherits all the public and protected members of the `User` class. This class represents a customer in a car rental system.

### Attribures

- `total_number_days`: This could represent the total number of days a customer has rented cars.
- `total_amount`: This represents the total amount a customer has paid for car rentals.
- `total_damage`: This represents the total cost of damages a customer has caused to rented cars.
- `current_rents`: This represents the number of cars currently rented by the customer.
- `allowed_rents`: This represents the number of cars a customer is allowed to rent, initially set up to -
- `cars`: This is a vector of `Car` objects, which is a list of all the cars availabe with the system.

### Functions

- `Customer()`, `Customer(vector<string> data)`,`~Customer()`, and `Customer(const Customer &other)`: These are the constructor, parameterized constructor, destructor, and copy constructor of the `Customer` class, respectively.
- `get_saved_data(string user_id)`: This method retrieves the saved data of a customer from the `data/` folder
- `check_eligibility()`: This method checks if a customer is eligible to rent a car.
- `save_customer_data()` : This method saves the data of a customer to `data/` folder.
- `open_cars_database()`
- `search_cars()`: This method allows a customer to search for cars.
- `view_rented_cars()` :This method allows a customer to view the cars they have rented.
- `update_customer()` : This method updates the data of a customer.
- `view_bill(vector<string> data)`: This method allows a customer to view their bill.
- `book_car(int)` and `book_car()`: These methods allow a customer to book a car.
- `list_cars()`: This method lists all the cars available for rent.
- `view_dues()`: This method allows a customer to view their dues.
- `clear_dues()`: This method allows a customer to clear their dues.
- `car_details()`: This method shows the details of a car.
- `return_car()`: This method allows a customer to return a rented car.
- `CustomerMenu()`: This method displays the customer menu.
- `logout()`: This method logs out the customer, and saves all the data.

This class encapsulates all the data and behaviors related to a customer in the car rental system.

## `Employee` Class

The `Employee` class is a derived class from the `Customer` base class, which means it inherits all the public and protected members of the `Customer` class.

### Attributes

- `sales` : The total amount of sales that the employee has caused.

### Functions

- `save_employee_data()`: This function saves the employee's data (such as total number of days, total amount, total damage, etc.) to a CSV file.
- `return_car()`: This function allows the employee to return a rented car.
- `view_dues()`: This function displays the dues (payment details) for the employee. It reads the dues data from a CSV file and calculates the base cost, kilometer cost, fine, and total amount for each due. It then displays the dues along with the calculated amounts.
- `clear_dues()`: This function allows the employee to clear dues.
- `fix_car()` : Allows employee to fix a car to its factory state that is with no damanges.
- `update_car_details()` : Allows employee to update the detauls of a car.

This class encapsulates all the data and behaviors related to a employee in the car rental system.

## `Manager` Class

The `Manager` class is a derived class from the `Employee` base class, which means it inherits all the public and protected members of the `Employee` class.

### Functions

- `list_cars()`: This function is responsible for listing the cars associated with the users that have rented them.

- `add_employee()`, `remove_employee()`, `update_employee()`: These functions are used to add, remove, and update employee information.

- `add_car()`, `remove_car()`: These functions are used to add and remove cars.

- `add_customer()`, `remove_customer()`, `update_customer()`: These functions are used to add, remove, and update customer information.

- `logout()`: This function is responsible for logging out the manager.

This class encapsulates all the data and behaviors related to a manager in the car rental system.
