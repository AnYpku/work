# This file was automatically created by FeynRules 2.1.7
# Mathematica version: 8.0 for Mac OS X x86 (64-bit) (November 6, 2010)
# Date: Fri 29 Nov 2013 12:01:43



from object_library import all_parameters, Parameter


from function_library import complexconjugate, re, im, csc, sec, acsc, asec, cot

# This is a default parameter object representing 0.
ZERO = Parameter(name = 'ZERO',
                 nature = 'internal',
                 type = 'real',
                 value = '0.0',
                 texname = '0')

# This is a default parameter object representing the renormalization scale (MU_R).
MU_R = Parameter(name = 'MU_R',
                 nature = 'external',
                 type = 'real',
                 value = 91.188,
                 texname = '\\text{\\mu_r}',
                 lhablock = 'LOOP',
                 lhacode = [1])

# User-defined parameters.
CWWWL2 = Parameter(name = 'CWWWL2',
                   nature = 'external',
                   type = 'real',
                   value = 1,
                   texname = '\\frac{C_{\\text{WWW}}}{\\Lambda ^2}',
                   lhablock = 'DIM6',
                   lhacode = [ 1 ])

CWL2 = Parameter(name = 'CWL2',
                 nature = 'external',
                 type = 'real',
                 value = 1,
                 texname = '\\frac{C_W}{\\Lambda ^2}',
                 lhablock = 'DIM6',
                 lhacode = [ 2 ])

CBL2 = Parameter(name = 'CBL2',
                 nature = 'external',
                 type = 'real',
                 value = 1,
                 texname = '\\frac{C_B}{\\Lambda ^2}',
                 lhablock = 'DIM6',
                 lhacode = [ 3 ])

CPWWWL2 = Parameter(name = 'CPWWWL2',
                    nature = 'external',
                    type = 'real',
                    value = 1,
                    texname = '\\frac{\\text{CP}_{\\text{WWW}}}{\\Lambda ^2}',
                    lhablock = 'DIM6',
                    lhacode = [ 4 ])

CPWL2 = Parameter(name = 'CPWL2',
                  nature = 'external',
                  type = 'real',
                  value = 1,
                  texname = '\\frac{\\text{CP}_W}{\\Lambda ^2}',
                  lhablock = 'DIM6',
                  lhacode = [ 5 ])

CphidL2 = Parameter(name = 'CphidL2',
                    nature = 'external',
                    type = 'real',
                    value = 1,
                    texname = '\\frac{C_{\\text{$\\phi $d}}}{\\Lambda ^2}',
                    lhablock = 'DIM6',
                    lhacode = [ 6 ])

CphiWL2 = Parameter(name = 'CphiWL2',
                    nature = 'external',
                    type = 'real',
                    value = 1,
                    texname = '\\frac{C_{\\text{$\\phi $W}}}{\\Lambda ^2}',
                    lhablock = 'DIM6',
                    lhacode = [ 7 ])

CphiBL2 = Parameter(name = 'CphiBL2',
                    nature = 'external',
                    type = 'real',
                    value = 1,
                    texname = '\\frac{C_{\\text{$\\phi $B}}}{\\Lambda ^2}',
                    lhablock = 'DIM6',
                    lhacode = [ 8 ])

aEWM1 = Parameter(name = 'aEWM1',
                  nature = 'external',
                  type = 'real',
                  value = 127.9,
                  texname = '\\text{aEWM1}',
                  lhablock = 'SMINPUTS',
                  lhacode = [ 1 ])

Gf = Parameter(name = 'Gf',
               nature = 'external',
               type = 'real',
               value = 0.0000116637,
               texname = 'G_f',
               lhablock = 'SMINPUTS',
               lhacode = [ 2 ])

aS = Parameter(name = 'aS',
               nature = 'external',
               type = 'real',
               value = 0.1184,
               texname = '\\alpha _s',
               lhablock = 'SMINPUTS',
               lhacode = [ 3 ])

lamWS = Parameter(name = 'lamWS',
                  nature = 'external',
                  type = 'real',
                  value = 0,
                  texname = '\\text{lamWS}',
                  lhablock = 'Wolfenstein',
                  lhacode = [ 1 ])

