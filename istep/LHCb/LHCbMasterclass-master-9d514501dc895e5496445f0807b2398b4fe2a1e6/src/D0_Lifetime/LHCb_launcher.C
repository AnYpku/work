/* (C) Copyright 2013  CERN

   This software is distributed under the terms of the GNU General Public
   License version 3 (GPL Version 3), copied verbatim in the file "COPYING".

   In applying this license, CERN does not waive the privileges and immunities
   granted to it by virtue of its status as an Intergovernmental Organization
   or submit itself to any jurisdiction.

 */
#include <TApplication.h>
#include <TControlBar.h>
#include <launcher.h>
#include "Riostream.h"
#include <TApplication.h>
#include <TControlBar.h>
#include <launcher.h>
#include "Riostream.h"
#include <TSystem.h>


int main(int argc, char *argv[])
{

   TApplication theApp("LHCb Masterclass launcher", &argc, argv);
   launcher *l=new launcher();
   theApp.Run();
   return 0;
}
