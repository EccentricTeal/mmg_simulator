/*-----------------------------------------------------------------------------
Ship Numerical Model Class


Author: Suisei WADA (D1)
        @Faculty of Naval Architecture and Ocean Engineering, Osaka University
Date:   10th May, 2020
-----------------------------------------------------------------------------*/
#include "mmg_models.hpp"

//Constractor
void ShallowWaterModel::ShallowWaterModel()
{
	;
}

//Destructor
void ShallowWaterModel::ShallowWaterModel~()
{
	;
}

//Accessor
void ShallowWaterModel::updateX(void)
{
	if(false == _X.isUpdated)
	{
		_calcX_H();
		_calcX_P();
		_calcX_R();
		_X = _tempX_H + _tempX_P + _tempX_R;
		_X.isUpdated = true;
	}
}

void ShallowWaterModel::updateY(void)
{
	if(false == _Y.isUpdated)
	{
		_calcY_H();;
		_calcY_R();
		_Y = _tempY_H + _tempY_R;		
		_Y.isUpdated = true;
	}
}

void ShallowWaterModel::updateN(void)
{
	if(false == _N.isUpdated)
	{
		_calcN_H();
		_calcN_R();
		_N = _tempN_H + _tempN_R;
		_N.isUpdated = true;
	}
}

void ShallowWaterModel::updateK(void)
{
	if(false == _K.isUpdated)
	{		
		double K_phi = 0.0;
		double K_phiphi = 0.0;
		double Y_R = 0.0;	
		
		K_phi =
			-2.0 / _phyconst.pi
			* _mmgparam.get_mmgHullParam("a")
			* std::sqrt(
				_phyconst.g
				* _massparam.mass
				* _hullparam.gm
				* ( _massparam.inertia(1,1) + _massparam.addinertia(1,1) )
				);
		
		K_phiphi =
			-0.75
			* _mmgparam.get_mmgHullParam("b")
			* 180 / _phyconst.pi
			* ( _massparam.inertia(1,1) + _massparam.addinertia(1,1) );
		
		if(false == _tempY_R.isUpdated)
		{
			_calcY_R();
		}
		Y_R = _tempY_R.value;		
		
		double K=
			_mmgparam.get_mmgHullParam("K_H")
			- Y_R * _rudderparam.force_point
			- _massparam.mass * _phyconst.g * _hullparam.gm * _pos.angular.y()
			+ K_phi * _vel.angular.y()
			+ K_phiphi * _vel.angular.y() * std::abs( _vel.angular.y() );

		_K.value = K;
		_K.isUpdated = true;
	}	
	
}


//Private Functions
void ShallowWaterModel::_calcU(void)
{
	if(false == _tempU.isUpdated)
	{
		_tempU.value = std::sqrt( std::pow(_vel.linear.x(),2) + std::pow(_vel.linear.y(),2) );
		tempU.isUpdated = true;
	}
	
}


void ShallowWaterModel::_calcF_N(void)
{
	if(false == _tempF_N.isUpdated)
	{
		
		double u_R = 0.0;
		double v_R = 0.0;
		double U = 0.0;
		double squareU_R = 0.0;
		
		double A_R = _rudderparam.width * _rudderparam.height;
		double Alpha_R = 0.0;
		double beta_R = 0.0;
		double Eta = _propellerparam.diameter / _rudderparam.height;
		
		double beta_P = beta - x_P * r + z_P * phi_dot;
		double w_P = _mmgparam.get_mmgPropellerParam("w_P0") * (1 - (1 - std::pow(std::cos(beta_P), 2) ) * (1 - std::abs(beta_P)));
		double u_P = ( 1 - w_P ) * _vel.linear.x();
		double propeller_slip = ( 1 - u_P / (_propeller[0].rotate * _propellerparam.pitch) );
		double J_P0 = _vel.linear.x() * (1 - _mmgparam.get_mmgPropellerParam("w_P0")) / (_propeller[0].rotate * _propellerparam.diameter);

		double F_N = 0.0;	
	
		if(false == _U_isUpdated)
		{
			_calcU();
		}
		U = _tempU;
	
		beta_R =
			_mmgparam.get_mmgRudderParam("Beta")
			-( (_rudderparam.force_point.x() / _hullparam.length) * (_vel.angular.z() * _hullparam.length / U) )
			+( (_rudderparam.force_point.z() / _hullparam.draft) * (_vel.angular.y() * _hullparam.draft / _vel.linear.y()) );

		v_R = U * _mmgparam.get_mmgRudderParam("Gamma_R") * beta_R;

		u_R =
			_mmgparam.get_mmgRudderParam("Epsilon")
			* _vel.linear.x()
			* ( 1 - _mmgparam.get_mmgPropellerParam("w_P0") )
			* std::sqrt(
				Eta
				* std::pow(1 + (
							   _mmgparam.get_mmgPropellerParam("Kapper") 
							   * (std::sqrt(1 + (propeller_slip * _propellerparam.K_T) / (_phyconst.pi * J_P0 * J_P0) ) - 1 )
							   )
					)
				+ ( 1 - Eta )
				);
	
		squareU_R = (u_R * u_R) + (v_R * v_R);
	
		Alpha_R = _rudder[0].angle - std::atan( v_R / u_R );

		F_N = 0.5 * _phyconst.rho * A_R * squareU_R * _mmgparam.get_mmgRudderParam("f_Alpha") * std::sin(Alpha_R);

		_tempF_N.value = F_N;
		_tempF_N.isUpdated = true;
	}
	
	
}


