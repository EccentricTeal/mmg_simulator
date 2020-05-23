/*-----------------------------------------------------------------------------
Ship Numerical Model Class


Author: Suisei WADA (D1)
        @Faculty of Naval Architecture and Ocean Engineering, Osaka University
Date:   10th May, 2020
-----------------------------------------------------------------------------*/

#ifndef MMG_MODELS_HPP
#define MMG_MODELS_HPP

//Include Library Headers
#include "physical_const.hpp"
#include "mmg_parameter.hpp"
#include "mmg_variable.hpp"

//Include Tools
#include <vector>
#include <cmath>


//  1:MMG Model on shallow water:
//
//  [Base Article Information]
//  (Title:   "Maneuvering Simulations of a Ship in Shallow Water)
//  (Authors: Takanori SUZUKI, Hironori YASUKAWA et al. of Hiroshima Univ.)
//  (Journal: JASNAOE Spring Conference 2019 Proceedings Vol.28 pp.491-496)
class ShallowWaterModel
{
	
	public:
	//Initialize and Finalize Functions
	void ShallowWaterModel();	//Constractor
	void ShallowWaterModel~();  //Destructor


	private:
	//Physical Constants
	PhysicalConst _phyconst;
	
	//Ship Variables
	std::vector<PropellerStatus> _propeller;
	std::vector<RudderStatus> _rudder;
	ShipPosition3D _pos;
	ShipVelocity3D _vel;
	ShipAcceralator3D _acc;
	
	//Ship Parameters
	HullParam _hullparam;
	MassParam _massparam;
	PropellerParam _propellerparam;
	RudderParam _rudderparam;
	MmgParam _mmgparam;
	

	//----Local Calculator
	double _calcX_H(void); //Calculate Surge force correspondings to Hull
	double _calcY_H(void); //Calculate Sway force correspondings to Hull
	double _calcN_H(void); //Calculate Yaw moment correspondings to Hull
	double _calcX_P(void); //Calculate Surge force correspondings to Propeller
	double _calcX_R(void); //Calculate Surge force correspondings to Rudder
	double _calcY_R(void); //Calculate Sway force correspondings to Rudder
	double _calcN_R(void); //Calculate Yaw moment correspondings to Rudder
	double _calcK(void); //Calculate Roll moment.
	
}

#endif
