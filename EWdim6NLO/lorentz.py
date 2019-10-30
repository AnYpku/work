# This file was automatically created by FeynRules 2.1.7
# Mathematica version: 8.0 for Mac OS X x86 (64-bit) (November 6, 2010)
# Date: Fri 29 Nov 2013 12:01:44


from object_library import all_lorentz, Lorentz

from function_library import complexconjugate, re, im, csc, sec, acsc, asec, cot
try:
   import form_factors as ForFac 
except ImportError:
   pass


FF1 = Lorentz(name = 'FF1',
              spins = [ 2, 2 ],
              structure = 'P(-1,1)*Gamma(-1,2,1)')

FF2 = Lorentz(name = 'FF2',
              spins = [ 2, 2 ],
              structure = 'ProjM(2,1) + ProjP(2,1)')

FF3 = Lorentz(name = 'FF3',
              spins = [ 2, 2 ],
              structure = 'P(-1,1)*Gamma(-1,2,-2)*ProjM(-2,1) + P(-1,1)*Gamma(-1,2,-2)*ProjP(-2,1)')

FF4 = Lorentz(name = 'FF4',
              spins = [ 2, 2 ],
              structure = '-(P(-1,1)*Gamma(-1,2,1)) + P(-1,1)*Gamma(-1,2,-2)*ProjM(-2,1) + P(-1,1)*Gamma(-1,2,-2)*ProjP(-2,1)')

VV1 = Lorentz(name = 'VV1',
              spins = [ 3, 3 ],
              structure = 'P(1,2)*P(2,2)')

VV2 = Lorentz(name = 'VV2',
              spins = [ 3, 3 ],
              structure = 'Metric(1,2)')

VV3 = Lorentz(name = 'VV3',
              spins = [ 3, 3 ],
              structure = 'P(-1,2)**2*Metric(1,2)')

VV4 = Lorentz(name = 'VV4',
              spins = [ 3, 3 ],
              structure = 'P(1,2)*P(2,2) - (3*P(-1,2)**2*Metric(1,2))/2.')

VV5 = Lorentz(name = 'VV5',
              spins = [ 3, 3 ],
              structure = 'P(1,2)*P(2,2) - P(-1,2)**2*Metric(1,2)')

UUS1 = Lorentz(name = 'UUS1',
               spins = [ -1, -1, 1 ],
               structure = '1')

UUV1 = Lorentz(name = 'UUV1',
               spins = [ -1, -1, 3 ],
               structure = 'P(3,2) + P(3,3)')

SSS1 = Lorentz(name = 'SSS1',
               spins = [ 1, 1, 1 ],
               structure = '1')

SSS2 = Lorentz(name = 'SSS2',
               spins = [ 1, 1, 1 ],
               structure = 'P(-1,1)*P(-1,3) + P(-1,2)*P(-1,3)')

SSS3 = Lorentz(name = 'SSS3',
               spins = [ 1, 1, 1 ],
               structure = 'P(-1,1)*P(-1,2) + P(-1,1)*P(-1,3) + P(-1,2)*P(-1,3)')

FFS1 = Lorentz(name = 'FFS1',
               spins = [ 2, 2, 1 ],
               structure = 'Gamma5(2,1)')

FFS2 = Lorentz(name = 'FFS2',
               spins = [ 2, 2, 1 ],
               structure = 'Identity(2,1)')

FFS3 = Lorentz(name = 'FFS3',
               spins = [ 2, 2, 1 ],
               structure = 'ProjM(2,1)')

FFS4 = Lorentz(name = 'FFS4',
               spins = [ 2, 2, 1 ],
               structure = 'ProjM(2,1) - ProjP(2,1)')

FFS5 = Lorentz(name = 'FFS5',
               spins = [ 2, 2, 1 ],
               structure = 'ProjP(2,1)')

FFS6 = Lorentz(name = 'FFS6',
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
               structure = 'Gamma(3,2,-1)*ProjM(-1,1) - 2*Gamma(3,2,-1)*ProjP(-1,1)')

FFV4 = Lorentz(name = 'FFV4',
               spins = [ 2, 2, 3 ],
               structure = 'Gamma(3,2,1) - Gamma(3,2,-1)*ProjM(-1,1) - Gamma(3,2,-1)*ProjP(-1,1)')

FFV5 = Lorentz(name = 'FFV5',
               spins = [ 2, 2, 3 ],
               structure = 'Gamma(3,2,1) - (4*Gamma(3,2,-1)*ProjM(-1,1))/13. - (4*Gamma(3,2,-1)*ProjP(-1,1))/13.')

FFV6 = Lorentz(name = 'FFV6',
               spins = [ 2, 2, 3 ],
               structure = 'Gamma(3,2,-1)*ProjM(-1,1) + Gamma(3,2,-1)*ProjP(-1,1)')

FFV7 = Lorentz(name = 'FFV7',
               spins = [ 2, 2, 3 ],
               structure = 'Gamma(3,2,-1)*ProjM(-1,1) + 2*Gamma(3,2,-1)*ProjP(-1,1)')

FFV8 = Lorentz(name = 'FFV8',
               spins = [ 2, 2, 3 ],
               structure = 'Gamma(3,2,-1)*ProjM(-1,1) + 4*Gamma(3,2,-1)*ProjP(-1,1)')

VSS1 = Lorentz(name = 'VSS1',
               spins = [ 3, 1, 1 ],
               structure = 'P(1,2) - P(1,3)')

VSS2 = Lorentz(name = 'VSS2',
               spins = [ 3, 1, 1 ],
               structure = '-(Epsilon(1,-1,-2,-3)*P(-3,1)*P(-2,2)*P(-1,3))')

VSS3 = Lorentz(name = 'VSS3',
               spins = [ 3, 1, 1 ],
               structure = '-(P(-1,1)*P(-1,3)*P(1,2)) + P(-1,1)*P(-1,2)*P(1,3)')

VSS4 = Lorentz(name = 'VSS4',
               spins = [ 3, 1, 1 ],
               structure = '-(Epsilon(1,-1,-2,-3)*P(-3,1)*P(-2,3)*P(-1,2))')

VSS5 = Lorentz(name = 'VSS5',
               spins = [ 3, 1, 1 ],
               structure = 'Epsilon(1,-1,-2,-3)*P(-3,1)*P(-2,3)*P(-1,2) - Epsilon(1,-1,-2,-3)*P(-3,1)*P(-2,2)*P(-1,3)')

VSS6 = Lorentz(name = 'VSS6',
               spins = [ 3, 1, 1 ],
               structure = '-(Epsilon(1,-1,-2,-3)*P(-3,1)*P(-2,3)*P(-1,2)) - Epsilon(1,-1,-2,-3)*P(-3,1)*P(-2,2)*P(-1,3)')

VVS1 = Lorentz(name = 'VVS1',
               spins = [ 3, 3, 1 ],
               structure = 'Epsilon(1,2,-1,-2)*P(-2,1)*P(-1,3)')

VVS2 = Lorentz(name = 'VVS2',
               spins = [ 3, 3, 1 ],
               structure = 'Epsilon(1,2,-1,-2)*P(-2,1)*P(-1,3) - Epsilon(1,2,-1,-2)*P(-2,2)*P(-1,3)')

VVS3 = Lorentz(name = 'VVS3',
               spins = [ 3, 3, 1 ],
               structure = 'Epsilon(1,2,-1,-2)*P(-2,1)*P(-1,3) + Epsilon(1,2,-1,-2)*P(-2,2)*P(-1,3)')

VVS4 = Lorentz(name = 'VVS4',
               spins = [ 3, 3, 1 ],
               structure = 'Metric(1,2)')

VVS5 = Lorentz(name = 'VVS5',
               spins = [ 3, 3, 1 ],
               structure = 'P(1,2)*P(2,1) - P(-1,1)*P(-1,2)*Metric(1,2)')

VVS6 = Lorentz(name = 'VVS6',
               spins = [ 3, 3, 1 ],
               structure = 'P(1,3)*P(2,1) - P(-1,1)*P(-1,3)*Metric(1,2)')

VVS7 = Lorentz(name = 'VVS7',
               spins = [ 3, 3, 1 ],
               structure = 'P(1,2)*P(2,3) - P(-1,2)*P(-1,3)*Metric(1,2)')

VVS8 = Lorentz(name = 'VVS8',
               spins = [ 3, 3, 1 ],
               structure = 'P(1,3)*P(2,1) + P(1,2)*P(2,3) - P(-1,1)*P(-1,3)*Metric(1,2) - P(-1,2)*P(-1,3)*Metric(1,2)')

VVS9 = Lorentz(name = 'VVS9',
               spins = [ 3, 3, 1 ],
               structure = 'P(1,3)*P(2,1) - P(1,2)*P(2,3) - P(-1,1)*P(-1,3)*Metric(1,2) + P(-1,2)*P(-1,3)*Metric(1,2)')

VVV1 = Lorentz(name = 'VVV1',
               spins = [ 3, 3, 3 ],
               structure = '-(Epsilon(1,2,3,-1)*P(-1,1))')

VVV2 = Lorentz(name = 'VVV2',
               spins = [ 3, 3, 3 ],
               structure = '-(Epsilon(1,2,3,-1)*P(-1,1)) - Epsilon(1,2,3,-1)*P(-1,2)')

VVV3 = Lorentz(name = 'VVV3',
               spins = [ 3, 3, 3 ],
               structure = '-(Epsilon(1,2,3,-1)*P(-1,1)) - Epsilon(1,2,3,-1)*P(-1,2) - Epsilon(1,2,3,-1)*P(-1,3)')

VVV4 = Lorentz(name = 'VVV4',
               spins = [ 3, 3, 3 ],
               structure = 'P(3,1)*Metric(1,2) - P(2,1)*Metric(1,3)')

VVV5 = Lorentz(name = 'VVV5',
               spins = [ 3, 3, 3 ],
               structure = 'P(3,1)*Metric(1,2) - P(3,2)*Metric(1,2) - P(2,1)*Metric(1,3) + P(1,2)*Metric(2,3)')

VVV6 = Lorentz(name = 'VVV6',
               spins = [ 3, 3, 3 ],
               structure = 'P(3,1)*Metric(1,2) - 3*P(3,2)*Metric(1,2) - P(3,3)*Metric(1,2) - P(2,1)*Metric(1,3) + P(2,2)*Metric(1,3) + 3*P(2,3)*Metric(1,3) + 2*P(1,2)*Metric(2,3) - 2*P(1,3)*Metric(2,3)')

VVV7 = Lorentz(name = 'VVV7',
               spins = [ 3, 3, 3 ],
               structure = 'P(2,3)*Metric(1,3) - P(1,3)*Metric(2,3)')

VVV8 = Lorentz(name = 'VVV8',
               spins = [ 3, 3, 3 ],
               structure = 'P(3,1)*Metric(1,2) - P(3,2)*Metric(1,2) - P(2,1)*Metric(1,3) + P(2,3)*Metric(1,3) + P(1,2)*Metric(2,3) - P(1,3)*Metric(2,3)')

VVV9 = Lorentz(name = 'VVV9',
               spins = [ 3, 3, 3 ],
               structure = 'P(3,1)*Metric(1,2) - (11*P(3,2)*Metric(1,2))/17. + (3*P(3,3)*Metric(1,2))/17. - P(2,1)*Metric(1,3) - (3*P(2,2)*Metric(1,3))/17. + (11*P(2,3)*Metric(1,3))/17. + (14*P(1,2)*Metric(2,3))/17. - (14*P(1,3)*Metric(2,3))/17.')

