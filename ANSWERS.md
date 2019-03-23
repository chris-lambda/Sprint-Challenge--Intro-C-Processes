**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
Created - When the process is first created it waits to be put in the ready state
Ready - Loaded into memory waiting to get ran by the CPU
Running - CPU is running the process
Blocked(Sleeping) - Process is on pause waiting for it to be ran again by the scheduler
Terminated(Zombie) - Child process



**2. What is a zombie process?**
Child process that have not got rid of its exit status yet, parent has not waited/collected its exit status


**3. How does a zombie process get created? How does one get destroyed?**
Zombie process is a child process created by `fork()`. It gets destroyed by having its exit status waited for/collected by its parent


**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**
Benefits:
More control over hardware and memory
No garbage collection
Speed

When you compile your code it get converted into machine code by doing so it executes a lot faster then iterpulated languages 
