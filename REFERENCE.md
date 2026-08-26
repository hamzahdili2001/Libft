# Standard C Library Functions — Reference for Reimplementation

A structured guide to commonly used C standard library functions. Implement each one yourself, then test against the real library.

---

## `<string.h>`

### `strlen`
```c
size_t strlen(const char *s);
```
**What it does:** Counts the number of characters in a string, not including the terminating null byte `'\0'`.
**How it works internally:** Walks the pointer forward from `s` until it hits a byte equal to `0`, then returns the number of steps taken.
**Return value:** Number of characters before the null terminator.
**Edge cases to think about:**
- `s` must not be NULL (undefined behavior if it is — real implementations don't check).
- Empty string `""` returns `0`.
- It only cares about the null byte, not embedded whitespace or other content.

---

### `strcpy`
```c
char *strcpy(char *dest, const char *src);
```
**What it does:** Copies the string `src` (including its null terminator) into the buffer `dest`.
**How it works internally:** Copies byte by byte until it copies the `'\0'`.
**Return value:** Returns `dest` (the original pointer), so calls can be chained, e.g. `printf("%s", strcpy(buf, "hi"))`.
**Edge cases:**
- `dest` must have enough space — this function does **no bounds checking**, which is why it's considered unsafe in real code.
- Behavior is undefined if `src` and `dest` overlap.

---

### `strncpy`
```c
char *strncpy(char *dest, const char *src, size_t n);
```
**What it does:** Like `strcpy`, but copies at most `n` bytes.
**Behavior quirk (important, commonly implemented wrong):**
- If `src` is shorter than `n`, the rest of `dest` up to `n` bytes is padded with `'\0'`.
- If `src` is `n` bytes or longer, `dest` will **not** be null-terminated — you have to do that yourself.
**Return value:** Returns `dest`.

---

### `strcat`
```c
char *strcat(char *dest, const char *src);
```
**What it does:** Appends `src` to the end of `dest` (finds `dest`'s null terminator, then copies `src` starting there).
**Return value:** Returns `dest`.
**Edge cases:**
- `dest` must already be null-terminated and have enough spare room for `src` plus a new `'\0'`.
- No bounds checking — classic buffer overflow source.

---

### `strcmp`
```c
int strcmp(const char *s1, const char *s2);
```
**What it does:** Compares two strings lexicographically (like dictionary order, but based on ASCII byte values).
**How it works internally:** Walks both strings in parallel, comparing byte by byte, until it finds a mismatch or both hit `'\0'`.
**Return value:**
- `0` if strings are identical.
- A negative value if `s1` is "less than" `s2` (comes first alphabetically / has smaller byte value at first mismatch).
- A positive value if `s1` is "greater than" `s2`.
- Common (but not guaranteed) implementation detail: returns `s1[i] - s2[i]` at the first differing byte.

---

### `strncmp`
```c
int strncmp(const char *s1, const char *s2, size_t n);
```
**What it does:** Same as `strcmp` but stops comparing after `n` bytes even if no null terminator was reached.
**Use case:** Comparing prefixes, e.g. checking if a string starts with `"http"`.

---

### `strchr`
```c
char *strchr(const char *s, int c);
```
**What it does:** Searches `s` for the first occurrence of character `c` (an `int` here, but treated as a `char`).
**Return value:** Pointer to the first matching character, or `NULL` if not found.
**Edge case:** If `c` is `'\0'`, this returns a pointer to the string's null terminator itself (that's a valid "found" result).

---

### `strrchr`
```c
char *strrchr(const char *s, int c);
```
**What it does:** Same idea as `strchr` but finds the **last** occurrence instead of the first.
**Typical use:** Finding a file extension by searching for the last `'.'`.

---

### `strstr`
```c
char *strstr(const char *haystack, const char *needle);
```
**What it does:** Finds the first occurrence of the substring `needle` inside `haystack`.
**Return value:** Pointer to the start of the match inside `haystack`, or `NULL` if not found.
**Edge case:** If `needle` is an empty string, it returns `haystack` itself (empty string matches at position 0).

---

### `memset`
```c
void *memset(void *s, int c, size_t n);
```
**What it does:** Sets the first `n` bytes of memory at `s` to the value `c` (converted to `unsigned char`).
**Common use:** Zeroing out a buffer: `memset(buf, 0, sizeof(buf));`
**Return value:** Returns `s`.
**Note:** Operates on raw bytes, not on the "logical" content — it doesn't know or care about the type at `s`.

---

### `memcpy`
```c
void *memcpy(void *dest, const void *src, size_t n);
```
**What it does:** Copies `n` bytes from `src` to `dest`, no matter what type of data it is.
**Important constraint:** Behavior is undefined if `src` and `dest` overlap — that's what `memmove` is for.
**Return value:** Returns `dest`.

---

### `memmove`
```c
void *memmove(void *dest, const void *src, size_t n);
```
**What it does:** Same as `memcpy`, but safe even when `src` and `dest` overlap.
**How it works internally:** Typically checks whether `dest` is ahead of or behind `src` in memory, and copies backward-to-forward or forward-to-backward accordingly so bytes don't get overwritten before they're read.
**Return value:** Returns `dest`.

---

### `memcmp`
```c
int memcmp(const void *s1, const void *s2, size_t n);
```
**What it does:** Compares the first `n` bytes of two memory blocks.
**Return value:** `0` if equal; negative/positive depending on which byte differs first, similar to `strcmp`.

---

### `memchr`
```c
void *memchr(const void *s, int c, size_t n);
```
**What it does:** Searches the first `n` bytes of memory block `s` for the first occurrence of byte `c`.
**Return value:** Pointer to the matching byte, or `NULL` if not found within `n` bytes.
**Difference from `strchr`:** Works on raw bytes and a fixed length, not a null-terminated string — it will happily search past embedded `'\0'` bytes since it only stops at `n`.

---

### `memccpy`
```c
void *memccpy(void *dest, const void *src, int c, size_t n);
```
**What it does:** Copies bytes from `src` to `dest`, stopping either after copying the byte equal to `c`, or after `n` bytes, whichever comes first.
**Return value:** If `c` was found and copied, returns a pointer to the byte in `dest` *right after* the copied `c`. If `c` was never found within `n` bytes, returns `NULL`.
**Use case:** Rarely used directly, but a good building block for a bounded `strcpy`-like function.

---

### `bzero`
```c
void bzero(void *s, size_t n);
```
**What it does:** Sets the first `n` bytes of `s` to zero. Functionally identical to `memset(s, 0, n)`.
**Note:** Considered legacy/deprecated in favor of `memset(..., 0, ...)`, but still commonly required in libc reimplementation exercises. Trivial to implement once you have `memset`.

---

### `strdup`
```c
char *strdup(const char *s);
```
**What it does:** Allocates (with `malloc`) a new buffer, copies `s` into it including the null terminator, and returns the new buffer.
**Return value:** Pointer to the newly allocated duplicate, or `NULL` if allocation fails.
**Implementation note:** Needs `strlen` (to size the allocation) and `strcpy`/`memcpy` (to do the copy) — good candidate for building on functions you already wrote. Caller is responsible for `free`ing the result.

---

### `strncat`
```c
char *strncat(char *dest, const char *src, size_t n);
```
**What it does:** Like `strcat`, but appends at most `n` bytes from `src` onto the end of `dest`.
**Return value:** Returns `dest`.
**Important quirk:** Unlike `strncpy`, this function **always** null-terminates the result — it appends at most `n` bytes from `src`, then adds exactly one `'\0'` after them, so the destination buffer needs room for `strlen(dest) + n + 1` bytes.

---

### `strlcat`
```c
size_t strlcat(char *dest, const char *src, size_t size);
```
**What it does:** A safer alternative to `strcat`/`strncat`. Appends `src` onto `dest`, but never writes past `size` total bytes in `dest` (including the null terminator).
**Return value:** Returns the **total length it *tried* to create** — `strlen(initial dest) + strlen(src)` — not the actual bytes written. This lets the caller detect truncation by checking if the return value is `>= size`.
**Edge case:** If `dest`'s initial length is already `>= size`, the function does not append anything and just returns `size + strlen(src)`.
**Note:** BSD-originated, not part of ISO C, but included in many libc reimplementation projects since it's a good "do it safely" exercise on top of `strcat`.

---

### `strnstr`
```c
char *strnstr(const char *haystack, const char *needle, size_t len);
```
**What it does:** Like `strstr`, but only searches within the first `len` bytes of `haystack`.
**Return value:** Pointer to the start of the first match, or `NULL` if not found.
**Edge case:** If `needle` is an empty string, returns `haystack` (matches at position 0), same as `strstr`.
**Note:** BSD function, not in every libc, but commonly required in reimplementation exercises alongside `strstr`.

---

## `<stdlib.h>`

### `malloc`
```c
void *malloc(size_t size);
```
**What it does:** Requests `size` bytes of heap memory. Contents are **uninitialized** (garbage values).
**Return value:** Pointer to the allocated block, or `NULL` if allocation fails.
**Implementation note:** A real implementation manages a free list or similar structure to track available memory blocks — this is the hard part if you want to build it from scratch rather than wrapping `sbrk`/`mmap`.

---

### `calloc`
```c
void *calloc(size_t nmemb, size_t size);
```
**What it does:** Allocates space for `nmemb` elements of `size` bytes each, and **zero-initializes** the whole block.
**Difference from `malloc`:** Zeroes memory, and takes count + size separately (also checks for multiplication overflow internally in good implementations).
**Return value:** Pointer to zeroed memory, or `NULL` on failure.

---

### `realloc`
```c
void *realloc(void *ptr, size_t size);
```
**What it does:** Resizes a previously allocated block to `size` bytes, preserving existing content up to the smaller of the old/new sizes.
**Behavior details:**
- If `ptr` is `NULL`, behaves like `malloc(size)`.
- If `size` is `0`, behaves like `free(ptr)` (implementation-defined, deprecated to rely on).
- May return a **different pointer** if it had to move the block — always reassign the result.

---

### `free`
```c
void free(void *ptr);
```
**What it does:** Releases memory previously returned by `malloc`/`calloc`/`realloc` back to the heap allocator.
**Edge cases:**
- `free(NULL)` is explicitly a no-op — safe to call.
- Freeing the same pointer twice ("double free") or a pointer not from malloc is undefined behavior.

---

### `atoi`
```c
int atoi(const char *nptr);
```
**What it does:** Converts a string to an `int`, skipping leading whitespace and handling an optional `+`/`-` sign.
**Behavior:** Stops at the first non-digit character. No error reporting — invalid input just returns `0`.

---

### `atol` / `atof`
```c
long atol(const char *nptr);
double atof(const char *nptr);
```
Same idea as `atoi`, but for `long` and `double` respectively. `atof` also needs to handle decimal points and exponent notation (`1.5e10`).

---

### `qsort`
```c
void qsort(void *base, size_t nmemb, size_t size,
           int (*compar)(const void *, const void *));
```
**What it does:** Sorts an array of `nmemb` elements, each `size` bytes, in place, using `compar` to determine order.
**How `compar` works:** Given two pointers to elements, returns negative/0/positive the same way `strcmp` does.
**Why this is a good exercise:** Forces you to work with `void *`, pointer arithmetic by byte size, and function pointers all at once. Typical algorithm to implement underneath: quicksort or introsort.

---

## `<stdio.h>`

### `printf`
```c
int printf(const char *format, ...);
```
**What it does:** Parses `format`, and for each `%` conversion specifier, pulls the next variadic argument and writes formatted output to stdout.
**Build it in stages:** Start with just `%d`, `%s`, `%c`, then add `%x`, `%u`, `%f`, then width/padding like `%5d` or `%02x`.
**Key mechanism to learn:** `<stdarg.h>` — `va_list`, `va_start`, `va_arg`, `va_end` for handling variable arguments.
**Return value:** Number of characters written (excluding null terminator), or negative on error.

---

### `sprintf` / `snprintf`
```c
int sprintf(char *str, const char *format, ...);
int snprintf(char *str, size_t size, const char *format, ...);
```
**What they do:** Same formatting logic as `printf`, but write into the buffer `str` instead of stdout.
**Key difference:** `snprintf` takes a `size` limit and will never write past it (truncating if needed) — this is why it's preferred in real code over `sprintf`, which has no bounds checking.

---

### `puts`
```c
int puts(const char *s);
```
**What it does:** Writes the string `s` to stdout, then automatically adds a newline.
**Return value:** Non-negative on success, `EOF` on error.

---

### `putchar` / `getchar`
```c
int putchar(int c);
int getchar(void);
```
**What they do:** Write/read a single character to/from stdout/stdin.
**Note:** Both use `int`, not `char`, so `getchar` can return `EOF` (-1) distinctly from any valid byte value (0–255).

---

### `fgets`
```c
char *fgets(char *s, int size, FILE *stream);
```
**What it does:** Reads a line (up to a newline or `size - 1` characters, whichever comes first) from `stream` into `s`, then null-terminates it. Unlike `gets` (removed from C11), it's bounds-safe.
**Return value:** Returns `s` on success, `NULL` on EOF or error with nothing read.
**Edge case:** The newline character `\n` is included in the buffer if it was read before hitting the size limit.

---

## `<ctype.h>`

All of these take an `int` (representing an `unsigned char` value or `EOF`) and return non-zero (true) or `0` (false).

```c
int isalpha(int c);   // is c a letter (a-z, A-Z)?
int isdigit(int c);   // is c a digit (0-9)?
int isspace(int c);   // is c whitespace (space, \t, \n, \v, \f, \r)?
int isupper(int c);   // is c an uppercase letter?
int islower(int c);   // is c a lowercase letter?
int toupper(int c);   // convert to uppercase if it's a lowercase letter, else return unchanged
int tolower(int c);   // convert to lowercase if it's an uppercase letter, else return unchanged
```
**Good exercise:** Implement these using explicit ASCII range checks (`'a' <= c && c <= 'z'`) rather than relying on a lookup table, so you understand the underlying character codes.

Three more worth adding to the set:
```c
int isalnum(int c);   // is c a letter OR a digit? (isalpha(c) || isdigit(c))
int isascii(int c);   // is c a 7-bit ASCII value, i.e. 0 <= c <= 127?
int isprint(int c);   // is c a printable character, including space? (0x20 to 0x7E)
```
**Note on `isprint` vs `isalpha`/`isdigit`:** "printable" is a broader category — it includes letters, digits, punctuation, and the space character, but excludes control characters like `'\n'`, `'\t'`, or `'\0'`.

---

## Additional Functions (not part of standard C, but commonly built alongside it)

These aren't in any ISO C header — you won't `#include` them from anywhere. They show up in libc-reimplementation exercises (e.g. the 42 School `libft` project) as a "part 2," either because they're convenience wrappers around the standard functions above, or because they fill in behavior the standard library doesn't provide directly. Good functions to build once your `<string.h>`/`<stdlib.h>` set above is solid, since several of these are just thin wrappers over what you already wrote.

### Allocation helpers

```c
void *ft_memalloc(size_t size);
```
**What it does:** Like `malloc`, but zero-initializes the memory before returning it (essentially `malloc` + `memset(..., 0, ...)` combined — similar in spirit to `calloc` with a single size argument instead of two).

```c
void ft_memdel(void **ap);
```
**What it does:** Takes the **address of a pointer**, frees the memory it points to, then sets that pointer itself to `NULL`. Guards against dangling-pointer bugs by nulling out the caller's variable, not just freeing the memory. The double pointer (`void **`) is what makes this possible — a plain `free(void *)` can't modify the caller's original pointer variable.

```c
char *ft_strnew(size_t size);
```
**What it does:** Allocates a string of `size` bytes (plus room for the terminator), with every byte initialized to `'\0'`.

```c
void ft_strdel(char **as);
```
**What it does:** Same idea as `ft_memdel`, but typed for strings — frees `*as` and sets `*as` to `NULL`.

```c
void ft_strclr(char *s);
```
**What it does:** Overwrites every character of an existing string with `'\0'`, without freeing or reallocating anything.

### String transformation / iteration

```c
void ft_striter(char *s, void (*f)(char *));
```
**What it does:** Calls `f` once per character in `s`, passing the **address** of each character so `f` can modify it in place (e.g. an uppercase-conversion function).

```c
void ft_striteri(char *s, void (*f)(unsigned int, char *));
```
**What it does:** Same as `ft_striter`, but also passes each character's index as the first argument to `f`.

```c
char *ft_strmap(char const *s, char (*f)(char));
```
**What it does:** Applies `f` to every character of `s` and builds a **brand-new** string (allocated with `malloc`) from the results — `s` itself is left untouched.

```c
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
```
**What it does:** Same as `ft_strmap`, but `f` also receives each character's index.

### Comparison, substrings, joining

```c
int ft_strequ(char const *s1, char const *s2);
```
**What it does:** Returns `1` if the two strings are exactly equal, `0` otherwise. Essentially `strcmp(s1, s2) == 0`, but returning a clean boolean instead of a sign-carrying int.

```c
int ft_strnequ(char const *s1, char const *s2, size_t n);
```
**What it does:** Same idea as `ft_strequ`, but only compares up to `n` characters (or until a `'\0'`, whichever comes first).

```c
char *ft_strsub(char const *s, unsigned int start, size_t len);
```
**What it does:** Allocates and returns a new substring of `s`, starting at index `start` and running for `len` characters. Behavior is undefined if `start`/`len` don't describe a valid range within `s` — this mirrors how something like Python's slicing would work, but without the safety net.

```c
char *ft_strjoin(char const *s1, char const *s2);
```
**What it does:** Allocates and returns a new string that's the concatenation of `s1` and `s2` — essentially `strdup`-then-`strcat`, but done in one allocation instead of a resize.

```c
char *ft_strtrim(char const *s);
```
**What it does:** Allocates and returns a copy of `s` with leading/trailing whitespace (space, `'\n'`, `'\t'`) stripped off. If there's no whitespace to trim, still returns a fresh copy of `s`, not the original pointer.

```c
char **ft_strsplit(char const *s, char c);
```
**What it does:** Splits `s` on every occurrence of delimiter `c`, and returns a heap-allocated, `NULL`-terminated array of heap-allocated substrings (the "tokens"). Consecutive delimiters are collapsed — e.g. splitting `"*hello*fellow***students*"` on `'*'` gives `["hello", "fellow", "students"]`, not empty strings in between. This is the trickiest function in this group: it requires careful two-pass logic (count the tokens first, then allocate and fill), and correct cleanup on partial-allocation failure.

### Numeric / output helpers

```c
char *ft_itoa(int n);
```
**What it does:** Allocates and returns a string representation of integer `n`, handling negative numbers (including the edge case `INT_MIN`, which can't simply be negated since `-INT_MIN` overflows `int`).

```c
void ft_putchar(char c);
void ft_putstr(char const *s);
void ft_putendl(char const *s);        // like ft_putstr, but appends '\n'
void ft_putnbr(int n);
```
**What they do:** Thin wrappers around `write(1, ...)` for writing a char, string, string+newline, or integer to stdout, without going through buffered `printf`/`puts`.

```c
void ft_putchar_fd(char c, int fd);
void ft_putstr_fd(char const *s, int fd);
void ft_putendl_fd(char const *s, int fd);
void ft_putnbr_fd(int n, int fd);
```
**What they do:** Same four functions as above, but writing to an arbitrary file descriptor `fd` instead of hardcoding stdout — useful for writing to stderr (`fd = 2`) or an open file.

---

## Bonus: Singly Linked List Functions

Once the string/memory functions are solid, a natural next step is a small linked-list toolkit. This uses one core struct:
```c
typedef struct s_list
{
    void            *content;       // the data stored in this node (any type, via void*)
    size_t          content_size;   // size in bytes of that data (needed since void* alone can't tell you)
    struct s_list   *next;          // pointer to the next node, or NULL if this is the last one
} t_list;
```

```c
t_list *ft_lstnew(void const *content, size_t content_size);
```
**What it does:** Allocates a new node, **copying** `content` and `content_size` into it (not just storing the pointer you passed — it makes its own copy). If `content` is `NULL`, the new node's `content` becomes `NULL` and `content_size` becomes `0`, regardless of what was passed for `content_size`. `next` starts as `NULL`.

```c
void ft_lstadd(t_list **alst, t_list *new);
```
**What it does:** Inserts `new` at the **front** of the list pointed to by `*alst` (i.e. `new->next = *alst; *alst = new;`).

```c
void ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
```
**What it does:** Frees a single node: calls `del` on its `content`/`content_size` to free that data, then frees the node itself, then sets `*alst` to `NULL`. Crucially, it must **not** touch `next` — deleting one node shouldn't delete the rest of the list.

```c
void ft_lstdel(t_list **alst, void (*del)(void *, size_t));
```
**What it does:** Frees the **entire list** starting at `*alst` — walks the chain, calling `del` + `free` on every node (essentially calling the logic of `ft_lstdelone` repeatedly), then sets `*alst` to `NULL`.

```c
void ft_lstiter(t_list *lst, void (*f)(t_list *elem));
```
**What it does:** Walks the list starting at `lst` and calls `f` on each node in place — no new list is created, and nodes aren't freed.

```c
t_list *ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
```
**What it does:** Walks `lst`, applies `f` to each node to produce a new node, and links those new nodes together into a **brand-new list**, which is returned. If any allocation along the way fails, the function should return `NULL` (and, to avoid leaks, clean up whatever partial list it had already built).

---

## Suggested Implementation Order

**Standard library core:**
1. `strlen`
2. `strcpy` / `strncpy`
3. `strcat` / `strncat` / `strlcat`
4. `strcmp` / `strncmp`
5. `strchr` / `strrchr` / `strstr` / `strnstr`
6. `memset` / `bzero`
7. `memcpy` / `memmove` / `memcmp` / `memchr` / `memccpy`
8. `ctype.h` functions: `isalpha`, `isdigit`, `isalnum`, `isascii`, `isspace`, `isprint`, `isupper`, `islower`, `toupper`, `tolower` (quick, good confidence builder)
9. `atoi` / `atol` / `atof`
10. `strdup` (needs `strlen` + `strcpy`, good first "compose what I already built" exercise)
11. `malloc` / `free` (simplest version: wrap a big static array as your "heap")
12. `realloc` / `calloc`
13. `qsort` (forces you to combine pointers, function pointers, and byte-level arithmetic)
14. `printf` family (the big one — save for last, build incrementally)

**Then the additional (non-standard) helpers, once the above is solid:**
1. `ft_memalloc` / `ft_memdel` / `ft_strnew` / `ft_strdel` / `ft_strclr` (allocation wrappers — quick wins)
2. `ft_strequ` / `ft_strnequ` (thin wrappers over your `strcmp`)
3. `ft_striter` / `ft_striteri` / `ft_strmap` / `ft_strmapi` (function-pointer practice)
4. `ft_strsub` / `ft_strjoin` / `ft_strtrim`
5. `ft_itoa` (watch out for `INT_MIN`)
6. `ft_putchar` / `ft_putstr` / `ft_putendl` / `ft_putnbr` and their `_fd` variants
7. `ft_strsplit` (save for near-last in this group — the trickiest one)

**Bonus (linked list), after everything else is stable:**
1. `ft_lstnew`
2. `ft_lstadd`
3. `ft_lstdelone` → `ft_lstdel`
4. `ft_lstiter`
5. `ft_lstmap`

For each function: implement it under a different name (e.g. `ft_strlen`), write test cases comparing your output to the real library's output side by side (where a real equivalent exists), and specifically test the edge cases listed above.
