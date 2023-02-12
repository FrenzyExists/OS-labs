#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
   char command[300];
   char ls_grep[300];
   //copy the command to download the file
   //execute the command
   //copy the commmand to list the files
   //execute the command
   char url[] = "https://www.c-programming-simple-steps.com/support-files/return-statement.zip";
   
  snprintf(command, 300, "wget --quiet --no-verbose %s", url);
  //   snprintf(command, sizeof(command), "wget --no-verbose %s && ls | grep return | head -1", url);
  system(command);
  
  snprintf(ls_grep, 300, "ls | grep ^return");
  system(ls_grep);

   return(0);
} 