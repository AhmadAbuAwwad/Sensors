#include "main.h"
#include "Sensor.hpp"

class GPS:public Sensor
{

private:
    vector<pair<double,double>> location_;

public:
    GPS (string path)
        : Sensor(path)
    {
        this->readFile(path);
    }

    //  Getter for Longitude
    vector< pair<double, double>> getLocation ()
    {
        return location_;
    }
    //  Setter for Longitude
    void setLocation (vector<pair<double, double>>location)
    {
        this->location_ = location;
    }

    // Average for Locations
    void printAverage()
    {
        double sumLongitude = 0;
        double sumLatitude = 0;
        int j = 0;
        for (auto i : location_)
        {
            sumLongitude += i.first;
            sumLatitude += i.second;
            j++;
        }
        cout << "locations is " << fixed << setprecision(6)  << sumLongitude/j << " , " <<fixed << setprecision(6)  << sumLatitude/j << endl;
    }


    // Maximum for Locations
    void printMax()
    {
        double maxLongitude = location_[0].first;
        double maxLatitude = location_[0].second;
        for (auto i : location_)
        {
            if(maxLongitude <= i.first)
            {
                maxLongitude = i.first;
            }
            if(maxLatitude <= i.second)
            {
                maxLatitude = i.second;
            }
        }
        cout << "Max longitude is " << fixed << setprecision(6)  << maxLongitude << ", and Max Latitude is " << fixed << setprecision(6)  << maxLatitude << endl;
    }

    // Minimum for Locations
    void printMin()
    {
        double minLongitude = location_[0].first;
        double minLatitude = location_[0].second;
        for (auto i : location_)
        {
            if(minLongitude >= i.first)
            {
                minLongitude = i.first;
            }
            if(minLatitude >= i.second)
            {
                minLatitude = i.second;
            }
        }
        cout << "MIN longitude is " << fixed << setprecision(6)  << minLongitude << ", and MIN Latitude is " << fixed << setprecision(6)  << minLatitude << endl;
    }

    void readFile(string path)
    {
        pair <double, double> locations;
        ifstream gpsFile ((string) path + "GPS.txt");

        // Error in file open
        if (!gpsFile.is_open ())
        {
            cerr << "Could not open the file - '" << "GPS.txt" << endl;
        }
        else
        {
            // reads Lines
            while (getline (gpsFile, line))
            {
                // separate line by commas and save values
                commaPos = line.find(',');
                doubleTimestamp = stod(line.substr (0,commaPos).c_str());   // read it as double
                longTimestamp = doubleTimestamp*pow(10,6);                  // then convert it to long long
                chrono::microseconds microTimestamp(longTimestamp);              // Save it as chrono miliseconds
                timestamp_.push_back(microTimestamp);

                // reads the Longitude
                line = line.substr(commaPos+1);
                commaPos = line.find(",");
                locations.first = stod(line.substr (0,commaPos).c_str());

                // reads the latitude
                line = line.substr(commaPos+1);
                locations.second = stod(line);
                location_.push_back(locations);
            }
        }
    }
};

