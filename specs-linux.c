#include "stdio.h" // FILE, fopen, fgets, puts, 
#include "string.h" // strlen, strncmp, strcpy, strtok
#include "stdlib.h" // system
#define MAX 1024

char *extract_attline(char *file, char *attribute){
    char *readline = malloc(sizeof(char)*MAX);
    char *attline = malloc(sizeof(char)*MAX);
    FILE *pfile = fopen(file, "rb");
    if (pfile == NULL){
        printf("Error! Could not open file\n"); 
        exit(-1); // must include stdlib.h 
    }
    while (fgets(readline, MAX, pfile) != NULL) {
        if(strncmp(readline, attribute, strlen(attribute)) == 0){
            strcpy(attline, readline);
            break;
        }
    }
    pclose(pfile);
    free(readline);
    strtok(attline, "\n"); //delete break line '\n'
    return attline;
}

int main(){
    printf("Get SW and HW specs from your computer with linux\n\n");
    printf("Option 1: Extracting data from '/proc' and '/etc' directories\n");
    char *cpumodel = extract_attline("/proc/cpuinfo", "model name");
    char *memtotal = extract_attline("/proc/meminfo", "MemTotal");
    char *os = extract_attline("/etc/os-release", "PRETTY_NAME=");
    printf("%s\n", cpumodel);
    printf("%s\n", memtotal);
    printf("%s\n", os);
    printf("\n");
    printf("Option 2: Extracting data from 'lshw' command\n");
    system("lshw -short > lshw_data");
    char *processor = extract_attline("lshw_data", "/0/1");
    char *memory = extract_attline("lshw_data", "/0/0");
    printf("%s\n", processor);
    printf("%s\n", memory);
    return 0;
}