#include "classes.hpp"

vector<string> split(string str)
{
    char delimiter = ',';
    vector<string> internal;
    stringstream ss(str);
    string tok;
    while (getline(ss, tok, delimiter))
    {
        internal.push_back(tok);
    }
    return internal;
}

vector<vector<string> > read_customers_db()
{
    vector<vector<string> > data;
    ifstream file("databases/customer.csv");
    if (!file.is_open())
    {
        // cout << "Error: File not found" << endl;
        return data;
    }
    string line;
    while (getline(file, line))
    {
        data.push_back(split(line));
    }
    file.close();
    ifstream file2("databases/employee.csv");
    if (!file2.is_open())
    {
        // cout << "Error: File not found" << endl;
        return data;
    }
    while (getline(file2, line))
    {
        data.push_back(split(line));
    }
    file2.close();
    ifstream file3("databases/manager.csv");
    if (!file3.is_open())
    {
        // cout << "Error: File not found" << endl;
        return data;
    }
    while (getline(file3, line))
    {
        data.push_back(split(line));
    }
    file3.close();
    return data;
}

vector<vector<string> > read_csv(string filename)
{
    vector<vector<string> > data;
    ifstream file(filename);
    if (!file.is_open())
    {
        // cout << "Error: File not found" << endl;
        return data;
    }
    string line;
    while (getline(file, line))
    {
        data.push_back(split(line));
    }
    file.close();
    return data;
}

void write_csv_line(string filename, vector<string> data)
{
    ofstream file(filename, ios::app);
    for (int j = 0; j < data.size(); j++)
    {
        file << data[j];
        if (j != data.size() - 1)
        {
            file << ",";
        }
    }
    file << endl;
    file.close();
    return;
}

void write_csv_line_clear(string filename, vector<string> data)
{
    ofstream file(filename);
    for (int j = 0; j < data.size(); j++)
    {
        file << data[j];
        if (j != data.size() - 1)
        {
            file << ",";
        }
    }
    file.close();
    return;
}

void write_csv(string filename, vector<vector<string> > data)
{
    ofstream file(filename);
    file.clear();
    for (int i = 0; i < data.size(); i++)
    {
        for (int j = 0; j < data[i].size(); j++)
        {
            file << data[i][j];
            if (j != data[i].size() - 1)
            {
                file << ",";
            }
        }
        file << endl;
    }
    file.close();
    return;
}