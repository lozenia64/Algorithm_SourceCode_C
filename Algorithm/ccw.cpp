
typedef pair<int, int> P;
int ccw(P a, P b, P c) {
	return (a.x*b.y + b.x*c.y + c.x*a.y) - (a.y*b.x + b.y*c.x + c.y*a.x);
}

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
	return (x1*y2 + x2*y3 + x3*y1) - (y1*x2 + y2*x3 + y3*x1);
}
