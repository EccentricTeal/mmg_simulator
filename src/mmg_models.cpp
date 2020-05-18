/*-----------------------------------------------------------------------------
Ship Numerical Model Class


Author: Suisei WADA (D1)
        @Faculty of Naval Architecture and Ocean Engineering, Osaka University
Date:   10th May, 2020
-----------------------------------------------------------------------------*/
#include "mmg_models.hpp"

void ShallowWaterModel::ShallowWaterModel()
{
	;
}

void ShallowWaterModel::ShallowWaterModel~()
{
	;
}

double ShallowWaterModel::_calX_H(void)
{
	double X_H;
	double X_H_dash = 0.0;
	
	double squareU = std::pow(_vel.linear.x(),2) + std::pow(_vel.linear.y(),2);
	double v = _vel.linear.y() / sqrt( squareU );
	double r = _vel.angular.z() * _shipinfo.length / std::sqrt( squareU );
	double phi = _pos.angular.y();

	X_H_dash =
		-_mmgResistFore
		+( _mmgHydroDeriv_Xvr2.ii * v * v )
		+( _mmgHydroDeriv_Xvr2.ij * v * r )
		+( _mmgHydroDeriv_Xvr2.jj * r * r )
		+( _mmgHydroDeriv_Xv4.val * std::pow(v, 4) )
		+( _mmgHyrdoDeriv_Xvp2.val * v * phi )
		+( _mmgHydroDeriv_Xrp2.ij * r * phi )
		+( _mmgHydroDeriv_Xrp2.jj * phi * phi );
	
	X_H = 0.5 * _phyconst.rho * _shipinfo.length * _shipinfo.draft * squareU * X_H_dash;
	return X_H;
}

double ShallowWaterModel::_calY_H(void)
{
	double Y_H;
	double Y_H_dash = 0.0;
	
	double squareU = std::pow(_vel.linear.x(),2) + std::pow(_vel.linear.y(),2);
	double v = _vel.linear.y() / sqrt( squareU );
	double r = _vel.angular.z() * _shipinfo.length / std::sqrt( squareU );
	double phi = _pos.angular.y();

	Y_H_dash =
		 ( _mmgHydroDeriv_Yvr1.i * v )
		+( _mmgHydroDeriv_Yvr1.j * r )
		+( _mmgHydroDeriv_Yvr3.iii * v * v * v )
		+( _mmgHydroDeriv_Yvr3.iij * v * v * r )
		+( _mmgHydroDeriv_Yvr3.ijj * v * r * r )
		+( _mmgHydroDeriv_Yvr3.jjj * r * r * r )
		+( _mmgHydroDeriv_Yp1.val * phi )
		+( _mmgHydroDeriv_Yvp3.iij * v * v * phi )
		+( _mmgHydroDeriv_Yvp3.ijj * v * phi * phi )
		+( _mmgHydroDeriv_Yrp3.iij * r * r * phi )
		+( _mmgHydroDeriv_Yrp3.ijj * r * phi * phi );

	Y_H = 0.5 * _phyconst.rho * _shipinfo.length * _shipinfo.draft * squareU * Y_H_dash;
	return Y_H;	
}

double ShallowWaterModel::_calN_H(void)
{
	double N_H;
	double N_H_dash = 0.0;
	
	double squareU = std::pow(_vel.linear.x(),2) + std::pow(_vel.linear.y(),2)
	double v = _vel.linear.y() / sqrt( squareU );
	double r = _vel.angular.z() * _shipinfo.length / std::sqrt( squareU );
	double phi = _pos.angular.y();

	N_H_dash =
		 ( _mmgHydroDeriv_Nvr1.i * v )
		+( _mmgHydroDeriv_Nvr1.j * r )
		+( _mmgHydroDeriv_Nvr3.iii * v * v * v )
		+( _mmgHydroDeriv_Nvr3.iij * v * v * r )
		+( _mmgHydroDeriv_Nvr3.ijj * v * r * r )
		+( _mmgHydroDeriv_Nvr3.jjj * r * r * r )
		+( _mmgHydroDeriv_Np1.val * phi )
		+( _mmgHydroDeriv_Nvp3.iij * v * v * phi )
		+( _mmgHydroDeriv_Nvp3.ijj * v * phi * phi )
		+( _mmgHydroDeriv_Nrp3.iij * r * r * phi )
		+( _mmgHydroDeriv_Nrp3.ijj * r * phi * phi );

	N_H = 0.5 * _phyconst.rho * _shipinfo.length * _shipinfo.draft * squareU * N_H_dash;
	return N_H;	
}

double ShallowWaterModel::_calcX_P(void)
{
	double squareU = std::pow(_vel.linear.x(),2) + std::pow(_vel.linear.y(),2);
	double x_P = _propinfo.pos.x() / _shipinfo.length;
	double z_P = _propinfo.pos.z() / _shipinfo.length;
	double u = _vel.linear.x();
	double v = _vel.linear.y();
	double r = _vel.angular.z() * _shipinfo.length / std::sqrt( squareU );
	double phi_dot = _vel.angular.y() *_shipinfo.length / std::sqrt( squareU );
	
	double beta = std::atan( -v / u );
	double beta_P = beta - x_P * r + z_P * phi_dot;
	double w_P = _mmgPropeller_wP0 * (1 - (1 - std::pow(std::cos(beta_P), 2) ) * (1 - std::abs(beta_P)));
	double J_P = u * (1 - w_P) / (_propeller[0] * _propinfo.diameter);
	double T =
		 _phyconst.rho
		* std::pow(_propeller[0],2)
		* std::pow(_propinfo.diameter, 4)
		* (_mmgPropellerSpec_k[2] * J_P * J_P + _mmgPropellerSpec_k[1] * J_P + _mmgPropellerSpec_k[0]);
	double X_P = (1 - _mmgPropeller_tP) * T;
	return X_P;
}

		
	

		
