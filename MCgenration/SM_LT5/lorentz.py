# This file was automatically created by FeynRules 2.3.14
# Mathematica version: 10.3.0 for Mac OS X x86 (64-bit) (October 9, 2015)
# Date: Wed 19 Jul 2017 13:17:13


from object_library import all_lorentz, Lorentz

from function_library import complexconjugate, re, im, csc, sec, acsc, asec, cot
try:
   import form_factors as ForFac 
except ImportError:
   pass


UUV1 = Lorentz(name = 'UUV1',
               spins = [ -1, -1, 3 ],
               structure = 'P(3,2) + P(3,3)')

SSS1 = Lorentz(name = 'SSS1',
               spins = [ 1, 1, 1 ],
               structure = '1')

FFS1 = Lorentz(name = 'FFS1',
               spins = [ 2, 2, 1 ],
               structure = 'ProjM(2,1) + ProjP(2,1)')

FFV1 = Lorentz(name = 'FFV1',
               spins = [ 2, 2, 3 ],
               structure = 'Gamma(3,2,1)')

FFV2 = Lorentz(name = 'FFV2',
               spins = [ 2, 2, 3 ],
               structure = 'Gamma(3,2,-1)*ProjM(-1,1)')

FFV3 = Lorentz(name = 'FFV3',
               spins = [ 2, 2, 3 ],
               structure = 'Gamma(3,2,-1)*ProjP(-1,1)')

FFV4 = Lorentz(name = 'FFV4',
               spins = [ 2, 2, 3 ],
               structure = 'Gamma(3,2,-1)*ProjM(-1,1) - 2*Gamma(3,2,-1)*ProjP(-1,1)')

FFV5 = Lorentz(name = 'FFV5',
               spins = [ 2, 2, 3 ],
               structure = 'Gamma(3,2,-1)*ProjM(-1,1) + 2*Gamma(3,2,-1)*ProjP(-1,1)')

VVS1 = Lorentz(name = 'VVS1',
               spins = [ 3, 3, 1 ],
               structure = 'Metric(1,2)')

VVV1 = Lorentz(name = 'VVV1',
               spins = [ 3, 3, 3 ],
               structure = 'P(3,1)*Metric(1,2) - P(3,2)*Metric(1,2) - P(2,1)*Metric(1,3) + P(2,3)*Metric(1,3) + P(1,2)*Metric(2,3) - P(1,3)*Metric(2,3)')

SSSS1 = Lorentz(name = 'SSSS1',
                spins = [ 1, 1, 1, 1 ],
                structure = '1')

VVSS1 = Lorentz(name = 'VVSS1',
                spins = [ 3, 3, 1, 1 ],
                structure = 'Metric(1,2)')

VVVV1 = Lorentz(name = 'VVVV1',
                spins = [ 3, 3, 3, 3 ],
                structure = 'P(1,4)*P(2,3)*P(3,2)*P(4,1) - P(-1,1)*P(-1,4)*P(2,3)*P(3,2)*Metric(1,4) - P(-1,2)*P(-1,3)*P(1,4)*P(4,1)*Metric(2,3) + P(-2,2)*P(-2,3)*P(-1,1)*P(-1,4)*Metric(1,4)*Metric(2,3)')

VVVV2 = Lorentz(name = 'VVVV2',
                spins = [ 3, 3, 3, 3 ],
                structure = 'Metric(1,4)*Metric(2,3) - Metric(1,3)*Metric(2,4)')

VVVV3 = Lorentz(name = 'VVVV3',
                spins = [ 3, 3, 3, 3 ],
                structure = 'P(1,4)*P(2,3)*P(3,2)*P(4,1) + P(1,3)*P(2,4)*P(3,1)*P(4,2) - P(-1,1)*P(-1,3)*P(2,4)*P(4,2)*Metric(1,3) - P(-1,1)*P(-1,4)*P(2,3)*P(3,2)*Metric(1,4) - P(-1,2)*P(-1,3)*P(1,4)*P(4,1)*Metric(2,3) + P(-2,2)*P(-2,3)*P(-1,1)*P(-1,4)*Metric(1,4)*Metric(2,3) - P(-1,2)*P(-1,4)*P(1,3)*P(3,1)*Metric(2,4) + P(-2,2)*P(-2,4)*P(-1,1)*P(-1,3)*Metric(1,3)*Metric(2,4)')

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
                structure = 'P(1,2)*P(2,1)*P(3,4)*P(4,3) - P(-1,1)*P(-1,2)*P(3,4)*P(4,3)*Metric(1,2) - P(-1,3)*P(-1,4)*P(1,2)*P(2,1)*Metric(3,4) + P(-2,3)*P(-2,4)*P(-1,1)*P(-1,2)*Metric(1,2)*Metric(3,4)')

