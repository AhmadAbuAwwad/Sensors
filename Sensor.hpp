#pragma once
#include "main.h"

class Sensor
{
protected:
    vector<chrono::microseconds> timestamp_;

public:
    string path;

    Sensor (string path)
        :path(path)
    {
    }

    //  Getter for Timestamp
    vector<chrono::microseconds> getTimestamp ()
    {
        return timestamp_;
    }

    virtual void readFile(string) = 0;
    virtual void printAverage() = 0;
    virtual void printMax() = 0;
    virtual void printMin() = 0;
};
