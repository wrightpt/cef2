/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   onewClass.cpp
 * Author: c
 * 
 * Created on November 23, 2016, 5:08 PM
 */

#include "onewClass.h"
#include <GL/gl.h>
#include <GL/glut.h>
//#endif

//namespace client {

onewClass::Settings::Settings()
    : transparent(false),
      show_update_rect(false),
      background_color(CefColorSetARGB(255, 255, 255, 255)) {
}


onewClass::onewClass() {
}

//onewClass::onewClass(const onewClass& orig) {
//}
GLuint texture_id_;
void onewClass::Initialize() {
  //if (initialized_)
   // return;

  glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST); //VERIFY_NO_ERROR;

 
 //glCearColor(255.0f,255.0f,255.0f,1.0f);
    //glClearColor(float(CefColorGetR(settings_.background_color)) / 255.0f,
  //             float(CefColorGetG(settings_.background_color)) / 255.0f,
   //            float(CefColorGetB(settings_.background_color)) / 255.0f,
   //            1.0f); VERIFY_NO_ERROR;

  // Necessary for non-power-of-2 textures to render correctly.
 glPixelStorei(GL_UNPACK_ALIGNMENT, 1);//ERIFY_NO_ERROR;

  // Create the texture.
 
 
 glGenTextures(1, &texture_id_); //VERIFY_NO_ERROR;
 // DCHECK_NE(texture_id_, 0U); VERIFY_NO_ERROR;

  glBindTexture(GL_TEXTURE_2D, texture_id_); //VERIFY_NO_ERROR;
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                  GL_NEAREST); //VERIFY_NO_ERROR;
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
                 GL_NEAREST);// VERIFY_NO_ERROR;
  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);// VERIFY_NO_ERROR;

  //initialized_ = true;
}


void onewClass::Render() {
  //if (view_width_ == 0 || view_height_ == 0)
   // return;

  //DCHECK(initialized_);

  struct {
    float tu, tv;
    float x, y, z;
  } 
  static vertices[] = {
    {0.0f, 1.0f, -1.0f, -1.0f, 0.0f},
    {1.0f, 1.0f,  1.0f, -1.0f, 0.0f},
    {1.0f, 0.0f,  1.0f,  1.0f, 0.0f},
    {0.0f, 0.0f, -1.0f,  1.0f, 0.0f}
  };

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //VERIFY_NO_ERROR;

  glMatrixMode(GL_MODELVIEW); //VERIFY_NO_ERROR;
  glLoadIdentity(); //VERIFY_NO_ERROR;

  // Match GL units to screen coordinates.
 // glViewport(0, 0, view_width_, view_height_);
  glViewport(0, 0, 50, 50);
  //VERIFY_NO_ERROR;
  glMatrixMode(GL_PROJECTION); //VERIFY_NO_ERROR;
  glLoadIdentity(); //VERIFY_NO_ERROR;

  // Draw the background gradient.
  glPushAttrib(GL_ALL_ATTRIB_BITS); //VERIFY_NO_ERROR;
  // Don't check for errors until glEnd().
  glBegin(GL_QUADS);
  glColor4f(1.0, 0.0, 0.0, 1.0);  // red
  glVertex2f(-1.0, -1.0);
  glVertex2f(1.0, -1.0);
  glColor4f(0.0, 0.0, 1.0, 1.0);  // blue
  glVertex2f(1.0, 1.0);
  glVertex2f(-1.0, 1.0);
  glEnd(); //VERIFY_NO_ERROR;
  glPopAttrib();// VERIFY_NO_ERROR;

  // Rotate the view based on the mouse spin.
 // if (spin_x_ != 0) {
 //   glRotatef(-spin_x_, 1.0f, 0.0f, 0.0f); //VERIFY_NO_ERROR;
 // }
 // if (spin_y_ != 0) {
  //  glRotatef(-spin_y_, 0.0f, 1.0f, 0.0f); //VERIFY_NO_ERROR;
 // }

 //if (settings_.transparent) {
    // Alpha blending style. Texture values have premultiplied alpha.
    glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA); //VERIFY_NO_ERROR;

    // Enable alpha blending.
    glEnable(GL_BLEND);// VERIFY_NO_ERROR;
    
    
    glEnable(GL_TEXTURE_2D); //VERIFY_NO_ERROR;

  // Draw the facets with the texture.
  DCHECK_NE(texture_id_, 0U); //VERIFY_NO_ERROR;
  glBindTexture(GL_TEXTURE_2D, texture_id_);// VERIFY_NO_ERROR;
  glInterleavedArrays(GL_T2F_V3F, 0, vertices); //VERIFY_NO_ERROR;
  glDrawArrays(GL_QUADS, 0, 4); //VERIFY_NO_ERROR;

  // Disable 2D textures.
  glDisable(GL_TEXTURE_2D); //VERIFY_NO_ERROR;

//  if (settings_.transparent) {
    // Disable alpha blending.
  //  glDisable(GL_BLEND); //VERIFY_NO_ERROR;
 // }

  // Draw a rectangle around the update region.
//  if (settings_.show_update_rect && !update_rect_.IsEmpty()) {
 //   int left = update_rect_.x;
  //  int right = update_rect_.x + update_rect_.width;
  //  int top = update_rect_.y;
  //  int bottom = update_rect_.y + update_rect_.height;

#if defined(OS_LINUX)
    // Shrink the box so that top & right sides are drawn.
//    top += 1;
//    right -= 1;
#else
    // Shrink the box so that left & bottom sides are drawn.
    
    left += 1;
    bottom -= 1;
   
#endif
    
    //

    glPushAttrib(GL_ALL_ATTRIB_BITS); //VERIFY_NO_ERROR
    glMatrixMode(GL_PROJECTION);// VERIFY_NO_ERROR;
    glPushMatrix();// VERIFY_NO_ERROR;
    glLoadIdentity(); //VERIFY_NO_ERROR;
   glOrtho(0, 50, 50, 0, 0, 1);
    
    // glOrtho(0, view_width_, view_height_, 0, 0, 1); //VERIFY_NO_ERROR;

    glLineWidth(1); //VERIFY_NO_ERROR;
    glColor3f(1.0f, 0.0f, 0.0f); //VERIFY_NO_ERROR;
    // Don't check for errors until glEnd().
    glBegin(GL_LINE_STRIP);
    // glVertex2i(left, top);
    glVertex2i(2,  1);
   // glVertex2i(right, top);
    //glVertex2i(right, bottom);
    //glVertex2i(left, bottom);
    //glVertex2i(left, top);
    glEnd(); //VERIFY_NO_ERROR;

    glPopMatrix(); //VERIFY_NO_ERROR;
    glPopAttrib(); //VERIFY_NO_ERROR;
  }
    
    
 // }
  
//}


onewClass::~onewClass() {
}

//}

