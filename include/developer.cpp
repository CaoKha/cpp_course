#include "developer.h"

developer::developer(std::string n, std::string l) : person(n), language(l) {}
std::string developer::dev_show() { return "I am " + get_name() + " and I code " + get_language(); }