
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

The repository includes example classes (`TestObject1`, `TestObject2`) to demonstrate how to use the signal-slot system. Below is a simple usage example from the `main.cpp` file:

```cpp
#include <QCoreApplication>
#include "SignalSlotSystem.h"
#include "TestObject1.h"
#include "TestObject2.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    SignalSlotSystem &signalSlotSystem = SignalSlotSystem::getInstance();
    TestObject1 testObject1;
    TestObject2 testObject2;

    signalSlotSystem.connect(&testObject1.onShowMessage, [&testObject2] { testObject2.showMessage(); });
    signalSlotSystem.sendSignal(&testObject1.onShowMessage);

    testObject1.showMessage();

    return a.exec();
}
```

## License

This project is licensed under the GPL-3.0 License. See the [LICENSE](https://github.com/VitalikObject/SignalSlotSystem/blob/main/LICENSE.txt) file for more details.

## Contributing

Contributions are welcome! Please submit pull requests or open issues to discuss improvements or bugs.