VVVV9 = Lorentz(name = 'VVVV9',
                spins = [ 3, 3, 3, 3 ],
                structure = 'P(1,4)*P(2,3)*P(3,2)*P(4,1) + P(1,3)*P(2,4)*P(3,1)*P(4,2) + P(1,2)*P(2,1)*P(3,4)*P(4,3) - P(-1,1)*P(-1,2)*P(3,4)*P(4,3)*Metric(1,2) - P(-1,1)*P(-1,3)*P(2,4)*P(4,2)*Metric(1,3) - P(-1,1)*P(-1,4)*P(2,3)*P(3,2)*Metric(1,4) - P(-1,2)*P(-1,3)*P(1,4)*P(4,1)*Metric(2,3) + P(-2,2)*P(-2,3)*P(-1,1)*P(-1,4)*Metric(1,4)*Metric(2,3) - P(-1,2)*P(-1,4)*P(1,3)*P(3,1)*Metric(2,4) + P(-2,2)*P(-2,4)*P(-1,1)*P(-1,3)*Metric(1,3)*Metric(2,4) - P(-1,3)*P(-1,4)*P(1,2)*P(2,1)*Metric(3,4) + P(-2,3)*P(-2,4)*P(-1,1)*P(-1,2)*Metric(1,2)*Metric(3,4)')

VVVVV1 = Lorentz(name = 'VVVVV1',
                 spins = [ 3, 3, 3, 3, 3 ],
                 structure = 'P(2,5)*P(4,1)*P(5,2)*Metric(1,3) - P(2,5)*P(4,3)*P(5,2)*Metric(1,3) - P(2,5)*P(3,1)*P(5,2)*Metric(1,4) + P(2,5)*P(3,4)*P(5,2)*Metric(1,4) + P(1,5)*P(4,2)*P(5,1)*Metric(2,3) - P(1,5)*P(4,3)*P(5,1)*Metric(2,3) - P(-1,1)*P(-1,5)*P(4,2)*Metric(1,5)*Metric(2,3) + P(-1,1)*P(-1,5)*P(4,3)*Metric(1,5)*Metric(2,3) - P(1,5)*P(3,2)*P(5,1)*Metric(2,4) + P(1,5)*P(3,4)*P(5,1)*Metric(2,4) + P(-1,1)*P(-1,5)*P(3,2)*Metric(1,5)*Metric(2,4) - P(-1,1)*P(-1,5)*P(3,4)*Metric(1,5)*Metric(2,4) - P(-1,2)*P(-1,5)*P(4,1)*Metric(1,3)*Metric(2,5) + P(-1,2)*P(-1,5)*P(4,3)*Metric(1,3)*Metric(2,5) + P(-1,2)*P(-1,5)*P(3,1)*Metric(1,4)*Metric(2,5) - P(-1,2)*P(-1,5)*P(3,4)*Metric(1,4)*Metric(2,5) + P(1,5)*P(2,3)*P(5,1)*Metric(3,4) - P(1,5)*P(2,4)*P(5,1)*Metric(3,4) + P(1,3)*P(2,5)*P(5,2)*Metric(3,4) - P(1,4)*P(2,5)*P(5,2)*Metric(3,4) - P(-1,1)*P(-1,5)*P(2,3)*Metric(1,5)*Metric(3,4) + P(-1,1)*P(-1,5)*P(2,4)*Metric(1,5)*Metric(3,4) - P(-1,2)*P(-1,5)*P(1,3)*Metric(2,5)*Metric(3,4) + P(-1,2)*P(-1,5)*P(1,4)*Metric(2,5)*Metric(3,4)')

VVVVV2 = Lorentz(name = 'VVVVV2',
                 spins = [ 3, 3, 3, 3, 3 ],
                 structure = 'P(1,5)*P(4,2)*P(5,1)*Metric(2,3) - P(1,5)*P(4,3)*P(5,1)*Metric(2,3) + P(1,4)*P(4,1)*P(5,2)*Metric(2,3) - P(1,4)*P(4,1)*P(5,3)*Metric(2,3) - P(-1,1)*P(-1,4)*P(5,2)*Metric(1,4)*Metric(2,3) + P(-1,1)*P(-1,4)*P(5,3)*Metric(1,4)*Metric(2,3) - P(-1,1)*P(-1,5)*P(4,2)*Metric(1,5)*Metric(2,3) + P(-1,1)*P(-1,5)*P(4,3)*Metric(1,5)*Metric(2,3) - P(1,5)*P(3,2)*P(5,1)*Metric(2,4) + P(1,5)*P(3,4)*P(5,1)*Metric(2,4) + P(-1,1)*P(-1,5)*P(3,2)*Metric(1,5)*Metric(2,4) - P(-1,1)*P(-1,5)*P(3,4)*Metric(1,5)*Metric(2,4) - P(1,4)*P(3,2)*P(4,1)*Metric(2,5) + P(1,4)*P(3,5)*P(4,1)*Metric(2,5) + P(-1,1)*P(-1,4)*P(3,2)*Metric(1,4)*Metric(2,5) - P(-1,1)*P(-1,4)*P(3,5)*Metric(1,4)*Metric(2,5) + P(1,5)*P(2,3)*P(5,1)*Metric(3,4) - P(1,5)*P(2,4)*P(5,1)*Metric(3,4) - P(-1,1)*P(-1,5)*P(2,3)*Metric(1,5)*Metric(3,4) + P(-1,1)*P(-1,5)*P(2,4)*Metric(1,5)*Metric(3,4) + P(1,4)*P(2,3)*P(4,1)*Metric(3,5) - P(1,4)*P(2,5)*P(4,1)*Metric(3,5) - P(-1,1)*P(-1,4)*P(2,3)*Metric(1,4)*Metric(3,5) + P(-1,1)*P(-1,4)*P(2,5)*Metric(1,4)*Metric(3,5)')

