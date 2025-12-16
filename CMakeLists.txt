cmake_minimum_required(VERSION 3.16)

project(RastreadorSalud VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Sql Charts)

set(PROJECT_SOURCES
    main.cpp
    databasemanager.cpp
    loginwindow.cpp
    mainwindow.cpp
    addrecorddialog.cpp
    csvexporter.cpp
)

set(PROJECT_HEADERS
    databasemanager.h
    loginwindow.h
    mainwindow.h
    addrecorddialog.h
    csvexporter.h
)

qt_add_executable(RastreadorSalud
    ${PROJECT_SOURCES}
    ${PROJECT_HEADERS}
)

target_link_libraries(RastreadorSalud
    Qt6::Widgets
    Qt6::Sql
    Qt6::Charts
)
