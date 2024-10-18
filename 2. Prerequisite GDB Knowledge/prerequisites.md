# Cheatsheet 1

## Basics of operating GDB

  - First make sure to compile with '-g' or a higher level (e.g. -g3) to get debug symbols.  eg gcc -ggdb lesson.c -o prog
  - gdb --silent ./prog
  - 'run' and 'start' are how we launch our program
  - 's' steps into function one line at a time
  - 'n' moves us to 'next' visible line in our src code

## GDB control flow

  - 'br' creates breakpoint.  eg 'br 18' and 'br lesson.c:18' to set breakpoint at line no 18
  - 'c' continues execution

## GDB info display

  - '^+l' clears our screen
  - 'print <variable>' will print out that variable value.  eg print i 
  - 'bt' and 'backtrace' will give us callstack
  - 'info locals' retrieves all variable values

## GDB TUI mode 

  - 'layout src' is one way to launch tui mode.
  - 'focus cmd' and 'focus src' a is way to switch between command window and source window.
  
