// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	char *originalDestination = destination;
	while (*source != '\0') {
        *destination = *source;
        destination++;
        source++;
    }
	*destination = '\0';
	/* TODO: Implement strcpy(). */
	return originalDestination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	char *originalDestination = destination;
	/* TODO: Implement strncpy(). */
	while (len > 0 && *source != '\0') {
        *destination = *source;
        destination++;
        source++;
        len--;
    }
	while (len > 0) {
        *destination = '\0';
        destination++;
        len--;
    }
	return originalDestination;
}

char *strcat(char *destination, const char *source)
{
	char *originalDestination = destination;
	while (*destination != '\0') {
        destination++;
    }
	while (*source != '\0') {
        *destination = *source;
        destination++;
        source++;
    }
	*destination = '\0';
	/* TODO: Implement strcat(). */
	return originalDestination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	char *originalDestination = destination;
	while (*destination != '\0') {
        destination++;
    }
	while (len > 0 && *source != '\0') {
        *destination = *source;
        destination++;
        source++;
        len--;
    }
	*destination = '\0';
	/* TODO: Implement strncat(). */
	return originalDestination;
}

int strcmp(const char *str1, const char *str2)
{
	while (*str1 != '\0' || *str2 != '\0') {
        if (*str1 != *str2) {
            return (*str1 > *str2) ? 1 : -1;
        }
        str1++;
        str2++;
    }

    return 0;
	/* TODO: Implement strcmp(). */
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	while ((len > 0) && (*str1 != '\0' || *str2 != '\0')) {
        if (*str1 != *str2) {
            return (*str1 > *str2) ? 1 : -1;
        }
        str1++;
        str2++;
        len--;
    }
	/* TODO: Implement strncmp(). */
	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	while (*str != '\0') {
        if (*str == (char)c) {
            return (char *)str;
        }
        str++;
    }
	/* TODO: Implement strchr(). */
	return NULL;
}

char *strrchr(const char *str, int c)
{
	const char *lastOccurrence = NULL;

    while (*str != '\0') {
        if (*str == (char)c) {
            lastOccurrence = str;
        }
        str++;
    }
	if (lastOccurrence != NULL) {
        return (char *)lastOccurrence;
    } else {
        return NULL;
    }
	/* TODO: Implement strrchr(). */
}

char *strstr(const char *haystack, const char *needle)
{
	if (*needle == '\0') {
        return (char *)haystack;
    }

    size_t needleLength = strlen(needle);
    while (*haystack != '\0') {
        if (*haystack == *needle) {
            const char *h = haystack;
            const char *n = needle;

            while (*n != '\0' && *h == *n) {
                h++;
                n++;
            }

            if (*n == '\0') {
                return (char *)haystack;
            }
        }

        haystack++;
    }
	/* TODO: Implement strstr(). */
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	if (*needle == '\0') {
        return (char *)haystack;
    }
    size_t haystackLen = strlen(haystack);
    size_t needleLen = strlen(needle);
    if (needleLen > haystackLen) {
        return NULL;
    }
    const char *found = NULL;
    for (size_t i = 0; i <= haystackLen - needleLen; ++i) {
        if (strncmp(&haystack[i], needle, needleLen) == 0) {
            found = &haystack[i];
        }
    }
    return (char *)found;
	/* TODO: Implement strrstr(). */
}

void *memcpy(void *destination, const void *source, size_t num)
{
	unsigned char *dest = (unsigned char *)destination;
    const unsigned char *src = (const unsigned char *)source;

    for (size_t i = 0; i < num; i++) {
        dest[i] = src[i];
    }
	/* TODO: Implement memcpy(). */
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	unsigned char *dest = (unsigned char *)destination;
    const unsigned char *src = (const unsigned char *)source;
    if (dest < src) {
        for (size_t i = 0; i < num; i++) {
            dest[i] = src[i];
        }
    } else if (dest > src) {
        for (size_t i = num; i > 0; i--) {
            dest[i - 1] = src[i - 1];
        }
    }
	/* TODO: Implement memmove(). */
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	const unsigned char *p1 = (const unsigned char *)ptr1;
    const unsigned char *p2 = (const unsigned char *)ptr2;

    for (size_t i = 0; i < num; i++) {
        if (p1[i] != p2[i]) {
            return p1[i] - p2[i];
        }
    }
	/* TODO: Implement memcmp(). */
	return 0;
}

void *memset(void *source, int value, size_t num)
{
	unsigned char *ptr = (unsigned char *)source;
    unsigned char val = (unsigned char)value;
    for (size_t i = 0; i < num; i++) {
        ptr[i] = val;
    }
	/* TODO: Implement memset(). */
	return source;
}
