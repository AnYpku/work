# This file was automatically created by FeynRules $Revision: 595 $
# Mathematica version: 9.0 for Mac OS X x86 (64-bit) (November 20, 2012)
# Date: Fri 7 Jun 2013 16:09:54


from object_library import all_couplings, Coupling

from function_library import complexconjugate, re, im, csc, sec, acsc, asec



GC_1 = Coupling(name = 'GC_1',
                value = '-(ee*complex(0,1))/3.',
                order = {'QED':1})

GC_2 = Coupling(name = 'GC_2',
                value = '(2*ee*complex(0,1))/3.',
                order = {'QED':1})

GC_3 = Coupling(name = 'GC_3',
                value = '-(ee*complex(0,1))',
                order = {'QED':1})

GC_4 = Coupling(name = 'GC_4',
                value = '2*complex(0,1)*FS0 + 2*complex(0,1)*FS1',
                order = {'NP':1})

GC_5 = Coupling(name = 'GC_5',
                value = '-G',
                order = {'QCD':1})

GC_6 = Coupling(name = 'GC_6',
                value = 'complex(0,1)*G',
                order = {'QCD':1})

GC_7 = Coupling(name = 'GC_7',
                value = 'complex(0,1)*G**2',
                order = {'QCD':2})

GC_8 = Coupling(name = 'GC_8',
                value = 'cw*complex(0,1)*gw',
                order = {'QED':1})

GC_9 = Coupling(name = 'GC_9',
                value = '-(complex(0,1)*gw**2)',
                order = {'QED':2})

GC_10 = Coupling(name = 'GC_10',
                 value = 'cw**2*complex(0,1)*gw**2',
                 order = {'QED':2})

GC_11 = Coupling(name = 'GC_11',
                 value = '-6*complex(0,1)*lam',
                 order = {'QED':2})

GC_12 = Coupling(name = 'GC_12',
                 value = '(3*ee**4*complex(0,1)*FS0)/(2.*cw**2) + (3*cw**2*ee**4*complex(0,1)*FS0)/(2.*sw**4) + (3*ee**4*complex(0,1)*FS0)/sw**2',
                 order = {'NP':1,'QED':4})

GC_13 = Coupling(name = 'GC_13',
                 value = '(3*ee**4*complex(0,1)*FS1)/cw**2 + (3*cw**2*ee**4*complex(0,1)*FS1)/sw**4 + (6*ee**4*complex(0,1)*FS1)/sw**2',
                 order = {'NP':1,'QED':4})

GC_14 = Coupling(name = 'GC_14',
                 value = '(-3*cw*ee**3*complex(0,1)*FS0)/(4.*sw**3) - (3*ee**3*complex(0,1)*FS0)/(4.*cw*sw)',
                 order = {'NP':1,'QED':3})

GC_15 = Coupling(name = 'GC_15',
                 value = '(6*ee**4*complex(0,1)*FS0)/sw**4',
                 order = {'NP':1,'QED':4})

GC_16 = Coupling(name = 'GC_16',
                 value = '(3*ee**4*complex(0,1)*FS1)/sw**4',
                 order = {'NP':1,'QED':4})

GC_17 = Coupling(name = 'GC_17',
                 value = '(ee**2*complex(0,1))/(2.*sw**2)',
                 order = {'QED':2})

GC_18 = Coupling(name = 'GC_18',
                 value = '-(ee**2*complex(0,1)*FS0)/(2.*sw**2)',
                 order = {'NP':1,'QED':2})

GC_19 = Coupling(name = 'GC_19',
                 value = '-((ee**2*complex(0,1)*FS1)/sw**2)',
                 order = {'NP':1,'QED':2})

GC_20 = Coupling(name = 'GC_20',
                 value = '(ee*complex(0,1))/(sw*cmath.sqrt(2))',
                 order = {'QED':1})

GC_21 = Coupling(name = 'GC_21',
                 value = '(CKM11*ee*complex(0,1))/(sw*cmath.sqrt(2))',
                 order = {'QED':1})

GC_22 = Coupling(name = 'GC_22',
                 value = '(CKM12*ee*complex(0,1))/(sw*cmath.sqrt(2))',
                 order = {'QED':1})

