<h1 align="center">Libft Toolkit</h1>

A reusable implementation of the 42 curriculum's foundational C library, extended with additional helpers and backed by an in-house tester designed to validate every feature before peer evaluations or interviews.

<h2 align="center">Index</h2>
<h3 align="center"><b>
    <a href="#About">About Libft</a>
    <span> • </span>
    <a href="#Tester">Custom Tester</a>
    <span> • </span>
    <a href="#Subject">Subject Compliance</a>
    <span> • </span>
    <a href="#Layout">Repository Layout</a>
    <span> • </span>
    <a href="#Build">Build & Integration</a>
    <span> • </span>
    <a href="#Usage">Usage Guidelines</a>
    <span> • </span>
    <a href="#Functions">Function Reference</a>
    <span> • </span>
    <a href="#Extras">Additional Helpers</a>
    <span> • </span>
    <a href="#Related">Related Projects</a>
    <span> • </span>
    <a href="#Credits">Credits</a>
</b></h3>

## <a id="About"></a>About Libft
- Reimplementation of the standard C library utilities required by the official 42 *Libft* subject (see `subject_libft.pdf`).
- Built to be Norm-compliant, memory-safe, and reusable across subsequent projects such as `get_next_line`, `ft_printf`, and personal side work.
- Expanded with quality-of-life helpers (`ft_atol`, `ft_isnumeric`, `ft_max`, `ft_str_append_char`, etc.) that proved valuable in more advanced codebases.

## <a id="Tester"></a>Custom Tester
- Located under `.testers/libft`, the tester recompiles all functions with `-Wall -Wextra -Werror` and links against the freshly built `libft.a`.
- Modular test files cover every mandatory feature; `run_tests.sh` orchestrates compilation, execution, color-coded reporting, and cleanup of temporary descriptor outputs.
- The workflow mirrors 42's evaluation expectations: producing a `results.txt` log and ensuring regressions are detected before submission.
- To run it:
  ```bash
  cd .testers/libft
  ./run_tests.sh
  ```

## <a id="Subject"></a>Subject Compliance
- Part 1: full recreation of libc staples for character tests, memory manipulation, and string queries.
- Part 2: higher-level string builders, conversion routines, and file-descriptor helpers required by the subject.
- Bonus: full linked-list API using `t_list`, plus optional utilities kept within the same compilation unit while respecting subject constraints.
- Makefile adheres to the required targets (`all`, `clean`, `fclean`, `re`) and builds with the mandated warning flags.

## <a id="Layout"></a>Repository Layout
| Path | Description |
| --- | --- |
| `libft/` | Source files and `libft.h` for mandatory and extra helper functions. |
| `.testers/libft/` | Custom tester with modular test cases, orchestrator script, and `results.txt` output. |
| `printf/` | Bonus implementation of `ft_printf`, cloned on demand by the Makefile. |
| `gnl/` | Bonus implementation of `get_next_line`, also cloned automatically. |
| `obj/` | Intermediate object files created during library builds. |
| `Makefile` | Builds `libft.a`, optionally fetching `printf`/`gnl`, and controls all dependencies. |
| `libft.a` | Static archive generated from the current sources. |
| `subject_libft.pdf` | Official subject reference included for context and compliance checks. |

## <a id="Build"></a>Build & Integration
```bash
make
```
- Ensures the optional `printf/` and `gnl/` directories exist (cloning them if absent).
- Compiles sources into `obj/` and archives them into `libft.a` at the repository root.
- Passes `-Wall -Wextra -Werror` to every translation unit for production-ready builds.

## <a id="Usage"></a>Usage Guidelines
- Include the header in client code: `#include "libft.h"`.
- Link the archive during compilation, e.g.: `cc main.c -L path/to/libft -lft`.
- For projects that ship multiple 42 prerequisites, keep the generated `libft.a` beside your sources or under a dedicated `libs/` directory.

## <a id="Functions"></a>Function Reference
The tables below list every function implemented in this repository, including optional helpers.

