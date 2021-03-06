===================================================================================
                 DSE Explorer Framework (DSEframe) v.1.0
===================================================================================

DSE Explorer Framework(DSEframe) is a software designed for generating and analysing the result of High-Level Synthesis (HLS) Design Space Exploration (DSE). It is a open source software based on Qt creator. The software can be used to call your own DSE process using any HLS tool. This is done by a system call of command  built inside.

All of the work has been done by the Design Automation and Reconfigurable Computing Laboratory (DARClab) at the Department of Electrical and Computer Engineering (ECE), at the  University of Texas at Dallas. 
DARClab=Design Automation and Reconfigurable Computing Laboratory - www.utdallas.edu/~schaferb/darclab


More details regarding the software can be found at the authors:
Zi Wang, zxw173030@utdallas.edu
Hao Wu, hxw152530@utdallas.edu
Benjamin Carrion Schafer, schaferb@utdallas.edu


DSEframe is distributed in the hope that it will be useful. DSEframe is free software; you can redistribute it and/or modify it, but please remember WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. And please install Qtcreator on your machine to access and make your own modification to the project.


## Usage

## Open the App

Double click the DSEframe app or open it from command line.

## File Format

To use DSEframe, user need to create their own result in CSV format. The file format has to be exactly as follow (the examples folder contains some samples)

Method,Iteration,ATTR,AREA,state,FU,REG,MUXrm,DEC,pin_pair,net,max,min,ave,MISC,MEM,cp_delay,sim,Pmax,Pmin,Pave,Latency,BlockMemoryBit,DSP
BF,412,0,928,6,265,456,195,0,1822,849,6,6,6,12,-,1.2401ns,-,-,-,-,62,-,-


Method : Lable of the DSE method
Iteration: Iteration of the same method ran again
ATTR: Hash value generated by all types of unique attributes
AREA: Total area of the synthesized design
state: FSM state count
REG: Number of registers
MUX: Area due to muxes
DEC: Area due to decoders
pin_pair: Number of pin pairs
net: Number of nets
max: Maximum latency
min: Minimum latency
ave: average latency
MISC: Area of miscelaneous logic
MEM: Area of memory
cp_delay: Critical path delay
sim: Simulation runtime
Pmax: Maximum power
Pmin: Minimum power
Pave: Average power
Latency: Latency of circuit
BlockMemoryBit: BlockRAM bits in case of FPGAs
DSP: Number of DSP macros in case of FPGAs only

Out of the these entries Method, Iteration, AREA and Latency MUST be incldued.

There are several csv example files under "DSEframe_path/examples/" for reference.

## New File

Making an new file in the target directory under "File" -> "New File". 
File name must in CSV format and meet the DSE result.

## Load File

Add a existing file with previous exploration rseults to display themunder "File" -> "Load File". 
All the data will be loaded automatically. 


## Run Command - Running own DSE method

1.) Select the folder and filename of the explorer .csv file which will contain the summary of the exploration as shown in File Format section.

2.) Write HLS command with arguments into the command line text box, click "Run" button. The exploration can be killed any time by pressing the stop button.

Note the file path load by "Load File" will work as well.

## Data Selection

After all the data are analyzed and plotted, user can select the data set by clicking the check box in the result table.
User can also select the optimum data or all data by clicking the radio button under graph.

## Kill The Process

If the command run into infinite loops or takes too long to finish, click the "Stop" button to kill the process.


## 

The following files in DSEframe may be important to your modification

-----------------------------------------------------------------
|   NAME              |        Description                      |
|---------------------+-----------------------------------------+
|---------------------+-----------------------------------------+
| examples/           | Folder with several example csv file    |
|                     | that can be tested by loading file      |
|---------------------+-----------------------------------------+
|---------------------+-----------------------------------------+
| release_linux/      | Folder with a executable file on linux  |
|---------------------+-----------------------------------------+
|---------------------+-----------------------------------------+
| release_windows/    | Folder with a executable file on windows|
|---------------------+-----------------------------------------+
|---------------------+-----------------------------------------+
| src/                | Folder with all the source code         |
|---------------------+-----------------------------------------+
|---------------------+-----------------------------------------+
| DSEframe.pro        | Qt program make file, open it from      |
|                     | Qt Creator                              |
|---------------------+-----------------------------------------+
|---------------------+-----------------------------------------+
| main.cpp            | main process of the project             |
|---------------------+-----------------------------------------+
|---------------------+-----------------------------------------+
| mainwindow.cpp      | The code for the behaviour of the main  |
| mainwindow.h        | main interface and all the data process |
| mainwindow.ui       |                                         |
|---------------------+-----------------------------------------+
|---------------------+-----------------------------------------+
| newfile.cpp         | The code for dialog from "File"->"New"  |
| newfile.h           | used to locate the file path            |
| newfile.ui          |                                         |
|---------------------+-----------------------------------------+
|---------------------+-----------------------------------------+
| qcustomplot.cpp     | Third party plot function used to       |
| qcustomplot.h       | generate the trade-off curve            |
-----------------------------------------------------------------
