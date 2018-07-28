/* (C) Copyright 2013  CERN

   This software is distributed under the terms of the GNU General Public
   License version 3 (GPL Version 3), copied verbatim in the file "COPYING".

   In applying this license, CERN does not waive the privileges and immunities
   granted to it by virtue of its status as an Intergovernmental Organization
   or submit itself to any jurisdiction.

 */
#include <TApplication.h>
#include "LHCb_D0_Exercise.h"


int main(int argc, char *argv[]) {

  TApplication theApp("App", &argc, argv);

  try {
    //LHCb_D0_Exercise(6);
  }
  catch (MissingDataFile & ) {
    // the error message is already printed by ROOT.
    return 1;
  }

  theApp.Run();

  return 0;
}
