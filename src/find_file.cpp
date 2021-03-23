#include <string>
#include <iostream>
#include <dirent.h>
#include <sys/types.h>

/* struct dirent readdir(DIR *dirp);
function is defined in dirent.h, representing directory entry 
at the current position in directory stream dirp. On every call 
to readdir() method, it returns file/directory at current position
in directory stream. readdir() return NULL pointer if reached 
at the end of stream
*/

/* DIR *opendir(const char *dirname);
Similar to file streams, opendir() opens a directory stream 
corresponding to the file path pointed by dirname. 
By default the opened directory stream points to first entry 
in the directory.
On success, the function returns a pointer to structure of DIR type.
Otherwise NULL pointer.
*/

/* int closedir(DIR *dirp);
*/

/* How to list all files and directories of a directory
1/ Input source path to list all files and sub-directories. Store it in some variable say path.
2/ Open directory stream using opendir() and store its reference to *dir of DIR type.
3/ Initialize another variable of pointer to structure dirent type, say struct dirent *dp.
4/ Read next element from directory stream using dp = readdir(dir).
5/ Print current directory stream item name, using dp->name.
6/ Repeat step 4-5 till dp != NULL.
4/ Finally, close the directory stream pointed by dir variable.
*/

void listFiles(const char *path){
    struct dirent *dp;
    DIR *dir=opendir(path);

    // Unable to open directory stream
    if(!dir)
        return;

    while ((dp = readdir(dir)) != NULL)
    {
        printf("%s\n", dp->d_name);
    }
    closedir(dir);
}

int main()
{
    // Directory path to list files
    char path[100];

    // Input path from user
    printf("Enter path to list files:");
    scanf("%s",path);

    listFiles(path);

    return 0;

}


