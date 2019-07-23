# This file was automatically created by FeynRules $Revision: 915 $
# Mathematica version: 9.0 for Linux x86 (64-bit) (November 20, 2012)
# Date: Sat 31 Oct 2015 00:39:21


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
                value = '2*ee**2*FM2*complex(0,1)',
                order = {'QED':3})

GC_5 = Coupling(name = 'GC_5',
                value = '-(ee**2*FM3*complex(0,1))/2.',
                order = {'QED':3})

GC_6 = Coupling(name = 'GC_6',
                value = '-(ee*FM4*complex(0,1))/2.',
                order = {'QED':2})

GC_7 = Coupling(name = 'GC_7',
                value = '-(ee**2*FM4*complex(0,1))/2.',
                order = {'QED':3})

GC_8 = Coupling(name = 'GC_8',
                value = '(ee*FM5*complex(0,1))/8.',
                order = {'QED':2})

GC_9 = Coupling(name = 'GC_9',
                value = '(ee**2*FM5*complex(0,1))/8.',
                order = {'QED':3})

GC_10 = Coupling(name = 'GC_10',
                 value = '-2*FM0*complex(0,1) - FM6*complex(0,1)',
                 order = {'QED':1})

GC_11 = Coupling(name = 'GC_11',
                 value = '-(FM1*complex(0,1))/2. + (FM7*complex(0,1))/4.',
                 order = {'QED':1})

GC_12 = Coupling(name = 'GC_12',
                 value = '-(ee*FM7*complex(0,1))/8.',
                 order = {'QED':2})

GC_13 = Coupling(name = 'GC_13',
                 value = '-(ee**2*FM7*complex(0,1))/4.',
                 order = {'QED':3})

GC_14 = Coupling(name = 'GC_14',
                 value = '2*complex(0,1)*FS0 + 2*complex(0,1)*FS1',
                 order = {'QED':1})

GC_15 = Coupling(name = 'GC_15',
                 value = '8*complex(0,1)*FT0',
                 order = {'QED':1})

GC_16 = Coupling(name = 'GC_16',
                 value = '4*complex(0,1)*FT1',
                 order = {'QED':1})

GC_17 = Coupling(name = 'GC_17',
                 value = '2*complex(0,1)*FT2',
                 order = {'QED':1})

GC_18 = Coupling(name = 'GC_18',
                 value = '-G',
                 order = {'QCD':1})

GC_19 = Coupling(name = 'GC_19',
                 value = 'complex(0,1)*G',
                 order = {'QCD':1})

GC_20 = Coupling(name = 'GC_20',
                 value = 'complex(0,1)*G**2',
                 order = {'QCD':2})

GC_21 = Coupling(name = 'GC_21',
                 value = 'cw*complex(0,1)*gw',
                 order = {'QED':1})

GC_22 = Coupling(name = 'GC_22',
                 value = '-(cw*FM4*complex(0,1)*gw)',
                 order = {'QED':2})

GC_23 = Coupling(name = 'GC_23',
                 value = '(cw*ee*FM4*complex(0,1)*gw)/2.',
                 order = {'QED':3})

GC_24 = Coupling(name = 'GC_24',
                 value = '(cw*ee**2*FM4*complex(0,1)*gw)/2.',
                 order = {'QED':4})

GC_25 = Coupling(name = 'GC_25',
                 value = '-(cw*FM5*complex(0,1)*gw)/4.',
                 order = {'QED':2})

GC_26 = Coupling(name = 'GC_26',
                 value = '(cw*ee*FM5*complex(0,1)*gw)/8.',
                 order = {'QED':3})

GC_27 = Coupling(name = 'GC_27',
                 value = '(cw*ee*FM5*complex(0,1)*gw)/4.',
                 order = {'QED':3})

GC_28 = Coupling(name = 'GC_28',
                 value = '-(cw*ee**2*FM5*complex(0,1)*gw)/4.',
                 order = {'QED':4})

GC_29 = Coupling(name = 'GC_29',
                 value = '(cw*ee*FM7*complex(0,1)*gw)/8.',
                 order = {'QED':3})

GC_30 = Coupling(name = 'GC_30',
                 value = '(ee**2*FM7*complex(0,1)*gw)/(8.*cw)',
                 order = {'QED':4})

GC_31 = Coupling(name = 'GC_31',
                 value = '(cw*ee**2*FM7*complex(0,1)*gw)/2.',
                 order = {'QED':4})

GC_32 = Coupling(name = 'GC_32',
                 value = '-8*cw*complex(0,1)*FT0*gw',
                 order = {'QED':2})

GC_33 = Coupling(name = 'GC_33',
                 value = '8*cw*complex(0,1)*FT1*gw',
                 order = {'QED':2})

GC_34 = Coupling(name = 'GC_34',
                 value = '-(cw*complex(0,1)*FT2*gw)',
                 order = {'QED':2})

GC_35 = Coupling(name = 'GC_35',
                 value = '-8*cw**3*complex(0,1)*FT5*gw',
                 order = {'QED':2})

GC_36 = Coupling(name = 'GC_36',
                 value = '4*cw**3*complex(0,1)*FT6*gw',
                 order = {'QED':2})

GC_37 = Coupling(name = 'GC_37',
                 value = '-(cw**3*complex(0,1)*FT7*gw)',
                 order = {'QED':2})

GC_38 = Coupling(name = 'GC_38',
                 value = '-(complex(0,1)*gw**2)',
                 order = {'QED':2})

GC_39 = Coupling(name = 'GC_39',
                 value = 'cw**2*complex(0,1)*gw**2',
                 order = {'QED':2})

GC_40 = Coupling(name = 'GC_40',
                 value = 'ee**2*FM1*complex(0,1)*gw**2',
                 order = {'QED':5})

GC_41 = Coupling(name = 'GC_41',
                 value = '-(ee**2*FM7*complex(0,1)*gw**2)',
                 order = {'QED':5})

GC_42 = Coupling(name = 'GC_42',
                 value = '(-3*ee**2*FM7*complex(0,1)*gw**2)/2.',
                 order = {'QED':5})

GC_43 = Coupling(name = 'GC_43',
                 value = '8*complex(0,1)*FT0*gw**2',
                 order = {'QED':3})

GC_44 = Coupling(name = 'GC_44',
                 value = '8*cw**2*complex(0,1)*FT0*gw**2',
                 order = {'QED':3})

GC_45 = Coupling(name = 'GC_45',
                 value = '4*complex(0,1)*FT1*gw**2',
                 order = {'QED':3})

GC_46 = Coupling(name = 'GC_46',
                 value = '4*cw**2*complex(0,1)*FT1*gw**2',
                 order = {'QED':3})

GC_47 = Coupling(name = 'GC_47',
                 value = '2*complex(0,1)*FT2*gw**2',
                 order = {'QED':3})

GC_48 = Coupling(name = 'GC_48',
                 value = '2*cw**2*complex(0,1)*FT2*gw**2',
                 order = {'QED':3})

GC_49 = Coupling(name = 'GC_49',
                 value = '8*cw**2*complex(0,1)*FT5*gw**2',
                 order = {'QED':3})

GC_50 = Coupling(name = 'GC_50',
                 value = '-8*cw**4*complex(0,1)*FT5*gw**2',
                 order = {'QED':3})

GC_51 = Coupling(name = 'GC_51',
                 value = '4*cw**2*complex(0,1)*FT6*gw**2',
                 order = {'QED':3})

GC_52 = Coupling(name = 'GC_52',
                 value = '-4*cw**4*complex(0,1)*FT6*gw**2',
                 order = {'QED':3})

GC_53 = Coupling(name = 'GC_53',
                 value = '2*cw**2*complex(0,1)*FT7*gw**2',
                 order = {'QED':3})

GC_54 = Coupling(name = 'GC_54',
                 value = '-2*cw**4*complex(0,1)*FT7*gw**2',
                 order = {'QED':3})

GC_55 = Coupling(name = 'GC_55',
                 value = '-8*cw*complex(0,1)*FT0*gw**3',
                 order = {'QED':4})

GC_56 = Coupling(name = 'GC_56',
                 value = '8*cw**3*complex(0,1)*FT0*gw**3',
                 order = {'QED':4})

GC_57 = Coupling(name = 'GC_57',
                 value = '4*cw*complex(0,1)*FT1*gw**3',
                 order = {'QED':4})

GC_58 = Coupling(name = 'GC_58',
                 value = '-8*cw**3*complex(0,1)*FT1*gw**3',
                 order = {'QED':4})

GC_59 = Coupling(name = 'GC_59',
                 value = '-2*cw*complex(0,1)*FT2*gw**3',
                 order = {'QED':4})

GC_60 = Coupling(name = 'GC_60',
                 value = '-2*cw**3*complex(0,1)*FT2*gw**3',
                 order = {'QED':4})

GC_61 = Coupling(name = 'GC_61',
                 value = '-8*cw**2*complex(0,1)*FT0*gw**4',
                 order = {'QED':5})

GC_62 = Coupling(name = 'GC_62',
                 value = '16*cw**4*complex(0,1)*FT0*gw**4',
                 order = {'QED':5})

GC_63 = Coupling(name = 'GC_63',
                 value = '-16*cw**2*complex(0,1)*FT1*gw**4',
                 order = {'QED':5})

GC_64 = Coupling(name = 'GC_64',
                 value = '16*cw**4*complex(0,1)*FT1*gw**4',
                 order = {'QED':5})

GC_65 = Coupling(name = 'GC_65',
                 value = '-4*cw**2*complex(0,1)*FT2*gw**4',
                 order = {'QED':5})

GC_66 = Coupling(name = 'GC_66',
                 value = '8*cw**4*complex(0,1)*FT2*gw**4',
                 order = {'QED':5})

GC_67 = Coupling(name = 'GC_67',
                 value = '2*cw*FM0*complex(0,1)*gw + cw*FM6*complex(0,1)*gw',
                 order = {'QED':2})

GC_68 = Coupling(name = 'GC_68',
                 value = '-(cw*FM1*complex(0,1)*gw)/2. + (cw*FM7*complex(0,1)*gw)/4.',
                 order = {'QED':2})

GC_69 = Coupling(name = 'GC_69',
                 value = '-2*FM0*complex(0,1)*gw**2 - FM6*complex(0,1)*gw**2',
                 order = {'QED':3})

GC_70 = Coupling(name = 'GC_70',
                 value = '2*cw**2*FM0*complex(0,1)*gw**2 + cw**2*FM6*complex(0,1)*gw**2',
                 order = {'QED':3})

GC_71 = Coupling(name = 'GC_71',
                 value = '-(ee**2*FM0*complex(0,1)*gw**2) - (ee**2*FM6*complex(0,1)*gw**2)/2.',
                 order = {'QED':5})

GC_72 = Coupling(name = 'GC_72',
                 value = '-(FM1*complex(0,1)*gw**2) + (FM7*complex(0,1)*gw**2)/2.',
                 order = {'QED':3})

GC_73 = Coupling(name = 'GC_73',
                 value = 'cw**2*FM1*complex(0,1)*gw**2 - (cw**2*FM7*complex(0,1)*gw**2)/2.',
                 order = {'QED':3})

GC_74 = Coupling(name = 'GC_74',
                 value = '24*complex(0,1)*FT0*gw**4 + 24*complex(0,1)*FT1*gw**4 + 12*complex(0,1)*FT2*gw**4',
                 order = {'QED':5})

GC_75 = Coupling(name = 'GC_75',
                 value = '-6*complex(0,1)*lam',
                 order = {'QED':2})

GC_76 = Coupling(name = 'GC_76',
                 value = '(ee**2*FM0*complex(0,1))/sw**2 + (ee**2*FM6*complex(0,1))/(2.*sw**2)',
                 order = {'QED':3})

GC_77 = Coupling(name = 'GC_77',
                 value = '(cw**2*ee**2*FM0*complex(0,1))/sw**2 + (cw**2*ee**2*FM6*complex(0,1))/(2.*sw**2)',
                 order = {'QED':3})

GC_78 = Coupling(name = 'GC_78',
                 value = '(3*ee**4*complex(0,1)*FS0)/(2.*cw**2) + (3*cw**2*ee**4*complex(0,1)*FS0)/(2.*sw**4) + (3*ee**4*complex(0,1)*FS0)/sw**2',
                 order = {'QED':5})

GC_79 = Coupling(name = 'GC_79',
                 value = '(3*ee**4*complex(0,1)*FS1)/cw**2 + (3*cw**2*ee**4*complex(0,1)*FS1)/sw**4 + (6*ee**4*complex(0,1)*FS1)/sw**2',
                 order = {'QED':5})

GC_80 = Coupling(name = 'GC_80',
                 value = '-(cw*ee**2*FM4*complex(0,1)*gw)/(2.*sw**2) - (cw*ee**2*FM5*complex(0,1)*gw)/(4.*sw**2)',
                 order = {'QED':4})

GC_81 = Coupling(name = 'GC_81',
                 value = '-((cw*ee**2*FM0*complex(0,1)*gw)/sw**2) - (cw*ee**2*FM6*complex(0,1)*gw)/(2.*sw**2)',
                 order = {'QED':4})

GC_82 = Coupling(name = 'GC_82',
                 value = '-((cw**2*ee**2*FM0*complex(0,1)*gw**2)/sw**2) - (cw**2*ee**2*FM6*complex(0,1)*gw**2)/(2.*sw**2)',
                 order = {'QED':5})

GC_83 = Coupling(name = 'GC_83',
                 value = '(3*ee**2*FM0*complex(0,1)*gw**2)/sw**2 - (3*ee**2*FM1*complex(0,1)*gw**2)/(2.*sw**2) + (3*ee**2*FM6*complex(0,1)*gw**2)/(2.*sw**2) + (3*ee**2*FM7*complex(0,1)*gw**2)/(4.*sw**2)',
                 order = {'QED':5})

GC_84 = Coupling(name = 'GC_84',
                 value = '-(cw*ee**2*FM1*complex(0,1))/(4.*sw) + (cw*ee**2*FM3*complex(0,1))/(2.*sw)',
                 order = {'QED':3})

GC_85 = Coupling(name = 'GC_85',
                 value = 'ee**2*FM0*complex(0,1) + (ee**2*FM6*complex(0,1))/2. + (2*cw**2*ee**2*FM2*complex(0,1))/sw**2 + (cw*ee**2*FM4*complex(0,1))/sw',
                 order = {'QED':3})

GC_86 = Coupling(name = 'GC_86',
                 value = '(ee**2*FM1*complex(0,1))/4. - (ee**2*FM7*complex(0,1))/8. + (cw**2*ee**2*FM3*complex(0,1))/(2.*sw**2) - (cw*ee**2*FM5*complex(0,1))/(4.*sw)',
                 order = {'QED':3})

GC_87 = Coupling(name = 'GC_87',
                 value = '(cw*ee**2*FM0*complex(0,1))/sw - (2*cw*ee**2*FM2*complex(0,1))/sw + (cw*ee**2*FM6*complex(0,1))/(2.*sw)',
                 order = {'QED':3})

GC_88 = Coupling(name = 'GC_88',
                 value = '(-3*cw*ee**3*complex(0,1)*FS0)/(4.*sw**3) - (3*ee**3*complex(0,1)*FS0)/(4.*cw*sw)',
                 order = {'QED':4})

GC_89 = Coupling(name = 'GC_89',
                 value = '(ee**2*FM4*complex(0,1)*gw)/(2.*sw) + (ee**2*FM5*complex(0,1)*gw)/(4.*sw)',
                 order = {'QED':4})

GC_90 = Coupling(name = 'GC_90',
                 value = '-((ee**2*FM0*complex(0,1)*gw)/sw) - (ee**2*FM6*complex(0,1)*gw)/(2.*sw)',
                 order = {'QED':4})

GC_91 = Coupling(name = 'GC_91',
                 value = '(4*cw*ee**2*FM0*complex(0,1)*gw**2)/sw + (2*cw*ee**2*FM6*complex(0,1)*gw**2)/sw',
                 order = {'QED':5})

GC_92 = Coupling(name = 'GC_92',
                 value = '(6*ee**4*complex(0,1)*FS0)/sw**4',
                 order = {'QED':5})

GC_93 = Coupling(name = 'GC_93',
                 value = '(3*ee**4*complex(0,1)*FS1)/sw**4',
                 order = {'QED':5})

GC_94 = Coupling(name = 'GC_94',
                 value = '(ee**2*complex(0,1))/(2.*sw**2)',
                 order = {'QED':2})

GC_95 = Coupling(name = 'GC_95',
                 value = '-(ee**2*FM1*complex(0,1))/(4.*sw**2)',
                 order = {'QED':3})

GC_96 = Coupling(name = 'GC_96',
                 value = '(cw**2*ee**2*FM1*complex(0,1))/(4.*sw**2)',
                 order = {'QED':3})

GC_97 = Coupling(name = 'GC_97',
                 value = '(cw**2*ee**2*FM4*complex(0,1))/(2.*sw**2)',
                 order = {'QED':3})

GC_98 = Coupling(name = 'GC_98',
                 value = '(cw**2*ee**2*FM5*complex(0,1))/(8.*sw**2)',
                 order = {'QED':3})

