/*-----------------------------------------------------------------------------
Ship Numerical Model Class


Author: Suisei WADA (D1)
        @Faculty of Naval Architecture and Ocean Engineering, Osaka University
Date:   10th May, 2020
-----------------------------------------------------------------------------*/
#include "mmg_models.hpp"

//Constractor
ShallowWaterModel::ShallowWaterModel()
{
	;
}

//Destructor
ShallowWaterModel::~ShallowWaterModel()
{
	;
}

//Accessor
void ShallowWaterModel::update(void)
{
	_updateX();
	_updateY();
	_updateN();
	_updateK();

	_resetUpdateFalgs();
}

double ShallowWaterModel::getForceX(void)
{
	double X = _X.value;
	return X;	
}

double ShallowWaterModel::getForceY(void)
{
	double Y = _Y.value;
	return Y;	
}

double ShallowWaterModel::getForceN(void)
{
	double N = _N.value;
	return N;	
}

double ShallowWaterModel::getForceK(void)
{
	double K = _K.value;
	return K;	
}


//Private Functions
void ShallowWaterModel::_calcU(void)
{
	if(false == _tempU.isUpdated)
	{
		_tempU.value = std::sqrt( std::pow(_vel.linear.x(),2) + std::pow(_vel.linear.y(),2) );
		_tempU.isUpdated = true;
	}
	
}


void ShallowWaterModel::_calcF_N(void)
{
	if(false == _tempF_N.isUpdated)
	{
		if(false == _tempU.isUpdated)
		{
			_calcU();
		}
		double U = _tempU.value;
		double u = _vel.linear.x();
		double v = _vel.linear.y();
		double beta = std::atan( -v / u );
		double D_P = _propellerparam.getDiameter();
		double Pitch = _propellerparam.getPitch();		
		double x_P = _propellerparam.getForcePoint_x();
		double z_P = _propellerparam.getForcePoint_z();
		double x_R = _rudderparam.getForcePoint_x();
		double z_R = _rudderparam.getForcePoint_z();		

		double L = _bodyparam.getLength();
		double D = _bodyparam.getDraft();
		double H_R = _rudderparam.getHeight();
		double W_R = _rudderparam.getWidth();		
		double Eta = D_P / H_R;
		double w_P0 = _mmgparam.get_mmgPropellerParam("w_P0");
		double Gamma_R = _mmgparam.get_mmgRudderParam("Gamma_R");		
		double Epsilon = _mmgparam.get_mmgRudderParam("Epsilon");
		double Kapper = _mmgparam.get_mmgPropellerParam("Kapper");
		double f_alpha = _mmgparam.get_mmgRudderParam("f_Alpha");
		double K_T = _propellerparam.getKT();		

		double A_R = W_R * H_R;
		double x_P_dash = x_P / L;
		double z_P_dash = z_P / L;
		double r_dash = _vel.angular.z() * L / U;
		double phi_dot_dash = _vel.angular.x() * L / U;		
			
		double beta_P = beta - x_P_dash * r_dash + z_P_dash * phi_dot_dash;
		double w_P = w_P0 * (1 - (1 - std::pow(std::cos(beta_P), 2) ) * (1 - std::abs(beta_P)));
		double u_P = ( 1 - w_P ) * _vel.linear.x();
		double propeller_slip = ( 1 - u_P / (_propeller[0].rotate * Pitch) );
		double J_P0 = _vel.linear.x() * (1 - w_P0) / (_propeller[0].rotate * D_P);

		double beta_R = 0.0;
		double u_R = 0.0;
		double v_R = 0.0;
		double squareU_R = 0.0;
		double Alpha_R = 0.0;
		double F_N = 0.0;

		
		beta_R = beta - ( (x_R / L) * (_vel.angular.z() * L / U) ) + ( (z_R / D) * (_vel.angular.x() * D / _vel.linear.y()) );
		v_R = U * Gamma_R * beta_R;
		u_R =
			Epsilon
			* _vel.linear.x()
			* ( 1 - w_P0 )
			* std::sqrt(
				Eta
				* std::pow(1 + (
							   Kapper 
							   * (std::sqrt(1 + (propeller_slip * K_T) / (_phyconst.pi * J_P0 * J_P0) ) - 1 )
							   ),
					2)
				+ ( 1 - Eta )
				);
	
		squareU_R = (u_R * u_R) + (v_R * v_R);
	
		Alpha_R = _rudder[0].angle - std::atan( v_R / u_R );

		F_N = 0.5 * _phyconst.rho * A_R * squareU_R * f_alpha * std::sin(Alpha_R);

		_tempF_N.value = F_N;
		_tempF_N.isUpdated = true;
	}
	
	
}


