

## Ex 4

Write a function that will setup the current process so that it can handle the following signals:

- SIGINT
- SIGQUIT
- SIGTERM
- SIGFPE
- SIGSEGV
- SIGILL

Your answer must include handler functions for each signal.  Each handler must print, for each signal received, the following line:

Received signal <name>!!!

where <name> is the mnemonic of the signal. 


## Ex 5

Write two functions with program errors that generate the following signals:

Signal 	Function prototype
SIGSEGV 	void generate_SIGFPE()
SIGFPE 	void generate_SISEGV()

```c
void generate_SIGSEGV() {
    raise(SIGSEGV);
}

void generate_SIGFPE() {
    raise(SIGFPE);
}
```

## Ex 6

Write a function to ignore the signal SIGSEGV using SIG_IGN.

```c
void ignore_SIGSEGV() {
    signal (SIGSEGV, SIG_IGN);
    // signal (SIGINT, SIG_IGN);

}
```

## Ex 7

Useful resources
http://www.gnu.org/software/libc/manual/html_mono/libc.html#Processes

Answer the following Questions:

1. What are the return values from the fork() function from the point of view of the parent and child process?

Ans: returns a pid_t. If the operation between a parent-child is successful, fork then a child process returns 0 while a parent process is the child's process ID. If process creation failed, fork returns a value of -1 in the parent process. 

2. What function is used to get the ID of a process?

getpid gets the ID of a process you specify in its argument and getpgrp gets the id the process which called said function

3. What function is used to get the ID of the parent process?

    *Answer*: p_id getppid(void)

4. What is a process image?

    *Answer*: program that the process is executing

5. What happens to the original process image when exec() is called?

    *Answer*: it replaces the current process image with a new process image. The new process image is specified by the path and arguments passed to the exec() function.

6. What are the differences among the family of exec() functions?

    *Answer*: They differ in the arguments they accept and their behavior. Some functions take an array of arguments, some take a variable number of arguments, and some allow for the specification of the environment variables to be passed to the new process. 

7. Explain the id_t waitpid (pid_t pid, int *status-ptr, int options) function


    *Amswer*: waitpid() returns the process ID of the child process that terminated, or -1 on error. It allows a parent process to wait for a child process to complete. It takes three arguments:

    pid: This argument specifies the process ID of the child process to wait for. The value -1 can be used to wait for any child process.

    status_ptr: This argument is a pointer to an int that will receive the exit status of the child process.

    options: This argument specifies options that control the behavior of waitpid(). Some of the options include WNOHANG, which returns immediately if the child process has not yet terminated, and WUNTRACED, which returns if the child process has stopped, but not yet terminated.


8. Explain the pid_t wait (int *status-ptr) function

a system call that allows a parent process to wait for its child process to terminate. Returns the child's process ID and sets the value of the status-ptr argument to the child's exit status. 

The pid_t type is the data type used to represent process IDs.

9. Explain its difference with waitpid()
Allows more control over the process to wait for where you add an additional argument pid which specifies the process id to wait for.

## Ex 8

```c
/* Example of use of fork system call */
#include <stdio.h>
main()
{
  int pid;  
  pid = fork();

  if (pid < 0) {
      fprintf(stderr, "Fork failed!\n");
      exit(-1);
  }
  else if (pid==0) {

      execlp("/bin/ps", "ps", NULL);

      printf("Still around...\n");
  }
  else {
      exit(0);
  }

}
```

*Answer*: So an example of how to use the fork function for system calls. We check if the pid is less than 0. If it is then fork has failed and we get an error message. Else we get the code executed by a child process. In this case the execlp, which replaces the current process image with a new process image specified by the path /bin/ps. The function execlp will only return only if there's an error. The parent process would be the block that is inside the else block, which in this case is just to exit the program.

## Ex 9 

Based on the code from the previous question:

1. Modify the program so the parent process waits for the child process to end before exiting.

2. Modify the program so the child process displays its own process id and the process id of its parent

3. Modify the program so the parent process displays the process id of its child. 






In this exercise, you will make use of all the basic knowledge we have been covering in previous parts: signals, processes and inter-process communication.

Please, peruse the following diagram and get familiar with the actors present and their relationships before you proceed.  

Complete client-server example diagram

        Each box represents a separate process.  
        The main process first forks the server process.  It then waits until it receives the SIGUSR1 signal, before forking the clients.  The server process sends this signal when it is ready to accept connections.  
        Each client process shares one forked (via connect/accept/fork) socket with a paired child server process.  Each client sends one of its messages to the child server and waits for a response.  When the response arrives, it outputs its contents to standard output, along with its identity.  It then proceeds to send the next message, if any, until all its messages have been sent.  Client processes exit after sending all their messages.  
        Child servers wait for messages to arrive from their paired client processes after connection.  When a message arrives, they output its contents to standard output along with their identity.  Then, they send the of the message back to the client process.  Child server processes exit after a prescribed amount of total idle time (about ten seconds).
        The server will shutdown (exit) when it receives the SIGINT signal (sent by the main process).  
        Finally, the zombie problem is avoided by having the server process wait for all its children to exit, before it exits.

    Notes:
        Message flow of each client-server(child) pair is decoupled from that of other pairs.  
        Any number of clients (as server resources allow) can connect and exchange messages concurrently.
        Sometimes the clients sleep between messages (about one second or so).  That makes it easier for the concurrency of the communication to show in the trace without sending many more messages. 
        Server child processes will spend some time waiting between message receives.  They must do so without taking too much valuable CPU time from other processes.  