GC_99 = Coupling(name = 'GC_99',
                 value = '(ee**2*FM7*complex(0,1))/(4.*sw**2)',
                 order = {'QED':3})

GC_100 = Coupling(name = 'GC_100',
                  value = '-(cw**2*ee**2*FM7*complex(0,1))/(8.*sw**2)',
                  order = {'QED':3})

GC_101 = Coupling(name = 'GC_101',
                  value = '-(ee**2*complex(0,1)*FS0)/(2.*sw**2)',
                  order = {'QED':3})

GC_102 = Coupling(name = 'GC_102',
                  value = '-((ee**2*complex(0,1)*FS1)/sw**2)',
                  order = {'QED':3})

GC_103 = Coupling(name = 'GC_103',
                  value = '(cw*ee**2*FM1*complex(0,1)*gw)/(4.*sw**2)',
                  order = {'QED':4})

GC_104 = Coupling(name = 'GC_104',
                  value = '(cw**3*ee**2*FM4*complex(0,1)*gw)/(2.*sw**2)',
                  order = {'QED':4})

GC_105 = Coupling(name = 'GC_105',
                  value = '-(cw**3*ee**2*FM5*complex(0,1)*gw)/(8.*sw**2)',
                  order = {'QED':4})

GC_106 = Coupling(name = 'GC_106',
                  value = '(cw*ee**2*FM7*complex(0,1)*gw)/(8.*sw**2)',
                  order = {'QED':4})

GC_107 = Coupling(name = 'GC_107',
                  value = '(3*cw**3*ee**2*FM7*complex(0,1)*gw)/(8.*sw**2)',
                  order = {'QED':4})

GC_108 = Coupling(name = 'GC_108',
                  value = '(3*cw**2*ee**2*FM1*complex(0,1)*gw**2)/(2.*sw**2)',
                  order = {'QED':5})

GC_109 = Coupling(name = 'GC_109',
                  value = '(-9*cw**2*ee**2*FM7*complex(0,1)*gw**2)/(4.*sw**2)',
                  order = {'QED':5})

GC_110 = Coupling(name = 'GC_110',
                  value = '(ee*complex(0,1))/(sw*cmath.sqrt(2))',
                  order = {'QED':1})

GC_111 = Coupling(name = 'GC_111',
                  value = '(CKM11*ee*complex(0,1))/(sw*cmath.sqrt(2))',
                  order = {'QED':1})

GC_112 = Coupling(name = 'GC_112',
                  value = '(CKM12*ee*complex(0,1))/(sw*cmath.sqrt(2))',
                  order = {'QED':1})

GC_113 = Coupling(name = 'GC_113',
                  value = '(CKM21*ee*complex(0,1))/(sw*cmath.sqrt(2))',
                  order = {'QED':1})

GC_114 = Coupling(name = 'GC_114',
                  value = '(CKM22*ee*complex(0,1))/(sw*cmath.sqrt(2))',
                  order = {'QED':1})

GC_115 = Coupling(name = 'GC_115',
                  value = '-(cw*ee*complex(0,1))/(2.*sw)',
                  order = {'QED':1})

GC_116 = Coupling(name = 'GC_116',
                  value = '(cw*ee*complex(0,1))/(2.*sw)',
                  order = {'QED':1})

GC_117 = Coupling(name = 'GC_117',
                  value = '(cw*ee*FM4*complex(0,1))/(2.*sw)',
                  order = {'QED':2})

GC_118 = Coupling(name = 'GC_118',
                  value = '-((cw*ee**2*FM4*complex(0,1))/sw)',
                  order = {'QED':3})

GC_119 = Coupling(name = 'GC_119',
                  value = '-(cw*ee*FM5*complex(0,1))/(8.*sw)',
                  order = {'QED':2})

GC_120 = Coupling(name = 'GC_120',
                  value = '(cw*ee**2*FM5*complex(0,1))/(8.*sw)',
                  order = {'QED':3})

GC_121 = Coupling(name = 'GC_121',
                  value = '-(cw*ee*FM7*complex(0,1))/(8.*sw)',
                  order = {'QED':2})

GC_122 = Coupling(name = 'GC_122',
                  value = '(cw*ee**2*FM7*complex(0,1))/(8.*sw)',
                  order = {'QED':3})

GC_123 = Coupling(name = 'GC_123',
                  value = '-(ee**2*FM1*complex(0,1)*gw)/(4.*sw)',
                  order = {'QED':4})

GC_124 = Coupling(name = 'GC_124',
                  value = '-(cw**2*ee*FM4*complex(0,1)*gw)/(2.*sw)',
                  order = {'QED':3})

GC_125 = Coupling(name = 'GC_125',
                  value = '-(cw**2*ee**2*FM4*complex(0,1)*gw)/(2.*sw)',
                  order = {'QED':4})

GC_126 = Coupling(name = 'GC_126',
                  value = '-(cw**2*ee*FM5*complex(0,1)*gw)/(8.*sw)',
                  order = {'QED':3})

GC_127 = Coupling(name = 'GC_127',
                  value = '(cw**2*ee**2*FM5*complex(0,1)*gw)/(8.*sw)',
                  order = {'QED':4})

GC_128 = Coupling(name = 'GC_128',
                  value = '(ee*FM7*complex(0,1)*gw)/(8.*sw)',
                  order = {'QED':3})

GC_129 = Coupling(name = 'GC_129',
                  value = '-(cw**2*ee*FM7*complex(0,1)*gw)/(8.*sw)',
                  order = {'QED':3})

GC_130 = Coupling(name = 'GC_130',
                  value = '(ee**2*FM7*complex(0,1)*gw)/(4.*sw)',
                  order = {'QED':4})

GC_131 = Coupling(name = 'GC_131',
                  value = '-(cw**2*ee**2*FM7*complex(0,1)*gw)/(8.*sw)',
                  order = {'QED':4})

GC_132 = Coupling(name = 'GC_132',
                  value = '-((cw*ee**2*FM1*complex(0,1)*gw**2)/sw)',
                  order = {'QED':5})

GC_133 = Coupling(name = 'GC_133',
                  value = '-(cw*ee**2*FM7*complex(0,1)*gw**2)/(2.*sw)',
                  order = {'QED':5})

GC_134 = Coupling(name = 'GC_134',
                  value = '-(ee*complex(0,1)*sw)/(6.*cw)',
                  order = {'QED':1})

GC_135 = Coupling(name = 'GC_135',
                  value = '(ee*complex(0,1)*sw)/(2.*cw)',
                  order = {'QED':1})

GC_136 = Coupling(name = 'GC_136',
                  value = '(ee**2*FM4*complex(0,1)*sw)/(2.*cw)',
                  order = {'QED':3})

GC_137 = Coupling(name = 'GC_137',
                  value = '(ee**2*FM5*complex(0,1)*sw)/(8.*cw)',
                  order = {'QED':3})

GC_138 = Coupling(name = 'GC_138',
                  value = '-(ee*FM7*complex(0,1)*sw)/(8.*cw)',
                  order = {'QED':2})

GC_139 = Coupling(name = 'GC_139',
                  value = '(ee**2*FM7*complex(0,1)*sw)/(8.*cw)',
                  order = {'QED':3})

GC_140 = Coupling(name = 'GC_140',
                  value = 'complex(0,1)*gw*sw',
                  order = {'QED':1})

GC_141 = Coupling(name = 'GC_141',
                  value = 'FM4*complex(0,1)*gw*sw',
                  order = {'QED':2})

GC_142 = Coupling(name = 'GC_142',
                  value = '-(ee*FM4*complex(0,1)*gw*sw)/2.',
                  order = {'QED':3})

GC_143 = Coupling(name = 'GC_143',
                  value = '(FM5*complex(0,1)*gw*sw)/4.',
                  order = {'QED':2})

GC_144 = Coupling(name = 'GC_144',
                  value = '-(ee*FM5*complex(0,1)*gw*sw)/8.',
                  order = {'QED':3})

GC_145 = Coupling(name = 'GC_145',
                  value = '-(ee*FM7*complex(0,1)*gw*sw)/8.',
                  order = {'QED':3})

GC_146 = Coupling(name = 'GC_146',
                  value = '-(ee**2*FM7*complex(0,1)*gw*sw)/4.',
                  order = {'QED':4})

GC_147 = Coupling(name = 'GC_147',
                  value = '-8*complex(0,1)*FT0*gw*sw',
                  order = {'QED':2})

GC_148 = Coupling(name = 'GC_148',
                  value = '-8*cw**2*complex(0,1)*FT0*gw*sw',
                  order = {'QED':2})

GC_149 = Coupling(name = 'GC_149',
                  value = '4*complex(0,1)*FT1*gw*sw',
                  order = {'QED':2})

GC_150 = Coupling(name = 'GC_150',
                  value = '4*cw**2*complex(0,1)*FT1*gw*sw',
                  order = {'QED':2})

GC_151 = Coupling(name = 'GC_151',
                  value = '-(complex(0,1)*FT2*gw*sw)',
                  order = {'QED':2})

GC_152 = Coupling(name = 'GC_152',
                  value = '-(cw**2*complex(0,1)*FT2*gw*sw)',
                  order = {'QED':2})

GC_153 = Coupling(name = 'GC_153',
                  value = '8*cw**2*complex(0,1)*FT5*gw*sw',
                  order = {'QED':2})

GC_154 = Coupling(name = 'GC_154',
                  value = '-4*cw**2*complex(0,1)*FT6*gw*sw',
                  order = {'QED':2})

GC_155 = Coupling(name = 'GC_155',
                  value = 'cw**2*complex(0,1)*FT7*gw*sw',
                  order = {'QED':2})

GC_156 = Coupling(name = 'GC_156',
                  value = '-2*cw*complex(0,1)*gw**2*sw',
                  order = {'QED':2})

GC_157 = Coupling(name = 'GC_157',
                  value = '-(ee**2*FM7*complex(0,1)*gw**2*sw)/(2.*cw)',
                  order = {'QED':5})

GC_158 = Coupling(name = 'GC_158',
                  value = '8*cw*complex(0,1)*FT0*gw**2*sw',
                  order = {'QED':3})

GC_159 = Coupling(name = 'GC_159',
                  value = '16*cw**3*complex(0,1)*FT0*gw**2*sw',
                  order = {'QED':3})

GC_160 = Coupling(name = 'GC_160',
                  value = '4*cw*complex(0,1)*FT1*gw**2*sw',
                  order = {'QED':3})

GC_161 = Coupling(name = 'GC_161',
                  value = '-4*cw**3*complex(0,1)*FT1*gw**2*sw',
                  order = {'QED':3})

GC_162 = Coupling(name = 'GC_162',
                  value = 'cw*complex(0,1)*FT2*gw**2*sw',
                  order = {'QED':3})

GC_163 = Coupling(name = 'GC_163',
                  value = '-2*cw**3*complex(0,1)*FT2*gw**2*sw',
                  order = {'QED':3})

GC_164 = Coupling(name = 'GC_164',
                  value = '-8*cw*complex(0,1)*FT5*gw**2*sw',
                  order = {'QED':3})

GC_165 = Coupling(name = 'GC_165',
                  value = '8*cw**3*complex(0,1)*FT5*gw**2*sw',
                  order = {'QED':3})

GC_166 = Coupling(name = 'GC_166',
                  value = '16*cw**3*complex(0,1)*FT5*gw**2*sw',
                  order = {'QED':3})

GC_167 = Coupling(name = 'GC_167',
                  value = '-4*cw*complex(0,1)*FT6*gw**2*sw',
                  order = {'QED':3})

GC_168 = Coupling(name = 'GC_168',
                  value = '4*cw**3*complex(0,1)*FT6*gw**2*sw',
                  order = {'QED':3})

GC_169 = Coupling(name = 'GC_169',
                  value = '2*cw*complex(0,1)*FT7*gw**2*sw',
                  order = {'QED':3})

GC_170 = Coupling(name = 'GC_170',
                  value = 'cw**3*complex(0,1)*FT7*gw**2*sw',
                  order = {'QED':3})

GC_171 = Coupling(name = 'GC_171',
                  value = '2*cw**3*complex(0,1)*FT7*gw**2*sw',
                  order = {'QED':3})

GC_172 = Coupling(name = 'GC_172',
                  value = '-8*complex(0,1)*FT0*gw**3*sw',
                  order = {'QED':4})

GC_173 = Coupling(name = 'GC_173',
                  value = '-16*cw**2*complex(0,1)*FT0*gw**3*sw',
                  order = {'QED':4})

GC_174 = Coupling(name = 'GC_174',
                  value = '4*complex(0,1)*FT1*gw**3*sw',
                  order = {'QED':4})

GC_175 = Coupling(name = 'GC_175',
                  value = '-8*cw**2*complex(0,1)*FT1*gw**3*sw',
                  order = {'QED':4})

GC_176 = Coupling(name = 'GC_176',
                  value = 'complex(0,1)*FT2*gw**3*sw',
                  order = {'QED':4})

GC_177 = Coupling(name = 'GC_177',
                  value = '-6*cw**2*complex(0,1)*FT2*gw**3*sw',
                  order = {'QED':4})

GC_178 = Coupling(name = 'GC_178',
                  value = '48*cw*complex(0,1)*FT0*gw**4*sw',
                  order = {'QED':5})

GC_179 = Coupling(name = 'GC_179',
                  value = '-16*cw**3*complex(0,1)*FT0*gw**4*sw',
                  order = {'QED':5})

GC_180 = Coupling(name = 'GC_180',
                  value = '8*cw*complex(0,1)*FT1*gw**4*sw',
                  order = {'QED':5})

GC_181 = Coupling(name = 'GC_181',
                  value = '-16*cw**3*complex(0,1)*FT1*gw**4*sw',
                  order = {'QED':5})

GC_182 = Coupling(name = 'GC_182',
                  value = '12*cw*complex(0,1)*FT2*gw**4*sw',
                  order = {'QED':5})

GC_183 = Coupling(name = 'GC_183',
                  value = '-4*cw**3*complex(0,1)*FT2*gw**4*sw',
                  order = {'QED':5})

GC_184 = Coupling(name = 'GC_184',
                  value = '-8*cw**2*complex(0,1)*FT6*sw**2',
                  order = {'QED':1})

GC_185 = Coupling(name = 'GC_185',
                  value = '-4*cw**2*complex(0,1)*FT7*sw**2',
                  order = {'QED':1})

GC_186 = Coupling(name = 'GC_186',
                  value = '(ee**2*FM4*complex(0,1)*gw*sw**2)/(2.*cw)',
                  order = {'QED':4})

GC_187 = Coupling(name = 'GC_187',
                  value = '-(ee**2*FM5*complex(0,1)*gw*sw**2)/(8.*cw)',
                  order = {'QED':4})

GC_188 = Coupling(name = 'GC_188',
                  value = '(ee*FM7*complex(0,1)*gw*sw**2)/(8.*cw)',
                  order = {'QED':3})

GC_189 = Coupling(name = 'GC_189',
                  value = '-8*cw*complex(0,1)*FT0*gw*sw**2',
                  order = {'QED':2})

GC_190 = Coupling(name = 'GC_190',
                  value = '4*cw*complex(0,1)*FT1*gw*sw**2',
                  order = {'QED':2})

GC_191 = Coupling(name = 'GC_191',
                  value = '-(cw*complex(0,1)*FT2*gw*sw**2)',
                  order = {'QED':2})

GC_192 = Coupling(name = 'GC_192',
                  value = '8*cw*complex(0,1)*FT5*gw*sw**2',
                  order = {'QED':2})

GC_193 = Coupling(name = 'GC_193',
                  value = '-4*cw*complex(0,1)*FT6*gw*sw**2',
                  order = {'QED':2})

GC_194 = Coupling(name = 'GC_194',
                  value = 'cw*complex(0,1)*FT7*gw*sw**2',
                  order = {'QED':2})

GC_195 = Coupling(name = 'GC_195',
                  value = 'complex(0,1)*gw**2*sw**2',
                  order = {'QED':2})

GC_196 = Coupling(name = 'GC_196',
                  value = '8*complex(0,1)*FT0*gw**2*sw**2',
                  order = {'QED':3})

GC_197 = Coupling(name = 'GC_197',
                  value = '-8*cw**2*complex(0,1)*FT0*gw**2*sw**2',
                  order = {'QED':3})

GC_198 = Coupling(name = 'GC_198',
                  value = '8*complex(0,1)*FT1*gw**2*sw**2',
                  order = {'QED':3})

GC_199 = Coupling(name = 'GC_199',
                  value = '-4*cw**2*complex(0,1)*FT1*gw**2*sw**2',
                  order = {'QED':3})

GC_200 = Coupling(name = 'GC_200',
                  value = '2*complex(0,1)*FT2*gw**2*sw**2',
                  order = {'QED':3})

GC_201 = Coupling(name = 'GC_201',
                  value = '-(cw**2*complex(0,1)*FT2*gw**2*sw**2)',
                  order = {'QED':3})

GC_202 = Coupling(name = 'GC_202',
                  value = '8*complex(0,1)*FT5*gw**2*sw**2',
                  order = {'QED':3})

GC_203 = Coupling(name = 'GC_203',
                  value = '-16*cw**2*complex(0,1)*FT5*gw**2*sw**2',
                  order = {'QED':3})

