// 2022-10-13
//  22:30 - 0:20
// 2022-10-16
//  13:30 - 19:51
//  21:44 - 22:22

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Person {
    public:
    string name;
    string surname;
    int age;
};

// string space2underscore(string text)
// {
//     replace(text.begin(), text.end(), ' ', '_');
//     return text;
// };

int main() {

bool opening_file;
opening_file = true;
string filetoread;
string filetoread2;
string line;
ifstream fileread;
vector <string> datavector;

while (opening_file)
{
    
    cout << "\nType name of the file to open (without extension name): ";
    getline(cin>>ws,filetoread);
    filetoread2 = filetoread + ".txt";

    fileread.open(filetoread2);
    if (fileread.is_open())
    {
        opening_file = false;
    }
    else
    {
        cout << "Could not acces file. Try again.";
    }
    while(getline(fileread, line)) 
        {
            datavector.push_back(line);    
        }
    fileread.close();
}

vector<vector<string>> datasplitvector;

for(int i = 0; i < datavector.size(); ++i)
{

    string line = datavector[i];
    istringstream iss(line);
    vector<string> linesplitvector;

    for(string s;iss>>s;)
    {
        linesplitvector.push_back(s);
    }

    if (linesplitvector.size() == 3)
    {
        int x;
        try 
        {
            x = stoi(linesplitvector[2]);
            datasplitvector.push_back(linesplitvector);
        }
        catch (invalid_argument) 
        {
            cout << "Expected age expressed as an integer in line: " << i+1 << endl;
        }
    }
    else if (linesplitvector.size() > 3)
    {
        cout << "Too many words in line number: " << i+1 << endl;
    }
    else if (linesplitvector.size() < 3)
    {
        cout << "Not enough words in line number: " << i+1 << endl;
    }
}

vector<Person> peoplevector;

for (int i = 0; i < datasplitvector.size(); ++i)
{
    Person guy;
    guy.name = datasplitvector[i][0];
    guy.surname = datasplitvector[i][1];
    guy.age = stoi(datasplitvector[i][2]);
    peoplevector.push_back(guy);
}

cout << "\nInitial list: \n";
for (int i = 0; i < peoplevector.size(); ++i)
{
    cout << "line nr: " << i+1 << " - " << peoplevector[i].name << " " << peoplevector[i].surname << " " << peoplevector[i].age << endl;
}
bool active1;
active1 = true;
bool active2;
bool age_flag;
bool line_flag;
while (active1)
{
    cout <<"\nDo you want to change, add or remove anything? Type 'YES' or 'NO': ";
    string x;
    // cin>>ws >> x;
    getline(cin>>ws, x);
    if (x=="YES")
    {
        cout << "ok yes" << endl;
        active2 = true;
        while (active2)
        {
            cout << "Type 'CHANGE', 'ADD' or 'REMOVE' respectively for action you want to perform: ";
            getline(cin>>ws, x);
            if (x=="CHANGE")
            {
                cout << "ok change" << endl;
                line_flag = true;                
                while (line_flag)
                {
                    cout << "Type number of line which you want to change: ";
                    string line_number_string;
                    int line_number_int;
                    getline(cin>>ws, line_number_string);
                    try
                    {
                        line_number_int = stoi(line_number_string)-1;
                        if (line_number_int<peoplevector.size())
                        {
                            line_flag = false;
                            cout << "Type name of person you want to add (instead of " << peoplevector[line_number_int].name << "): ";
                            string name_str;
                            getline(cin>>ws, name_str);
                            cout << "Type surname of person you want to add (instead of "<< peoplevector[line_number_int].surname << "): "; 
                            string surname_str;
                            getline(cin>>ws, surname_str);
                            age_flag = true;
                            while (age_flag)
                            {
                                cout << "Type age of person you want to add (instead of " << peoplevector[line_number_int].age << "): ";
                                string age_str;
                                int age_int;
                                getline(cin>>ws, age_str);
                                try
                                {
                                    age_int = stoi(age_str);
                                    age_flag = false;
                                    Person guy;
                                    guy.name = name_str;
                                    guy.surname = surname_str;
                                    guy.age = age_int;
                                    peoplevector[line_number_int] = guy;
                                    cout << "Ok, the person: " << guy.name << " " << guy.surname << " " << guy.age << " has been added to the line " << line_number_int+1 << endl;
                                }
                                catch(invalid_argument)
                                {
                                    cout << "Inappropriate value (integer expected)." << endl;
                                }
                            }
                        }      
                        else
                        {
                            cout << "Given integer out of range." << endl;
                        }
                    }
                    catch(invalid_argument)
                    {
                        cout << "Inappropriate value (integer expected)." << endl;
                    }
                }
                cout << "\nCurrent list: \n";
                for (int i = 0; i < peoplevector.size(); ++i)
                {
                    cout << "line nr: " << i+1 << " - " << peoplevector[i].name << " " << peoplevector[i].surname << " " << peoplevector[i].age << endl;
                }
                active2 = false;
            }

            else if (x=="ADD")
            {
                cout << "ok add" << endl;
                cout << "Type name of person you want to add: ";
                string name_str;
                getline(cin>>ws, name_str);
                cout << "Type surname of person you want to add: ";
                string surname_str;
                getline(cin>>ws, surname_str);
                age_flag = true;
                while (age_flag)
                {
                    cout << "Type age of person you want to add: ";
                    string age_str;
                    int age_int;
                    getline(cin>>ws, age_str);
                    try
                    {
                        age_int = stoi(age_str);
                        age_flag = false;
                        Person guy;
                        guy.name = name_str;
                        guy.surname = surname_str;
                        guy.age = age_int;
                        peoplevector.push_back(guy);
                        cout << "Ok, the person: " << guy.name << " " << guy.surname << " " << guy.age << " has been added to the list." << endl;
                    }
                    catch(invalid_argument)
                    {
                        cout << "Inappropriate value (integer expected)." << endl;
                    }  
                }
                cout << "\nCurrent list: \n";
                for (int i = 0; i < peoplevector.size(); ++i)
                {
                    cout << "line nr: " << i+1 << " - " << peoplevector[i].name << " " << peoplevector[i].surname << " " << peoplevector[i].age << endl;
                }
                active2 = false;                
            }
            else if (x=="REMOVE")
            {
                cout << "ok remove" << endl;
                line_flag = true;
                while (line_flag)
                {
                    cout << "Type number of line which you want to remove: ";
                    string line_number_string;
                    int line_number_int;
                    getline(cin>>ws, line_number_string);
                    try
                    {
                        line_number_int = stoi(line_number_string)-1;
                        if (line_number_int<peoplevector.size())
                        {
                            line_flag = false;
                            cout << "Ok, the person '" << peoplevector[line_number_int].name << " " 
                            << peoplevector[line_number_int].surname << " " << peoplevector[line_number_int].age 
                            << "' has been removed." << endl;
                            peoplevector.erase(peoplevector.begin() + line_number_int);
                        }
                        else
                        {
                            cout << "Given integer out of range." << endl;
                        }
                    }
                    catch(invalid_argument)
                    {
                        cout << "Inappropriate value (integer expected)." << endl;
                    }                      
                }
                cout << "\nCurrent list: \n";
                for (int i = 0; i < peoplevector.size(); ++i)
                {
                    cout << "line nr: " << i+1 << " - " << peoplevector[i].name << " " << peoplevector[i].surname << " " << peoplevector[i].age << endl;
                }
                active2 = false;
            }
            else
            {
                cout << "I don't understand, please answer again." << endl;
            }
        }  
    }
    else if (x=="NO")
    {
        cout << "ok no" << endl;
        active1 = false;
    }
    else
    {
        cout << "I don't understand, please answer again." << endl;
    }
}

cout << "\nFinal list: \n";
for (int i = 0; i < peoplevector.size(); ++i)
{
    cout << "line nr: " << i+1 << " - " << peoplevector[i].name << " " << peoplevector[i].surname << " " << peoplevector[i].age << endl;
}

cout << "\nName the file (without extension name): ";
string filename;
getline(cin>>ws, filename);

string filename2;
filename2 = filename + ".txt";

ofstream filesave;
filesave.open(filename2);
for (int i = 0; i < peoplevector.size(); ++i)
{
    filesave  << peoplevector[i].name << " " << peoplevector[i].surname << " " << peoplevector[i].age << endl;
}
filesave.close();

return 0;

}