GC_23 = Coupling(name = 'GC_23',
                 value = '(CKM21*ee*complex(0,1))/(sw*cmath.sqrt(2))',
                 order = {'QED':1})

GC_24 = Coupling(name = 'GC_24',
                 value = '(CKM22*ee*complex(0,1))/(sw*cmath.sqrt(2))',
                 order = {'QED':1})

GC_25 = Coupling(name = 'GC_25',
                 value = '-(cw*ee*complex(0,1))/(2.*sw)',
                 order = {'QED':1})

GC_26 = Coupling(name = 'GC_26',
                 value = '(cw*ee*complex(0,1))/(2.*sw)',
                 order = {'QED':1})

GC_27 = Coupling(name = 'GC_27',
                 value = '-(ee*complex(0,1)*sw)/(6.*cw)',
                 order = {'QED':1})

GC_28 = Coupling(name = 'GC_28',
                 value = '(ee*complex(0,1)*sw)/(2.*cw)',
                 order = {'QED':1})

GC_29 = Coupling(name = 'GC_29',
                 value = 'complex(0,1)*gw*sw',
                 order = {'QED':1})

GC_30 = Coupling(name = 'GC_30',
                 value = '-2*cw*complex(0,1)*gw**2*sw',
                 order = {'QED':2})

GC_31 = Coupling(name = 'GC_31',
                 value = 'complex(0,1)*gw**2*sw**2',
                 order = {'QED':2})

GC_32 = Coupling(name = 'GC_32',
                 value = '(cw*ee*complex(0,1))/(2.*sw) + (ee*complex(0,1)*sw)/(2.*cw)',
                 order = {'QED':1})

GC_33 = Coupling(name = 'GC_33',
                 value = 'ee**2*complex(0,1) + (cw**2*ee**2*complex(0,1))/(2.*sw**2) + (ee**2*complex(0,1)*sw**2)/(2.*cw**2)',
                 order = {'QED':2})

GC_34 = Coupling(name = 'GC_34',
                 value = '-2*ee**2*complex(0,1)*FS0 - (cw**2*ee**2*complex(0,1)*FS0)/sw**2 - (ee**2*complex(0,1)*FS0*sw**2)/cw**2',
                 order = {'NP':1,'QED':2})

GC_35 = Coupling(name = 'GC_35',
                 value = '-2*ee**2*complex(0,1)*FS1 - (cw**2*ee**2*complex(0,1)*FS1)/sw**2 - (ee**2*complex(0,1)*FS1*sw**2)/cw**2',
                 order = {'NP':1,'QED':2})

GC_36 = Coupling(name = 'GC_36',
                 value = '18*ee**4*complex(0,1)*FS0 + 18*ee**4*complex(0,1)*FS1 + (3*cw**4*ee**4*complex(0,1)*FS0)/sw**4 + (3*cw**4*ee**4*complex(0,1)*FS1)/sw**4 + (12*cw**2*ee**4*complex(0,1)*FS0)/sw**2 + (12*cw**2*ee**4*complex(0,1)*FS1)/sw**2 + (12*ee**4*complex(0,1)*FS0*sw**2)/cw**2 + (12*ee**4*complex(0,1)*FS1*sw**2)/cw**2 + (3*ee**4*complex(0,1)*FS0*sw**4)/cw**4 + (3*ee**4*complex(0,1)*FS1*sw**4)/cw**4',
                 order = {'NP':1,'QED':4})

GC_37 = Coupling(name = 'GC_37',
                 value = '-6*complex(0,1)*lam*v',
                 order = {'QED':1})

GC_38 = Coupling(name = 'GC_38',
                 value = '(6*ee**4*complex(0,1)*FS0*v)/sw**4',
                 order = {'NP':1,'QED':3})

GC_39 = Coupling(name = 'GC_39',
                 value = '(3*ee**4*complex(0,1)*FS1*v)/sw**4',
                 order = {'NP':1,'QED':3})

GC_40 = Coupling(name = 'GC_40',
                 value = '(ee**2*complex(0,1)*v)/(2.*sw**2)',
                 order = {'QED':1})

