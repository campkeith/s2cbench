===================================================================================
				S2CBENCH v.1.1
===================================================================================

S2CBENCH stands for Synthesizable SystemC Benchmark suite. It is a open source
SystemC benchmarks created to help designers evaluate the QoR of state of the art
HLS Tools. All of the main HLS tools support the synthesizable subset of SystemC
and hence should be able to synthesize all of these designs without any modifications
EXCEPT for the FFT. The FFT is non-synthesizable as it is because it inludes floating
point and trigonometric functions which are not supported as per the latest SystemC
Synthesizable subset draft 1.3. The FFT was included in order to help you evaluate
how the different vendors deal with floating point synthesis and if they support trigonometric
functions.

Most of the work has been done by the DARClab at the Hong Kong Polytechnic Universities
Department of Electronic and Information Engineering (EIE)
DARClab =Design Automation and Reconfigurable Computing Laboratory - www.eie.polyu.edu.hk/~schaferb/darclab

More details regarding the benchmarks can be found at the following academic publications:

B. Carrion Schafer and A. Mahapatra,"S2CBench:Synthesizable SystemC Benchmark Suite for High-Level Synthesis",
IEEE Embedded Systems Letters, Vol. 6(3), pp. 53-56, 2014

Please cite this work if you use S2CBench for your academic work.


S2CBench is distributed in the hope that it will be useful. S2CBench is free software; you can 
redistribute it and/or modify it, but please remember but WITHOUT ANY WARRANTY; without even the 
implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  

S2CBENCH includes the following Testcases:

------------------------------------------------------------------------------------
|   NAME      |      		Description             |     Author   
|-------------+-----------------------------------------+---------------------------
| adpcm       | Adaptive Differential Pulse-Code        | FFmpeg
|	      |	Modulation (encoder part only)         	| PolyU DARClab 
|-------------+-----------------------------------------+--------------------------
| ann         | Artificial Neuronal Network (ANN)	| David Aledo, CEI, ETSII, Universidad Politecnica Madrid 
| 	      | 2 and 4 layer version	                | PolyU DARClab 
|-------------+-----------------------------------------+--------------------------
| aes         | Advanced Encryption standared (AES)     | pjc.co.jp 
| 	      | 128-bits (cipher and inv cipher)        | Shuangnan Liu, PolyU DARClab 
|-------------+-----------------------------------------+--------------------------
| disparity   | Stereoscopic image disparity estimator  | Miscellanous
| estimator   |					        | PolyU DARClab 
|-------------+-----------------------------------------+--------------------------
| fft         | Fast Fourier Transform                  | R.Goswami,Synopsys, Inc.
|             |						| PolyU DARClab 
|-------------+-----------------------------------------+---------------------------
| fir         | 10-Tap FIR filter                       | PolyU DARClab 
|-------------+-----------------------------------------+--------------------------
| decimation  | 5 Stages decimation filter              | PolyU DARClab
|-------------+-----------------------------------------+--------------------------
|interpolation| 4 Stages interpolation filter           | PolyU DARClab
|-------------+-----------------------------------------+--------------------------
| idct        | Inverse Discrete Cosine Transform       | Thomas G. Lange
|	      |						| PolyU DARClab
|-------------+-----------------------------------------+--------------------------
| kasumi      | Kasumi encryption algorithm             |  ETSI/SAGE
|             |						|  PolyU DARClab
|-------------+-----------------------------------------+--------------------------
| md5c        | Message Digest Algorithm                | RSA Data Security, Inc
|	      |						| PolyU DARClab
|-------------+-----------------------------------------+--------------------------
| qsort       | Quick sort                              | Darel Rex Finley 
|	      | 					| PolyU DARClab
|-------------+-----------------------------------------+--------------------------
| uart        | Universal Asynchronous			| Nandeesh Veeranna,PolyU DARClab
|	      |	Receiver/Trasmitter			| 
|-------------+-----------------------------------------+--------------------------
| snow3G      | snow 3G encryption algorithm            | ETSI/SAGE
|	      |						| PolyU DARClab
|-------------+-----------------------------------------+--------------------------
| sobel       | Sobel filter                            | Anushree Mahapatra, PolyU DARClab
|             |                                         |
|-------------+-----------------------------------------+------------------------
| VGA         | VGA controller and image generator      | Siyuan Xu, PolyU DARClab  
|             |                                         |   
|---------------------------------------------------------------------------------


Each benchmark contains the following files:

Makefile -- Need to modify the path to the systemC folder
---------
make : Generates the executable binary
make wave :Generates the same binary, but the simulate creates a VCD file to view the simulation results
make debug : to create a debug version	   -- VCD File can be visualied with GTKwave (free VCD file viewer)
make clean : cleans the exe and .o files

SystemC files
------------
main.cpp  : Instantiates the modules which sends and receives data and the unit under test
benchmark.cpp /.h : Main description of the benchmark
tb_benchmark.cpp /.h : Testbech for the given benchmark
define.h  : Includes define statments and stimuli filenames

Stimuli files (.txt)
-------------------
<name>.txt       :  File with iput stimuli (could be more than one)
<name>_golden.txt :  File with golden output with which the simulation results will be compared



Extraction instruction (Linux):
%tar -zxvf S2Cbench_<ver>.tar.gz


Version update notes:
--------------------
The follwing changes have been made since the version 1.0.

Design updates:
1.- Update of AES design. In version 1.0 only the cipher was included.In this new version encryption and decryption is possible

New designs added to the benchmark suite:
1.- Added ANN design
2.- Added UART design
3.- Added VGA controller and image generator


Misc changes:
1.- Modified Makefiles to compile the SystemC files for 32-bit and 64-bit machines (previous version only worked with 32-bit machines)

Special thanks to Tim Schmidt from UCI for reviewing and correcting some issues in the initial version and to David Aledo for contribugint with an Artificial Neuronal Network (ANN) design. 


							[END]





