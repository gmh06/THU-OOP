#pragma once

class Splash;

#include <iostream>

using namespace std;

enum Direction {NONE, LEFT, RIGHT, UP, DOWN};
enum Actor {PLAYER, WATER, TOXIC};

class Object {
protected:
	Splash* splash;
	int x, y;
public:
	Object(int x, int y, Splash* splash): x(x), y(y), splash(splash) {}
	virtual int act(Direction fromwhere, Actor fromwho) = 0;
	virtual ~Object() {}
};

class Water : public Object {
private:
	int size;
public:
	Water(int size, int x, int y, Splash* splash): size(size), Object(x, y, splash) {}
	int act(Direction fromwhere, Actor fromwho);
};

class Void : public Object {
public:
	Void(int x, int y, Splash* splash): Object(x, y, splash) {}
	int act(Direction fromwhere, Actor fromwho);
};

class Barrier : public Object {
public:
	Barrier(int x, int y, Splash* splash): Object(x, y, splash) {}
	// hit a barrier will cause no effect
	int act(Direction fromwhere, Actor fromwho);
};

class Toxic : public Object {
private:
	int size;
public:
	Toxic(int size, int x, int y, Splash* splash): size(size), Object(x, y, splash) {}
	int act(Direction fromwhere, Actor fromwho);
};
