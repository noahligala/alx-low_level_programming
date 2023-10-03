#include "main.h"

void displayElfHeader(const Elf64_Ehdr *elfHeader)
{
	int i;


	printf("ELF Header:\n");
	printf("	Magic:	");
	for (i = 0; i < 16; i++)
	{
		printf("%02x ", elfHeader->e_ident[i]);
	}

	printf("\n");
	printf(" Class:			ELF%d\n", elfHeader->e_ident[4] == 1 ? 32 : 64);
	printf(" Data:			2's compliment, %s endian\n", elfHeader->e_ident[5] == 1 ? "little" : "big");
	printf(" Version:		%d (current)\n", elfHeader->e_version);
	printf(" OS/ABI:		UNIX - ");
	switch (elfHeader->e_ident[7])
	{
		case 0:
			printf("System V\n");
			break;

		case 3:
			printf("Linux\n");
			break;
		case 6:
			printf("Solaris\n");
			break;
		case 53:
			printf("NetBSD\n");
			break;
		default:
			printf("<unknown: %d>\n", elfHeader->e_ident[7]);
	}
	print(" ABI Version:		%d\n", elfHeader->e_ident[8]);
	printf(" Type:			");
	switch (elfHeader->e_type)
	{
		case 1:
			printf("REL (Relocatable file)\n");
			break;
		case 2:
			printf("EXEC (Executable file)\n");
			break;
		case 3:
			printf("DYN (Shared object file)\n");
			break;
		case 4:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown: %d>\n", elfHeader->e_type);
	}

	int main(int argc, char *argv[])
	{
		if (argc != 2)
		{
			dprint(2, "Usage: %s elf_filename\n", argv[0]);
			return (98);
		}


		const char *elfFilename = argv[1];
		int fd = open(elfFilename, O_RDONLY);

		if (fd == -1)
		{
			dprintf(2, "Error: Can't open file %s\n", elfFilename);
			return (98);
		}

		Elf64_Ehdr eldHeader;
		ssize_t bytesRead = read(fd, elfHeader, sizeof(elfHeader));

		if (bytesRead != sizeof(elfHeader))
		{
			dprintf(2, "Error: Can't Read ELF header from file %s\n", elfFilename);
			close(fd);
			return (98);
		}

		displayElfHeader(&elfHeader);
		close(fd);

		return (0);
	}
