class Point {
	public:
		Point(int x, int y);
		Point(const Point& point) = delete;
		Point& operator=(const Point& point) = delete;
		int getX() const;
		void setX(int x);
		int getY() const;
		void setY(int y);
	private:
		int x_;
		int y_;
}