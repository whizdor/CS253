#include "include_files.cpp"

int main()
{
    User user;
    int choice;
    Clear();
    cout << line_break;
    date.confirmDate();
    Clear();

    do
    {
        Clear();
        cout << "      ░▒▓███████▓▒░ ░▒▓████████▓▒░░▒▓███████▓▒░░▒▓████████▓▒░░▒▓██████▓▒░ ░▒▓█▓▒░" << endl;
        cout << "      ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░       ░▒▓█▓▒░░▒▓█▓▒░  ░▒▓█▓▒░   ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░" << endl;
        cout << "      ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░       ░▒▓█▓▒░░▒▓█▓▒░  ░▒▓█▓▒░   ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░" << endl;
        cout << "      ░▒▓███████▓▒░ ░▒▓██████▓▒░  ░▒▓█▓▒░░▒▓█▓▒░  ░▒▓█▓▒░   ░▒▓████████▓▒░░▒▓█▓▒░" << endl;
        cout << "      ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░       ░▒▓█▓▒░░▒▓█▓▒░  ░▒▓█▓▒░   ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░" << endl;
        cout << "      ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░       ░▒▓█▓▒░░▒▓█▓▒░  ░▒▓█▓▒░   ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░" << endl;
        cout << "      ░▒▓█▓▒░░▒▓█▓▒░░▒▓████████▓▒░░▒▓█▓▒░░▒▓█▓▒░  ░▒▓█▓▒░   ░▒▓█▓▒░░▒▓█▓▒░░▒▓████████▓▒░" << endl;
        cout << endl;
        cout << endl;
        cout << line_break;
        date.printDate();
        cout << line_break;
        print(" 1. Register");
        print(" 2. Login");
        print(" 3. Exit");
        print("");
        cout << "| >> Enter your choice: ";
        if (!(cin >> choice))
        {
            cin.clear();                                                   // clears the error state
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // remove the bad input from the buffer
            print("Invalid Choice");
            Clear();
        }
        else
        {
            if (choice == 1)
            {
                user.registeration();
            }
            else if (choice == 2)
            {
                user.login();
            }
            else if (choice == 3)
            {
                cout << line_break;
                print("Have a great driving experence. Thanks!");
                cout << line_break;
                return 0;
            }
            else
            {
                print("Invalid choice");
                Clear();
            }
        }
    } while (choice != 3);
}