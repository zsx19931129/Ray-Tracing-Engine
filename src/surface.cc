// File: surface.cc
// Date: Fri Jun 14 11:03:50 2013 +0800
// Author: Yuxin Wu <ppwwyyxxc@gmail.com>

#include "material/surface.hh"
using namespace std;

const Surface
	Surface::WHITE_REFL(0, 20, Color::WHITE, Color::WHITE, Color::WHITE * DEFAULT_SPECULAR),
	Surface::BLACK_REFL(0, 20, Color::BLACK, Color::WHITE, Color::WHITE * DEFAULT_SPECULAR),
	Surface::BLUE_REFL(0.2, 50, Color::BLUE, Color::WHITE, Color::WHITE * DEFAULT_SPECULAR),
	Surface::RED(0, 50, Color::RED, Color::WHITE, Color::WHITE * DEFAULT_SPECULAR);



