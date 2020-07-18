/*-----------------------------------------------------------------------------
MMG Model Parameter Structure Definition


Author: Suisei WADA (D1)
        @Faculty of Naval Architecture and Ocean Engineering, Osaka University
Date:   10th May, 2020
-----------------------------------------------------------------------------*/
#ifndef MMG_PARAMETER_HPP
#define MMG_PARAMETER_HPP

//Include 
#include <eigen/Eigen/Core>
#include <unordered_map>
#include <string>


/*------------------------------------------------
MMG Ship Unique Parameter
------------------------------------------------*/
struct HullParam
{
	double length; //L [m]
	double beam; //B [m]
	double draft; //d [m]
	double gm; //GM [m]

	HullParam():
		length(0.0),
		beam(0.0),
		draft(0.0),
		gm(0.0)
	{
		;
	}
	
	
};

struct MassParam
{
	double mass; //m [kg]
	Eigen::Vector3d addmass; //(m_x, m_y, m_z) [kg]
	Eigen::Matrix3d inertia; //(Ixx, Ixy, Ixz / Iyx, Iyy, Iyz, / Izx, Izy, Izz) [kg*m^2]
	Eigen::Matrix3d addinertia; //(Jxx, Jxy, Jxz / Jyx, Jyy, Jyz, / Jzx, Jzy, Jzz) [kg*m^2]
	Eigen::Vector3d cog_position; //x_G, y_G, z_G (Midship origin, Coordinate: On Ship)

	MassParam():
		mass(0.0)
	{
		addmass = Eigen::Vector3d::Zero();
		inertia = Eigen::Matrix3d::Zero();
		addinertia = Eigen::Matrix3d::Zero();
		cog_position = Eigen::Vector3d::Zero();
	}		
	
};

struct PropellerParam
{
	//T = ρ * n_P^2 * D_P^4 * K_T
	double diameter; //D_P
	double pitch; //P
	double K_T; //Coef. of Propeller Specification

	//Point of propeller force(Midship origin, Coordinate: On ship)
	Eigen::Vector3d force_point;

	PropellerParam():
		diameter(0.0),
		pitch(0.0),
		K_T(0.0)
	{
		force_point = Eigen::Vector3d::Zero();
	}
		
};

	

struct RudderParam
{
	//F_N = 1/2 * ρ * A_R * U_R^2 * f_α * sin(α_R)
	double area; //A_R : Area of the rudder
	double f_alpha; //Rudder Pressure Gradient Coef.
	double height; //Hieght of Rudder Boad
	double width; //Width of Rudder Boad

	//Point of rudder force(Midship origin, Coordinate: On ship)
	Eigen::Vector3d force_point;

	RudderParam():
		area(0.0),
		f_alpha(0.0),
		height(0.0),
		width(0.0)
	{
		force_point = Eigen::Vector3d::Zero();
	}
	
};



/*------------------------------------------------
MMG Hydrodynamic Force(Hull) Parameter
------------------------------------------------*/
class MmgParam
{
	public:
	//Constractor, Destructor
	MmgParam();
	~MmgParam();

	//Accessor
	double get_mmgHullParam(std::string key);
	double get_mmgPropellerParam(std::string key);
	double get_mmgRudderParam(std::string key);
	
	double set_mmgHullParam(std::string key, double value);
	double set_mmgPropellerParam(std::string key, double value);
	double set_mmgRudderParam(std::string key, double value);

	
	private:
	std::unordered_map<std::string, double> _hull;
	std::unordered_map<std::string, double> _propeller;
	std::unordered_map<std::string, double> _rudder;
	
};


struct FlagParam
{
	bool isUpdated;
	double value;

	FlagParam():
		isUpdated(false),
		value(0.0)
	{
		;
	}
	
	
};

	

#endif
