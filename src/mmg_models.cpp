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
	double X_H_dash = 0.0;
	double squareU = std::pow(_vel.linear.x(),2) + std::pow(_vel.linear.y(),2);
	double result;

	X_H_dash =
		-_mmgResistFore
		+( _mmgHydroDeriv_Xvr.ii * _vel.linear.y() * _vel.linear.y() )
		+( _mmgHydroDeriv_Xvr.ij * _vel.linear.y() * _vel.angular.z() )
		+( _mmgHydroDeriv_Xvr.jj * _vel.angular.z() * _vel.angular.z() )
		+( _mmgHydroDeriv_Xvvvv.val * std::pow(_vel.linear.y(), 4) )
		+( _mmgHyrdoDeriv_Xvp.val * _vel.linear.y() * _vel.angular.y() )
		+( _mmgHydroDeriv_Xrp.ij * _vel.angular.z() * _vel.angular.y() )
		+( _mmgHydroDeriv_Xrp.jj * _vel.angular.y() * _vel.angular.y() );
	
	result = 0.5 * _phyconst.rho * _shipinfo.length * _shipinfo.draft * squareU * X_H_dash;
	return result;
}

	

/*double ShallowWaterModel::calc_speed_Vm(double v, double x_g, double r, double z_g, double phi_dot)
{
	return v - x_g * r + z_g * phi_dot;
}

double ShallowWaterMmgModel::calc_speed_U(double u, double v_m)
{
	return std::sqrt( pow(u) + pow(v_m) );
}

double ShallowWaterMmgModel::calc_angle_Beta(double v_m, double u)
{
	return std::atan(-v_m / u);
}
	
double ShallowWaterMmgModel::calc_coef_K_phidot();*/
