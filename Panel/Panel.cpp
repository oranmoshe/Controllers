#include "Panel.h"

Panel::Panel() : Control(0), _height(0) {

}

Panel::Panel(int height, int width) : Control(width), _height(height) {

}

Panel::~Panel() {

}

void Panel::AddControl(Control& c, int x, int y) {
	c.setPosition({ x, y });
	_controls.push_back(&c);
}

void Panel::getAllControls(vector<Control*> &controls) {
	for (Control* c : _controls) {
		controls.push_back(c);
	}
}

void Panel::draw(Graphics& g, int x, int y, size_t layer) {
	for (Control * c : _controls) c->draw(g, x, y, layer);
}

void Panel::mousePressed(int x, int y, bool isLeft) {
	for (int i = _position.Y; i < _position.Y + getTop() + 1; i++){
		for (int j = _position.X; j < _position.X + getLeft() + 1; j++){
			if (i == y && j == x){
				
			}
		}
	}
}

void Panel::keyDown(int, char) {

}

bool Panel::canGetFocus() const {
	return true;
}
