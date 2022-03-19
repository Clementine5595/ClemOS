// GCC provides these header files automatically
// They give us access to useful things like fixed-width types
#include <lib/libscr.h>

void main()
{
	term_init();
	term_print("Hello, World!\n");
	term_print("Welcome to the kernel.\n");
}