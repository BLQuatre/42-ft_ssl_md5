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

unsigned char **ft_split_chunks(unsigned char *str, size_t str_len_bytes, size_t chunk_len_bytes) {
	if (str_len_bytes % chunk_len_bytes != 0) {
		return NULL;
	}

	size_t chunks_amount = str_len_bytes / chunk_len_bytes;

	unsigned char **chunks = (unsigned char **) malloc(sizeof(unsigned char *) * (chunks_amount + 1));
	if (!chunks) {
		return NULL;
	}

	// TODO: Free all if errors here
	for (size_t i = 0; i < chunks_amount; i++) {
		chunks[i] = (unsigned char *) malloc(sizeof(unsigned char) * chunk_len_bytes);
		ft_memcpy(chunks[i], str + (i * chunk_len_bytes), chunk_len_bytes);
	}

	chunks[chunks_amount] = NULL;
	return chunks;
}
