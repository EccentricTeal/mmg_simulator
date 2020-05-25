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

	//Accessor
	void update();	


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

	//Force and Moment
	FlagParam _X;
	FlagParam _Y;
	FlagParam _N;	
	FlagParam _K;

	//Temporary Variables
	//-- first: isUpdated flag,  second: value--
	FlagParam _tempU;
	FlagParam _tempF_N;
	FlagParam _tempX_H;
	FlagParam _tempY_H;
	FlagParam _tempN_H;
	FlagParam _tempX_P;
	FlagParam _tempX_R;
	FlagParam _tempY_R;
	FlagParam _tempN_R;
	
	//Local Calculator
	void _calcU(void); //Calculate U temporarily
	void _calcF_N(void); //Calculate F_N temporarily
	void _calcX_H(void); //Calculate Surge force correspondings to Hull
	void _calcY_H(void); //Calculate Sway force correspondings to Hull
	void _calcN_H(void); //Calculate Yaw moment correspondings to Hull
	void _calcX_P(void); //Calculate Surge force correspondings to Propeller
	void _calcX_R(void); //Calculate Surge force correspondings to Rudder
	void _calcY_R(void); //Calculate Sway force correspondings to Rudder
	void _calcN_R(void); //Calculate Yaw moment correspondings to Rudder

	void _updateX(void); //Update Surge Force
	void _updateY(void); //Update Sway Force
	void _updateN(void); //Update Yaw Moment
	void _updateK(void); //Update Roll Moment

	void _resetUpdateFalgs(void);
	
	
}

#endif
