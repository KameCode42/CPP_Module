/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:33:12 by david             #+#    #+#             */
/*   Updated: 2025/10/16 17:27:57 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

/*-------constructeur sans parametre-------*/
template<typename T>
Array<T>::Array() : _array(NULL), _size(0){
}

/*-------constructeur avec parametre-------*/
template<typename T>
Array<T>::Array(unsigned int n) : _array(NULL), _size(n){
	if (n > 0)
		_array = new T[n];
}

template<typename T>
Array<T>::Array(Array const& src) : _array(NULL), _size(src._size){
	if (_size > 0)
		_array = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = src._array[i];
}

/*-------operateur-------------------------*/
template<typename T>
Array<T>&	Array<T>::operator=(Array const& other)
{
	if (this != &other)
	{
		if (_array == NULL)
			delete[] _array;
		if (_size > 0){
			_size = other._size;
			_array = new T[other._size];
		}
		for (unsigned int i = 0; i < _size; i++)
			this->_array[i] = other._array[i];
	}
	return *this;
}

template<typename T>
T&	Array<T>::operator[](unsigned int index){
	if (index >= _size)
		throw std::exception();
	return _array[index];
}

template<typename T>
const T&	Array<T>::operator[](unsigned int index) const{
	if (index >= _size)
		throw std::exception();
	return _array[index];
}

/*-------destructeur-----------------------*/
template<typename T>
Array<T>::~Array(){
	if (_array)
		delete[] _array;
}

/*-------fonction membre-------------------*/
template<typename T>
unsigned int Array<T>::size()const{
	return this->_size;
}

#endif
