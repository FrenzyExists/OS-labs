## Ex 1

In this challenge, you will learn to implement the basic functionalities of pointers in C. A [pointer](https://www.hackerrank.com/external_redirect?to=http://en.wikipedia.org/wiki/Pointer_%28computer_programming%29) in C is a way to share a memory address among different contexts (primarily functions). They are primarily used whenever a function needs to modify the content of a variable, of which it doesn't have ownership.

In order to access the memory address of a variable, we need to prepend it with `&` sign. E.g., `&val` returns the memory address of `val`.

This memory address is assigned to a pointer and can be shared among various functions. E.g. `int* p = &val`  will assign the memory address of  `val` to pointer `p`. To access the content of the memory to which the pointer points, prepend it with a `*`. For example, `*p` will return the value reflected by `val` and any modification to it will be reflected at the source (`val`)

```c
void increment(int *v) {
    (*v)++; 
}

int main() {
    int a;
    scanf("%d", &a); 
    increment(&a);
    printf("%d", a);
    return 0;      
    }     
```
You have to complete the function void update(int *a,int *b), which reads two integers as argument, and sets 
 with the difference (a-b) of them, and 

 with the absolute difference of them (b-a) if the result of a-b is even or the product of them if a-b is odd.

    a'=a-b
    if a' is odd: b'=|b-a|
    if a' is even:  b'=a*b

Explanation

    a = 0, b = 4
    a'=0-4=-4 //a' is even
    b'=0*4=0



## For example:

 ### Test 

```c
int a, b;
int * pa = &a, * pb = &b;

*pa = 0; *pb = 4;
update(&a,&b);
printf("a = %d, b = %d\n",a,b);

*pa = 1; *pb = 2;
update(&a,&b);
printf("a = %d, b = %d\n",a,b);

*pa = 10; *pb = 4;
update(&a,&b);
printf("a = %d, b = %d\n",a,b);

*pa = 13; *pb = 11;
update(&a,&b);
printf("a = %d, b = %d\n",a,b);
```

### Result

```c
a = -4, b = 0
a = -1, b = 1
a = 6, b = 40
a = 2, b = 143
```

## Answer

```c
void update(int *a, int *b){
    // TODO
    int old_a = *a;
    (*a) = *a - *b;
    if (*a % 2 != 0) {
        (*b) = abs(*b-old_a);
    } else {
        (*b) = (old_a) * (*b);
    }
}
```