VVVVV3 = Lorentz(name = 'VVVVV3',
                 spins = [ 3, 3, 3, 3, 3 ],
                 structure = 'P(1,2)*P(2,1)*P(5,3)*Metric(3,4) - P(1,2)*P(2,1)*P(5,4)*Metric(3,4) - P(-1,1)*P(-1,2)*P(5,3)*Metric(1,2)*Metric(3,4) + P(-1,1)*P(-1,2)*P(5,4)*Metric(1,2)*Metric(3,4) - P(1,2)*P(2,1)*P(4,3)*Metric(3,5) + P(1,2)*P(2,1)*P(4,5)*Metric(3,5) + P(-1,1)*P(-1,2)*P(4,3)*Metric(1,2)*Metric(3,5) - P(-1,1)*P(-1,2)*P(4,5)*Metric(1,2)*Metric(3,5) + P(1,2)*P(2,1)*P(3,4)*Metric(4,5) - P(1,2)*P(2,1)*P(3,5)*Metric(4,5) - P(-1,1)*P(-1,2)*P(3,4)*Metric(1,2)*Metric(4,5) + P(-1,1)*P(-1,2)*P(3,5)*Metric(1,2)*Metric(4,5)')

VVVVV4 = Lorentz(name = 'VVVVV4',
                 spins = [ 3, 3, 3, 3, 3 ],
                 structure = 'P(2,3)*P(3,2)*P(5,1)*Metric(1,4) - P(2,3)*P(3,2)*P(5,4)*Metric(1,4) - P(2,3)*P(3,2)*P(4,1)*Metric(1,5) + P(2,3)*P(3,2)*P(4,5)*Metric(1,5) - P(-1,2)*P(-1,3)*P(5,1)*Metric(1,4)*Metric(2,3) + P(-1,2)*P(-1,3)*P(5,4)*Metric(1,4)*Metric(2,3) + P(-1,2)*P(-1,3)*P(4,1)*Metric(1,5)*Metric(2,3) - P(-1,2)*P(-1,3)*P(4,5)*Metric(1,5)*Metric(2,3) + P(1,3)*P(3,1)*P(5,2)*Metric(2,4) - P(1,3)*P(3,1)*P(5,4)*Metric(2,4) - P(-1,1)*P(-1,3)*P(5,2)*Metric(1,3)*Metric(2,4) + P(-1,1)*P(-1,3)*P(5,4)*Metric(1,3)*Metric(2,4) - P(1,3)*P(3,1)*P(4,2)*Metric(2,5) + P(1,3)*P(3,1)*P(4,5)*Metric(2,5) + P(-1,1)*P(-1,3)*P(4,2)*Metric(1,3)*Metric(2,5) - P(-1,1)*P(-1,3)*P(4,5)*Metric(1,3)*Metric(2,5) + P(1,2)*P(2,1)*P(5,3)*Metric(3,4) - P(1,2)*P(2,1)*P(5,4)*Metric(3,4) - P(-1,1)*P(-1,2)*P(5,3)*Metric(1,2)*Metric(3,4) + P(-1,1)*P(-1,2)*P(5,4)*Metric(1,2)*Metric(3,4) - P(1,2)*P(2,1)*P(4,3)*Metric(3,5) + P(1,2)*P(2,1)*P(4,5)*Metric(3,5) + P(-1,1)*P(-1,2)*P(4,3)*Metric(1,2)*Metric(3,5) - P(-1,1)*P(-1,2)*P(4,5)*Metric(1,2)*Metric(3,5) + P(1,3)*P(2,4)*P(3,1)*Metric(4,5) - P(1,3)*P(2,5)*P(3,1)*Metric(4,5) + P(1,4)*P(2,3)*P(3,2)*Metric(4,5) - P(1,5)*P(2,3)*P(3,2)*Metric(4,5) + P(1,2)*P(2,1)*P(3,4)*Metric(4,5) - P(1,2)*P(2,1)*P(3,5)*Metric(4,5) - P(-1,1)*P(-1,2)*P(3,4)*Metric(1,2)*Metric(4,5) + P(-1,1)*P(-1,2)*P(3,5)*Metric(1,2)*Metric(4,5) - P(-1,1)*P(-1,3)*P(2,4)*Metric(1,3)*Metric(4,5) + P(-1,1)*P(-1,3)*P(2,5)*Metric(1,3)*Metric(4,5) - P(-1,2)*P(-1,3)*P(1,4)*Metric(2,3)*Metric(4,5) + P(-1,2)*P(-1,3)*P(1,5)*Metric(2,3)*Metric(4,5)')

