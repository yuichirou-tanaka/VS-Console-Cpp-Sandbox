#include <iostream>
#include <algorithm>
using namespace std;


void sorttest() {
	struct mginfo {
		int number;
		int order;
		mginfo(int _n, int _o) :number(_n), order(_o) {}
		void print() {
			cout << "number:" << number << ", order:" << order << endl;
		}

		
	};
	mginfo ary[3] = { mginfo(4,10), mginfo(3,3), mginfo(1,40) };
	for (auto i : ary) {
		i.print();
	}

	std::sort(ary, std::end(ary), [](const mginfo& a, const mginfo& b) {
		return a.number < b.number;
	});

	for (auto i : ary) {
		i.print();
	}


}

int main()
{
	sorttest();
    return 0;
}