GC_204 = Coupling(name = 'GC_204',
                  value = '4*complex(0,1)*FT6*gw**2*sw**2',
                  order = {'QED':3})

GC_205 = Coupling(name = 'GC_205',
                  value = '-4*cw**2*complex(0,1)*FT6*gw**2*sw**2',
                  order = {'QED':3})

GC_206 = Coupling(name = 'GC_206',
                  value = 'complex(0,1)*FT7*gw**2*sw**2',
                  order = {'QED':3})

GC_207 = Coupling(name = 'GC_207',
                  value = 'cw**2*complex(0,1)*FT7*gw**2*sw**2',
                  order = {'QED':3})

GC_208 = Coupling(name = 'GC_208',
                  value = '8*cw*complex(0,1)*FT0*gw**3*sw**2',
                  order = {'QED':4})

GC_209 = Coupling(name = 'GC_209',
                  value = '-8*cw*complex(0,1)*FT1*gw**3*sw**2',
                  order = {'QED':4})

GC_210 = Coupling(name = 'GC_210',
                  value = '-2*cw*complex(0,1)*FT2*gw**3*sw**2',
                  order = {'QED':4})

GC_211 = Coupling(name = 'GC_211',
                  value = '-8*complex(0,1)*FT0*gw**4*sw**2',
                  order = {'QED':5})

GC_212 = Coupling(name = 'GC_212',
                  value = '64*cw**2*complex(0,1)*FT0*gw**4*sw**2',
                  order = {'QED':5})

GC_213 = Coupling(name = 'GC_213',
                  value = '-16*complex(0,1)*FT1*gw**4*sw**2',
                  order = {'QED':5})

GC_214 = Coupling(name = 'GC_214',
                  value = '32*cw**2*complex(0,1)*FT1*gw**4*sw**2',
                  order = {'QED':5})

GC_215 = Coupling(name = 'GC_215',
                  value = '-4*complex(0,1)*FT2*gw**4*sw**2',
                  order = {'QED':5})

GC_216 = Coupling(name = 'GC_216',
                  value = '24*cw**2*complex(0,1)*FT2*gw**4*sw**2',
                  order = {'QED':5})

GC_217 = Coupling(name = 'GC_217',
                  value = '-(ee**2*FM4*complex(0,1)*gw*sw**3)/(2.*cw**2)',
                  order = {'QED':4})

GC_218 = Coupling(name = 'GC_218',
                  value = '(ee**2*FM5*complex(0,1)*gw*sw**3)/(8.*cw**2)',
                  order = {'QED':4})

GC_219 = Coupling(name = 'GC_219',
                  value = '-8*complex(0,1)*FT5*gw*sw**3',
                  order = {'QED':2})

GC_220 = Coupling(name = 'GC_220',
                  value = '4*complex(0,1)*FT6*gw*sw**3',
                  order = {'QED':2})

GC_221 = Coupling(name = 'GC_221',
                  value = '-(complex(0,1)*FT7*gw*sw**3)',
                  order = {'QED':2})

GC_222 = Coupling(name = 'GC_222',
                  value = '-8*cw*complex(0,1)*FT0*gw**2*sw**3',
                  order = {'QED':3})

GC_223 = Coupling(name = 'GC_223',
                  value = '4*cw*complex(0,1)*FT1*gw**2*sw**3',
                  order = {'QED':3})

GC_224 = Coupling(name = 'GC_224',
                  value = 'cw*complex(0,1)*FT2*gw**2*sw**3',
                  order = {'QED':3})

GC_225 = Coupling(name = 'GC_225',
                  value = '8*cw*complex(0,1)*FT5*gw**2*sw**3',
                  order = {'QED':3})

GC_226 = Coupling(name = 'GC_226',
                  value = '16*cw*complex(0,1)*FT5*gw**2*sw**3',
                  order = {'QED':3})

GC_227 = Coupling(name = 'GC_227',
                  value = '4*cw*complex(0,1)*FT6*gw**2*sw**3',
                  order = {'QED':3})

GC_228 = Coupling(name = 'GC_228',
                  value = '-2*cw*complex(0,1)*FT7*gw**2*sw**3',
                  order = {'QED':3})

GC_229 = Coupling(name = 'GC_229',
                  value = '2*cw*complex(0,1)*FT7*gw**2*sw**3',
                  order = {'QED':3})

GC_230 = Coupling(name = 'GC_230',
                  value = '8*complex(0,1)*FT0*gw**3*sw**3',
                  order = {'QED':4})

GC_231 = Coupling(name = 'GC_231',
                  value = '-4*complex(0,1)*FT1*gw**3*sw**3',
                  order = {'QED':4})

GC_232 = Coupling(name = 'GC_232',
                  value = '2*complex(0,1)*FT2*gw**3*sw**3',
                  order = {'QED':4})

GC_233 = Coupling(name = 'GC_233',
                  value = '-16*cw*complex(0,1)*FT0*gw**4*sw**3',
                  order = {'QED':5})

GC_234 = Coupling(name = 'GC_234',
                  value = '-16*cw*complex(0,1)*FT1*gw**4*sw**3',
                  order = {'QED':5})

GC_235 = Coupling(name = 'GC_235',
                  value = '-4*cw*complex(0,1)*FT2*gw**4*sw**3',
                  order = {'QED':5})

GC_236 = Coupling(name = 'GC_236',
                  value = '-8*complex(0,1)*FT5*gw**2*sw**4',
                  order = {'QED':3})

GC_237 = Coupling(name = 'GC_237',
                  value = '-4*complex(0,1)*FT6*gw**2*sw**4',
                  order = {'QED':3})

GC_238 = Coupling(name = 'GC_238',
                  value = '-(complex(0,1)*FT7*gw**2*sw**4)',
                  order = {'QED':3})

GC_239 = Coupling(name = 'GC_239',
                  value = '16*complex(0,1)*FT0*gw**4*sw**4',
                  order = {'QED':5})

GC_240 = Coupling(name = 'GC_240',
                  value = '16*complex(0,1)*FT1*gw**4*sw**4',
                  order = {'QED':5})

GC_241 = Coupling(name = 'GC_241',
                  value = '8*complex(0,1)*FT2*gw**4*sw**4',
                  order = {'QED':5})

GC_242 = Coupling(name = 'GC_242',
                  value = '(cw*ee*complex(0,1))/(2.*sw) + (ee*complex(0,1)*sw)/(2.*cw)',
                  order = {'QED':1})

GC_243 = Coupling(name = 'GC_243',
                  value = '8*cw*complex(0,1)*FT0*sw - 8*cw*complex(0,1)*FT5*sw',
                  order = {'QED':1})

GC_244 = Coupling(name = 'GC_244',
                  value = '4*cw*complex(0,1)*FT1*sw - 4*cw*complex(0,1)*FT6*sw',
                  order = {'QED':1})

GC_245 = Coupling(name = 'GC_245',
                  value = 'cw*complex(0,1)*FT2*sw - cw*complex(0,1)*FT7*sw',
                  order = {'QED':1})

GC_246 = Coupling(name = 'GC_246',
                  value = '-(cw**2*ee**2*FM4*complex(0,1)*gw)/(2.*sw) - (ee**2*FM4*complex(0,1)*gw*sw)/2.',
                  order = {'QED':4})

GC_247 = Coupling(name = 'GC_247',
                  value = '(cw**2*ee**2*FM5*complex(0,1)*gw)/(8.*sw) + (ee**2*FM5*complex(0,1)*gw*sw)/8.',
                  order = {'QED':4})

GC_248 = Coupling(name = 'GC_248',
                  value = '-(ee**2*FM4*complex(0,1)*gw*sw)/2. + (ee**2*FM5*complex(0,1)*gw*sw)/4.',
                  order = {'QED':4})

GC_249 = Coupling(name = 'GC_249',
                  value = '2*FM0*complex(0,1)*gw*sw + FM6*complex(0,1)*gw*sw',
                  order = {'QED':2})

GC_250 = Coupling(name = 'GC_250',
                  value = '-(FM1*complex(0,1)*gw*sw)/2. + (FM7*complex(0,1)*gw*sw)/4.',
                  order = {'QED':2})

GC_251 = Coupling(name = 'GC_251',
                  value = '-4*cw*FM0*complex(0,1)*gw**2*sw - 2*cw*FM6*complex(0,1)*gw**2*sw',
                  order = {'QED':3})

GC_252 = Coupling(name = 'GC_252',
                  value = '-(cw*FM1*complex(0,1)*gw**2*sw)/2. + (cw*FM7*complex(0,1)*gw**2*sw)/4.',
                  order = {'QED':3})

GC_253 = Coupling(name = 'GC_253',
                  value = 'ee**2*complex(0,1) + (cw**2*ee**2*complex(0,1))/(2.*sw**2) + (ee**2*complex(0,1)*sw**2)/(2.*cw**2)',
                  order = {'QED':2})

GC_254 = Coupling(name = 'GC_254',
                  value = '-2*cw**2*FM0*complex(0,1) - cw**2*FM6*complex(0,1) - 2*cw*FM4*complex(0,1)*sw - 4*FM2*complex(0,1)*sw**2',
                  order = {'QED':1})

GC_255 = Coupling(name = 'GC_255',
                  value = '-(cw**2*FM1*complex(0,1))/2. + (cw**2*FM7*complex(0,1))/4. + (cw*FM5*complex(0,1)*sw)/2. - FM3*complex(0,1)*sw**2',
                  order = {'QED':1})

GC_256 = Coupling(name = 'GC_256',
                  value = 'cw**2*FM4*complex(0,1) - 2*cw*FM0*complex(0,1)*sw + 4*cw*FM2*complex(0,1)*sw - cw*FM6*complex(0,1)*sw - FM4*complex(0,1)*sw**2',
                  order = {'QED':1})

GC_257 = Coupling(name = 'GC_257',
                  value = '-(cw**2*FM5*complex(0,1))/4. - (cw*FM1*complex(0,1)*sw)/2. + cw*FM3*complex(0,1)*sw + (cw*FM7*complex(0,1)*sw)/4. + (FM5*complex(0,1)*sw**2)/4.',
                  order = {'QED':1})

GC_258 = Coupling(name = 'GC_258',
                  value = '-4*cw**2*FM2*complex(0,1) + 2*cw*FM4*complex(0,1)*sw - 2*FM0*complex(0,1)*sw**2 - FM6*complex(0,1)*sw**2',
                  order = {'QED':1})

GC_259 = Coupling(name = 'GC_259',
                  value = '2*ee**2*FM0*complex(0,1) + ee**2*FM6*complex(0,1) + (ee**2*FM0*complex(0,1)*sw**2)/cw**2 + (ee**2*FM6*complex(0,1)*sw**2)/(2.*cw**2)',
                  order = {'QED':3})

GC_260 = Coupling(name = 'GC_260',
                  value = '-(cw**2*FM3*complex(0,1)) - (cw*FM5*complex(0,1)*sw)/2. - (FM1*complex(0,1)*sw**2)/2. + (FM7*complex(0,1)*sw**2)/4.',
                  order = {'QED':1})

GC_261 = Coupling(name = 'GC_261',
                  value = '(ee**2*FM1*complex(0,1))/2. + (ee**2*FM1*complex(0,1)*sw**2)/(4.*cw**2) - (ee**2*FM7*complex(0,1)*sw**2)/(8.*cw**2)',
                  order = {'QED':3})

GC_262 = Coupling(name = 'GC_262',
                  value = '-2*ee**2*complex(0,1)*FS0 - (cw**2*ee**2*complex(0,1)*FS0)/sw**2 - (ee**2*complex(0,1)*FS0*sw**2)/cw**2',
                  order = {'QED':3})

GC_263 = Coupling(name = 'GC_263',
                  value = '-2*ee**2*complex(0,1)*FS1 - (cw**2*ee**2*complex(0,1)*FS1)/sw**2 - (ee**2*complex(0,1)*FS1*sw**2)/cw**2',
                  order = {'QED':3})

GC_264 = Coupling(name = 'GC_264',
                  value = '8*cw**2*complex(0,1)*FT5 + 8*complex(0,1)*FT0*sw**2',
                  order = {'QED':1})

GC_265 = Coupling(name = 'GC_265',
                  value = '4*cw**2*complex(0,1)*FT6 + 4*complex(0,1)*FT1*sw**2',
                  order = {'QED':1})

GC_266 = Coupling(name = 'GC_266',
                  value = 'cw**2*complex(0,1)*FT7 + complex(0,1)*FT2*sw**2',
                  order = {'QED':1})

GC_267 = Coupling(name = 'GC_267',
                  value = '8*cw**2*complex(0,1)*FT0 + 8*complex(0,1)*FT5*sw**2',
                  order = {'QED':1})

GC_268 = Coupling(name = 'GC_268',
                  value = '4*cw**2*complex(0,1)*FT1 + 4*complex(0,1)*FT6*sw**2',
                  order = {'QED':1})

GC_269 = Coupling(name = 'GC_269',
                  value = 'cw**2*complex(0,1)*FT2 + complex(0,1)*FT7*sw**2',
                  order = {'QED':1})

GC_270 = Coupling(name = 'GC_270',
                  value = '8*cw**2*complex(0,1)*FT0*sw**2 + 8*cw**2*complex(0,1)*FT1*sw**2 + 32*cw**2*complex(0,1)*FT8*sw**2',
                  order = {'QED':1})

GC_271 = Coupling(name = 'GC_271',
                  value = '2*cw**2*complex(0,1)*FT2*sw**2 + 8*cw**2*complex(0,1)*FT9*sw**2',
                  order = {'QED':1})

GC_272 = Coupling(name = 'GC_272',
                  value = '-2*cw*ee**2*FM0*complex(0,1)*gw - cw*ee**2*FM6*complex(0,1)*gw - (cw**3*ee**2*FM0*complex(0,1)*gw)/sw**2 - (cw**3*ee**2*FM6*complex(0,1)*gw)/(2.*sw**2) - (ee**2*FM0*complex(0,1)*gw*sw**2)/cw - (ee**2*FM6*complex(0,1)*gw*sw**2)/(2.*cw)',
                  order = {'QED':4})

GC_273 = Coupling(name = 'GC_273',
                  value = '(cw*ee**2*FM7*complex(0,1)*gw)/8. + (ee**2*FM7*complex(0,1)*gw*sw**2)/(8.*cw)',
                  order = {'QED':4})

GC_274 = Coupling(name = 'GC_274',
                  value = '-(cw*ee**2*FM1*complex(0,1)*gw)/2. - (cw**3*ee**2*FM1*complex(0,1)*gw)/(4.*sw**2) - (ee**2*FM1*complex(0,1)*gw*sw**2)/(4.*cw) + (ee**2*FM7*complex(0,1)*gw*sw**2)/(8.*cw)',
                  order = {'QED':4})

GC_275 = Coupling(name = 'GC_275',
                  value = '-8*cw**3*complex(0,1)*FT0*gw - 8*cw*complex(0,1)*FT5*gw*sw**2',
                  order = {'QED':2})

GC_276 = Coupling(name = 'GC_276',
                  value = '4*cw**3*complex(0,1)*FT1*gw + 4*cw*complex(0,1)*FT6*gw*sw**2',
                  order = {'QED':2})

GC_277 = Coupling(name = 'GC_277',
                  value = '-(cw**3*complex(0,1)*FT2*gw) - cw*complex(0,1)*FT7*gw*sw**2',
                  order = {'QED':2})

GC_278 = Coupling(name = 'GC_278',
                  value = '2*FM0*complex(0,1)*gw**2*sw**2 + FM6*complex(0,1)*gw**2*sw**2',
                  order = {'QED':3})

GC_279 = Coupling(name = 'GC_279',
                  value = '2*ee**2*FM0*complex(0,1)*gw**2 + ee**2*FM6*complex(0,1)*gw**2 + (ee**2*FM0*complex(0,1)*gw**2*sw**2)/cw**2 + (ee**2*FM6*complex(0,1)*gw**2*sw**2)/(2.*cw**2)',
                  order = {'QED':5})

GC_280 = Coupling(name = 'GC_280',
                  value = 'FM1*complex(0,1)*gw**2*sw**2 - (FM7*complex(0,1)*gw**2*sw**2)/2.',
                  order = {'QED':3})

GC_281 = Coupling(name = 'GC_281',
                  value = '-(cw**2*ee*FM7*complex(0,1)*gw**2)/8. - (ee*FM7*complex(0,1)*gw**2*sw**2)/8.',
                  order = {'QED':4})

GC_282 = Coupling(name = 'GC_282',
                  value = '-2*cw**2*ee**2*FM0*complex(0,1)*gw**2 + cw**2*ee**2*FM1*complex(0,1)*gw**2 - cw**2*ee**2*FM6*complex(0,1)*gw**2 - (cw**2*ee**2*FM7*complex(0,1)*gw**2)/2. - (cw**4*ee**2*FM0*complex(0,1)*gw**2)/sw**2 + (cw**4*ee**2*FM1*complex(0,1)*gw**2)/(2.*sw**2) - (cw**4*ee**2*FM6*complex(0,1)*gw**2)/(2.*sw**2) - (cw**4*ee**2*FM7*complex(0,1)*gw**2)/(4.*sw**2) - ee**2*FM0*complex(0,1)*gw**2*sw**2 + (ee**2*FM1*complex(0,1)*gw**2*sw**2)/2. - (ee**2*FM6*complex(0,1)*gw**2*sw**2)/2. - (ee**2*FM7*complex(0,1)*gw**2*sw**2)/4.',
                  order = {'QED':5})

