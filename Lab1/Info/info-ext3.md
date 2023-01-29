In this problem, you will implement a decoder that produces strings from ciphertexts by:

    1. Converting the string into an nxn matrix in column-major order

    2. Generating the new string by reading the matrix in row major order

For example, the following matrix would be constructed for the input string "WECGEWHYAAIORTNU":

    W E A R
    E W A T
    C H  I N
    G Y O U


Taking characters in row-major order from this matrix, the decrypted text would read:

    WEAREWATCHINGYOU

Input Format

Input starts with a line consisting of a single number T. T test cases follow. Each test case consists of one line. This line contains the cipher text. The cipher text contains either UPPERCASE letters or blank spaces.  

Constraints

Total number of character in the text will not be more 10,000.

Output Format

For each test case, the output contains a single line containing the decrypted text. If the number of characters in the input text is not square of any number, then give the output ‘INVALID’

For example:
Test 	Result

char cmd[MAX_CHARS];

strcpy(cmd, "WE OUE OUT LNGSAO H RWDN!");
decode(cmd); // Expected: WE ARE LOW ON DOUGHNUTS !
memset(cmd,0,MAX_CHARS);

strcpy(cmd, "S EFEM FNOCEDROE");
decode(cmd); // Expected: SEND MORE COFFEE
memset(cmd,0,MAX_CHARS);

strcpy(cmd, "CSERULES");
decode(cmd); // Expected: INVALID
memset(cmd,0,MAX_CHARS);

	

WE ARE LOW ON DOUGHNUTS !
SEND MORE COFFEE
INVALID
[]