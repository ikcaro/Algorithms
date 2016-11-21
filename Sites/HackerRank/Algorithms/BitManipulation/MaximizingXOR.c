#include <stdio.h>
#include <string.h>

static inline unsigned max(unsigned a, unsigned b)
{
	if (a > b)
		return a;
	return b;
}

int main()
{
	unsigned l, r, m, i, j;
	
	m = 0;
	scanf("%u %u\n", &l, &r);
	for (i = l; i <= r; ++i)
		for (j = l; j <= r; ++j)
			m = max(m, i ^ j);

	printf("%d\n", m);
	return 0;
}

