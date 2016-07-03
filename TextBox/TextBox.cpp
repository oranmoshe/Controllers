#include "TextBox.h"

TextBox::TextBox(int width) : Control(width) {
	_cursor = { getLeft() + 1, getTop() + 1 };
}

TextBox::~TextBox() {

}

void TextBox::setText(string text) {
	_text = text;
}

string TextBox::getText() const {
	return _text;
}

void TextBox::showCursorOnScreen() {
	//_graphics.setCursorVisibility(true);
	//_graphics.moveTo(_cursor.X, _cursor.Y);
}

void TextBox::draw(Graphics& g, int x, int y, size_t layer) {
	//g.setBackground(getBackgroundColor());
	//g.setForeground(getForegroundColor());
	Control::draw(g, x, y, layer);
	if (getBorder() != BorderType::None) g.write(x + getLeft() + 1, y + getTop() + 1, _text);
	else g.write(x + getLeft(), y + getTop(), _text);
	_cursor = { getLeft() + _text.length(), getTop() + 1 };
	if (getFocus() == this) showCursorOnScreen();
}

void TextBox::mousePressed(int x, int y, bool isLeft) {
	if (getVisibility()) {
		int width = getWidth();
		int height = getHeight();
		if (getBorder() != BorderType::None) {
			width += 2;
			height += 2;
		}
		if (x > getLeft() - 1 && x < getLeft() + width && y<getTop() - 1 && y>getTop() + height) {
			Control::setFocus(this);
		}
	}
}

void TextBox::keyDown(int code, char ch) {
	COORD crd;
	crd.Y = _cursor.Y;
	crd.X = _cursor.X;
	Graphics().moveTo(this->_position.X + 1, this->_position.Y + 1);
	
	if ((code >= 65 && code <= 90) || (code >= 97 && code <= 122) || (code >= 48 && code <= 57) || (code == 32))
	{
		if (this->_text.length() < this->_position.X - 3 || this->_text.length() == this->_position.X - 3)
		{
			this->_text = this->_text + string(1, ch);
			crd.X++;
			_cursor =(crd);
		}
	}
	COORD coord;
	coord.Y = _cursor.Y;
	switch (code){
	case VK_BACK:
		coord.X = _cursor.X - 1;
		_cursor = (coord);
		_text.erase(this->_text.length() - 1, 1);
		break;
	case VK_RIGHT:
	case VK_NUMPAD6:
		coord.X = _cursor.X + 1;
		_cursor = (coord);
		break;
	case VK_LEFT:
	case VK_NUMPAD4:
		coord.X = _cursor.X - 1;
		_cursor = (coord);
		break;
	case VK_RETURN:
		break;
	case VK_DELETE:
		break;
	default:
		break;
	}
}

bool TextBox::canGetFocus() const {
	return true;
}