The following is a verbose trace of what might happen with two clients, named "Uno" and "Dos", sending three messages each to its paired child server.  Messages in this run (only for this example trace) have the format "Message <child number>-<message number>".  Process IDs are included inside parenthesis when appropriate.

Main: Server(5896) forked...

Main: Server(5896) signaled ready to receive messages
Client Uno(5897) forked...
Client Dos(5898) forked...
Main: Waiting for client Uno(5897) to complete...
Server child(5899): got message: Mensaje 1-1
Client Uno(5897): Return message: Mensaje 1-1
Server child(5900): got message: Mensaje 2-1
Client Dos(5898): Return message: Mensaje 2-1
Server child(5899): got message: Mensaje 1-2
Server child(5900): got message: Mensaje 2-2
Client Uno(5897): Return message: Mensaje 1-2
Client Dos(5898): Return message: Mensaje 2-2
Server child(5899): got message: Mensaje 1-3
Server child(5900): got message: Mensaje 2-3
Client Dos(5898): Return message: Mensaje 2-3
Client Uno(5897): Return message: Mensaje 1-3
Child server(5900): sleeping 1...
Child server(5899): sleeping 1...
Main: Client Uno(5897) terminated with status: 0
Main: Waiting for client Dos(5898) to complete...
Main: Client Dos(5898) terminated with status: 0
Main: Killing server (5896)
Child server(5900): sleeping 2...
Child server(5899): sleeping 2...
Child server(5900): sleeping 3...
Child server(5899): sleeping 3...
Child server(5900): sleeping 4...
Child server(5899): sleeping 4...
Child server(5899): sleeping 5...
Child server(5900): sleeping 5...
Child server(5900): sleeping 6...
Child server(5899): sleeping 6...
Child server(5900): sleeping 7...
Child server(5899): sleeping 7...
Child server(5899): sleeping 8...
Child server(5900): sleeping 8...
Child server(5900): sleeping 9...
Child server(5899): sleeping 9...
Server(5896): child server with pid 5900 terminated with status: 0
Server(5896): child server with pid 5899 terminated with status: 0
Main: Server(5896) terminated with status: 0

Your job is to implement the code for the server (including children) and client processes.  You need to define the following functions, along with any supporting code:

void client(char *clientName, int numMessages, char *messages[]);

    clientName is a properly terminated string with the name of the client.

    numMessages is the number of messages to extract from messages.

    messages is an array of properly terminated strings, each with a message to be sent.

    This function is called within the body of the forked client process. It connects to the server (at address localhost:PORT_NUMBER) and sends each of the numMessages messages, as prescribed above. Instead of the verbose traces as shown above, this function must output the following lines for each message:

<name of client> : <client PID> : <message returned>

void server();

    This function is called within the body of the forked server process. It binds to PORT_NUMBER (at locahost) and accepts client connections, as prescribed above. 

    Instead of the verbose traces as shown above, this function must output the following lines for each message:

Server : <child server PID> : <message received>

    This function must send the SIGUSR1 signal to the parent process when it is ready to accept connections.

    This function must handle signal SIGINT to stop accepting connections and perform cleanup as prescribed above.

Any debugging output must be sent to the standard error (stderr).  Only properly formatted output should be sent to the standard output (stdout).  The automatic grader only looks at the standard output, and might get confused with unexpected output.

The following is an example output (over stdout) corresponding to the trace above:
Server : 7918 : Mensaje 1-1
Uno : 7916 : Mensaje 1-1
Server : 7919 : Mensaje 2-1
Dos : 7917 : Mensaje 2-1
Server : 7918 : Mensaje 1-2
Server : 7919 : Mensaje 2-2
Uno : 7916 : Mensaje 1-2
Dos : 7917 : Mensaje 2-2
Server : 7918 : Mensaje 1-3
Server : 7919 : Mensaje 2-3
Uno : 7916 : Mensaje 1-3
Dos : 7917 : Mensaje 2-3
Although your output might be a little different, it must have the following characteristics:

        Messages sent/received by different clients will alternate in the order of the lines
        All messages from all clients must be sent and received completely

Hints:

        Clients must connect to the same port to which the server is bound.  To avoid collisions with ports used by other students during test case runs, please, choose a port number with the following format:

[1-4]<last 4 digits of your student number>

