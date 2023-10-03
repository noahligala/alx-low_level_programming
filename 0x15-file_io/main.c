#include "main.h"
#include "elf_header.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
	fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        return EXIT_FAILURE;
    }

    int elf_fd = open(argv[1], O_RDONLY);
    if (elf_fd == -1) {
        perror("Error");
        return EXIT_FAILURE;
    }

    Elf64_Ehdr elfHeader;
    if (read(elf_fd, &elfHeader, sizeof(Elf64_Ehdr)) == -1) {
        perror("Error");
        close(elf_fd);
        return EXIT_FAILURE;
    }

    displayElfHeader(&elfHeader);
    close(elf_fd);
    return EXIT_SUCCESS;
}