VVVVV5 = Lorentz(name = 'VVVVV5',
                 spins = [ 3, 3, 3, 3, 3 ],
                 structure = 'P(3,1)*P(4,5)*P(5,4)*Metric(1,2) - P(3,2)*P(4,5)*P(5,4)*Metric(1,2) - P(2,1)*P(4,5)*P(5,4)*Metric(1,3) + P(2,3)*P(4,5)*P(5,4)*Metric(1,3) + P(1,2)*P(4,5)*P(5,4)*Metric(2,3) - P(1,3)*P(4,5)*P(5,4)*Metric(2,3) - P(-1,4)*P(-1,5)*P(3,1)*Metric(1,2)*Metric(4,5) + P(-1,4)*P(-1,5)*P(3,2)*Metric(1,2)*Metric(4,5) + P(-1,4)*P(-1,5)*P(2,1)*Metric(1,3)*Metric(4,5) - P(-1,4)*P(-1,5)*P(2,3)*Metric(1,3)*Metric(4,5) - P(-1,4)*P(-1,5)*P(1,2)*Metric(2,3)*Metric(4,5) + P(-1,4)*P(-1,5)*P(1,3)*Metric(2,3)*Metric(4,5)')

VVVVV6 = Lorentz(name = 'VVVVV6',
                 spins = [ 3, 3, 3, 3, 3 ],
                 structure = 'P(3,4)*P(4,3)*P(5,1)*Metric(1,2) - P(3,4)*P(4,3)*P(5,2)*Metric(1,2) + P(3,5)*P(4,1)*P(5,3)*Metric(1,2) - P(3,5)*P(4,2)*P(5,3)*Metric(1,2) + P(3,1)*P(4,5)*P(5,4)*Metric(1,2) - P(3,2)*P(4,5)*P(5,4)*Metric(1,2) - P(2,1)*P(4,5)*P(5,4)*Metric(1,3) + P(2,3)*P(4,5)*P(5,4)*Metric(1,3) - P(2,1)*P(3,5)*P(5,3)*Metric(1,4) + P(2,4)*P(3,5)*P(5,3)*Metric(1,4) - P(2,1)*P(3,4)*P(4,3)*Metric(1,5) + P(2,5)*P(3,4)*P(4,3)*Metric(1,5) + P(1,2)*P(4,5)*P(5,4)*Metric(2,3) - P(1,3)*P(4,5)*P(5,4)*Metric(2,3) + P(1,2)*P(3,5)*P(5,3)*Metric(2,4) - P(1,4)*P(3,5)*P(5,3)*Metric(2,4) + P(1,2)*P(3,4)*P(4,3)*Metric(2,5) - P(1,5)*P(3,4)*P(4,3)*Metric(2,5) - P(-1,3)*P(-1,4)*P(5,1)*Metric(1,2)*Metric(3,4) + P(-1,3)*P(-1,4)*P(5,2)*Metric(1,2)*Metric(3,4) + P(-1,3)*P(-1,4)*P(2,1)*Metric(1,5)*Metric(3,4) - P(-1,3)*P(-1,4)*P(2,5)*Metric(1,5)*Metric(3,4) - P(-1,3)*P(-1,4)*P(1,2)*Metric(2,5)*Metric(3,4) + P(-1,3)*P(-1,4)*P(1,5)*Metric(2,5)*Metric(3,4) - P(-1,3)*P(-1,5)*P(4,1)*Metric(1,2)*Metric(3,5) + P(-1,3)*P(-1,5)*P(4,2)*Metric(1,2)*Metric(3,5) + P(-1,3)*P(-1,5)*P(2,1)*Metric(1,4)*Metric(3,5) - P(-1,3)*P(-1,5)*P(2,4)*Metric(1,4)*Metric(3,5) - P(-1,3)*P(-1,5)*P(1,2)*Metric(2,4)*Metric(3,5) + P(-1,3)*P(-1,5)*P(1,4)*Metric(2,4)*Metric(3,5) - P(-1,4)*P(-1,5)*P(3,1)*Metric(1,2)*Metric(4,5) + P(-1,4)*P(-1,5)*P(3,2)*Metric(1,2)*Metric(4,5) + P(-1,4)*P(-1,5)*P(2,1)*Metric(1,3)*Metric(4,5) - P(-1,4)*P(-1,5)*P(2,3)*Metric(1,3)*Metric(4,5) - P(-1,4)*P(-1,5)*P(1,2)*Metric(2,3)*Metric(4,5) + P(-1,4)*P(-1,5)*P(1,3)*Metric(2,3)*Metric(4,5)')

