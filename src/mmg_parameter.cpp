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

BodyParam::BodyParam()
{
	setParam(0.0, 0.0, 0.0, 0.0);
}

BodyParam::~BodyParam()
{
	;
}

int BodyParam::setParam(double length, double beam, double draft, double gm)
{
	_length = length;
	_beam = beam;
	_draft = draft;
	_gm = gm;

	return 1;	
}

double BodyParam::getLength(void)
{
	return _length;
}

double BodyParam::getBeam(void)
{
	return _beam;
}

double BodyParam::getDraft(void)
{
	return _draft;
}

double BodyParam::getGm(void)
{
	return _gm;
}



MassParam::MassParam()
{
	_mass = 0.0;
	_addmass = Eigen::Vector3d::Zero();
	_inertia = Eigen::Matrix3d::Zero();
	_addinertia = Eigen::Matrix3d::Zero();
	_cog_position = Eigen::Vector3d::Zero();
}

MassParam::~MassParam()
{
	;
}

int MassParam::setParam(double mass, Eigen::Vector3d addmass, Eigen::Matrix3d inertia, Eigen::Matrix3d addinertia, Eigen::Vector3d cog_position)
{
	_mass = mass;
	
	_addmass(0,0) = addmass(0,0);	
	_addmass(0,1) = addmass(0,1);
	_addmass(0,2) = addmass(0,2);

	_inertia(0,0) = inertia(0,0);	
	_inertia(0,1) = inertia(0,1);
	_inertia(0,2) = inertia(0,2);
	_inertia(1,0) = inertia(1,0);	
	_inertia(1,1) = inertia(1,1);
	_inertia(1,2) = inertia(1,2);
	_inertia(2,0) = inertia(2,0);	
	_inertia(2,1) = inertia(2,1);
	_inertia(2,2) = inertia(2,2);

	_addinertia(0,0) = addinertia(0,0);	
	_addinertia(0,1) = addinertia(0,1);
	_addinertia(0,2) = addinertia(0,2);
	_addinertia(1,0) = addinertia(1,0);	
	_addinertia(1,1) = addinertia(1,1);
	_addinertia(1,2) = addinertia(1,2);
	_addinertia(2,0) = addinertia(2,0);	
	_addinertia(2,1) = addinertia(2,1);
	_addinertia(2,2) = addinertia(2,2);

	_cog_position(0,0) = cog_position(0,0);	
	_cog_position(0,1) = cog_position(0,1);
	_cog_position(0,2) = cog_position(0,2);	

	return 1;
}

double MassParam::getMass(void)
{
	return _mass;
}

double MassParam::getAddMass_x(void){
	return _addmass(0,0);
}
	
double MassParam::getAddMass_y(void){
		return _addmass(0,1);
}

double MassParam::getAddMass_z(void){
		return _addmass(0,2);
}

double MassParam::getInertia_xx(void){
	return _inertia(0,0);
}

double MassParam::getInertia_xy(void){
	return _inertia(0,1);
}

double MassParam::getInertia_xz(void){
	return _inertia(0,2);
}

double MassParam::getInertia_yx(void){
	return _inertia(1,0);
}

double MassParam::getInertia_yy(void){
	return _inertia(1,1);
}

double MassParam::getInertia_yz(void){
	return _inertia(1,2);
}

double MassParam::getInertia_zx(void){
	return _inertia(2,0);
}

double MassParam::getInertia_zy(void){
		return _inertia(2,1);
}

double MassParam::getInertia_zz(void){
	return _inertia(2,2);
}

double MassParam::getAddInertia_xx(void){
	return _addinertia(0,0);
}

double MassParam::getAddInertia_xy(void){
	return _addinertia(0,1);
}

double MassParam::getAddInertia_xz(void){
	return _addinertia(0,2);
}

double MassParam::getAddInertia_yx(void){
	return _addinertia(1,0);
}

double MassParam::getAddInertia_yy(void){
	return _addinertia(1,1);
}

double MassParam::getAddInertia_yz(void){
	return _addinertia(1,2);
}

double MassParam::getAddInertia_zx(void){
	return _addinertia(2,0);
}

double MassParam::getAddInertia_zy(void){
		return _addinertia(2,1);
}

double MassParam::getAddInertia_zz(void){
	return _addinertia(2,2);
}