### Character Classification & Helpers
| Function | Prototype | Purpose |
| --- | --- | --- |
| `ft_isalpha` | `int ft_isalpha(int c);` | Checks if `c` is an alphabetic ASCII character. |
| `ft_isdigit` | `int ft_isdigit(int c);` | Checks if `c` is a decimal digit (`0`–`9`). |
| `ft_isnumeric` | `int ft_isnumeric(const char *str);` | Verifies that `str` contains an optional sign followed by digits only. |
| `ft_isalnum` | `int ft_isalnum(int c);` | Checks if `c` is alphanumeric. |
| `ft_isascii` | `int ft_isascii(int c);` | Checks if `c` falls within the ASCII range (0–127). |
| `ft_isprint` | `int ft_isprint(int c);` | Checks if `c` is a printable ASCII character. |
| `ft_iswhitespace` | `bool ft_iswhitespace(int c);` | Returns `true` for whitespace control characters or space. |
| `ft_isspace` | `int ft_isspace(char c);` | Detects plain space or tab characters. |
| `ft_tolower` | `int ft_tolower(int c);` | Converts uppercase ASCII letters to lowercase. |
| `ft_toupper` | `int ft_toupper(int c);` | Converts lowercase ASCII letters to uppercase. |
| `ft_max` | `int ft_max(int a, int b);` | Returns the greater of the two integers. |

### String Query & Comparison
| Function | Prototype | Purpose |
| --- | --- | --- |
| `ft_strlen` | `size_t ft_strlen(const char *str);` | Returns the length of `str`. |
| `ft_strlcpy` | `size_t ft_strlcpy(char *dst, const char *src, size_t size);` | Copies `src` into `dst` with size limiting and reports `src` length. |
| `ft_strlcat` | `size_t ft_strlcat(char *dst, const char *src, size_t size);` | Appends `src` to `dst`, respecting the buffer size and reporting intended length. |
| `ft_strchr` | `char *ft_strchr(const char *s, int c);` | Finds the first occurrence of `c` in `s`. |
| `ft_strrchr` | `char *ft_strrchr(const char *s, int c);` | Finds the last occurrence of `c` in `s`. |
| `ft_strncmp` | `int ft_strncmp(const char *s1, const char *s2, size_t n);` | Compares two strings up to `n` characters. |
| `ft_strcmp` | `int ft_strcmp(const char *s1, const char *s2);` | Compares two strings until they differ or terminate. |
| `ft_strnstr` | `char *ft_strnstr(const char *big, const char *little, size_t len);` | Searches for `little` within `big` inside `len` characters. |
| `ft_strdup` | `char *ft_strdup(const char *s);` | Allocates and copies `s` into a new string. |

### String Builders & Iterators
| Function | Prototype | Purpose |
| --- | --- | --- |
| `ft_substr` | `char *ft_substr(char const *s, unsigned int start, size_t len);` | Produces a substring starting at `start` with length `len`. |
| `ft_strjoin` | `char *ft_strjoin(char const *s1, char const *s2);` | Concatenates two strings into a new allocation. |
| `ft_strtrim` | `char *ft_strtrim(char const *s1, char const *set);` | Trims all characters in `set` from both ends of `s1`. |
| `ft_split` | `char **ft_split(const char *s, char c);` | Splits `s` into a NULL-terminated array using `c` as delimiter. |
| `ft_strmapi` | `char *ft_strmapi(const char *s, char (*f)(unsigned int, char));` | Maps each character of `s` through `f`, returning a new string. |
| `ft_striteri` | `void ft_striteri(char *s, void (*f)(unsigned int, char *));` | Iterates over `s` in place, calling `f` with the index and character pointer. |
| `ft_str_append_char` | `void ft_str_append_char(char **res, const char c);` | Appends a single character to a heap-allocated string pointer. |
| `ft_swapstrs` | `void ft_swapstrs(char *a, char *b);` | Swaps two string pointers when handled via references. |

