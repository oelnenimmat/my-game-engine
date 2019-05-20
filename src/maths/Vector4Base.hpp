#pragma once

#include "VectorBase.hpp"
#include "../assertions.hpp"

namespace ng::maths
{
	/*
	Base alias for 4d vector types
	*/
	template<typename T>
	using Vector4Base = VectorBase<T, 4>;

	template<typename ValueType>
	union VectorBase<ValueType, 4>
	{
		constexpr static int dimension = 4;
		
		using value_type = ValueType;
		using this_type = VectorBase<value_type, dimension>;

		struct
		{
			union { value_type x, r; };
			union { value_type y, g; };
			union { value_type z, b; };
			union { value_type w, a; };
		};
		value_type mData [dimension];

		value_type & operator [] (int index)
		{
			NG_ASSERT (0 <= index && index < dimension);

			return mData [index];
		}

		value_type operator [] (int index) const
		{
			NG_ASSERT (0 <= index && index < dimension);

			return mData [index];
		}
		
		const value_type * valuePtr() const
		{
			return mData;
		}	
	};
}