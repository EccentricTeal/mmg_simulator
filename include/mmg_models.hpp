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


private:
	//Physical Constants
	PhysicalConst _phyconst;
	
	//Ship Variables
	std::vector<PropellerStatus> _propeller;
	std::vector<RudderStatus> _rudder;
	ShipPosition3D _pos;
	ShipVelocity3D _vel;
	ShipAcceralator3D _acc;
	
	//Ship Parameter
	ShipParam _shipinfo;
	PropellerParam _propinfo;
	RudderParam _rudderinfo;

	//MMG Parameter
	//----Hull
	//---X
	MmgHullForceForwardResistanceParam3D _mmgResistFore;
	MmgHullForceHydrodynamicDerivatives2D _mmgHydroDeriv_Xvr2; //Xvv, Xvr, Xrr
	MmgHullForceHydrodynamicDerivative _mmgHydroDeriv_Xv4; //Xvvvv
	MmgHullForceHydrodynamicDerivative _mmgHydroDeriv_Xvp2; //Xvφ
	MmgHullForceHydrodynamicDerivatives2D _mmgHydroDeriv_Xrp2; //Xrr, Xrφ, Xφφ
	//---Y	
	MmgHullForceHydrodynamicDerivatives1D _mmgHydroDeriv_Yvr1; //Yv, Yr
	MmgHullForceHydrodynamicDerivatives3D _mmgHydroDeriv_Yvr3; //Yvvv, Yvvr, Yvrr, Yrrr
	MmgHullForceHydrodynamicDerivative _mmgHydroDeriv_Yp1; //Yφ
	MmgHullForceHydrodynamicDerivatives3D _mmgHydroDeriv_Yvp3; //Yvvv, Yvvφ, Yvφφ, Yφφφ
	MmgHullForceHydrodynamicDerivatives3D _mmgHydroDeriv_Yrp3; //Yrrr, Yrrφ, Yrφφ, Yφφφ
	//---N
	MmgHullForceHydrodynamicDerivatives1D _mmgHydroDeriv_Nvr1; //Nv, Nr
	MmgHullForceHydrodynamicDerivatives3D _mmgHydroDeriv_Nvr3; //Nvvv, Nvvr, Nvrr, Nrrr
	MmgHullForceHydrodynamicDerivative _mmgHydroDeriv_Np1; //Nφ
	MmgHullForceHydrodynamicDerivatives3D _mmgHydroDeriv_Nvp3; //Nvvv, Nvvφ, Nvφφ, Nφφφ
	MmgHullForceHydrodynamicDerivatives3D _mmgHydroDeriv_Nrp3; //Nrrr, Nrrφ, Nrφφ, Nφφφ
	
	double _mmgHullRollMoment_KH; //K_H
	double _mmgRollDumpCoef_a; //a
	double _mmgRollDumpCoef_b; //b

	//----Propeller
	double _mmgPropeller_tP; //Thrust Deduction
	double _mmgPropellerSpec_k[3]; //Standalone Propeller spec coef. k0, k1, k2
	double _mmgPropeller_wP0; //Wake Fraction

	//----Rudder
	double _mmgRudder_tR; //Rudder Wake Coef.
	double _mmgRudder_aR; //Rudder Wake Coef.
	double _mmgRudder_xR; //Rudder Wake Coef.
	double _mmgRudder_ganmaR; //Rudder Flow Straightening Coef.
	double _mmgRudder_K; //Constants from experiment

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