VVV10 = Lorentz(name = 'VVV10',
                spins = [ 3, 3, 3 ],
                structure = '-(P(1,2)*P(2,3)*P(3,1)) + P(1,3)*P(2,1)*P(3,2) + P(-1,2)*P(-1,3)*P(3,1)*Metric(1,2) - P(-1,1)*P(-1,3)*P(3,2)*Metric(1,2) - P(-1,2)*P(-1,3)*P(2,1)*Metric(1,3) + P(-1,1)*P(-1,2)*P(2,3)*Metric(1,3) + P(-1,1)*P(-1,3)*P(1,2)*Metric(2,3) - P(-1,1)*P(-1,2)*P(1,3)*Metric(2,3)')

VVV11 = Lorentz(name = 'VVV11',
                spins = [ 3, 3, 3 ],
                structure = '-2*Epsilon(1,2,3,-2)*P(-2,3)*P(-1,1)*P(-1,2) - 2*Epsilon(1,2,3,-2)*P(-2,2)*P(-1,1)*P(-1,3) - 2*Epsilon(1,2,3,-2)*P(-2,1)*P(-1,2)*P(-1,3) + Epsilon(2,3,-1,-2)*P(-2,3)*P(-1,1)*P(1,2) - Epsilon(2,3,-1,-2)*P(-2,1)*P(-1,3)*P(1,2) + Epsilon(2,3,-1,-2)*P(-2,2)*P(-1,1)*P(1,3) - Epsilon(2,3,-1,-2)*P(-2,1)*P(-1,2)*P(1,3) - Epsilon(1,3,-1,-2)*P(-2,3)*P(-1,2)*P(2,1) + Epsilon(1,3,-1,-2)*P(-2,2)*P(-1,3)*P(2,1) + Epsilon(1,3,-1,-2)*P(-2,2)*P(-1,1)*P(2,3) - Epsilon(1,3,-1,-2)*P(-2,1)*P(-1,2)*P(2,3) - Epsilon(1,2,-1,-2)*P(-2,3)*P(-1,2)*P(3,1) + Epsilon(1,2,-1,-2)*P(-2,2)*P(-1,3)*P(3,1) - Epsilon(1,2,-1,-2)*P(-2,3)*P(-1,1)*P(3,2) + Epsilon(1,2,-1,-2)*P(-2,1)*P(-1,3)*P(3,2) - (Epsilon(3,-1,-2,-3)*P(-3,3)*P(-2,2)*P(-1,1)*Metric(1,2))/2. + (Epsilon(3,-1,-2,-3)*P(-3,3)*P(-2,1)*P(-1,2)*Metric(1,2))/2. - (Epsilon(3,-1,-2,-3)*P(-3,2)*P(-2,1)*P(-1,3)*Metric(1,2))/2. + (Epsilon(3,-1,-2,-3)*P(-3,1)*P(-2,2)*P(-1,3)*Metric(1,2))/2. + (Epsilon(2,-1,-2,-3)*P(-3,2)*P(-2,3)*P(-1,1)*Metric(1,3))/2. + (Epsilon(2,-1,-2,-3)*P(-3,3)*P(-2,1)*P(-1,2)*Metric(1,3))/2. - (Epsilon(2,-1,-2,-3)*P(-3,1)*P(-2,3)*P(-1,2)*Metric(1,3))/2. - (Epsilon(2,-1,-2,-3)*P(-3,2)*P(-2,1)*P(-1,3)*Metric(1,3))/2. - (Epsilon(1,-1,-2,-3)*P(-3,3)*P(-2,2)*P(-1,1)*Metric(2,3))/2. + (Epsilon(1,-1,-2,-3)*P(-3,2)*P(-2,3)*P(-1,1)*Metric(2,3))/2. - (Epsilon(1,-1,-2,-3)*P(-3,1)*P(-2,3)*P(-1,2)*Metric(2,3))/2. + (Epsilon(1,-1,-2,-3)*P(-3,1)*P(-2,2)*P(-1,3)*Metric(2,3))/2.')

SSSS1 = Lorentz(name = 'SSSS1',
                spins = [ 1, 1, 1, 1 ],
                structure = '1')

SSSS2 = Lorentz(name = 'SSSS2',
                spins = [ 1, 1, 1, 1 ],
                structure = 'P(-1,1)*P(-1,3) + P(-1,2)*P(-1,3) + P(-1,1)*P(-1,4) + P(-1,2)*P(-1,4)')

SSSS3 = Lorentz(name = 'SSSS3',
                spins = [ 1, 1, 1, 1 ],
                structure = 'P(-1,1)*P(-1,2) + (P(-1,1)*P(-1,3))/2. + (P(-1,2)*P(-1,3))/2. + (P(-1,1)*P(-1,4))/2. + (P(-1,2)*P(-1,4))/2. + P(-1,3)*P(-1,4)')

SSSS4 = Lorentz(name = 'SSSS4',
                spins = [ 1, 1, 1, 1 ],
                structure = 'P(-1,1)*P(-1,2) + P(-1,1)*P(-1,3) + P(-1,2)*P(-1,3) + P(-1,1)*P(-1,4) + P(-1,2)*P(-1,4) + P(-1,3)*P(-1,4)')

VVSS1 = Lorentz(name = 'VVSS1',
                spins = [ 3, 3, 1, 1 ],
                structure = 'Epsilon(1,2,-1,-2)*P(-2,1)*P(-1,3) + Epsilon(1,2,-1,-2)*P(-2,1)*P(-1,4)')

VVSS2 = Lorentz(name = 'VVSS2',
                spins = [ 3, 3, 1, 1 ],
                structure = 'Epsilon(1,2,-1,-2)*P(-2,1)*P(-1,3) - 2*Epsilon(1,2,-1,-2)*P(-2,2)*P(-1,3) + Epsilon(1,2,-1,-2)*P(-2,1)*P(-1,4) - 2*Epsilon(1,2,-1,-2)*P(-2,2)*P(-1,4)')

VVSS3 = Lorentz(name = 'VVSS3',
                spins = [ 3, 3, 1, 1 ],
                structure = 'Epsilon(1,2,-1,-2)*P(-2,1)*P(-1,3) - Epsilon(1,2,-1,-2)*P(-2,2)*P(-1,3) + Epsilon(1,2,-1,-2)*P(-2,1)*P(-1,4) - Epsilon(1,2,-1,-2)*P(-2,2)*P(-1,4)')

VVSS4 = Lorentz(name = 'VVSS4',
                spins = [ 3, 3, 1, 1 ],
                structure = 'Epsilon(1,2,-1,-2)*P(-2,1)*P(-1,3) + 2*Epsilon(1,2,-1,-2)*P(-2,2)*P(-1,3) - Epsilon(1,2,-1,-2)*P(-2,1)*P(-1,4) - 2*Epsilon(1,2,-1,-2)*P(-2,3)*P(-1,4)')

VVSS5 = Lorentz(name = 'VVSS5',
                spins = [ 3, 3, 1, 1 ],
                structure = 'Epsilon(1,2,-1,-2)*P(-2,1)*P(-1,3) - Epsilon(1,2,-1,-2)*P(-2,1)*P(-1,4) - 2*Epsilon(1,2,-1,-2)*P(-2,2)*P(-1,4) - 2*Epsilon(1,2,-1,-2)*P(-2,3)*P(-1,4)')

VVSS6 = Lorentz(name = 'VVSS6',
                spins = [ 3, 3, 1, 1 ],
                structure = 'Epsilon(1,2,-1,-2)*P(-2,1)*P(-1,3) + Epsilon(1,2,-1,-2)*P(-2,2)*P(-1,3) - Epsilon(1,2,-1,-2)*P(-2,1)*P(-1,4) - Epsilon(1,2,-1,-2)*P(-2,2)*P(-1,4) - 2*Epsilon(1,2,-1,-2)*P(-2,3)*P(-1,4)')

VVSS7 = Lorentz(name = 'VVSS7',
                spins = [ 3, 3, 1, 1 ],
                structure = 'Epsilon(1,2,-1,-2)*P(-2,2)*P(-1,3) - Epsilon(1,2,-1,-2)*P(-2,1)*P(-1,4) - Epsilon(1,2,-1,-2)*P(-2,3)*P(-1,4)')

VVSS8 = Lorentz(name = 'VVSS8',
                spins = [ 3, 3, 1, 1 ],
                structure = 'Epsilon(1,2,-1,-2)*P(-2,1)*P(-1,3) - Epsilon(1,2,-1,-2)*P(-2,2)*P(-1,3) - Epsilon(1,2,-1,-2)*P(-2,4)*P(-1,3) + Epsilon(1,2,-1,-2)*P(-2,1)*P(-1,4) - Epsilon(1,2,-1,-2)*P(-2,2)*P(-1,4) - Epsilon(1,2,-1,-2)*P(-2,3)*P(-1,4)')

VVSS9 = Lorentz(name = 'VVSS9',
                spins = [ 3, 3, 1, 1 ],
                structure = 'Epsilon(1,2,-1,-2)*P(-2,1)*P(-1,3) + Epsilon(1,2,-1,-2)*P(-2,2)*P(-1,3) + Epsilon(1,2,-1,-2)*P(-2,4)*P(-1,3) - Epsilon(1,2,-1,-2)*P(-2,1)*P(-1,4) - Epsilon(1,2,-1,-2)*P(-2,2)*P(-1,4) - Epsilon(1,2,-1,-2)*P(-2,3)*P(-1,4)')

VVSS10 = Lorentz(name = 'VVSS10',
                 spins = [ 3, 3, 1, 1 ],
                 structure = 'Epsilon(1,2,-1,-2)*P(-2,1)*P(-1,3) + 2*Epsilon(1,2,-1,-2)*P(-2,2)*P(-1,3) + 2*Epsilon(1,2,-1,-2)*P(-2,4)*P(-1,3) - Epsilon(1,2,-1,-2)*P(-2,1)*P(-1,4)')

VVSS11 = Lorentz(name = 'VVSS11',
                 spins = [ 3, 3, 1, 1 ],
                 structure = 'Epsilon(1,2,-1,-2)*P(-2,1)*P(-1,3) + 2*Epsilon(1,2,-1,-2)*P(-2,4)*P(-1,3) - Epsilon(1,2,-1,-2)*P(-2,1)*P(-1,4) - 2*Epsilon(1,2,-1,-2)*P(-2,2)*P(-1,4)')

VVSS12 = Lorentz(name = 'VVSS12',
                 spins = [ 3, 3, 1, 1 ],
                 structure = 'Epsilon(1,2,-1,-2)*P(-2,1)*P(-1,3) + Epsilon(1,2,-1,-2)*P(-2,2)*P(-1,3) + 2*Epsilon(1,2,-1,-2)*P(-2,4)*P(-1,3) - Epsilon(1,2,-1,-2)*P(-2,1)*P(-1,4) - Epsilon(1,2,-1,-2)*P(-2,2)*P(-1,4)')

VVSS13 = Lorentz(name = 'VVSS13',
                 spins = [ 3, 3, 1, 1 ],
                 structure = 'Metric(1,2)')

VVSS14 = Lorentz(name = 'VVSS14',
                 spins = [ 3, 3, 1, 1 ],
                 structure = 'P(1,2)*P(2,1) - P(-1,1)*P(-1,2)*Metric(1,2)')

VVSS15 = Lorentz(name = 'VVSS15',
                 spins = [ 3, 3, 1, 1 ],
                 structure = 'P(1,3)*P(2,1) + P(1,4)*P(2,1) - P(-1,1)*P(-1,3)*Metric(1,2) - P(-1,1)*P(-1,4)*Metric(1,2)')

VVSS16 = Lorentz(name = 'VVSS16',
                 spins = [ 3, 3, 1, 1 ],
                 structure = 'P(1,4)*P(2,1) + P(1,2)*P(2,3) - P(1,4)*P(2,3) + P(1,3)*P(2,4) - P(-1,2)*P(-1,3)*Metric(1,2) - P(-1,1)*P(-1,4)*Metric(1,2)')

