// File: view.hh
// Date: Wed Jun 19 00:20:10 2013 +0800
// Author: Yuxin Wu <ppwwyyxxc@gmail.com>

#pragma once

#include <memory>
#include "geometry/geometry.hh"
#include "space.hh"
using namespace std;

class View {
	private:
		const Geometry geo;

		inline void normalize_dir_vector()
		{ dir_w.normalize(); dir_h.normalize(); }

		inline void resume_dir_vector() {
			dir_w = dir_w.get_normalized() * (size / geo.w);
			dir_h = dir_h.get_normalized() * (size / geo.h);
		}

	public:
		std::shared_ptr<Space> sp;
		Vec view_point;
		Vec mid;
		real_t size;		// length the img cover in the scene
		Vec dir_w, dir_h;

		bool use_dof = true;

		View(const std::shared_ptr<Space> m_sp, const Vec& m_view_point,
				const Vec& m_mid, real_t w, const Geometry& m_geo);

		void zoom(real_t ratio);	// r > 1: zoom in

		void twist(int angle); // -180 ~ 180

		void rotate(int angle); // -180 ~ 180

		void shift(real_t dist, bool horiz);

		void move_screen(real_t dist);

		Color render(int i, int j, bool debug = false) const;	// i row j column

		const Geometry& get_geo() const
		{return geo; }

};

