#include<stdio.h>
#include<fcntl.h>
#include <sys/time.h>
#include <sys/stat.h>

#define MAX 20
#define BUFFER_SIZE 1024

int main(int argc, char* argv){
    struct timeval start, end;
    struct stat st;
    int source_file, target_file, source_file_size;
    long long counter = 0;
    int bytes_read, bytes_write;
    char buffer[BUFFER_SIZE], source_file_name[MAX], target_file_name[MAX];

    printf("Enter the Source File Name :");
    scanf("%s", source_file_name);
    printf("Enter the Target File Name :");
    scanf("%s", target_file_name);

    gettimeofday(&start, NULL);

    source_file = open(source_file_name, O_RDONLY);
    target_file = open(target_file_name, O_WRONLY | O_EXCL | O_CREAT);

    if(source_file == -1){
        perror("cant do shit");
        return 1;
    }
    if(stat(source_file_name, &st)==0){
        source_file_size = st.st_size;
    }

    if(target_file == -1){
        perror("Bruh");
        close(source_file);
        return 2;
    }
    
    while ( (bytes_read = read (source_file, &buffer, BUFFER_SIZE)) > 0){
        counter += BUFFER_SIZE;
        bytes_write = write(target_file, &buffer, (int) bytes_read);  
        double progress = ((double)counter / source_file_size)*100.0;
        printf("\rDone %d KB/ %d KB  %.2f%%", counter/1024, source_file_size/1024, progress);
    }
    gettimeofday(&end, NULL);

    close(source_file);
    close(target_file);
    double time = ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec))/1000000;
    printf("\nCopy Complete in %.4f sec\n", time);

    return 0;

}
