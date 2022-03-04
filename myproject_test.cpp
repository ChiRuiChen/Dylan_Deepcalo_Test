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
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "firmware/myproject.h"
#include "firmware/nnet_utils/nnet_helpers.h"
//#include "firmware/weights/w27.h"
//#include "firmware/weights/w31.h"
//#include "firmware/weights/w36.h"
//#include "firmware/weights/w40.h"
//#include "firmware/weights/w44.h"
//#include "firmware/weights/w48.h"
#include "firmware/parameters.h"


#define CHECKPOINT 5000

int main(int argc, char **argv)
{
  //load input data from text file
  std::ifstream fin("tb_data/tb_input_features.dat");
  //load predictions from text file
  std::ifstream fpr("tb_data/tb_output_predictions.dat");

#ifdef RTL_SIM
  std::string RESULTS_LOG = "tb_data/rtl_cosim_results.log";
#else
  std::string RESULTS_LOG = "tb_data/csim_results.log";
#endif
  std::ofstream fout(RESULTS_LOG);

  std::string iline;
  std::string pline;
  int e = 0;
  model_weightdefault_t w40[589824];
  hls::stream<input_t> em_barrel[257];
  hls::stream<result_t> layer54_out[257];
  
  for(int iX = 0; iX < 5; iX++) { 
    input_t pTest = 1;
    for(int i0 = 0; i0 < (3)*(3); i0++) {
		for(int i2 = 0; i2 < 257; i2++) {
			em_barrel[i2].write(pTest);	  
        }
    }
  }
	model_weightdefault_t w = 1;
	for(int i = 0; i < 589824; i++) {
		w40[i] = w;
	}
  
  
  
	myproject(em_barrel,layer54_out,w40);
	for(int iX = 0; iX < 5; iX++) { 
		for(int i1 = 0; i1 < 9; i1++) {
			for(int i0 = 0; i0 < 257; i0++) {
				std::cout << layer54_out[i0].read() << " ";
			}
			std::cout  << std::endl;
		}
	}
  
   
	
     
  
   
	fin.close();
    fpr.close();
  return 0;
}
