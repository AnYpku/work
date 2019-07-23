# This file was automatically created by FeynRules $Revision: 595 $
# Mathematica version: 9.0 for Mac OS X x86 (64-bit) (November 20, 2012)
# Date: Fri 7 Jun 2013 16:09:54


from object_library import all_lorentz, Lorentz

from function_library import complexconjugate, re, im, csc, sec, acsc, asec



SSS1 = Lorentz(name = 'SSS1',
               spins = [ 1, 1, 1 ],
               structure = '1')

FFS1 = Lorentz(name = 'FFS1',
               spins = [ 2, 2, 1 ],
               structure = 'Identity(2,1)')

FFV1 = Lorentz(name = 'FFV1',
               spins = [ 2, 2, 3 ],
               structure = 'Gamma(3,2,1)')

FFV2 = Lorentz(name = 'FFV2',
               spins = [ 2, 2, 3 ],
               structure = 'Gamma(3,2,-1)*ProjM(-1,1)')

FFV3 = Lorentz(name = 'FFV3',
               spins = [ 2, 2, 3 ],
               structure = 'Gamma(3,2,-1)*ProjM(-1,1) - 2*Gamma(3,2,-1)*ProjP(-1,1)')

FFV4 = Lorentz(name = 'FFV4',
               spins = [ 2, 2, 3 ],
               structure = 'Gamma(3,2,-1)*ProjM(-1,1) + 2*Gamma(3,2,-1)*ProjP(-1,1)')

FFV5 = Lorentz(name = 'FFV5',
               spins = [ 2, 2, 3 ],
               structure = 'Gamma(3,2,-1)*ProjM(-1,1) + 4*Gamma(3,2,-1)*ProjP(-1,1)')

VVS1 = Lorentz(name = 'VVS1',
               spins = [ 3, 3, 1 ],
               structure = 'Metric(1,2)')

VVV1 = Lorentz(name = 'VVV1',
               spins = [ 3, 3, 3 ],
               structure = 'P(3,1)*Metric(1,2) - P(3,2)*Metric(1,2) - P(2,1)*Metric(1,3) + P(2,3)*Metric(1,3) + P(1,2)*Metric(2,3) - P(1,3)*Metric(2,3)')

SSSS1 = Lorentz(name = 'SSSS1',
                spins = [ 1, 1, 1, 1 ],
                structure = '1')

SSSS2 = Lorentz(name = 'SSSS2',
                spins = [ 1, 1, 1, 1 ],
                structure = 'P(-2,3)*P(-2,4)*P(-1,1)*P(-1,2) + P(-2,2)*P(-2,4)*P(-1,1)*P(-1,3) + P(-2,2)*P(-2,3)*P(-1,1)*P(-1,4)')

VVSS1 = Lorentz(name = 'VVSS1',
                spins = [ 3, 3, 1, 1 ],
                structure = 'P(1,4)*P(2,3) + P(1,3)*P(2,4)')

VVSS2 = Lorentz(name = 'VVSS2',
                spins = [ 3, 3, 1, 1 ],
                structure = 'Metric(1,2)')

VVSS3 = Lorentz(name = 'VVSS3',
                spins = [ 3, 3, 1, 1 ],
                structure = 'P(-1,3)*P(-1,4)*Metric(1,2)')

VVSS4 = Lorentz(name = 'VVSS4',
                spins = [ 3, 3, 1, 1 ],
                structure = 'P(1,4)*P(2,3) + P(1,3)*P(2,4) - P(-1,3)*P(-1,4)*Metric(1,2)')

VVVS1 = Lorentz(name = 'VVVS1',
                spins = [ 3, 3, 3, 1 ],
                structure = 'P(2,4)*Metric(1,3) - P(1,4)*Metric(2,3)')

VVVV1 = Lorentz(name = 'VVVV1',
                spins = [ 3, 3, 3, 3 ],
                structure = 'Metric(1,4)*Metric(2,3) - Metric(1,3)*Metric(2,4)')

VVVV2 = Lorentz(name = 'VVVV2',
                spins = [ 3, 3, 3, 3 ],
                structure = 'Metric(1,4)*Metric(2,3) + Metric(1,3)*Metric(2,4)')

VVVV3 = Lorentz(name = 'VVVV3',
                spins = [ 3, 3, 3, 3 ],
                structure = 'Metric(1,2)*Metric(3,4)')

