#include "main.h"
#include "Sensor.hpp"

class IMU:public Sensor
{
private:
    vector<tuple <double,double, double>> imuData_;

public:
    IMU(string path)
        : Sensor(path)
    {
        this->readFile(path);
    }

    // Getter for IMU Data
    vector<tuple <double,double, double>> getIMUData()
    {
        return imuData_;
    }

    // Setter for IMU Data
    void setIMUData(vector<tuple <double,double, double>> imuData)
    {
        imuData_ = imuData;
    }

    //  Average of IMU
    void printAverage()
    {
        double yawSum;
        double rollSum;
        double pitchSum;
        for (auto i : imuData_)
        {
            yawSum += get<0>(i);
            rollSum += get<1>(i);
            pitchSum += get<2>(i);
        }
        cout << "IMU Data: Yaw average is " << fixed << setprecision(15)  <<  yawSum/imuData_.size()  <<"\nRoll average is "  << fixed << setprecision(15)  << rollSum/imuData_.size() <<  "\nPitch average is "  << fixed << setprecision(15)  << pitchSum/imuData_.size() <<  endl;
        cout << endl;
    }

    //  Maximum of IMU
    void printMax()
    {
        double yawMax = get<0>(imuData_[0]);
        double rollMax = get<1>(imuData_[0]);
        double pitchMax = get<2>(imuData_[0]);
        for (auto i : imuData_)
        {
            if(yawMax <= get<0>(i))
                yawMax = get<0>(i);

            if(rollMax <= get<1>(i))
                rollMax = get<1>(i);

            if(pitchMax <= get<2>(i))
                pitchMax = get<2>(i);
        }
        cout << "IMU Data: Yaw Max is " << fixed << setprecision(15)  << yawMax << "\nRoll Max is " << fixed << setprecision(15)  << rollMax << "\nPitch Max is "  << fixed << setprecision(15)  << pitchMax <<  endl;
        cout << endl;
    }

    //  Minimum of IMU
    void printMin()
    {
        double yawMin = get<0>(imuData_[0]);
        double rollMin = get<1>(imuData_[0]);
        double pitchMin = get<2>(imuData_[0]);

        for (auto i : imuData_)
        {
            if(yawMin >= get<0>(i))
                yawMin = get<0>(i);

            if(rollMin >= get<1>(i))
                rollMin = get<1>(i);

            if(pitchMin >= get<2>(i))
                pitchMin = get<2>(i);
        }
        cout << "IMU Data: Yaw Min is " << fixed << setprecision(15)  << yawMin << "\nRoll Min is " << fixed << setprecision(15)  << rollMin << "\nPitch Min is "  << fixed << setprecision(15)  << pitchMin <<  endl;
        cout << endl;
    }


    void readFile(string path)
    {
        vector<chrono::microseconds> timestamp1;
        tuple <double,double,double> temp;
        ifstream imuFile ((string) path + "IMU.txt");

        // Error in file open
        if (!imuFile.is_open ())
        {
            cerr << "Could not open the file - '" << "IMU.txt" << endl;
        }
        else
        {
            // reads and separate line by commas
            while (getline (imuFile, line))
            {

                commaPos = line.find(',');
                doubleTimestamp = stod(line.substr (0,commaPos).c_str(),0); // read it as double
                longTimestamp = doubleTimestamp * pow(10,6);                // then convert it to long long
                chrono::microseconds timestamp(longTimestamp);              // Save it as chrono miliseconds);
                timestamp1.push_back(timestamp);




                line = line.substr(commaPos+1);
                commaPos = line.find(",");

                get<0>(temp) = stod(line.substr (0,commaPos).c_str());  // YAW value

                line = line.substr(commaPos+1);
                commaPos = line.find(",");

                get<1>(temp) = stod(line.substr (0,commaPos).c_str());  // ROLL value
                get<2>(temp) = stod(line.substr (commaPos+1));          // PITCH value

                imuData_.push_back(temp);
            }
        }
    }
};
