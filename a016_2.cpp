#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int main(int argc, const char *argv[])
{
	int tmp, row[9], n, x3[9][9], key;
	int i, j;
	while(cin.peek() != EOF) {
		n = 0;
		key = 0;
		memset(row, 0, sizeof(row));
		memset(x3, 0, sizeof(x3));
		for (i = 0; i < 9; i++) {
			if (i == 0) {
				row[i] = 0;
			}
			for (j = 0; j < 9; j++) {
				cin >> tmp;
				if (key == 0) {
					n += tmp;
					if (x3[tmp - 1][3*(i/3) + (j/3)] != 0) {
						key = 1;
					}
					x3[tmp - 1][3*(i/3) + (j/3)]++;
					row[j] += tmp;
				}
			}
			if (key == 0) {
				if (n != 45) {
					key = 1;
				}
				n = 0;
			}
		}
		if (key == 0) {
			for (i = 0; i < 9; i++) {
				if (row[i] != 45) {
					key = 1;
					break;
				}
			}
		}

		if (key == 0) {
			printf("yes\n");
		}
		else if (key == 1) {
			printf("no\n");
		}
		cin.get();
		cin.get();
	}
	return 0;
}