void ShallowWaterModel::_calX_H(void)
{
	if(false == _tempX_H.isUpdated)
	{
		double X_H_dash = 0.0;
		double U = 0.0;

		if(false == _U_isUpdated)
		{
			_calcU();
		}
		U = _tempU;

		double v = _vel.linear.y() / U;
		double r = _vel.angular.z() * _hullparam.length / U;
		double phi = _pos.angular.y();

		X_H_dash =
			-_mmgparam.get_mmgHullParam("R0")
			+( _mmgparam.get_mmgHullParam("Xvv") * v * v )
			+( _mmgparam.get_mmgHullParam("Xvr") * v * r )
			+( _mmgparam.get_mmgHullParam("Xrr") * r * r )
			+( _mmgparam.get_mmgHullParam("Xvvvv") * std::pow(v, 4) )
			+( _mmgparam.get_mmgHullParam("Xvp") * v * phi )
			+( _mmgparam.get_mmgHullParam("Xrp") * r * phi )
			+( _mmgparam.get_mmgHullParam("Xpp") * phi * phi );
	
		double X_H = 0.5 * _phyconst.rho * _hullparam.length * _hullparam.draft * U * U * X_H_dash;
		_tempX_H.value = X_H;
		_tempX_H.isUpdated = true;
	}
	
}


void ShallowWaterModel::_calY_H(void)
{
	if(false == _tempY_H.isUpdated)
	{
		double Y_H_dash = 0.0;
		double U = 0.0;

		if(false == _U_isUpdated)
		{
			_calcU();
		}
		U = _tempU;
	
		double v = _vel.linear.y() / U;
		double r = _vel.angular.z() * _hullparam.length / U;
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

		double Y_H = 0.5 * _phyconst.rho * _hullparam.length * _hullparam.draft * U * U * Y_H_dash;
		_tempY_H.value = Y_H;
		_tempY_H.isUpdated = true;
	}
				
}


void ShallowWaterModel::_calN_H(void)
{
	if(false == _tempN_H.isUpdated)
	{		
		double N_H_dash = 0.0;
		double U = 0.0;

		if(false == _U_isUpdated)
		{
			_calcU();
		}
		U = _tempU;
		double v = _vel.linear.y() / U;
		double r = _vel.angular.z() * _hullparam.length / U;
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

		double N_H = 0.5 * _phyconst.rho * _hullparam.length * _hullparam.draft * U * U * N_H_dash;
		_tempN_H.value = N_H;
		_tempN_H.isUpdated = true;
	}
	
}

void ShallowWaterModel::_calcX_P(void)
{
	if(false == _tempX_P.isUpdated)
	{		
		double U = 0.0;

		if(false == _U_isUpdated)
		{
			_calcU();
		}
		U = _tempU;
	
		double x_P = _propellerparam.pos.x() / _hullparam.length;
		double z_P = _propellerparam.pos.z() / _hullparam.draft;
		double u = _vel.linear.x();
		double v = _vel.linear.y();
		double r = _vel.angular.z() * _hullparam.length / U;
		double phi_dot = _vel.angular.y() *_hullparam.length / U;
	
		double beta = std::atan( -v / u );
		double beta_P = beta - x_P * r + z_P * phi_dot;
		double w_P = _mmgparam.get_mmgPropellerParam("wP0") * (1 - (1 - std::pow(std::cos(beta_P), 2) ) * (1 - std::abs(beta_P)));
		double J_P = u * (1 - w_P) / (_propeller[0].rotate * _propellerparam.diameter);
		double T =
			_phyconst.rho
			* std::pow(_propeller[0], 2)
			* std::pow(_propellerparam.diameter, 4)
			* (_mmgparam.get_mmgPropellerParam("k2") * J_P * J_P + _mmgparam.get_mmgPropellerParam("k1") * J_P + _mmgparam.get_mmgPropellerParam("k0") );
	
		double X_P = ( 1 - _mmgparam.get_mmgPropellerParam("t0") ) * T;
		_tempX_P.value = X_P;
		_tempX_P.isUpdated = true;
	}
	
}


void ShallowWaterModel::_calcX_R(void)
{
	if(false == _tempX_R.isUpdated)
	{
		double F_N = 0.0;
		if(false == _F_N_isUpdated)
		{
			_calcF_N();
		}
		F_N = _tempF_N;
		
		double X_R =
			- (1 - _mmgparam.get_mmgPropellerParam("t_R") )
			* F_N
			* std::sin( _rudder[0].angle )
			* std::cos( _pos.angular.y() );

		_tempX_R.value = X_R;
		_tempX_R.isUpdated = true;
	}
	
}


void ShallowWaterModel::_calcY_R(void)
{
	if(false == _tempY_R.isUpdated)
	{		
		double F_N = 0.0;
		if(false == _F_N_isUpdated)
		{
			_calcF_N();
		}
		F_N = _tempF_N;
		
		double Y_R =
			- (1 + _mmgparam.get_mmgPropellerParam("Alpha_H") )
			* F_N
			* std::cos( _rudder[0].angle )
			* std::cos( _pos.angular.y() );		
		_tempY_R.value = Y_R;
		_tempY_R.isUpdated = true;
	}
			
}

void ShallowWaterModel::_calcN_R(void)
{
	if(false == _tempN_R.isUpdated)
	{
		double F_N = 0.0;
		if(false == _F_N_isUpdated)
		{
			_calcF_N();
		}
		F_N = _tempF_N;
		
		double N_R =
			- (_rudderparam.force_point.x() + _mmgparam.get_mmgPropellerParam("Alpha_H") *  _mmgparam.get_mmgPropellerParam("x_H") )
			* F_N
			* std::cos( _rudder[0].angle )
			* std::cos( _pos.angular.y() );

		_tempN_R.value = N_R;
		_tempN_R.isUpdated = true;
	}
	
}

   
		
