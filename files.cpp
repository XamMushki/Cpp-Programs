#include <iostream>
#include <fstream>
#include <string>
#include<sstream>
using namespace std;
void write()
{
    string name = "Zahid";
    int age = 20;
    string address = "Janglat Mandi";

    ofstream outfile;
    outfile.open("file1.txt");
    if (outfile.is_open())
    {
        outfile << name <<"\n"
                << age << "\n"
                << address;
        cout << "Written Successfully!" << endl;
    }
}
void read()
{
    string name,mname,lname,address;
    int age;
    ifstream infile;
    infile.open("file1.txt");
    if (infile.is_open())
    {
        infile>>name>>age>>address;
    }
    cout<<name<<endl;
    cout<<age<<endl;
    
}
void test(){
string name ="zahid amin mushki";
stringstream ss(name);
string word;
while(getline(ss,word,' ')){
    cout<<word<<endl;
}
}
void readfile(){
    ifstream ifile;
    ifile.open("file1.txt");
    string line;
    while (getline(ifile, line))
    {
        cout<<line<<endl;
    }
}

int main()
{
    // write();
    // read();

    // test();
    readfile();
}
