# Loops, Functions, I/O - meet at least 2 criteria
| Criteria | Submission Requirements | Implementation |
|---|---|---|
|The project demonstrates an understanding of C++ functions and control structures.| A variety of control structures are added to the project. The project code is clearly organized into functions.|Writing the highscore in main.cpp is factored out into a function. Determining opposite direction is refactored into a function in controller.cpp|
| The project reads data from a file and process the data, or the program writes data to a file.| The project reads data from an external file or writes data to a file as part of the necessary operation of the program.|in main.cpp the program writes the highscore into a file "score.txt".|
|The project accepts user input and processes the input.| In addition to controlling the snake, the game can also receive new types of input from the player.|Added a cheat mode by pressing 'c' in controller.cpp|
|The project uses data structures and immutable variables.| The project uses arrays or vectors and uses constant variables.||
# Object Oriented Programming - meet at least 3 criteria
| Criteria | Submission Requirements | Implementation |
|---|---|---|
|One or more classes are added to the project with appropriate access specifiers for class members.| Classes are organized with attributes to hold data and methods to perform tasks.   All class data members are explicitly specified as public, protected, or private. Member data that is subject to an invariant is hidden from the user and accessed via member methods.||
|Class constructors utilize member initialization lists.|All class members that are set to argument values are initialized through member initialization lists.||
|Classes abstract implementation details from their interfaces.|All class member functions document their effects, either through function names, comments, or formal documentation. Member functions do not change the program state in undocumented ways.||
|Overloaded functions allow the same function to operate on different parameters.|One function is overloaded with different signatures for the same function name.||
|Classes follow an appropriate inheritance hierarchy with virtual and override functions.|Inheritance hierarchies are logical. One member function in an inherited class overrides a virtual base class member function.|
|Templates generalize functions or classes in the project.|One function or class is declared with a template that allows it to accept a generic parameter.||
# Memory Management - meet at least 3 criteria
| Criteria | Submission Requirements | Implementation |
|---|---|---|
|The project makes use of references in function clarations. |At least two variables are defined as references, or two functions use pass-by-reference in the project code.||
|The project uses destructors appropriately.| At least one class that uses unmanaged dynamically allocated memory, along with any class that otherwise needs to modify state upon the termination of an object, uses a destructor.||
|The project uses scope / Resource Acquisition Is Initialization (RAII) where appropriate.| The project follows the Resource Acquisition Is Initialization pattern where appropriate, by allocating objects at compile-time, initializing objects when they are declared, and utilizing scope to ensure their automatic destruction.||
|The project follows the Rule of 5.|For all classes, if any one of the copy constructor, copy assignment operator, move constructor, move assignment operator, and destructor are defined, then all of these functions are defined.||
|The project uses move semantics to move data instead of copying it, where possible.|The project relies on the move semantics, instead of copying the object.||
|The project uses smart pointers instead of raw pointers.|The project uses at least one smart pointer: unique_ptr, shared_ptr, or weak_ptr.||
# Concurrency - meet at least 2 criteria
| Criteria | Submission Requirements | Implementation |
|---|---|---|
| The project uses multithreading. | The project uses multiple threads or async tasks in the execution. | |
| A promise and future is used in the project. | A promise and future is used to pass data from a worker thread to a parent thread in the project code. | |
| A mutex or lock is used in the project. | A mutex or lock (e.g. std::lock_guard or `std::unique_lock) is used to protect data that is shared across multiple threads in the project code. | |
| A condition variable is used in the project.|A std::condition_variable is used in the project code to synchronize thread execution.||