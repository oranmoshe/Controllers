#pragma once

#include "../Control/Control.h"

class TextBox : public Control {
private:
	string _text;
	COORD _cursor;
protected:

public:
	TextBox(int);
	~TextBox();

	void setText(string);
	string getText() const;
	void showCursorOnScreen();

	virtual void draw(Graphics&, int, int, size_t);
	virtual void mousePressed(int, int, bool);
	virtual void keyDown(int, char);
	virtual bool canGetFocus() const;
};