GC_41 = Coupling(name = 'GC_41',
                 value = '-(ee**2*complex(0,1)*FS0*v)/(2.*sw**2)',
                 order = {'NP':1,'QED':1})

GC_42 = Coupling(name = 'GC_42',
                 value = '-((ee**2*complex(0,1)*FS1*v)/sw**2)',
                 order = {'NP':1,'QED':1})

GC_43 = Coupling(name = 'GC_43',
                 value = '(3*ee**4*complex(0,1)*FS0*v**2)/sw**4',
                 order = {'NP':1,'QED':2})

GC_44 = Coupling(name = 'GC_44',
                 value = '(3*ee**4*complex(0,1)*FS1*v**2)/(2.*sw**4)',
                 order = {'NP':1,'QED':2})

GC_45 = Coupling(name = 'GC_45',
                 value = '-(ee**2*complex(0,1)*FS0*v**2)/(4.*sw**2)',
                 order = {'NP':1})

GC_46 = Coupling(name = 'GC_46',
                 value = '-(ee**2*complex(0,1)*FS1*v**2)/(2.*sw**2)',
                 order = {'NP':1})

GC_47 = Coupling(name = 'GC_47',
                 value = '(ee**4*complex(0,1)*FS0*v**3)/sw**4',
                 order = {'NP':1,'QED':1})

GC_48 = Coupling(name = 'GC_48',
                 value = '(ee**4*complex(0,1)*FS1*v**3)/(2.*sw**4)',
                 order = {'NP':1,'QED':1})

GC_49 = Coupling(name = 'GC_49',
                 value = '(ee**4*complex(0,1)*FS0*v**4)/(4.*sw**4)',
                 order = {'NP':1})

GC_50 = Coupling(name = 'GC_50',
                 value = '(ee**4*complex(0,1)*FS1*v**4)/(8.*sw**4)',
                 order = {'NP':1})

GC_51 = Coupling(name = 'GC_51',
                 value = '(3*ee**4*complex(0,1)*FS0*v)/(2.*cw**2) + (3*cw**2*ee**4*complex(0,1)*FS0*v)/(2.*sw**4) + (3*ee**4*complex(0,1)*FS0*v)/sw**2',
                 order = {'NP':1,'QED':3})

GC_52 = Coupling(name = 'GC_52',
                 value = '(3*ee**4*complex(0,1)*FS1*v)/cw**2 + (3*cw**2*ee**4*complex(0,1)*FS1*v)/sw**4 + (6*ee**4*complex(0,1)*FS1*v)/sw**2',
                 order = {'NP':1,'QED':3})

GC_53 = Coupling(name = 'GC_53',
                 value = '(-3*cw*ee**3*complex(0,1)*FS0*v)/(4.*sw**3) - (3*ee**3*complex(0,1)*FS0*v)/(4.*cw*sw)',
                 order = {'NP':1,'QED':2})

GC_54 = Coupling(name = 'GC_54',
                 value = 'ee**2*complex(0,1)*v + (cw**2*ee**2*complex(0,1)*v)/(2.*sw**2) + (ee**2*complex(0,1)*sw**2*v)/(2.*cw**2)',
                 order = {'QED':1})

GC_55 = Coupling(name = 'GC_55',
                 value = '-2*ee**2*complex(0,1)*FS0*v - (cw**2*ee**2*complex(0,1)*FS0*v)/sw**2 - (ee**2*complex(0,1)*FS0*sw**2*v)/cw**2',
                 order = {'NP':1,'QED':1})

GC_56 = Coupling(name = 'GC_56',
                 value = '-2*ee**2*complex(0,1)*FS1*v - (cw**2*ee**2*complex(0,1)*FS1*v)/sw**2 - (ee**2*complex(0,1)*FS1*sw**2*v)/cw**2',
                 order = {'NP':1,'QED':1})

