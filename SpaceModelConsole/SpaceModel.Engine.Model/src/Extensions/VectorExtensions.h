#pragma once

#include <vector>

template<typename T>
class VectorExtensions
{
public:
	static int getIndex(const std::vector<T> &vector,const T &value)
	{
		int index = 0;
		for (
			std::vector<T>::const_iterator i = vector.begin();
			i != vector.end();
			i++,index++)
		{
			if (*i == value) {
				return index;
			}
		}
		
		return -1;
	}

	static bool IsContain(const std::vector<T> &vector,const T &value) 
	{
		return getIndex(vector, value) >= 0;
	}

	static bool Remove(std::vector<T> &vector,const T &value)
	{
		int index = getIndex(vector, value);
		if (index < 0) {
			return false;
		}

		vector.erase(vector.begin() + index);
		return true;
	}
};