void ShallowWaterModel::_calcX_H(void)
{
	if(false == _tempX_H.isUpdated)
	{
		double X_H_dash = 0.0;
		double U = 0.0;

		if(false == _tempU.isUpdated)
		{
			_calcU();
		}
		U = _tempU.value;

		double L = _bodyparam.getLength();
		double D = _bodyparam.getDraft();		
		double v = _vel.linear.y() / U;
		double r = _vel.angular.z() * L / U;
		double phi = _pos.angular.x();

		X_H_dash =
			-_mmgparam.get_mmgHullParam("R0")
			+( _mmgparam.get_mmgHullParam("Xvv") * v * v )
			+( _mmgparam.get_mmgHullParam("Xvr") * v * r )
			+( _mmgparam.get_mmgHullParam("Xrr") * r * r )
			+( _mmgparam.get_mmgHullParam("Xvvvv") * std::pow(v, 4) )
			+( _mmgparam.get_mmgHullParam("Xvp") * v * phi )
			+( _mmgparam.get_mmgHullParam("Xrp") * r * phi )
			+( _mmgparam.get_mmgHullParam("Xpp") * phi * phi );
	
		double X_H = 0.5 * _phyconst.rho * L * D * U * U * X_H_dash;
		_tempX_H.value = X_H;
		_tempX_H.isUpdated = true;
	}
	
}


void ShallowWaterModel::_calcY_H(void)
{
	if(false == _tempY_H.isUpdated)
	{
		double Y_H_dash = 0.0;
		double U = 0.0;

		if(false == _tempU.isUpdated)
		{
			_calcU();
		}
		U = _tempU.value;

		double L = _bodyparam.getLength();
		double D = _bodyparam.getDraft();		
		double v = _vel.linear.y() / U;
		double r = _vel.angular.z() * L / U;
		double phi = _pos.angular.x();

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

		double Y_H = 0.5 * _phyconst.rho * L * D * U * U * Y_H_dash;
		_tempY_H.value = Y_H;
		_tempY_H.isUpdated = true;
	}
				
}


void ShallowWaterModel::_calcN_H(void)
{
	if(false == _tempN_H.isUpdated)
	{		
		double N_H_dash = 0.0;
		double U = 0.0;

		if(false == _tempU.isUpdated)
		{
			_calcU();
		}
		U = _tempU.value;
		double L = _bodyparam.getLength();
		double D = _bodyparam.getDraft();		
		double v = _vel.linear.y() / U;
		double r = _vel.angular.z() * L / U;
		double phi = _pos.angular.x();

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

		double N_H = 0.5 * _phyconst.rho * L * D * U * U * N_H_dash;
		_tempN_H.value = N_H;
		_tempN_H.isUpdated = true;
	}
	
}

void ShallowWaterModel::_calcX_P(void)
{
	if(false == _tempX_P.isUpdated)
	{		
		double U = 0.0;

		if(false == _tempU.isUpdated)
		{
			_calcU();
		}
		U = _tempU.value;

		double L = _bodyparam.getLength();
		double D = _bodyparam.getDraft();
		double k0 = _mmgparam.get_mmgPropellerParam("k0");
		double k1 = _mmgparam.get_mmgPropellerParam("k1");
		double k2 = _mmgparam.get_mmgPropellerParam("k2");
		double w_P0 = _mmgparam.get_mmgPropellerParam("wP0");
		double t_0 = _mmgparam.get_mmgPropellerParam("t0");		
		double D_P = _propellerparam.getDiameter();
		double u = _vel.linear.x();
		double v = _vel.linear.y();
		double x_P = _propellerparam.getForcePoint_x();
		double z_P = _propellerparam.getForcePoint_z();		
		
		double x_P_dash = x_P / L;
		double z_P_dash = z_P / D;
		double r = _vel.angular.z() * L / U;
		double phi_dot = _vel.angular.x() * L / U;	
		double beta = std::atan( -v / u );
		double beta_P = beta - x_P_dash * r + z_P_dash * phi_dot;		
		double w_P =  w_P0 * (1 - (1 - std::pow(std::cos(beta_P), 2) ) * (1 - std::abs(beta_P)));
		double J_P = u * (1 - w_P) / (_propeller[0].rotate * D_P);
		
		double T = _phyconst.rho * std::pow(_propeller[0].rotate, 2) * std::pow(D_P, 4) * ( k2 * J_P * J_P + k1 * J_P + k0 );
		double X_P = ( 1 - t_0 ) * T;
		
		_tempX_P.value = X_P;
		_tempX_P.isUpdated = true;
	}
	
}


