# Magus
Magus Gui wizzard

Magus is a (Qt) application that generates code (eg. C++) for GUI applications and offers a set of standard widgets to quickly create an application (focussed on game/3D editors). 

![Magus overview](/Magus.png)
The basic framework of a GUI application in Magus is specified in a template file (.ide). This template file is loaded into Magus, which displays a graphical representation of the
GUI framework. The graphical representation of the framework can be modified in Magus before it is build. Building the GUI applications means that Magus generates all the 
relevant application code and all related resources.
Currently, only Qt projects are supported. Magus generates the C++ code, a Qt project file (.pro) and the relevant resources (images).

Note, the Git repo also contains some Windows Dll's. These are VC2010 Qt Dll's. Their purpose is more as a reference (to show which Dll's are needed for the executable).