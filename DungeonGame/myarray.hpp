//
//  myarray.hpp
//  myarray
//
//  Created by Ivan Yakovenko on 07/12/2018.
//  Copyright © 2018 Ivan Yakovenko. All rights reserved.
//

#ifndef myarray_
#define myarray_



#include <type_traits>
#include <algorithm>
#include <stdexcept>


template<typename T, int N>
class array
{
public:
	typedef T value_type;
	typedef size_t size_type;

	typedef typename std::add_lvalue_reference<T>::type reference;
	typedef const reference const_reference;
	typedef typename std::add_pointer<T>::type pointer;

	typedef const pointer const_pointer;
	typedef pointer iterator;
	typedef const_pointer const_iterator;
	
	
	
	constexpr size_type size() const { return N; }
	constexpr size_type max_size() const { return size(); }
	constexpr bool empty() const { return !N; }
	reference operator [](size_type idx) { return array_[idx]; }
	const_reference operator [](size_type idx) const { return array_[idx]; }
	reference at(size_type idx)
	{
		check_size(idx);
		return array_[idx];
	}
	const_reference at(size_type idx) const
	{
		check_size(idx);
		return array_[idx];
	}
	reference front()
	{
		return *begin();
	}
	const_reference front() const
	{
		return *begin();
	}
	reference back()
	{
		return N ? *(end() - 1) : *end();
	}
	const_reference back() const
	{
		return N ? (*end() - 1) : *end();
	}
	pointer data() { return array_; }
	const_pointer data() const { return array_; }
	iterator begin() { return iterator(array_); }
	const_iterator begin() const { return const_iterator(array_); }
	iterator end() { return iterator(array_ + N); }
	const_iterator end() const { return const_iterator(array_ + N); }
	
	
	void fill(const value_type& val)
	{
		for(int i = 0; i < N; i++){
			*(begin()+i) = val;
		}
	}
	
	
	void swap(array& other)
	{
		if(other.size() >= N)
			for(int i = 0; i < N; i++){
				*(other.begin()+i) = *(begin()+i);
			}
		else
			throw std::out_of_range("new_is_too_small");
	}
	
	T array_[N ? N : 1];
private:
	void check_size(size_type idx) const
	{
		if (idx >= size())
		{
			throw std::out_of_range("out_of_range");
		}
	}
};

#endif
