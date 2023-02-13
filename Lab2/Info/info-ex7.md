## Ex 7

### [Useful resources](http://www.gnu.org/software/libc/manual/html_mono/libc.html#Processes)

Answer the following Questions:

1. What are the return values from the `fork()` function from the point of view of the parent and child process?

### Answer

returns a `pid_t`. If the operation between a parent-child is successful, `fork` then a child process returns `0` while a parent process is the child's process ID. If process creation failed, `fork` returns a value of `-1` in the parent process. 

2. What function is used to get the ID of a process?

### Answer

`getpid` gets the ID of a process you specify in its argument and `getpgrp` gets the id the process which called said function

3. What function is used to get the ID of the parent process?

### Answer

```c
p_id getppid(void)
```

4. What is a process image?

### Answer 

Program that the process is executing

5. What happens to the original process image when `exec()` is called?

### Answer

It replaces the current process image with a new process image. The new process image is specified by the path and arguments passed to the `exec()` function.

6. What are the differences among the family of `exec()` functions?

### Answer

They differ in the arguments they accept and their behavior. Some functions take an array of arguments, some take a variable number of arguments, and some allow for the specification of the environment variables to be passed to the new process. 

7. Explain the `id_t waitpid (pid_t pid, int *status-ptr, int options)` function

### Answer

`waitpid()` returns the process ID of the child process that terminated, or `-1` on error. It allows a parent process to wait for a child process to complete. It takes three arguments:

- `pid`: This argument specifies the process ID of the child process to wait for. The value `-1` can be used to wait for any child process.

- `status_ptr`: This argument is a pointer to an `int` that will receive the exit status of the child process.

- `options`: This argument specifies options that control the behavior of `waitpid()`. Some of the options include `WNOHANG`, which returns immediately if the child process has not yet terminated, and `WUNTRACED`, which returns if the child process has stopped, but not yet terminated.


8. Explain the `pid_t wait (int *status-ptr)` function

### Answer

A system call that allows a parent process to wait for its child process to terminate. Returns the child's process ID and sets the value of the `status-ptr` argument to the child's exit status. 

The `pid_t` type is the data type used to represent process IDs.

### Answer

9. Explain its difference with `waitpid()`

### Answer

Allows more control over the process to wait for where you add an additional argument pid which specifies the process id to wait for.