VVVVVV1 = Lorentz(name = 'VVVVVV1',
                  spins = [ 3, 3, 3, 3, 3, 3 ],
                  structure = 'P(1,6)*P(6,1)*Metric(2,5)*Metric(3,4) - P(-1,1)*P(-1,6)*Metric(1,6)*Metric(2,5)*Metric(3,4) + P(1,6)*P(6,1)*Metric(2,4)*Metric(3,5) - P(-1,1)*P(-1,6)*Metric(1,6)*Metric(2,4)*Metric(3,5) - 2*P(1,6)*P(6,1)*Metric(2,3)*Metric(4,5) + 2*P(-1,1)*P(-1,6)*Metric(1,6)*Metric(2,3)*Metric(4,5)')

VVVVVV2 = Lorentz(name = 'VVVVVV2',
                  spins = [ 3, 3, 3, 3, 3, 3 ],
                  structure = 'P(3,6)*P(6,3)*Metric(1,5)*Metric(2,4) + P(3,6)*P(6,3)*Metric(1,4)*Metric(2,5) + P(2,6)*P(6,2)*Metric(1,5)*Metric(3,4) + P(1,6)*P(6,1)*Metric(2,5)*Metric(3,4) - P(-1,1)*P(-1,6)*Metric(1,6)*Metric(2,5)*Metric(3,4) - P(-1,2)*P(-1,6)*Metric(1,5)*Metric(2,6)*Metric(3,4) + P(2,6)*P(6,2)*Metric(1,4)*Metric(3,5) + P(1,6)*P(6,1)*Metric(2,4)*Metric(3,5) - P(-1,1)*P(-1,6)*Metric(1,6)*Metric(2,4)*Metric(3,5) - P(-1,2)*P(-1,6)*Metric(1,4)*Metric(2,6)*Metric(3,5) - P(-1,3)*P(-1,6)*Metric(1,5)*Metric(2,4)*Metric(3,6) - P(-1,3)*P(-1,6)*Metric(1,4)*Metric(2,5)*Metric(3,6) - 2*P(3,6)*P(6,3)*Metric(1,2)*Metric(4,5) - 2*P(2,6)*P(6,2)*Metric(1,3)*Metric(4,5) - 2*P(1,6)*P(6,1)*Metric(2,3)*Metric(4,5) + 2*P(-1,1)*P(-1,6)*Metric(1,6)*Metric(2,3)*Metric(4,5) + 2*P(-1,2)*P(-1,6)*Metric(1,3)*Metric(2,6)*Metric(4,5) + 2*P(-1,3)*P(-1,6)*Metric(1,2)*Metric(3,6)*Metric(4,5)')

VVVVVV3 = Lorentz(name = 'VVVVVV3',
                  spins = [ 3, 3, 3, 3, 3, 3 ],
                  structure = 'P(2,6)*P(6,2)*Metric(1,5)*Metric(3,4) + P(2,5)*P(5,2)*Metric(1,6)*Metric(3,4) + P(1,6)*P(6,1)*Metric(2,5)*Metric(3,4) - P(-1,2)*P(-1,5)*Metric(1,6)*Metric(2,5)*Metric(3,4) - P(-1,1)*P(-1,6)*Metric(1,6)*Metric(2,5)*Metric(3,4) + P(1,5)*P(5,1)*Metric(2,6)*Metric(3,4) - P(-1,1)*P(-1,5)*Metric(1,5)*Metric(2,6)*Metric(3,4) - P(-1,2)*P(-1,6)*Metric(1,5)*Metric(2,6)*Metric(3,4) - (P(2,6)*P(6,2)*Metric(1,4)*Metric(3,5))/2. - (P(1,6)*P(6,1)*Metric(2,4)*Metric(3,5))/2. + (P(-1,1)*P(-1,6)*Metric(1,6)*Metric(2,4)*Metric(3,5))/2. + (P(-1,2)*P(-1,6)*Metric(1,4)*Metric(2,6)*Metric(3,5))/2. - (P(2,5)*P(5,2)*Metric(1,4)*Metric(3,6))/2. - (P(1,5)*P(5,1)*Metric(2,4)*Metric(3,6))/2. + (P(-1,1)*P(-1,5)*Metric(1,5)*Metric(2,4)*Metric(3,6))/2. + (P(-1,2)*P(-1,5)*Metric(1,4)*Metric(2,5)*Metric(3,6))/2. - (P(2,6)*P(6,2)*Metric(1,3)*Metric(4,5))/2. - (P(1,6)*P(6,1)*Metric(2,3)*Metric(4,5))/2. + (P(-1,1)*P(-1,6)*Metric(1,6)*Metric(2,3)*Metric(4,5))/2. + (P(-1,2)*P(-1,6)*Metric(1,3)*Metric(2,6)*Metric(4,5))/2. - (P(2,5)*P(5,2)*Metric(1,3)*Metric(4,6))/2. - (P(1,5)*P(5,1)*Metric(2,3)*Metric(4,6))/2. + (P(-1,1)*P(-1,5)*Metric(1,5)*Metric(2,3)*Metric(4,6))/2. + (P(-1,2)*P(-1,5)*Metric(1,3)*Metric(2,5)*Metric(4,6))/2.')

