#include <iostream>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


int getFileStatus(const char* file){
    struct stat buf;
    int s = stat(file,&buf);
//    std::cout << buf.st_atime << "\n";
//    std::cout << buf.st_uid << "\n";
//    std::cout << buf.st_mtime << "\n";
//    std::cout << buf.st_ctime << "\n";
    if(S_ISDIR(buf.st_mode)){
        return 1;
    }else{
        return 0;
    }
}
int scanDir(const char* dir){
    std::string illegal = "..";
    std::string illegal2 = ".";
    std::cout << "CWD: " << dir << "\n";
    int changeError = chdir(dir);
    if(!changeError){
        struct dirent **nameList;
        int n = scandir("./",&nameList,NULL,alphasort);
        if(!n){
            std::cout << "No Files\n";
            return false;
        }else{
            while(n--){
                if(nameList[n]->d_name == illegal || nameList[n]->d_name == illegal2){
                    continue;
                }
                int dirCheck = getFileStatus(nameList[n]->d_name);
                if(dirCheck){
                    scanDir(nameList[n]->d_name);
                }else{
                    continue;
                }
            }
        }
    }else{
        std::cout << "There was an error changing directories\n";
    }
    return 1;    
}

int main(){
    scanDir("/srv/www/htdocs/vendor");
    return 0;
}