# Qualqulator

![Screenshot](assets/background.png)

## Description

**Qualqulator** is a modern calculator with a clean, customizable UI built from custom elements.  
It uses a [Pratt parsing algorithm](https://en.wikipedia.org/wiki/Operator-precedence_parser#Pratt_parsing) for expression evaluation, ensuring correct operator precedence and making the system easily **extensible**.  
The combination of a **modular UI** and robust parsing highlights both usability and solid software design.

## Dependencies

- C++20
- Clang++
- Qt 6.9
- CMake
- Ninja

## Build & Run

```sh
cmake --preset=clang-debug-build
cmake --build --preset=clang-debug-build

./build/clang-debug-build/src/calculator
```

# Important

Before building the project, create your own CMakeUserPresets.json from CMakeUserPresets.template.json and update the CMAKE_PREFIX_PATH variable to point to your actual Qt CMake path.

# Testing

``` sh
ctest --preset=clang-test
```