VVVVVV4 = Lorentz(name = 'VVVVVV4',
                  spins = [ 3, 3, 3, 3, 3, 3 ],
                  structure = 'P(1,6)*P(6,1)*Metric(2,5)*Metric(3,4) - P(-1,1)*P(-1,6)*Metric(1,6)*Metric(2,5)*Metric(3,4) + P(1,5)*P(5,1)*Metric(2,6)*Metric(3,4) - P(-1,1)*P(-1,5)*Metric(1,5)*Metric(2,6)*Metric(3,4) + P(1,6)*P(6,1)*Metric(2,4)*Metric(3,5) - P(-1,1)*P(-1,6)*Metric(1,6)*Metric(2,4)*Metric(3,5) + P(1,4)*P(4,1)*Metric(2,6)*Metric(3,5) - P(-1,1)*P(-1,4)*Metric(1,4)*Metric(2,6)*Metric(3,5) + P(1,5)*P(5,1)*Metric(2,4)*Metric(3,6) - P(-1,1)*P(-1,5)*Metric(1,5)*Metric(2,4)*Metric(3,6) + P(1,4)*P(4,1)*Metric(2,5)*Metric(3,6) - P(-1,1)*P(-1,4)*Metric(1,4)*Metric(2,5)*Metric(3,6) - 2*P(1,6)*P(6,1)*Metric(2,3)*Metric(4,5) + 2*P(-1,1)*P(-1,6)*Metric(1,6)*Metric(2,3)*Metric(4,5) - 2*P(1,5)*P(5,1)*Metric(2,3)*Metric(4,6) + 2*P(-1,1)*P(-1,5)*Metric(1,5)*Metric(2,3)*Metric(4,6) - 2*P(1,4)*P(4,1)*Metric(2,3)*Metric(5,6) + 2*P(-1,1)*P(-1,4)*Metric(1,4)*Metric(2,3)*Metric(5,6)')

VVVVVV5 = Lorentz(name = 'VVVVVV5',
                  spins = [ 3, 3, 3, 3, 3, 3 ],
                  structure = 'P(2,3)*P(3,2)*Metric(1,6)*Metric(4,5) - P(-1,2)*P(-1,3)*Metric(1,6)*Metric(2,3)*Metric(4,5) + P(1,3)*P(3,1)*Metric(2,6)*Metric(4,5) - P(-1,1)*P(-1,3)*Metric(1,3)*Metric(2,6)*Metric(4,5) + P(1,2)*P(2,1)*Metric(3,6)*Metric(4,5) - P(-1,1)*P(-1,2)*Metric(1,2)*Metric(3,6)*Metric(4,5) - (P(2,3)*P(3,2)*Metric(1,5)*Metric(4,6))/2. + (P(-1,2)*P(-1,3)*Metric(1,5)*Metric(2,3)*Metric(4,6))/2. - (P(1,3)*P(3,1)*Metric(2,5)*Metric(4,6))/2. + (P(-1,1)*P(-1,3)*Metric(1,3)*Metric(2,5)*Metric(4,6))/2. - (P(1,2)*P(2,1)*Metric(3,5)*Metric(4,6))/2. + (P(-1,1)*P(-1,2)*Metric(1,2)*Metric(3,5)*Metric(4,6))/2. - (P(2,3)*P(3,2)*Metric(1,4)*Metric(5,6))/2. + (P(-1,2)*P(-1,3)*Metric(1,4)*Metric(2,3)*Metric(5,6))/2. - (P(1,3)*P(3,1)*Metric(2,4)*Metric(5,6))/2. + (P(-1,1)*P(-1,3)*Metric(1,3)*Metric(2,4)*Metric(5,6))/2. - (P(1,2)*P(2,1)*Metric(3,4)*Metric(5,6))/2. + (P(-1,1)*P(-1,2)*Metric(1,2)*Metric(3,4)*Metric(5,6))/2.')

VVVVVV6 = Lorentz(name = 'VVVVVV6',
                  spins = [ 3, 3, 3, 3, 3, 3 ],
                  structure = 'P(1,2)*P(2,1)*Metric(3,6)*Metric(4,5) - P(-1,1)*P(-1,2)*Metric(1,2)*Metric(3,6)*Metric(4,5) + P(1,2)*P(2,1)*Metric(3,5)*Metric(4,6) - P(-1,1)*P(-1,2)*Metric(1,2)*Metric(3,5)*Metric(4,6) - 2*P(1,2)*P(2,1)*Metric(3,4)*Metric(5,6) + 2*P(-1,1)*P(-1,2)*Metric(1,2)*Metric(3,4)*Metric(5,6)')

