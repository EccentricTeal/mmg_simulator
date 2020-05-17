/*-----------------------------------------------------------------------------
MMG Model Variable Structure Definition


Author: Suisei WADA (D1)
        @Faculty of Naval Architecture and Ocean Engineering, Osaka University
Date:   10th May, 2020
-----------------------------------------------------------------------------*/
#ifndef MMG_VARIABLE_HPP
#define MMG_VARIABLE_HPP

//Include 
#include <Eigen/Core>

/*------------------------------------------------
MMG Variables
------------------------------------------------*/
typedef struct PropellerStatus
{
	double rotate; // n_P [rps]
	
}PropellerStatus;

typedef struct RudderStatus
{
	double angle; //δ[rad]
	double velocity; //δdot [rad]
	
}RudderStatus;

typedef struct ShipPosition2D
{
	Eigen::Vector2d linear; //x, y
    double yaw; //Ψ(Yaw)
	
}ShipPosition2D;

typedef struct ShipPosition3D
{
	Eigen::Vector3d linear; //x, y, z
	Eigen::Vector3d angular; //θ(Pitch), φ(Roll), Ψ(Yaw)
	
}ShipPosition3D;

typedef struct ShipVelocity2D
{
	Eigen::Vector2d linear; //u, v
	double yawvel; //r (=Ψdot)
	
}ShipVelocity2D;

typedef struct ShipVelocity3D
{
	Eigen::Vector3d linear; //u, v, w
	Eigen::Vector3d angular; //θdot, φdot, r (=Ψdot)
	
}ShipVelocity3D;

typedef struct ShipAcceralator2D
{
	Eigen::Vector2d linear; //udot, vdot
	double yawacc; //rdot(=Ψdotdot)
	
}ShipAcceralator3D;

typedef struct ShipAcceralator3D
{
	Eigen::Vector3d linear; //udot, vdot, wdot
	Eigen::Vector3d angular; //θdotdot, φdotdot, rdot(=Ψdotdot)
	
}ShipAcceralator3D;


#endif