GC_283 = Coupling(name = 'GC_283',
                  value = 'ee**2*FM1*complex(0,1)*gw**2 + (ee**2*FM1*complex(0,1)*gw**2*sw**2)/(2.*cw**2) - (ee**2*FM7*complex(0,1)*gw**2*sw**2)/(4.*cw**2)',
                  order = {'QED':5})

GC_284 = Coupling(name = 'GC_284',
                  value = '-8*cw**4*complex(0,1)*FT0*gw**2 - 8*cw**2*complex(0,1)*FT5*gw**2*sw**2',
                  order = {'QED':3})

GC_285 = Coupling(name = 'GC_285',
                  value = '-4*cw**4*complex(0,1)*FT1*gw**2 - 4*cw**2*complex(0,1)*FT6*gw**2*sw**2',
                  order = {'QED':3})

GC_286 = Coupling(name = 'GC_286',
                  value = '-(cw**4*complex(0,1)*FT2*gw**2) - cw**2*complex(0,1)*FT7*gw**2*sw**2',
                  order = {'QED':3})

GC_287 = Coupling(name = 'GC_287',
                  value = '8*cw**3*complex(0,1)*FT5*sw + 8*cw**3*complex(0,1)*FT6*sw - 32*cw**3*complex(0,1)*FT8*sw + 8*cw*complex(0,1)*FT0*sw**3 + 8*cw*complex(0,1)*FT1*sw**3 - 8*cw*complex(0,1)*FT5*sw**3 - 8*cw*complex(0,1)*FT6*sw**3',
                  order = {'QED':1})

GC_288 = Coupling(name = 'GC_288',
                  value = '2*cw**3*complex(0,1)*FT7*sw - 8*cw**3*complex(0,1)*FT9*sw + 2*cw*complex(0,1)*FT2*sw**3 - 2*cw*complex(0,1)*FT7*sw**3',
                  order = {'QED':1})

GC_289 = Coupling(name = 'GC_289',
                  value = '8*cw**3*complex(0,1)*FT0*sw + 8*cw**3*complex(0,1)*FT1*sw - 8*cw**3*complex(0,1)*FT5*sw - 8*cw**3*complex(0,1)*FT6*sw + 8*cw*complex(0,1)*FT5*sw**3 + 8*cw*complex(0,1)*FT6*sw**3 - 32*cw*complex(0,1)*FT8*sw**3',
                  order = {'QED':1})

GC_290 = Coupling(name = 'GC_290',
                  value = '2*cw**3*complex(0,1)*FT2*sw - 2*cw**3*complex(0,1)*FT7*sw + 2*cw*complex(0,1)*FT7*sw**3 - 8*cw*complex(0,1)*FT9*sw**3',
                  order = {'QED':1})

GC_291 = Coupling(name = 'GC_291',
                  value = '-((cw**2*ee**2*FM0*complex(0,1)*gw)/sw) - (cw**2*ee**2*FM6*complex(0,1)*gw)/(2.*sw) - 2*ee**2*FM0*complex(0,1)*gw*sw - ee**2*FM6*complex(0,1)*gw*sw - (ee**2*FM0*complex(0,1)*gw*sw**3)/cw**2 - (ee**2*FM6*complex(0,1)*gw*sw**3)/(2.*cw**2)',
                  order = {'QED':4})

GC_292 = Coupling(name = 'GC_292',
                  value = '(cw**2*ee**2*FM1*complex(0,1)*gw)/(4.*sw) + (ee**2*FM1*complex(0,1)*gw*sw)/2. + (ee**2*FM1*complex(0,1)*gw*sw**3)/(4.*cw**2) - (ee**2*FM7*complex(0,1)*gw*sw**3)/(8.*cw**2)',
                  order = {'QED':4})

GC_293 = Coupling(name = 'GC_293',
                  value = '-8*cw**2*complex(0,1)*FT5*gw*sw - 8*complex(0,1)*FT0*gw*sw**3',
                  order = {'QED':2})

GC_294 = Coupling(name = 'GC_294',
                  value = '4*cw**2*complex(0,1)*FT6*gw*sw + 4*complex(0,1)*FT1*gw*sw**3',
                  order = {'QED':2})

GC_295 = Coupling(name = 'GC_295',
                  value = '-2*cw**2*complex(0,1)*FT7*gw*sw - 2*complex(0,1)*FT2*gw*sw**3',
                  order = {'QED':2})

GC_296 = Coupling(name = 'GC_296',
                  value = '-(cw*ee*FM7*complex(0,1)*gw**2*sw)/8. - (ee*FM7*complex(0,1)*gw**2*sw**3)/(8.*cw)',
                  order = {'QED':4})

GC_297 = Coupling(name = 'GC_297',
                  value = '(2*cw**3*ee**2*FM0*complex(0,1)*gw**2)/sw - (cw**3*ee**2*FM1*complex(0,1)*gw**2)/sw + (cw**3*ee**2*FM6*complex(0,1)*gw**2)/sw + (cw**3*ee**2*FM7*complex(0,1)*gw**2)/(2.*sw) + 4*cw*ee**2*FM0*complex(0,1)*gw**2*sw - 2*cw*ee**2*FM1*complex(0,1)*gw**2*sw + 2*cw*ee**2*FM6*complex(0,1)*gw**2*sw + cw*ee**2*FM7*complex(0,1)*gw**2*sw + (2*ee**2*FM0*complex(0,1)*gw**2*sw**3)/cw - (ee**2*FM1*complex(0,1)*gw**2*sw**3)/cw + (ee**2*FM6*complex(0,1)*gw**2*sw**3)/cw + (ee**2*FM7*complex(0,1)*gw**2*sw**3)/(2.*cw)',
                  order = {'QED':5})

GC_298 = Coupling(name = 'GC_298',
                  value = '2*cw**2*ee**2*FM0*complex(0,1) + 2*cw**2*ee**2*FM2*complex(0,1) + cw**2*ee**2*FM6*complex(0,1) + (cw**4*ee**2*FM0*complex(0,1))/sw**2 + (cw**4*ee**2*FM6*complex(0,1))/(2.*sw**2) + (cw**3*ee**2*FM4*complex(0,1))/sw + 2*cw*ee**2*FM4*complex(0,1)*sw + ee**2*FM0*complex(0,1)*sw**2 + 4*ee**2*FM2*complex(0,1)*sw**2 + (ee**2*FM6*complex(0,1)*sw**2)/2. + (ee**2*FM4*complex(0,1)*sw**3)/cw + (2*ee**2*FM2*complex(0,1)*sw**4)/cw**2',
                  order = {'QED':3})

GC_299 = Coupling(name = 'GC_299',
                  value = '(cw**2*ee**2*FM1*complex(0,1))/2. + (cw**2*ee**2*FM3*complex(0,1))/2. - (cw**2*ee**2*FM7*complex(0,1))/4. + (cw**4*ee**2*FM1*complex(0,1))/(4.*sw**2) - (cw**4*ee**2*FM7*complex(0,1))/(8.*sw**2) - (cw**3*ee**2*FM5*complex(0,1))/(4.*sw) - (cw*ee**2*FM5*complex(0,1)*sw)/2. + (ee**2*FM1*complex(0,1)*sw**2)/4. + ee**2*FM3*complex(0,1)*sw**2 - (ee**2*FM7*complex(0,1)*sw**2)/8. - (ee**2*FM5*complex(0,1)*sw**3)/(4.*cw) + (ee**2*FM3*complex(0,1)*sw**4)/(2.*cw**2)',
                  order = {'QED':3})

GC_300 = Coupling(name = 'GC_300',
                  value = '-(cw**2*ee**2*FM4*complex(0,1))/2. - (cw**4*ee**2*FM4*complex(0,1))/(2.*sw**2) + (cw**3*ee**2*FM0*complex(0,1))/sw - (2*cw**3*ee**2*FM2*complex(0,1))/sw + (cw**3*ee**2*FM6*complex(0,1))/(2.*sw) + 2*cw*ee**2*FM0*complex(0,1)*sw - 4*cw*ee**2*FM2*complex(0,1)*sw + cw*ee**2*FM6*complex(0,1)*sw + (ee**2*FM4*complex(0,1)*sw**2)/2. + (ee**2*FM0*complex(0,1)*sw**3)/cw - (2*ee**2*FM2*complex(0,1)*sw**3)/cw + (ee**2*FM6*complex(0,1)*sw**3)/(2.*cw) + (ee**2*FM4*complex(0,1)*sw**4)/(2.*cw**2)',
                  order = {'QED':3})

GC_301 = Coupling(name = 'GC_301',
                  value = '(cw**2*ee**2*FM5*complex(0,1))/8. + (cw**4*ee**2*FM5*complex(0,1))/(8.*sw**2) + (cw**3*ee**2*FM1*complex(0,1))/(4.*sw) - (cw**3*ee**2*FM3*complex(0,1))/(2.*sw) - (cw**3*ee**2*FM7*complex(0,1))/(8.*sw) + (cw*ee**2*FM1*complex(0,1)*sw)/2. - cw*ee**2*FM3*complex(0,1)*sw - (cw*ee**2*FM7*complex(0,1)*sw)/4. - (ee**2*FM5*complex(0,1)*sw**2)/8. + (ee**2*FM1*complex(0,1)*sw**3)/(4.*cw) - (ee**2*FM3*complex(0,1)*sw**3)/(2.*cw) - (ee**2*FM7*complex(0,1)*sw**3)/(8.*cw) - (ee**2*FM5*complex(0,1)*sw**4)/(8.*cw**2)',
                  order = {'QED':3})

GC_302 = Coupling(name = 'GC_302',
                  value = 'cw**2*ee**2*FM0*complex(0,1) + 4*cw**2*ee**2*FM2*complex(0,1) + (cw**2*ee**2*FM6*complex(0,1))/2. + (2*cw**4*ee**2*FM2*complex(0,1))/sw**2 - (cw**3*ee**2*FM4*complex(0,1))/sw - 2*cw*ee**2*FM4*complex(0,1)*sw + 2*ee**2*FM0*complex(0,1)*sw**2 + 2*ee**2*FM2*complex(0,1)*sw**2 + ee**2*FM6*complex(0,1)*sw**2 - (ee**2*FM4*complex(0,1)*sw**3)/cw + (ee**2*FM0*complex(0,1)*sw**4)/cw**2 + (ee**2*FM6*complex(0,1)*sw**4)/(2.*cw**2)',
                  order = {'QED':3})

GC_303 = Coupling(name = 'GC_303',
                  value = '(cw**2*ee**2*FM1*complex(0,1))/4. + cw**2*ee**2*FM3*complex(0,1) - (cw**2*ee**2*FM7*complex(0,1))/8. + (cw**4*ee**2*FM3*complex(0,1))/(2.*sw**2) + (cw**3*ee**2*FM5*complex(0,1))/(4.*sw) + (cw*ee**2*FM5*complex(0,1)*sw)/2. + (ee**2*FM1*complex(0,1)*sw**2)/2. + (ee**2*FM3*complex(0,1)*sw**2)/2. - (ee**2*FM7*complex(0,1)*sw**2)/4. + (ee**2*FM5*complex(0,1)*sw**3)/(4.*cw) + (ee**2*FM1*complex(0,1)*sw**4)/(4.*cw**2) - (ee**2*FM7*complex(0,1)*sw**4)/(8.*cw**2)',
                  order = {'QED':3})

GC_304 = Coupling(name = 'GC_304',
                  value = '18*ee**4*complex(0,1)*FS0 + 18*ee**4*complex(0,1)*FS1 + (3*cw**4*ee**4*complex(0,1)*FS0)/sw**4 + (3*cw**4*ee**4*complex(0,1)*FS1)/sw**4 + (12*cw**2*ee**4*complex(0,1)*FS0)/sw**2 + (12*cw**2*ee**4*complex(0,1)*FS1)/sw**2 + (12*ee**4*complex(0,1)*FS0*sw**2)/cw**2 + (12*ee**4*complex(0,1)*FS1*sw**2)/cw**2 + (3*ee**4*complex(0,1)*FS0*sw**4)/cw**4 + (3*ee**4*complex(0,1)*FS1*sw**4)/cw**4',
                  order = {'QED':5})

GC_305 = Coupling(name = 'GC_305',
                  value = '32*cw**4*complex(0,1)*FT8 + 16*cw**2*complex(0,1)*FT5*sw**2 + 16*cw**2*complex(0,1)*FT6*sw**2 + 8*complex(0,1)*FT0*sw**4 + 8*complex(0,1)*FT1*sw**4',
                  order = {'QED':1})

GC_306 = Coupling(name = 'GC_306',
                  value = '8*cw**4*complex(0,1)*FT9 + 4*cw**2*complex(0,1)*FT7*sw**2 + 2*complex(0,1)*FT2*sw**4',
                  order = {'QED':1})

GC_307 = Coupling(name = 'GC_307',
                  value = '8*cw**4*complex(0,1)*FT5 + 8*complex(0,1)*FT5*sw**4',
                  order = {'QED':1})

GC_308 = Coupling(name = 'GC_308',
                  value = '4*cw**4*complex(0,1)*FT6 - 16*cw**2*complex(0,1)*FT5*sw**2 + 4*complex(0,1)*FT6*sw**4',
                  order = {'QED':1})

GC_309 = Coupling(name = 'GC_309',
                  value = 'cw**4*complex(0,1)*FT7 + complex(0,1)*FT7*sw**4',
                  order = {'QED':1})

GC_310 = Coupling(name = 'GC_310',
                  value = '8*cw**4*complex(0,1)*FT0 + 8*cw**4*complex(0,1)*FT1 + 16*cw**2*complex(0,1)*FT5*sw**2 + 16*cw**2*complex(0,1)*FT6*sw**2 + 32*complex(0,1)*FT8*sw**4',
                  order = {'QED':1})

GC_311 = Coupling(name = 'GC_311',
                  value = '2*cw**4*complex(0,1)*FT2 + 4*cw**2*complex(0,1)*FT7*sw**2 + 8*complex(0,1)*FT9*sw**4',
                  order = {'QED':1})

GC_312 = Coupling(name = 'GC_312',
                  value = '-(cw**2*ee**2*FM0*complex(0,1)*gw**2) - (cw**2*ee**2*FM6*complex(0,1)*gw**2)/2. - 2*ee**2*FM0*complex(0,1)*gw**2*sw**2 - ee**2*FM6*complex(0,1)*gw**2*sw**2 - (ee**2*FM0*complex(0,1)*gw**2*sw**4)/cw**2 - (ee**2*FM6*complex(0,1)*gw**2*sw**4)/(2.*cw**2)',
                  order = {'QED':5})

GC_313 = Coupling(name = 'GC_313',
                  value = '-(cw**2*ee**2*FM1*complex(0,1)*gw**2)/2. + (cw**2*ee**2*FM7*complex(0,1)*gw**2)/4. - ee**2*FM1*complex(0,1)*gw**2*sw**2 + (ee**2*FM7*complex(0,1)*gw**2*sw**2)/2. - (ee**2*FM1*complex(0,1)*gw**2*sw**4)/(2.*cw**2) + (ee**2*FM7*complex(0,1)*gw**2*sw**4)/(4.*cw**2)',
                  order = {'QED':5})

GC_314 = Coupling(name = 'GC_314',
                  value = '-8*cw**2*complex(0,1)*FT5*gw**2*sw**2 - 8*complex(0,1)*FT0*gw**2*sw**4',
                  order = {'QED':3})

GC_315 = Coupling(name = 'GC_315',
                  value = '-4*cw**2*complex(0,1)*FT6*gw**2*sw**2 - 4*complex(0,1)*FT1*gw**2*sw**4',
                  order = {'QED':3})

GC_316 = Coupling(name = 'GC_316',
                  value = '-2*cw**2*complex(0,1)*FT7*gw**2*sw**2 - 2*complex(0,1)*FT2*gw**2*sw**4',
                  order = {'QED':3})

GC_317 = Coupling(name = 'GC_317',
                  value = '2*ee**2*FM2*complex(0,1)*v',
                  order = {'QED':2})

GC_318 = Coupling(name = 'GC_318',
                  value = '-(ee**2*FM3*complex(0,1)*v)/2.',
                  order = {'QED':2})

GC_319 = Coupling(name = 'GC_319',
                  value = '-(ee*FM4*complex(0,1)*v)/2.',
                  order = {'QED':1})

GC_320 = Coupling(name = 'GC_320',
                  value = '-(ee**2*FM4*complex(0,1)*v)/2.',
                  order = {'QED':2})

GC_321 = Coupling(name = 'GC_321',
                  value = '(ee*FM5*complex(0,1)*v)/8.',
                  order = {'QED':1})

GC_322 = Coupling(name = 'GC_322',
                  value = '(ee**2*FM5*complex(0,1)*v)/8.',
                  order = {'QED':2})

GC_323 = Coupling(name = 'GC_323',
                  value = '-(ee*FM7*complex(0,1)*v)/8.',
                  order = {'QED':1})

