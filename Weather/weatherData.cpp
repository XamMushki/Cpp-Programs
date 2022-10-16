#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;
void printArray(float arr[][12][31], int y, int m, int d)
{
    // printing
    int year = 2015;
    for (int i = 0; i < y; i++)
    {
        cout << "Year: " << year << endl;
        year++;
        for (int j = 0; j < m; j++)
        {
            cout << "Month: " << j + 1 << endl;
            ;
            for (int k = 0; k < d; k++)
            {
                cout << arr[i][j][k] << "  ";
                // cout<<"\'"<<k<<"\'";
                if ((k + 1) % 5 == 0)
                {
                    cout << endl;
                }
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main()
{
    int y = 5, m = 12, d = 31;
    float temperature[5][12][31];

    // initializing every element with 0.
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < d; k++)
            {
                temperature[i][j][k] = 0.0;
            }
        }
    }

    // loading .csv file
    ifstream file;
    file.open("city_temp_la.csv");
    string line;
    vector<vector<string>> dataset; // nested vector
    if (file.is_open())
    {
        while (getline(file, line))
        {

            //    getline(file,line);
            // here line is string which contains one line from the csv file at a time (seperated by ',').

            /*A stringstream associates a string object with a stream allowing you to
            read from the string as if it were a stream (like cin).*/

            std::stringstream lineStream(line);
            // cout << line;
            string word;
            vector<string> row; // individual strings

            while (getline(lineStream, word, ','))
            {
                row.push_back(word); // individual words (seperated by commas) in 'line'
            }
            dataset.push_back(row); // append vector 'row' to vector 'dataset'
            // break;
        }
    }
    file.close();
    // cout << dataset[0][7] << endl;
    // dataset[][4] contains month
    // dataset[][5] contains day
    // dataset[][6] contains year
    // dataset[][7] contains avg temp

    // cout << dataset.size() << endl;

    // assigning values to temperature[][][]

    int c = 1; // counter for dataset vector, where first row is just the names of columns

    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < d; k++)
            {
                float temp_temperature = 0.0;
                int temp_day = stof(dataset[c][5]);
                if (temp_day == k + 1)
                {
                    temp_temperature = stof(dataset[c][7]);
                    temperature[i][j][k] = temp_temperature;
                    c++;
                }
            }
        }
    }

    printArray(temperature, y, m, d);
}