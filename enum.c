#include <stdio.h>
enum week {frid = '0', sat = 'd', sun = '9'};
int main() {
	enum week day;
	day = frid;
	printf("%d\n", day); 
	return 0;
}