GC_324 = Coupling(name = 'GC_324',
                  value = '-(ee**2*FM7*complex(0,1)*v)/4.',
                  order = {'QED':2})

GC_325 = Coupling(name = 'GC_325',
                  value = '(cw*ee*FM4*complex(0,1)*gw*v)/2.',
                  order = {'QED':2})

GC_326 = Coupling(name = 'GC_326',
                  value = '(cw*ee**2*FM4*complex(0,1)*gw*v)/2.',
                  order = {'QED':3})

GC_327 = Coupling(name = 'GC_327',
                  value = '(cw*ee*FM5*complex(0,1)*gw*v)/8.',
                  order = {'QED':2})

GC_328 = Coupling(name = 'GC_328',
                  value = '(cw*ee*FM5*complex(0,1)*gw*v)/4.',
                  order = {'QED':2})

GC_329 = Coupling(name = 'GC_329',
                  value = '-(cw*ee**2*FM5*complex(0,1)*gw*v)/4.',
                  order = {'QED':3})

GC_330 = Coupling(name = 'GC_330',
                  value = '(cw*ee*FM7*complex(0,1)*gw*v)/8.',
                  order = {'QED':2})

GC_331 = Coupling(name = 'GC_331',
                  value = '(ee**2*FM7*complex(0,1)*gw*v)/(8.*cw)',
                  order = {'QED':3})

GC_332 = Coupling(name = 'GC_332',
                  value = '(cw*ee**2*FM7*complex(0,1)*gw*v)/2.',
                  order = {'QED':3})

GC_333 = Coupling(name = 'GC_333',
                  value = 'ee**2*FM1*complex(0,1)*gw**2*v',
                  order = {'QED':4})

GC_334 = Coupling(name = 'GC_334',
                  value = '-(ee**2*FM7*complex(0,1)*gw**2*v)',
                  order = {'QED':4})

GC_335 = Coupling(name = 'GC_335',
                  value = '(-3*ee**2*FM7*complex(0,1)*gw**2*v)/2.',
                  order = {'QED':4})

GC_336 = Coupling(name = 'GC_336',
                  value = '-6*complex(0,1)*lam*v',
                  order = {'QED':1})

GC_337 = Coupling(name = 'GC_337',
                  value = '(6*ee**4*complex(0,1)*FS0*v)/sw**4',
                  order = {'QED':4})

GC_338 = Coupling(name = 'GC_338',
                  value = '(3*ee**4*complex(0,1)*FS1*v)/sw**4',
                  order = {'QED':4})

GC_339 = Coupling(name = 'GC_339',
                  value = '(ee**2*complex(0,1)*v)/(2.*sw**2)',
                  order = {'QED':1})

GC_340 = Coupling(name = 'GC_340',
                  value = '-(ee**2*FM1*complex(0,1)*v)/(4.*sw**2)',
                  order = {'QED':2})

GC_341 = Coupling(name = 'GC_341',
                  value = '(cw**2*ee**2*FM1*complex(0,1)*v)/(4.*sw**2)',
                  order = {'QED':2})

GC_342 = Coupling(name = 'GC_342',
                  value = '(cw**2*ee**2*FM4*complex(0,1)*v)/(2.*sw**2)',
                  order = {'QED':2})

GC_343 = Coupling(name = 'GC_343',
                  value = '(cw**2*ee**2*FM5*complex(0,1)*v)/(8.*sw**2)',
                  order = {'QED':2})

GC_344 = Coupling(name = 'GC_344',
                  value = '(ee**2*FM7*complex(0,1)*v)/(4.*sw**2)',
                  order = {'QED':2})

GC_345 = Coupling(name = 'GC_345',
                  value = '-(cw**2*ee**2*FM7*complex(0,1)*v)/(8.*sw**2)',
                  order = {'QED':2})

GC_346 = Coupling(name = 'GC_346',
                  value = '-(ee**2*complex(0,1)*FS0*v)/(2.*sw**2)',
                  order = {'QED':2})

GC_347 = Coupling(name = 'GC_347',
                  value = '-((ee**2*complex(0,1)*FS1*v)/sw**2)',
                  order = {'QED':2})

GC_348 = Coupling(name = 'GC_348',
                  value = '(cw*ee**2*FM1*complex(0,1)*gw*v)/(4.*sw**2)',
                  order = {'QED':3})

GC_349 = Coupling(name = 'GC_349',
                  value = '(cw**3*ee**2*FM4*complex(0,1)*gw*v)/(2.*sw**2)',
                  order = {'QED':3})

GC_350 = Coupling(name = 'GC_350',
                  value = '-(cw**3*ee**2*FM5*complex(0,1)*gw*v)/(8.*sw**2)',
                  order = {'QED':3})

GC_351 = Coupling(name = 'GC_351',
                  value = '(cw*ee**2*FM7*complex(0,1)*gw*v)/(8.*sw**2)',
                  order = {'QED':3})

GC_352 = Coupling(name = 'GC_352',
                  value = '(3*cw**3*ee**2*FM7*complex(0,1)*gw*v)/(8.*sw**2)',
                  order = {'QED':3})

GC_353 = Coupling(name = 'GC_353',
                  value = '(3*cw**2*ee**2*FM1*complex(0,1)*gw**2*v)/(2.*sw**2)',
                  order = {'QED':4})

GC_354 = Coupling(name = 'GC_354',
                  value = '(-9*cw**2*ee**2*FM7*complex(0,1)*gw**2*v)/(4.*sw**2)',
                  order = {'QED':4})

GC_355 = Coupling(name = 'GC_355',
                  value = '(cw*ee*FM4*complex(0,1)*v)/(2.*sw)',
                  order = {'QED':1})

GC_356 = Coupling(name = 'GC_356',
                  value = '-((cw*ee**2*FM4*complex(0,1)*v)/sw)',
                  order = {'QED':2})

GC_357 = Coupling(name = 'GC_357',
                  value = '-(cw*ee*FM5*complex(0,1)*v)/(8.*sw)',
                  order = {'QED':1})

GC_358 = Coupling(name = 'GC_358',
                  value = '(cw*ee**2*FM5*complex(0,1)*v)/(8.*sw)',
                  order = {'QED':2})

GC_359 = Coupling(name = 'GC_359',
                  value = '-(cw*ee*FM7*complex(0,1)*v)/(8.*sw)',
                  order = {'QED':1})

GC_360 = Coupling(name = 'GC_360',
                  value = '(cw*ee**2*FM7*complex(0,1)*v)/(8.*sw)',
                  order = {'QED':2})

GC_361 = Coupling(name = 'GC_361',
                  value = '-(ee**2*FM1*complex(0,1)*gw*v)/(4.*sw)',
                  order = {'QED':3})

GC_362 = Coupling(name = 'GC_362',
                  value = '-(cw**2*ee*FM4*complex(0,1)*gw*v)/(2.*sw)',
                  order = {'QED':2})

GC_363 = Coupling(name = 'GC_363',
                  value = '-(cw**2*ee**2*FM4*complex(0,1)*gw*v)/(2.*sw)',
                  order = {'QED':3})

GC_364 = Coupling(name = 'GC_364',
                  value = '-(cw**2*ee*FM5*complex(0,1)*gw*v)/(8.*sw)',
                  order = {'QED':2})

GC_365 = Coupling(name = 'GC_365',
                  value = '(cw**2*ee**2*FM5*complex(0,1)*gw*v)/(8.*sw)',
                  order = {'QED':3})

GC_366 = Coupling(name = 'GC_366',
                  value = '(ee*FM7*complex(0,1)*gw*v)/(8.*sw)',
                  order = {'QED':2})

GC_367 = Coupling(name = 'GC_367',
                  value = '-(cw**2*ee*FM7*complex(0,1)*gw*v)/(8.*sw)',
                  order = {'QED':2})

GC_368 = Coupling(name = 'GC_368',
                  value = '(ee**2*FM7*complex(0,1)*gw*v)/(4.*sw)',
                  order = {'QED':3})

GC_369 = Coupling(name = 'GC_369',
                  value = '-(cw**2*ee**2*FM7*complex(0,1)*gw*v)/(8.*sw)',
                  order = {'QED':3})

GC_370 = Coupling(name = 'GC_370',
                  value = '-((cw*ee**2*FM1*complex(0,1)*gw**2*v)/sw)',
                  order = {'QED':4})

GC_371 = Coupling(name = 'GC_371',
                  value = '-(cw*ee**2*FM7*complex(0,1)*gw**2*v)/(2.*sw)',
                  order = {'QED':4})

GC_372 = Coupling(name = 'GC_372',
                  value = '(ee**2*FM4*complex(0,1)*sw*v)/(2.*cw)',
                  order = {'QED':2})

GC_373 = Coupling(name = 'GC_373',
                  value = '(ee**2*FM5*complex(0,1)*sw*v)/(8.*cw)',
                  order = {'QED':2})

GC_374 = Coupling(name = 'GC_374',
                  value = '-(ee*FM7*complex(0,1)*sw*v)/(8.*cw)',
                  order = {'QED':1})

GC_375 = Coupling(name = 'GC_375',
                  value = '(ee**2*FM7*complex(0,1)*sw*v)/(8.*cw)',
                  order = {'QED':2})

GC_376 = Coupling(name = 'GC_376',
                  value = '-(ee*FM4*complex(0,1)*gw*sw*v)/2.',
                  order = {'QED':2})

GC_377 = Coupling(name = 'GC_377',
                  value = '-(ee*FM5*complex(0,1)*gw*sw*v)/8.',
                  order = {'QED':2})

GC_378 = Coupling(name = 'GC_378',
                  value = '-(ee*FM7*complex(0,1)*gw*sw*v)/8.',
                  order = {'QED':2})

GC_379 = Coupling(name = 'GC_379',
                  value = '-(ee**2*FM7*complex(0,1)*gw*sw*v)/4.',
                  order = {'QED':3})

GC_380 = Coupling(name = 'GC_380',
                  value = '-(ee**2*FM7*complex(0,1)*gw**2*sw*v)/(2.*cw)',
                  order = {'QED':4})

GC_381 = Coupling(name = 'GC_381',
                  value = '(ee**2*FM4*complex(0,1)*gw*sw**2*v)/(2.*cw)',
                  order = {'QED':3})

GC_382 = Coupling(name = 'GC_382',
                  value = '-(ee**2*FM5*complex(0,1)*gw*sw**2*v)/(8.*cw)',
                  order = {'QED':3})

GC_383 = Coupling(name = 'GC_383',
                  value = '(ee*FM7*complex(0,1)*gw*sw**2*v)/(8.*cw)',
                  order = {'QED':2})

GC_384 = Coupling(name = 'GC_384',
                  value = '-(ee**2*FM4*complex(0,1)*gw*sw**3*v)/(2.*cw**2)',
                  order = {'QED':3})

GC_385 = Coupling(name = 'GC_385',
                  value = '(ee**2*FM5*complex(0,1)*gw*sw**3*v)/(8.*cw**2)',
                  order = {'QED':3})

GC_386 = Coupling(name = 'GC_386',
                  value = 'ee**2*FM2*complex(0,1)*v**2',
                  order = {'QED':1})

GC_387 = Coupling(name = 'GC_387',
                  value = '-(ee**2*FM3*complex(0,1)*v**2)/4.',
                  order = {'QED':1})

GC_388 = Coupling(name = 'GC_388',
                  value = '-(ee**2*FM4*complex(0,1)*v**2)/4.',
                  order = {'QED':1})

GC_389 = Coupling(name = 'GC_389',
                  value = '(ee**2*FM5*complex(0,1)*v**2)/16.',
                  order = {'QED':1})

GC_390 = Coupling(name = 'GC_390',
                  value = '-(ee**2*FM7*complex(0,1)*v**2)/8.',
                  order = {'QED':1})

GC_391 = Coupling(name = 'GC_391',
                  value = '(cw*ee**2*FM4*complex(0,1)*gw*v**2)/4.',
                  order = {'QED':2})

GC_392 = Coupling(name = 'GC_392',
                  value = '-(cw*ee**2*FM5*complex(0,1)*gw*v**2)/8.',
                  order = {'QED':2})

GC_393 = Coupling(name = 'GC_393',
                  value = '(ee**2*FM7*complex(0,1)*gw*v**2)/(16.*cw)',
                  order = {'QED':2})

GC_394 = Coupling(name = 'GC_394',
                  value = '(cw*ee**2*FM7*complex(0,1)*gw*v**2)/4.',
                  order = {'QED':2})

GC_395 = Coupling(name = 'GC_395',
                  value = '(ee**2*FM1*complex(0,1)*gw**2*v**2)/2.',
                  order = {'QED':3})

GC_396 = Coupling(name = 'GC_396',
                  value = '-(ee**2*FM7*complex(0,1)*gw**2*v**2)/2.',
                  order = {'QED':3})

GC_397 = Coupling(name = 'GC_397',
                  value = '(-3*ee**2*FM7*complex(0,1)*gw**2*v**2)/4.',
                  order = {'QED':3})

GC_398 = Coupling(name = 'GC_398',
                  value = '(3*ee**4*complex(0,1)*FS0*v**2)/sw**4',
                  order = {'QED':3})

GC_399 = Coupling(name = 'GC_399',
                  value = '(3*ee**4*complex(0,1)*FS1*v**2)/(2.*sw**4)',
                  order = {'QED':3})

GC_400 = Coupling(name = 'GC_400',
                  value = '-(ee**2*FM1*complex(0,1)*v**2)/(8.*sw**2)',
                  order = {'QED':1})

GC_401 = Coupling(name = 'GC_401',
                  value = '(cw**2*ee**2*FM1*complex(0,1)*v**2)/(8.*sw**2)',
                  order = {'QED':1})

GC_402 = Coupling(name = 'GC_402',
                  value = '(cw**2*ee**2*FM4*complex(0,1)*v**2)/(4.*sw**2)',
                  order = {'QED':1})

GC_403 = Coupling(name = 'GC_403',
                  value = '(cw**2*ee**2*FM5*complex(0,1)*v**2)/(16.*sw**2)',
                  order = {'QED':1})

GC_404 = Coupling(name = 'GC_404',
                  value = '(ee**2*FM7*complex(0,1)*v**2)/(8.*sw**2)',
                  order = {'QED':1})

GC_405 = Coupling(name = 'GC_405',
                  value = '-(cw**2*ee**2*FM7*complex(0,1)*v**2)/(16.*sw**2)',
                  order = {'QED':1})

GC_406 = Coupling(name = 'GC_406',
                  value = '-(ee**2*complex(0,1)*FS0*v**2)/(4.*sw**2)',
                  order = {'QED':1})

GC_407 = Coupling(name = 'GC_407',
                  value = '-(ee**2*complex(0,1)*FS1*v**2)/(2.*sw**2)',
                  order = {'QED':1})

GC_408 = Coupling(name = 'GC_408',
                  value = '(cw*ee**2*FM1*complex(0,1)*gw*v**2)/(8.*sw**2)',
                  order = {'QED':2})

GC_409 = Coupling(name = 'GC_409',
                  value = '(cw**3*ee**2*FM4*complex(0,1)*gw*v**2)/(4.*sw**2)',
                  order = {'QED':2})

GC_410 = Coupling(name = 'GC_410',
                  value = '-(cw**3*ee**2*FM5*complex(0,1)*gw*v**2)/(16.*sw**2)',
                  order = {'QED':2})

GC_411 = Coupling(name = 'GC_411',
                  value = '(cw*ee**2*FM7*complex(0,1)*gw*v**2)/(16.*sw**2)',
                  order = {'QED':2})

GC_412 = Coupling(name = 'GC_412',
                  value = '(3*cw**3*ee**2*FM7*complex(0,1)*gw*v**2)/(16.*sw**2)',
                  order = {'QED':2})

GC_413 = Coupling(name = 'GC_413',
                  value = '(3*cw**2*ee**2*FM1*complex(0,1)*gw**2*v**2)/(4.*sw**2)',
                  order = {'QED':3})

GC_414 = Coupling(name = 'GC_414',
                  value = '(-9*cw**2*ee**2*FM7*complex(0,1)*gw**2*v**2)/(8.*sw**2)',
                  order = {'QED':3})

GC_415 = Coupling(name = 'GC_415',
                  value = '-(cw*ee**2*FM4*complex(0,1)*v**2)/(2.*sw)',
                  order = {'QED':1})

GC_416 = Coupling(name = 'GC_416',
                  value = '(cw*ee**2*FM5*complex(0,1)*v**2)/(16.*sw)',
                  order = {'QED':1})

GC_417 = Coupling(name = 'GC_417',
                  value = '(cw*ee**2*FM7*complex(0,1)*v**2)/(16.*sw)',
                  order = {'QED':1})

GC_418 = Coupling(name = 'GC_418',
                  value = '-(ee**2*FM1*complex(0,1)*gw*v**2)/(8.*sw)',
                  order = {'QED':2})

GC_419 = Coupling(name = 'GC_419',
                  value = '-(cw**2*ee**2*FM4*complex(0,1)*gw*v**2)/(4.*sw)',
                  order = {'QED':2})

GC_420 = Coupling(name = 'GC_420',
                  value = '(cw**2*ee**2*FM5*complex(0,1)*gw*v**2)/(16.*sw)',
                  order = {'QED':2})

