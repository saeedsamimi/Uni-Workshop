#include <iostream>
using std::cout, std::cin, std::endl;

struct Point {
	int x, y;
};

void generateSpiral(int, int, int, Point&, Point&);

int main(){
	int n, A, B;
	cin >> n >> A >> B;
	Point start = { -1,-1 }, end = { -1,-1 }; // invalid location
	generateSpiral(n, A, B, start, end);
	if (start.x > end.x)
		cout << start.x - end.x << " L" << endl;
	else if (start.x < end.x)
		cout << end.x - start.x << " R" << endl;
	if (start.y > end.y)
		cout << start.y - end.y << " U";
	else if (start.y < end.y)
		cout << end.y - start.y << " D";
	return 0;
}

constexpr bool CAN(Point &a, Point &b) {
	return (a.x == -1 || a.y == -1 || b.x == -1 || b.y == -1);
}

void checkPosition(int k,int start,int end,int row,int col,Point &startPoint,Point& endPoint) {
	if (k == start) {
		startPoint.x = col;
		startPoint.y = row;
	}
	else if (k == end) {
		endPoint.x = col;
		endPoint.y = row;
	}
}

void generateSpiral(int n, int start, int end, Point &startPoint, Point &endPoint) {
	// generate last line
	int row, col, k = 1;
	row = n - 1;
	for (col = 0;col < n && CAN(startPoint, endPoint);col++,k++)
		checkPosition(k, start, end, row, col, startPoint, endPoint);
	n--, col--;
	char Sw = -1;
	while (n > 0 && CAN(startPoint, endPoint)) {
		// vertical movement
		int minRow = row + Sw * n;
		row += Sw;
		for (;Sw*(row - minRow) <= 0 && CAN(startPoint, endPoint);row += Sw, k++)
			checkPosition(k, start, end, row, col, startPoint, endPoint);
		row -= Sw;
		int minCol = col + Sw * n;
		col += Sw;
		for (;Sw*(col - minCol) <= 0 && CAN(startPoint, endPoint);col += Sw, k++)
			checkPosition(k, start, end, row, col, startPoint, endPoint);
		// change while controllers
		col -= Sw;
		Sw *= -1;
		n--;
	}
}
