/* 
 * Unit tests for string utilities
 * Compile: gcc -o test_string_utils test_string_utils.c ../simplemenu/src/logic/string_utils.c -I../simplemenu/src/headers
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/* Include the functions we're testing */
extern char *toLower(char* string);
extern char *toUpper(char* string);
extern char *getExtension(char *stringWithExtension);
extern char *getRomPath(char *fileName);
extern char *getNameWithoutExtension(char *fileName);

/* Test counter */
int tests_run = 0;
int tests_passed = 0;

#define TEST(name) \
    printf("Testing: %s ... ", name); \
    tests_run++;

#define ASSERT(condition) \
    if (condition) { \
        printf("✓ PASS\n"); \
        tests_passed++; \
    } else { \
        printf("✗ FAIL\n"); \
        return; \
    }

void test_toLower() {
    TEST("toLower basic");
    char *result = toLower("HELLO");
    ASSERT(strcmp(result, "hello") == 0);
    free(result);
}

void test_toLower_mixed() {
    TEST("toLower mixed case");
    char *result = toLower("HeLLo WoRLd");
    ASSERT(strcmp(result, "hello world") == 0);
    free(result);
}

void test_toUpper() {
    TEST("toUpper basic");
    char *result = toUpper("hello");
    ASSERT(strcmp(result, "HELLO") == 0);
    free(result);
}

void test_toUpper_mixed() {
    TEST("toUpper mixed case");
    char *result = toUpper("HeLLo WoRLd");
    ASSERT(strcmp(result, "HELLO WORLD") == 0);
    free(result);
}

void test_getExtension() {
    TEST("getExtension basic");
    char *result = getExtension("game.gba");
    ASSERT(result != NULL && strcmp(result, ".gba") == 0);
}

void test_getExtension_multiple_dots() {
    TEST("getExtension multiple dots");
    char *result = getExtension("my.game.gba");
    ASSERT(result != NULL && strcmp(result, ".gba") == 0);
}

void test_getExtension_no_extension() {
    TEST("getExtension no extension");
    char *result = getExtension("game");
    ASSERT(result == NULL);
}

void test_getRomPath() {
    TEST("getRomPath basic");
    char *result = getRomPath("/path/to/game.gba");
    ASSERT(strcmp(result, "/path/to") == 0);
    free(result);
}

void test_getRomPath_no_slash() {
    TEST("getRomPath no slash");
    char *result = getRomPath("game.gba");
    ASSERT(strcmp(result, "game.gba") == 0);
    free(result);
}

void test_getNameWithoutExtension() {
    TEST("getNameWithoutExtension basic");
    char *result = getNameWithoutExtension("game.gba");
    ASSERT(strcmp(result, "game") == 0);
    free(result);
}

void test_getNameWithoutExtension_path() {
    TEST("getNameWithoutExtension with path");
    char *result = getNameWithoutExtension("/path/to/game.gba");
    ASSERT(strcmp(result, "/path/to/game") == 0);
    free(result);
}

void test_getNameWithoutExtension_no_extension() {
    TEST("getNameWithoutExtension no extension");
    char *result = getNameWithoutExtension("game");
    ASSERT(strcmp(result, "game") == 0);
    free(result);
}

/* Memory safety tests */
void test_toLower_memory_safety() {
    TEST("toLower doesn't overflow");
    /* Create a long string */
    char longString[1000];
    memset(longString, 'A', 999);
    longString[999] = '\0';
    
    char *result = toLower(longString);
    ASSERT(result != NULL && strlen(result) == 999);
    free(result);
}

void test_toUpper_memory_safety() {
    TEST("toUpper doesn't overflow");
    /* Create a long string */
    char longString[1000];
    memset(longString, 'a', 999);
    longString[999] = '\0';
    
    char *result = toUpper(longString);
    ASSERT(result != NULL && strlen(result) == 999);
    free(result);
}

int main() {
    printf("=================================\n");
    printf("String Utilities Unit Tests\n");
    printf("=================================\n\n");
    
    /* Run all tests */
    test_toLower();
    test_toLower_mixed();
    test_toUpper();
    test_toUpper_mixed();
    test_getExtension();
    test_getExtension_multiple_dots();
    test_getExtension_no_extension();
    test_getRomPath();
    test_getRomPath_no_slash();
    test_getNameWithoutExtension();
    test_getNameWithoutExtension_path();
    test_getNameWithoutExtension_no_extension();
    test_toLower_memory_safety();
    test_toUpper_memory_safety();
    
    printf("\n=================================\n");
    printf("Results: %d/%d tests passed\n", tests_passed, tests_run);
    printf("=================================\n");
    
    return (tests_passed == tests_run) ? 0 : 1;
}
