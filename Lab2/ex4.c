#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void handle_sigint(int signal) {
    printf("Received signal SIGINT!!!\n");
}

void handle_sigquit(int signal) {
    printf("Received signal SIGQUIT!!!\n");
}

void handle_sigterm(int signal) {
    printf("Received signal SIGTERM!!!\n");
}

void handle_sigfpe(int signal) {
    printf("Received signal SIGFPE!!!\n");
}

void handle_sigsegv(int signal) {
    printf("Received signal SIGSEGV!!!\n");
}

void handle_sigill(int signal) {
    printf("Received signal SIGILL!!!\n");
}

void setup_signal_handlers() {
    // Setup handlers for each signal
    signal(SIGINT, handle_sigint);
    signal(SIGQUIT, handle_sigquit);
    signal(SIGTERM, handle_sigterm);
    signal(SIGFPE, handle_sigfpe);
    signal(SIGSEGV, handle_sigsegv);
    signal(SIGILL, handle_sigill);
}

int main(int argc, char *argv[]) {
    setup_signal_handlers();
    raise(SIGINT);

    return 0;
}