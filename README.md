# 📜 Complete Libft to be used in 42 Projects

## 📂 Libft Functions
<details>
<summary>1️⃣ String Handling</summary>

<table>
<tr>
<th>Function</th>
<th>Prototype</th>
<th>Description</th>
</tr>
<tr>
<td><small>**ft_strlen**</small></td>
<td><small>`size_t ft_strlen(const char *str);`</small></td>
<td><small>Computes the length of a string.</small></td>
</tr>
<tr>
<td><small>**ft_strlcpy**</small></td>
<td><small>`size_t ft_strlcpy(char *dst, const char *src, size_t size);`</small></td>
<td><small>Copies a string into a destination buffer with size limit.</small></td>
</tr>
<tr>
<td><small>**ft_strlcat**</small></td>
<td><small>`size_t ft_strlcat(char *dst, const char *src, size_t size);`</small></td>
<td><small>Appends a string to another with size control.</small></td>
</tr>
<tr>
<td><small>**ft_strncmp**</small></td>
<td><small>`int ft_strncmp(const char *s1, const char *s2, size_t n);`</small></td>
<td><small>Compares two strings up to `n` characters.</small></td>
</tr>
<tr>
<td><small>**ft_strdup**</small></td>
<td><small>`char *ft_strdup(const char *s);`</small></td>
<td><small>Duplicates a string.</small></td>
</tr>
<tr>
<td><small>**ft_strjoin**</small></td>
<td><small>`char *ft_strjoin(char const *s1, char const *s2);`</small></td>
<td><small>Concatenates two strings.</small></td>
</tr>
<tr>
<td><small>**ft_strchr**</small></td>
<td><small>`char *ft_strchr(const char *s, int c);`</small></td>
<td><small>Locates a character in a string.</small></td>
</tr>
<tr>
<td><small>**ft_strrchr**</small></td>
<td><small>`char *ft_strrchr(const char *s, int c);`</small></td>
<td><small>Locates a character in a string from the end.</small></td>
</tr>
</table>

</details>

<details>
<summary>2️⃣ Memory Management</summary>

<table>
<tr>
<th>Function</th>
<th>Prototype</th>
<th>Description</th>
</tr>
<tr>
<td><small>**ft_memset**</small></td>
<td><small>`void *ft_memset(void *s, int c, size_t n);`</small></td>
<td><small>Fills memory with a constant byte.</small></td>
</tr>
<tr>
<td><small>**ft_memcpy**</small></td>
<td><small>`void *ft_memcpy(void *dest, const void *src, size_t n);`</small></td>
<td><small>Copies memory area.</small></td>
</tr>
<tr>
<td><small>**ft_memmove**</small></td>
<td><small>`void *ft_memmove(void *dest, const void *src, size_t n);`</small></td>
<td><small>Moves memory area, handling overlaps safely.</small></td>
</tr>
<tr>
<td><small>**ft_memcmp**</small></td>
<td><small>`int ft_memcmp(const void *s1, const void *s2, size_t n);`</small></td>
<td><small>Compares memory areas.</small></td>
</tr>
<tr>
<td><small>**ft_memchr**</small></td>
<td><small>`void *ft_memchr(const void *s, int c, size_t n);`</small></td>
<td><small>Searches for a byte in a memory area.</small></td>
</tr>
<tr>
<td><small>**ft_calloc**</small></td>
<td><small>`void *ft_calloc(size_t nmemb, size_t size);`</small></td>
<td><small>Allocates and zeroes out memory.</small></td>
</tr>
<tr>
<td><small>**ft_bzero**</small></td>
<td><small>`void ft_bzero(void *s, size_t n);`</small></td>
<td><small>Sets a block of memory to zero.</small></td>
</tr>
</table>

</details>

<details>
<summary>3️⃣ Integer Handling</summary>

<table>
<tr>
<th>Function</th>
<th>Prototype</th>
<th>Description</th>
</tr>
<tr>
<td><small>**ft_atoi**</small></td>
<td><small>`int ft_atoi(const char *nptr);`</small></td>
<td><small>Converts a string to an integer.</small></td>
</tr>
</table>

</details>

<details>
<summary>4️⃣ Character Checks</summary>

<table>
<tr>
<th>Function</th>
<th>Prototype</th>
<th>Description</th>
</tr>
<tr>
<td><small>**ft_isalpha**</small></td>
<td><small>`int ft_isalpha(int c);`</small></td>
<td><small>Checks if a character is alphabetic.</small></td>
</tr>
<tr>
<td><small>**ft_isdigit**</small></td>
<td><small>`int ft_isdigit(int c);`</small></td>
<td><small>Checks if a character is a digit.</small></td>
</tr>
<tr>
<td><small>**ft_isalnum**</small></td>
<td><small>`int ft_isalnum(int c);`</small></td>
<td><small>Checks if a character is alphanumeric.</small></td>
</tr>
<tr>
<td><small>**ft_isascii**</small></td>
<td><small>`int ft_isascii(int c);`</small></td>
<td><small>Checks if a character is an ASCII character.</small></td>
</tr>
<tr>
<td><small>**ft_isprint**</small></td>
<td><small>`int ft_isprint(int c);`</small></td>
<td><small>Checks if a character is printable.</small></td>
</tr>
<tr>
<td><small>**ft_tolower**</small></td>
<td><small>`int ft_tolower(int c);`</small></td>
<td><small>Converts a character to lowercase.</small></td>
</tr>
<tr>
<td><small>**ft_toupper**</small></td>
<td><small>`int ft_toupper(int c);`</small></td>
<td><small>Converts a character to uppercase.</small></td>
</tr>
</table>

