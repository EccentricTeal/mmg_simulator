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
class BodyParam
{
	public:
	BodyParam();
	~BodyParam();	
	int setParam(double length, double beam, double draft, double gm);
	double getLength(void);
	double getBeam(void);
	double getDraft(void);
	double getGm(void);

	private:
	double _length; //L [m]
	double _beam; //B [m]
	double _draft; //d [m]
	double _gm; //GM [m]
	
};


class MassParam
{
	public:
	MassParam();
	~MassParam();
	int setParam(double mass, Eigen::Vector3d addmass, Eigen::Matrix3d inertia, Eigen::Matrix3d addinertia, Eigen::Vector3d cog_position);	
	double getMass(void);
	double getAddMass_x(void);
	double getAddMass_y(void);
	double getAddMass_z(void);
	double getInertia_xx(void);
	double getInertia_xy(void);
	double getInertia_xz(void);
	double getInertia_yx(void);
	double getInertia_yy(void);
	double getInertia_yz(void);
	double getInertia_zx(void);
	double getInertia_zy(void);
	double getInertia_zz(void);
	double getAddInertia_xx(void);
	double getAddInertia_xy(void);
	double getAddInertia_xz(void);
	double getAddInertia_yx(void);
	double getAddInertia_yy(void);
	double getAddInertia_yz(void);
	double getAddInertia_zx(void);
	double getAddInertia_zy(void);
	double getAddInertia_zz(void);
	double getCogPos_x(void);
	double getCogPos_y(void);
	double getCogPos_z(void);
	
	private:
	double _mass; //m [kg]
	Eigen::Vector3d _addmass; //(m_x, m_y, m_z) [kg]
	Eigen::Matrix3d _inertia; //(Ixx, Ixy, Ixz / Iyx, Iyy, Iyz, / Izx, Izy, Izz) [kg*m^2]
	Eigen::Matrix3d _addinertia; //(Jxx, Jxy, Jxz / Jyx, Jyy, Jyz, / Jzx, Jzy, Jzz) [kg*m^2]
	Eigen::Vector3d _cog_position; //x_G, y_G, z_G (Midship origin, Coordinate: On Ship)
	
};



class PropellerParam
{	//T = ρ * n_P^2 * D_P^4 * K_T
	
	public:
	PropellerParam();
	~PropellerParam();
	int setParam(double diameter, double pitch, double K_T, Eigen::Vector3d force_point);
	double getDiameter(void);
	double getPitch(void);
	double getKT(void);
	double getForcePoint_x(void);
	double getForcePoint_y(void);
	double getForcePoint_z(void);	
	
	private:
	double _diameter; //D_P
	double _pitch; //P
	double _K_T; //Coef. of Propeller Specification
	Eigen::Vector3d _force_point;	//Point of propeller force(Midship origin, Coordinate: On ship)
		
};

	

class RudderParam
{//F_N = 1/2 * ρ * A_R * U_R^2 * f_α * sin(α_R)

	public:
	RudderParam();
	~RudderParam();
	int setParam(double area, double f_alpha, double height, double width, Eigen::Vector3d force_point);
	double getArea(void);
	double getFAlpha(void);
	double getHeight(void);
	double getWidth(void);
	double getForcePoint_x(void);
	double getForcePoint_y(void);
	double getForcePoint_z(void);
	
	private:
	double _area; //A_R : Area of the rudder
	double _f_alpha; //Rudder Pressure Gradient Coef.
	double _height; //Hieght of Rudder Boad
	double _width; //Width of Rudder Boad
	Eigen::Vector3d _force_point; //Point of rudder force(Midship origin, Coordinate: On ship)
	
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
