/*-----------------------------------------------------------------------------
MMG Parameter Structures and Classes


Author: Suisei WADA (D1)
        @Faculty of Naval Architecture and Ocean Engineering, Osaka University
Date:   21th May, 2020
-----------------------------------------------------------------------------*/
#include "mmg_parameter.hpp"
#include <iostream>
#include <exception>

void MmgParam::ShallowWaterModel()
{
	;
}

void MmgParam::ShallowWaterModel~()
{
	;
}

double Mmgparam::get_mmgHullParam(std::string param_key)
{
	double value;
	
	try
	{
		value = _hull.at(param_key);
		return value;
	}
	catch(std::out_of_range&)
	{
		std::cout
			<< "[ERROR] -"
			<< param_key
			<< "- is not defined as Hull Force MMG Parameter. Please confirm it!"
			<< endl;
		std::terminate();
	}
}

double MmgParam::get_mmgPropellerParam(std::string param_key)
{
	double value;
	
	try
	{
		value = _propeller.at(param_key);
		return value;
	}
	catch(std::out_of_range&)
	{
		std::cout
			<< "[ERROR] -"
			<< param_key
			<< "- is not defined as Propeller Force MMG Parameter. Please confirm it!"
			<< endl;
		std::terminate();
	}
}	

double MmgParam::get_mmgRudderParam(std::string param_key)
{
	double value;
	
	try
	{
		value = _rudder.at(param_key);
		return value;
	}
	catch(std::out_of_range&)
	{
		std::cout
			<< "[ERROR] -"
			<< param_key
			<< "- is not defined as Rudder Force MMG Parameter. Please confirm it!"
			<< endl;
		std::terminate();
	}
}
