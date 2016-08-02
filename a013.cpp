#include <iostream>
#include <math.h>
using namespace std;

const string roma = "MDCLXVI";
const int number[] = {1000, 500, 100, 50, 10, 5, 1};

int RomaToNumber(string n) {
	int ans = 0;
	for (int i = 0; i < n.size(); i++) {
		if (roma.find(n[i]) < roma.find(n[i - 1]) && i != 0) {
			ans -= number[roma.find(n[i - 1])] * 2;
		}
		ans += number[roma.find(n[i])];
		//cout << "Roma To Number: " << ans << endl;
	}
	return ans;
}

string NumberToRoma(int n) {
	string ans;
	int tmp, key;
	for (int i = 6; i >= 0; i -= 2) {
		tmp = n % 10;
		n /= 10;
		key = 0;
		if (tmp == 4) {
			ans.insert(0, roma, i - 1, 1);
			ans.insert(0, roma, i, 1);
		}
		else if (tmp == 9) {
			ans.insert(0, roma, i - 2, 1);
			ans.insert(0, roma, i, 1);
		}
		else {
			tmp *= pow(10, (6-i) / 2);
			while (tmp >= number[i - 1]) {
				tmp -= number[i - 1];
				key = 1;
			}
			while (tmp >= number[i]) {
				tmp -= number[i];
				ans.insert(0, roma, i, 1);
			}
			if (key == 1) {
				ans.insert(0, roma, i - 1, 1);
			}
		}
	}

	return ans;
}

int main(int argc, const char *argv[])
{
	string na, nb;
	while (cin >> na) {
		if (na == "#") {
			break;
		}
		cin >> nb;
		if (na == nb) {
			cout << "ZERO" << endl;
		}
		else {
			cout << NumberToRoma(fabs(RomaToNumber(na) - RomaToNumber(nb))) << endl;
		}
	}
	return 0;
}

