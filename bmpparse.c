#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int width;                      
    int height;                     
    unsigned short bits_per_pixel;  
    unsigned char *pixel_data;     
} ParsedFile;

unsigned char *read_file(const char *filename, long *out_size) {

    FILE *fptr = fopen(filename, "rb");
    if (fptr == NULL) {
        perror("Error opening file");
        return NULL;
    }
    fseek(fptr, 0, SEEK_END);
    long file_size = ftell(fptr);
    rewind(fptr);

    unsigned char *buffer = (unsigned char *)malloc(file_size);
    if (buffer == NULL) {
        perror("Error allocating memory");
        fclose(fptr);
        return NULL;
    }
    size_t read_size = fread(buffer, 1, file_size, fptr);
    fclose(fptr);

    if (out_size != NULL) {
        *out_size = file_size;
    }

    return buffer;
}

int parse_file(unsigned char *buffer, long file_size, ParsedFile *outbmp) {
    if (buffer == NULL || outbmp == NULL || file_size < 54) {
        return 0;
    }
    if(buffer[0] != 'B' || buffer[1] != 'M') {
        fprintf(stderr, "Error: Not a valid BMP file\n");
        free(buffer);
        return 0;
    }
    int data_offset = *(int*)&buffer[10];
    outbmp -> width = *(int*)&buffer[18];
    outbmp -> height = *(int*)&buffer[22];
    outbmp -> bits_per_pixel = *(unsigned short*)&buffer[28];

    if (outbmp -> bits_per_pixel != 24) {
        fprintf(stderr, "Error: Only 24-bit BMP files are supported\n");
        return 0;
    }
    outbmp -> pixel_data = &buffer[data_offset];
    return 1;
}

int main(){
    long size = 0;
    unsigned char *data = read_file("test.bmp", &size);
    if (data == NULL) {
        fprintf(stderr, "Failed to parse file\n");
        return EXIT_FAILURE;
    }

    ParsedFile parsed_file;
    if(parse_file(data , size, &parsed_file) == 0) {
        free(data);
        return EXIT_FAILURE;
    }

    free(data);
    return 0;
}
