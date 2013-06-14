// File: plane.cc
// Date: Fri Jun 14 10:59:40 2013 +0800
// Author: Yuxin Wu <ppwwyyxxc@gmail.com>

#include "renderable/plane.hh"
using namespace std;

const InfPlane InfPlane::XYPLANE(Vec(0, 0, 1), 0),
	  InfPlane::YZPLANE(Vec(1, 0, 0), 0),
	  InfPlane::XZPLANE(Vec(0, 1, 0), 0);

shared_ptr<Trace> Plane::get_trace(const Ray& ray) const {
	shared_ptr<Trace> ret(new PlaneTrace(*this, ray));
	if (ret->intersect()) return ret;
	return nullptr;
}

Vec Plane::surf_dir() const {
	Vec ret(plane.norm.y, -plane.norm.x, 0);
	// possibily get a (0,0,0) !
	// but cannot be all zero
	if (ret == Vec::get_zero())
		ret = Vec(0, plane.norm.z, -plane.norm.y);
	m_assert(!(ret == Vec::get_zero()));
	ret.normalize();
	return ret;
}

void Plane::set_finite(real_t _radius, Vec _center) {
	radius = _radius;
	center = _center;
}

bool PlaneTrace::intersect() {
	dist_to_plane = plane.plane.dist(ray.orig);
	if (fabs(dist_to_plane) < EPS) // source on the plane
		return false;
	dir_dot_norm = plane.plane.norm.dot(ray.dir);
	if (fabs(dir_dot_norm) < EPS)  // parallel to plane
		return false;
	if ((dist_to_plane > 0) ^ (dir_dot_norm < 0))  // ray leaves plane
		return toward = false;

	if (plane.radius < EPS) 		// infinite
		return true;
	else {
		inter_dist = - dist_to_plane / dir_dot_norm;
		Vec inter_point = ray.get_dist(inter_dist);
		real_t dist = (inter_point - plane.center).mod();
		if (dist >= plane.radius)
			return false;
		else
			return true;
	}
}

real_t PlaneTrace::intersection_dist() {
	if (isfinite(inter_dist)) return inter_dist;
	inter_dist = -dist_to_plane / dir_dot_norm;
	return inter_dist;
}

Vec PlaneTrace::normal() {	// norm to the ray side
	Vec ret = plane.plane.norm;
	if (plane.plane.in_half_space(ray.orig))
		return ret;
	return -ret;
}

shared_ptr<Surface> PlaneTrace::transform_get_property() const {
	Vec diff = intersection_point() - plane.center;
	real_t x = diff.dot(plane.surfdir);
	real_t y = diff.dot(plane.surfdir.cross(plane.plane.norm));
	return plane.texture->get_property(x, y);
}
