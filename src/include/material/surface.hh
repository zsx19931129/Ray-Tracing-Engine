// File: surface.hh
// Date: Thu Jun 20 02:13:16 2013 +0800
// Author: Yuxin Wu <ppwwyyxxc@gmail.com>

#pragma once

#include "color.hh"

class Surface {
	// http://en.wikipedia.org/wiki/Phong_reflection_model
	public:
		real_t transparency = 0,
			   shininess = 0,
			   refractive = 0,
			   ambient = 0;
		Color diffuse = Color::BLACK,
			  specular = Color::BLACK;
		bool ok = false;

		Surface(){}

		Surface(real_t _transparency, real_t _shininess,
				real_t _ambient, const Color& _diffuse,
				const Color& _specular, real_t _refractive = DEFAULT_REFRACTIVE_INDEX):
			transparency(_transparency), shininess(_shininess), refractive(_refractive),
			ambient(_ambient), diffuse(_diffuse), specular(_specular), ok(true) {}

		static const Surface WHITE_REFL, BLACK_REFL, BLUE_REFL, RED;
};

