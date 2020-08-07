/*-----------------------------------------------------------------------------
MMG Model Variable Structure Definition


Author: Suisei WADA (D1)
        @Faculty of Naval Architecture and Ocean Engineering, Osaka University
Date:   10th May, 2020
-----------------------------------------------------------------------------*/
#ifndef MMG_VARIABLE_HPP
#define MMG_VARIABLE_HPP

//Include 
#include <eigen/Eigen/Core>

/*------------------------------------------------
MMG Variables
------------------------------------------------*/
struct PropellerStatus
{
	double rotate; // n_P [rps]

	PropellerStatus():
		rotate(0.0)
	{
		;
	}
		
};

struct RudderStatus
{
	double angle; //δ[rad]
	double velocity; //δdot [rad]

	RudderStatus():
		angle(0.0),
		velocity(0.0)
	{
		;
	}
			
};

struct ShipPosition2D
{
	Eigen::Vector2d linear; //x, y
    double yaw; //Ψ(Yaw)

	ShipPosition2D():
		yaw(0.0)
	{
		linear = Eigen::Vector2d::Zero();
	}	
	
};

struct ShipPosition3D
{
	Eigen::Vector3d linear; //x, y, z
	Eigen::Vector3d angular; //θ(Pitch), φ(Roll), Ψ(Yaw)

	ShipPosition3D()
	{
		linear = Eigen::Vector3d::Zero();
		angular = Eigen::Vector3d::Zero();
	}	
	
};

struct ShipVelocity2D
{
	Eigen::Vector2d linear; //u, v
	double yawvel; //r (=Ψdot)

	ShipVelocity2D():
		yawvel(0.0)
	{
		linear = Eigen::Vector2d::Zero();
	}	
	
};

struct ShipVelocity3D
{
	Eigen::Vector3d linear; //u, v, w
	Eigen::Vector3d angular; //θdot, φdot, r (=Ψdot)

	ShipVelocity3D()
	{
		linear = Eigen::Vector3d::Zero();
		angular = Eigen::Vector3d::Zero();
	}	
	
};

struct ShipAcceralator2D
{
	Eigen::Vector2d linear; //udot, vdot
	double yawacc; //rdot(=Ψdotdot)

	ShipAcceralator2D():
		yawacc(0.0)
	{
		linear = Eigen::Vector2d::Zero();
	}	
	
};

struct ShipAcceralator3D
{
	Eigen::Vector3d linear; //udot, vdot, wdot
	Eigen::Vector3d angular; //θdotdot, φdotdot, rdot(=Ψdotdot)

	ShipAcceralator3D()
	{
		linear = Eigen::Vector3d::Zero();
		angular = Eigen::Vector3d::Zero();
	}
		
};



#endif