### Memory Utilities
| Function | Prototype | Purpose |
| --- | --- | --- |
| `ft_memset` | `void *ft_memset(void *s, int c, size_t n);` | Fills `n` bytes of `s` with the byte `c`. |
| `ft_memcpy` | `void *ft_memcpy(void *dest, const void *src, size_t n);` | Copies `n` bytes from `src` to `dest` (non-overlapping). |
| `ft_memmove` | `void *ft_memmove(void *dest, const void *src, size_t n);` | Copies `n` bytes while safely handling overlap. |
| `ft_memchr` | `void *ft_memchr(const void *s, int c, size_t n);` | Searches the first `n` bytes of `s` for byte `c`. |
| `ft_memcmp` | `int ft_memcmp(const void *s1, const void *s2, size_t n);` | Compares two memory blocks byte by byte. |
| `ft_bzero` | `void ft_bzero(void *s, size_t n);` | Sets `n` bytes of `s` to zero. |
| `ft_calloc` | `void *ft_calloc(size_t nmemb, size_t size);` | Allocates zero-initialized memory for an array. |

### Numeric Conversion
| Function | Prototype | Purpose |
| --- | --- | --- |
| `ft_atoi` | `int ft_atoi(const char *nptr);` | Parses an `int` value from `nptr` with leading whitespace and sign support. |
| `ft_atol` | `long ft_atol(const char *str);` | Parses a `long` using the same rules as `ft_atoi`, covering wider ranges. |
| `ft_itoa` | `char *ft_itoa(int n);` | Converts an integer to a newly allocated decimal string. |

### File Descriptor Output
| Function | Prototype | Purpose |
| --- | --- | --- |
| `ft_putchar_fd` | `void ft_putchar_fd(char c, int fd);` | Writes the character `c` to the file descriptor `fd`. |
| `ft_putstr_fd` | `void ft_putstr_fd(char *s, int fd);` | Writes the string `s` to `fd`. |
| `ft_putendl_fd` | `void ft_putendl_fd(char *s, int fd);` | Writes `s` followed by a newline to `fd`. |
| `ft_putnbr_fd` | `void ft_putnbr_fd(int n, int fd);` | Writes the decimal representation of `n` to `fd`. |

### Linked List API
| Function | Prototype | Purpose |
| --- | --- | --- |
| `ft_lstnew` | `t_list *ft_lstnew(void *content);` | Creates a new list node storing `content`. |
| `ft_lstadd_front` | `void ft_lstadd_front(t_list **lst, t_list *new);` | Inserts `new` at the beginning of `lst`. |
| `ft_lstadd_back` | `void ft_lstadd_back(t_list **lst, t_list *new);` | Appends `new` to the end of `lst`. |
| `ft_lstsize` | `int ft_lstsize(t_list *lst);` | Counts the nodes in `lst`. |
| `ft_lstlast` | `t_list *ft_lstlast(t_list *lst);` | Retrieves the last node of `lst`. |
| `ft_lstdelone` | `void ft_lstdelone(t_list *lst, void (*del)(void *));` | Deletes one node and calls `del` on its content. |
| `ft_lstclear` | `void ft_lstclear(t_list **lst, void (*del)(void *));` | Clears the entire list, deleting every node. |
| `ft_lstiter` | `void ft_lstiter(t_list *lst, void (*f)(void *));` | Applies `f` to each node's content. |
| `ft_lstmap` | `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));` | Creates a new list by mapping `f` over `lst`, cleaning up with `del` on failure. |

## <a id="Extras"></a>Additional Helpers
- `ft_isnumeric`, `ft_atol`, and `ft_max` accelerate numeric parsing and comparisons in later projects.
- `ft_iswhitespace` and `ft_isspace` offer fine-grained whitespace handling tailored to parsing tasks.
- `ft_str_append_char` and `ft_swapstrs` support custom string builders, reducing boilerplate in utilities such as `get_next_line` or parsers.
- These helpers stay within the same archive for convenience, while keeping mandatory subject deliverables untouched.

## <a id="Related"></a>Related Projects
- `printf/`: bonus `ft_printf` implementation aligned with the style of this library and intended to link seamlessly.
- `gnl/`: bonus `get_next_line` sources bundled for a complete I/O toolkit in a single repository snapshot.

## <a id="Credits"></a>Credits
Crafted by paalexan at 42 Porto. Shared for educational purposes—anyone may study, reuse, or extend the work with proper attribution.
