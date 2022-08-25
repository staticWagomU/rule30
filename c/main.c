#include <stdio.h>
#include <math.h>

int
main(int argv, char **args) {
	int n = 121;
	int step = 50;
	int cells[n], previous_cells[n];
	int i, j;
	int l, c, r;

	for(i=0; i<n; i++)cells[i]=0;
	cells[(int)ceil(n/2)]=1;

	for(i=0; i<n; i++)printf("%d", cells[i]);
	printf("\n");
	for(j=0; j<step; j++){
		for(i=0; i<n; i++){
			l = i==0?cells[n-1]:cells[i-1];
			c = cells[i];
			r = i==n-1?cells[0]:cells[i+1];
			if(l==0 && c==0 && r==1){
				previous_cells[i]=1;
			}else if(l==0 && c==1 && r==0){
				previous_cells[i]=1;
			}else if(l==0 && c==1 && r==1){
				previous_cells[i]=1;
			}else if(l==1 && c==0 && r==0){
				previous_cells[i]=1;
			}else {
				previous_cells[i]=0;
			}
		}
		for(i=0; i<n; i++)cells[i]=previous_cells[i];
		for(i=0; i<n; i++)printf("%d", cells[i]);
		printf("\n");
	}
	return 1;
}
