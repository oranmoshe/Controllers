#pragma once

#include "../Control/Control.h"

class Panel : public Control {
private:
	int _height;
	vector<Control*> _controls;

protected:

public:
	Panel();
	Panel(int, int);
	~Panel();

	void AddControl(Control &, int, int);

	virtual void getAllControls(vector<Control*>&);
	virtual void draw(Graphics&, int, int, size_t);
	virtual void mousePressed(int, int, bool);
	virtual void keyDown(int, char);
	virtual bool canGetFocus() const;
};