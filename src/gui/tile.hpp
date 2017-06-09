#ifndef TILE_HPP
#define TILE_HPP

#include <vector>
#include <sstream>

#include <boost/smart_ptr.hpp>


struct Tile
{

    unsigned int id_;

    unsigned int terrain_;
	char terrain_representation_;

	std::vector<unsigned int > cover_;

	std::string ToString()
	{
		std::stringstream os;
		os << "{ id : " << id_ 
						<< " terrain : " << terrain_ 
						<< " terrain_representation : " << terrain_representation_ << " ";		
		for( size_t i = 0;
				i < cover_.size();
				++i
			)
		{
			os << "cover[" << i << "] : " << cover_[i];
		}

		return os.str();
	}
};

#endif