VVSS17 = Lorentz(name = 'VVSS17',
                 spins = [ 3, 3, 1, 1 ],
                 structure = 'P(1,3)*P(2,1) - P(1,4)*P(2,1) - 2*P(1,2)*P(2,3) + 2*P(1,4)*P(2,3) - 2*P(1,3)*P(2,4) - P(-1,1)*P(-1,3)*Metric(1,2) + 2*P(-1,2)*P(-1,3)*Metric(1,2) + P(-1,1)*P(-1,4)*Metric(1,2)')

VVSS18 = Lorentz(name = 'VVSS18',
                 spins = [ 3, 3, 1, 1 ],
                 structure = 'P(1,3)*P(2,1) + P(1,4)*P(2,1) + 2*P(1,2)*P(2,3) + 2*P(1,2)*P(2,4) - P(-1,1)*P(-1,3)*Metric(1,2) - 2*P(-1,2)*P(-1,3)*Metric(1,2) - P(-1,1)*P(-1,4)*Metric(1,2) - 2*P(-1,2)*P(-1,4)*Metric(1,2)')

VVSS19 = Lorentz(name = 'VVSS19',
                 spins = [ 3, 3, 1, 1 ],
                 structure = 'P(1,3)*P(2,1) - P(1,4)*P(2,1) + 2*P(1,4)*P(2,3) + 2*P(1,2)*P(2,4) - 2*P(1,3)*P(2,4) - P(-1,1)*P(-1,3)*Metric(1,2) + P(-1,1)*P(-1,4)*Metric(1,2) - 2*P(-1,2)*P(-1,4)*Metric(1,2)')

VVSS20 = Lorentz(name = 'VVSS20',
                 spins = [ 3, 3, 1, 1 ],
                 structure = 'P(1,2)*P(2,3) + P(1,2)*P(2,4) - P(-1,2)*P(-1,3)*Metric(1,2) - P(-1,2)*P(-1,4)*Metric(1,2)')

VVSS21 = Lorentz(name = 'VVSS21',
                 spins = [ 3, 3, 1, 1 ],
                 structure = 'P(1,3)*P(2,1) + P(1,4)*P(2,1) + P(1,2)*P(2,3) + P(1,2)*P(2,4) - P(-1,1)*P(-1,3)*Metric(1,2) - P(-1,2)*P(-1,3)*Metric(1,2) - P(-1,1)*P(-1,4)*Metric(1,2) - P(-1,2)*P(-1,4)*Metric(1,2)')

VVSS22 = Lorentz(name = 'VVSS22',
                 spins = [ 3, 3, 1, 1 ],
                 structure = 'P(1,3)*P(2,1) - P(1,4)*P(2,1) - P(1,2)*P(2,3) + 2*P(1,4)*P(2,3) + P(1,2)*P(2,4) - 2*P(1,3)*P(2,4) - P(-1,1)*P(-1,3)*Metric(1,2) + P(-1,2)*P(-1,3)*Metric(1,2) + P(-1,1)*P(-1,4)*Metric(1,2) - P(-1,2)*P(-1,4)*Metric(1,2)')

VVVS1 = Lorentz(name = 'VVVS1',
                spins = [ 3, 3, 3, 1 ],
                structure = '-(Epsilon(1,2,3,-1)*P(-1,1)) + Epsilon(1,2,3,-1)*P(-1,2)')

VVVS2 = Lorentz(name = 'VVVS2',
                spins = [ 3, 3, 3, 1 ],
                structure = '-(Epsilon(1,2,3,-1)*P(-1,2)) + Epsilon(1,2,3,-1)*P(-1,3)')

VVVS3 = Lorentz(name = 'VVVS3',
                spins = [ 3, 3, 3, 1 ],
                structure = '-(Epsilon(1,2,3,-1)*P(-1,1)) - Epsilon(1,2,3,-1)*P(-1,2) - Epsilon(1,2,3,-1)*P(-1,4)')

VVVS4 = Lorentz(name = 'VVVS4',
                spins = [ 3, 3, 3, 1 ],
                structure = '-(Epsilon(1,2,3,-1)*P(-1,2)) - Epsilon(1,2,3,-1)*P(-1,3) - Epsilon(1,2,3,-1)*P(-1,4)')

VVVS5 = Lorentz(name = 'VVVS5',
                spins = [ 3, 3, 3, 1 ],
                structure = '-(Epsilon(1,2,3,-1)*P(-1,1)) - 2*Epsilon(1,2,3,-1)*P(-1,4)')

VVVS6 = Lorentz(name = 'VVVS6',
                spins = [ 3, 3, 3, 1 ],
                structure = '-(Epsilon(1,2,3,-1)*P(-1,1)) - Epsilon(1,2,3,-1)*P(-1,2) - Epsilon(1,2,3,-1)*P(-1,3) - 3*Epsilon(1,2,3,-1)*P(-1,4)')

VVVS7 = Lorentz(name = 'VVVS7',
                spins = [ 3, 3, 3, 1 ],
                structure = 'P(3,1)*Metric(1,2) - P(2,1)*Metric(1,3)')

VVVS8 = Lorentz(name = 'VVVS8',
                spins = [ 3, 3, 3, 1 ],
                structure = 'P(3,1)*Metric(1,2) - P(3,4)*Metric(1,2) - P(2,1)*Metric(1,3) + P(2,4)*Metric(1,3)')

VVVS9 = Lorentz(name = 'VVVS9',
                spins = [ 3, 3, 3, 1 ],
                structure = 'P(3,1)*Metric(1,2) + P(3,2)*Metric(1,2) - P(2,1)*Metric(1,3) - P(1,2)*Metric(2,3)')

VVVS10 = Lorentz(name = 'VVVS10',
                 spins = [ 3, 3, 3, 1 ],
                 structure = 'P(2,3)*Metric(1,3) - P(1,3)*Metric(2,3)')

VVVS11 = Lorentz(name = 'VVVS11',
                 spins = [ 3, 3, 3, 1 ],
                 structure = 'P(3,2)*Metric(1,2) + P(2,3)*Metric(1,3) - P(1,2)*Metric(2,3) - P(1,3)*Metric(2,3)')

VVVS12 = Lorentz(name = 'VVVS12',
                 spins = [ 3, 3, 3, 1 ],
                 structure = 'P(3,1)*Metric(1,2) - P(3,2)*Metric(1,2) - P(2,1)*Metric(1,3) + P(2,3)*Metric(1,3) + P(1,2)*Metric(2,3) - P(1,3)*Metric(2,3)')

VVVS13 = Lorentz(name = 'VVVS13',
                 spins = [ 3, 3, 3, 1 ],
                 structure = 'P(3,4)*Metric(1,2) + P(2,4)*Metric(1,3) - 2*P(1,4)*Metric(2,3)')

VVVS14 = Lorentz(name = 'VVVS14',
                 spins = [ 3, 3, 3, 1 ],
                 structure = 'P(3,1)*Metric(1,2) - P(3,2)*Metric(1,2) - P(2,1)*Metric(1,3) + P(2,4)*Metric(1,3) + P(1,2)*Metric(2,3) - P(1,4)*Metric(2,3)')

VVVS15 = Lorentz(name = 'VVVS15',
                 spins = [ 3, 3, 3, 1 ],
                 structure = 'P(3,4)*Metric(1,2) - (P(2,4)*Metric(1,3))/2. - (P(1,4)*Metric(2,3))/2.')

VVVS16 = Lorentz(name = 'VVVS16',
                 spins = [ 3, 3, 3, 1 ],
                 structure = 'P(3,2)*Metric(1,2) - P(2,3)*Metric(1,3) - P(2,4)*Metric(1,3) - P(1,2)*Metric(2,3) + P(1,3)*Metric(2,3) + P(1,4)*Metric(2,3)')

VVVS17 = Lorentz(name = 'VVVS17',
                 spins = [ 3, 3, 3, 1 ],
                 structure = 'P(3,2)*Metric(1,2) - P(3,4)*Metric(1,2) + P(2,3)*Metric(1,3) - P(2,4)*Metric(1,3) - P(1,2)*Metric(2,3) - P(1,3)*Metric(2,3) + 2*P(1,4)*Metric(2,3)')

VVVV1 = Lorentz(name = 'VVVV1',
                spins = [ 3, 3, 3, 3 ],
                structure = 'Epsilon(1,2,3,4)')

VVVV2 = Lorentz(name = 'VVVV2',
                spins = [ 3, 3, 3, 3 ],
                structure = 'Metric(1,4)*Metric(2,3)')

VVVV3 = Lorentz(name = 'VVVV3',
                spins = [ 3, 3, 3, 3 ],
                structure = 'Metric(1,3)*Metric(2,4)')

VVVV4 = Lorentz(name = 'VVVV4',
                spins = [ 3, 3, 3, 3 ],
                structure = 'Metric(1,4)*Metric(2,3) - Metric(1,3)*Metric(2,4)')

VVVV5 = Lorentz(name = 'VVVV5',
                spins = [ 3, 3, 3, 3 ],
                structure = 'Metric(1,2)*Metric(3,4)')