GC_57 = Coupling(name = 'GC_57',
                 value = '18*ee**4*complex(0,1)*FS0*v + 18*ee**4*complex(0,1)*FS1*v + (3*cw**4*ee**4*complex(0,1)*FS0*v)/sw**4 + (3*cw**4*ee**4*complex(0,1)*FS1*v)/sw**4 + (12*cw**2*ee**4*complex(0,1)*FS0*v)/sw**2 + (12*cw**2*ee**4*complex(0,1)*FS1*v)/sw**2 + (12*ee**4*complex(0,1)*FS0*sw**2*v)/cw**2 + (12*ee**4*complex(0,1)*FS1*sw**2*v)/cw**2 + (3*ee**4*complex(0,1)*FS0*sw**4*v)/cw**4 + (3*ee**4*complex(0,1)*FS1*sw**4*v)/cw**4',
                 order = {'NP':1,'QED':3})

GC_58 = Coupling(name = 'GC_58',
                 value = '(3*ee**4*complex(0,1)*FS0*v**2)/(4.*cw**2) + (3*cw**2*ee**4*complex(0,1)*FS0*v**2)/(4.*sw**4) + (3*ee**4*complex(0,1)*FS0*v**2)/(2.*sw**2)',
                 order = {'NP':1,'QED':2})

GC_59 = Coupling(name = 'GC_59',
                 value = '(3*ee**4*complex(0,1)*FS1*v**2)/(2.*cw**2) + (3*cw**2*ee**4*complex(0,1)*FS1*v**2)/(2.*sw**4) + (3*ee**4*complex(0,1)*FS1*v**2)/sw**2',
                 order = {'NP':1,'QED':2})

GC_60 = Coupling(name = 'GC_60',
                 value = '(-3*cw*ee**3*complex(0,1)*FS0*v**2)/(8.*sw**3) - (3*ee**3*complex(0,1)*FS0*v**2)/(8.*cw*sw)',
                 order = {'NP':1,'QED':1})

GC_61 = Coupling(name = 'GC_61',
                 value = '-(ee**2*complex(0,1)*FS0*v**2) - (cw**2*ee**2*complex(0,1)*FS0*v**2)/(2.*sw**2) - (ee**2*complex(0,1)*FS0*sw**2*v**2)/(2.*cw**2)',
                 order = {'NP':1})

GC_62 = Coupling(name = 'GC_62',
                 value = '-(ee**2*complex(0,1)*FS1*v**2) - (cw**2*ee**2*complex(0,1)*FS1*v**2)/(2.*sw**2) - (ee**2*complex(0,1)*FS1*sw**2*v**2)/(2.*cw**2)',
                 order = {'NP':1})

GC_63 = Coupling(name = 'GC_63',
                 value = '9*ee**4*complex(0,1)*FS0*v**2 + 9*ee**4*complex(0,1)*FS1*v**2 + (3*cw**4*ee**4*complex(0,1)*FS0*v**2)/(2.*sw**4) + (3*cw**4*ee**4*complex(0,1)*FS1*v**2)/(2.*sw**4) + (6*cw**2*ee**4*complex(0,1)*FS0*v**2)/sw**2 + (6*cw**2*ee**4*complex(0,1)*FS1*v**2)/sw**2 + (6*ee**4*complex(0,1)*FS0*sw**2*v**2)/cw**2 + (6*ee**4*complex(0,1)*FS1*sw**2*v**2)/cw**2 + (3*ee**4*complex(0,1)*FS0*sw**4*v**2)/(2.*cw**4) + (3*ee**4*complex(0,1)*FS1*sw**4*v**2)/(2.*cw**4)',
                 order = {'NP':1,'QED':2})

GC_64 = Coupling(name = 'GC_64',
                 value = '(ee**4*complex(0,1)*FS0*v**3)/(4.*cw**2) + (cw**2*ee**4*complex(0,1)*FS0*v**3)/(4.*sw**4) + (ee**4*complex(0,1)*FS0*v**3)/(2.*sw**2)',
                 order = {'NP':1,'QED':1})

GC_65 = Coupling(name = 'GC_65',
                 value = '(ee**4*complex(0,1)*FS1*v**3)/(2.*cw**2) + (cw**2*ee**4*complex(0,1)*FS1*v**3)/(2.*sw**4) + (ee**4*complex(0,1)*FS1*v**3)/sw**2',
                 order = {'NP':1,'QED':1})

