#include "main.h"
#include "GPS.hpp"
#include "Lidar.hpp"
#include "Image.hpp"
#include "IMU.hpp"

int
main ()
{
    string path;
    cout << "please enter the path: ";
    cin >> path;
    cout << endl;
    path = path + "//";
    
    //  push it into Sensor Vector
    vector <Sensor*> Sensors;
    Sensors.push_back(new GPS(path));
    Sensors.push_back(new Lidar(path));
    Sensors.push_back(new Image(path));
    Sensors.push_back(new IMU(path));

    // calling methods
    for (auto i: Sensors)
    {
        i->printAverage();
        i->printMax();
        i->printMin();
        cout <<endl;
    }

    return 0;

}