VVVV6 = Lorentz(name = 'VVVV6',
                spins = [ 3, 3, 3, 3 ],
                structure = '-(Epsilon(1,2,3,4)*P(-1,1)*P(-1,3)) + Epsilon(1,2,3,4)*P(-1,2)*P(-1,3) + Epsilon(1,2,3,4)*P(-1,1)*P(-1,4) - Epsilon(1,2,3,4)*P(-1,2)*P(-1,4) - Epsilon(2,3,4,-1)*P(-1,3)*P(1,2) + Epsilon(2,3,4,-1)*P(-1,4)*P(1,2) - Epsilon(2,3,4,-1)*P(-1,1)*P(1,3) - Epsilon(2,3,4,-1)*P(-1,2)*P(1,3) + Epsilon(2,3,4,-1)*P(-1,1)*P(1,4) + Epsilon(2,3,4,-1)*P(-1,2)*P(1,4) - Epsilon(1,3,4,-1)*P(-1,3)*P(2,1) + Epsilon(1,3,4,-1)*P(-1,4)*P(2,1) - Epsilon(1,3,4,-1)*P(-1,1)*P(2,3) - Epsilon(1,3,4,-1)*P(-1,2)*P(2,3) + Epsilon(1,3,4,-1)*P(-1,1)*P(2,4) + Epsilon(1,3,4,-1)*P(-1,2)*P(2,4) - Epsilon(1,2,4,-1)*P(-1,3)*P(3,1) - Epsilon(1,2,4,-1)*P(-1,4)*P(3,1) + Epsilon(1,2,4,-1)*P(-1,3)*P(3,2) + Epsilon(1,2,4,-1)*P(-1,4)*P(3,2) - Epsilon(1,2,4,-1)*P(-1,1)*P(3,4) + Epsilon(1,2,4,-1)*P(-1,2)*P(3,4) - Epsilon(1,2,3,-1)*P(-1,3)*P(4,1) - Epsilon(1,2,3,-1)*P(-1,4)*P(4,1) + Epsilon(1,2,3,-1)*P(-1,3)*P(4,2) + Epsilon(1,2,3,-1)*P(-1,4)*P(4,2) - Epsilon(1,2,3,-1)*P(-1,1)*P(4,3) + Epsilon(1,2,3,-1)*P(-1,2)*P(4,3) + (Epsilon(3,4,-1,-2)*P(-2,3)*P(-1,1)*Metric(1,2))/2. - (Epsilon(3,4,-1,-2)*P(-2,4)*P(-1,1)*Metric(1,2))/2. + (Epsilon(3,4,-1,-2)*P(-2,3)*P(-1,2)*Metric(1,2))/2. - (Epsilon(3,4,-1,-2)*P(-2,4)*P(-1,2)*Metric(1,2))/2. - (Epsilon(3,4,-1,-2)*P(-2,1)*P(-1,3)*Metric(1,2))/2. - (Epsilon(3,4,-1,-2)*P(-2,2)*P(-1,3)*Metric(1,2))/2. + (Epsilon(3,4,-1,-2)*P(-2,1)*P(-1,4)*Metric(1,2))/2. + (Epsilon(3,4,-1,-2)*P(-2,2)*P(-1,4)*Metric(1,2))/2. + (Epsilon(2,4,-1,-2)*P(-2,3)*P(-1,1)*Metric(1,3))/2. + (Epsilon(2,4,-1,-2)*P(-2,4)*P(-1,1)*Metric(1,3))/2. + (Epsilon(2,4,-1,-2)*P(-2,3)*P(-1,2)*Metric(1,3))/2. - (Epsilon(2,4,-1,-2)*P(-2,1)*P(-1,3)*Metric(1,3))/2. - (Epsilon(2,4,-1,-2)*P(-2,2)*P(-1,3)*Metric(1,3))/2. - (Epsilon(2,4,-1,-2)*P(-2,1)*P(-1,4)*Metric(1,3))/2. + (Epsilon(2,3,-1,-2)*P(-2,3)*P(-1,1)*Metric(1,4))/2. + (Epsilon(2,3,-1,-2)*P(-2,4)*P(-1,1)*Metric(1,4))/2. + (Epsilon(2,3,-1,-2)*P(-2,4)*P(-1,2)*Metric(1,4))/2. - (Epsilon(2,3,-1,-2)*P(-2,1)*P(-1,3)*Metric(1,4))/2. - (Epsilon(2,3,-1,-2)*P(-2,1)*P(-1,4)*Metric(1,4))/2. - (Epsilon(2,3,-1,-2)*P(-2,2)*P(-1,4)*Metric(1,4))/2. + (Epsilon(1,4,-1,-2)*P(-2,3)*P(-1,1)*Metric(2,3))/2. + (Epsilon(1,4,-1,-2)*P(-2,3)*P(-1,2)*Metric(2,3))/2. + (Epsilon(1,4,-1,-2)*P(-2,4)*P(-1,2)*Metric(2,3))/2. - (Epsilon(1,4,-1,-2)*P(-2,1)*P(-1,3)*Metric(2,3))/2. - (Epsilon(1,4,-1,-2)*P(-2,2)*P(-1,3)*Metric(2,3))/2. - (Epsilon(1,4,-1,-2)*P(-2,2)*P(-1,4)*Metric(2,3))/2. + (Epsilon(1,3,-1,-2)*P(-2,4)*P(-1,1)*Metric(2,4))/2. + (Epsilon(1,3,-1,-2)*P(-2,3)*P(-1,2)*Metric(2,4))/2. + (Epsilon(1,3,-1,-2)*P(-2,4)*P(-1,2)*Metric(2,4))/2. - (Epsilon(1,3,-1,-2)*P(-2,2)*P(-1,3)*Metric(2,4))/2. - (Epsilon(1,3,-1,-2)*P(-2,1)*P(-1,4)*Metric(2,4))/2. - (Epsilon(1,3,-1,-2)*P(-2,2)*P(-1,4)*Metric(2,4))/2. - (Epsilon(1,2,-1,-2)*P(-2,3)*P(-1,1)*Metric(3,4))/2. - (Epsilon(1,2,-1,-2)*P(-2,4)*P(-1,1)*Metric(3,4))/2. + (Epsilon(1,2,-1,-2)*P(-2,3)*P(-1,2)*Metric(3,4))/2. + (Epsilon(1,2,-1,-2)*P(-2,4)*P(-1,2)*Metric(3,4))/2. + (Epsilon(1,2,-1,-2)*P(-2,1)*P(-1,3)*Metric(3,4))/2. - (Epsilon(1,2,-1,-2)*P(-2,2)*P(-1,3)*Metric(3,4))/2. + (Epsilon(1,2,-1,-2)*P(-2,1)*P(-1,4)*Metric(3,4))/2. - (Epsilon(1,2,-1,-2)*P(-2,2)*P(-1,4)*Metric(3,4))/2.')

VVVV7 = Lorentz(name = 'VVVV7',
                spins = [ 3, 3, 3, 3 ],
                structure = 'Epsilon(1,2,3,4)*P(-1,1)*P(-1,2) - Epsilon(1,2,3,4)*P(-1,1)*P(-1,3) - Epsilon(1,2,3,4)*P(-1,2)*P(-1,4) + Epsilon(1,2,3,4)*P(-1,3)*P(-1,4) + Epsilon(2,3,4,-1)*P(-1,1)*P(1,2) + Epsilon(2,3,4,-1)*P(-1,4)*P(1,2) - Epsilon(2,3,4,-1)*P(-1,1)*P(1,3) - Epsilon(2,3,4,-1)*P(-1,4)*P(1,3) + Epsilon(2,3,4,-1)*P(-1,2)*P(1,4) - Epsilon(2,3,4,-1)*P(-1,3)*P(1,4) - Epsilon(1,3,4,-1)*P(-1,2)*P(2,1) - Epsilon(1,3,4,-1)*P(-1,3)*P(2,1) - Epsilon(1,3,4,-1)*P(-1,1)*P(2,3) + Epsilon(1,3,4,-1)*P(-1,4)*P(2,3) + Epsilon(1,3,4,-1)*P(-1,2)*P(2,4) + Epsilon(1,3,4,-1)*P(-1,3)*P(2,4) - Epsilon(1,2,4,-1)*P(-1,2)*P(3,1) - Epsilon(1,2,4,-1)*P(-1,3)*P(3,1) - Epsilon(1,2,4,-1)*P(-1,1)*P(3,2) + Epsilon(1,2,4,-1)*P(-1,4)*P(3,2) + Epsilon(1,2,4,-1)*P(-1,2)*P(3,4) + Epsilon(1,2,4,-1)*P(-1,3)*P(3,4) + Epsilon(1,2,3,-1)*P(-1,2)*P(4,1) - Epsilon(1,2,3,-1)*P(-1,3)*P(4,1) + Epsilon(1,2,3,-1)*P(-1,1)*P(4,2) + Epsilon(1,2,3,-1)*P(-1,4)*P(4,2) - Epsilon(1,2,3,-1)*P(-1,1)*P(4,3) - Epsilon(1,2,3,-1)*P(-1,4)*P(4,3) + (Epsilon(3,4,-1,-2)*P(-2,2)*P(-1,1)*Metric(1,2))/2. + (Epsilon(3,4,-1,-2)*P(-2,3)*P(-1,1)*Metric(1,2))/2. - (Epsilon(3,4,-1,-2)*P(-2,1)*P(-1,2)*Metric(1,2))/2. - (Epsilon(3,4,-1,-2)*P(-2,4)*P(-1,2)*Metric(1,2))/2. - (Epsilon(3,4,-1,-2)*P(-2,1)*P(-1,3)*Metric(1,2))/2. + (Epsilon(3,4,-1,-2)*P(-2,2)*P(-1,4)*Metric(1,2))/2. + (Epsilon(2,4,-1,-2)*P(-2,2)*P(-1,1)*Metric(1,3))/2. + (Epsilon(2,4,-1,-2)*P(-2,3)*P(-1,1)*Metric(1,3))/2. - (Epsilon(2,4,-1,-2)*P(-2,1)*P(-1,2)*Metric(1,3))/2. - (Epsilon(2,4,-1,-2)*P(-2,1)*P(-1,3)*Metric(1,3))/2. - (Epsilon(2,4,-1,-2)*P(-2,4)*P(-1,3)*Metric(1,3))/2. + (Epsilon(2,4,-1,-2)*P(-2,3)*P(-1,4)*Metric(1,3))/2. - (Epsilon(2,3,-1,-2)*P(-2,2)*P(-1,1)*Metric(1,4))/2. + (Epsilon(2,3,-1,-2)*P(-2,3)*P(-1,1)*Metric(1,4))/2. + (Epsilon(2,3,-1,-2)*P(-2,1)*P(-1,2)*Metric(1,4))/2. + (Epsilon(2,3,-1,-2)*P(-2,4)*P(-1,2)*Metric(1,4))/2. - (Epsilon(2,3,-1,-2)*P(-2,1)*P(-1,3)*Metric(1,4))/2. - (Epsilon(2,3,-1,-2)*P(-2,4)*P(-1,3)*Metric(1,4))/2. - (Epsilon(2,3,-1,-2)*P(-2,2)*P(-1,4)*Metric(1,4))/2. + (Epsilon(2,3,-1,-2)*P(-2,3)*P(-1,4)*Metric(1,4))/2. + (Epsilon(1,4,-1,-2)*P(-2,2)*P(-1,1)*Metric(2,3))/2. + (Epsilon(1,4,-1,-2)*P(-2,3)*P(-1,1)*Metric(2,3))/2. - (Epsilon(1,4,-1,-2)*P(-2,1)*P(-1,2)*Metric(2,3))/2. + (Epsilon(1,4,-1,-2)*P(-2,4)*P(-1,2)*Metric(2,3))/2. - (Epsilon(1,4,-1,-2)*P(-2,1)*P(-1,3)*Metric(2,3))/2. + (Epsilon(1,4,-1,-2)*P(-2,4)*P(-1,3)*Metric(2,3))/2. - (Epsilon(1,4,-1,-2)*P(-2,2)*P(-1,4)*Metric(2,3))/2. - (Epsilon(1,4,-1,-2)*P(-2,3)*P(-1,4)*Metric(2,3))/2. - (Epsilon(1,3,-1,-2)*P(-2,2)*P(-1,1)*Metric(2,4))/2. + (Epsilon(1,3,-1,-2)*P(-2,1)*P(-1,2)*Metric(2,4))/2. + (Epsilon(1,3,-1,-2)*P(-2,4)*P(-1,2)*Metric(2,4))/2. + (Epsilon(1,3,-1,-2)*P(-2,4)*P(-1,3)*Metric(2,4))/2. - (Epsilon(1,3,-1,-2)*P(-2,2)*P(-1,4)*Metric(2,4))/2. - (Epsilon(1,3,-1,-2)*P(-2,3)*P(-1,4)*Metric(2,4))/2. - (Epsilon(1,2,-1,-2)*P(-2,3)*P(-1,1)*Metric(3,4))/2. + (Epsilon(1,2,-1,-2)*P(-2,4)*P(-1,2)*Metric(3,4))/2. + (Epsilon(1,2,-1,-2)*P(-2,1)*P(-1,3)*Metric(3,4))/2. + (Epsilon(1,2,-1,-2)*P(-2,4)*P(-1,3)*Metric(3,4))/2. - (Epsilon(1,2,-1,-2)*P(-2,2)*P(-1,4)*Metric(3,4))/2. - (Epsilon(1,2,-1,-2)*P(-2,3)*P(-1,4)*Metric(3,4))/2.')

VVVV8 = Lorentz(name = 'VVVV8',
                spins = [ 3, 3, 3, 3 ],
                structure = 'Metric(1,4)*Metric(2,3) + Metric(1,3)*Metric(2,4) - 2*Metric(1,2)*Metric(3,4)')

VVVV9 = Lorentz(name = 'VVVV9',
                spins = [ 3, 3, 3, 3 ],
                structure = 'Metric(1,4)*Metric(2,3) - Metric(1,2)*Metric(3,4)')

VVVV10 = Lorentz(name = 'VVVV10',
                 spins = [ 3, 3, 3, 3 ],
                 structure = 'Metric(1,3)*Metric(2,4) - Metric(1,2)*Metric(3,4)')

