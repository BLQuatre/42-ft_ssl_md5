#include <ft_ssl.h>

size_t ft_strlen(const char *msg) {
	size_t count = 0;
	while (*msg++)
		count++;

	return count;
}

void *ft_memcpy(void *dest, const void *src, size_t n) {
	unsigned char *d = (unsigned char *)dest;
	const unsigned char *s = (const unsigned char *)src;

	if (!dest && !src)
		return NULL;

	while (n--)
		*d++ = *s++;

	return dest;
}

void ft_write(int fd, char *msg) {
	write(fd, msg, ft_strlen(msg));
}

int ft_strncmp(const char *s1, const char *s2, size_t n) {
	while (n > 0 && *s1 && (*s1 == *s2)) {
		s1++;
		s2++;
		n--;
	}

	if (n == 0)
		return 0;

	return *(unsigned char *)s1 - *(unsigned char *)s2;
}

void ft_reverse(unsigned char *str, size_t n) {
	if (n == 0)
		return;

	for (size_t i = 0; i < n / 2; i++) {
		unsigned char tmp = str[i];
		str[i] = str[n - i - 1];
		str[n - i - 1] = tmp;
	}
}

char *ft_strdup(const char *s1) {
	size_t len = ft_strlen(s1);
	char *dup = (char *) malloc(len + 1);
	if (!dup)
		return NULL;

	size_t i = 0;
	while (i < len) {
		dup[i] = s1[i];
		i++;
	}

	dup[i] = '\0';
	return dup;
}

char *ft_strjoin(const char *s1, const char *s2) {
	size_t len1 = ft_strlen(s1);
	size_t len2 = ft_strlen(s2);
	char *joined = (char *) malloc(len1 + len2 + 1);
	if (!joined)
		return NULL;

	size_t i = 0;
	while (i < len1) {
		joined[i] = s1[i];
		i++;
	}

	while (i < len1 + len2) {
		joined[i] = s2[i - len1];
		i++;
	}

	joined[i] = '\0';
	return joined;
}

static void *ft_memset(void *s, int c, size_t n)
{
	char *array = (char *) s;
	size_t i = 0;
	while (i < n) {
		array[i] = c;
		i++;
	}

	return s;
}

void *ft_calloc(size_t nmemb, size_t size) {
	if (nmemb == 0 || size == 0)
		return NULL;

	void *ptr = malloc(nmemb * size);
	if (!ptr)
		return NULL;

	ft_memset(ptr, 0, nmemb * size);
	return ptr;
}

char *ft_strchr(const char *s, int c) {
	size_t i = 0;
	while (s[i]) {
		if (s[i] == (char) c)
			return (char *) (s + i);
		i++;
	}

	if (s[i] == (char) c)
		return (char *) (s + i);

	return NULL;
}