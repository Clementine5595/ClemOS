// GCC provides these header files automatically
// They give us access to useful things like fixed-width types
#include <libscr.h>
#include <keyboard.h>

int alive = 1;

void main()
{
	kb_init();
	init_video();
	puts("Hello, World!\n");
	puts("Welcome to the kernel.\n");
	while(alive) {
		keyboard_handler_main();
	}
}