


int itoa (unsigned char* to, int num)
{
	char						stack[16];
	int							ptr, len;


	for (ptr = 0; num && ptr < 16; num /= 10, ptr++) 	stack[ptr] = (num % 10) | 0x30;
	len = ptr;
	while ( ptr-- )										*to++ = stack[ptr];

	if ( !len ) {
		*to++ = '0';
		len = 1;
	}

	*to = 0;


	return len;
}
