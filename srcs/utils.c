#include <ft_ssl.h>

size_t ft_strlen(const char *msg) {
	size_t count = 0;
	while (*msg++) {
		count++;
	}

	return count;
}

void *ft_memcpy(void *dest, const void *src, size_t n) {
	unsigned char *d = (unsigned char *)dest;
	const unsigned char *s = (const unsigned char *)src;

	if (!dest && !src) {
		return NULL;
	}

	while (n--) {
		*d++ = *s++;
	}
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
	if (n == 0) {
		return (0);
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}