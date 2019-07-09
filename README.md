# Trash-Mechanics
A simple game in which you need to classify your garbages and throw them into correct dustbins, coded with C++ and FLTK library.

# Tool Specification
Coding System : Visual Studio (Windows 10 SDK Ver 10.0.17134.0) 

Version Control : Github

Continuous Intergration & Deployment : Jenkins

Build Tool: CMake

Style Check : cpplint ( https://github.com/cpplint/cpplint )

Static Analysis : cppcheck ( http://cppcheck.sourceforge.net/ ) 

Complexity Analysis : cppncss ( http://cppncss.sourceforge.net/ )

Unit Test Coverage : OpenCppCoverage 

Text Editor : markdown

Graph Maker : LaTeX 

Graphics Library : FLTK 1.3.5 ( https://www.fltk.org/ )

## FLTK Lib Install

Based on https://www.cnblogs.com/lulipro/p/10120917.html

1. Download fltk-1.3.5-source.tar and  unpack it to an only-English address

2. Launch Visual Studio and open \fltk-1.3.5\ide\VisualC2010\fltk.sln 

3. Choose "Debug" mode and set demo as the start program

4. Ctrl+F5 and see if it works

5. Change to "Release" mode and redo 3&4

6. Copy the whole "FL" document packs from \fltk-1.3.5\FL to C:\Program Files (x86)\Microsoft Visual Studio\2017\Professional\VC\Tools\MSVC\14.16.27023\include\FL

7. Copy all ".lib" files ( totally 14 files ) from \fltk-1.3.5\lib to C:\Program Files (x86)\Microsoft Visual Studio\2017\Professional\VC\Tools\MSVC\14.16.27023\lib\x86

8. Launch Visual Studio and build a Visual C++ -- empty project

9. Build main.cpp in Project1 -- source files 

10. Copy the code below to the main.cpp : ( NOTE : Don't compile now ! )

    ```c++
    #include <FL/Fl.H>
    #include <FL/Fl_Window.H>
    #include <FL/Fl_Box.H>
    int  main(int argc, char *argv[])
    {
    	Fl_Window  *window;
    	Fl_Box  *box;
    	window = new  Fl_Window(450, 330, "First App!");
    	box = new Fl_Box(20, 40, 360, 200, "Hello World");
    	box->box(FL_FLAT_BOX);
    	box->labelsize(36);                   
    	box->labelfont(FL_BOLD + FL_ITALIC);  
    	box->labeltype(FL_SHADOW_LABEL);      
    	window->end();
    	window->show(argc, argv);
    	return  Fl::run();
    }
    ```

11. Right-button click Project1 -- Settings -- C/C++ -- Preprocessor -- Preprocessor Definition -- Edit , then add "WIN32" to it. ( NOTE : the "Configuration" on the left top corner should be in "All Configurations" ) , click "Confirm".

12. Project1 -- Settings -- Linkers -- Input , then change the configuration to "Debug"

13. Additional Dependences -- Edit , then add the list below to it :

    ```
    Comctl32.lib
    fltkd.lib
    fltkformsd.lib
    fltkgld.lib
    fltkimagesd.lib
    fltkjpegd.lib
    fltkpngd.lib
    fltkzlibd.lib
    ```

    click "Confirm"

14. change the configuration to "Release" 

15. Additional Dependences -- Edit , then add the list below to it :

    ```
    Comctl32.lib
    fltk.lib
    fltkforms.lib
    fltkgl.lib
    fltkimages.lib
    fltkjpeg.lib
    fltkpng.lib
    fltkzlib.lib
    ```

    click "Confirm",

    click "Apply".

16. Ctrl+F5 , compile the program to check if it works
17. Project ( On the top ) -- output template -- Project template -- name:FLTK -- Finish
18. Now you can use it by "New project -- FLTK project"

