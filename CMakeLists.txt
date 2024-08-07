cmake_minimum_required(VERSION 3.16)

project(SignalSlotSystem LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(SignalSlotSystem
  main.cpp
  SignalSlotSystem.h
  VObject.h
  SignalObject.h SignalObject.cpp
  SlotObject.h SlotObject.cpp
  SignalSlotSystem.cpp
)
target_link_libraries(SignalSlotSystem Qt${QT_VERSION_MAJOR}::Core)

include(GNUInstallDirs)
install(TARGETS SignalSlotSystem
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
