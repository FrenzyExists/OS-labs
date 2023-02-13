## Ex 4

Complete the following script to sort a list of **words/numbers**.

Use the pointer `"word"` and the double pointer `"word_list"` to store the words given by the` STD Input`.

NOTE: Complete the code following the TODO hints

## For example:

### Test

```bash
Expected:
AAA
BBB
CCC
DDD
```

### Input

```
4
CCC
BBB
DDD
AAA
```

### Result

```
AAA
BBB
CCC
DDD
```


```c
#include "ex4.h"

int main (void) {
    
    int nlines;			/*number of input lines read */
    
    char *word;
    char **word_list;

    scanf("%d\n", &nlines);

    //TODO: INIT word AND word_list
    word_list = calloc(nlines, sizeof(char*));
    word = (char *)calloc(0, sizeof(char));


    // READ WORDS AND POINT EACH ELEMENT OF WORD_LIST TO A WORD
    for (int i = 0; i < nlines ; i++) {
        //TODO: INSERT YOUR CODE TO FILL word_list WITH THE STD INPUTS 
        fgets(word, MAX_CHARS, stdin);
        word_list[i] = (char *)calloc(sizeof(&word), sizeof(char));
        word_list[i] = word;
        
        word = (char *)calloc(0, sizeof(char));        
    }
    free(word);
    qsort_((void **) word_list, 0, nlines - 1, (int (*)(void *, void *)) (strcmp));

    // PRINT SORTED ELEMENTS: 
    for (int i = 0; i < nlines; i++) {
        printf("%s", word_list[i]);
    }

}

void qsort_ (void **v, int left, int right, int (*comp) (void *, void *))
{
    int i, last;
    void swap (void *v[], int, int);

    if (left >= right)
        return;
    swap (v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if ((*comp) (v[i], v[left]) < 0)
            swap (v, ++last, i);
    swap (v, left, last);

   qsort_ (v, left, last - 1, comp);
   qsort_ (v, last + 1, right, comp);
}


void swap (void *v[], int i, int j)
{
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
```