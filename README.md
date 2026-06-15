*This project has been created as part of the 42 curriculum by tireis.*

## Description

The goal of this project is to implement a function that reads a file descriptor line by line. Each call to `get_next_line()` returns the next available line from the file, including the newline character `\n` when present.

This project introduces several important concepts in C programming:

* Static variables
* File descriptors
* Low-level I/O with `read()`
* Dynamic memory management
* String manipulation
* Buffering techniques

The main challenge is preserving unread data between function calls while returning exactly one line at a time.

---

## Compilation

Compile with:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 *.c
```

You can test different buffer sizes:

```bash
-D BUFFER_SIZE=1
-D BUFFER_SIZE=1024
```

---

## Usage Example

```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
	int		fd;
	char	*line;

	fd = open("file.txt", O_RDONLY);
	if (fd < 0)
		return (1);

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
```

---

## Detailed Description

The implementation uses a static stash to store unread data between function calls.

### 1. Reading and Stashing

The function `stashing()` reads from the file descriptor using `read()` until:

* A newline character is found
* End of file is reached
* An error occurs

Each newly read buffer is appended to the existing stash.

Example:

```text
BUFFER_SIZE = 4

File:
Hello
World

Read #1 -> "Hell"
Read #2 -> "o\nWo"

Stash:
"Hello\nWo"
```

The stash now contains enough data to return the first line.

---

### 2. Extracting the Line

The function `cutline()` extracts exactly one line from the stash.

Example:

```text
Stash:
"Hello\nWo"

Returned line:
"Hello\n"
```

Memory is allocated only for the returned line.

---

### 3. Cleaning the Stash

After returning a line, `cleanfunc()` removes the extracted portion and keeps only the remaining unread data.

Example:

```text
Before:
"Hello\nWo"

After:
"Wo"
```

This remaining data is stored in the static stash and reused during the next call.

---

### 4. End of File

When EOF is reached:

```text
Stash:
"Last line"
```

The final line is returned.

Afterwards:

```text
stash = NULL
```

and subsequent calls return:

```c
NULL
```

---

## Function Structure

### `join_free()`

Concatenates the current stash with newly read data and frees the old stash.

### `stashing()`

Reads from the file descriptor until a complete line or EOF is reached.

### `cutline()`

Extracts the next line from the stash.

### `cleanfunc()`

Removes the extracted line and stores any leftover data.

### `get_next_line()`

Coordinates the entire process:

1. Validate input
2. Fill the stash
3. Extract a line
4. Update the stash
5. Return the line

---

## Memory Management

Special care is taken to avoid memory leaks:

* Every allocation is checked
* Old stash contents are freed when replaced
* Errors free allocated memory before returning
* The static stash is cleaned when EOF or an error occurs

The implementation successfully handles:

* Empty files
* Files without trailing newline
* Very small BUFFER_SIZE values
* Large BUFFER_SIZE values
* Invalid file descriptors
* Read errors

---

## Concepts Learned

* Static variables
* Dynamic memory allocation
* File descriptors
* Buffered reading
* String handling
* Error management
* Memory leak prevention

---

## Resources

### Documentation

* https://man7.org/linux/man-pages/man2/read.2.html
* https://en.cppreference.com/w/c/io/fgets
* https://www.gnu.org/software/libc/manual/
* 42 subject: get_next_line.pdf

### AI Usage

AI tools were used for:

* Debugging memory leaks
* Investigating segmentation faults
* Reviewing edge cases
* Improving documentation structure

All implementation decisions and final code behavior were understood and verified manually.

---

## Notes

* Supports any valid BUFFER_SIZE.
* Returns one line per function call.
* Preserves unread data using a static stash.
* Correctly handles EOF and read errors.
* Fully compliant with the 42 project requirements.

