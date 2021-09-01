# include <stdio.h>

void main () {
    
    int x1x[15], h1x[15], y1x[15];
    int i, j, N;
    printf("Enter N = ");
    scanf("%d", &N);

    for(i = 0; i < N; i++) {
        printf("Enter the first sequence x[n]:");
        scanf("%d",&x1x[i]);
    }

    for(i = 0; i < N; i++) {
        printf("Enter the second sequence h[n]:");
        scanf("%d",&h1x[i]);
    }

    for (i = N; i <= ((2 * N) - 1); i++) {
		x1x[i] = 0;
	}

	for (i = N; i <= ((2 * N) - 1); i++) {
		h1x[i] = 0;
	}

    printf("Output sequence:\n");

	for(i = 0; i < ((2 * N) - 1); i++) {
		y1x[i] = 0;

		for(j = 0; j <= i; j++) {
			y1x[i] = y1x[i] + (x1x[j] * h1x[i - j]);
		}

         printf("%d ", y1x[i]);
    }
}