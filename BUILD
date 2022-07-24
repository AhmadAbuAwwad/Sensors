load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")


cc_library(
    name = "mainH",
    srcs = ["main.h"],
)

cc_library(
    name = "Sensor",
    srcs = ["Sensor.hpp"],
    deps = ["mainH"],
)

cc_library(
    name = "GPS",
    srcs = ["GPS.hpp"],
    deps = ["mainH", "Sensor"],
)

cc_library(
    name = "Lidar",
    srcs = ["Lidar.hpp"],
    deps = ["mainH", "Sensor"],
)

cc_library(
    name = "Image",
    srcs = ["Image.hpp"],
    deps = ["mainH", "Sensor"],
)

cc_library(
    name = "IMU",
    srcs = ["IMU.hpp"],
    deps = ["mainH", "Sensor"],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = ["mainH", "Sensor", "Lidar", "Image", "GPS", "IMU"],
)