VVVV11 = Lorentz(name = 'VVVV11',
                 spins = [ 3, 3, 3, 3 ],
                 structure = 'Metric(1,4)*Metric(2,3) - (Metric(1,3)*Metric(2,4))/2. - (Metric(1,2)*Metric(3,4))/2.')

VVVV12 = Lorentz(name = 'VVVV12',
                 spins = [ 3, 3, 3, 3 ],
                 structure = 'Metric(1,4)*Metric(2,3) + Metric(1,3)*Metric(2,4) + Metric(1,2)*Metric(3,4)')

VVVV13 = Lorentz(name = 'VVVV13',
                 spins = [ 3, 3, 3, 3 ],
                 structure = 'P(3,2)*P(4,1)*Metric(1,2) - P(3,1)*P(4,2)*Metric(1,2) + P(3,4)*P(4,2)*Metric(1,2) + P(3,1)*P(4,3)*Metric(1,2) + P(2,3)*P(4,1)*Metric(1,3) + P(2,1)*P(4,2)*Metric(1,3) - P(2,1)*P(4,3)*Metric(1,3) + P(2,4)*P(4,3)*Metric(1,3) - P(2,3)*P(3,1)*Metric(1,4) - P(2,1)*P(3,2)*Metric(1,4) - P(2,4)*P(3,2)*Metric(1,4) - P(2,3)*P(3,4)*Metric(1,4) - P(1,2)*P(4,1)*Metric(2,3) - P(1,3)*P(4,1)*Metric(2,3) - P(1,4)*P(4,2)*Metric(2,3) - P(1,4)*P(4,3)*Metric(2,3) + P(-1,1)*P(-1,2)*Metric(1,4)*Metric(2,3) + P(-1,1)*P(-1,3)*Metric(1,4)*Metric(2,3) + P(-1,2)*P(-1,4)*Metric(1,4)*Metric(2,3) + P(-1,3)*P(-1,4)*Metric(1,4)*Metric(2,3) + P(1,2)*P(3,1)*Metric(2,4) + P(1,4)*P(3,2)*Metric(2,4) - P(1,2)*P(3,4)*Metric(2,4) + P(1,3)*P(3,4)*Metric(2,4) - P(-1,1)*P(-1,2)*Metric(1,3)*Metric(2,4) - P(-1,3)*P(-1,4)*Metric(1,3)*Metric(2,4) + P(1,3)*P(2,1)*Metric(3,4) + P(1,4)*P(2,3)*Metric(3,4) + P(1,2)*P(2,4)*Metric(3,4) - P(1,3)*P(2,4)*Metric(3,4) - P(-1,1)*P(-1,3)*Metric(1,2)*Metric(3,4) - P(-1,2)*P(-1,4)*Metric(1,2)*Metric(3,4)')

VVVV14 = Lorentz(name = 'VVVV14',
                 spins = [ 3, 3, 3, 3 ],
                 structure = 'P(3,4)*P(4,1)*Metric(1,2) + P(3,4)*P(4,2)*Metric(1,2) + P(3,1)*P(4,3)*Metric(1,2) + P(3,2)*P(4,3)*Metric(1,2) + P(2,3)*P(4,1)*Metric(1,3) - P(2,4)*P(4,1)*Metric(1,3) - P(2,3)*P(4,2)*Metric(1,3) - P(2,1)*P(4,3)*Metric(1,3) - P(2,3)*P(3,1)*Metric(1,4) + P(2,4)*P(3,1)*Metric(1,4) - P(2,4)*P(3,2)*Metric(1,4) - P(2,1)*P(3,4)*Metric(1,4) - P(1,3)*P(4,1)*Metric(2,3) + P(1,3)*P(4,2)*Metric(2,3) - P(1,4)*P(4,2)*Metric(2,3) - P(1,2)*P(4,3)*Metric(2,3) + P(-1,1)*P(-1,3)*Metric(1,4)*Metric(2,3) + P(-1,2)*P(-1,4)*Metric(1,4)*Metric(2,3) - P(1,4)*P(3,1)*Metric(2,4) - P(1,3)*P(3,2)*Metric(2,4) + P(1,4)*P(3,2)*Metric(2,4) - P(1,2)*P(3,4)*Metric(2,4) + P(-1,2)*P(-1,3)*Metric(1,3)*Metric(2,4) + P(-1,1)*P(-1,4)*Metric(1,3)*Metric(2,4) + P(1,3)*P(2,1)*Metric(3,4) + P(1,4)*P(2,1)*Metric(3,4) + P(1,2)*P(2,3)*Metric(3,4) + P(1,2)*P(2,4)*Metric(3,4) - P(-1,1)*P(-1,3)*Metric(1,2)*Metric(3,4) - P(-1,2)*P(-1,3)*Metric(1,2)*Metric(3,4) - P(-1,1)*P(-1,4)*Metric(1,2)*Metric(3,4) - P(-1,2)*P(-1,4)*Metric(1,2)*Metric(3,4)')

VVVSS1 = Lorentz(name = 'VVVSS1',
                 spins = [ 3, 3, 3, 1, 1 ],
                 structure = '-(Epsilon(1,2,3,-1)*P(-1,1)) + Epsilon(1,2,3,-1)*P(-1,2)')

VVVSS2 = Lorentz(name = 'VVVSS2',
                 spins = [ 3, 3, 3, 1, 1 ],
                 structure = '-(Epsilon(1,2,3,-1)*P(-1,2)) + Epsilon(1,2,3,-1)*P(-1,3)')

VVVSS3 = Lorentz(name = 'VVVSS3',
                 spins = [ 3, 3, 3, 1, 1 ],
                 structure = '-(Epsilon(1,2,3,-1)*P(-1,1)) - Epsilon(1,2,3,-1)*P(-1,2) - Epsilon(1,2,3,-1)*P(-1,4) - Epsilon(1,2,3,-1)*P(-1,5)')

VVVSS4 = Lorentz(name = 'VVVSS4',
                 spins = [ 3, 3, 3, 1, 1 ],
                 structure = '-(Epsilon(1,2,3,-1)*P(-1,2)) - Epsilon(1,2,3,-1)*P(-1,3) - Epsilon(1,2,3,-1)*P(-1,4) - Epsilon(1,2,3,-1)*P(-1,5)')

VVVSS5 = Lorentz(name = 'VVVSS5',
                 spins = [ 3, 3, 3, 1, 1 ],
                 structure = '-(Epsilon(1,2,3,-1)*P(-1,1)) - 2*Epsilon(1,2,3,-1)*P(-1,4) - 2*Epsilon(1,2,3,-1)*P(-1,5)')

VVVSS6 = Lorentz(name = 'VVVSS6',
                 spins = [ 3, 3, 3, 1, 1 ],
                 structure = '-(Epsilon(1,2,3,-1)*P(-1,1)) - Epsilon(1,2,3,-1)*P(-1,2) - Epsilon(1,2,3,-1)*P(-1,3) - 3*Epsilon(1,2,3,-1)*P(-1,4) - 3*Epsilon(1,2,3,-1)*P(-1,5)')

VVVSS7 = Lorentz(name = 'VVVSS7',
                 spins = [ 3, 3, 3, 1, 1 ],
                 structure = '-(Epsilon(1,2,3,-1)*P(-1,1)) - 2*Epsilon(1,2,3,-1)*P(-1,2) - 2*Epsilon(1,2,3,-1)*P(-1,3) - 4*Epsilon(1,2,3,-1)*P(-1,4) - 4*Epsilon(1,2,3,-1)*P(-1,5)')

VVVSS8 = Lorentz(name = 'VVVSS8',
                 spins = [ 3, 3, 3, 1, 1 ],
                 structure = 'P(3,1)*Metric(1,2) - P(2,1)*Metric(1,3)')

VVVSS9 = Lorentz(name = 'VVVSS9',
                 spins = [ 3, 3, 3, 1, 1 ],
                 structure = 'P(3,1)*Metric(1,2) - P(3,4)*Metric(1,2) - P(3,5)*Metric(1,2) - P(2,1)*Metric(1,3) + P(2,4)*Metric(1,3) + P(2,5)*Metric(1,3)')

VVVSS10 = Lorentz(name = 'VVVSS10',
                  spins = [ 3, 3, 3, 1, 1 ],
                  structure = 'P(3,1)*Metric(1,2) + P(3,2)*Metric(1,2) - P(2,1)*Metric(1,3) - P(1,2)*Metric(2,3)')

VVVSS11 = Lorentz(name = 'VVVSS11',
                  spins = [ 3, 3, 3, 1, 1 ],
                  structure = 'P(2,3)*Metric(1,3) - P(1,3)*Metric(2,3)')

VVVSS12 = Lorentz(name = 'VVVSS12',
                  spins = [ 3, 3, 3, 1, 1 ],
                  structure = 'P(3,2)*Metric(1,2) + P(2,3)*Metric(1,3) - P(1,2)*Metric(2,3) - P(1,3)*Metric(2,3)')

VVVSS13 = Lorentz(name = 'VVVSS13',
                  spins = [ 3, 3, 3, 1, 1 ],
                  structure = 'P(3,1)*Metric(1,2) - P(3,2)*Metric(1,2) - P(2,1)*Metric(1,3) + P(2,3)*Metric(1,3) + P(1,2)*Metric(2,3) - P(1,3)*Metric(2,3)')

VVVSS14 = Lorentz(name = 'VVVSS14',
                  spins = [ 3, 3, 3, 1, 1 ],
                  structure = 'P(3,1)*Metric(1,2) + P(3,2)*Metric(1,2) - 4*P(3,4)*Metric(1,2) - P(2,1)*Metric(1,3) + 2*P(2,4)*Metric(1,3) - P(1,2)*Metric(2,3) + 2*P(1,4)*Metric(2,3)')

VVVSS15 = Lorentz(name = 'VVVSS15',
                  spins = [ 3, 3, 3, 1, 1 ],
                  structure = 'P(3,1)*Metric(1,2) - 2*P(3,2)*Metric(1,2) + 2*P(3,5)*Metric(1,2) - P(2,1)*Metric(1,3) + 2*P(2,3)*Metric(1,3) - 2*P(2,4)*Metric(1,3) + 2*P(1,2)*Metric(2,3) - 2*P(1,3)*Metric(2,3) + 2*P(1,4)*Metric(2,3) - 2*P(1,5)*Metric(2,3)')

VVVSS16 = Lorentz(name = 'VVVSS16',
                  spins = [ 3, 3, 3, 1, 1 ],
                  structure = 'P(3,1)*Metric(1,2) - P(3,2)*Metric(1,2) - P(2,1)*Metric(1,3) + P(2,4)*Metric(1,3) + P(2,5)*Metric(1,3) + P(1,2)*Metric(2,3) - P(1,4)*Metric(2,3) - P(1,5)*Metric(2,3)')

VVVSS17 = Lorentz(name = 'VVVSS17',
                  spins = [ 3, 3, 3, 1, 1 ],
                  structure = 'P(3,2)*Metric(1,2) - 2*P(3,5)*Metric(1,2) - P(2,3)*Metric(1,3) - P(2,4)*Metric(1,3) + 3*P(2,5)*Metric(1,3) - P(1,2)*Metric(2,3) + P(1,3)*Metric(2,3) + P(1,4)*Metric(2,3) - P(1,5)*Metric(2,3)')

VVVSS18 = Lorentz(name = 'VVVSS18',
                  spins = [ 3, 3, 3, 1, 1 ],
                  structure = 'P(3,4)*Metric(1,2) - P(3,5)*Metric(1,2) - (P(2,4)*Metric(1,3))/2. + (P(2,5)*Metric(1,3))/2. - (P(1,4)*Metric(2,3))/2. + (P(1,5)*Metric(2,3))/2.')

