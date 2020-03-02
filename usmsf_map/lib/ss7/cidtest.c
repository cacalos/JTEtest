#include <stdio.h>

int main()
{
	int i, j, id;
	int alloc[1000];
	int n = 0;

	did_init(20);

	for( i=0; i< 100000; i++) {
		id = did_alloc();
		if ( id < 0) {
			for( j=0; j< n; j++) {
				did_free( alloc[j]);
			}
			n=0;
		}

		printf("alloc %d\n", id);
		alloc[n++] = id;

		if ( n > 100 ) {
			for( j=n-1; j>= n-50; j--) {
				did_free( alloc[j]);
			}
			n -= 50;
		}

		did_checkValid();
	}

	return 0;
}

