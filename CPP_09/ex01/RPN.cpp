/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 12:50:15 by david             #+#    #+#             */
/*   Updated: 2025/11/27 17:27:25 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/*=== Constructeur ===*/

RPN::RPN() {}

RPN::RPN(RPN const& src) {
	(void)src;
}

RPN&	RPN::operator=(RPN const& other) {
	(void)other;
	return *this;
}

RPN::~RPN() {}

/*==================================================================================*/

/*=== Fonction membre ===*/

int	RPN::evaluate(std::string const& expression)
{
	std::stack<int> stack;
	int	opCount = 0;

	for (int i = 0; i < expression.size(); i++)
	{
		if (expression[i] == ' ')
			continue;
		
		if (expression[i] >= '0' && expression[i] <= '9') {
			if (std::isdigit(expression[i + 1]))
				throw ErrorExpression();
			int expr = expression[i] - '0';
			stack.push(expr);
		}
		else if (expression[i] == '+'
				|| expression[i] == '-'
				|| expression[i] == '*'
				|| expression[i] == '/')
			{
			opCount++;
			if (stack.size() < 2)
				throw ErrorExpression();

			int b = stack.top();
			stack.pop();

			int a = stack.top();
			stack.pop();

			int result;
			if (expression[i] == '+')
				result = a + b;
			else if (expression[i] == '-')
				result = a - b;
			else if (expression[i] == '*')
				result = a * b;
			else if (expression[i] == '/') {
				if (b == 0)
					throw ErrorExpression();
				result = a / b;
			}
			stack.push(result);
		}
		else
			throw ErrorExpression();
	}

	if (stack.size() != 1 || opCount == 0)
		throw ErrorExpression();

	return stack.top();
}

/*==================================================================================*/

/*=== Gestion erreur ===*/

const char* RPN::ErrorExpression::what() const throw() {
	return ("Erreur : operation impossible");
}