double MassParam::getCogPos_x(void){
	return _cog_position(0,0);
}

double MassParam::getCogPos_y(void){
	return _cog_position(0,1);
}

double MassParam::getCogPos_z(void){
	return _cog_position(0,2);
}		



PropellerParam::PropellerParam()
{
	_diameter = 0.0;	
	_pitch = 0.0;	
	_K_T = 0.0;	
	_force_point = Eigen::Vector3d::Zero();
}

PropellerParam::~PropellerParam()
{
	;
}

int PropellerParam::setParam(double diameter, double pitch, double K_T, Eigen::Vector3d force_point)
{
	_diameter = diameter;
	_pitch = pitch;
	_K_T = K_T;
	_force_point(0,0) = force_point(0,0);
	_force_point(0,1) = force_point(0,1);	
	_force_point(0,2) = force_point(0,2);

	return 1;
}

double PropellerParam::getDiameter(void)
{
	return _diameter;
}

double PropellerParam::getPitch(void)
{
	return _pitch;
}

double PropellerParam::getKT(void)
{
	return _K_T;
}

double PropellerParam::getForcePoint_x(void)
{
	return _force_point(0, 0);
}

double PropellerParam::getForcePoint_y(void)
{
	return _force_point(0, 1);
}

double PropellerParam::getForcePoint_z(void)
{
	return _force_point(0, 2);
}



RudderParam::RudderParam()
{
	_area = 0.0;
   	_f_alpha = 0.0;	
	_height = 0.0;
	_width = 0.0;
	_force_point = Eigen::Vector3d::Zero();
}

RudderParam::~RudderParam()
{
	;
}

int RudderParam::setParam(double area, double f_alpha, double height, double width, Eigen::Vector3d force_point)
{
	_area = area;
	_f_alpha = f_alpha;
    _height = height;
	_width = width;
	_force_point(0,0) = force_point(0,0);
	_force_point(0,1) = force_point(0,1);	
	_force_point(0,2) = force_point(0,2);
	return 1;
}
	
double RudderParam::getArea(void)
{
	return _area;
}
	
double RudderParam::getFAlpha(void)
{
	return _f_alpha;
}
	
double RudderParam::getHeight(void)
{
	return _height;
}

double RudderParam::getWidth(void)
{
	return _width;
}
	
double RudderParam::getForcePoint_x(void)
{
	return _force_point(0,0);
}

double RudderParam::getForcePoint_y(void)
{
	return _force_point(0,1);
}

double RudderParam::getForcePoint_z(void)
{
	return _force_point(0,2);
}		



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
	//Show Current target parameter
	std::cout
		<< "[HULL] Read parameter: "
		<< key
		<< "......"
		<< std::flush;
		
	auto result = _hull.try_emplace(key, value);
	if(true == result.second)
	{
		std::cout
			<< "Success! Set "
			<< key
			<< " as "
			<< result.second
			<< std::endl;
	}
	else
	{
		std::cout
			<< "ERROR! "
			<< key
			<< " is already defined as "
			<< result.second
			<< "! Confirm Parameter Lists!"
			<< std::endl;
	}

}

double MmgParam::set_mmgPropellerParam(std::string key, double value)
{
	//Show Current target parameter
	std::cout
		<< "[PROPELLER] Read parameter: "
		<< key
		<< "......"
		<< std::flush;
		
	auto result = _propeller.try_emplace(key, value);
	if(true == result.second)
	{
		std::cout
			<< "Success! Set "
			<< key
			<< " as "
			<< result.second
			<< std::endl;
	}
	else
	{
		std::cout
			<< "ERROR! "
			<< key
			<< " is already defined as "
			<< result.second
			<< "! Confirm Parameter Lists!"
			<< std::endl;
	}

}

double MmgParam::set_mmgRudderParam(std::string key, double value)
{
	//Show Current target parameter
	std::cout
		<< "[RUDDER] Read parameter: "
		<< key
		<< "......"
		<< std::flush;
		
	auto result = _rudder.try_emplace(key, value);
	if(true == result.second)
	{
		std::cout
			<< "Success! Set "
			<< key
			<< " as "
			<< result.second
			<< std::endl;
	}
	else
	{
		std::cout
			<< "ERROR! "
			<< key
			<< " is already defined as "
			<< result.second
			<< "! Confirm Parameter Lists!"
			<< std::endl;
	}

}	
	