GC_66 = Coupling(name = 'GC_66',
                 value = '-(cw*ee**3*complex(0,1)*FS0*v**3)/(8.*sw**3) - (ee**3*complex(0,1)*FS0*v**3)/(8.*cw*sw)',
                 order = {'NP':1})

GC_67 = Coupling(name = 'GC_67',
                 value = '3*ee**4*complex(0,1)*FS0*v**3 + 3*ee**4*complex(0,1)*FS1*v**3 + (cw**4*ee**4*complex(0,1)*FS0*v**3)/(2.*sw**4) + (cw**4*ee**4*complex(0,1)*FS1*v**3)/(2.*sw**4) + (2*cw**2*ee**4*complex(0,1)*FS0*v**3)/sw**2 + (2*cw**2*ee**4*complex(0,1)*FS1*v**3)/sw**2 + (2*ee**4*complex(0,1)*FS0*sw**2*v**3)/cw**2 + (2*ee**4*complex(0,1)*FS1*sw**2*v**3)/cw**2 + (ee**4*complex(0,1)*FS0*sw**4*v**3)/(2.*cw**4) + (ee**4*complex(0,1)*FS1*sw**4*v**3)/(2.*cw**4)',
                 order = {'NP':1,'QED':1})

GC_68 = Coupling(name = 'GC_68',
                 value = '(ee**4*complex(0,1)*FS0*v**4)/(16.*cw**2) + (cw**2*ee**4*complex(0,1)*FS0*v**4)/(16.*sw**4) + (ee**4*complex(0,1)*FS0*v**4)/(8.*sw**2)',
                 order = {'NP':1})

GC_69 = Coupling(name = 'GC_69',
                 value = '(ee**4*complex(0,1)*FS1*v**4)/(8.*cw**2) + (cw**2*ee**4*complex(0,1)*FS1*v**4)/(8.*sw**4) + (ee**4*complex(0,1)*FS1*v**4)/(4.*sw**2)',
                 order = {'NP':1})

GC_70 = Coupling(name = 'GC_70',
                 value = '(3*ee**4*complex(0,1)*FS0*v**4)/4. + (3*ee**4*complex(0,1)*FS1*v**4)/4. + (cw**4*ee**4*complex(0,1)*FS0*v**4)/(8.*sw**4) + (cw**4*ee**4*complex(0,1)*FS1*v**4)/(8.*sw**4) + (cw**2*ee**4*complex(0,1)*FS0*v**4)/(2.*sw**2) + (cw**2*ee**4*complex(0,1)*FS1*v**4)/(2.*sw**2) + (ee**4*complex(0,1)*FS0*sw**2*v**4)/(2.*cw**2) + (ee**4*complex(0,1)*FS1*sw**2*v**4)/(2.*cw**2) + (ee**4*complex(0,1)*FS0*sw**4*v**4)/(8.*cw**4) + (ee**4*complex(0,1)*FS1*sw**4*v**4)/(8.*cw**4)',
                 order = {'NP':1})

GC_71 = Coupling(name = 'GC_71',
                 value = '-((complex(0,1)*yb)/cmath.sqrt(2))',
                 order = {'QED':1})

GC_72 = Coupling(name = 'GC_72',
                 value = '-((complex(0,1)*yt)/cmath.sqrt(2))',
                 order = {'QED':1})

GC_73 = Coupling(name = 'GC_73',
                 value = '-((complex(0,1)*ytau)/cmath.sqrt(2))',
                 order = {'QED':1})

GC_74 = Coupling(name = 'GC_74',
                 value = '(ee*complex(0,1)*complexconjugate(CKM11))/(sw*cmath.sqrt(2))',
                 order = {'QED':1})

GC_75 = Coupling(name = 'GC_75',
                 value = '(ee*complex(0,1)*complexconjugate(CKM12))/(sw*cmath.sqrt(2))',
                 order = {'QED':1})

GC_76 = Coupling(name = 'GC_76',
                 value = '(ee*complex(0,1)*complexconjugate(CKM21))/(sw*cmath.sqrt(2))',
                 order = {'QED':1})

GC_77 = Coupling(name = 'GC_77',
                 value = '(ee*complex(0,1)*complexconjugate(CKM22))/(sw*cmath.sqrt(2))',
                 order = {'QED':1})

