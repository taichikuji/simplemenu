# Security Policy

## Reporting a Vulnerability

If you discover a security vulnerability in SimpleMenu, please report it responsibly:

1. **Do NOT open a public issue** for security vulnerabilities
2. Email the maintainers directly (check repository for contact info)
3. Include detailed information:
   - Description of the vulnerability
   - Steps to reproduce
   - Potential impact
   - Suggested fix (if you have one)

We will acknowledge your report within 48 hours and provide updates as we work on a fix.

## Security Best Practices for Contributors

When contributing code, please follow these security guidelines:

### String Operations
- ❌ Never use: `strcpy()`, `strcat()`, `sprintf()`
- ✅ Always use: `strncpy()`, `strncat()`, `snprintf()`
- Always null-terminate strings explicitly
- Always check buffer sizes before copying

### Memory Management
- Always check if `malloc()`/`calloc()` returns NULL
- Always free allocated memory on all code paths
- Use Valgrind or AddressSanitizer during development

### System Calls
- Never pass user input to `system()` without sanitization
- Prefer direct system calls over shell execution
- Validate and sanitize all file paths

### Input Validation
- Validate all external input (files, environment variables, user data)
- Check array bounds before access
- Validate string lengths before operations

## Recommended Tools

Use these tools to catch security issues:

```bash
# Static analysis
cppcheck --enable=all src/

# Clang static analyzer
clang-tidy src/**/*.c

# Memory error detection
valgrind --leak-check=full ./simplemenu

# Address sanitizer (compile with -fsanitize=address)
gcc -fsanitize=address -g -o simplemenu src/logic/*.c
```

## Security Checklist for Pull Requests

Before submitting code:

- [ ] No use of unsafe string functions (strcpy, sprintf, strcat)
- [ ] All malloc() calls are checked for NULL
- [ ] All allocated memory is freed
- [ ] No user input passed to system() calls
- [ ] Input validation on all external data
- [ ] Ran static analysis tools
- [ ] No compiler warnings
- [ ] Tested with Valgrind or sanitizers

## Supported Versions

| Version | Supported          |
| ------- | ------------------ |
| main    | ✅ Yes             |
| < main  | ❌ No              |

We only support the latest version from the main branch. Please update to the latest version before reporting issues.

## Additional Resources

- [CERT C Coding Standard](https://wiki.sei.cmu.edu/confluence/display/c/SEI+CERT+C+Coding+Standard)
- [CWE - Common Weakness Enumeration](https://cwe.mitre.org/)
- [OWASP Secure Coding Practices](https://owasp.org/www-project-secure-coding-practices-quick-reference-guide/)
