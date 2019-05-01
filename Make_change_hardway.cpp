#include <iostream>

using namespace std;

int main() {
	int c25, c10, c5, c1;
	int amount;
	cin >> c25 >> c10 >> c5 >> c1 >> amount;
	int coin, coinx;
	coin = c25 + c10 + c5 + c1;
	int i25, i10, i5, i1;
	int min = coin;
	int sum;
	int f25, f10, f5, f1;
	bool can = false;
	for (i25 = 0; i25 <= c25; i25++){
		for (i10 = 0; i10 <= c10; i10++){
			for (i5 = 0; i5 <= c5; i5++){
				for (i1 = 0; i1 <= c1; i1++){
					sum = i25 * 25 + i10 * 10 + i5 * 5 + i1 * 1;
					coinx = i25 + i10 + i5 + i1;
					if (sum == amount) {
						can = true;
						if (coinx <= min) {
							min = coinx;
							f25 = i25;
							f10 = i10;
							f5 = i5;
							f1 = i1;
						}
					}
				}
			}
		}
	}
	if (can){
		cout << f25 << " " << f10 << " " << f5 << " " << f1 << endl;
	}
	else {
		cerr << "Error: cannot make change." << endl;
	}
	return 0;
}