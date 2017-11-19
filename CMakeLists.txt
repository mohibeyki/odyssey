cmake_minimum_required(VERSION 3.8)
project(odyssey)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        types/Scheduler.cpp
        types/Scheduler.h
        types/task.cpp
        types/task.h
        types/worker.cpp
        types/worker.h
        utils/tgparser.cpp
        utils/tgparser.h
        utils/utils.cpp
        utils/utils.h
        LICENSE
        main.cpp
        README.md
        robot.stg)

add_executable(odyssey ${SOURCE_FILES})