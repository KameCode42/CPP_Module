/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 11:33:21 by david             #+#    #+#             */
/*   Updated: 2026/02/06 11:33:49 by david            ###   ########.fr       */
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