GC_421 = Coupling(name = 'GC_421',
                  value = '(ee**2*FM7*complex(0,1)*gw*v**2)/(8.*sw)',
                  order = {'QED':2})

GC_422 = Coupling(name = 'GC_422',
                  value = '-(cw**2*ee**2*FM7*complex(0,1)*gw*v**2)/(16.*sw)',
                  order = {'QED':2})

GC_423 = Coupling(name = 'GC_423',
                  value = '-(cw*ee**2*FM1*complex(0,1)*gw**2*v**2)/(2.*sw)',
                  order = {'QED':3})

GC_424 = Coupling(name = 'GC_424',
                  value = '-(cw*ee**2*FM7*complex(0,1)*gw**2*v**2)/(4.*sw)',
                  order = {'QED':3})

GC_425 = Coupling(name = 'GC_425',
                  value = '(ee**2*FM4*complex(0,1)*sw*v**2)/(4.*cw)',
                  order = {'QED':1})

GC_426 = Coupling(name = 'GC_426',
                  value = '(ee**2*FM5*complex(0,1)*sw*v**2)/(16.*cw)',
                  order = {'QED':1})

GC_427 = Coupling(name = 'GC_427',
                  value = '(ee**2*FM7*complex(0,1)*sw*v**2)/(16.*cw)',
                  order = {'QED':1})

GC_428 = Coupling(name = 'GC_428',
                  value = '-(ee**2*FM7*complex(0,1)*gw*sw*v**2)/8.',
                  order = {'QED':2})

GC_429 = Coupling(name = 'GC_429',
                  value = '-(ee**2*FM7*complex(0,1)*gw**2*sw*v**2)/(4.*cw)',
                  order = {'QED':3})

GC_430 = Coupling(name = 'GC_430',
                  value = '(ee**2*FM4*complex(0,1)*gw*sw**2*v**2)/(4.*cw)',
                  order = {'QED':2})

GC_431 = Coupling(name = 'GC_431',
                  value = '-(ee**2*FM5*complex(0,1)*gw*sw**2*v**2)/(16.*cw)',
                  order = {'QED':2})

GC_432 = Coupling(name = 'GC_432',
                  value = '-(ee**2*FM4*complex(0,1)*gw*sw**3*v**2)/(4.*cw**2)',
                  order = {'QED':2})

GC_433 = Coupling(name = 'GC_433',
                  value = '(ee**2*FM5*complex(0,1)*gw*sw**3*v**2)/(16.*cw**2)',
                  order = {'QED':2})

GC_434 = Coupling(name = 'GC_434',
                  value = '(ee**4*complex(0,1)*FS0*v**3)/sw**4',
                  order = {'QED':2})

GC_435 = Coupling(name = 'GC_435',
                  value = '(ee**4*complex(0,1)*FS1*v**3)/(2.*sw**4)',
                  order = {'QED':2})

GC_436 = Coupling(name = 'GC_436',
                  value = '(ee**4*complex(0,1)*FS0*v**4)/(4.*sw**4)',
                  order = {'QED':1})

GC_437 = Coupling(name = 'GC_437',
                  value = '(ee**4*complex(0,1)*FS1*v**4)/(8.*sw**4)',
                  order = {'QED':1})

GC_438 = Coupling(name = 'GC_438',
                  value = '-(ee**2*FM0*complex(0,1)*gw**2*v) - (ee**2*FM6*complex(0,1)*gw**2*v)/2.',
                  order = {'QED':4})

GC_439 = Coupling(name = 'GC_439',
                  value = '(ee**2*FM0*complex(0,1)*v)/sw**2 + (ee**2*FM6*complex(0,1)*v)/(2.*sw**2)',
                  order = {'QED':2})

GC_440 = Coupling(name = 'GC_440',
                  value = '(cw**2*ee**2*FM0*complex(0,1)*v)/sw**2 + (cw**2*ee**2*FM6*complex(0,1)*v)/(2.*sw**2)',
                  order = {'QED':2})

GC_441 = Coupling(name = 'GC_441',
                  value = '(3*ee**4*complex(0,1)*FS0*v)/(2.*cw**2) + (3*cw**2*ee**4*complex(0,1)*FS0*v)/(2.*sw**4) + (3*ee**4*complex(0,1)*FS0*v)/sw**2',
                  order = {'QED':4})

GC_442 = Coupling(name = 'GC_442',
                  value = '(3*ee**4*complex(0,1)*FS1*v)/cw**2 + (3*cw**2*ee**4*complex(0,1)*FS1*v)/sw**4 + (6*ee**4*complex(0,1)*FS1*v)/sw**2',
                  order = {'QED':4})

GC_443 = Coupling(name = 'GC_443',
                  value = '-(cw*ee**2*FM4*complex(0,1)*gw*v)/(2.*sw**2) - (cw*ee**2*FM5*complex(0,1)*gw*v)/(4.*sw**2)',
                  order = {'QED':3})

GC_444 = Coupling(name = 'GC_444',
                  value = '-((cw*ee**2*FM0*complex(0,1)*gw*v)/sw**2) - (cw*ee**2*FM6*complex(0,1)*gw*v)/(2.*sw**2)',
                  order = {'QED':3})

GC_445 = Coupling(name = 'GC_445',
                  value = '-((cw**2*ee**2*FM0*complex(0,1)*gw**2*v)/sw**2) - (cw**2*ee**2*FM6*complex(0,1)*gw**2*v)/(2.*sw**2)',
                  order = {'QED':4})

GC_446 = Coupling(name = 'GC_446',
                  value = '(3*ee**2*FM0*complex(0,1)*gw**2*v)/sw**2 - (3*ee**2*FM1*complex(0,1)*gw**2*v)/(2.*sw**2) + (3*ee**2*FM6*complex(0,1)*gw**2*v)/(2.*sw**2) + (3*ee**2*FM7*complex(0,1)*gw**2*v)/(4.*sw**2)',
                  order = {'QED':4})

GC_447 = Coupling(name = 'GC_447',
                  value = '-(cw*ee**2*FM1*complex(0,1)*v)/(4.*sw) + (cw*ee**2*FM3*complex(0,1)*v)/(2.*sw)',
                  order = {'QED':2})

GC_448 = Coupling(name = 'GC_448',
                  value = 'ee**2*FM0*complex(0,1)*v + (ee**2*FM6*complex(0,1)*v)/2. + (2*cw**2*ee**2*FM2*complex(0,1)*v)/sw**2 + (cw*ee**2*FM4*complex(0,1)*v)/sw',
                  order = {'QED':2})

GC_449 = Coupling(name = 'GC_449',
                  value = '(ee**2*FM1*complex(0,1)*v)/4. - (ee**2*FM7*complex(0,1)*v)/8. + (cw**2*ee**2*FM3*complex(0,1)*v)/(2.*sw**2) - (cw*ee**2*FM5*complex(0,1)*v)/(4.*sw)',
                  order = {'QED':2})

GC_450 = Coupling(name = 'GC_450',
                  value = '(cw*ee**2*FM0*complex(0,1)*v)/sw - (2*cw*ee**2*FM2*complex(0,1)*v)/sw + (cw*ee**2*FM6*complex(0,1)*v)/(2.*sw)',
                  order = {'QED':2})

GC_451 = Coupling(name = 'GC_451',
                  value = '(-3*cw*ee**3*complex(0,1)*FS0*v)/(4.*sw**3) - (3*ee**3*complex(0,1)*FS0*v)/(4.*cw*sw)',
                  order = {'QED':3})

GC_452 = Coupling(name = 'GC_452',
                  value = '(ee**2*FM4*complex(0,1)*gw*v)/(2.*sw) + (ee**2*FM5*complex(0,1)*gw*v)/(4.*sw)',
                  order = {'QED':3})

GC_453 = Coupling(name = 'GC_453',
                  value = '-((ee**2*FM0*complex(0,1)*gw*v)/sw) - (ee**2*FM6*complex(0,1)*gw*v)/(2.*sw)',
                  order = {'QED':3})

GC_454 = Coupling(name = 'GC_454',
                  value = '(4*cw*ee**2*FM0*complex(0,1)*gw**2*v)/sw + (2*cw*ee**2*FM6*complex(0,1)*gw**2*v)/sw',
                  order = {'QED':4})

GC_455 = Coupling(name = 'GC_455',
                  value = '-(cw**2*ee**2*FM4*complex(0,1)*gw*v)/(2.*sw) - (ee**2*FM4*complex(0,1)*gw*sw*v)/2.',
                  order = {'QED':3})

GC_456 = Coupling(name = 'GC_456',
                  value = '(cw**2*ee**2*FM5*complex(0,1)*gw*v)/(8.*sw) + (ee**2*FM5*complex(0,1)*gw*sw*v)/8.',
                  order = {'QED':3})

GC_457 = Coupling(name = 'GC_457',
                  value = '-(ee**2*FM4*complex(0,1)*gw*sw*v)/2. + (ee**2*FM5*complex(0,1)*gw*sw*v)/4.',
                  order = {'QED':3})

GC_458 = Coupling(name = 'GC_458',
                  value = 'ee**2*complex(0,1)*v + (cw**2*ee**2*complex(0,1)*v)/(2.*sw**2) + (ee**2*complex(0,1)*sw**2*v)/(2.*cw**2)',
                  order = {'QED':1})

GC_459 = Coupling(name = 'GC_459',
                  value = '2*ee**2*FM0*complex(0,1)*v + ee**2*FM6*complex(0,1)*v + (ee**2*FM0*complex(0,1)*sw**2*v)/cw**2 + (ee**2*FM6*complex(0,1)*sw**2*v)/(2.*cw**2)',
                  order = {'QED':2})

GC_460 = Coupling(name = 'GC_460',
                  value = '(ee**2*FM1*complex(0,1)*v)/2. + (ee**2*FM1*complex(0,1)*sw**2*v)/(4.*cw**2) - (ee**2*FM7*complex(0,1)*sw**2*v)/(8.*cw**2)',
                  order = {'QED':2})

GC_461 = Coupling(name = 'GC_461',
                  value = '-2*ee**2*complex(0,1)*FS0*v - (cw**2*ee**2*complex(0,1)*FS0*v)/sw**2 - (ee**2*complex(0,1)*FS0*sw**2*v)/cw**2',
                  order = {'QED':2})

GC_462 = Coupling(name = 'GC_462',
                  value = '-2*ee**2*complex(0,1)*FS1*v - (cw**2*ee**2*complex(0,1)*FS1*v)/sw**2 - (ee**2*complex(0,1)*FS1*sw**2*v)/cw**2',
                  order = {'QED':2})

GC_463 = Coupling(name = 'GC_463',
                  value = '-2*cw*ee**2*FM0*complex(0,1)*gw*v - cw*ee**2*FM6*complex(0,1)*gw*v - (cw**3*ee**2*FM0*complex(0,1)*gw*v)/sw**2 - (cw**3*ee**2*FM6*complex(0,1)*gw*v)/(2.*sw**2) - (ee**2*FM0*complex(0,1)*gw*sw**2*v)/cw - (ee**2*FM6*complex(0,1)*gw*sw**2*v)/(2.*cw)',
                  order = {'QED':3})

GC_464 = Coupling(name = 'GC_464',
                  value = '(cw*ee**2*FM7*complex(0,1)*gw*v)/8. + (ee**2*FM7*complex(0,1)*gw*sw**2*v)/(8.*cw)',
                  order = {'QED':3})

GC_465 = Coupling(name = 'GC_465',
                  value = '-(cw*ee**2*FM1*complex(0,1)*gw*v)/2. - (cw**3*ee**2*FM1*complex(0,1)*gw*v)/(4.*sw**2) - (ee**2*FM1*complex(0,1)*gw*sw**2*v)/(4.*cw) + (ee**2*FM7*complex(0,1)*gw*sw**2*v)/(8.*cw)',
                  order = {'QED':3})

GC_466 = Coupling(name = 'GC_466',
                  value = '2*ee**2*FM0*complex(0,1)*gw**2*v + ee**2*FM6*complex(0,1)*gw**2*v + (ee**2*FM0*complex(0,1)*gw**2*sw**2*v)/cw**2 + (ee**2*FM6*complex(0,1)*gw**2*sw**2*v)/(2.*cw**2)',
                  order = {'QED':4})

GC_467 = Coupling(name = 'GC_467',
                  value = '-(cw**2*ee*FM7*complex(0,1)*gw**2*v)/8. - (ee*FM7*complex(0,1)*gw**2*sw**2*v)/8.',
                  order = {'QED':3})

GC_468 = Coupling(name = 'GC_468',
                  value = '-2*cw**2*ee**2*FM0*complex(0,1)*gw**2*v + cw**2*ee**2*FM1*complex(0,1)*gw**2*v - cw**2*ee**2*FM6*complex(0,1)*gw**2*v - (cw**2*ee**2*FM7*complex(0,1)*gw**2*v)/2. - (cw**4*ee**2*FM0*complex(0,1)*gw**2*v)/sw**2 + (cw**4*ee**2*FM1*complex(0,1)*gw**2*v)/(2.*sw**2) - (cw**4*ee**2*FM6*complex(0,1)*gw**2*v)/(2.*sw**2) - (cw**4*ee**2*FM7*complex(0,1)*gw**2*v)/(4.*sw**2) - ee**2*FM0*complex(0,1)*gw**2*sw**2*v + (ee**2*FM1*complex(0,1)*gw**2*sw**2*v)/2. - (ee**2*FM6*complex(0,1)*gw**2*sw**2*v)/2. - (ee**2*FM7*complex(0,1)*gw**2*sw**2*v)/4.',
                  order = {'QED':4})

GC_469 = Coupling(name = 'GC_469',
                  value = 'ee**2*FM1*complex(0,1)*gw**2*v + (ee**2*FM1*complex(0,1)*gw**2*sw**2*v)/(2.*cw**2) - (ee**2*FM7*complex(0,1)*gw**2*sw**2*v)/(4.*cw**2)',
                  order = {'QED':4})

GC_470 = Coupling(name = 'GC_470',
                  value = '-((cw**2*ee**2*FM0*complex(0,1)*gw*v)/sw) - (cw**2*ee**2*FM6*complex(0,1)*gw*v)/(2.*sw) - 2*ee**2*FM0*complex(0,1)*gw*sw*v - ee**2*FM6*complex(0,1)*gw*sw*v - (ee**2*FM0*complex(0,1)*gw*sw**3*v)/cw**2 - (ee**2*FM6*complex(0,1)*gw*sw**3*v)/(2.*cw**2)',
                  order = {'QED':3})

GC_471 = Coupling(name = 'GC_471',
                  value = '(cw**2*ee**2*FM1*complex(0,1)*gw*v)/(4.*sw) + (ee**2*FM1*complex(0,1)*gw*sw*v)/2. + (ee**2*FM1*complex(0,1)*gw*sw**3*v)/(4.*cw**2) - (ee**2*FM7*complex(0,1)*gw*sw**3*v)/(8.*cw**2)',
                  order = {'QED':3})

GC_472 = Coupling(name = 'GC_472',
                  value = '-(cw*ee*FM7*complex(0,1)*gw**2*sw*v)/8. - (ee*FM7*complex(0,1)*gw**2*sw**3*v)/(8.*cw)',
                  order = {'QED':3})

GC_473 = Coupling(name = 'GC_473',
                  value = '(2*cw**3*ee**2*FM0*complex(0,1)*gw**2*v)/sw - (cw**3*ee**2*FM1*complex(0,1)*gw**2*v)/sw + (cw**3*ee**2*FM6*complex(0,1)*gw**2*v)/sw + (cw**3*ee**2*FM7*complex(0,1)*gw**2*v)/(2.*sw) + 4*cw*ee**2*FM0*complex(0,1)*gw**2*sw*v - 2*cw*ee**2*FM1*complex(0,1)*gw**2*sw*v + 2*cw*ee**2*FM6*complex(0,1)*gw**2*sw*v + cw*ee**2*FM7*complex(0,1)*gw**2*sw*v + (2*ee**2*FM0*complex(0,1)*gw**2*sw**3*v)/cw - (ee**2*FM1*complex(0,1)*gw**2*sw**3*v)/cw + (ee**2*FM6*complex(0,1)*gw**2*sw**3*v)/cw + (ee**2*FM7*complex(0,1)*gw**2*sw**3*v)/(2.*cw)',
                  order = {'QED':4})

GC_474 = Coupling(name = 'GC_474',
                  value = '2*cw**2*ee**2*FM0*complex(0,1)*v + 2*cw**2*ee**2*FM2*complex(0,1)*v + cw**2*ee**2*FM6*complex(0,1)*v + (cw**4*ee**2*FM0*complex(0,1)*v)/sw**2 + (cw**4*ee**2*FM6*complex(0,1)*v)/(2.*sw**2) + (cw**3*ee**2*FM4*complex(0,1)*v)/sw + 2*cw*ee**2*FM4*complex(0,1)*sw*v + ee**2*FM0*complex(0,1)*sw**2*v + 4*ee**2*FM2*complex(0,1)*sw**2*v + (ee**2*FM6*complex(0,1)*sw**2*v)/2. + (ee**2*FM4*complex(0,1)*sw**3*v)/cw + (2*ee**2*FM2*complex(0,1)*sw**4*v)/cw**2',
                  order = {'QED':2})