AWS = Parameter(name = 'AWS',
                nature = 'external',
                type = 'real',
                value = 0,
                texname = '\\text{AWS}',
                lhablock = 'Wolfenstein',
                lhacode = [ 2 ])

rhoWS = Parameter(name = 'rhoWS',
                  nature = 'external',
                  type = 'real',
                  value = 0,
                  texname = '\\text{rhoWS}',
                  lhablock = 'Wolfenstein',
                  lhacode = [ 3 ])

etaWS = Parameter(name = 'etaWS',
                  nature = 'external',
                  type = 'real',
                  value = 0,
                  texname = '\\text{etaWS}',
                  lhablock = 'Wolfenstein',
                  lhacode = [ 4 ])

ymc = Parameter(name = 'ymc',
                nature = 'external',
                type = 'real',
                value = 1.27,
                texname = '\\text{ymc}',
                lhablock = 'YUKAWA',
                lhacode = [ 4 ])

ymb = Parameter(name = 'ymb',
                nature = 'external',
                type = 'real',
                value = 4.7,
                texname = '\\text{ymb}',
                lhablock = 'YUKAWA',
                lhacode = [ 5 ])

ymt = Parameter(name = 'ymt',
                nature = 'external',
                type = 'real',
                value = 172,
                texname = '\\text{ymt}',
                lhablock = 'YUKAWA',
                lhacode = [ 6 ])

ymtau = Parameter(name = 'ymtau',
                  nature = 'external',
                  type = 'real',
                  value = 1.777,
                  texname = '\\text{ymtau}',
                  lhablock = 'YUKAWA',
                  lhacode = [ 15 ])

MZ = Parameter(name = 'MZ',
               nature = 'external',
               type = 'real',
               value = 91.1876,
               texname = '\\text{MZ}',
               lhablock = 'MASS',
               lhacode = [ 23 ])

MC = Parameter(name = 'MC',
               nature = 'external',
               type = 'real',
               value = 1.27,
               texname = '\\text{MC}',
               lhablock = 'MASS',
               lhacode = [ 4 ])

MT = Parameter(name = 'MT',
               nature = 'external',
               type = 'real',
               value = 172,
               texname = '\\text{MT}',
               lhablock = 'MASS',
               lhacode = [ 6 ])

MB = Parameter(name = 'MB',
               nature = 'external',
               type = 'real',
               value = 4.7,
               texname = '\\text{MB}',
               lhablock = 'MASS',
               lhacode = [ 5 ])

MH = Parameter(name = 'MH',
               nature = 'external',
               type = 'real',
               value = 120,
               texname = '\\text{MH}',
               lhablock = 'MASS',
               lhacode = [ 25 ])

WZ = Parameter(name = 'WZ',
               nature = 'external',
               type = 'real',
               value = 2.4952,
               texname = '\\text{WZ}',
               lhablock = 'DECAY',
               lhacode = [ 23 ])

WW = Parameter(name = 'WW',
               nature = 'external',
               type = 'real',
               value = 2.085,
               texname = '\\text{WW}',
               lhablock = 'DECAY',
               lhacode = [ 24 ])

WT = Parameter(name = 'WT',
               nature = 'external',
               type = 'real',
               value = 1.50833649,
               texname = '\\text{WT}',
               lhablock = 'DECAY',
               lhacode = [ 6 ])

WH = Parameter(name = 'WH',
               nature = 'external',
               type = 'real',
               value = 0.00575308848,
               texname = '\\text{WH}',
               lhablock = 'DECAY',
               lhacode = [ 25 ])

WTau = Parameter(name = 'WTau',
                 nature = 'external',
                 type = 'real',
                 value = 2.27e-12,
                 texname = '\\text{WTau}',
                 lhablock = 'DECAY',
                 lhacode = [ 15 ])

aEW = Parameter(name = 'aEW',
                nature = 'internal',
                type = 'real',
                value = '1/aEWM1',
                texname = '\\alpha _{\\text{EW}}')

