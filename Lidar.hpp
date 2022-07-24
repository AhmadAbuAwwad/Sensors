#include "main.h"
#include "Sensor.hpp"

class Lidar:public Sensor
{
public:
    vector<double> lidarValues_;

    Lidar (string path)
        : Sensor(path)
     {
        this->readFile(path);
    }

    // Getter for LIDAR Data
    vector<double> getLidarValues()
    {
        return lidarValues_;
    }

    // Setter for LIDAR Data
    void setLidarValues(vector<double> lidarValues1)
    {
        lidarValues_ = lidarValues1;
    }

    //  Average of LIDAR data
    void printAverage()
    {
        cout << "LIDAR is " << fixed << setprecision(6)  << accumulate( lidarValues_.begin(), lidarValues_.end(), 0.0 )/ lidarValues_.size() << endl;
    }

    //  Maximum of LIDAR data
    void printMax()
    {
        cout << "LIDAR is " << fixed << setprecision(6)  << *max_element(lidarValues_.begin(), lidarValues_.end()) << endl;
    }

    //  Minimum of LIDAR data
    void printMin()
    {
         cout << "LIDAR is " << fixed << setprecision(6)  << *min_element(lidarValues_.begin(), lidarValues_.end()) << endl;
    }

    void readFile(string path)
    {
        ifstream lidarFile ((string) path + "Lidar.txt");

        // Error in file open
        if (!lidarFile.is_open ())
        {
            cerr << "Could not open the file - '" << "LIDAR.txt" << endl;
        }
        else
        {
            // reads and separate line by commas
            getline (lidarFile, line);
            commaPos = line.find(',');

            doubleTimestamp = stod(line.substr (0,commaPos).c_str(),0);     // read it as double
            longTimestamp = doubleTimestamp * pow(10,6);                    // then convert it to long long
            chrono::microseconds microTimestamp(longTimestamp);                   // Save it as chrono miliseconds;
            timestamp_.push_back(microTimestamp);

            // save the date into vector of doubles
            while(commaPos != -1)
            {
                line = line.substr(commaPos+1);
                commaPos = line.find(',');
                lidarValues_.push_back(stod(line.substr (0,commaPos).c_str()));
            }
            lidarValues_.push_back(stod(line.substr (commaPos+1).c_str()));  // last value
        }
    }
};
