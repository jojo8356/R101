#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "utils.h"

void test_strcmp()
{
    printf("🔹 Test strcmp...\n");
    assert(strcmp("abc", "abc") == 0);
    assert(strcmp("abc", "abd") < 0);
    assert(strcmp("abd", "abc") > 0);
    assert(strcmp("", "") == 0);
    printf("✅ strcmp OK\n");
}

void test_strcpy()
{
    printf("🔹 Test strcpy...\n");
    char dest[50];
    strcpy(dest, "Hello");
    assert(strcmp(dest, "Hello") == 0);
    strcpy(dest, "");
    assert(strcmp(dest, "") == 0);
    printf("✅ strcpy OK\n");
}

void test_strlen()
{
    printf("🔹 Test strlen...\n");
    assert(strlen("Hello") == 5);
    assert(strlen("") == 0);
    assert(strlen(" ") == 1);
    printf("✅ strlen OK\n");
}

void test_diff_seconds()
{
    printf("🔹 Test diff_seconds...\n");
    assert(diff_seconds("2025-10-12 10:00:00", "2025-10-12 10:01:00") == 60);
    assert(diff_seconds("2025-10-12 09:59:30", "2025-10-12 10:00:00") == 30);
    printf("✅ diff_seconds OK\n");
}

void test_format_time()
{
    printf("🔹 Test format_time...\n");
    char buf[50];
    format_time(125, buf);
    assert(strcmp(buf, "2 min 5 sec") == 0);
    format_time(60, buf);
    assert(strcmp(buf, "1 min 0 sec") == 0);
    printf("✅ format_time OK\n");
}

void test_include_char()
{
    printf("🔹 Test include_char...\n");
    char *list[] = {"pomme", "banane", "cerise"};
    assert(include_char(list, 3, "banane") == 1);
    assert(include_char(list, 3, "raisin") == 0);
    printf("✅ include_char OK\n");
}

void test_len_utf8_chars()
{
    printf("🔹 Test len_utf8_chars...\n");
    assert(len_utf8_chars('A') == 1);
    assert(len_utf8_chars(0xC3) == 2);
    assert(len_utf8_chars(0xE2) == 3);
    assert(len_utf8_chars(0xF0) == 4);
    printf("✅ len_utf8_chars OK\n");
}

int main()
{
    printf("\n🧪 Lancement des tests unitaires...\n\n");

    test_strcmp();
    test_strcpy();
    test_strlen();
    test_diff_seconds();
    test_format_time();
    test_include_char();
    test_len_utf8_chars();

    printf("\n🎉 Tous les tests sont passés avec succès !\n");
    return 0;
}