G = Parameter(name = 'G',
              nature = 'internal',
              type = 'real',
              value = '2*cmath.sqrt(aS)*cmath.sqrt(cmath.pi)',
              texname = 'G')

vev = Parameter(name = 'vev',
                nature = 'internal',
                type = 'real',
                value = 'cmath.sqrt(1/Gf)/2**0.25',
                texname = '\\text{vev}')

MW = Parameter(name = 'MW',
               nature = 'internal',
               type = 'real',
               value = 'cmath.sqrt(MZ**2/2. + cmath.sqrt(MZ**4/4. - (aEW*cmath.pi*MZ**2)/(Gf*cmath.sqrt(2))))',
               texname = 'M_W')

ee = Parameter(name = 'ee',
               nature = 'internal',
               type = 'real',
               value = '2*cmath.sqrt(aEW)*cmath.sqrt(cmath.pi)',
               texname = 'e')

lam = Parameter(name = 'lam',
                nature = 'internal',
                type = 'real',
                value = '(4*MH**2 - (CphidL2*MH**2*vev**2)/250000.)/(8.*vev**2*(1 - (3*CphidL2*vev**2)/1.e6 + (CphidL2**2*vev**4)/5.e11))',
                texname = '\\text{lam}')

yb = Parameter(name = 'yb',
               nature = 'internal',
               type = 'real',
               value = '(ymb*cmath.sqrt(2))/vev',
               texname = '\\text{yb}')

yc = Parameter(name = 'yc',
               nature = 'internal',
               type = 'real',
               value = '(ymc*cmath.sqrt(2))/vev',
               texname = '\\text{yc}')

yt = Parameter(name = 'yt',
               nature = 'internal',
               type = 'real',
               value = '(ymt*cmath.sqrt(2))/vev',
               texname = '\\text{yt}')

ytau = Parameter(name = 'ytau',
                 nature = 'internal',
                 type = 'real',
                 value = '(ymtau*cmath.sqrt(2))/vev',
                 texname = '\\text{ytau}')

muH = Parameter(name = 'muH',
                nature = 'internal',
                type = 'real',
                value = 'cmath.sqrt((-4*lam*vev**2 + (CphidL2*lam*vev**4)/250000.)/(-1 + (CphidL2*vev**2)/1.e6))/2.',
                texname = '\\mu')

sw2 = Parameter(name = 'sw2',
                nature = 'internal',
                type = 'real',
                value = '1 - MW**2/MZ**2',
                texname = '\\text{sw2}')

cw = Parameter(name = 'cw',
               nature = 'internal',
               type = 'real',
               value = 'cmath.sqrt(1 - sw2)',
               texname = 'c_w')

sw = Parameter(name = 'sw',
               nature = 'internal',
               type = 'real',
               value = 'cmath.sqrt(sw2)',
               texname = 's_w')

g1 = Parameter(name = 'g1',
               nature = 'internal',
               type = 'real',
               value = 'ee/cw',
               texname = 'g_1')

gw = Parameter(name = 'gw',
               nature = 'internal',
               type = 'real',
               value = 'ee/sw',
               texname = 'g_w')

I1a33 = Parameter(name = 'I1a33',
                  nature = 'internal',
                  type = 'complex',
                  value = 'yb',
                  texname = '\\text{I1a33}')

I2a22 = Parameter(name = 'I2a22',
                  nature = 'internal',
                  type = 'complex',
                  value = 'yc',
                  texname = '\\text{I2a22}')

I2a33 = Parameter(name = 'I2a33',
                  nature = 'internal',
                  type = 'complex',
                  value = 'yt',
                  texname = '\\text{I2a33}')

I3a22 = Parameter(name = 'I3a22',
                  nature = 'internal',
                  type = 'complex',
                  value = 'yc',
                  texname = '\\text{I3a22}')

I3a33 = Parameter(name = 'I3a33',
                  nature = 'internal',
                  type = 'complex',
                  value = 'yt',
                  texname = '\\text{I3a33}')

I4a33 = Parameter(name = 'I4a33',
                  nature = 'internal',
                  type = 'complex',
                  value = 'yb',
                  texname = '\\text{I4a33}')

