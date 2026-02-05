# Contributing to SimpleMenu

Thank you for your interest in contributing to SimpleMenu! This document provides guidelines and standards for contributing to the project.

## Code of Conduct

- Be respectful and constructive in all interactions
- Focus on what is best for the community
- Show empathy towards other community members

## Getting Started

### Prerequisites

- GCC or Clang compiler
- SDL 1.2 development libraries
- Make build system
- Git

### Building the Project

```bash
cd simplemenu
make
```

See [README.md](README.md) for platform-specific build instructions.

## Coding Standards

### C Style Guidelines

1. **Use safe string functions**: Always prefer `strncpy`, `snprintf`, `strncat` over `strcpy`, `sprintf`, `strcat`
2. **Check return values**: Always check return values from functions that can fail (malloc, fopen, etc.)
3. **Initialize variables**: Always initialize pointers to NULL
4. **Free allocated memory**: Every `malloc`/`calloc` should have a corresponding `free`
5. **Bounds checking**: Always validate array indices and buffer sizes

### Security Best Practices

- **Never use `system()` with user input**: Use direct system calls or safe wrapper functions
- **Validate all input**: Check sizes, ranges, and formats before use
- **Avoid buffer overflows**: Use size-aware string functions
- **Check for NULL**: Always check pointers before dereferencing

### Code Examples

**Bad:**
```c
char buffer[100];
strcpy(buffer, userInput);  // Buffer overflow risk!
```

**Good:**
```c
char buffer[100];
strncpy(buffer, userInput, sizeof(buffer) - 1);
buffer[sizeof(buffer) - 1] = '\0';  // Ensure null termination
```

**Bad:**
```c
char *data = malloc(size);
data[0] = 'x';  // Might crash if malloc failed!
```

**Good:**
```c
char *data = malloc(size);
if (data == NULL) {
    return -1;  // Handle error
}
data[0] = 'x';
// ... use data ...
free(data);
```

## Testing

### Static Analysis

Before submitting, run static analysis tools:

```bash
# cppcheck
cppcheck --enable=all --inconclusive simplemenu/src/

# clang-tidy (if available)
clang-tidy simplemenu/src/logic/*.c -- -I simplemenu/src/headers
```

### Memory Leak Detection

Run Valgrind to check for memory leaks:

```bash
valgrind --leak-check=full --show-leak-kinds=all ./simplemenu
```

## Submitting Changes

### Pull Request Process

1. **Fork the repository** and create your branch from `main`
2. **Make your changes** following the coding standards above
3. **Test thoroughly** - ensure no regressions
4. **Run static analysis** and fix any warnings
5. **Update documentation** if needed
6. **Submit a pull request** with a clear description of changes

### Pull Request Checklist

- [ ] Code follows the project's coding standards
- [ ] No compiler warnings
- [ ] Static analysis passes (cppcheck, clang-tidy)
- [ ] No memory leaks (checked with Valgrind if possible)
- [ ] Changes are documented in code comments
- [ ] README.md updated if needed

### Commit Messages

Write clear, descriptive commit messages:

```
Fix buffer overflow in getOPK() function

Replace unsafe strcpy() calls with strncpy() and add proper
bounds checking to prevent buffer overflows when copying
OPK metadata.

Fixes #123
```

## Common Issues and Solutions

### Build Failures

- Ensure all SDL development packages are installed
- Check that include paths are correct
- Verify cross-compilation toolchain is set up (for embedded targets)

### Memory Issues

- Use Valgrind or AddressSanitizer to detect memory problems
- Ensure all allocated memory is freed
- Check for use-after-free bugs

## Areas Needing Improvement

High-priority areas where contributions are welcome:

1. **Security fixes**: Replace remaining unsafe string operations
2. **Memory management**: Fix memory leaks and improve cleanup
3. **Unit tests**: Add test coverage for core functionality
4. **Documentation**: Improve code comments and API documentation
5. **SDL2 migration**: Update from SDL 1.2 to SDL2
6. **Refactoring**: Break up large files (config.c, logic.c, graphics.c)
7. **Error handling**: Improve error handling and reporting

## Getting Help

- Open an issue for bugs or feature requests
- Tag issues with appropriate labels (bug, enhancement, security, etc.)
- Be patient and respectful when asking for help

## License

By contributing to SimpleMenu, you agree that your contributions will be licensed under the same license as the project.

---

Thank you for contributing to SimpleMenu!
