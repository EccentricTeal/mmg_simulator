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


/*------------------------------------------------
MMG Hydrodynamic Force(Hull) Parameter
------------------------------------------------*/
typedef struct MmgHullForceAheadResistanceParam2D //Hughes Equation Based
{
	double D_Cf; //ΔCf:Coef. of roughness correction
	double Cr; //Cr:Coef. of surplus resitance
	double S; //S: Hull wetted surface area
	double Re; //Re: Reynolds number

}MmgHullForceAheadResistanceParam2D;

typedef struct MmgHullForceForwardResistanceParam3D //Hughes Equation Based
{
	double Nabla; //∇:Volume of displacement
	double DeltaCf; //ΔCf:Coef. of Roughness Correction
	double K; //K: Coef. of Hull Form Effect
	double S; //S: Hull wetted surface area
	double Cw; //Cw: Coef. of Wave Generate Resitance
	double Re; //Re: Reynolds Number

}MmgHullForceForwardResistanceParam3D;



typedef struct MmgHullForceHydrodynamicDerivative
{
	//For any MmgHullForceHydrodynamicDerivative(Single)
	double val;
	
}MmgHullForceHydrodynamicDerivative;


typedef struct MmgHullForceHydrodynamicDerivatives1D
{
	//(e.g.) X_v, X_r
	double i;	
	double j;
	
}MmgHullForceHydrodynamicDerivatives1D;


typedef struct MmgHullForceHydrodynamicDerivatives2D
{
	//(e.g.) X_vv, X_vr, X_rr
	double ii;
	double ij;
	double jj;
	
}MmgHullForceHydrodynamicDerivatives2D;


typedef struct MmgHullForceHydrodynamicDerivatives3D
{
	//(e.g.) X_vvv, X_vvr, X_vrr, X_rrr
	double iii;
	double iij;
	double ijj;
	double jjj;
	
}MmgHullForceHydrodynamicDerivatives3D;


typedef struct MmgHullForceHydrodynamicDerivatives4D
{
	//(e.g.) X_vvvv, X_vvvr, X_vvrr, X_vrrr, X_rrrr
	double iiii;
	double iiij;
	double iijj;
	double ijjj;
	double jjjj;
	
}MmgHullForceHydrodynamicDerivatives4D;


typedef struct MmgHullForceHydrodynamicDerivatives5D
{
	//(e.g.) X_vvvvv, X_vvvvr, X_vvvrr, X_vvrrr, X_vrrrr, X_rrrr
	double iiiii;
	double iiiij;
	double iiijj;
	double iijjj;
	double ijjjj;
	double jjjjj;
	
}MmgHullForceHydrodynamicDerivatives5D;

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
