#include "Label.h"

Label::Label(int width) : Control(width) {

}

Label::~Label() {

}

void Label::setText(string text) {
	_text = text;
}

string Label::getText() const {
	return _text;
}

void Label::draw(Graphics& g, int x, int y, size_t layer) {
	//g.setBackground(getBackgroundColor());
	//g.setForeground(getForegroundColor());
	Control::draw(g, x, y, layer);
	if (getBorder() != BorderType::None) g.write(x + getLeft() + 1, y + getTop() + 1, _text);
	else g.write(x + getLeft(), y + getTop(), _text);
}

void Label::mousePressed(int, int, bool) {

}

void Label::keyDown(int, char) {

}

bool Label::canGetFocus() const {
	return false;
}
