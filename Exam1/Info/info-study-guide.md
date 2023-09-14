# Operating Systems - Exam No. 1 - Concepts

1. What the heck is an *Operating System*?
	- An Operating System is simply a resource allocator. It deals with numerous conflicting requests for resources from places like file-storage space, I/O, processes and so on.
	- There is no universally accepted definition of an operating system

2.  What a *Control Program* manages anyway?
	- A control Program manages the execution of user programs to prevent errors and an improper use of the computer. It's especially concerned with the operation and control of I/O devices.

3. What is the main goal of computers and what is a kernel?
	- The fundamental goal of  a computer system is to execute user programs and to make solving user problems easier. This goes all the way to the hardware itself.
	- The kernel is a program that is running at all times.

4. What are the four components of a computer system?
	1. Hardware
	2. OS
	3. Applications
	4. Users

5. Provide at least three resources the OS allocates
	1. Memory
	2. CPU
	3. Storage

6. What special operation triggers a software interrupt?

System Call

9. Briefly discuss the mayor advantage of SJF scheduling and the two mayor problems with this technique along with solutions to them.
	- First we must focus on optimatility and starvation
	- The mayor advantage of SJF is that it gets the optimal average waiting time, meaning it minimizes the waiting time of each process.
	- One problem of SJF is starvation, which is when a process with a big CPU burst can stay waiting forever if the other processes that keep emiting to the ready queue have shorter CPU bursts.
	- Another problem is that predicting the length of the next CPU is really hard to do since each burst goes really fast and are done by the short-term scheduler

10. What is a *System Program*?
	- A system program is also a program associated with the operating system but its not really part of the kernel and it includes user-level apps that are not associated with the operating system per se.

11. What do mobile operating systems often include in addition to the core kernel?
	- A middleware is a set of software frameworks that provide additional services to app developers.

12. What is an interrupt?
	- An interrupt is an event sent from either hardware or software that alters the sequence in which a processor executes instructions.

13. What is an interrupt handler?
	- An interrupt handler (IH) is an operating system routine used to process each different type of interrupt. 

14. What is one advantage of using a solid state disk over a magnetic disk?
	- It's faster and uses less power.

15. Advantages of using pipes for communication between IPC processes
	- Easier to implement
	- Easy to create shared memory segments
	- Pipes deal with synchronization. Shared memory can't.
	- Its easier to specify how to send a series of messages in a certain order
	- You can have a waiting queue over multiple pipes with a call to "select", but it can't wait for multiple mutexes

16. Advantages of Shared Memory for communication between IPC processes
	- Data sharing is more flexible
	- a common parent is necessary to establish communication
	- In terms of performance is faster than pipes.

17. What is a thread?
	- A basic unit of CPU utilization. This is different from a process. Threads are lightweight as compared to processes which are heavyweight. A thread is a separate line of execution inside of a process.

18. What a thread consists of?
	- It comprises a thread ID, a PC (program counter ), a register set, and a stack.

19. What are the advantages of using threads?
	- **Responsiveness**: One part of the program can keep running while other parts may be blocked or not doing anything.
	- **Resource Sharing**: Threads can share resources with the parent process while running in the same address space. These threads running in the same address do not need a context switch.
	- **Economy**: Shorter context switching time. Less over-head than running several processes doing the same task. The sharing of resources causes thread creation to be simple. It is easier to manage than multiple processes.
	- **Scalability**: Its possible to have multiple threads running on multiple CPUs. A single-threaded process can run on only one processor, regardless how many are available.

20. Concurrency VS Parallelism
	- Concurrency is when two tasks can start, run, and complete in overlapping time periods. It doesn't necessarily mean they'll ever both be running at the same instant, like multitasking on a single-core machine.

21. What is a Pthread?
	- The POSIX standard defining an API for thread creation and synchronization. This is a specification for thread behavior, **NOT** and implementation.

22. What is an Implicit threading?
	- Transfers the creation and management of threading from application developers to compilers and run-time libraries

23.  What is a PSW?
	- Program Status Word (PSW) control the order of instruction execution and has info about the state of a process.

24. Jobs and Processes are interchangeably terms

25. What a process includes?
	- A process includes:
		- Stack
		- Data Section
		- Code Section
		- Program Counter (PC)

26. Explain the process creation super briefly
	- Resources sharing
		- Parent and children share all resources
		- Parent and child share no resources
	- Excetution
		- Parent and children execute concurrently
		- Parent waits until children terminate
	- Address space
		- Child duplicate of parent (when cloning)
		- Child has a program loaded into it

27. What is clustering?
	- A technique where two or more servers linked to equally share the server processor load
 
28. Explain the following concepts related to processes:
    - *Parent* -> Creating process
    - *Child* -> A new process spawned by a parent process
    - *Orphan* -> A process that is still executing, but whose parent has died. When the parent dies, the orphaned child process is adopted by init (process ID 1). When orphan processes die, they are waited on by init.
    - *Zombie* ->  A process that has completed execution but still has an entry in the process table. Not to be confused with an orphan
    - When creating a process over and over the amount of processes spawn at a rate of `2^n` processes.

The following is an example of how to deal with a basic process

```c
// Entonces si == 0, es el last fork that its performed, and the last fork will be the last child to create
else if (pid == 0) { 
	// Print this child, output this child process
	printf("Child 1\n");
	// Flush is just the output of the console
	fflush(stdout);
	// Sleep does not wait for anyone
	// Wait will wait any signal of any of the child processes
	pid = fork(); // Normal name
	waitpid(pid, NULL, WUNTRACED);
	if (pid < 0) { // Check for any errors
		fprintf(stderr, "Error creating fork");
	}
	

}
