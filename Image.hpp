#include "main.h"
#include "Sensor.hpp"

class Image:public Sensor
{
private:
    vector<vector <int>> imageValues_;

public:
    Image (string path)
        : Sensor(path)
    {
        this->readFile(path);
    }

    // Getter for image values
    vector<vector <int>> getImageValues()
    {
        return imageValues_;
    }

    // Setter for image values
    void setImageValues(vector<vector <int>> imageValues)
    {
        imageValues_ = imageValues;
    }

    //  Average of Image
    void printAverage()
    {
        int sum = 0;
        int counter = 0;
        for (auto i : imageValues_)
        {
            for (auto j : i)
            {
                sum += j;
                counter++;
            }
        }
        cout << "Image Values is " << sum/counter <<endl;

    }

    // Maximum of Image
    void printMax()
    {
        int max = imageValues_[0][0];
        for (auto i : imageValues_)
        {
            for (auto j : i)
                if(max <= j)
                    max = j;
        }

        cout << "Image is " << max << endl;
    }

    // Minimum of Image
    void printMin()
    {
        int min = imageValues_[0][0];
        for (auto i : imageValues_)
        {
            for (auto j : i)
                if(min >= j)
                    min = j;
        }

        cout << "Image is " << min << endl;
    }


    void readFile(string path)
    {
        ifstream imageFile ((string) path + "Image.txt");
        vector<int> row;

        // Error in file open
        if (!imageFile.is_open ())
        {
            cerr << "Could not open the file - '" << "Image.txt" << endl;
        }
        else
        {
            // reads and separate line by commas
            commaPos = 0;
            while (getline (imageFile, line))
            {
                row.clear();
                commaPos = line.find(',');

                // reads the timestamp
                if(commaPos == -1)
                {
                    doubleTimestamp =stod(line);                    // read it as double
                    longTimestamp = doubleTimestamp * pow(10,6);    // then convert it to long long
                    chrono::microseconds microTimestamp(longTimestamp);  // Save it as chrono miliseconds;
                    timestamp_.push_back(microTimestamp);
                }
                // reads the image data
                else
                {
                    while(commaPos != -1)
                    {
                        row.push_back(stod(line.substr (0,commaPos).c_str()));
                        line = line.substr(commaPos+1);
                        commaPos = line.find(',');
                    }
                    row.push_back(stod(line.substr (commaPos+1).c_str()));     // last value
                    imageValues_.push_back(row);
                }
            }
        }
    }
};
