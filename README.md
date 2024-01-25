# debug.hpp
C++ Debug Library (header only)

## Usage

declare `_DEBUG` before including this library

it automatically writes into a file called `debug_log.txt`

## Public Methods

All Methods are under the namespace Debug

* When starting the program you can clear the previous debug output with this function:

    ```cpp
    Debug::clear();
    ```

* You can log Messages, Warnings and Errors with these:

    ```cpp
    Debug::logMessage("This is a message");
    Debug::logWarning("This is a warning");
    Debug::logError("This is an error");
    ```

    The time of this message will automatically be added

* you can pause the program by calling

    ```cpp
    Debug::pause();
    ```

* When a critical Error occurs, you can call:

    ```cpp
    Debug::logCriticalError("A critical error occurred");
    ```

    This prints the error message to the console and debug output,
    then pauses.

    Even if debug is not enabled, this function exits after doing all of this

* When you want to log a raw text, use this function:

    ```cpp
    Debug::logRaw("This is my raw message");
    ```

## Use Example

```cpp
#define _DEBUG

#include "debug.hpp"
#include <iostream>
#include <string>
#include <fstream>

int main(void) {
    // clear the debug output
    Debug::clear();

    // log, that the program started
    Debug::logMessage("Program Started");
    
    // open a file stream to text.txt
    std::ifstream file("text.txt", std::ios::in);

    // check if couldn't be opened
    if (!file) {
        // when the file can't be read, there is a critical error
        Debug::logCriticalError("File text.txt couldn't be opened...\nExiting.");
    }

    Debug::logMessage("Opened File successfully");

    std::string first_line;

    std::getline(file, first_line);

    if (first_line.empty()) {
        Debug::logWarning("text.txt file is empty");
    }

    std::cout << "First line of text.txt: " << first_line << "\n";

    file.close();

    Debug::logMessage("Program executed successfully");
    return 0;
}
```
