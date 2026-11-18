#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <sstream>
#include <cmath>

using namespace std;

void bloodReport(string bloodGroup);
string calculateDuration(string dateStr);

int main()
{
    string username, password;

    string correctUser = "Tanfir";
    string correctPass = "15624";

    cout << "Welcome to savedrops" << endl;
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    if (username == correctUser && password == correctPass)
    {
        cout << "Login Successful! Welcome, " << username << endl;

        int choice;
        while (true)
        {

            cout << "\n Main Menu \n";
            cout << "1. Search by Blood Group\n";
            cout << "2. Exit\n";
            cout << "Enter option: ";
            cin >> choice;

            if (choice == 1)
            {
                string bloodInput;
                cout << "Enter blood group: ";
                cin >> bloodInput;

                if (bloodInput=="O+"||bloodInput=="O-"||bloodInput=="A+"||bloodInput=="A-"||
                        bloodInput=="B+"||bloodInput=="B-"||bloodInput=="AB+"||bloodInput=="AB-")
                {
                    bloodReport(bloodInput);
                }
                else
                {
                    cout << "Invalid blood group!" << endl;
                }
            }
            else if (choice == 2)
            {
                cout << "Exiting... Thank you!" << endl;
                break;
            }
            else
            {
                cout << "Invalid option!" << endl;
            }
        }
    }
    else
    {
        cout << "Access Denied! Incorrect Username or Password" << endl;
    }

    return 0;
}

void bloodReport(string bloodGroup)
{
    string bloodFile = bloodGroup + ".txt";
    ifstream file(bloodFile);

    if (!file)
    {
        cout << "File not found!" << endl;
        return;
    }

    string line;
    while (getline(file, line))
    {
        if (line.find("Validation") != string::npos)
        {
            int pos = line.find(':');
            string datePart = line.substr(pos + 1);
            cout << "Validation: " << calculateDuration(datePart) << endl;
        }
        else
        {
            cout << line << endl;
        }
    }

    file.close();
}

string calculateDuration(string dateStr)
{
    int day = 0, month = 0, year = 0;
    char dot;

    stringstream ss(dateStr);
    ss >> day >> dot >> month >> dot >> year;

    struct tm fileDate = {0};
    fileDate.tm_mday = day;
    fileDate.tm_mon  = month - 1;
    fileDate.tm_year = year - 1900;

    time_t now = time(0);
    time_t fileTime = mktime(&fileDate);

    long long totalSecs = abs(difftime(now, fileTime));
    int totalDays = totalSecs / 86400;

    string status = (totalDays > 120) ? " (Eligible)" : " (Not Eligible)";
    string result;

    if (totalDays >= 365)
    {
        int years = totalDays / 365;
        int months = (totalDays % 365) / 30;
        result = to_string(years) + " Years " + to_string(months) + " Months";
    }
    else if (totalDays >= 30)
    {
        int months = totalDays / 30;
        int days = totalDays % 30;
        result = to_string(months) + " Months " + to_string(days) + " Days";
    }
    else if (totalDays >= 1)
    {
        result = to_string(totalDays) + " Days";
    }
    else
    {
        result = "0 Days";
    }

    return result + status;
}