## Ex 6

Write a function to ignore the signal SIGSEGV using SIG_IGN.

```c
void ignore_SIGSEGV() {
    signal (SIGSEGV, SIG_IGN);
}
```