void ShallowWaterModel::_calcX_R(void)
{
	if(false == _tempX_R.isUpdated)
	{
		double F_N = 0.0;
		if(false == _tempF_N.isUpdated)
		{
			_calcF_N();
		}
		F_N = _tempF_N.value;
		double t_R = _mmgparam.get_mmgPropellerParam("t_R");
				
		double X_R = -(1 - t_R ) * F_N * std::sin( _rudder[0].angle ) * std::cos( _pos.angular.x() );
		_tempX_R.value = X_R;
		_tempX_R.isUpdated = true;
	}
	
}


void ShallowWaterModel::_calcY_R(void)
{
	if(false == _tempY_R.isUpdated)
	{		
		double F_N = 0.0;
		if(false == _tempF_N.isUpdated)
		{
			_calcF_N();
		}
		F_N = _tempF_N.value;
		double alpha_H = _mmgparam.get_mmgPropellerParam("alpha_H");
				
		double Y_R = -(1 + alpha_H ) * F_N * std::cos( _rudder[0].angle ) * std::cos( _pos.angular.x() );	
		_tempY_R.value = Y_R;
		_tempY_R.isUpdated = true;
	}
			
}


void ShallowWaterModel::_calcN_R(void)
{
	if(false == _tempN_R.isUpdated)
	{
		double F_N = 0.0;
		if(false == _tempF_N.isUpdated)
		{
			_calcF_N();
		}
		F_N = _tempF_N.value;
		double alpha_H = _mmgparam.get_mmgPropellerParam("alpha_H");
		double x_H = _mmgparam.get_mmgPropellerParam("x_H");
		double x_R = _rudderparam.getForcePoint_x();		
		
		double N_R =
			- (x_R + alpha_H * x_H )
			* F_N
			* std::cos( _rudder[0].angle )
			* std::cos( _pos.angular.x() );

		_tempN_R.value = N_R;
		_tempN_R.isUpdated = true;
	}
	
}

   
void ShallowWaterModel::_updateX(void)
{
	if(false == _X.isUpdated)
	{
		_calcX_H();
		_calcX_P();
		_calcX_R();
		_X.value = _tempX_H.value + _tempX_P.value + _tempX_R.value;
		_X.isUpdated = true;
	}
}

void ShallowWaterModel::_updateY(void)
{
	if(false == _Y.isUpdated)
	{
		_calcY_H();;
		_calcY_R();
		_Y.value = _tempY_H.value + _tempY_R.value;		
		_Y.isUpdated = true;
	}
}


void ShallowWaterModel::_updateN(void)
{
	if(false == _N.isUpdated)
	{
		_calcN_H();
		_calcN_R();
		_N.value = _tempN_H.value + _tempN_R.value;
		_N.isUpdated = true;
	}
}


void ShallowWaterModel::_updateK(void)
{
	if(false == _K.isUpdated)
	{
		double a = _mmgparam.get_mmgHullParam("a");		
		double b = _mmgparam.get_mmgHullParam("b");
		double K_H = _mmgparam.get_mmgHullParam("K_H");
		double z_R = _rudderparam.getForcePoint_z();		
		double m = _massparam.getMass();
		double Ixx = _massparam.getInertia_xx();
		double Jxx = _massparam.getAddInertia_xx();		
		double K_phi = 0.0;
		double K_phiphi = 0.0;
		double Y_R = 0.0;
		double GM = _bodyparam.getGm();		
		
		K_phi = -2.0 / _phyconst.pi * a * std::sqrt( _phyconst.g * m * GM * ( Ixx + Jxx ) );		
		K_phiphi = -0.75* b * 180 / _phyconst.pi * ( Ixx + Jxx );
		
		if(false == _tempY_R.isUpdated)
		{
			_calcY_R();
		}
		Y_R = _tempY_R.value;		
		
		double K =
			K_H
			- ( Y_R * z_R )
			- ( m * _phyconst.g * GM * _pos.angular.x() )
			+ ( K_phi * _vel.angular.x() )
			+ ( K_phiphi * _vel.angular.x() * std::abs(_vel.angular.x()) );

		_K.value = K;
		_K.isUpdated = true;
	}	
	
}


void ShallowWaterModel::_resetUpdateFalgs(void)
{
	_X.isUpdated = false;
	_Y.isUpdated = false;
	_N.isUpdated = false;
	_K.isUpdated = false;

	_tempU.isUpdated = false;
	_tempF_N.isUpdated = false;
	_tempX_H.isUpdated = false;
	_tempY_H.isUpdated = false;
	_tempN_H.isUpdated = false;
	_tempX_P.isUpdated = false;
	_tempX_R.isUpdated = false;
	_tempY_R.isUpdated = false;
	_tempN_R.isUpdated = false;
}

   