VVVV4 = Lorentz(name = 'VVVV4',
                spins = [ 3, 3, 3, 3 ],
                structure = 'Metric(1,4)*Metric(2,3) + Metric(1,3)*Metric(2,4) - 2*Metric(1,2)*Metric(3,4)')

VVVV5 = Lorentz(name = 'VVVV5',
                spins = [ 3, 3, 3, 3 ],
                structure = 'Metric(1,4)*Metric(2,3) - Metric(1,2)*Metric(3,4)')

VVVV6 = Lorentz(name = 'VVVV6',
                spins = [ 3, 3, 3, 3 ],
                structure = 'Metric(1,3)*Metric(2,4) - Metric(1,2)*Metric(3,4)')

VVVV7 = Lorentz(name = 'VVVV7',
                spins = [ 3, 3, 3, 3 ],
                structure = 'Metric(1,4)*Metric(2,3) - (Metric(1,3)*Metric(2,4))/2. - (Metric(1,2)*Metric(3,4))/2.')

VVVV8 = Lorentz(name = 'VVVV8',
                spins = [ 3, 3, 3, 3 ],
                structure = 'Metric(1,4)*Metric(2,3) + Metric(1,3)*Metric(2,4) + Metric(1,2)*Metric(3,4)')

VVSSS1 = Lorentz(name = 'VVSSS1',
                 spins = [ 3, 3, 1, 1, 1 ],
                 structure = 'P(1,4)*P(2,3) + P(1,5)*P(2,3) + P(1,3)*P(2,4) + P(1,5)*P(2,4) + P(1,3)*P(2,5) + P(1,4)*P(2,5)')

VVSSS2 = Lorentz(name = 'VVSSS2',
                 spins = [ 3, 3, 1, 1, 1 ],
                 structure = 'P(1,4)*P(2,3) + P(1,5)*P(2,3) + P(1,3)*P(2,4) + P(1,5)*P(2,4) + P(1,3)*P(2,5) + P(1,4)*P(2,5) - P(-1,3)*P(-1,4)*Metric(1,2) - P(-1,3)*P(-1,5)*Metric(1,2) - P(-1,4)*P(-1,5)*Metric(1,2)')

VVSSS3 = Lorentz(name = 'VVSSS3',
                 spins = [ 3, 3, 1, 1, 1 ],
                 structure = 'P(-1,3)*P(-1,4)*Metric(1,2) + P(-1,3)*P(-1,5)*Metric(1,2) + P(-1,4)*P(-1,5)*Metric(1,2)')

VVVSS1 = Lorentz(name = 'VVVSS1',
                 spins = [ 3, 3, 3, 1, 1 ],
                 structure = 'P(2,4)*Metric(1,3) + P(2,5)*Metric(1,3) - P(1,4)*Metric(2,3) - P(1,5)*Metric(2,3)')

VVVVS1 = Lorentz(name = 'VVVVS1',
                 spins = [ 3, 3, 3, 3, 1 ],
                 structure = 'Metric(1,4)*Metric(2,3) + Metric(1,3)*Metric(2,4)')

VVVVS2 = Lorentz(name = 'VVVVS2',
                 spins = [ 3, 3, 3, 3, 1 ],
                 structure = 'Metric(1,2)*Metric(3,4)')

VVVVS3 = Lorentz(name = 'VVVVS3',
                 spins = [ 3, 3, 3, 3, 1 ],
                 structure = 'Metric(1,4)*Metric(2,3) + Metric(1,3)*Metric(2,4) + Metric(1,2)*Metric(3,4)')

VVSSSS1 = Lorentz(name = 'VVSSSS1',
                  spins = [ 3, 3, 1, 1, 1, 1 ],
                  structure = 'P(1,4)*P(2,3) + P(1,5)*P(2,3) + P(1,6)*P(2,3) + P(1,3)*P(2,4) + P(1,5)*P(2,4) + P(1,6)*P(2,4) + P(1,3)*P(2,5) + P(1,4)*P(2,5) + P(1,6)*P(2,5) + P(1,3)*P(2,6) + P(1,4)*P(2,6) + P(1,5)*P(2,6)')

