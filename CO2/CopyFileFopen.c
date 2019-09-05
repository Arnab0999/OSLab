#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fs, *ft;
    int ch;

    fs = fopen("input.out", "rb");
    if(fs == NULL){
        puts("Cannot open source file! Exiting...\n");
        exit(1);
    }

    ft = fopen("output.out", "wb");

    if(ft == NULL){
        puts("Cannot open taget file! Exiting...\n");
        fclose(fs);
        exit(2);
    }

    while (1) {
        ch = fgetc(fs);

        if(ch == EOF){
            break;
        }
        else{
            fputc(ch, ft);
        }
    }
    
    fclose(fs);
    fclose(ft);

    return 0;

}



//tells about the size of the file
// #include<stdio.h>
// #include<stdlib.h>

// int main(){
//     FILE *fs, *ft;
//     int ch;

//     fs = fopen("input.mp4", "rb");
//     if(fs == NULL){
//         puts("Cannot open source file! Exiting...\n");
//         exit(1);
//     }

//     ft = fopen("output.mp4", "wb");

//     if(ft == NULL){
//         puts("Cannot open taget file! Exiting...\n");
//         fclose(fs);
//         exit(2);
//     }
//     long long size_source = 0, size_target = 0;

//     while (1) {
//         //system("cls");
//         ch = fgetc(fs);
        
//         // fseek(fs, 0, 2);    /* file pointer at the end of file */
//         // size_source = ftell(fs);   /* take a position of file pointer un size variable */

//         // fseek(ft, 0, 2);    /* file pointer at the end of file */
//         // size_target = ftell(ft); 


//         // printf("Done %d/%d gg\n", size_target, size_source); 
//         if(ch == EOF){
//             break;
//         }
//         else{
//             fputc(ch, ft);
//         }
//     }
    
//     fclose(fs);
//     fclose(ft);
//     printf("done");
//     return 0;

// }
