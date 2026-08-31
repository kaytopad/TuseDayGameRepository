#include <iostream>
#include "Dog.h"
using namespace std;

Dog::Dog(string Name)
{
	name = Name;
}

void Dog::ShowProfile()
{
	cout << "Œ¢‚Ì–¼‘O‚ÍA" << name << "‚Å‚·B\n";
}