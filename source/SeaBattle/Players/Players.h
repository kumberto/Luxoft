#pragma once
#include <string>
class Players
{
public:
	Players(std::string name);
	Players(const Players& player) = delete;
	Players& operator=(const Players& player) = delete;
	virtual ~Players() = 0;
	std::string getName() const;
	virtual void move() = 0;
	void statistics() const;
	virtual bool shot(int x, int y) const;
protected:
	int getHit() const;
	void setHit();
	int getMishit() const;
	void setMishit();
	int getKilledShips() const;
	void setKilledShips();
private:
	std::string name_;
	int hit_;
	int mishit_;
	int killedShips_;
};

