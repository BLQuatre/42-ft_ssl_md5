#include "ft_ssl_md5.h"

void md5_init(t_md5_context *ctx) {
	ctx->A = 0x67452301;
	ctx->B = 0xefcdab89;
	ctx->C = 0x98badcfe;
	ctx->D = 0x10325476;
}

unsigned char *md5_pad(const unsigned char *msg, size_t len_bytes, size_t *padded_len_bytes) {
	size_t len_bits = len_bytes * 8;

	size_t total_len = len_bytes + 1 + 8;
	while (total_len % 64 != 0) {
		total_len++;
	}
	*padded_len_bytes = total_len;

	unsigned char *padded_msg = (unsigned char *) malloc(sizeof(unsigned char) * total_len);
	if (!padded_msg) {
		return NULL;
	};

	ft_memcpy(padded_msg, msg, len_bytes);

	padded_msg[len_bytes] = 0x80;

	for (size_t i = len_bytes + 1; i < total_len - 8; i++) {
		padded_msg[i] = 0x00;
	}

	unsigned char *length_field = padded_msg + (total_len - 8);
	for (int i = 0; i < 8; i++) {
		length_field[i] = (unsigned char)((len_bits >> (i * 8)) & 0xFF);
	}

	return padded_msg;
}
