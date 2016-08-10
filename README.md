# SimpVM
## Purpose
A simple stack-based VM with the following commands:
* `push <num>` - pushes `<num>` onto stack
* `pop` - pops top value from stack and discards it
* `add` - pops top two values from stack, adds them, then pushes result onto stack
* `ifeq <linenum>` - pops top value from stack, if 0, jump to `<linenum>`, else continue
* `jump <linenum>` - unconditionally jump to `<linenum>`
* `print` - pops top value from stack and prints it
* `dup` - push a copy of the top value in stack onto stack

## Usage
	make
	./simpVM example.txt
Runs the commands in `example.txt`.

## Future
* Stack manipulation commands (roll, switch, etc.)
* Labels instead of line numbers
* New syntax: if-then-else, while
Those last two will probably be better put in a compiler that turns C-like syntax into the current syntax.

## License
This code is provided as is, with no guarantee of it working, simply for my own illumination.
