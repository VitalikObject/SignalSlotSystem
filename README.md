
# SignalSlotSystem

A simple signal-slot system implemented in C++.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [License](#license)
- [Contributing](#contributing)

## Introduction

The SignalSlotSystem project is a C++ implementation of a signal-slot mechanism, which is commonly used for event-driven programming. This system allows for the decoupling of objects that produce events (signals) from those that process events (slots).

## Features

- Easy-to-use signal-slot mechanism
- Decouples event producers from event consumers
- Example objects demonstrating usage

## Requirements
* C++20 or later

## Installation

To build the SignalSlotSystem, ensure you have CMake installed. Then follow these steps:

```sh
git clone https://github.com/VitalikObject/SignalSlotSystem.git
cd SignalSlotSystem
mkdir build
cd build
cmake ..
make
```

## Usage

The repository includes example classes (`SignalObject`, `SlotObject`) to demonstrate how to use the signal-slot system. Below is a simple usage example from the `main.cpp` file:

```cpp
#include "SignalObject.h"
#include "SlotObject.h"

int main(int argc, char *argv[])
{
    SignalSlotSystem& signalSlotSystem = SignalSlotSystem::getInstance();
    SignalObject signalObject;
    SlotObject slotObject;

    signalSlotSystem.connect(&signalObject, &SignalObject::showMessage, &slotObject, &SlotObject::showMessage);
    signalSlotSystem.connect(&signalObject, &SignalObject::addNumbers, &slotObject, &SlotObject::addNumbers);
    signalSlotSystem.connect(&signalObject, &SignalObject::multiplyNumbers, &slotObject, &SlotObject::multiplyNumbers);

    signalSlotSystem.connect(&signalObject, &SignalObject::mergeStringsAsync, &slotObject, &SlotObject::mergeStrings);

    signalObject.showMessage("hello");
    signalObject.addNumbers(4, 5);
    signalObject.multiplyNumbers(4, 5, 6);

    signalObject.mergeStringsAsync("Hello, ", "World!");

    return 0;
}

```

## License

This project is licensed under the GPL-3.0 License. See the [LICENSE](https://github.com/VitalikObject/SignalSlotSystem/blob/main/LICENSE.txt) file for more details.

## Contributing

Contributions are welcome! Please submit pull requests or open issues to discuss improvements or bugs.
