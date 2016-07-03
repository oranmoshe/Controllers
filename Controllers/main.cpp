#include <string>
#include "../EventEngine/EventEngine.h"
#include "../TextBox/TextBox.h"
#include "../Label/Label.h"
//#include "Button.h"
#include "../Panel/Panel.h"
//#include "NumericBox.h"
//#include "ComboBox.h"
using namespace std;

/*struct MyListener : public MouseListener
{
	MyListener(Control &c) : _c(c) { }
	void mousePressed(Button &b, int x, int y, bool isLeft)
	{
		_c.setForeground(Color::Red);
	}
private:
	Control &_c;
};*/

int main(int argc, char **argv)
{
	Label lName(20);
	lName.setText("Name: ");
	Label lAddress(20);
	lAddress.setText("Address:");
	Label lCountry(20);
	lCountry.setText("Counrty:");
	Label lSex(20);
	lSex.setText("Sex:");
	Label lInterests(20);
	lInterests.setText("Interests:");
	Label lAge(20);
	lAge.setText("Age:");


	TextBox tName(20);
	tName.setText("Sherlock Holmes");
	tName.setBorder(BorderType::Double);
	TextBox tAddress(25);
	tAddress.setText("221B Baker Street, London");
	tAddress.setBorder(BorderType::Single);
	/*ComboBox cCountry({ "Israel", "Great Britain", "United States" }, 20);
	cCountry.setSelectedIndex(1);
	cCountry.setBorder(BorderType::Single);
	Radiolist rSex(2, 15, { "Male", "Female" });
	rSex.setBorder(BorderType::Single);
	Checklist clInterests(3, 15, { "Sports", "Books", "Movies" });
	clInterests.selectIndex(1);
	clInterests.setBorder(BorderType::Single);
	NumericBox nAge(15, 18, 120);
	nAge.setValue(23);
	nAge.setBorder(BorderType::Single);
	MyListener listener(tAddress);
	Button bSubmit(10);
	bSubmit.setText("Submit");
	bSubmit.addListener(listener);
	bSubmit.setBorder(BorderType::Double);*/
	Panel main;
	main.AddControl(lName, 1, 2);
	main.AddControl(lAddress, 1, 5);
	main.AddControl(lCountry, 1, 8);
	main.AddControl(lSex, 1, 11);
	main.AddControl(lInterests, 1, 15);
	main.AddControl(lAge, 1, 20);
	main.AddControl(tName, 25, 2);
	main.AddControl(tAddress, 25, 5);
	/*main.AddControl(cCountry, 25, 8);
	main.AddControl(rSex, 25, 11);
	main.AddControl(clInterests, 25, 15);
	main.AddControl(nAge, 25, 20);

	main.AddControl(bSubmit, 1, 22);*/
	Control::setFocus(&tName);
	EventEngine engine;
	engine.run(main);
	return 0;
}