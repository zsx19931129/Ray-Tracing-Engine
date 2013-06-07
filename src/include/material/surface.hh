// File: surface.hh
<<<<<<< HEAD
// Date: Fri Jun 07 21:54:36 2013 +0800
=======
// Date: Fri Jun 07 21:54:36 2013 +0800
>>>>>>> 2465e2402a229ad6c68cf00dcfa3d7313007afd8
// Author: Yuxin Wu <ppwwyyxxc@gmail.com>

#pragma once

#include "color.hh"

class Surface {
	// http://en.wikipedia.org/wiki/Phong_reflection_model
	public:
		real_t transparency = 0,
			   shininess = 0,
			   refractive = 0;
		Color diffuse = Color::BLACK,
			  ambient = Color::BLACK,
			  specular = Color::BLACK;

		Surface(){}

		Surface(real_t _transparency, real_t _shininess,
				const Color& _diffuse, const Color& _ambient,
				const Color& _specular, real_t _refractive = DEFAULT_REFRACTIVE_INDEX):
			transparency(_transparency), shininess(_shininess), refractive(_refractive),
			diffuse(_diffuse), ambient(_ambient), specular(_specular) {}

		static const Surface WHITE_REFL, BLACK_REFL, BLUE_REFL;
};