VVVSS19 = Lorentz(name = 'VVVSS19',
                  spins = [ 3, 3, 3, 1, 1 ],
                  structure = 'P(3,1)*Metric(1,2) - P(3,2)*Metric(1,2) + 2*P(3,4)*Metric(1,2) - 2*P(3,5)*Metric(1,2) - P(2,1)*Metric(1,3) + P(2,3)*Metric(1,3) - P(2,4)*Metric(1,3) + P(2,5)*Metric(1,3) + P(1,2)*Metric(2,3) - P(1,3)*Metric(2,3) - P(1,4)*Metric(2,3) + P(1,5)*Metric(2,3)')

VVVSS20 = Lorentz(name = 'VVVSS20',
                  spins = [ 3, 3, 3, 1, 1 ],
                  structure = 'P(3,2)*Metric(1,2) - 2*P(3,4)*Metric(1,2) - P(2,3)*Metric(1,3) + 3*P(2,4)*Metric(1,3) - P(2,5)*Metric(1,3) - P(1,2)*Metric(2,3) + P(1,3)*Metric(2,3) - P(1,4)*Metric(2,3) + P(1,5)*Metric(2,3)')

VVVSS21 = Lorentz(name = 'VVVSS21',
                  spins = [ 3, 3, 3, 1, 1 ],
                  structure = 'P(3,1)*Metric(1,2) + P(3,2)*Metric(1,2) - 4*P(3,5)*Metric(1,2) - P(2,1)*Metric(1,3) + 2*P(2,5)*Metric(1,3) - P(1,2)*Metric(2,3) + 2*P(1,5)*Metric(2,3)')

VVVSS22 = Lorentz(name = 'VVVSS22',
                  spins = [ 3, 3, 3, 1, 1 ],
                  structure = 'P(3,4)*Metric(1,2) - P(3,5)*Metric(1,2) + P(2,4)*Metric(1,3) - P(2,5)*Metric(1,3) - 2*P(1,4)*Metric(2,3) + 2*P(1,5)*Metric(2,3)')

VVVSS23 = Lorentz(name = 'VVVSS23',
                  spins = [ 3, 3, 3, 1, 1 ],
                  structure = 'P(3,2)*Metric(1,2) - P(3,4)*Metric(1,2) - P(3,5)*Metric(1,2) + P(2,3)*Metric(1,3) - P(2,4)*Metric(1,3) - P(2,5)*Metric(1,3) - P(1,2)*Metric(2,3) - P(1,3)*Metric(2,3) + 2*P(1,4)*Metric(2,3) + 2*P(1,5)*Metric(2,3)')

VVVVS1 = Lorentz(name = 'VVVVS1',
                 spins = [ 3, 3, 3, 3, 1 ],
                 structure = 'Metric(1,4)*Metric(2,3) + Metric(1,3)*Metric(2,4) - 2*Metric(1,2)*Metric(3,4)')

VVVVS2 = Lorentz(name = 'VVVVS2',
                 spins = [ 3, 3, 3, 3, 1 ],
                 structure = 'Metric(1,4)*Metric(2,3) - (Metric(1,3)*Metric(2,4))/2. - (Metric(1,2)*Metric(3,4))/2.')

VVVVV1 = Lorentz(name = 'VVVVV1',
                 spins = [ 3, 3, 3, 3, 3 ],
                 structure = 'Epsilon(2,3,4,5)*P(1,2) - Epsilon(2,3,4,5)*P(1,3) + Epsilon(1,3,4,5)*P(2,1) - Epsilon(1,3,4,5)*P(2,3) + Epsilon(1,2,4,5)*P(3,1) - Epsilon(1,2,4,5)*P(3,2) + Epsilon(3,4,5,-1)*P(-1,1)*Metric(1,2) + Epsilon(3,4,5,-1)*P(-1,2)*Metric(1,2) + Epsilon(3,4,5,-1)*P(-1,3)*Metric(1,2) + Epsilon(2,4,5,-1)*P(-1,1)*Metric(1,3) + Epsilon(2,4,5,-1)*P(-1,2)*Metric(1,3) + Epsilon(2,4,5,-1)*P(-1,3)*Metric(1,3) - (Epsilon(2,3,5,-1)*P(-1,2)*Metric(1,4))/2. + (Epsilon(2,3,5,-1)*P(-1,3)*Metric(1,4))/2. + (Epsilon(2,3,4,-1)*P(-1,2)*Metric(1,5))/2. - (Epsilon(2,3,4,-1)*P(-1,3)*Metric(1,5))/2. + Epsilon(1,4,5,-1)*P(-1,1)*Metric(2,3) + Epsilon(1,4,5,-1)*P(-1,2)*Metric(2,3) + Epsilon(1,4,5,-1)*P(-1,3)*Metric(2,3) - (Epsilon(1,3,5,-1)*P(-1,1)*Metric(2,4))/2. + (Epsilon(1,3,5,-1)*P(-1,3)*Metric(2,4))/2. + (Epsilon(1,3,4,-1)*P(-1,1)*Metric(2,5))/2. - (Epsilon(1,3,4,-1)*P(-1,3)*Metric(2,5))/2. - (Epsilon(1,2,5,-1)*P(-1,1)*Metric(3,4))/2. + (Epsilon(1,2,5,-1)*P(-1,2)*Metric(3,4))/2. + (Epsilon(1,2,4,-1)*P(-1,1)*Metric(3,5))/2. - (Epsilon(1,2,4,-1)*P(-1,2)*Metric(3,5))/2.')

VVVVV2 = Lorentz(name = 'VVVVV2',
                 spins = [ 3, 3, 3, 3, 3 ],
                 structure = 'P(5,1)*Metric(1,4)*Metric(2,3) - (P(5,2)*Metric(1,4)*Metric(2,3))/2. - (P(5,3)*Metric(1,4)*Metric(2,3))/2. - P(4,1)*Metric(1,5)*Metric(2,3) + (P(4,2)*Metric(1,5)*Metric(2,3))/2. + (P(4,3)*Metric(1,5)*Metric(2,3))/2. - (P(5,1)*Metric(1,3)*Metric(2,4))/2. + P(5,2)*Metric(1,3)*Metric(2,4) - (P(5,3)*Metric(1,3)*Metric(2,4))/2. + (P(3,1)*Metric(1,5)*Metric(2,4))/2. - (P(3,2)*Metric(1,5)*Metric(2,4))/2. + (P(4,1)*Metric(1,3)*Metric(2,5))/2. - P(4,2)*Metric(1,3)*Metric(2,5) + (P(4,3)*Metric(1,3)*Metric(2,5))/2. - (P(3,1)*Metric(1,4)*Metric(2,5))/2. + (P(3,2)*Metric(1,4)*Metric(2,5))/2. - (P(5,1)*Metric(1,2)*Metric(3,4))/2. - (P(5,2)*Metric(1,2)*Metric(3,4))/2. + P(5,3)*Metric(1,2)*Metric(3,4) + (P(2,1)*Metric(1,5)*Metric(3,4))/2. - (P(2,3)*Metric(1,5)*Metric(3,4))/2. + (P(1,2)*Metric(2,5)*Metric(3,4))/2. - (P(1,3)*Metric(2,5)*Metric(3,4))/2. + (P(4,1)*Metric(1,2)*Metric(3,5))/2. + (P(4,2)*Metric(1,2)*Metric(3,5))/2. - P(4,3)*Metric(1,2)*Metric(3,5) - (P(2,1)*Metric(1,4)*Metric(3,5))/2. + (P(2,3)*Metric(1,4)*Metric(3,5))/2. - (P(1,2)*Metric(2,4)*Metric(3,5))/2. + (P(1,3)*Metric(2,4)*Metric(3,5))/2.')

VVVVV3 = Lorentz(name = 'VVVVV3',
                 spins = [ 3, 3, 3, 3, 3 ],
                 structure = 'Epsilon(2,3,4,5)*P(1,2) - Epsilon(2,3,4,5)*P(1,5) + Epsilon(1,3,4,5)*P(2,1) - Epsilon(1,3,4,5)*P(2,5) + Epsilon(1,2,3,4)*P(5,1) - Epsilon(1,2,3,4)*P(5,2) + Epsilon(3,4,5,-1)*P(-1,1)*Metric(1,2) + Epsilon(3,4,5,-1)*P(-1,2)*Metric(1,2) + Epsilon(3,4,5,-1)*P(-1,5)*Metric(1,2) + (Epsilon(2,4,5,-1)*P(-1,2)*Metric(1,3))/2. - (Epsilon(2,4,5,-1)*P(-1,5)*Metric(1,3))/2. - (Epsilon(2,3,5,-1)*P(-1,2)*Metric(1,4))/2. + (Epsilon(2,3,5,-1)*P(-1,5)*Metric(1,4))/2. + Epsilon(2,3,4,-1)*P(-1,1)*Metric(1,5) + Epsilon(2,3,4,-1)*P(-1,2)*Metric(1,5) + Epsilon(2,3,4,-1)*P(-1,5)*Metric(1,5) + (Epsilon(1,4,5,-1)*P(-1,1)*Metric(2,3))/2. - (Epsilon(1,4,5,-1)*P(-1,5)*Metric(2,3))/2. - (Epsilon(1,3,5,-1)*P(-1,1)*Metric(2,4))/2. + (Epsilon(1,3,5,-1)*P(-1,5)*Metric(2,4))/2. + Epsilon(1,3,4,-1)*P(-1,1)*Metric(2,5) + Epsilon(1,3,4,-1)*P(-1,2)*Metric(2,5) + Epsilon(1,3,4,-1)*P(-1,5)*Metric(2,5) - (Epsilon(1,2,4,-1)*P(-1,1)*Metric(3,5))/2. + (Epsilon(1,2,4,-1)*P(-1,2)*Metric(3,5))/2. + (Epsilon(1,2,3,-1)*P(-1,1)*Metric(4,5))/2. - (Epsilon(1,2,3,-1)*P(-1,2)*Metric(4,5))/2.')

VVVVV4 = Lorentz(name = 'VVVVV4',
                 spins = [ 3, 3, 3, 3, 3 ],
                 structure = '-(Epsilon(2,3,4,5)*P(1,3)) + Epsilon(2,3,4,5)*P(1,4) - Epsilon(1,3,4,5)*P(2,3) + Epsilon(1,3,4,5)*P(2,4) + Epsilon(1,2,4,5)*P(3,1) - Epsilon(1,2,4,5)*P(3,2) + Epsilon(1,2,3,5)*P(4,1) - Epsilon(1,2,3,5)*P(4,2) + Epsilon(3,4,5,-1)*P(-1,3)*Metric(1,2) - Epsilon(3,4,5,-1)*P(-1,4)*Metric(1,2) + Epsilon(2,4,5,-1)*P(-1,1)*Metric(1,3) + (Epsilon(2,4,5,-1)*P(-1,2)*Metric(1,3))/2. + Epsilon(2,4,5,-1)*P(-1,3)*Metric(1,3) + (Epsilon(2,4,5,-1)*P(-1,4)*Metric(1,3))/2. + Epsilon(2,3,5,-1)*P(-1,1)*Metric(1,4) + (Epsilon(2,3,5,-1)*P(-1,2)*Metric(1,4))/2. + (Epsilon(2,3,5,-1)*P(-1,3)*Metric(1,4))/2. + Epsilon(2,3,5,-1)*P(-1,4)*Metric(1,4) - (Epsilon(2,3,4,-1)*P(-1,3)*Metric(1,5))/2. + (Epsilon(2,3,4,-1)*P(-1,4)*Metric(1,5))/2. + (Epsilon(1,4,5,-1)*P(-1,1)*Metric(2,3))/2. + Epsilon(1,4,5,-1)*P(-1,2)*Metric(2,3) + Epsilon(1,4,5,-1)*P(-1,3)*Metric(2,3) + (Epsilon(1,4,5,-1)*P(-1,4)*Metric(2,3))/2. + (Epsilon(1,3,5,-1)*P(-1,1)*Metric(2,4))/2. + Epsilon(1,3,5,-1)*P(-1,2)*Metric(2,4) + (Epsilon(1,3,5,-1)*P(-1,3)*Metric(2,4))/2. + Epsilon(1,3,5,-1)*P(-1,4)*Metric(2,4) - (Epsilon(1,3,4,-1)*P(-1,3)*Metric(2,5))/2. + (Epsilon(1,3,4,-1)*P(-1,4)*Metric(2,5))/2. - Epsilon(1,2,5,-1)*P(-1,1)*Metric(3,4) + Epsilon(1,2,5,-1)*P(-1,2)*Metric(3,4) + (Epsilon(1,2,4,-1)*P(-1,1)*Metric(3,5))/2. - (Epsilon(1,2,4,-1)*P(-1,2)*Metric(3,5))/2. + (Epsilon(1,2,3,-1)*P(-1,1)*Metric(4,5))/2. - (Epsilon(1,2,3,-1)*P(-1,2)*Metric(4,5))/2.')

