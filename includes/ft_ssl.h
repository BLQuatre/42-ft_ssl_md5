#ifndef FT_SSL_H
# define FT_SSL_H

# include <unistd.h>
# include <stdlib.h>

size_t ft_strlen(const char *msg);
void *ft_memcpy(void *dest, const void *src, size_t n);
void ft_write(int fd, char *msg);
unsigned char **ft_split_chunks(unsigned char *str, size_t str_len_bytes, size_t chunk_len_bytes);

// TEMP DEV
# include <stdio.h>
void print_hex_dump(const unsigned char *data, size_t len, int bytes_per_line);

#endif
