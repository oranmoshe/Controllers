#pragma once

#include "../Control/Control.h"

class Label : public Control {
private:
	string _text;

protected:

public:
	Label(int);
	~Label();

	void setText(string);
	string getText() const;

	virtual void draw(Graphics&, int, int, size_t);
	virtual void mousePressed(int, int, bool);
	virtual void keyDown(int, char);
	virtual bool canGetFocus() const;
};