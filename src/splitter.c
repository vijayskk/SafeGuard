#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void split_file(const char *filename, int num_parts) {
    FILE *input_file = fopen(filename, "r");
    if (input_file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Calculate the total number of lines in the file
    size_t line_count = 0;
    char *line = NULL;
    size_t len = 0;

    while (getline(&line, &len, input_file) != -1) {
        line_count++;
    }
    rewind(input_file); // Reset file pointer to the beginning

    // Determine the number of lines per part
    size_t lines_per_part = line_count / num_parts;
    size_t extra_lines = line_count % num_parts; // Extra lines to distribute evenly

    // Split the file into parts
    for (int i = 0; i < num_parts; i++) {
        char output_filename[256];
        snprintf(output_filename, sizeof(output_filename), "chunks/part_%d.txt", i + 1);

        FILE *output_file = fopen(output_filename, "w");
        if (output_file == NULL) {
            perror("Error creating output file");
            fclose(input_file);
            exit(EXIT_FAILURE);
        }

        size_t lines_to_write = lines_per_part + (i < extra_lines ? 1 : 0);
        for (size_t j = 0; j < lines_to_write; j++) {
            if (getline(&line, &len, input_file) == -1) {
                break; // Stop if we reach the end of the file
            }
            fprintf(output_file, "%s", line);
        }

        fclose(output_file);
    }

    // Cleanup
    fclose(input_file);
    free(line);

    printf("File successfully split into %d parts.\n", num_parts);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <filename> <number_of_parts>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *filename = argv[1];
    int num_parts = atoi(argv[2]);

    if (num_parts <= 0) {
        fprintf(stderr, "Number of parts must be greater than 0.\n");
        return EXIT_FAILURE;
    }

    split_file(filename, num_parts);

    return EXIT_SUCCESS;
}