VVVVV5 = Lorentz(name = 'VVVVV5',
                 spins = [ 3, 3, 3, 3, 3 ],
                 structure = '-(Epsilon(1,3,4,5)*P(2,4)) + Epsilon(1,3,4,5)*P(2,5) - Epsilon(1,2,4,5)*P(3,4) + Epsilon(1,2,4,5)*P(3,5) + Epsilon(1,2,3,5)*P(4,2) - Epsilon(1,2,3,5)*P(4,3) + Epsilon(1,2,3,4)*P(5,2) - Epsilon(1,2,3,4)*P(5,3) + (Epsilon(3,4,5,-1)*P(-1,4)*Metric(1,2))/2. - (Epsilon(3,4,5,-1)*P(-1,5)*Metric(1,2))/2. + (Epsilon(2,4,5,-1)*P(-1,4)*Metric(1,3))/2. - (Epsilon(2,4,5,-1)*P(-1,5)*Metric(1,3))/2. - (Epsilon(2,3,5,-1)*P(-1,2)*Metric(1,4))/2. + (Epsilon(2,3,5,-1)*P(-1,3)*Metric(1,4))/2. - (Epsilon(2,3,4,-1)*P(-1,2)*Metric(1,5))/2. + (Epsilon(2,3,4,-1)*P(-1,3)*Metric(1,5))/2. - Epsilon(1,4,5,-1)*P(-1,4)*Metric(2,3) + Epsilon(1,4,5,-1)*P(-1,5)*Metric(2,3) - Epsilon(1,3,5,-1)*P(-1,2)*Metric(2,4) - (Epsilon(1,3,5,-1)*P(-1,3)*Metric(2,4))/2. - Epsilon(1,3,5,-1)*P(-1,4)*Metric(2,4) - (Epsilon(1,3,5,-1)*P(-1,5)*Metric(2,4))/2. - Epsilon(1,3,4,-1)*P(-1,2)*Metric(2,5) - (Epsilon(1,3,4,-1)*P(-1,3)*Metric(2,5))/2. - (Epsilon(1,3,4,-1)*P(-1,4)*Metric(2,5))/2. - Epsilon(1,3,4,-1)*P(-1,5)*Metric(2,5) - (Epsilon(1,2,5,-1)*P(-1,2)*Metric(3,4))/2. - Epsilon(1,2,5,-1)*P(-1,3)*Metric(3,4) - Epsilon(1,2,5,-1)*P(-1,4)*Metric(3,4) - (Epsilon(1,2,5,-1)*P(-1,5)*Metric(3,4))/2. - (Epsilon(1,2,4,-1)*P(-1,2)*Metric(3,5))/2. - Epsilon(1,2,4,-1)*P(-1,3)*Metric(3,5) - (Epsilon(1,2,4,-1)*P(-1,4)*Metric(3,5))/2. - Epsilon(1,2,4,-1)*P(-1,5)*Metric(3,5) + Epsilon(1,2,3,-1)*P(-1,2)*Metric(4,5) - Epsilon(1,2,3,-1)*P(-1,3)*Metric(4,5)')

VVVVV6 = Lorentz(name = 'VVVVV6',
                 spins = [ 3, 3, 3, 3, 3 ],
                 structure = 'Epsilon(2,3,4,5)*P(1,4) - Epsilon(2,3,4,5)*P(1,5) + Epsilon(1,2,3,5)*P(4,1) - Epsilon(1,2,3,5)*P(4,5) + Epsilon(1,2,3,4)*P(5,1) - Epsilon(1,2,3,4)*P(5,4) - (Epsilon(3,4,5,-1)*P(-1,4)*Metric(1,2))/2. + (Epsilon(3,4,5,-1)*P(-1,5)*Metric(1,2))/2. + (Epsilon(2,4,5,-1)*P(-1,4)*Metric(1,3))/2. - (Epsilon(2,4,5,-1)*P(-1,5)*Metric(1,3))/2. + Epsilon(2,3,5,-1)*P(-1,1)*Metric(1,4) + Epsilon(2,3,5,-1)*P(-1,4)*Metric(1,4) + Epsilon(2,3,5,-1)*P(-1,5)*Metric(1,4) + Epsilon(2,3,4,-1)*P(-1,1)*Metric(1,5) + Epsilon(2,3,4,-1)*P(-1,4)*Metric(1,5) + Epsilon(2,3,4,-1)*P(-1,5)*Metric(1,5) + (Epsilon(1,3,5,-1)*P(-1,1)*Metric(2,4))/2. - (Epsilon(1,3,5,-1)*P(-1,5)*Metric(2,4))/2. + (Epsilon(1,3,4,-1)*P(-1,1)*Metric(2,5))/2. - (Epsilon(1,3,4,-1)*P(-1,4)*Metric(2,5))/2. - (Epsilon(1,2,5,-1)*P(-1,1)*Metric(3,4))/2. + (Epsilon(1,2,5,-1)*P(-1,5)*Metric(3,4))/2. - (Epsilon(1,2,4,-1)*P(-1,1)*Metric(3,5))/2. + (Epsilon(1,2,4,-1)*P(-1,4)*Metric(3,5))/2. + Epsilon(1,2,3,-1)*P(-1,1)*Metric(4,5) + Epsilon(1,2,3,-1)*P(-1,4)*Metric(4,5) + Epsilon(1,2,3,-1)*P(-1,5)*Metric(4,5)')

VVVVV7 = Lorentz(name = 'VVVVV7',
                 spins = [ 3, 3, 3, 3, 3 ],
                 structure = 'Epsilon(1,2,4,5)*P(3,4) - Epsilon(1,2,4,5)*P(3,5) + Epsilon(1,2,3,5)*P(4,3) - Epsilon(1,2,3,5)*P(4,5) + Epsilon(1,2,3,4)*P(5,3) - Epsilon(1,2,3,4)*P(5,4) - (Epsilon(2,4,5,-1)*P(-1,4)*Metric(1,3))/2. + (Epsilon(2,4,5,-1)*P(-1,5)*Metric(1,3))/2. - (Epsilon(2,3,5,-1)*P(-1,3)*Metric(1,4))/2. + (Epsilon(2,3,5,-1)*P(-1,5)*Metric(1,4))/2. - (Epsilon(2,3,4,-1)*P(-1,3)*Metric(1,5))/2. + (Epsilon(2,3,4,-1)*P(-1,4)*Metric(1,5))/2. + (Epsilon(1,4,5,-1)*P(-1,4)*Metric(2,3))/2. - (Epsilon(1,4,5,-1)*P(-1,5)*Metric(2,3))/2. + (Epsilon(1,3,5,-1)*P(-1,3)*Metric(2,4))/2. - (Epsilon(1,3,5,-1)*P(-1,5)*Metric(2,4))/2. + (Epsilon(1,3,4,-1)*P(-1,3)*Metric(2,5))/2. - (Epsilon(1,3,4,-1)*P(-1,4)*Metric(2,5))/2. + Epsilon(1,2,5,-1)*P(-1,3)*Metric(3,4) + Epsilon(1,2,5,-1)*P(-1,4)*Metric(3,4) + Epsilon(1,2,5,-1)*P(-1,5)*Metric(3,4) + Epsilon(1,2,4,-1)*P(-1,3)*Metric(3,5) + Epsilon(1,2,4,-1)*P(-1,4)*Metric(3,5) + Epsilon(1,2,4,-1)*P(-1,5)*Metric(3,5) + Epsilon(1,2,3,-1)*P(-1,3)*Metric(4,5) + Epsilon(1,2,3,-1)*P(-1,4)*Metric(4,5) + Epsilon(1,2,3,-1)*P(-1,5)*Metric(4,5)')

VVVVV8 = Lorentz(name = 'VVVVV8',
                 spins = [ 3, 3, 3, 3, 3 ],
                 structure = 'P(5,1)*Metric(1,3)*Metric(2,4) - P(5,4)*Metric(1,3)*Metric(2,4) - P(3,1)*Metric(1,5)*Metric(2,4) + 2*P(3,4)*Metric(1,5)*Metric(2,4) - P(3,5)*Metric(1,5)*Metric(2,4) + P(4,1)*Metric(1,3)*Metric(2,5) - P(4,5)*Metric(1,3)*Metric(2,5) - P(3,1)*Metric(1,4)*Metric(2,5) - P(3,4)*Metric(1,4)*Metric(2,5) + 2*P(3,5)*Metric(1,4)*Metric(2,5) - P(5,1)*Metric(1,2)*Metric(3,4) + P(5,4)*Metric(1,2)*Metric(3,4) + P(2,1)*Metric(1,5)*Metric(3,4) - 2*P(2,4)*Metric(1,5)*Metric(3,4) + P(2,5)*Metric(1,5)*Metric(3,4) + P(1,4)*Metric(2,5)*Metric(3,4) - P(1,5)*Metric(2,5)*Metric(3,4) - P(4,1)*Metric(1,2)*Metric(3,5) + P(4,5)*Metric(1,2)*Metric(3,5) + P(2,1)*Metric(1,4)*Metric(3,5) + P(2,4)*Metric(1,4)*Metric(3,5) - 2*P(2,5)*Metric(1,4)*Metric(3,5) - P(1,4)*Metric(2,4)*Metric(3,5) + P(1,5)*Metric(2,4)*Metric(3,5) + 2*P(3,1)*Metric(1,2)*Metric(4,5) - P(3,4)*Metric(1,2)*Metric(4,5) - P(3,5)*Metric(1,2)*Metric(4,5) - 2*P(2,1)*Metric(1,3)*Metric(4,5) + P(2,4)*Metric(1,3)*Metric(4,5) + P(2,5)*Metric(1,3)*Metric(4,5)')

