/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 13:45:12 by david             #+#    #+#             */
/*   Updated: 2025/10/25 17:26:46 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void    testSubject()
{
    std::cout << "TEST SUJET : " << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << std::endl;
    return;
}

void    testComplete()
{
    std::cout << "TEST COMPLET : " << std::endl;
    try
    {
        Span sp = Span(10);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::vector<int>    more = {100, 200, 300, 400, 500};
        sp.addNumber(more.begin(), more.end());
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << "Erreur : " << e.what() << std::endl;
    }
    std::cout << std::endl;
    return;
}








void    testBig()
{
    std::cout << "TEST 10000 : " << std::endl;
    try
    {
        Span sp = Span(10000);

        std::vector<int>    array;

        for (size_t i = 0; i < 10000; i++)
        {
            array.push_back(i);
        }
        sp.addNumber(array.begin(), array.end());
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;

        std::cout << std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << "Erreur : " << e.what() << std::endl;
    }
    std::cout << std::endl;
    return;
}







void    testErrorFull()
{
    std::cout << "TEST ERROR FULL : " << std::endl;
    try
    {
        Span sp = Span(3);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(20);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << "Erreur : " << e.what() << std::endl;
    }
    std::cout << std::endl;
    return;
}

void    testErrorStorage()
{
    std::cout << "TEST ERROR STORAGE : " << std::endl;
    try
    {
        Span sp = Span(1);
        sp.addNumber(6);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << "Erreur : " << e.what() << std::endl;
    }
    std::cout << std::endl;
    return;
}


int	main()
{
    system("clear");

    testSubject();
    testComplete();

    

    testBig();


    testErrorFull();
    testErrorStorage();

	return 0;

}