VVVVVV7 = Lorentz(name = 'VVVVVV7',
                  spins = [ 3, 3, 3, 3, 3, 3 ],
                  structure = 'P(3,4)*P(4,3)*Metric(1,6)*Metric(2,5) + P(3,4)*P(4,3)*Metric(1,5)*Metric(2,6) - P(-1,3)*P(-1,4)*Metric(1,6)*Metric(2,5)*Metric(3,4) - P(-1,3)*P(-1,4)*Metric(1,5)*Metric(2,6)*Metric(3,4) + P(2,4)*P(4,2)*Metric(1,6)*Metric(3,5) - P(-1,2)*P(-1,4)*Metric(1,6)*Metric(2,4)*Metric(3,5) + P(1,4)*P(4,1)*Metric(2,6)*Metric(3,5) - P(-1,1)*P(-1,4)*Metric(1,4)*Metric(2,6)*Metric(3,5) + P(2,4)*P(4,2)*Metric(1,5)*Metric(3,6) - P(-1,2)*P(-1,4)*Metric(1,5)*Metric(2,4)*Metric(3,6) + P(1,4)*P(4,1)*Metric(2,5)*Metric(3,6) - P(-1,1)*P(-1,4)*Metric(1,4)*Metric(2,5)*Metric(3,6) + P(2,3)*P(3,2)*Metric(1,6)*Metric(4,5) - P(-1,2)*P(-1,3)*Metric(1,6)*Metric(2,3)*Metric(4,5) + P(1,3)*P(3,1)*Metric(2,6)*Metric(4,5) - P(-1,1)*P(-1,3)*Metric(1,3)*Metric(2,6)*Metric(4,5) + P(1,2)*P(2,1)*Metric(3,6)*Metric(4,5) - P(-1,1)*P(-1,2)*Metric(1,2)*Metric(3,6)*Metric(4,5) + P(2,3)*P(3,2)*Metric(1,5)*Metric(4,6) - P(-1,2)*P(-1,3)*Metric(1,5)*Metric(2,3)*Metric(4,6) + P(1,3)*P(3,1)*Metric(2,5)*Metric(4,6) - P(-1,1)*P(-1,3)*Metric(1,3)*Metric(2,5)*Metric(4,6) + P(1,2)*P(2,1)*Metric(3,5)*Metric(4,6) - P(-1,1)*P(-1,2)*Metric(1,2)*Metric(3,5)*Metric(4,6) - 2*P(3,4)*P(4,3)*Metric(1,2)*Metric(5,6) - 2*P(2,4)*P(4,2)*Metric(1,3)*Metric(5,6) - 2*P(2,3)*P(3,2)*Metric(1,4)*Metric(5,6) - 2*P(1,4)*P(4,1)*Metric(2,3)*Metric(5,6) + 2*P(-1,2)*P(-1,3)*Metric(1,4)*Metric(2,3)*Metric(5,6) + 2*P(-1,1)*P(-1,4)*Metric(1,4)*Metric(2,3)*Metric(5,6) - 2*P(1,3)*P(3,1)*Metric(2,4)*Metric(5,6) + 2*P(-1,1)*P(-1,3)*Metric(1,3)*Metric(2,4)*Metric(5,6) + 2*P(-1,2)*P(-1,4)*Metric(1,3)*Metric(2,4)*Metric(5,6) - 2*P(1,2)*P(2,1)*Metric(3,4)*Metric(5,6) + 2*P(-1,1)*P(-1,2)*Metric(1,2)*Metric(3,4)*Metric(5,6) + 2*P(-1,3)*P(-1,4)*Metric(1,2)*Metric(3,4)*Metric(5,6)')

VVVVVV8 = Lorentz(name = 'VVVVVV8',
                  spins = [ 3, 3, 3, 3, 3, 3 ],
                  structure = 'P(5,6)*P(6,5)*Metric(1,4)*Metric(2,3) + P(4,6)*P(6,4)*Metric(1,5)*Metric(2,3) + P(4,5)*P(5,4)*Metric(1,6)*Metric(2,3) - (P(5,6)*P(6,5)*Metric(1,3)*Metric(2,4))/2. - (P(4,6)*P(6,4)*Metric(1,3)*Metric(2,5))/2. - (P(4,5)*P(5,4)*Metric(1,3)*Metric(2,6))/2. - (P(5,6)*P(6,5)*Metric(1,2)*Metric(3,4))/2. - (P(4,6)*P(6,4)*Metric(1,2)*Metric(3,5))/2. - (P(4,5)*P(5,4)*Metric(1,2)*Metric(3,6))/2. - P(-1,4)*P(-1,5)*Metric(1,6)*Metric(2,3)*Metric(4,5) + (P(-1,4)*P(-1,5)*Metric(1,3)*Metric(2,6)*Metric(4,5))/2. + (P(-1,4)*P(-1,5)*Metric(1,2)*Metric(3,6)*Metric(4,5))/2. - P(-1,4)*P(-1,6)*Metric(1,5)*Metric(2,3)*Metric(4,6) + (P(-1,4)*P(-1,6)*Metric(1,3)*Metric(2,5)*Metric(4,6))/2. + (P(-1,4)*P(-1,6)*Metric(1,2)*Metric(3,5)*Metric(4,6))/2. - P(-1,5)*P(-1,6)*Metric(1,4)*Metric(2,3)*Metric(5,6) + (P(-1,5)*P(-1,6)*Metric(1,3)*Metric(2,4)*Metric(5,6))/2. + (P(-1,5)*P(-1,6)*Metric(1,2)*Metric(3,4)*Metric(5,6))/2.')

