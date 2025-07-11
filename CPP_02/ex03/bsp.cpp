/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 09:47:07 by dle-fur           #+#    #+#             */
/*   Updated: 2025/07/11 15:18:02 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

/*
But : return true si le point est à l'interieur du triangle, false dans le cas contraire
1. recuperer les valeurs en float de chaque coordonnees
2. calculer les vecteurs de cotes
3. calculer les vecteurs vers le point a tester
4. faire trois produit vectoriel
- cross = produit vectoriel
- operation qui prend deux vecteurs et en retourne un troisieme vecteur 
  perpendiculaire aux deux premiers
5. si les trois variables return la meme valeur, return true
*/

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float	xA = a.getX().toFloat();
	float	yA = a.getY().toFloat();
	float	xB = b.getX().toFloat();
	float	yB = b.getY().toFloat();
	float	xC = c.getX().toFloat();
	float	yC = c.getY().toFloat();
	float	xP = point.getX().toFloat();
	float	yP = point.getY().toFloat();

	float	xAB = xB - xA;
	float	yAB = yB - yA;
	float	xBC = xC - xB;
	float	yBC = yC - yB;
	float	xCA = xA - xC;
	float	yCA = yA - yC;

	float	xAP = xP - xA;
	float	yAP = yP - yA;
	float	xBP = xP - xB;
	float	yBP = yP - yB;
	float	xCP = xP - xC;
	float	yCP = yP - yC;

	float	crossAB_AP = xAB * yAP - yAB * xAP;
	float	crossBC_BP = xBC * yBP - yBC * xBP;
	float	crossCA_CP = xCA * yCP - yCA * xCP;

	if ((crossAB_AP >= 0 && crossBC_BP >= 0 && crossCA_CP >= 0)
	|| (crossAB_AP <= 0 && crossBC_BP <= 0 && crossCA_CP <= 0))
		return true;
	return false;
}
