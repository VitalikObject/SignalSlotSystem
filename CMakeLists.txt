cmake_minimum_required(VERSION 3.16)

project(SignalSlotSystem LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(SignalSlotSystem
  main.cpp
  SignalSlotSystem.h SignalSlotSystem.cpp
  VObject.h
  TestObject1.h TestObject1.cpp
  TestObject2.h TestObject2.cpp
)
target_link_libraries(SignalSlotSystem Qt${QT_VERSION_MAJOR}::Core)

include(GNUInstallDirs)
install(TARGETS SignalSlotSystem
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
