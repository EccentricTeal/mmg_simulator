/*-----------------------------------------------------------------------------
MMG Model Parameter Structure Definition


Author: Suisei WADA (D1)
        @Faculty of Naval Architecture and Ocean Engineering, Osaka University
Date:   10th May, 2020
-----------------------------------------------------------------------------*/
#ifndef MMG_PARAMETER_HPP
#define MMG_PARAMETER_HPP

//Include 
#include <Eigen/Core>
#include <unordered_map>
#include <string>


/*------------------------------------------------
MMG Hydrodynamic Force(Hull) Parameter
------------------------------------------------*/

class MmgParam
{
	public:
	//Constractor, Destructor
	void MmgParam();
	void MmgParam~();

	//Accessor
	double get_mmgHullParam(std::string param_key);
	double get_mmgPropellerParam(std::string param_key);
	double get_mmgRudderParam(std::string param_key);

	
	private;
	std::unordered_map<std::string, double> _hull;
	std::unordered_map<std::string, double> _propeller;
	std::unordered_map<std::string, double> _rudder;
	
};



/*------------------------------------------------
MMG Ship Unique Parameter
------------------------------------------------*/
typedef struct ShipParam
{	
	//Scale Parameter
	double length; //L [m]
	double beam; //B [m]
	double draft; //d [m]
	double gm; //GM [m]
	Eigen::Vector3d position_rudderforce; //point of rudder force(Midship origin, Coordinate: On ship)
	Eigen::Vector3d position_cog; //x_G, y_G, z_G (Midship origin, Coordinate: On Ship)
	

	//Inertia Parameter
	double mass; //m [kg]
	Eigen::Vector3d addmass; //(m_x, m_y, m_z) [kg]
	Eigen::Matrix3d inertia; //(Ixx, Ixy, Ixz / Iyx, Iyy, Iyz, / Izx, Izy, Izz) [kg*m^2]
	Eigen::Matrix3d addinertia; //(Jxx, Jxy, Jxz / Jyx, Jyy, Jyz, / Jzx, Jzy, Jzz) [kg*m^2]

}ShipParam;

typedef struct PropellerParam
{
	//T = ρ * n_P^2 * D_P^4 * K_T
	
	//Scale Parameter
	Eigen::Vector3d pos;
	
	//Propeller Parameter
	double diameter; //D_P
	double K_T; //Coef. of Propeller Specification
	
}PropellerParam;

typedef struct RudderParam
{
	//F_N = 1/2 * ρ * A_R * U_R^2 * f_α * sin(α_R)
	double area; //A_R : Area of the rudder
	double f_alpha; //Rudder Pressure Gradient Coef.
	double height;
	double width;
	
}RudderParam;

#endif
