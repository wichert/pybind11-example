#include "base.hh"

using namespace std;


Base::Base() : a(one) {
}

string Base::virt() {
	return "Base::virt()";
};


string Child::virt() {
	return "Child::virt()";
}

string Child::pureVirtual() {
	return "Child::pureVirtual()";
}