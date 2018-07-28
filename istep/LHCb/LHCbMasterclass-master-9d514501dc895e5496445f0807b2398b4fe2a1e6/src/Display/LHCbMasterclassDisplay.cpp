//============================================================================
// Name        : LHCb.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <TApplication.h>
#include <TEveManager.h>

#include "Frame.h"

int main(int argc, char **argv)
{
  // Use TApplication if you don't need prompt.
  TApplication  *app = new TApplication("LHCb Masterclass", &argc, argv);

  // See arguments to Create() and constructor -- you can choose not to show the window
  // or some GUI parts.
  //TEveManager::Create();
  Frame *f = new Frame();
  
  // Create custom GUI, if needed.

  app->Run(kTRUE);
  // Pass kFALSE if you want application to terminate by itself.
  // Then you just need "return 0;" below (to avoid compiler warnings).

  // Optionally shutdown eve here (not really needed):
  // TEveManager::Terminate();
  app->Terminate(0);

  delete f;

  return 0;
}
