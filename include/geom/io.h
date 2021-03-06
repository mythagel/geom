/* cxxcam - C++ CAD/CAM driver library.
 * Copyright (C) 2013  Nicholas Gill
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * io.h
 *
 *  Created on: 23/05/2013
 *      Author: nicholas
 */

#ifndef GEOM_IO_H_
#define GEOM_IO_H_
#include <vector>
#include <iosfwd>

namespace geom
{

class polyhedron_t;

// TODO better name
struct object_t
{
	struct vertex_3
	{
		double x;
		double y;
		double z;
	};
	struct vector_3
	{
		double x;
		double y;
		double z;
	};
	struct face
	{
		std::vector<std::size_t> vertices;
		vector_3 normal;
	};
	
	std::vector<vertex_3> vertices;
	std::vector<face> faces;
};

object_t to_object(const polyhedron_t& poly);
std::istream& operator>>(std::istream&, object_t&);

}

#endif /* GEOM_IO_H_ */