</details>

<details>
<summary>5️⃣ Input & Output</summary>

<table>
<tr>
<th>Function</th>
<th>Prototype</th>
<th>Description</th>
</tr>
<tr>
<td><small>**ft_putchar_fd**</small></td>
<td><small>`void ft_putchar_fd(char c, int fd);`</small></td>
<td><small>Outputs a character to a file descriptor.</small></td>
</tr>
<tr>
<td><small>**ft_putstr_fd**</small></td>
<td><small>`void ft_putstr_fd(char *s, int fd);`</small></td>
<td><small>Outputs a string to a file descriptor.</small></td>
</tr>
<tr>
<td><small>**ft_putendl_fd**</small></td>
<td><small>`void ft_putendl_fd(char *s, int fd);`</small></td>
<td><small>Outputs a string to a file descriptor, followed by a newline.</small></td>
</tr>
<tr>
<td><small>**ft_putnbr_fd**</small></td>
<td><small>`void ft_putnbr_fd(int n, int fd);`</small></td>
<td><small>Outputs an integer to a file descriptor.</small></td>
</tr>
</table>

</details>

<details>
<summary>6️⃣ Linked List Management</summary>

<table>
<tr>
<th>Function</th>
<th>Prototype</th>
<th>Description</th>
</tr>
<tr>
<td><small>**ft_lstnew**</small></td>
<td><small>`t_list *ft_lstnew(void *content);`</small></td>
<td><small>Creates a new list node.</small></td>
</tr>
<tr>
<td><small>**ft_lstadd_front**</small></td>
<td><small>`void ft_lstadd_front(t_list **lst, t_list *new);`</small></td>
<td><small>Adds a node at the beginning of a list.</small></td>
</tr>
<tr>
<td><small>**ft_lstadd_back**</small></td>
<td><small>`void ft_lstadd_back(t_list **lst, t_list *new);`</small></td>
<td><small>Adds a node at the end of a list.</small></td>
</tr>
<tr>
<td><small>**ft_lstsize**</small></td>
<td><small>`int ft_lstsize(t_list *lst);`</small></td>
<td><small>Returns the number of nodes in a list.</small></td>
</tr>
<tr>
<td><small>**ft_lstlast**</small></td>
<td><small>`t_list *ft_lstlast(t_list *lst);`</small></td>
<td><small>Returns the last node of a list.</small></td>
</tr>
</table>

</details>

---

## 📂 Printf Functions

<details>
<summary>📜 Core Printing Functions</summary>

<table>
<tr>
<th>Function</th>
<th>Prototype</th>
<th>Description</th>
</tr>
<tr>
<td><small>**ft_printf**</small></td>
<td><small>`int ft_printf(const char *format, ...);`</small></td>
<td><small>Main function that mimics `printf()`, parsing format specifiers and printing accordingly.</small></td>
</tr>
<tr>
<td><small>**ft_printf_numbers**</small></td>
<td><small>`int ft_printf_numbers(int num, t_parser *info, t_padding *pad);`</small></td>
<td><small>Handles integer formatting (`d`, `i`, `u`).</small></td>
</tr>
<tr>
<td><small>**ft_printf_strings**</small></td>
<td><small>`int ft_printf_strings(const char *str, t_parser *info, t_padding *pad);`</small></td>
<td><small>Handles string formatting (`s`).</small></td>
</tr>
</table>

</details>

---

## 📂 gnl Functions

<details>
<summary>📜 Core Functionality</summary>

<table>
<tr>
<th>Function</th>
<th>Prototype</th>
<th>Description</th>
</tr>
<tr>
<td><small>**get_next_line**</small></td>
<td><small>`char *get_next_line(int fd);`</small></td>
<td><small>Reads a single line from a file descriptor.</small></td>
</tr>
<tr>
<td><small>**ft_strlen_gnl**</small></td>
<td><small>`size_t ft_strlen_gnl(const char *str);`</small></td>
<td><small>Custom `strlen` for `get_next_line`.</small></td>
</tr>
<tr>
<td><small>**ft_strchr_gnl**</small></td>
<td><small>`char *ft_strchr_gnl(const char *s, int c);`</small></td>
<td><small>Finds a newline character (`\n`).</small></td>
</tr>
<tr>
<td><small>**ft_strdup_gnl**</small></td>
<td><small>`char *ft_strdup_gnl(const char *s);`</small></td>
<td><small>Custom `strdup` for duplicating strings in `get_next_line`.</small></td>
</tr>
<tr>
<td><small>**ft_strjoin_gnl**</small></td>
<td><small>`char *ft_strjoin_gnl(char *s1, char *s2);`</small></td>
<td><small>Joins two strings while handling leftover buffer data.</small></td>
</tr>
</table>

</details>
