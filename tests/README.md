# SimpleMenu Tests

This directory contains tests for the SimpleMenu project.

## Running Tests

### Quick Test
Run the test script to check code quality and basic compilation:

```bash
./run_tests.sh
```

### Unit Tests

Compile and run individual unit tests:

```bash
# String utilities tests
gcc -o test_string_utils test_string_utils.c ../simplemenu/src/logic/string_utils.c -I../simplemenu/src/headers
./test_string_utils
```

### Static Analysis

Run static analysis tools manually:

```bash
# cppcheck - comprehensive analysis
cppcheck --enable=all --inconclusive ../simplemenu/src/

# clang-tidy - modern C best practices
clang-tidy ../simplemenu/src/logic/*.c -- -I../simplemenu/src/headers
```

### Memory Leak Detection

Use Valgrind to check for memory issues:

```bash
# Compile with debug symbols
cd ../simplemenu
make clean
make CFLAGS="-g -O0"

# Run with Valgrind
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./simplemenu
```

### Address Sanitizer

Compile with AddressSanitizer for runtime memory error detection:

```bash
cd ../simplemenu
make clean
make CFLAGS="-fsanitize=address -g -O0" LDFLAGS="-fsanitize=address"
./simplemenu
```

## Test Coverage

Current test coverage:

- ✅ String utilities (test_string_utils.c)
- ⏳ Configuration parsing (TODO)
- ⏳ ROM list management (TODO)
- ⏳ Graphics rendering (TODO)
- ⏳ Input handling (TODO)

## Adding New Tests

To add a new unit test:

1. Create a new test file: `test_<module>.c`
2. Include the module's header files
3. Write test functions
4. Compile with the module's source file
5. Update this README

Example test structure:

```c
#include <stdio.h>
#include <assert.h>

void test_feature() {
    // Arrange
    int input = 5;
    
    // Act
    int result = my_function(input);
    
    // Assert
    assert(result == expected);
    printf("test_feature: PASS\n");
}

int main() {
    test_feature();
    return 0;
}
```

## Continuous Integration

Tests are automatically run via GitHub Actions on every push and pull request. See `.github/workflows/ci.yml` for configuration.

## Test Requirements

- All new code should have corresponding tests
- Tests should cover normal cases, edge cases, and error cases
- Memory safety must be verified (no leaks, no overflows)
- Static analysis must pass with no errors

## Known Issues

- Cross-compilation testing not yet implemented
- Integration tests needed for full system testing
- More comprehensive unit test coverage needed
