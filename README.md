# PAT Report Generator

WIP system for generating PAT (Portable Appliance Testing) reports in PDF format using C++.

## Tools and libraries used
* Visual Studio 2022
* wxWidgets - nice graphics library for making GUIs.
    - Download and build from source: https://wxwidgets.org/downloads/
* TinyXML2 - XML parsing
    - Install using vcpkg
* Google Glog - debug logging
    - Install using vcpkg
* libHaru (?) - PDF generation
    - Installation steps TBC -- not yet implemented.

## Intended outcome
The program should allow the user to input entries with a list of the devices tested. The current implementation (made using MS Word) is shown below:

![](https://i.imgur.com/r1uTKNf.png)

The system should generate a PDF document using this as a template.