For example, if your student number ends in 1234, we suggest you choose as port number one of the following: 11234, 21234, 31234 or 41234.

        Your processes should call fflush(stdout) after calling fprintf(stdout, ...) so that each line is printed as soon as possible.  
        You might find it easier to progress incrementally to the desired solution, rather than trying to implement all requirements at once.  Analyze the trace and diagram provided above to understand what need to be done and design the solution one piece at a time, testing each increment separately.
        Start by copying the code from the answer box to your favorite IDE editor.  Then, modify it until you have a working solution.  Only try to submit when you think you have a valid solution.  If you must submit an incomplete solution, you might do that as well, but you will need to wait for it to be graded by hand in order to see any partial points.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdbool.h>
#include <sys/un.h>
#include <signal.h>
#include <stdarg.h>

// Prototypes for internal functions and utilities
void error(const char *fmt, ...);
int runClient(char *clientName, int numMessages, char **messages);
int runServer();
void serverReady(int signal);

bool serverIsReady = false;

// Prototypes for functions to be implemented by students
void server();
void client(char *clientName, int numMessages, char *messages[]);

void verror(const char *fmt, va_list argp)
{
    fprintf(stderr, "error: ");
    vfprintf(stderr, fmt, argp);
    fprintf(stderr, "\n");
}

void error(const char *fmt, ...)
{
    va_list argp;
    va_start(argp, fmt);
    verror(fmt, argp);
    va_end(argp);
    exit(1);
}

int runServer(int port) {
    int forkPID = fork();
    if (forkPID < 0)
        error("ERROR forking server");
    else if (forkPID == 0) {
        server();
        exit(0);
    } else {
        printf("Main: Server(%d) launched...\n", forkPID);
    }
    return forkPID;
}

int runClient(char *clientName, int numMessages, char **messages) {
    fflush(stdout);
    printf("Launching client %s...\n", clientName);
    int forkPID = fork();
    if (forkPID < 0)

        error("ERROR forking client %s", clientName);
    else if (forkPID == 0) {
        client(clientName, numMessages, messages);
        exit(0);
    }
    return forkPID;
}

void serverReady(int signal) {
    serverIsReady = true;
}

#define NUM_CLIENTS 2
#define MAX_MESSAGES 5
#define MAX_CLIENT_NAME_LENGTH 10

struct client {
    char name[MAX_CLIENT_NAME_LENGTH];
    int num_messages;
    char *messages[MAX_MESSAGES];
    int PID;
};

// Modify these to implement different scenarios
struct client clients[] = {
        {"Uno", 3, {"Mensaje 1-1", "Mensaje 1-2", "Mensaje 1-3"}},
        {"Dos", 3, {"Mensaje 2-1", "Mensaje 2-2", "Mensaje 2-3"}}
};

int main() {
    signal(SIGUSR1, serverReady);
    int serverPID = runServer(getpid());
    while(!serverIsReady) {
        sleep(1);
    }
    printf("Main: Server(%d) signaled ready to receive messages\n", serverPID);

    for (int client = 0 ; client < NUM_CLIENTS ; client++) {
        clients[client].PID = runClient(clients[client].name, clients[client].num_messages,
                                        clients[client].messages);
    }

    for (int client = 0 ; client < NUM_CLIENTS ; client++) {
        int clientStatus;
        printf("Main: Waiting for client %s(%d) to complete...\n", clients[client].name, clients[client].PID);
        waitpid(clients[client].PID, &clientStatus, 0);
        printf("Main: Client %s(%d) terminated with status: %d\n",
               clients[client].name, clients[client].PID, clientStatus);
    }

    printf("Main: Killing server (%d)\n", serverPID);
    kill(serverPID, SIGINT);
    int statusServer;
    pid_t wait_result = waitpid(serverPID, &statusServer, 0);
    printf("Main: Server(%d) terminated with status: %d\n", serverPID, statusServer);
    return 0;
}



//*********************************************************************************
//**************************** EDIT FROM HERE *************************************
//#you can create the global variables and functions that you consider necessary***
//*********************************************************************************

#define PORT_NUMBER 44142

bool serverShutdown = false;

void shutdownServer(int signal) {
 //Indicate that the server has to shutdown
 //Wait for the children to finish
 //Exit
}

void client(char *clientName, int numMessages, char *messages[])
{
    char buffer[256];
    //Open the socket
    //Connect to the server
    //For each message, write to the server and read the response
    //Accept connection and create a child proccess to read and write 
    printf("Client %s(%d): Return message: %s\n", clientName, getpid(), buffer);
    fflush(stdout);
    sleep(1);
    //Close socket
}

void server()
{
    char buffer[256];
    //Handle SIGINT so the server stops when the main process kills it
    //Open the socket
    //Bind the socket
    //Signal server is ready
    //Accept connection and create a child proccess to read and write 
    printf("Server child(%d): got message: %s\n", getpid(), buffer); //expected output 
    //Close socket
}