#ifndef FT_SSL_MD5_H
# define FT_SSL_MD5_H

# include <stdint.h>
# include <stdbool.h>

# include "ft_ssl.h"
# include "ft_ssl_md5_errors.h"

# define CHUNK_SIZE 64 // 64 bytes = 512 bits

typedef struct s_md5_context {
	bool reverse;
	bool quiet;

	uint32_t A;
	uint32_t B;
	uint32_t C;
	uint32_t D;
} t_md5_context;

void md5_init(t_md5_context *ctx);
void md5_compute(const unsigned char *msg, size_t len_bytes, unsigned char result[16]);
void md5_print(const char *input, const unsigned char digest[16]);

unsigned char *md5_pad(const unsigned char *msg, size_t len_bytes, size_t *padded_len_bytes);
void md5_transform(t_md5_context *ctx, const unsigned char input[CHUNK_SIZE]);
void md5_finalize(t_md5_context *ctx, unsigned char *result);

#endif
