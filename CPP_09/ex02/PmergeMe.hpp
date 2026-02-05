/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 16:04:47 by david             #+#    #+#             */
/*   Updated: 2026/02/01 14:27:21 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <climits>
#include <algorithm>
#include <ctime>
#include <utility>
#include <deque>
#include <vector>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& src);
		PmergeMe&	operator=(const PmergeMe& other);
		~PmergeMe();

		int					parse(int argc, char **argv);
		std::vector<int>	fordJohnsonVector(std::vector<int> input);
		void				run();

	private:
		std::deque<int>		_myDeque;
		std::vector<int>	_myVector;
};

#endif