VVVVV9 = Lorentz(name = 'VVVVV9',
                 spins = [ 3, 3, 3, 3, 3 ],
                 structure = 'P(5,1)*Metric(1,4)*Metric(2,3) + P(5,2)*Metric(1,4)*Metric(2,3) - P(5,3)*Metric(1,4)*Metric(2,3) - P(5,4)*Metric(1,4)*Metric(2,3) - P(4,1)*Metric(1,5)*Metric(2,3) + P(4,3)*Metric(1,5)*Metric(2,3) + P(5,1)*Metric(1,3)*Metric(2,4) + P(5,2)*Metric(1,3)*Metric(2,4) - P(5,3)*Metric(1,3)*Metric(2,4) - P(5,4)*Metric(1,3)*Metric(2,4) - P(3,1)*Metric(1,5)*Metric(2,4) + P(3,4)*Metric(1,5)*Metric(2,4) - P(4,2)*Metric(1,3)*Metric(2,5) + P(4,3)*Metric(1,3)*Metric(2,5) - P(3,2)*Metric(1,4)*Metric(2,5) + P(3,4)*Metric(1,4)*Metric(2,5) - 2*P(5,1)*Metric(1,2)*Metric(3,4) - 2*P(5,2)*Metric(1,2)*Metric(3,4) + 2*P(5,3)*Metric(1,2)*Metric(3,4) + 2*P(5,4)*Metric(1,2)*Metric(3,4) + 2*P(2,1)*Metric(1,5)*Metric(3,4) - P(2,3)*Metric(1,5)*Metric(3,4) - P(2,4)*Metric(1,5)*Metric(3,4) + 2*P(1,2)*Metric(2,5)*Metric(3,4) - P(1,3)*Metric(2,5)*Metric(3,4) - P(1,4)*Metric(2,5)*Metric(3,4) + P(4,1)*Metric(1,2)*Metric(3,5) + P(4,2)*Metric(1,2)*Metric(3,5) - 2*P(4,3)*Metric(1,2)*Metric(3,5) - P(2,1)*Metric(1,4)*Metric(3,5) + P(2,3)*Metric(1,4)*Metric(3,5) - P(1,2)*Metric(2,4)*Metric(3,5) + P(1,3)*Metric(2,4)*Metric(3,5) + P(3,1)*Metric(1,2)*Metric(4,5) + P(3,2)*Metric(1,2)*Metric(4,5) - 2*P(3,4)*Metric(1,2)*Metric(4,5) - P(2,1)*Metric(1,3)*Metric(4,5) + P(2,4)*Metric(1,3)*Metric(4,5) - P(1,2)*Metric(2,3)*Metric(4,5) + P(1,4)*Metric(2,3)*Metric(4,5)')

VVVVV10 = Lorentz(name = 'VVVVV10',
                  spins = [ 3, 3, 3, 3, 3 ],
                  structure = 'P(5,1)*Metric(1,4)*Metric(2,3) - P(5,2)*Metric(1,4)*Metric(2,3) - P(4,1)*Metric(1,5)*Metric(2,3) + 2*P(4,2)*Metric(1,5)*Metric(2,3) - P(4,5)*Metric(1,5)*Metric(2,3) - P(5,1)*Metric(1,3)*Metric(2,4) + P(5,2)*Metric(1,3)*Metric(2,4) + P(3,1)*Metric(1,5)*Metric(2,4) - 2*P(3,2)*Metric(1,5)*Metric(2,4) + P(3,5)*Metric(1,5)*Metric(2,4) + 2*P(4,1)*Metric(1,3)*Metric(2,5) - P(4,2)*Metric(1,3)*Metric(2,5) - P(4,5)*Metric(1,3)*Metric(2,5) - 2*P(3,1)*Metric(1,4)*Metric(2,5) + P(3,2)*Metric(1,4)*Metric(2,5) + P(3,5)*Metric(1,4)*Metric(2,5) - P(4,1)*Metric(1,2)*Metric(3,5) - P(4,2)*Metric(1,2)*Metric(3,5) + 2*P(4,5)*Metric(1,2)*Metric(3,5) + P(2,1)*Metric(1,4)*Metric(3,5) - P(2,5)*Metric(1,4)*Metric(3,5) + P(1,2)*Metric(2,4)*Metric(3,5) - P(1,5)*Metric(2,4)*Metric(3,5) + P(3,1)*Metric(1,2)*Metric(4,5) + P(3,2)*Metric(1,2)*Metric(4,5) - 2*P(3,5)*Metric(1,2)*Metric(4,5) - P(2,1)*Metric(1,3)*Metric(4,5) + P(2,5)*Metric(1,3)*Metric(4,5) - P(1,2)*Metric(2,3)*Metric(4,5) + P(1,5)*Metric(2,3)*Metric(4,5)')

VVVVV11 = Lorentz(name = 'VVVVV11',
                  spins = [ 3, 3, 3, 3, 3 ],
                  structure = 'P(5,3)*Metric(1,4)*Metric(2,3) - P(5,4)*Metric(1,4)*Metric(2,3) + P(4,3)*Metric(1,5)*Metric(2,3) - P(4,5)*Metric(1,5)*Metric(2,3) - P(5,3)*Metric(1,3)*Metric(2,4) + P(5,4)*Metric(1,3)*Metric(2,4) + P(3,4)*Metric(1,5)*Metric(2,4) - P(3,5)*Metric(1,5)*Metric(2,4) - P(4,3)*Metric(1,3)*Metric(2,5) + P(4,5)*Metric(1,3)*Metric(2,5) - P(3,4)*Metric(1,4)*Metric(2,5) + P(3,5)*Metric(1,4)*Metric(2,5) - P(2,3)*Metric(1,5)*Metric(3,4) - P(2,4)*Metric(1,5)*Metric(3,4) + 2*P(2,5)*Metric(1,5)*Metric(3,4) + P(1,3)*Metric(2,5)*Metric(3,4) + P(1,4)*Metric(2,5)*Metric(3,4) - 2*P(1,5)*Metric(2,5)*Metric(3,4) - P(2,3)*Metric(1,4)*Metric(3,5) + 2*P(2,4)*Metric(1,4)*Metric(3,5) - P(2,5)*Metric(1,4)*Metric(3,5) + P(1,3)*Metric(2,4)*Metric(3,5) - 2*P(1,4)*Metric(2,4)*Metric(3,5) + P(1,5)*Metric(2,4)*Metric(3,5) + 2*P(2,3)*Metric(1,3)*Metric(4,5) - P(2,4)*Metric(1,3)*Metric(4,5) - P(2,5)*Metric(1,3)*Metric(4,5) - 2*P(1,3)*Metric(2,3)*Metric(4,5) + P(1,4)*Metric(2,3)*Metric(4,5) + P(1,5)*Metric(2,3)*Metric(4,5)')

VVVVV12 = Lorentz(name = 'VVVVV12',
                  spins = [ 3, 3, 3, 3, 3 ],
                  structure = 'P(5,2)*Metric(1,4)*Metric(2,3) + P(5,3)*Metric(1,4)*Metric(2,3) - 2*P(5,4)*Metric(1,4)*Metric(2,3) + P(4,2)*Metric(1,5)*Metric(2,3) + P(4,3)*Metric(1,5)*Metric(2,3) - 2*P(4,5)*Metric(1,5)*Metric(2,3) - P(5,3)*Metric(1,3)*Metric(2,4) + P(5,4)*Metric(1,3)*Metric(2,4) - P(3,2)*Metric(1,5)*Metric(2,4) + P(3,5)*Metric(1,5)*Metric(2,4) - P(4,3)*Metric(1,3)*Metric(2,5) + P(4,5)*Metric(1,3)*Metric(2,5) - P(3,2)*Metric(1,4)*Metric(2,5) + P(3,4)*Metric(1,4)*Metric(2,5) - P(5,2)*Metric(1,2)*Metric(3,4) + P(5,4)*Metric(1,2)*Metric(3,4) - P(2,3)*Metric(1,5)*Metric(3,4) + P(2,5)*Metric(1,5)*Metric(3,4) + P(1,2)*Metric(2,5)*Metric(3,4) + P(1,3)*Metric(2,5)*Metric(3,4) - P(1,4)*Metric(2,5)*Metric(3,4) - P(1,5)*Metric(2,5)*Metric(3,4) - P(4,2)*Metric(1,2)*Metric(3,5) + P(4,5)*Metric(1,2)*Metric(3,5) - P(2,3)*Metric(1,4)*Metric(3,5) + P(2,4)*Metric(1,4)*Metric(3,5) + P(1,2)*Metric(2,4)*Metric(3,5) + P(1,3)*Metric(2,4)*Metric(3,5) - P(1,4)*Metric(2,4)*Metric(3,5) - P(1,5)*Metric(2,4)*Metric(3,5) + 2*P(3,2)*Metric(1,2)*Metric(4,5) - P(3,4)*Metric(1,2)*Metric(4,5) - P(3,5)*Metric(1,2)*Metric(4,5) + 2*P(2,3)*Metric(1,3)*Metric(4,5) - P(2,4)*Metric(1,3)*Metric(4,5) - P(2,5)*Metric(1,3)*Metric(4,5) - 2*P(1,2)*Metric(2,3)*Metric(4,5) - 2*P(1,3)*Metric(2,3)*Metric(4,5) + 2*P(1,4)*Metric(2,3)*Metric(4,5) + 2*P(1,5)*Metric(2,3)*Metric(4,5)')

VVVVSS1 = Lorentz(name = 'VVVVSS1',
                  spins = [ 3, 3, 3, 3, 1, 1 ],
                  structure = 'Metric(1,4)*Metric(2,3) + Metric(1,3)*Metric(2,4) - 2*Metric(1,2)*Metric(3,4)')

VVVVSS2 = Lorentz(name = 'VVVVSS2',
                  spins = [ 3, 3, 3, 3, 1, 1 ],
                  structure = 'Metric(1,4)*Metric(2,3) - (Metric(1,3)*Metric(2,4))/2. - (Metric(1,2)*Metric(3,4))/2.')

VVVVVV1 = Lorentz(name = 'VVVVVV1',
                  spins = [ 3, 3, 3, 3, 3, 3 ],
                  structure = 'Metric(1,6)*Metric(2,5)*Metric(3,4) + Metric(1,5)*Metric(2,6)*Metric(3,4) - (Metric(1,6)*Metric(2,4)*Metric(3,5))/2. - (Metric(1,4)*Metric(2,6)*Metric(3,5))/2. - (Metric(1,5)*Metric(2,4)*Metric(3,6))/2. - (Metric(1,4)*Metric(2,5)*Metric(3,6))/2. - (Metric(1,6)*Metric(2,3)*Metric(4,5))/2. - (Metric(1,3)*Metric(2,6)*Metric(4,5))/2. + Metric(1,2)*Metric(3,6)*Metric(4,5) - (Metric(1,5)*Metric(2,3)*Metric(4,6))/2. - (Metric(1,3)*Metric(2,5)*Metric(4,6))/2. + Metric(1,2)*Metric(3,5)*Metric(4,6) + Metric(1,4)*Metric(2,3)*Metric(5,6) + Metric(1,3)*Metric(2,4)*Metric(5,6) - 2*Metric(1,2)*Metric(3,4)*Metric(5,6)')

VVVVVV2 = Lorentz(name = 'VVVVVV2',
                  spins = [ 3, 3, 3, 3, 3, 3 ],
                  structure = 'Metric(1,6)*Metric(2,5)*Metric(3,4) - (Metric(1,5)*Metric(2,6)*Metric(3,4))/2. + Metric(1,6)*Metric(2,4)*Metric(3,5) - (Metric(1,4)*Metric(2,6)*Metric(3,5))/2. - (Metric(1,5)*Metric(2,4)*Metric(3,6))/2. - (Metric(1,4)*Metric(2,5)*Metric(3,6))/2. - 2*Metric(1,6)*Metric(2,3)*Metric(4,5) + Metric(1,3)*Metric(2,6)*Metric(4,5) + Metric(1,2)*Metric(3,6)*Metric(4,5) + Metric(1,5)*Metric(2,3)*Metric(4,6) - (Metric(1,3)*Metric(2,5)*Metric(4,6))/2. - (Metric(1,2)*Metric(3,5)*Metric(4,6))/2. + Metric(1,4)*Metric(2,3)*Metric(5,6) - (Metric(1,3)*Metric(2,4)*Metric(5,6))/2. - (Metric(1,2)*Metric(3,4)*Metric(5,6))/2.')

