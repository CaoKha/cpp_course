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

void listFiles(const std::string path)
{
    struct dirent *dp;                // pointer of type "struct dirent"
    DIR *dir = opendir(path.c_str()); // pointer points to the first file in the folder

    // Unable to open directory stream
    if (!dir)
        return;

    while ((dp = readdir(dir)) != NULL)
    {
        std::cout << dp->d_name << std::endl;
    }
    closedir(dir);
}

void listFilesRecursively(std::string &basePath, std::string &pathResult, const std::string &fileToFind, bool &found)
{
    std::string path;
    struct dirent *dp;
    DIR *dir = opendir((char *)basePath.c_str());

    // Unable to open directory stream
    if (!dir)
    {
        //do nothing
        return;
    }

    while ((dp = readdir(dir)) != NULL)
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {
            path.assign(basePath);
            path.append("/");
            path.append(dp->d_name);
            std::cout << path << std::endl;
            if (std::string(dp->d_name).compare(fileToFind) == 0)
            {
                pathResult = path;
                found = true;
            }
            listFilesRecursively(path, pathResult, fileToFind, found);
        }
    }
    closedir(dir);
}

int main()
{
    std::string path("C:/Users/nguye/Documents/code/cpp_course");
    std::string pathResult;
    std::string fileToFind("zim.cpp");
    bool found = false;
    listFilesRecursively(path, pathResult, fileToFind, found);
    if (found)
        std::cout << "Found at: " << pathResult << std::endl;
    else
        std::cout << "Not found!" << std::endl;
}
