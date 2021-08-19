<h1 align=center>
	<b>printf</b>
</h1>

<h2 align=center>
	 <i>42cursus' project #3</i>
</h2>

<p align=center>
	The <b>printf</b> function is one of the most versatile and well-known functions in the C language. From a testing aid to tabulation method, printf is a very powerful and important tool in every dev's kit. This project aims to recreate the behaviour of the original MacOS's printf, including its basic error management, some of its flags, minimum field width stipulation and most of its basic conversions.

---
<div align=center>
<h2>
	Final score
</h2>
</div>

---

<h3 align=center>
Mandatory
</h3>

> <i>A small description of the required conversion:
> - %c print a single character.
> - %s print a string of characters.
> - %p The void * pointer argument is printed in hexadecimal.
> - %d print a decimal (base 10) number.
> - %i print an integer in base 10.
> - %u print an unsigned decimal (base 10) number.
> - %x print a number in hexadecimal (base 16).
> - %% print a percent sign.</i>

<h3 align=center>
Bonus
</h3>

> <i>Manage any combination of the following flags: 
> - ’-0.’ and minimum field width with all conversions
> - Manage all the following flags: ’# +’ (yes, one of them is a space)<i>

---

<h2>
The project
</h2>

### Implementation

- [`Makefile`](Makefile)
- [`libft functions`](libft/)
- [`header file`](include/libftprintf.h)
Main functions
- [`printf.c`](srcs/printf.c)
- [`initialize.c`](srcs/initialize.c)
- [`placeholder.c`](srcs/placeholder.c)
- [`parse.c`](srcs/parse.c)
- [`conversion.c`](srcs/printf.c)


---
<h2>
Usage
</h2>

### Instructions

When compiling `get_next_line` or its **bonus** version, be sure to include the following flags

```sh
$> gcc -Wall -Wextra -Werror -D BUFFER_SIZE=xxx <files>.c.
```

Where the `xxx` can be substituted by the number of bytes read at a time into the buffer for the `read` function. 
