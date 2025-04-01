# 📚 Libft

**Libft** is a foundational C library developed during the 42 programming cursus. It reimplements many essential functions from the standard C library (`libc`) and adds useful utilities and data structures for future projects.

---

## Project Overview

This project consists of:

- Rewriting standard C library functions (like `strlen`, `memcpy`, `strchr`, etc.).
- Implementing memory and string manipulation tools.
- Managing character type checks.
- Creating custom functions like `ft_split`, `ft_strtrim`, `ft_itoa`, and more.
- Building and manipulating a singly linked list (`t_list`).

This library is designed to be reused throughout many 42 projects such as `get_next_line`, `ft_printf`, and more.

---

## 🛠 Functions Implemented

### 🧵 String & Memory
- `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strdup`
- `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`
- `ft_memset`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`
- `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`

### 🔡 Character Checks
- `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`
- `ft_tolower`, `ft_toupper`
- `ft_iswhitespace` *(custom)*

### 🔢 Conversion
- `ft_atoi`, `ft_itoa`

### 🧠 Memory Allocation
- `ft_calloc`, `ft_bzero`

### 📤 File Descriptor Output
- `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`

### 🔁 Functional String Tools
- `ft_strmapi`, `ft_striteri`

### 🧱 Linked List Utilities (`t_list`)
- `ft_lstnew`, `ft_lstadd_front`, `ft_lstadd_back`
- `ft_lstsize`, `ft_lstlast`, `ft_lstdelone`, `ft_lstclear`
- `ft_lstiter`, `ft_lstmap`

---

## 🧪 How to Use

### 🔧 Compile the library

```bash
make
