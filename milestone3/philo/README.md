# PHILOSOPHERS 🧔‍♂️🧠👨‍🏫🧙‍♂️
*This project was created as part of the 42 curriculum by aluther-.*

# Description
This project is a simulation where philosophers perform three actions: eating, sleeping, and thinking.
Philosophers are born with one fork in hand, but since they need two forks to eat, they must take turns.
The goal is to avoid starvation, satisfy the required meal count (if provided), or die when the simulation arguments dictate so.

# Instructions
1. Navigate to the `philo` directory.
2. Compile the program using `make`:
    - `make all`: General compilation (same as `make`). If run again after compiling, it only recompiles modified files.
    - `make clean`: Removes `.o` object files.
    - `make fclean`: Removes all compiled files, including the **philo** executable, leaving the directory completely clean.
    - `make re`: Cleans and recompiles everything from scratch.
3. Run the program with your chosen arguments, for example:
    `./philo 4 810 400 400 7`

The program accepts the following arguments:
- `number_of_philosophers`
- `time_to_die` (in milliseconds)
- `time_to_eat` (in milliseconds)
- `time_to_sleep` (in milliseconds)
- **OPTIONAL:** `number_of_times_each_philosopher_must_eat`

The terminal will display logs of the philosophers' actions along with a timestamp in milliseconds.

# Resources

### Documentation Used
* [GeeksforGeeks: Multithreading in C](https://www.geeksforgeeks.org/c/multithreading-in-c/)
* [Medium: Understanding Threads in C](https://medium.com/@akshatarhabib/understanding-threads-in-c-c9feb5e9372a)
* [Man7: Pthreads](https://man7.org/linux/man-pages/man7/pthreads.7.html)
* [Man7: Gettimeofday](https://man7.org/linux/man-pages/man2/gettimeofday.2.html)
* [Medium: Mutexes in C](https://medium.com/@sherniiazov.da/mutexes-in-c-ac2b0f1a6d34)
* [GeeksforGeeks: Mutex Lock for Linux Thread Synchronization](https://www.geeksforgeeks.org/linux-unix/mutex-lock-for-linux-thread-synchronization/)

### About AI Usage
As expected, this project was developed with the assistance of AI. This wasn't "vibecoding," but rather an atomic collaboration: I designed and understood the program structure, identified unknown language features (like threads), and tested how they work. I consulted the AI for specific doubts and examples. Afterward, I coded the components myself, maintaining full awareness of every part of the program. Whenever I got stuck, instead of asking for direct code, I explained my vision for that function or block and asked for guidance on the best approach.
