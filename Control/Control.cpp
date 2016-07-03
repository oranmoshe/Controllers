#include "Control.h"

Control::Control(int width) : _width(width), _height(1), _bgColor(BackgroundColor::Black), _fgColor(ForegroundColor::White),
							  _isVisible(true), _layer(0), _border(BorderType::None), _position({ 0, 0 }) {

}

Control::~Control() {

}

void Control::setWidth(int width) {
	_width = width;
}

void Control::setHeight(int height) {
	_height = height;
}

void Control::SetVisibility(bool visibility) {
	if (visibility) Show();
	else Hide();
}

void Control::setLayer(size_t layer) {
	_layer = layer;
}

void Control::setPosition(COORD position) {
	_position = position;
}

void Control::SetBackground(BackgroundColor background) {
	_bgColor = background;
}

void Control::SetForeground(ForegroundColor foreground) {
	_fgColor = foreground;
}

void Control::setBorder(BorderType border) {
	_border = border;
}

#include <typeinfo>
void Control::setFocus(Control* c){
	focus = c;
	string g = typeid(*c).name();
	//if (g.compare("class TextBox")) c->showCursorOnScreen();

}

void Control::Show() {
	_isVisible = true;
	_layer = 5;
}

void Control::Hide() {
	_isVisible = false;
	_layer = 0;
}

int Control::getWidth() const {
	return _width;
}

int Control::getHeight() const {
	return _height;
}

bool Control::getVisibility() const {
	return _isVisible;
}

size_t Control::getLayer() const {
	return _layer;
}

COORD Control::getPosition() const {
	return _position;
}

BorderType Control::getBorder() const {
	return _border;
}

Control* Control::getFocus() {
	return focus;
}

BackgroundColor Control::getBackgroundColor() const {
	return _bgColor;
}

ForegroundColor Control::getForegroundColor() const {
	return _fgColor;
}

void Control::draw(Graphics &g, int left, int top, size_t layer) {
	if (_border != BorderType::None) drawBorder(g, left, top, layer);
}

bool Control::canGetFocus() const {
	return false;
}

int Control::getLeft() const {
	return _position.X;
}

int Control::getTop() const {
	return _position.Y;
}

void Control::drawBorder(Graphics& g, int x, int y, size_t layer) {
	x += _position.X;
	y += _position.Y;
	g.moveTo(x, y);
	g.write(string(1, _border == BorderType::Single ? S_TOP_LEFT_CHAR : D_TOP_LEFT_CHAR));
	g.write(string(_width, _border == BorderType::Single ? S_VERT_CHAR : D_VERT_CHAR));
	g.write(string(1, _border == BorderType::Single ? S_TOP_RIGHT_CHAR : D_TOP_RIGHT_CHAR));

	for (int i = 0; i < _height; i++) {
		g.write(x, y + 1, string(1, _border == BorderType::Single ? S_HORZ_CHAR : D_HORZ_CHAR));
		g.write(string(_width, ' '));
		g.write(string(1, _border == BorderType::Single ? S_HORZ_CHAR : D_HORZ_CHAR));
	}

	g.write(x, y + 2, string(1, _border == BorderType::Single ? S_BOTTOM_LEFT_CHAR : D_BOTTOM_LEFT_CHAR));
	g.write(string(_width, _border == BorderType::Single ? S_VERT_CHAR : D_VERT_CHAR));
	g.write(string(1, _border == BorderType::Single ? S_BOTTOM_RIGHT_CHAR : D_BOTTOM_RIGHT_CHAR));

	g.moveTo(x + _width, y + _height + 1);
}