GC_475 = Coupling(name = 'GC_475',
                  value = '(cw**2*ee**2*FM1*complex(0,1)*v)/2. + (cw**2*ee**2*FM3*complex(0,1)*v)/2. - (cw**2*ee**2*FM7*complex(0,1)*v)/4. + (cw**4*ee**2*FM1*complex(0,1)*v)/(4.*sw**2) - (cw**4*ee**2*FM7*complex(0,1)*v)/(8.*sw**2) - (cw**3*ee**2*FM5*complex(0,1)*v)/(4.*sw) - (cw*ee**2*FM5*complex(0,1)*sw*v)/2. + (ee**2*FM1*complex(0,1)*sw**2*v)/4. + ee**2*FM3*complex(0,1)*sw**2*v - (ee**2*FM7*complex(0,1)*sw**2*v)/8. - (ee**2*FM5*complex(0,1)*sw**3*v)/(4.*cw) + (ee**2*FM3*complex(0,1)*sw**4*v)/(2.*cw**2)',
                  order = {'QED':2})

GC_476 = Coupling(name = 'GC_476',
                  value = '-(cw**2*ee**2*FM4*complex(0,1)*v)/2. - (cw**4*ee**2*FM4*complex(0,1)*v)/(2.*sw**2) + (cw**3*ee**2*FM0*complex(0,1)*v)/sw - (2*cw**3*ee**2*FM2*complex(0,1)*v)/sw + (cw**3*ee**2*FM6*complex(0,1)*v)/(2.*sw) + 2*cw*ee**2*FM0*complex(0,1)*sw*v - 4*cw*ee**2*FM2*complex(0,1)*sw*v + cw*ee**2*FM6*complex(0,1)*sw*v + (ee**2*FM4*complex(0,1)*sw**2*v)/2. + (ee**2*FM0*complex(0,1)*sw**3*v)/cw - (2*ee**2*FM2*complex(0,1)*sw**3*v)/cw + (ee**2*FM6*complex(0,1)*sw**3*v)/(2.*cw) + (ee**2*FM4*complex(0,1)*sw**4*v)/(2.*cw**2)',
                  order = {'QED':2})

GC_477 = Coupling(name = 'GC_477',
                  value = '(cw**2*ee**2*FM5*complex(0,1)*v)/8. + (cw**4*ee**2*FM5*complex(0,1)*v)/(8.*sw**2) + (cw**3*ee**2*FM1*complex(0,1)*v)/(4.*sw) - (cw**3*ee**2*FM3*complex(0,1)*v)/(2.*sw) - (cw**3*ee**2*FM7*complex(0,1)*v)/(8.*sw) + (cw*ee**2*FM1*complex(0,1)*sw*v)/2. - cw*ee**2*FM3*complex(0,1)*sw*v - (cw*ee**2*FM7*complex(0,1)*sw*v)/4. - (ee**2*FM5*complex(0,1)*sw**2*v)/8. + (ee**2*FM1*complex(0,1)*sw**3*v)/(4.*cw) - (ee**2*FM3*complex(0,1)*sw**3*v)/(2.*cw) - (ee**2*FM7*complex(0,1)*sw**3*v)/(8.*cw) - (ee**2*FM5*complex(0,1)*sw**4*v)/(8.*cw**2)',
                  order = {'QED':2})

GC_478 = Coupling(name = 'GC_478',
                  value = 'cw**2*ee**2*FM0*complex(0,1)*v + 4*cw**2*ee**2*FM2*complex(0,1)*v + (cw**2*ee**2*FM6*complex(0,1)*v)/2. + (2*cw**4*ee**2*FM2*complex(0,1)*v)/sw**2 - (cw**3*ee**2*FM4*complex(0,1)*v)/sw - 2*cw*ee**2*FM4*complex(0,1)*sw*v + 2*ee**2*FM0*complex(0,1)*sw**2*v + 2*ee**2*FM2*complex(0,1)*sw**2*v + ee**2*FM6*complex(0,1)*sw**2*v - (ee**2*FM4*complex(0,1)*sw**3*v)/cw + (ee**2*FM0*complex(0,1)*sw**4*v)/cw**2 + (ee**2*FM6*complex(0,1)*sw**4*v)/(2.*cw**2)',
                  order = {'QED':2})

GC_479 = Coupling(name = 'GC_479',
                  value = '(cw**2*ee**2*FM1*complex(0,1)*v)/4. + cw**2*ee**2*FM3*complex(0,1)*v - (cw**2*ee**2*FM7*complex(0,1)*v)/8. + (cw**4*ee**2*FM3*complex(0,1)*v)/(2.*sw**2) + (cw**3*ee**2*FM5*complex(0,1)*v)/(4.*sw) + (cw*ee**2*FM5*complex(0,1)*sw*v)/2. + (ee**2*FM1*complex(0,1)*sw**2*v)/2. + (ee**2*FM3*complex(0,1)*sw**2*v)/2. - (ee**2*FM7*complex(0,1)*sw**2*v)/4. + (ee**2*FM5*complex(0,1)*sw**3*v)/(4.*cw) + (ee**2*FM1*complex(0,1)*sw**4*v)/(4.*cw**2) - (ee**2*FM7*complex(0,1)*sw**4*v)/(8.*cw**2)',
                  order = {'QED':2})

GC_480 = Coupling(name = 'GC_480',
                  value = '18*ee**4*complex(0,1)*FS0*v + 18*ee**4*complex(0,1)*FS1*v + (3*cw**4*ee**4*complex(0,1)*FS0*v)/sw**4 + (3*cw**4*ee**4*complex(0,1)*FS1*v)/sw**4 + (12*cw**2*ee**4*complex(0,1)*FS0*v)/sw**2 + (12*cw**2*ee**4*complex(0,1)*FS1*v)/sw**2 + (12*ee**4*complex(0,1)*FS0*sw**2*v)/cw**2 + (12*ee**4*complex(0,1)*FS1*sw**2*v)/cw**2 + (3*ee**4*complex(0,1)*FS0*sw**4*v)/cw**4 + (3*ee**4*complex(0,1)*FS1*sw**4*v)/cw**4',
                  order = {'QED':4})

GC_481 = Coupling(name = 'GC_481',
                  value = '-(cw**2*ee**2*FM0*complex(0,1)*gw**2*v) - (cw**2*ee**2*FM6*complex(0,1)*gw**2*v)/2. - 2*ee**2*FM0*complex(0,1)*gw**2*sw**2*v - ee**2*FM6*complex(0,1)*gw**2*sw**2*v - (ee**2*FM0*complex(0,1)*gw**2*sw**4*v)/cw**2 - (ee**2*FM6*complex(0,1)*gw**2*sw**4*v)/(2.*cw**2)',
                  order = {'QED':4})

GC_482 = Coupling(name = 'GC_482',
                  value = '-(cw**2*ee**2*FM1*complex(0,1)*gw**2*v)/2. + (cw**2*ee**2*FM7*complex(0,1)*gw**2*v)/4. - ee**2*FM1*complex(0,1)*gw**2*sw**2*v + (ee**2*FM7*complex(0,1)*gw**2*sw**2*v)/2. - (ee**2*FM1*complex(0,1)*gw**2*sw**4*v)/(2.*cw**2) + (ee**2*FM7*complex(0,1)*gw**2*sw**4*v)/(4.*cw**2)',
                  order = {'QED':4})

GC_483 = Coupling(name = 'GC_483',
                  value = '-(ee**2*FM0*complex(0,1)*gw**2*v**2)/2. - (ee**2*FM6*complex(0,1)*gw**2*v**2)/4.',
                  order = {'QED':3})

GC_484 = Coupling(name = 'GC_484',
                  value = '(ee**2*FM0*complex(0,1)*v**2)/(2.*sw**2) + (ee**2*FM6*complex(0,1)*v**2)/(4.*sw**2)',
                  order = {'QED':1})

GC_485 = Coupling(name = 'GC_485',
                  value = '(cw**2*ee**2*FM0*complex(0,1)*v**2)/(2.*sw**2) + (cw**2*ee**2*FM6*complex(0,1)*v**2)/(4.*sw**2)',
                  order = {'QED':1})

GC_486 = Coupling(name = 'GC_486',
                  value = '(3*ee**4*complex(0,1)*FS0*v**2)/(4.*cw**2) + (3*cw**2*ee**4*complex(0,1)*FS0*v**2)/(4.*sw**4) + (3*ee**4*complex(0,1)*FS0*v**2)/(2.*sw**2)',
                  order = {'QED':3})

GC_487 = Coupling(name = 'GC_487',
                  value = '(3*ee**4*complex(0,1)*FS1*v**2)/(2.*cw**2) + (3*cw**2*ee**4*complex(0,1)*FS1*v**2)/(2.*sw**4) + (3*ee**4*complex(0,1)*FS1*v**2)/sw**2',
                  order = {'QED':3})

GC_488 = Coupling(name = 'GC_488',
                  value = '-(cw*ee**2*FM4*complex(0,1)*gw*v**2)/(4.*sw**2) - (cw*ee**2*FM5*complex(0,1)*gw*v**2)/(8.*sw**2)',
                  order = {'QED':2})

GC_489 = Coupling(name = 'GC_489',
                  value = '-(cw*ee**2*FM0*complex(0,1)*gw*v**2)/(2.*sw**2) - (cw*ee**2*FM6*complex(0,1)*gw*v**2)/(4.*sw**2)',
                  order = {'QED':2})

GC_490 = Coupling(name = 'GC_490',
                  value = '-(cw**2*ee**2*FM0*complex(0,1)*gw**2*v**2)/(2.*sw**2) - (cw**2*ee**2*FM6*complex(0,1)*gw**2*v**2)/(4.*sw**2)',
                  order = {'QED':3})

GC_491 = Coupling(name = 'GC_491',
                  value = '(3*ee**2*FM0*complex(0,1)*gw**2*v**2)/(2.*sw**2) - (3*ee**2*FM1*complex(0,1)*gw**2*v**2)/(4.*sw**2) + (3*ee**2*FM6*complex(0,1)*gw**2*v**2)/(4.*sw**2) + (3*ee**2*FM7*complex(0,1)*gw**2*v**2)/(8.*sw**2)',
                  order = {'QED':3})

GC_492 = Coupling(name = 'GC_492',
                  value = '-(cw*ee**2*FM1*complex(0,1)*v**2)/(8.*sw) + (cw*ee**2*FM3*complex(0,1)*v**2)/(4.*sw)',
                  order = {'QED':1})

GC_493 = Coupling(name = 'GC_493',
                  value = '(ee**2*FM0*complex(0,1)*v**2)/2. + (ee**2*FM6*complex(0,1)*v**2)/4. + (cw**2*ee**2*FM2*complex(0,1)*v**2)/sw**2 + (cw*ee**2*FM4*complex(0,1)*v**2)/(2.*sw)',
                  order = {'QED':1})

GC_494 = Coupling(name = 'GC_494',
                  value = '(ee**2*FM1*complex(0,1)*v**2)/8. - (ee**2*FM7*complex(0,1)*v**2)/16. + (cw**2*ee**2*FM3*complex(0,1)*v**2)/(4.*sw**2) - (cw*ee**2*FM5*complex(0,1)*v**2)/(8.*sw)',
                  order = {'QED':1})

GC_495 = Coupling(name = 'GC_495',
                  value = '(cw*ee**2*FM0*complex(0,1)*v**2)/(2.*sw) - (cw*ee**2*FM2*complex(0,1)*v**2)/sw + (cw*ee**2*FM6*complex(0,1)*v**2)/(4.*sw)',
                  order = {'QED':1})

GC_496 = Coupling(name = 'GC_496',
                  value = '(-3*cw*ee**3*complex(0,1)*FS0*v**2)/(8.*sw**3) - (3*ee**3*complex(0,1)*FS0*v**2)/(8.*cw*sw)',
                  order = {'QED':2})

GC_497 = Coupling(name = 'GC_497',
                  value = '(ee**2*FM4*complex(0,1)*gw*v**2)/(4.*sw) + (ee**2*FM5*complex(0,1)*gw*v**2)/(8.*sw)',
                  order = {'QED':2})

GC_498 = Coupling(name = 'GC_498',
                  value = '-(ee**2*FM0*complex(0,1)*gw*v**2)/(2.*sw) - (ee**2*FM6*complex(0,1)*gw*v**2)/(4.*sw)',
                  order = {'QED':2})

GC_499 = Coupling(name = 'GC_499',
                  value = '(2*cw*ee**2*FM0*complex(0,1)*gw**2*v**2)/sw + (cw*ee**2*FM6*complex(0,1)*gw**2*v**2)/sw',
                  order = {'QED':3})

GC_500 = Coupling(name = 'GC_500',
                  value = '-(cw**2*ee**2*FM4*complex(0,1)*gw*v**2)/(4.*sw) - (ee**2*FM4*complex(0,1)*gw*sw*v**2)/4.',
                  order = {'QED':2})

GC_501 = Coupling(name = 'GC_501',
                  value = '(cw**2*ee**2*FM5*complex(0,1)*gw*v**2)/(16.*sw) + (ee**2*FM5*complex(0,1)*gw*sw*v**2)/16.',
                  order = {'QED':2})

GC_502 = Coupling(name = 'GC_502',
                  value = '-(ee**2*FM4*complex(0,1)*gw*sw*v**2)/4. + (ee**2*FM5*complex(0,1)*gw*sw*v**2)/8.',
                  order = {'QED':2})

GC_503 = Coupling(name = 'GC_503',
                  value = 'ee**2*FM0*complex(0,1)*v**2 + (ee**2*FM6*complex(0,1)*v**2)/2. + (ee**2*FM0*complex(0,1)*sw**2*v**2)/(2.*cw**2) + (ee**2*FM6*complex(0,1)*sw**2*v**2)/(4.*cw**2)',
                  order = {'QED':1})

GC_504 = Coupling(name = 'GC_504',
                  value = '(ee**2*FM1*complex(0,1)*v**2)/4. + (ee**2*FM1*complex(0,1)*sw**2*v**2)/(8.*cw**2) - (ee**2*FM7*complex(0,1)*sw**2*v**2)/(16.*cw**2)',
                  order = {'QED':1})

GC_505 = Coupling(name = 'GC_505',
                  value = '-(ee**2*complex(0,1)*FS0*v**2) - (cw**2*ee**2*complex(0,1)*FS0*v**2)/(2.*sw**2) - (ee**2*complex(0,1)*FS0*sw**2*v**2)/(2.*cw**2)',
                  order = {'QED':1})

GC_506 = Coupling(name = 'GC_506',
                  value = '-(ee**2*complex(0,1)*FS1*v**2) - (cw**2*ee**2*complex(0,1)*FS1*v**2)/(2.*sw**2) - (ee**2*complex(0,1)*FS1*sw**2*v**2)/(2.*cw**2)',
                  order = {'QED':1})

GC_507 = Coupling(name = 'GC_507',
                  value = '-(cw*ee**2*FM0*complex(0,1)*gw*v**2) - (cw*ee**2*FM6*complex(0,1)*gw*v**2)/2. - (cw**3*ee**2*FM0*complex(0,1)*gw*v**2)/(2.*sw**2) - (cw**3*ee**2*FM6*complex(0,1)*gw*v**2)/(4.*sw**2) - (ee**2*FM0*complex(0,1)*gw*sw**2*v**2)/(2.*cw) - (ee**2*FM6*complex(0,1)*gw*sw**2*v**2)/(4.*cw)',
                  order = {'QED':2})

GC_508 = Coupling(name = 'GC_508',
                  value = '(cw*ee**2*FM7*complex(0,1)*gw*v**2)/16. + (ee**2*FM7*complex(0,1)*gw*sw**2*v**2)/(16.*cw)',
                  order = {'QED':2})

GC_509 = Coupling(name = 'GC_509',
                  value = '-(cw*ee**2*FM1*complex(0,1)*gw*v**2)/4. - (cw**3*ee**2*FM1*complex(0,1)*gw*v**2)/(8.*sw**2) - (ee**2*FM1*complex(0,1)*gw*sw**2*v**2)/(8.*cw) + (ee**2*FM7*complex(0,1)*gw*sw**2*v**2)/(16.*cw)',
                  order = {'QED':2})

GC_510 = Coupling(name = 'GC_510',
                  value = 'ee**2*FM0*complex(0,1)*gw**2*v**2 + (ee**2*FM6*complex(0,1)*gw**2*v**2)/2. + (ee**2*FM0*complex(0,1)*gw**2*sw**2*v**2)/(2.*cw**2) + (ee**2*FM6*complex(0,1)*gw**2*sw**2*v**2)/(4.*cw**2)',
                  order = {'QED':3})

