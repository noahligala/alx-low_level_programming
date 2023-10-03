#include "main.h"

/**
 * display_error - Display an error message and exit with status code 98.
 * @msg: The error message to display.
 */
void display_error(char *msg)
{
	dprintf(STDERR_FILENO, "%s\n", msg);
	exit(98);
}

/**
 * check_elf - Check if the given file is an ELF file.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 */
void check_elf(unsigned char *e_ident)
{
	int i;
	
	unsigned char magic[] = {0x7F, 'E', 'L', 'F'};
	for (i = 0; i < EI_NIDENT; i++)
	{
		if (e_ident[i] != magic[i])
			display_error("Error: Not an ELF file");
	}	
}
/**
 * print_elf_header - Print the information from the ELF header.
 * @header: A pointer to the ELF header.
 */
void print_elf_header(Elf64_Ehdr *header)
{
	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (int i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", header->e_ident[i]);
		if (i < EI_NIDENT - 1)
			printf(" ");
		else
			printf("\n");
	}
	printf("  Class:                             ");
	switch (header->e_ident[EI_CLASS])
	{
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("Unknown\n");
	}
	printf("  Data:                              ");
	switch (header->e_ident[EI_DATA])
	{
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("Unknown\n");
	}
	printf("  Version:                           %d (current)\n", header->e_ident[EI_VERSION]);
	printf("  OS/ABI:                            ");
	switch (header->e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
		default:
			printf("Unknown (%x)\n", header->e_ident[EI_OSABI]);
	}
	printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);
	printf("  Type:                              ");
	switch (header->e_type)
	{
		case ET_NONE:
			printf("NONE (None)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("Unknown (%x)\n", header->e_type);
	}
	printf("  Entry point address:               %#lx\n", header->e_entry);
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of pointers to the command-line arguments.
 *
 * Return: 0 on success, 98 on error.
 *
 * Description: This program displays the information contained in the ELF header
 * at the start of an ELF file. It checks if the provided file is an ELF file,
 * prints various attributes from the ELF header, and handles errors accordingly.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
		display_error("Usage: elf_header elf_filename");

	int fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		display_error("Error: Can't read file");
	
	Elf64_Ehdr header;
	if (read(fd, &header, sizeof(header)) != sizeof(header))
	{
		close(fd);
		display_error("Error: Can't read file");
	}
	
	check_elf(header.e_ident);
	print_elf_header(&header);
	
	close(fd);
	return (0);
}
