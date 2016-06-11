
//##########################################################################
//# This software is part of the Treescaper i
//# -- Version 0.1   
//# Copyright (C) 2010 Wen Huang
//# 
//# This program is free software; you can redistribute it and/or
//# modify it under the terms of the GNU General Public License
//# as published by the Free Software Foundation; either version 2
//# of the License, or (at your option) any later version.
//#
//# This program is distributed in the hope that it will be useful,
//# but WITHOUT ANY WARRANTY; without even the implied warranty of
//# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//# GNU General Public License for more details. 
//# http://www.gnu.org/copyleft/gpl.html 
//##########################################################################

// dimension estimator head file
//            April/20/2010
//                    whuang

#ifndef WDIMEST_H
#define WDIMEST_H

#include "wdef.h"
#include "warray.cpp"
#include "wstring.h"
#include "wfile.h"
#include "wmatrix.cpp"
#ifdef COMMAND_LINE_VERSION
#include "wmix.h"
#include "wimport_form.h"
#include "wmapping.cpp"
#endif

struct dimest_parameters{
	int cor_n;
	int nn_n;
	int mle_n;
    int distance_file_type;
};

class DimEst{
public:
    DimEst(){};

#ifdef _MAC
	DimEst(String filename, String meth, String dataform, String para_fname)
	{
		double **dist = NULL;
		initial_DimEst(filename, dist, 0, 0, meth, dataform, para_fname);
	};
#endif
    
#ifdef _WINDOWS
	DimEst(String filename, String meth, String dataform, String para_fname)
	{
		double **dist = NULL;
		initial_DimEst(filename, dist, 0, 0, meth, dataform, para_fname);
	};
#endif
    
#ifdef _LINUX
	DimEst(String filename, String meth, String dataform, String para_fname)
	{
		double **dist = NULL;
		initial_DimEst(filename, dist, 0, 0, meth, dataform, para_fname);
	}; 
#endif
    
#ifdef COMMAND_LINE_VERSION
	DimEst(String filename, String meth, String dataform, String para_fname)
	{
		initial_DimEst(filename, method, dataform, para_fname);
	}
	void initial_DimEst(String filename, String meth, String dataform, String para_fname);

	void init_parameters(String para_filename);
#endif

	void initial_DimEst(String filename, double **dist, int sizeinput, int diminput, String meth, String dataform, String para_fname);

	void Compute_Dim();

	void Compute_Cor_Dim();

	void Compute_NN_Dim();

	void Compute_NN_Dist(Matrix<double> &NND);

	void Compute_Eig_Dim();

	void Compute_MLE_Dim();

	void Compute_MLE_Mk(Matrix<double> &Mk);

	void output_to_files();

	String makefilename(String output);

	double Cor_Dim_C(double r);

    dimest_parameters parameters;

private:
	Matrix<double> D;
	Matrix<double> X;
	Matrix<double> Dim_C;
	Matrix<double> Dim_D;
	String method;
	String D_prefname;
	String D_postfname;
	int num_r;
    int size;
};

#endif