VVVVVV9 = Lorentz(name = 'VVVVVV9',
                  spins = [ 3, 3, 3, 3, 3, 3 ],
                  structure = 'P(5,6)*P(6,5)*Metric(1,4)*Metric(2,3) + P(5,6)*P(6,5)*Metric(1,3)*Metric(2,4) - 2*P(5,6)*P(6,5)*Metric(1,2)*Metric(3,4) - P(-1,5)*P(-1,6)*Metric(1,4)*Metric(2,3)*Metric(5,6) - P(-1,5)*P(-1,6)*Metric(1,3)*Metric(2,4)*Metric(5,6) + 2*P(-1,5)*P(-1,6)*Metric(1,2)*Metric(3,4)*Metric(5,6)')

VVVVVV10 = Lorentz(name = 'VVVVVV10',
                   spins = [ 3, 3, 3, 3, 3, 3 ],
                   structure = 'P(5,6)*P(6,5)*Metric(1,4)*Metric(2,3) + P(4,6)*P(6,4)*Metric(1,5)*Metric(2,3) + P(4,5)*P(5,4)*Metric(1,6)*Metric(2,3) + P(5,6)*P(6,5)*Metric(1,3)*Metric(2,4) + P(3,6)*P(6,3)*Metric(1,5)*Metric(2,4) + P(3,5)*P(5,3)*Metric(1,6)*Metric(2,4) + P(4,6)*P(6,4)*Metric(1,3)*Metric(2,5) + P(3,6)*P(6,3)*Metric(1,4)*Metric(2,5) + P(3,4)*P(4,3)*Metric(1,6)*Metric(2,5) + P(4,5)*P(5,4)*Metric(1,3)*Metric(2,6) + P(3,5)*P(5,3)*Metric(1,4)*Metric(2,6) + P(3,4)*P(4,3)*Metric(1,5)*Metric(2,6) - 2*P(5,6)*P(6,5)*Metric(1,2)*Metric(3,4) - P(-1,3)*P(-1,4)*Metric(1,6)*Metric(2,5)*Metric(3,4) - P(-1,3)*P(-1,4)*Metric(1,5)*Metric(2,6)*Metric(3,4) - 2*P(4,6)*P(6,4)*Metric(1,2)*Metric(3,5) - P(-1,3)*P(-1,5)*Metric(1,6)*Metric(2,4)*Metric(3,5) - P(-1,3)*P(-1,5)*Metric(1,4)*Metric(2,6)*Metric(3,5) - 2*P(4,5)*P(5,4)*Metric(1,2)*Metric(3,6) - P(-1,3)*P(-1,6)*Metric(1,5)*Metric(2,4)*Metric(3,6) - P(-1,3)*P(-1,6)*Metric(1,4)*Metric(2,5)*Metric(3,6) - 2*P(3,6)*P(6,3)*Metric(1,2)*Metric(4,5) - P(-1,4)*P(-1,5)*Metric(1,6)*Metric(2,3)*Metric(4,5) - P(-1,4)*P(-1,5)*Metric(1,3)*Metric(2,6)*Metric(4,5) + 2*P(-1,4)*P(-1,5)*Metric(1,2)*Metric(3,6)*Metric(4,5) + 2*P(-1,3)*P(-1,6)*Metric(1,2)*Metric(3,6)*Metric(4,5) - 2*P(3,5)*P(5,3)*Metric(1,2)*Metric(4,6) - P(-1,4)*P(-1,6)*Metric(1,5)*Metric(2,3)*Metric(4,6) - P(-1,4)*P(-1,6)*Metric(1,3)*Metric(2,5)*Metric(4,6) + 2*P(-1,3)*P(-1,5)*Metric(1,2)*Metric(3,5)*Metric(4,6) + 2*P(-1,4)*P(-1,6)*Metric(1,2)*Metric(3,5)*Metric(4,6) - 2*P(3,4)*P(4,3)*Metric(1,2)*Metric(5,6) - P(-1,5)*P(-1,6)*Metric(1,4)*Metric(2,3)*Metric(5,6) - P(-1,5)*P(-1,6)*Metric(1,3)*Metric(2,4)*Metric(5,6) + 2*P(-1,3)*P(-1,4)*Metric(1,2)*Metric(3,4)*Metric(5,6) + 2*P(-1,5)*P(-1,6)*Metric(1,2)*Metric(3,4)*Metric(5,6)')

