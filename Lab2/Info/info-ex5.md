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