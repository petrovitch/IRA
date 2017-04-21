#include <iostream>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


int getFileStatus(){
    struct stat buf;
    int s = stat("/srv/www/htdocs/cPlus/testdata.txt",&buf);
    std::cout << buf.st_atime << "\n";
    std::cout << buf.st_uid << "\n";
    std::cout << buf.st_mtime << "\n";
    std::cout << buf.st_ctime << "\n";
    return 1;
}
int scanDir(std::string dir){
    int changeError = chdir(dir);
    if(!changeError){
        struct dirent **nameList;
        int n = scandir("./",&nameList,NULL,alphasort);
        std::cout << n << "\n";
        if(!n){
            std::cout << "No Files\n";
        }else{
            std::cout << nameList << "\n";
                while(n--){
                    //std::cout << nameList[n]->d_name << "\n";
                }
            }
        }else{
            std::cout << "There was an error changing directories\n";
        }
    return 1;    
}

int main(){
    scanDir("/srv/www/htdocs/");
    getFileStatus();
    return 0;
}