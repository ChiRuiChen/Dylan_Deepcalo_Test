//
//    rfnoc-hls-neuralnet: Vivado HLS code for neural-net building blocks
//
//    Copyright (C) 2017 EJ Kreinar
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
#include <iostream>

#include "myproject.h"

//hls-fpga-machine-learning insert weights
// #include "weights/s3.h"
// #include "weights/b3.h"
// #include "weights/w4.h"
// #include "weights/b4.h"
// #include "weights/w9.h"
// #include "weights/b9.h"
// #include "weights/w13.h"
// #include "weights/b13.h"
// #include "weights/w18.h"
// #include "weights/b18.h"
// #include "weights/w22.h"
// #include "weights/b22.h"
// #include "weights/b27.h"
// #include "weights/b31.h"
// #include "weights/b36.h"
//#include "weights/b40.h"
// #include "weights/b44.h"
// #include "weights/s46.h"
// #include "weights/b46.h"
// #include "weights/b48.h"
// #include "weights/s50.h"
// #include "weights/b50.h"
// #include "weights/w52.h"
// #include "weights/b52.h"


void myproject(
	     
	       hls::stream<input_t>   em_barrel[257],
	       hls::stream<result_t>  layer54_out[257],	       
	       model_weightdefault_t w40[589824]
	      
	       ) { 


	
	model_weightdefault_t b40[256];
	model_weightdefault_t b = 0;
	for(int i = 0; i < 256; i++) {
			b40[i] = b;
		}
	  
	unsigned iN=0;
	
	
	hls::stream<input_t> out[257];
	
	for(int i0 = 0; i0 < (3)*(3)*5; i0++) {    
    
		nnet::zeropad<input_t, input_t, config40>(iN, em_barrel, out);
	}
	

	for(int i0 = 0; i0 < (3+2)*(3+2)*5; i0++) {
		nnet::conv_2d_large_cl_nopad_pad<input_t, result_t, config40>(out, layer54_out, w40, b40);        
	}

  

  }   
  