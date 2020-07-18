/*-----------------------------------------------------------------------------
MMG Parameter Structures and Classes


Author: Suisei WADA (D1)
        @Faculty of Naval Architecture and Ocean Engineering, Osaka University
Date:   21th May, 2020
-----------------------------------------------------------------------------*/
#include "mmg_parameter.hpp"
#include <iostream>
#include <exception>
#include <utility>

MmgParam::MmgParam()
{
	_hull.clear();
	_propeller.clear();
	_rudder.clear();	
}

MmgParam::~MmgParam()
{
	;
}

double MmgParam::get_mmgHullParam(std::string key)
{
	double value;
	
	try
	{
		value = _hull.at(key);
		return value;
	}
	catch(std::out_of_range&)
	{
		std::cout
			<< "[ERROR] -"
			<< key
			<< "- is not defined as Hull Force MMG Parameter. Please confirm it!"
			<< std::endl;
		std::terminate();
	}
}

double MmgParam::get_mmgPropellerParam(std::string key)
{
	double value;
	
	try
	{
		value = _propeller.at(key);
		return value;
	}
	catch(std::out_of_range&)
	{
		std::cout
			<< "[ERROR] -"
			<< key
			<< "- is not defined as Propeller Force MMG Parameter. Please confirm it!"
			<< std::endl;
		std::terminate();
	}
}	

double MmgParam::get_mmgRudderParam(std::string key)
{
	double value;
	
	try
	{
		value = _rudder.at(key);
		return value;
	}
	catch(std::out_of_range&)
	{
		std::cout
			<< "[ERROR] -"
			<< key
			<< "- is not defined as Rudder Force MMG Parameter. Please confirm it!"
			<< std::endl;
		std::terminate();
	}
}


double MmgParam::set_mmgHullParam(std::string key, double value)
{
	//Define Local Variable
	std::pair<std::string, double> result;

	//Show Current target parameter
	std::cout
		<< "[HULL] Read parameter: "
		<< key
		<< "......"
		<< std::flush;
		
	result = _hull.try_emplace(key, value);
	if(true == result.second)
	{
		std::cout
			<< "Success! Set "
			<< result.first
			<< " as "
			<< result.second
			<< std::endl;
	}
	else
	{
		std::cout
			<< "ERROR! "
			<< result.first
			<< " is already defined as "
			<< result.second
			<< "! Confirm Parameter Lists!"
			<< std::endl;
	}

}

double MmgParam::set_mmgPropellerParam(std::string key, double value)
{
	//Define Local Variable
	std::pair<std::string, double> result;

	//Show Current target parameter
	std::cout
		<< "[PROPELLER] Read parameter: "
		<< key
		<< "......"
		<< std::flush;
		
	result = _propeller.try_emplace(key, value);
	if(true == result.second)
	{
		std::cout
			<< "Success! Set "
			<< result.first
			<< " as "
			<< result.second
			<< std::endl;
	}
	else
	{
		std::cout
			<< "ERROR! "
			<< result.first
			<< " is already defined as "
			<< result.second
			<< "! Confirm Parameter Lists!"
			<< std::endl;
	}

}

double MmgParam::set_mmgRudderParam(std::string key, double value)
{
	//Define Local Variable
	std::pair<std::string, double> result;

	//Show Current target parameter
	std::cout
		<< "[RUDDER] Read parameter: "
		<< key
		<< "......"
		<< std::flush;
		
	result = _rudder.try_emplace(key, value);
	if(true == result.second)
	{
		std::cout
			<< "Success! Set "
			<< result.first
			<< " as "
			<< result.second
			<< std::endl;
	}
	else
	{
		std::cout
			<< "ERROR! "
			<< result.first
			<< " is already defined as "
			<< result.second
			<< "! Confirm Parameter Lists!"
			<< std::endl;
	}

}	
	
