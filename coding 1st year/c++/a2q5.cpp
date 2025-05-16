#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    string name = "", tempage = "", line;
    int age;
    while (!fin.eof())
    {
        getline(fin, line);
        int temp = 0;
        for (int i = 0; i < line.length(); i++)
        {
            if (temp == 0)
            {
                if (line[i] == ',')
                    temp = 1;
                else
                    name += line[i];
            }
            else if (temp == 1)
            {
                if (line[i] == ' ')
                    continue;
                if (line[i] == ',')
                    break;
                else
                    tempage += line[i];
            }
        }
        age = stoi(tempage);
        fout << "Name: " << name << ", Age: " << age << ", Birth Year: " << (2023 - age) << endl;
        tempage = "";
        name = "";
    }
    cout<<"Done";
}