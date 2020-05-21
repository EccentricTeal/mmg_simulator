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
		+( _mmgparam.get_mmgHullParam("Xvv") * v * v )
		+( _mmgparam.get_mmgHullParam("Xvr") * v * r )
		+( _mmgparam.get_mmgHullParam("Xrr") * r * r )
		+( _mmgparam.get_mmgHullParam("Xvvvv") * std::pow(v, 4) )
		+( _mmgparam.get_mmgHullParam("Xvp") * v * phi )
		+( _mmgparam.get_mmgHullParam("Xrp") * r * phi )
		+( _mmgparam.get_mmgHullParam("Xpp") * phi * phi );
	
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
		 ( _mmgparam.get_mmgHullParam("Yv") * v )
		+( _mmgparam.get_mmgHullParam("Yr") * r )
		+( _mmgparam.get_mmgHullParam("Yvvv") * v * v * v )
		+( _mmgparam.get_mmgHullParam("Yvvr") * v * v * r )
		+( _mmgparam.get_mmgHullParam("Yvrr") * v * r * r )
		+( _mmgparam.get_mmgHullParam("Yrrr") * r * r * r )
		+( _mmgparam.get_mmgHullParam("Yp") * phi )
		+( _mmgparam.get_mmgHullParam("Yvvp") * v * v * phi )
		+( _mmgparam.get_mmgHullParam("Yvpp") * v * phi * phi )
		+( _mmgparam.get_mmgHullParam("Yrrp") * r * r * phi )
		+( _mmgparam.get_mmgHullParam("Yrpp") * r * phi * phi );

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
		 ( _mmgparam.get_mmgHullParam("Nv") * v )
		+( _mmgparam.get_mmgHullParam("Nr") * r )
		+( _mmgparam.get_mmgHullParam("Nvvv") * v * v * v )
		+( _mmgparam.get_mmgHullParam("Nvvr") * v * v * r )
		+( _mmgparam.get_mmgHullParam("Nvrr") * v * r * r )
		+( _mmgparam.get_mmgHullParam("Nrrr") * r * r * r )
		+( _mmgparam.get_mmgHullParam("Np") * phi )
		+( _mmgparam.get_mmgHullParam("Nvvp") * v * v * phi )
		+( _mmgparam.get_mmgHullParam("Nvpp") * v * phi * phi )
		+( _mmgparam.get_mmgHullParam("Nrrp") * r * r * phi )
		+( _mmgparam.get_mmgHullParam("Nrpp") * r * phi * phi );

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
	double w_P = _mmgparam.get_mmgPropellerParam("wP0") * (1 - (1 - std::pow(std::cos(beta_P), 2) ) * (1 - std::abs(beta_P)));
	double J_P = u * (1 - w_P) / (_propeller[0] * _propinfo.diameter);
	double T =
		 _phyconst.rho
		* std::pow(_propeller[0], 2)
		* std::pow(_propinfo.diameter, 4)
		* (_mmgparam.get_mmgPropellerParam("k2") * J_P * J_P + _mmgparam.get_mmgPropellerParam("k1") * J_P + _mmgparam.get_mmgPropellerParam("k0") );
	double X_P = ( 1 - _mmgparam.get_mmgPropellerParam("t0") ) * T;
	return X_P;
}

		
	

		
