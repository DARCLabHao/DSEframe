===================================================================================
                 DSE Explorer Framework
===================================================================================

DSE Explorer Framework(DEEF) is a software designed for generating and analysing the result of Design Space Exploration(DSE). It is a open source software based on Qt creator. The software can be used to call your own DSE process designed by different high-level synthesis tool with system call of command line built inside.

All of the work has been done by the Design Automation and Reconfigurable Computing Laboratory (DARClab) at the Department of Electrical and Computer Engineering (ECE), at the  University of Texas at Dallas. And this is the first version of the project.

Link: www.utdallas.edu/~schaferb/darclab

More details regarding the software can be found at the authors:
Zi Wang, zxw173030@utdallas.edu
Hao Wu, hxw152530@utdallas.edu
Benjamin Carrion Schafer, schaferb@utdallas.edu

Please cite this work if you use DEEF for your academic work.

DEEF is distributed in the hope that it will be useful. DEEF is free software; you can redistribute it and/or modify it, but please remember WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. And please install Qtcreator on your machine to access and make your own modification to the project.




## Usage

## Open the App

Double click the DEEF app or open it from command line.

## Create result

To use DEEF, user need to create their own result in CSV format. The information should include
	"Method, Iteration, ..., AREA, ..., Lantency, ... "

There are several csv example files under "your_app_path/examples" for reference.

## New File

Making an new file in the target directory under "File" -> "New File". 
File name must in CSV format and meet the DSE result.

## Load File

Add a existing file path to the file watcher under "File" -> "Load File". 
All the data will be load automatically.

## Run Command

After put the command into the command line text box, click "Run" button.
All the data generated and save to the target file will be update on the application.
Note the file path load by "Load File" will work as well.

## Data Selection

After all the data are analyzed and plotted, user can select the data set by clicking the check box in the result table.
User can also select the optimum data or all data by clicking the radio button under graph.

## Kill The Process

If the command run into infinite loops or takes too long to finish, user can click the "Stop" button to kill the process.


## 

The following files in DEEF may be important to your modification

-----------------------------------------------------------------
|   NAME              |        Description                      |
|---------------------+-----------------------------------------+
|---------------------+-----------------------------------------+
| QT_DSE_1_1.pro      | Qt program make file, open it from      | 
|                     | Qt Creator                              |
|---------------------+-----------------------------------------+
|---------------------+-----------------------------------------+
| main.cpp            | main process of the project,	        | 
|                     | used to link different object only      |
|---------------------+-----------------------------------------+
|---------------------+-----------------------------------------+
| mainwindow.cpp      | The code for the behaviour of the main  |
| mainwindow.h        | main interface and all the data process |
| mainwindow.ui       |                                         |
|---------------------+-----------------------------------------+
|---------------------+-----------------------------------------+
| newfile.cpp         | The code for dialog from "File"->"New"  |
| newfile.h           | use to locate the file path             |
| newfile.ui          |                                         | 
|---------------------+-----------------------------------------+
|---------------------+-----------------------------------------+
| qcustomplot.cpp     | Third party plot function used to       |
| qcustomplot.h       | generate the trade-off curve            |
|---------------------+-----------------------------------------+
|---------------------+-----------------------------------------+
