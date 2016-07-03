#pragma once

#include <Windows.h>
#include <vector>
#include "../Graphics/Graphics.h"
using namespace std;

enum Single { S_TOP_LEFT_CHAR = '\xDA', S_TOP_RIGHT_CHAR = '\xBF', S_HORZ_CHAR = '\xB3', S_VERT_CHAR = '\xC4', S_BOTTOM_LEFT_CHAR = '\xC0', S_BOTTOM_RIGHT_CHAR = '\xD9' };
enum Double { D_TOP_LEFT_CHAR = '\xC9', D_TOP_RIGHT_CHAR = '\xBB', D_HORZ_CHAR = '\xBA', D_VERT_CHAR = '\xCD', D_BOTTOM_LEFT_CHAR = '\xC8', D_BOTTOM_RIGHT_CHAR = '\xBC' };

enum class BorderType { Single, Double, None };

class Control {
private:
	int				_width;
	int				_height;
	bool			_isVisible;
	size_t			_layer;
	BackgroundColor	_bgColor;
	ForegroundColor	_fgColor;
	BorderType		_border;
	
protected:
	COORD	_position;
	//Graphics _graphics;			//? CHECK IF MUST

public:
	Control(int);
	~Control();

	void setWidth(int);
	void setHeight(int);
	void SetVisibility(bool);
	void setLayer(size_t);
	void setPosition(COORD);
	void SetBackground(BackgroundColor);
	void SetForeground(ForegroundColor);
	void setBorder(BorderType);
	static void setFocus(Control*);
	void Show();
	void Hide();

	int getWidth() const;
	int getHeight() const;
	bool getVisibility() const;
	size_t getLayer() const;
	COORD getPosition() const;
	BorderType getBorder() const;
	static Control* getFocus();
	BackgroundColor getBackgroundColor() const;
	ForegroundColor getForegroundColor() const;

	int getLeft() const;
	int getTop() const;

	virtual void draw(Graphics&, int, int, size_t);
	virtual void mousePressed(int, int, bool) = 0;
	virtual void keyDown(int, char) = 0;
	virtual bool canGetFocus() const;
	virtual void getAllControls(vector<Control*>&) {}
	//virtual void showCursorOnScreen() = 0;
	
	void drawBorder(Graphics&, int, int, size_t);

};

static Control* focus = NULL;