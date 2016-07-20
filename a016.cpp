#include <stdio.h>
#include <iostream>
using namespace std;

int main(int argc, const char *argv[])
{
	int tmp, row[9], n, n1, n2, n3, key;
	int i, j;
	while(cin.peek() != EOF) {
		n = 0; n1 = 0; n2 = 0; n3 = 0;
		for (i = 0; i < 9; i++) {
			row[i] = 0;
		}
		key = 0;
		for (i = 0; i < 9; i++) {
			for (j = 0; j < 9; j++) {
				cin >> tmp;
				n += tmp;
				if (j / 3 == 0) {
					n1 += tmp;
				}
				else if (j / 3 == 1) {
					n2 += tmp;
				}
				else {
					n3 += tmp;
				}
				row[j] += tmp;
			}
			if (key == 0) {
				if ((i + 1) % 3 == 0) {
					if (n != 45 || n1 != 45 || n2 != 45 || n3 != 45) {
						key = 1;
					}
					else {
						n1 = 0;
						n2 = 0;
						n3 = 0;
					}
				}
				else if (n != 45) {
					key = 1;
				}
			}
			n = 0;
		}
		for (i = 0; i < 9; i++) {
			if (row[i] != 45) {
				key = 1;
				break;
			}
		}

		if (key == 0) {
			printf("yes\n");
		}
		else if (key == 1) {
			printf("no\n");
		}
		cin.get();
	}
	return 0;
}
