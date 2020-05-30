# kvxlogger
Logger for some apps

# Example

```c++
#include <kvxlogger/logger.hpp>

int main() {
    Logger logger("Test", WARNING | INFO | ERROR); // app name, messages that can be displayed

    // lg is Logger alias

    logger.info << "Info test" << lg::endl; // lg::endl flushes stream
    logger.warning << "Warning test" << lg::endl;
    logger.error << "Error test" << lg::endl;
    logger.debug << "Debug test" << lg::endl;
    return 0;
}

```