GC_511 = Coupling(name = 'GC_511',
                  value = '-(cw**2*ee**2*FM0*complex(0,1)*gw**2*v**2) + (cw**2*ee**2*FM1*complex(0,1)*gw**2*v**2)/2. - (cw**2*ee**2*FM6*complex(0,1)*gw**2*v**2)/2. - (cw**2*ee**2*FM7*complex(0,1)*gw**2*v**2)/4. - (cw**4*ee**2*FM0*complex(0,1)*gw**2*v**2)/(2.*sw**2) + (cw**4*ee**2*FM1*complex(0,1)*gw**2*v**2)/(4.*sw**2) - (cw**4*ee**2*FM6*complex(0,1)*gw**2*v**2)/(4.*sw**2) - (cw**4*ee**2*FM7*complex(0,1)*gw**2*v**2)/(8.*sw**2) - (ee**2*FM0*complex(0,1)*gw**2*sw**2*v**2)/2. + (ee**2*FM1*complex(0,1)*gw**2*sw**2*v**2)/4. - (ee**2*FM6*complex(0,1)*gw**2*sw**2*v**2)/4. - (ee**2*FM7*complex(0,1)*gw**2*sw**2*v**2)/8.',
                  order = {'QED':3})

GC_512 = Coupling(name = 'GC_512',
                  value = '(ee**2*FM1*complex(0,1)*gw**2*v**2)/2. + (ee**2*FM1*complex(0,1)*gw**2*sw**2*v**2)/(4.*cw**2) - (ee**2*FM7*complex(0,1)*gw**2*sw**2*v**2)/(8.*cw**2)',
                  order = {'QED':3})

GC_513 = Coupling(name = 'GC_513',
                  value = '-(cw**2*ee**2*FM0*complex(0,1)*gw*v**2)/(2.*sw) - (cw**2*ee**2*FM6*complex(0,1)*gw*v**2)/(4.*sw) - ee**2*FM0*complex(0,1)*gw*sw*v**2 - (ee**2*FM6*complex(0,1)*gw*sw*v**2)/2. - (ee**2*FM0*complex(0,1)*gw*sw**3*v**2)/(2.*cw**2) - (ee**2*FM6*complex(0,1)*gw*sw**3*v**2)/(4.*cw**2)',
                  order = {'QED':2})

GC_514 = Coupling(name = 'GC_514',
                  value = '(cw**2*ee**2*FM1*complex(0,1)*gw*v**2)/(8.*sw) + (ee**2*FM1*complex(0,1)*gw*sw*v**2)/4. + (ee**2*FM1*complex(0,1)*gw*sw**3*v**2)/(8.*cw**2) - (ee**2*FM7*complex(0,1)*gw*sw**3*v**2)/(16.*cw**2)',
                  order = {'QED':2})

GC_515 = Coupling(name = 'GC_515',
                  value = '(cw**3*ee**2*FM0*complex(0,1)*gw**2*v**2)/sw - (cw**3*ee**2*FM1*complex(0,1)*gw**2*v**2)/(2.*sw) + (cw**3*ee**2*FM6*complex(0,1)*gw**2*v**2)/(2.*sw) + (cw**3*ee**2*FM7*complex(0,1)*gw**2*v**2)/(4.*sw) + 2*cw*ee**2*FM0*complex(0,1)*gw**2*sw*v**2 - cw*ee**2*FM1*complex(0,1)*gw**2*sw*v**2 + cw*ee**2*FM6*complex(0,1)*gw**2*sw*v**2 + (cw*ee**2*FM7*complex(0,1)*gw**2*sw*v**2)/2. + (ee**2*FM0*complex(0,1)*gw**2*sw**3*v**2)/cw - (ee**2*FM1*complex(0,1)*gw**2*sw**3*v**2)/(2.*cw) + (ee**2*FM6*complex(0,1)*gw**2*sw**3*v**2)/(2.*cw) + (ee**2*FM7*complex(0,1)*gw**2*sw**3*v**2)/(4.*cw)',
                  order = {'QED':3})

GC_516 = Coupling(name = 'GC_516',
                  value = 'cw**2*ee**2*FM0*complex(0,1)*v**2 + cw**2*ee**2*FM2*complex(0,1)*v**2 + (cw**2*ee**2*FM6*complex(0,1)*v**2)/2. + (cw**4*ee**2*FM0*complex(0,1)*v**2)/(2.*sw**2) + (cw**4*ee**2*FM6*complex(0,1)*v**2)/(4.*sw**2) + (cw**3*ee**2*FM4*complex(0,1)*v**2)/(2.*sw) + cw*ee**2*FM4*complex(0,1)*sw*v**2 + (ee**2*FM0*complex(0,1)*sw**2*v**2)/2. + 2*ee**2*FM2*complex(0,1)*sw**2*v**2 + (ee**2*FM6*complex(0,1)*sw**2*v**2)/4. + (ee**2*FM4*complex(0,1)*sw**3*v**2)/(2.*cw) + (ee**2*FM2*complex(0,1)*sw**4*v**2)/cw**2',
                  order = {'QED':1})

GC_517 = Coupling(name = 'GC_517',
                  value = '(cw**2*ee**2*FM1*complex(0,1)*v**2)/4. + (cw**2*ee**2*FM3*complex(0,1)*v**2)/4. - (cw**2*ee**2*FM7*complex(0,1)*v**2)/8. + (cw**4*ee**2*FM1*complex(0,1)*v**2)/(8.*sw**2) - (cw**4*ee**2*FM7*complex(0,1)*v**2)/(16.*sw**2) - (cw**3*ee**2*FM5*complex(0,1)*v**2)/(8.*sw) - (cw*ee**2*FM5*complex(0,1)*sw*v**2)/4. + (ee**2*FM1*complex(0,1)*sw**2*v**2)/8. + (ee**2*FM3*complex(0,1)*sw**2*v**2)/2. - (ee**2*FM7*complex(0,1)*sw**2*v**2)/16. - (ee**2*FM5*complex(0,1)*sw**3*v**2)/(8.*cw) + (ee**2*FM3*complex(0,1)*sw**4*v**2)/(4.*cw**2)',
                  order = {'QED':1})

GC_518 = Coupling(name = 'GC_518',
                  value = '-(cw**2*ee**2*FM4*complex(0,1)*v**2)/4. - (cw**4*ee**2*FM4*complex(0,1)*v**2)/(4.*sw**2) + (cw**3*ee**2*FM0*complex(0,1)*v**2)/(2.*sw) - (cw**3*ee**2*FM2*complex(0,1)*v**2)/sw + (cw**3*ee**2*FM6*complex(0,1)*v**2)/(4.*sw) + cw*ee**2*FM0*complex(0,1)*sw*v**2 - 2*cw*ee**2*FM2*complex(0,1)*sw*v**2 + (cw*ee**2*FM6*complex(0,1)*sw*v**2)/2. + (ee**2*FM4*complex(0,1)*sw**2*v**2)/4. + (ee**2*FM0*complex(0,1)*sw**3*v**2)/(2.*cw) - (ee**2*FM2*complex(0,1)*sw**3*v**2)/cw + (ee**2*FM6*complex(0,1)*sw**3*v**2)/(4.*cw) + (ee**2*FM4*complex(0,1)*sw**4*v**2)/(4.*cw**2)',
                  order = {'QED':1})

GC_519 = Coupling(name = 'GC_519',
                  value = '(cw**2*ee**2*FM5*complex(0,1)*v**2)/16. + (cw**4*ee**2*FM5*complex(0,1)*v**2)/(16.*sw**2) + (cw**3*ee**2*FM1*complex(0,1)*v**2)/(8.*sw) - (cw**3*ee**2*FM3*complex(0,1)*v**2)/(4.*sw) - (cw**3*ee**2*FM7*complex(0,1)*v**2)/(16.*sw) + (cw*ee**2*FM1*complex(0,1)*sw*v**2)/4. - (cw*ee**2*FM3*complex(0,1)*sw*v**2)/2. - (cw*ee**2*FM7*complex(0,1)*sw*v**2)/8. - (ee**2*FM5*complex(0,1)*sw**2*v**2)/16. + (ee**2*FM1*complex(0,1)*sw**3*v**2)/(8.*cw) - (ee**2*FM3*complex(0,1)*sw**3*v**2)/(4.*cw) - (ee**2*FM7*complex(0,1)*sw**3*v**2)/(16.*cw) - (ee**2*FM5*complex(0,1)*sw**4*v**2)/(16.*cw**2)',
                  order = {'QED':1})

GC_520 = Coupling(name = 'GC_520',
                  value = '(cw**2*ee**2*FM0*complex(0,1)*v**2)/2. + 2*cw**2*ee**2*FM2*complex(0,1)*v**2 + (cw**2*ee**2*FM6*complex(0,1)*v**2)/4. + (cw**4*ee**2*FM2*complex(0,1)*v**2)/sw**2 - (cw**3*ee**2*FM4*complex(0,1)*v**2)/(2.*sw) - cw*ee**2*FM4*complex(0,1)*sw*v**2 + ee**2*FM0*complex(0,1)*sw**2*v**2 + ee**2*FM2*complex(0,1)*sw**2*v**2 + (ee**2*FM6*complex(0,1)*sw**2*v**2)/2. - (ee**2*FM4*complex(0,1)*sw**3*v**2)/(2.*cw) + (ee**2*FM0*complex(0,1)*sw**4*v**2)/(2.*cw**2) + (ee**2*FM6*complex(0,1)*sw**4*v**2)/(4.*cw**2)',
                  order = {'QED':1})

GC_521 = Coupling(name = 'GC_521',
                  value = '(cw**2*ee**2*FM1*complex(0,1)*v**2)/8. + (cw**2*ee**2*FM3*complex(0,1)*v**2)/2. - (cw**2*ee**2*FM7*complex(0,1)*v**2)/16. + (cw**4*ee**2*FM3*complex(0,1)*v**2)/(4.*sw**2) + (cw**3*ee**2*FM5*complex(0,1)*v**2)/(8.*sw) + (cw*ee**2*FM5*complex(0,1)*sw*v**2)/4. + (ee**2*FM1*complex(0,1)*sw**2*v**2)/4. + (ee**2*FM3*complex(0,1)*sw**2*v**2)/4. - (ee**2*FM7*complex(0,1)*sw**2*v**2)/8. + (ee**2*FM5*complex(0,1)*sw**3*v**2)/(8.*cw) + (ee**2*FM1*complex(0,1)*sw**4*v**2)/(8.*cw**2) - (ee**2*FM7*complex(0,1)*sw**4*v**2)/(16.*cw**2)',
                  order = {'QED':1})

GC_522 = Coupling(name = 'GC_522',
                  value = '9*ee**4*complex(0,1)*FS0*v**2 + 9*ee**4*complex(0,1)*FS1*v**2 + (3*cw**4*ee**4*complex(0,1)*FS0*v**2)/(2.*sw**4) + (3*cw**4*ee**4*complex(0,1)*FS1*v**2)/(2.*sw**4) + (6*cw**2*ee**4*complex(0,1)*FS0*v**2)/sw**2 + (6*cw**2*ee**4*complex(0,1)*FS1*v**2)/sw**2 + (6*ee**4*complex(0,1)*FS0*sw**2*v**2)/cw**2 + (6*ee**4*complex(0,1)*FS1*sw**2*v**2)/cw**2 + (3*ee**4*complex(0,1)*FS0*sw**4*v**2)/(2.*cw**4) + (3*ee**4*complex(0,1)*FS1*sw**4*v**2)/(2.*cw**4)',
                  order = {'QED':3})

GC_523 = Coupling(name = 'GC_523',
                  value = '-(cw**2*ee**2*FM0*complex(0,1)*gw**2*v**2)/2. - (cw**2*ee**2*FM6*complex(0,1)*gw**2*v**2)/4. - ee**2*FM0*complex(0,1)*gw**2*sw**2*v**2 - (ee**2*FM6*complex(0,1)*gw**2*sw**2*v**2)/2. - (ee**2*FM0*complex(0,1)*gw**2*sw**4*v**2)/(2.*cw**2) - (ee**2*FM6*complex(0,1)*gw**2*sw**4*v**2)/(4.*cw**2)',
                  order = {'QED':3})

GC_524 = Coupling(name = 'GC_524',
                  value = '-(cw**2*ee**2*FM1*complex(0,1)*gw**2*v**2)/4. + (cw**2*ee**2*FM7*complex(0,1)*gw**2*v**2)/8. - (ee**2*FM1*complex(0,1)*gw**2*sw**2*v**2)/2. + (ee**2*FM7*complex(0,1)*gw**2*sw**2*v**2)/4. - (ee**2*FM1*complex(0,1)*gw**2*sw**4*v**2)/(4.*cw**2) + (ee**2*FM7*complex(0,1)*gw**2*sw**4*v**2)/(8.*cw**2)',
                  order = {'QED':3})

GC_525 = Coupling(name = 'GC_525',
                  value = '(ee**4*complex(0,1)*FS0*v**3)/(4.*cw**2) + (cw**2*ee**4*complex(0,1)*FS0*v**3)/(4.*sw**4) + (ee**4*complex(0,1)*FS0*v**3)/(2.*sw**2)',
                  order = {'QED':2})

GC_526 = Coupling(name = 'GC_526',
                  value = '(ee**4*complex(0,1)*FS1*v**3)/(2.*cw**2) + (cw**2*ee**4*complex(0,1)*FS1*v**3)/(2.*sw**4) + (ee**4*complex(0,1)*FS1*v**3)/sw**2',
                  order = {'QED':2})

GC_527 = Coupling(name = 'GC_527',
                  value = '-(cw*ee**3*complex(0,1)*FS0*v**3)/(8.*sw**3) - (ee**3*complex(0,1)*FS0*v**3)/(8.*cw*sw)',
                  order = {'QED':1})

GC_528 = Coupling(name = 'GC_528',
                  value = '3*ee**4*complex(0,1)*FS0*v**3 + 3*ee**4*complex(0,1)*FS1*v**3 + (cw**4*ee**4*complex(0,1)*FS0*v**3)/(2.*sw**4) + (cw**4*ee**4*complex(0,1)*FS1*v**3)/(2.*sw**4) + (2*cw**2*ee**4*complex(0,1)*FS0*v**3)/sw**2 + (2*cw**2*ee**4*complex(0,1)*FS1*v**3)/sw**2 + (2*ee**4*complex(0,1)*FS0*sw**2*v**3)/cw**2 + (2*ee**4*complex(0,1)*FS1*sw**2*v**3)/cw**2 + (ee**4*complex(0,1)*FS0*sw**4*v**3)/(2.*cw**4) + (ee**4*complex(0,1)*FS1*sw**4*v**3)/(2.*cw**4)',
                  order = {'QED':2})

GC_529 = Coupling(name = 'GC_529',
                  value = '(ee**4*complex(0,1)*FS0*v**4)/(16.*cw**2) + (cw**2*ee**4*complex(0,1)*FS0*v**4)/(16.*sw**4) + (ee**4*complex(0,1)*FS0*v**4)/(8.*sw**2)',
                  order = {'QED':1})

GC_530 = Coupling(name = 'GC_530',
                  value = '(ee**4*complex(0,1)*FS1*v**4)/(8.*cw**2) + (cw**2*ee**4*complex(0,1)*FS1*v**4)/(8.*sw**4) + (ee**4*complex(0,1)*FS1*v**4)/(4.*sw**2)',
                  order = {'QED':1})

GC_531 = Coupling(name = 'GC_531',
                  value = '(3*ee**4*complex(0,1)*FS0*v**4)/4. + (3*ee**4*complex(0,1)*FS1*v**4)/4. + (cw**4*ee**4*complex(0,1)*FS0*v**4)/(8.*sw**4) + (cw**4*ee**4*complex(0,1)*FS1*v**4)/(8.*sw**4) + (cw**2*ee**4*complex(0,1)*FS0*v**4)/(2.*sw**2) + (cw**2*ee**4*complex(0,1)*FS1*v**4)/(2.*sw**2) + (ee**4*complex(0,1)*FS0*sw**2*v**4)/(2.*cw**2) + (ee**4*complex(0,1)*FS1*sw**2*v**4)/(2.*cw**2) + (ee**4*complex(0,1)*FS0*sw**4*v**4)/(8.*cw**4) + (ee**4*complex(0,1)*FS1*sw**4*v**4)/(8.*cw**4)',
                  order = {'QED':1})

GC_532 = Coupling(name = 'GC_532',
                  value = '-((complex(0,1)*yb)/cmath.sqrt(2))',
                  order = {'QED':1})

GC_533 = Coupling(name = 'GC_533',
                  value = '-((complex(0,1)*yt)/cmath.sqrt(2))',
                  order = {'QED':1})

GC_534 = Coupling(name = 'GC_534',
                  value = '-((complex(0,1)*ytau)/cmath.sqrt(2))',
                  order = {'QED':1})

GC_535 = Coupling(name = 'GC_535',
                  value = '(ee*complex(0,1)*complexconjugate(CKM11))/(sw*cmath.sqrt(2))',
                  order = {'QED':1})

GC_536 = Coupling(name = 'GC_536',
                  value = '(ee*complex(0,1)*complexconjugate(CKM12))/(sw*cmath.sqrt(2))',
                  order = {'QED':1})

GC_537 = Coupling(name = 'GC_537',
                  value = '(ee*complex(0,1)*complexconjugate(CKM21))/(sw*cmath.sqrt(2))',
                  order = {'QED':1})

GC_538 = Coupling(name = 'GC_538',
                  value = '(ee*complex(0,1)*complexconjugate(CKM22))/(sw*cmath.sqrt(2))',
                  order = {'QED':1})

