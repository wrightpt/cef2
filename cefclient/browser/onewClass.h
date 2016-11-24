/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   onewClass.h
 * Author: c
 *
 * Created on November 23, 2016, 5:08 PM
 */

#ifndef ONEWCLASS_H
#define ONEWCLASS_H
//#pragma once

//namespace client {

//#include "onewClass.cpp"
 #include "include/cef_base.h"



class onewClass //: public virtual CefBase 
{
public:
    
    
     struct Settings {
    Settings();

    // If true use transparent rendering.
    bool transparent;

    // If true draw a border around update rectangles.
    bool show_update_rect;

    // Background color.
    cef_color_t background_color;
  };
    onewClass();
   // onewClass(const onewClass& orig);
    
    // Initialize the OpenGL environment.
  void Initialize();

  // Clean up the OpenGL environment.
 // void Cleanup();

  // Render to the screen.
  void Render();
    
    
    virtual ~onewClass();
private:

};

//}

#endif /* ONEWCLASS_H */