VVSSSS2 = Lorentz(name = 'VVSSSS2',
                  spins = [ 3, 3, 1, 1, 1, 1 ],
                  structure = 'P(1,4)*P(2,3) + P(1,5)*P(2,3) + P(1,6)*P(2,3) + P(1,3)*P(2,4) + P(1,5)*P(2,4) + P(1,6)*P(2,4) + P(1,3)*P(2,5) + P(1,4)*P(2,5) + P(1,6)*P(2,5) + P(1,3)*P(2,6) + P(1,4)*P(2,6) + P(1,5)*P(2,6) - P(-1,3)*P(-1,4)*Metric(1,2) - P(-1,3)*P(-1,5)*Metric(1,2) - P(-1,4)*P(-1,5)*Metric(1,2) - P(-1,3)*P(-1,6)*Metric(1,2) - P(-1,4)*P(-1,6)*Metric(1,2) - P(-1,5)*P(-1,6)*Metric(1,2)')

VVSSSS3 = Lorentz(name = 'VVSSSS3',
                  spins = [ 3, 3, 1, 1, 1, 1 ],
                  structure = 'P(-1,3)*P(-1,4)*Metric(1,2) + P(-1,3)*P(-1,5)*Metric(1,2) + P(-1,4)*P(-1,5)*Metric(1,2) + P(-1,3)*P(-1,6)*Metric(1,2) + P(-1,4)*P(-1,6)*Metric(1,2) + P(-1,5)*P(-1,6)*Metric(1,2)')

VVVSSS1 = Lorentz(name = 'VVVSSS1',
                  spins = [ 3, 3, 3, 1, 1, 1 ],
                  structure = 'P(2,4)*Metric(1,3) + P(2,5)*Metric(1,3) + P(2,6)*Metric(1,3) - P(1,4)*Metric(2,3) - P(1,5)*Metric(2,3) - P(1,6)*Metric(2,3)')

VVVVSS1 = Lorentz(name = 'VVVVSS1',
                  spins = [ 3, 3, 3, 3, 1, 1 ],
                  structure = 'Metric(1,4)*Metric(2,3) + Metric(1,3)*Metric(2,4)')

VVVVSS2 = Lorentz(name = 'VVVVSS2',
                  spins = [ 3, 3, 3, 3, 1, 1 ],
                  structure = 'Metric(1,2)*Metric(3,4)')

VVVVSS3 = Lorentz(name = 'VVVVSS3',
                  spins = [ 3, 3, 3, 3, 1, 1 ],
                  structure = 'Metric(1,4)*Metric(2,3) + Metric(1,3)*Metric(2,4) + Metric(1,2)*Metric(3,4)')

VVVSSSS1 = Lorentz(name = 'VVVSSSS1',
                   spins = [ 3, 3, 3, 1, 1, 1, 1 ],
                   structure = 'P(2,4)*Metric(1,3) + P(2,5)*Metric(1,3) + P(2,6)*Metric(1,3) + P(2,7)*Metric(1,3) - P(1,4)*Metric(2,3) - P(1,5)*Metric(2,3) - P(1,6)*Metric(2,3) - P(1,7)*Metric(2,3)')

VVVVSSS1 = Lorentz(name = 'VVVVSSS1',
                   spins = [ 3, 3, 3, 3, 1, 1, 1 ],
                   structure = 'Metric(1,4)*Metric(2,3) + Metric(1,3)*Metric(2,4)')

VVVVSSS2 = Lorentz(name = 'VVVVSSS2',
                   spins = [ 3, 3, 3, 3, 1, 1, 1 ],
                   structure = 'Metric(1,2)*Metric(3,4)')

VVVVSSS3 = Lorentz(name = 'VVVVSSS3',
                   spins = [ 3, 3, 3, 3, 1, 1, 1 ],
                   structure = 'Metric(1,4)*Metric(2,3) + Metric(1,3)*Metric(2,4) + Metric(1,2)*Metric(3,4)')

VVVVSSSS1 = Lorentz(name = 'VVVVSSSS1',
                    spins = [ 3, 3, 3, 3, 1, 1, 1, 1 ],
                    structure = 'Metric(1,4)*Metric(2,3) + Metric(1,3)*Metric(2,4)')

VVVVSSSS2 = Lorentz(name = 'VVVVSSSS2',
                    spins = [ 3, 3, 3, 3, 1, 1, 1, 1 ],
                    structure = 'Metric(1,2)*Metric(3,4)')

VVVVSSSS3 = Lorentz(name = 'VVVVSSSS3',
                    spins = [ 3, 3, 3, 3, 1, 1, 1, 1 ],
                    structure = 'Metric(1,4)*Metric(2,3) + Metric(1,3)*Metric(2,4) + Metric(1,2)*Metric(3,4)')

