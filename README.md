
# stoopidC

The stoopid programing language rewritten in C

---

## How to Use

You can use the interpreter by running the command `stoopid <filename>`

## Build Instructions

If you dont use g++ change the `CC` variable in `makefile`

Requirements:

- C++ compiler, G++ recommended
- make

NOTE: mingw comes with make, its just named mingw32-make, so if you are using mingw just run `mingw32-make` instead of `make`

### Windows

1. create a folder called `build`
2. `make compile-windows`
3. `make exe`
4. `make del`
5. run `stoopid.exe` in the `build` folder with the script as an argument, for testing use `test.stpd`

### Linux

1. create a folder called `build`
2. `make compile-linux`
3. `make exe`
4. `make rm`
5. run `stoopid` in the `build` folder with the script as an argument, for testing use `test.stpd`

You can also use the provied debug scripts for your Operating System but they are just made for testing

## Guide

| Keyword | Description | Syntax |
| ------- | ----------- | ------ |
| var | Defines a variable | `var : <name> = <value>` |
| out | Prints something to the output | `out : <value>` |
| goto | Sets the next line to be read by the Interpreter | `goto : <linenumber>` |

### String

Strings can be combined with `+`

ints, bools and variables can also be combined with strings

### Math

Math equasions can be used anywhere

All standart operators can be used as well as `%` for modulo and `^` to get the power of something

Math equasions also support brackets

### Bools

Booleans are also completely implemented although they work different than in other languages

| Comparator | Description |
| ---------- | ----------- |
| `<<` | less than |
| `>>` | greater than |
| `<=` | less or equal |
| `>=` | greater or equal |
| `==` | equal |
| `!=` | not equal |
| `&&` | and |
| `\|\|` | or |
| `!` | not |

### Comments

Comments always need their own line and can be used by starting with `#`

Example: `# This is a comment`
