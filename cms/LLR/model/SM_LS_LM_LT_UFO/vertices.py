# This file was automatically created by FeynRules 2.3.13
# Mathematica version: 9.0 for Linux x86 (64-bit) (February 7, 2013)
# Date: Fri 18 Dec 2015 02:10:12


from object_library import all_vertices, Vertex
import particles as P
import couplings as C
import lorentz as L


V_1 = Vertex(name = 'V_1',
             particles = [ P.G, P.G, P.G ],
             color = [ 'f(1,2,3)' ],
             lorentz = [ L.VVV1 ],
             couplings = {(0,0):C.GC_18})

V_2 = Vertex(name = 'V_2',
             particles = [ P.G, P.G, P.G, P.G ],
             color = [ 'f(-1,1,2)*f(3,4,-1)', 'f(-1,1,3)*f(2,4,-1)', 'f(-1,1,4)*f(2,3,-1)' ],
             lorentz = [ L.VVVV14, L.VVVV15, L.VVVV3 ],
             couplings = {(1,0):C.GC_20,(0,2):C.GC_20,(2,1):C.GC_20})

V_3 = Vertex(name = 'V_3',
             particles = [ P.A, P.W__minus__, P.W__plus__ ],
             color = [ '1' ],
             lorentz = [ L.VVV1 ],
             couplings = {(0,0):C.GC_138})

V_4 = Vertex(name = 'V_4',
             particles = [ P.A, P.A, P.W__minus__, P.W__plus__ ],
             color = [ '1' ],
             lorentz = [ L.VVVV13, L.VVVV18, L.VVVV40, L.VVVV42, L.VVVV5, L.VVVV9 ],
             couplings = {(0,5):C.GC_267,(0,2):C.GC_268,(0,3):C.GC_266,(0,4):C.GC_498,(0,0):C.GC_194,(0,1):C.GC_497})

V_5 = Vertex(name = 'V_5',
             particles = [ P.W__minus__, P.W__plus__, P.Z ],
             color = [ '1' ],
             lorentz = [ L.VVV1 ],
             couplings = {(0,0):C.GC_21})

V_6 = Vertex(name = 'V_6',
             particles = [ P.W__minus__, P.W__minus__, P.W__plus__, P.W__plus__ ],
             color = [ '1' ],
             lorentz = [ L.VVVV10, L.VVVV13, L.VVVV28, L.VVVV29, L.VVVV39, L.VVVV4, L.VVVV45, L.VVVV7, L.VVVV8 ],
             couplings = {(0,8):C.GC_15,(0,6):C.GC_16,(0,4):C.GC_17,(0,3):C.GC_403,(0,2):C.GC_407,(0,7):C.GC_488,(0,1):C.GC_37,(0,5):C.GC_440,(0,0):C.GC_439})

V_7 = Vertex(name = 'V_7',
             particles = [ P.A, P.W__minus__, P.W__plus__, P.Z ],
             color = [ '1' ],
             lorentz = [ L.VVVV1, L.VVVV16, L.VVVV19, L.VVVV2, L.VVVV20, L.VVVV21, L.VVVV22, L.VVVV23, L.VVVV24, L.VVVV37, L.VVVV43, L.VVVV6 ],
             couplings = {(0,3):C.GC_245,(0,9):C.GC_247,(0,10):C.GC_246,(0,7):C.GC_420,(0,5):C.GC_430,(0,8):C.GC_392,(0,11):C.GC_406,(0,6):C.GC_496,(0,2):C.GC_391,(0,4):C.GC_405,(0,0):C.GC_499,(0,1):C.GC_154})

V_8 = Vertex(name = 'V_8',
             particles = [ P.W__minus__, P.W__plus__, P.Z, P.Z ],
             color = [ '1' ],
             lorentz = [ L.VVVV10, L.VVVV11, L.VVVV12, L.VVVV13, L.VVVV18, L.VVVV26, L.VVVV27, L.VVVV30, L.VVVV31, L.VVVV33, L.VVVV34, L.VVVV35, L.VVVV4, L.VVVV40, L.VVVV42, L.VVVV5, L.VVVV7, L.VVVV8 ],
             couplings = {(0,17):C.GC_270,(0,13):C.GC_271,(0,14):C.GC_269,(0,15):C.GC_508,(0,8):C.GC_393,(0,2):C.GC_404,(0,7):C.GC_408,(0,6):C.GC_419,(0,5):C.GC_429,(0,9):C.GC_389,(0,11):C.GC_489,(0,10):C.GC_418,(0,16):C.GC_428,(0,1):C.GC_390,(0,3):C.GC_38,(0,12):C.GC_533,(0,4):C.GC_507,(0,0):C.GC_534})

V_9 = Vertex(name = 'V_9',
             particles = [ P.H, P.H, P.H, P.H ],
             color = [ '1' ],
             lorentz = [ L.SSSS1, L.SSSS2 ],
             couplings = {(0,0):C.GC_74,(0,1):C.GC_14})

V_10 = Vertex(name = 'V_10',
              particles = [ P.H, P.H, P.H ],
              color = [ '1' ],
              lorentz = [ L.SSS1 ],
              couplings = {(0,0):C.GC_338})

V_11 = Vertex(name = 'V_11',
              particles = [ P.W__minus__, P.W__plus__, P.H, P.H ],
              color = [ '1' ],
              lorentz = [ L.VVSS1, L.VVSS2, L.VVSS3, L.VVSS5, L.VVSS6 ],
              couplings = {(0,0):C.GC_409,(0,1):C.GC_93,(0,3):C.GC_11,(0,4):C.GC_10,(0,2):C.GC_410})

V_12 = Vertex(name = 'V_12',
              particles = [ P.W__minus__, P.W__plus__, P.H ],
              color = [ '1' ],
              lorentz = [ L.VVS1 ],
              couplings = {(0,0):C.GC_341})

V_13 = Vertex(name = 'V_13',
              particles = [ P.Z, P.Z, P.H, P.H ],
              color = [ '1' ],
              lorentz = [ L.VVSS2, L.VVSS3, L.VVSS4, L.VVSS5, L.VVSS6 ],
              couplings = {(0,2):C.GC_509,(0,0):C.GC_255,(0,3):C.GC_257,(0,4):C.GC_256,(0,1):C.GC_510})

V_14 = Vertex(name = 'V_14',
              particles = [ P.Z, P.Z, P.H ],
              color = [ '1' ],
              lorentz = [ L.VVS1 ],
              couplings = {(0,0):C.GC_461})

V_15 = Vertex(name = 'V_15',
              particles = [ P.b__tilde__, P.b, P.G ],
              color = [ 'T(3,2,1)' ],
              lorentz = [ L.FFV1 ],
              couplings = {(0,0):C.GC_19})

V_16 = Vertex(name = 'V_16',
              particles = [ P.d__tilde__, P.d, P.G ],
              color = [ 'T(3,2,1)' ],
              lorentz = [ L.FFV1 ],
              couplings = {(0,0):C.GC_19})

V_17 = Vertex(name = 'V_17',
              particles = [ P.s__tilde__, P.s, P.G ],
              color = [ 'T(3,2,1)' ],
              lorentz = [ L.FFV1 ],
              couplings = {(0,0):C.GC_19})

V_18 = Vertex(name = 'V_18',
              particles = [ P.c__tilde__, P.c, P.G ],
              color = [ 'T(3,2,1)' ],
              lorentz = [ L.FFV1 ],
              couplings = {(0,0):C.GC_19})

V_19 = Vertex(name = 'V_19',
              particles = [ P.t__tilde__, P.t, P.G ],
              color = [ 'T(3,2,1)' ],
              lorentz = [ L.FFV1 ],
              couplings = {(0,0):C.GC_19})

V_20 = Vertex(name = 'V_20',
              particles = [ P.u__tilde__, P.u, P.G ],
              color = [ 'T(3,2,1)' ],
              lorentz = [ L.FFV1 ],
              couplings = {(0,0):C.GC_19})

V_21 = Vertex(name = 'V_21',
              particles = [ P.b__tilde__, P.b, P.A ],
              color = [ 'Identity(1,2)' ],
              lorentz = [ L.FFV1 ],
              couplings = {(0,0):C.GC_1})

V_22 = Vertex(name = 'V_22',
              particles = [ P.d__tilde__, P.d, P.A ],
              color = [ 'Identity(1,2)' ],
              lorentz = [ L.FFV1 ],
              couplings = {(0,0):C.GC_1})

V_23 = Vertex(name = 'V_23',
              particles = [ P.s__tilde__, P.s, P.A ],
              color = [ 'Identity(1,2)' ],
              lorentz = [ L.FFV1 ],
              couplings = {(0,0):C.GC_1})

V_24 = Vertex(name = 'V_24',
              particles = [ P.b__tilde__, P.b, P.Z ],
              color = [ 'Identity(1,2)' ],
              lorentz = [ L.FFV2, L.FFV3 ],
              couplings = {(0,0):C.GC_241,(0,1):C.GC_131})

V_25 = Vertex(name = 'V_25',
              particles = [ P.d__tilde__, P.d, P.Z ],
              color = [ 'Identity(1,2)' ],
              lorentz = [ L.FFV2, L.FFV3 ],
              couplings = {(0,0):C.GC_241,(0,1):C.GC_131})

V_26 = Vertex(name = 'V_26',
              particles = [ P.s__tilde__, P.s, P.Z ],
              color = [ 'Identity(1,2)' ],
              lorentz = [ L.FFV2, L.FFV3 ],
              couplings = {(0,0):C.GC_241,(0,1):C.GC_131})

V_27 = Vertex(name = 'V_27',
              particles = [ P.e__plus__, P.e__minus__, P.A ],
              color = [ '1' ],
              lorentz = [ L.FFV1 ],
              couplings = {(0,0):C.GC_3})

V_28 = Vertex(name = 'V_28',
              particles = [ P.m__plus__, P.m__minus__, P.A ],
              color = [ '1' ],
              lorentz = [ L.FFV1 ],
              couplings = {(0,0):C.GC_3})

V_29 = Vertex(name = 'V_29',
              particles = [ P.tt__plus__, P.tt__minus__, P.A ],
              color = [ '1' ],
              lorentz = [ L.FFV1 ],
              couplings = {(0,0):C.GC_3})

V_30 = Vertex(name = 'V_30',
              particles = [ P.e__plus__, P.e__minus__, P.Z ],
              color = [ '1' ],
              lorentz = [ L.FFV2, L.FFV3 ],
              couplings = {(0,0):C.GC_243,(0,1):C.GC_133})

V_31 = Vertex(name = 'V_31',
              particles = [ P.m__plus__, P.m__minus__, P.Z ],
              color = [ '1' ],
              lorentz = [ L.FFV2, L.FFV3 ],
              couplings = {(0,0):C.GC_243,(0,1):C.GC_133})

V_32 = Vertex(name = 'V_32',
              particles = [ P.tt__plus__, P.tt__minus__, P.Z ],
              color = [ '1' ],
              lorentz = [ L.FFV2, L.FFV3 ],
              couplings = {(0,0):C.GC_243,(0,1):C.GC_133})

V_33 = Vertex(name = 'V_33',
              particles = [ P.c__tilde__, P.c, P.A ],
              color = [ 'Identity(1,2)' ],
              lorentz = [ L.FFV1 ],
              couplings = {(0,0):C.GC_2})

V_34 = Vertex(name = 'V_34',
              particles = [ P.t__tilde__, P.t, P.A ],
              color = [ 'Identity(1,2)' ],
              lorentz = [ L.FFV1 ],
              couplings = {(0,0):C.GC_2})

V_35 = Vertex(name = 'V_35',
              particles = [ P.u__tilde__, P.u, P.A ],
              color = [ 'Identity(1,2)' ],
              lorentz = [ L.FFV1 ],
              couplings = {(0,0):C.GC_2})

V_36 = Vertex(name = 'V_36',
              particles = [ P.c__tilde__, P.c, P.Z ],
              color = [ 'Identity(1,2)' ],
              lorentz = [ L.FFV2, L.FFV3 ],
              couplings = {(0,0):C.GC_242,(0,1):C.GC_132})

V_37 = Vertex(name = 'V_37',
              particles = [ P.t__tilde__, P.t, P.Z ],
              color = [ 'Identity(1,2)' ],
              lorentz = [ L.FFV2, L.FFV3 ],
              couplings = {(0,0):C.GC_242,(0,1):C.GC_132})

V_38 = Vertex(name = 'V_38',
              particles = [ P.u__tilde__, P.u, P.Z ],
              color = [ 'Identity(1,2)' ],
              lorentz = [ L.FFV2, L.FFV3 ],
              couplings = {(0,0):C.GC_242,(0,1):C.GC_132})

V_39 = Vertex(name = 'V_39',
              particles = [ P.ve__tilde__, P.ve, P.Z ],
              color = [ '1' ],
              lorentz = [ L.FFV2 ],
              couplings = {(0,0):C.GC_244})

V_40 = Vertex(name = 'V_40',
              particles = [ P.vm__tilde__, P.vm, P.Z ],
              color = [ '1' ],
              lorentz = [ L.FFV2 ],
              couplings = {(0,0):C.GC_244})

V_41 = Vertex(name = 'V_41',
              particles = [ P.vt__tilde__, P.vt, P.Z ],
              color = [ '1' ],
              lorentz = [ L.FFV2 ],
              couplings = {(0,0):C.GC_244})

V_42 = Vertex(name = 'V_42',
              particles = [ P.e__plus__, P.ve, P.W__minus__ ],
              color = [ '1' ],
              lorentz = [ L.FFV2 ],
              couplings = {(0,0):C.GC_109})

V_43 = Vertex(name = 'V_43',
              particles = [ P.m__plus__, P.vm, P.W__minus__ ],
              color = [ '1' ],
              lorentz = [ L.FFV2 ],
              couplings = {(0,0):C.GC_109})

V_44 = Vertex(name = 'V_44',
              particles = [ P.tt__plus__, P.vt, P.W__minus__ ],
              color = [ '1' ],
              lorentz = [ L.FFV2 ],
              couplings = {(0,0):C.GC_109})

V_45 = Vertex(name = 'V_45',
              particles = [ P.d__tilde__, P.c, P.W__minus__ ],
              color = [ 'Identity(1,2)' ],
              lorentz = [ L.FFV2 ],
              couplings = {(0,0):C.GC_112})

V_46 = Vertex(name = 'V_46',
              particles = [ P.s__tilde__, P.c, P.W__minus__ ],
              color = [ 'Identity(1,2)' ],
              lorentz = [ L.FFV2 ],
              couplings = {(0,0):C.GC_113})

V_47 = Vertex(name = 'V_47',
              particles = [ P.b__tilde__, P.t, P.W__minus__ ],
              color = [ 'Identity(1,2)' ],
              lorentz = [ L.FFV2 ],
              couplings = {(0,0):C.GC_109})

V_48 = Vertex(name = 'V_48',
              particles = [ P.d__tilde__, P.u, P.W__minus__ ],
              color = [ 'Identity(1,2)' ],
              lorentz = [ L.FFV2 ],
              couplings = {(0,0):C.GC_110})

V_49 = Vertex(name = 'V_49',
              particles = [ P.s__tilde__, P.u, P.W__minus__ ],
              color = [ 'Identity(1,2)' ],
              lorentz = [ L.FFV2 ],
              couplings = {(0,0):C.GC_111})

V_50 = Vertex(name = 'V_50',
              particles = [ P.ve__tilde__, P.e__minus__, P.W__plus__ ],
              color = [ '1' ],
              lorentz = [ L.FFV2 ],
              couplings = {(0,0):C.GC_109})

V_51 = Vertex(name = 'V_51',
              particles = [ P.vm__tilde__, P.m__minus__, P.W__plus__ ],
              color = [ '1' ],
              lorentz = [ L.FFV2 ],
              couplings = {(0,0):C.GC_109})

V_52 = Vertex(name = 'V_52',
              particles = [ P.vt__tilde__, P.tt__minus__, P.W__plus__ ],
              color = [ '1' ],
              lorentz = [ L.FFV2 ],
              couplings = {(0,0):C.GC_109})

V_53 = Vertex(name = 'V_53',
              particles = [ P.t__tilde__, P.b, P.W__plus__ ],
              color = [ 'Identity(1,2)' ],
              lorentz = [ L.FFV2 ],
              couplings = {(0,0):C.GC_109})

V_54 = Vertex(name = 'V_54',
              particles = [ P.c__tilde__, P.d, P.W__plus__ ],
              color = [ 'Identity(1,2)' ],
              lorentz = [ L.FFV2 ],
              couplings = {(0,0):C.GC_541})

V_55 = Vertex(name = 'V_55',
              particles = [ P.u__tilde__, P.d, P.W__plus__ ],
              color = [ 'Identity(1,2)' ],
              lorentz = [ L.FFV2 ],
              couplings = {(0,0):C.GC_539})

V_56 = Vertex(name = 'V_56',
              particles = [ P.c__tilde__, P.s, P.W__plus__ ],
              color = [ 'Identity(1,2)' ],
              lorentz = [ L.FFV2 ],
              couplings = {(0,0):C.GC_542})

V_57 = Vertex(name = 'V_57',
              particles = [ P.u__tilde__, P.s, P.W__plus__ ],
              color = [ 'Identity(1,2)' ],
              lorentz = [ L.FFV2 ],
              couplings = {(0,0):C.GC_540})

V_58 = Vertex(name = 'V_58',
              particles = [ P.b__tilde__, P.b, P.H ],
              color = [ 'Identity(1,2)' ],
              lorentz = [ L.FFS1 ],
              couplings = {(0,0):C.GC_536})

V_59 = Vertex(name = 'V_59',
              particles = [ P.tt__plus__, P.tt__minus__, P.H ],
              color = [ '1' ],
              lorentz = [ L.FFS1 ],
              couplings = {(0,0):C.GC_538})

V_60 = Vertex(name = 'V_60',
              particles = [ P.t__tilde__, P.t, P.H ],
              color = [ 'Identity(1,2)' ],
              lorentz = [ L.FFS1 ],
              couplings = {(0,0):C.GC_537})

V_61 = Vertex(name = 'V_61',
              particles = [ P.W__minus__, P.W__plus__, P.H, P.H, P.H, P.H ],
              color = [ '1' ],
              lorentz = [ L.VVSSSS1, L.VVSSSS3 ],
              couplings = {(0,0):C.GC_100,(0,1):C.GC_101})

V_62 = Vertex(name = 'V_62',
              particles = [ P.W__minus__, P.W__plus__, P.H, P.H, P.H ],
              color = [ '1' ],
              lorentz = [ L.VVSSS1, L.VVSSS3 ],
              couplings = {(0,0):C.GC_348,(0,1):C.GC_349})

V_63 = Vertex(name = 'V_63',
              particles = [ P.W__minus__, P.W__minus__, P.W__plus__, P.W__plus__, P.H, P.H, P.H, P.H ],
              color = [ '1' ],
              lorentz = [ L.VVVVSSSS1, L.VVVVSSSS2 ],
              couplings = {(0,0):C.GC_92,(0,1):C.GC_91})

V_64 = Vertex(name = 'V_64',
              particles = [ P.W__minus__, P.W__minus__, P.W__plus__, P.W__plus__, P.H, P.H, P.H ],
              color = [ '1' ],
              lorentz = [ L.VVVVSSS1, L.VVVVSSS2 ],
              couplings = {(0,0):C.GC_340,(0,1):C.GC_339})

V_65 = Vertex(name = 'V_65',
              particles = [ P.W__minus__, P.W__minus__, P.W__plus__, P.W__plus__, P.H, P.H ],
              color = [ '1' ],
              lorentz = [ L.VVVVSS14, L.VVVVSS27, L.VVVVSS28, L.VVVVSS4, L.VVVVSS40, L.VVVVSS44, L.VVVVSS7, L.VVVVSS8 ],
              couplings = {(0,2):C.GC_94,(0,1):C.GC_98,(0,4):C.GC_125,(0,0):C.GC_71,(0,6):C.GC_75,(0,3):C.GC_402,(0,7):C.GC_401,(0,5):C.GC_68})

V_66 = Vertex(name = 'V_66',
              particles = [ P.W__minus__, P.W__minus__, P.W__plus__, P.W__plus__, P.H ],
              color = [ '1' ],
              lorentz = [ L.VVVVS25, L.VVVVS26, L.VVVVS38, L.VVVVS4, L.VVVVS7, L.VVVVS8 ],
              couplings = {(0,1):C.GC_342,(0,0):C.GC_346,(0,2):C.GC_368,(0,4):C.GC_442,(0,3):C.GC_438,(0,5):C.GC_437})

V_67 = Vertex(name = 'V_67',
              particles = [ P.W__minus__, P.W__plus__, P.Z, P.H, P.H, P.H, P.H ],
              color = [ '1' ],
              lorentz = [ L.VVVSSSS1 ],
              couplings = {(0,0):C.GC_87})

V_68 = Vertex(name = 'V_68',
              particles = [ P.W__minus__, P.W__plus__, P.Z, P.H, P.H, P.H ],
              color = [ '1' ],
              lorentz = [ L.VVVSSS1 ],
              couplings = {(0,0):C.GC_454})

V_69 = Vertex(name = 'V_69',
              particles = [ P.W__minus__, P.W__plus__, P.Z, P.H, P.H ],
              color = [ '1' ],
              lorentz = [ L.VVVSS10, L.VVVSS11, L.VVVSS12, L.VVVSS13, L.VVVSS14, L.VVVSS15, L.VVVSS4, L.VVVSS5, L.VVVSS6 ],
              couplings = {(0,1):C.GC_118,(0,8):C.GC_136,(0,0):C.GC_8,(0,7):C.GC_6,(0,3):C.GC_67,(0,2):C.GC_141,(0,6):C.GC_500,(0,5):C.GC_66,(0,4):C.GC_139})

V_70 = Vertex(name = 'V_70',
              particles = [ P.W__minus__, P.W__plus__, P.Z, P.H ],
              color = [ '1' ],
              lorentz = [ L.VVVS2, L.VVVS3, L.VVVS4, L.VVVS8, L.VVVS9 ],
              couplings = {(0,4):C.GC_361,(0,2):C.GC_376,(0,3):C.GC_324,(0,1):C.GC_322,(0,0):C.GC_531})

V_71 = Vertex(name = 'V_71',
              particles = [ P.Z, P.Z, P.H, P.H, P.H, P.H ],
              color = [ '1' ],
              lorentz = [ L.VVSSSS2, L.VVSSSS3 ],
              couplings = {(0,0):C.GC_264,(0,1):C.GC_265})

V_72 = Vertex(name = 'V_72',
              particles = [ P.Z, P.Z, P.H, P.H, P.H ],
              color = [ '1' ],
              lorentz = [ L.VVSSS2, L.VVSSS3 ],
              couplings = {(0,0):C.GC_464,(0,1):C.GC_465})

V_73 = Vertex(name = 'V_73',
              particles = [ P.W__minus__, P.W__plus__, P.Z, P.Z, P.H, P.H, P.H, P.H ],
              color = [ '1' ],
              lorentz = [ L.VVVVSSSS1, L.VVVVSSSS2 ],
              couplings = {(0,0):C.GC_77,(0,1):C.GC_78})

V_74 = Vertex(name = 'V_74',
              particles = [ P.W__minus__, P.W__plus__, P.Z, P.Z, P.H, P.H, P.H ],
              color = [ '1' ],
              lorentz = [ L.VVVVSSS1, L.VVVVSSS2 ],
              couplings = {(0,0):C.GC_444,(0,1):C.GC_445})

V_75 = Vertex(name = 'V_75',
              particles = [ P.W__minus__, P.W__plus__, P.Z, P.Z, P.H, P.H ],
              color = [ '1' ],
              lorentz = [ L.VVVVSS10, L.VVVVSS12, L.VVVVSS13, L.VVVVSS14, L.VVVVSS17, L.VVVVSS25, L.VVVVSS26, L.VVVVSS29, L.VVVVSS30, L.VVVVSS32, L.VVVVSS33, L.VVVVSS34, L.VVVVSS37, L.VVVVSS4, L.VVVVSS40, L.VVVVSS42, L.VVVVSS44, L.VVVVSS5, L.VVVVSS7, L.VVVVSS8, L.VVVVSS9 ],
              couplings = {(0,17):C.GC_263,(0,8):C.GC_13,(0,0):C.GC_95,(0,7):C.GC_99,(0,6):C.GC_117,(0,5):C.GC_135,(0,9):C.GC_4,(0,11):C.GC_76,(0,10):C.GC_115,(0,14):C.GC_126,(0,12):C.GC_143,(0,15):C.GC_26,(0,3):C.GC_72,(0,18):C.GC_134,(0,20):C.GC_5,(0,1):C.GC_23,(0,2):C.GC_185,(0,13):C.GC_490,(0,4):C.GC_261,(0,19):C.GC_491,(0,16):C.GC_69})

V_76 = Vertex(name = 'V_76',
              particles = [ P.W__minus__, P.W__plus__, P.Z, P.Z, P.H ],
              color = [ '1' ],
              lorentz = [ L.VVVVS10, L.VVVVS12, L.VVVVS13, L.VVVVS15, L.VVVVS23, L.VVVVS24, L.VVVVS27, L.VVVVS28, L.VVVVS30, L.VVVVS31, L.VVVVS32, L.VVVVS35, L.VVVVS38, L.VVVVS4, L.VVVVS40, L.VVVVS5, L.VVVVS7, L.VVVVS8, L.VVVVS9 ],
              couplings = {(0,15):C.GC_463,(0,7):C.GC_327,(0,0):C.GC_343,(0,6):C.GC_347,(0,5):C.GC_360,(0,4):C.GC_375,(0,8):C.GC_320,(0,10):C.GC_443,(0,9):C.GC_358,(0,12):C.GC_369,(0,11):C.GC_380,(0,14):C.GC_330,(0,16):C.GC_374,(0,18):C.GC_321,(0,1):C.GC_328,(0,2):C.GC_384,(0,13):C.GC_529,(0,3):C.GC_462,(0,17):C.GC_530})

V_77 = Vertex(name = 'V_77',
              particles = [ P.Z, P.Z, P.Z, P.Z, P.H, P.H, P.H, P.H ],
              color = [ '1' ],
              lorentz = [ L.VVVVSSSS3 ],
              couplings = {(0,0):C.GC_307})

V_78 = Vertex(name = 'V_78',
              particles = [ P.Z, P.Z, P.Z, P.Z, P.H, P.H, P.H ],
              color = [ '1' ],
              lorentz = [ L.VVVVSSS3 ],
              couplings = {(0,0):C.GC_484})

V_79 = Vertex(name = 'V_79',
              particles = [ P.Z, P.Z, P.Z, P.Z, P.H, P.H ],
              color = [ '1' ],
              lorentz = [ L.VVVVSS16, L.VVVVSS31, L.VVVVSS35 ],
              couplings = {(0,1):C.GC_302,(0,2):C.GC_301,(0,0):C.GC_526})

V_80 = Vertex(name = 'V_80',
              particles = [ P.Z, P.Z, P.Z, P.Z, P.H ],
              color = [ '1' ],
              lorentz = [ L.VVVVS14, L.VVVVS29, L.VVVVS33 ],
              couplings = {(0,1):C.GC_479,(0,2):C.GC_478,(0,0):C.GC_532})

V_81 = Vertex(name = 'V_81',
              particles = [ P.Z, P.Z, P.Z, P.Z ],
              color = [ '1' ],
              lorentz = [ L.VVVV17, L.VVVV32, L.VVVV36, L.VVVV41, L.VVVV44 ],
              couplings = {(0,4):C.GC_313,(0,3):C.GC_314,(0,1):C.GC_521,(0,2):C.GC_520,(0,0):C.GC_535})

V_82 = Vertex(name = 'V_82',
              particles = [ P.A, P.A, P.H, P.H ],
              color = [ '1' ],
              lorentz = [ L.VVSS5, L.VVSS6 ],
              couplings = {(0,0):C.GC_262,(0,1):C.GC_260})

V_83 = Vertex(name = 'V_83',
              particles = [ P.A, P.Z, P.H, P.H ],
              color = [ '1' ],
              lorentz = [ L.VVSS5, L.VVSS6 ],
              couplings = {(0,0):C.GC_259,(0,1):C.GC_258})

V_84 = Vertex(name = 'V_84',
              particles = [ P.A, P.W__minus__, P.W__plus__, P.H, P.H ],
              color = [ '1' ],
              lorentz = [ L.VVVSS1, L.VVVSS13, L.VVVSS15, L.VVVSS2, L.VVVSS3, L.VVVSS7, L.VVVSS8 ],
              couplings = {(0,5):C.GC_12,(0,6):C.GC_116,(0,0):C.GC_114,(0,3):C.GC_25,(0,1):C.GC_252,(0,4):C.GC_22,(0,2):C.GC_251})

V_85 = Vertex(name = 'V_85',
              particles = [ P.A, P.A, P.W__minus__, P.W__plus__, P.H, P.H ],
              color = [ '1' ],
              lorentz = [ L.VVVVSS14, L.VVVVSS17, L.VVVVSS3, L.VVVVSS37, L.VVVVSS39, L.VVVVSS44, L.VVVVSS5 ],
              couplings = {(0,6):C.GC_85,(0,2):C.GC_23,(0,4):C.GC_26,(0,3):C.GC_143,(0,0):C.GC_282,(0,1):C.GC_84,(0,5):C.GC_280})

V_86 = Vertex(name = 'V_86',
              particles = [ P.A, P.A, P.W__minus__, P.W__plus__, P.H ],
              color = [ '1' ],
              lorentz = [ L.VVVVS15, L.VVVVS3, L.VVVVS35, L.VVVVS37, L.VVVVS5 ],
              couplings = {(0,4):C.GC_452,(0,1):C.GC_328,(0,3):C.GC_330,(0,2):C.GC_380,(0,0):C.GC_451})

V_87 = Vertex(name = 'V_87',
              particles = [ P.A, P.W__minus__, P.W__plus__, P.Z, P.H, P.H ],
              color = [ '1' ],
              lorentz = [ L.VVVVSS1, L.VVVVSS11, L.VVVVSS15, L.VVVVSS18, L.VVVVSS19, L.VVVVSS2, L.VVVVSS20, L.VVVVSS21, L.VVVVSS22, L.VVVVSS23, L.VVVVSS36, L.VVVVSS38, L.VVVVSS41, L.VVVVSS43, L.VVVVSS45, L.VVVVSS6 ],
              couplings = {(0,8):C.GC_119,(0,6):C.GC_137,(0,9):C.GC_9,(0,15):C.GC_97,(0,7):C.GC_83,(0,12):C.GC_28,(0,0):C.GC_121,(0,10):C.GC_123,(0,13):C.GC_142,(0,11):C.GC_187,(0,2):C.GC_254,(0,1):C.GC_140,(0,3):C.GC_7,(0,4):C.GC_96,(0,5):C.GC_86,(0,14):C.GC_253})

V_88 = Vertex(name = 'V_88',
              particles = [ P.A, P.W__minus__, P.W__plus__, P.Z, P.H ],
              color = [ '1' ],
              lorentz = [ L.VVVVS1, L.VVVVS11, L.VVVVS16, L.VVVVS17, L.VVVVS18, L.VVVVS19, L.VVVVS2, L.VVVVS20, L.VVVVS21, L.VVVVS34, L.VVVVS36, L.VVVVS39, L.VVVVS41, L.VVVVS6 ],
              couplings = {(0,7):C.GC_362,(0,4):C.GC_377,(0,8):C.GC_325,(0,13):C.GC_345,(0,5):C.GC_450,(0,11):C.GC_332,(0,0):C.GC_364,(0,9):C.GC_366,(0,12):C.GC_379,(0,10):C.GC_386,(0,1):C.GC_378,(0,2):C.GC_323,(0,3):C.GC_344,(0,6):C.GC_453})

V_89 = Vertex(name = 'V_89',
              particles = [ P.A, P.W__minus__, P.W__minus__, P.W__plus__, P.W__plus__, P.H, P.H ],
              color = [ '1' ],
              lorentz = [ L.VVVVVSS1, L.VVVVVSS31, L.VVVVVSS32, L.VVVVVSS4 ],
              couplings = {(0,2):C.GC_120,(0,1):C.GC_127,(0,0):C.GC_79,(0,3):C.GC_89})

V_90 = Vertex(name = 'V_90',
              particles = [ P.A, P.W__minus__, P.W__minus__, P.W__plus__, P.W__plus__, P.H ],
              color = [ '1' ],
              lorentz = [ L.VVVVVS1, L.VVVVVS31, L.VVVVVS32, L.VVVVVS4 ],
              couplings = {(0,2):C.GC_363,(0,1):C.GC_370,(0,0):C.GC_446,(0,3):C.GC_456})

V_91 = Vertex(name = 'V_91',
              particles = [ P.A, P.W__minus__, P.W__minus__, P.W__plus__, P.W__plus__ ],
              color = [ '1' ],
              lorentz = [ L.VVVVV10, L.VVVVV3, L.VVVVV40, L.VVVVV41, L.VVVVV52, L.VVVVV58, L.VVVVV7 ],
              couplings = {(0,4):C.GC_149,(0,0):C.GC_145,(0,5):C.GC_147,(0,3):C.GC_421,(0,2):C.GC_424,(0,1):C.GC_492,(0,6):C.GC_502})

V_92 = Vertex(name = 'V_92',
              particles = [ P.A, P.A, P.W__minus__, P.W__minus__, P.W__plus__, P.W__plus__, P.H, P.H ],
              color = [ '1' ],
              lorentz = [ L.VVVVVVSS1, L.VVVVVVSS6, L.VVVVVVSS7 ],
              couplings = {(0,2):C.GC_39,(0,1):C.GC_40,(0,0):C.GC_70})

V_93 = Vertex(name = 'V_93',
              particles = [ P.A, P.A, P.W__minus__, P.W__minus__, P.W__plus__, P.W__plus__, P.H ],
              color = [ '1' ],
              lorentz = [ L.VVVVVVS1, L.VVVVVVS6, L.VVVVVVS7 ],
              couplings = {(0,2):C.GC_335,(0,1):C.GC_336,(0,0):C.GC_441})

V_94 = Vertex(name = 'V_94',
              particles = [ P.A, P.A, P.W__minus__, P.W__minus__, P.W__plus__, P.W__plus__ ],
              color = [ '1' ],
              lorentz = [ L.VVVVVV1, L.VVVVVV16, L.VVVVVV26, L.VVVVVV27, L.VVVVVV39, L.VVVVVV40, L.VVVVVV54, L.VVVVVV66, L.VVVVVV8 ],
              couplings = {(0,0):C.GC_50,(0,5):C.GC_195,(0,7):C.GC_197,(0,6):C.GC_199,(0,1):C.GC_52,(0,3):C.GC_398,(0,2):C.GC_399,(0,8):C.GC_487,(0,4):C.GC_48})

V_95 = Vertex(name = 'V_95',
              particles = [ P.W__minus__, P.W__minus__, P.W__plus__, P.W__plus__, P.Z, P.H, P.H ],
              color = [ '1' ],
              lorentz = [ L.VVVVVSS17, L.VVVVVSS18, L.VVVVVSS19, L.VVVVVSS22, L.VVVVVSS30 ],
              couplings = {(0,0):C.GC_29,(0,3):C.GC_80,(0,1):C.GC_102,(0,4):C.GC_105,(0,2):C.GC_88})

V_96 = Vertex(name = 'V_96',
              particles = [ P.W__minus__, P.W__minus__, P.W__plus__, P.W__plus__, P.Z, P.H ],
              color = [ '1' ],
              lorentz = [ L.VVVVVS17, L.VVVVVS18, L.VVVVVS19, L.VVVVVS22, L.VVVVVS30 ],
              couplings = {(0,0):C.GC_333,(0,3):C.GC_447,(0,1):C.GC_350,(0,4):C.GC_353,(0,2):C.GC_455})

V_97 = Vertex(name = 'V_97',
              particles = [ P.W__minus__, P.W__minus__, P.W__plus__, P.W__plus__, P.Z ],
              color = [ '1' ],
              lorentz = [ L.VVVVV26, L.VVVVV27, L.VVVVV28, L.VVVVV31, L.VVVVV39, L.VVVVV42, L.VVVVV47, L.VVVVV56 ],
              couplings = {(0,6):C.GC_33,(0,7):C.GC_32,(0,5):C.GC_31,(0,0):C.GC_396,(0,3):C.GC_493,(0,1):C.GC_411,(0,4):C.GC_414,(0,2):C.GC_501})

V_98 = Vertex(name = 'V_98',
              particles = [ P.W__minus__, P.W__minus__, P.W__minus__, P.W__plus__, P.W__plus__, P.W__plus__, P.H, P.H ],
              color = [ '1' ],
              lorentz = [ L.VVVVVVSS12 ],
              couplings = {(0,0):C.GC_82})

V_99 = Vertex(name = 'V_99',
              particles = [ P.W__minus__, P.W__minus__, P.W__minus__, P.W__plus__, P.W__plus__, P.W__plus__, P.H ],
              color = [ '1' ],
              lorentz = [ L.VVVVVVS12 ],
              couplings = {(0,0):C.GC_449})

V_100 = Vertex(name = 'V_100',
               particles = [ P.W__minus__, P.W__minus__, P.W__minus__, P.W__plus__, P.W__plus__, P.W__plus__ ],
               color = [ '1' ],
               lorentz = [ L.VVVVVV19, L.VVVVVV32, L.VVVVVV45, L.VVVVVV53 ],
               couplings = {(0,3):C.GC_46,(0,0):C.GC_44,(0,2):C.GC_42,(0,1):C.GC_495})

V_101 = Vertex(name = 'V_101',
               particles = [ P.A, P.A, P.Z, P.Z, P.H, P.H ],
               color = [ '1' ],
               lorentz = [ L.VVVVSS17, L.VVVVSS5 ],
               couplings = {(0,1):C.GC_306,(0,0):C.GC_305})

V_102 = Vertex(name = 'V_102',
               particles = [ P.A, P.A, P.Z, P.Z, P.H ],
               color = [ '1' ],
               lorentz = [ L.VVVVS15, L.VVVVS5 ],
               couplings = {(0,1):C.GC_483,(0,0):C.GC_482})

V_103 = Vertex(name = 'V_103',
               particles = [ P.A, P.A, P.Z, P.Z ],
               color = [ '1' ],
               lorentz = [ L.VVVV18, L.VVVV38, L.VVVV40, L.VVVV41, L.VVVV42, L.VVVV44, L.VVVV45, L.VVVV5, L.VVVV8 ],
               couplings = {(0,8):C.GC_311,(0,5):C.GC_272,(0,6):C.GC_182,(0,3):C.GC_273,(0,1):C.GC_183,(0,2):C.GC_312,(0,4):C.GC_310,(0,7):C.GC_525,(0,0):C.GC_524})

V_104 = Vertex(name = 'V_104',
               particles = [ P.A, P.Z, P.Z, P.Z, P.H, P.H ],
               color = [ '1' ],
               lorentz = [ L.VVVVSS18, L.VVVVSS24 ],
               couplings = {(0,1):C.GC_304,(0,0):C.GC_303})

V_105 = Vertex(name = 'V_105',
               particles = [ P.A, P.Z, P.Z, P.Z, P.H ],
               color = [ '1' ],
               lorentz = [ L.VVVVS16, L.VVVVS22 ],
               couplings = {(0,1):C.GC_481,(0,0):C.GC_480})

V_106 = Vertex(name = 'V_106',
               particles = [ P.A, P.Z, P.Z, P.Z ],
               color = [ '1' ],
               lorentz = [ L.VVVV19, L.VVVV25, L.VVVV41, L.VVVV44 ],
               couplings = {(0,3):C.GC_292,(0,2):C.GC_293,(0,1):C.GC_523,(0,0):C.GC_522})

V_107 = Vertex(name = 'V_107',
               particles = [ P.A, P.W__minus__, P.W__plus__, P.Z, P.Z, P.H, P.H ],
               color = [ '1' ],
               lorentz = [ L.VVVVVSS10, L.VVVVVSS11, L.VVVVVSS15, L.VVVVVSS20, L.VVVVVSS21, L.VVVVVSS3, L.VVVVVSS5, L.VVVVVSS6, L.VVVVVSS7, L.VVVVVSS8, L.VVVVVSS9 ],
               couplings = {(0,5):C.GC_295,(0,10):C.GC_128,(0,0):C.GC_144,(0,4):C.GC_27,(0,3):C.GC_186,(0,7):C.GC_24,(0,8):C.GC_103,(0,6):C.GC_104,(0,1):C.GC_283,(0,9):C.GC_184,(0,2):C.GC_294})

V_108 = Vertex(name = 'V_108',
               particles = [ P.A, P.W__minus__, P.W__plus__, P.Z, P.Z, P.H ],
               color = [ '1' ],
               lorentz = [ L.VVVVVS10, L.VVVVVS11, L.VVVVVS15, L.VVVVVS20, L.VVVVVS21, L.VVVVVS3, L.VVVVVS5, L.VVVVVS6, L.VVVVVS7, L.VVVVVS8, L.VVVVVS9 ],
               couplings = {(0,5):C.GC_475,(0,10):C.GC_371,(0,0):C.GC_381,(0,4):C.GC_331,(0,3):C.GC_385,(0,7):C.GC_329,(0,8):C.GC_351,(0,6):C.GC_352,(0,1):C.GC_470,(0,9):C.GC_383,(0,2):C.GC_474})

V_109 = Vertex(name = 'V_109',
               particles = [ P.A, P.W__minus__, P.W__plus__, P.Z, P.Z ],
               color = [ '1' ],
               lorentz = [ L.VVVVV13, L.VVVVV14, L.VVVVV15, L.VVVVV16, L.VVVVV17, L.VVVVV18, L.VVVVV19, L.VVVVV20, L.VVVVV24, L.VVVVV29, L.VVVVV30, L.VVVVV4, L.VVVVV45, L.VVVVV50, L.VVVVV51, L.VVVVV59, L.VVVVV6, L.VVVVV60, L.VVVVV9 ],
               couplings = {(0,14):C.GC_150,(0,12):C.GC_153,(0,7):C.GC_148,(0,6):C.GC_152,(0,13):C.GC_220,(0,17):C.GC_146,(0,15):C.GC_218,(0,18):C.GC_219,(0,11):C.GC_151,(0,16):C.GC_518,(0,4):C.GC_425,(0,5):C.GC_431,(0,10):C.GC_395,(0,9):C.GC_434,(0,1):C.GC_394,(0,2):C.GC_412,(0,0):C.GC_413,(0,3):C.GC_433,(0,8):C.GC_517})

V_110 = Vertex(name = 'V_110',
               particles = [ P.A, P.A, P.W__minus__, P.W__plus__, P.Z, P.Z, P.H, P.H ],
               color = [ '1' ],
               lorentz = [ L.VVVVVVSS2, L.VVVVVVSS5 ],
               couplings = {(0,0):C.GC_316,(0,1):C.GC_315})

V_111 = Vertex(name = 'V_111',
               particles = [ P.A, P.A, P.W__minus__, P.W__plus__, P.Z, P.Z, P.H ],
               color = [ '1' ],
               lorentz = [ L.VVVVVVS2, L.VVVVVVS5 ],
               couplings = {(0,0):C.GC_486,(0,1):C.GC_485})

V_112 = Vertex(name = 'V_112',
               particles = [ P.A, P.A, P.W__minus__, P.W__plus__, P.Z, P.Z ],
               color = [ '1' ],
               lorentz = [ L.VVVVVV1, L.VVVVVV14, L.VVVVVV15, L.VVVVVV16, L.VVVVVV23, L.VVVVVV25, L.VVVVVV39, L.VVVVVV49, L.VVVVVV5, L.VVVVVV50, L.VVVVVV62, L.VVVVVV64, L.VVVVVV7, L.VVVVVV9 ],
               couplings = {(0,0):C.GC_51,(0,1):C.GC_198,(0,9):C.GC_200,(0,7):C.GC_206,(0,11):C.GC_196,(0,10):C.GC_235,(0,2):C.GC_204,(0,4):C.GC_237,(0,12):C.GC_236,(0,3):C.GC_53,(0,8):C.GC_202,(0,13):C.GC_528,(0,6):C.GC_49,(0,5):C.GC_527})

V_113 = Vertex(name = 'V_113',
               particles = [ P.W__minus__, P.W__plus__, P.Z, P.Z, P.Z, P.H, P.H ],
               color = [ '1' ],
               lorentz = [ L.VVVVVSS14, L.VVVVVSS16, L.VVVVVSS23, L.VVVVVSS24, L.VVVVVSS25, L.VVVVVSS26, L.VVVVVSS27, L.VVVVVSS28, L.VVVVVSS29 ],
               couplings = {(0,3):C.GC_276,(0,8):C.GC_30,(0,6):C.GC_106,(0,7):C.GC_122,(0,4):C.GC_124,(0,5):C.GC_250,(0,2):C.GC_217,(0,1):C.GC_274,(0,0):C.GC_216})

V_114 = Vertex(name = 'V_114',
               particles = [ P.W__minus__, P.W__plus__, P.Z, P.Z, P.Z, P.H ],
               color = [ '1' ],
               lorentz = [ L.VVVVVS14, L.VVVVVS16, L.VVVVVS23, L.VVVVVS24, L.VVVVVS25, L.VVVVVS26, L.VVVVVS27, L.VVVVVS28, L.VVVVVS29 ],
               couplings = {(0,3):C.GC_468,(0,8):C.GC_334,(0,6):C.GC_354,(0,7):C.GC_365,(0,4):C.GC_367,(0,5):C.GC_460,(0,2):C.GC_388,(0,1):C.GC_466,(0,0):C.GC_387})

V_115 = Vertex(name = 'V_115',
               particles = [ P.W__minus__, P.W__plus__, P.Z, P.Z, P.Z ],
               color = [ '1' ],
               lorentz = [ L.VVVVV23, L.VVVVV25, L.VVVVV32, L.VVVVV33, L.VVVVV34, L.VVVVV35, L.VVVVV36, L.VVVVV37, L.VVVVV38, L.VVVVV53, L.VVVVV57, L.VVVVV61 ],
               couplings = {(0,11):C.GC_277,(0,9):C.GC_279,(0,10):C.GC_278,(0,3):C.GC_513,(0,8):C.GC_397,(0,6):C.GC_415,(0,7):C.GC_422,(0,4):C.GC_423,(0,5):C.GC_506,(0,2):C.GC_436,(0,1):C.GC_511,(0,0):C.GC_435})

V_116 = Vertex(name = 'V_116',
               particles = [ P.W__minus__, P.W__minus__, P.W__plus__, P.W__plus__, P.Z, P.Z, P.H, P.H ],
               color = [ '1' ],
               lorentz = [ L.VVVVVVSS10, L.VVVVVVSS16, L.VVVVVVSS2, L.VVVVVVSS5, L.VVVVVVSS8, L.VVVVVVSS9 ],
               couplings = {(0,2):C.GC_285,(0,0):C.GC_41,(0,5):C.GC_107,(0,4):C.GC_108,(0,1):C.GC_81,(0,3):C.GC_281})

V_117 = Vertex(name = 'V_117',
               particles = [ P.W__minus__, P.W__minus__, P.W__plus__, P.W__plus__, P.Z, P.Z, P.H ],
               color = [ '1' ],
               lorentz = [ L.VVVVVVS10, L.VVVVVVS16, L.VVVVVVS2, L.VVVVVVS5, L.VVVVVVS8, L.VVVVVVS9 ],
               couplings = {(0,2):C.GC_472,(0,0):C.GC_337,(0,5):C.GC_355,(0,4):C.GC_356,(0,1):C.GC_448,(0,3):C.GC_469})

V_118 = Vertex(name = 'V_118',
               particles = [ P.W__minus__, P.W__minus__, P.W__plus__, P.W__plus__, P.Z, P.Z ],
               color = [ '1' ],
               lorentz = [ L.VVVVVV23, L.VVVVVV25, L.VVVVVV28, L.VVVVVV29, L.VVVVVV30, L.VVVVVV36, L.VVVVVV42, L.VVVVVV62, L.VVVVVV63, L.VVVVVV67, L.VVVVVV7, L.VVVVVV9 ],
               couplings = {(0,8):C.GC_43,(0,9):C.GC_45,(0,6):C.GC_47,(0,7):C.GC_201,(0,0):C.GC_205,(0,10):C.GC_203,(0,11):C.GC_516,(0,4):C.GC_400,(0,3):C.GC_416,(0,2):C.GC_417,(0,5):C.GC_494,(0,1):C.GC_514})

V_119 = Vertex(name = 'V_119',
               particles = [ P.A, P.W__minus__, P.W__minus__, P.W__plus__, P.W__plus__, P.Z, P.H, P.H ],
               color = [ '1' ],
               lorentz = [ L.VVVVVVSS11, L.VVVVVVSS14, L.VVVVVVSS15, L.VVVVVVSS3 ],
               couplings = {(0,2):C.GC_90,(0,3):C.GC_129,(0,0):C.GC_130,(0,1):C.GC_155})

V_120 = Vertex(name = 'V_120',
               particles = [ P.A, P.W__minus__, P.W__minus__, P.W__plus__, P.W__plus__, P.Z, P.H ],
               color = [ '1' ],
               lorentz = [ L.VVVVVVS11, L.VVVVVVS14, L.VVVVVVS15, L.VVVVVVS3 ],
               couplings = {(0,2):C.GC_457,(0,3):C.GC_372,(0,0):C.GC_373,(0,1):C.GC_382})

V_121 = Vertex(name = 'V_121',
               particles = [ P.A, P.W__minus__, P.W__minus__, P.W__plus__, P.W__plus__, P.Z ],
               color = [ '1' ],
               lorentz = [ L.VVVVVV10, L.VVVVVV12, L.VVVVVV3, L.VVVVVV31, L.VVVVVV34, L.VVVVVV35, L.VVVVVV44, L.VVVVVV48, L.VVVVVV57, L.VVVVVV61 ],
               couplings = {(0,9):C.GC_158,(0,8):C.GC_160,(0,7):C.GC_167,(0,6):C.GC_156,(0,0):C.GC_165,(0,2):C.GC_162,(0,5):C.GC_503,(0,1):C.GC_426,(0,3):C.GC_427,(0,4):C.GC_432})

V_122 = Vertex(name = 'V_122',
               particles = [ P.A, P.W__minus__, P.W__plus__, P.Z, P.Z, P.Z, P.H, P.H ],
               color = [ '1' ],
               lorentz = [ L.VVVVVVSS13 ],
               couplings = {(0,0):C.GC_300})

V_123 = Vertex(name = 'V_123',
               particles = [ P.A, P.W__minus__, P.W__plus__, P.Z, P.Z, P.Z, P.H ],
               color = [ '1' ],
               lorentz = [ L.VVVVVVS13 ],
               couplings = {(0,0):C.GC_477})

V_124 = Vertex(name = 'V_124',
               particles = [ P.A, P.W__minus__, P.W__plus__, P.Z, P.Z, P.Z ],
               color = [ '1' ],
               lorentz = [ L.VVVVVV11, L.VVVVVV13, L.VVVVVV20, L.VVVVVV21, L.VVVVVV33, L.VVVVVV47, L.VVVVVV55, L.VVVVVV56, L.VVVVVV59, L.VVVVVV60 ],
               couplings = {(0,6):C.GC_161,(0,5):C.GC_169,(0,7):C.GC_228,(0,9):C.GC_157,(0,8):C.GC_225,(0,2):C.GC_159,(0,0):C.GC_166,(0,3):C.GC_226,(0,1):C.GC_163,(0,4):C.GC_519})

V_125 = Vertex(name = 'V_125',
               particles = [ P.W__minus__, P.W__plus__, P.Z, P.Z, P.Z, P.Z, P.H, P.H ],
               color = [ '1' ],
               lorentz = [ L.VVVVVVSS4 ],
               couplings = {(0,0):C.GC_284})

V_126 = Vertex(name = 'V_126',
               particles = [ P.W__minus__, P.W__plus__, P.Z, P.Z, P.Z, P.Z, P.H ],
               color = [ '1' ],
               lorentz = [ L.VVVVVVS4 ],
               couplings = {(0,0):C.GC_471})

V_127 = Vertex(name = 'V_127',
               particles = [ P.W__minus__, P.W__plus__, P.Z, P.Z, P.Z, P.Z ],
               color = [ '1' ],
               lorentz = [ L.VVVVVV22, L.VVVVVV24, L.VVVVVV58, L.VVVVVV65 ],
               couplings = {(0,0):C.GC_287,(0,2):C.GC_288,(0,3):C.GC_286,(0,1):C.GC_515})

V_128 = Vertex(name = 'V_128',
               particles = [ P.A, P.W__minus__, P.W__plus__, P.H ],
               color = [ '1' ],
               lorentz = [ L.VVVS1, L.VVVS5, L.VVVS6 ],
               couplings = {(0,1):C.GC_326,(0,2):C.GC_359,(0,0):C.GC_357})

V_129 = Vertex(name = 'V_129',
               particles = [ P.A, P.A, P.W__minus__, P.W__plus__, P.Z, P.H, P.H ],
               color = [ '1' ],
               lorentz = [ L.VVVVVSS12, L.VVVVVSS13, L.VVVVVSS2, L.VVVVVSS33 ],
               couplings = {(0,0):C.GC_275,(0,2):C.GC_249,(0,3):C.GC_299,(0,1):C.GC_248})

V_130 = Vertex(name = 'V_130',
               particles = [ P.A, P.A, P.W__minus__, P.W__plus__, P.Z, P.H ],
               color = [ '1' ],
               lorentz = [ L.VVVVVS12, L.VVVVVS13, L.VVVVVS2, L.VVVVVS33 ],
               couplings = {(0,0):C.GC_467,(0,2):C.GC_459,(0,3):C.GC_476,(0,1):C.GC_458})

V_131 = Vertex(name = 'V_131',
               particles = [ P.A, P.A, P.W__minus__, P.W__plus__, P.Z ],
               color = [ '1' ],
               lorentz = [ L.VVVVV1, L.VVVVV11, L.VVVVV12, L.VVVVV2, L.VVVVV21, L.VVVVV22, L.VVVVV44, L.VVVVV48, L.VVVVV49, L.VVVVV5, L.VVVVV54, L.VVVVV55 ],
               couplings = {(0,6):C.GC_36,(0,7):C.GC_190,(0,8):C.GC_193,(0,10):C.GC_189,(0,11):C.GC_192,(0,0):C.GC_35,(0,2):C.GC_188,(0,3):C.GC_191,(0,4):C.GC_512,(0,9):C.GC_505,(0,1):C.GC_34,(0,5):C.GC_504})

V_132 = Vertex(name = 'V_132',
               particles = [ P.A, P.Z, P.Z, P.H, P.H ],
               color = [ '1' ],
               lorentz = [ L.VVVSS9 ],
               couplings = {(0,0):C.GC_289})

V_133 = Vertex(name = 'V_133',
               particles = [ P.A, P.Z, P.Z, P.H ],
               color = [ '1' ],
               lorentz = [ L.VVVS7 ],
               couplings = {(0,0):C.GC_473})

V_134 = Vertex(name = 'V_134',
               particles = [ P.A, P.A, P.A, P.A ],
               color = [ '1' ],
               lorentz = [ L.VVVV41, L.VVVV44 ],
               couplings = {(0,1):C.GC_308,(0,0):C.GC_309})

V_135 = Vertex(name = 'V_135',
               particles = [ P.A, P.A, P.A, P.Z ],
               color = [ '1' ],
               lorentz = [ L.VVVV41, L.VVVV44 ],
               couplings = {(0,1):C.GC_290,(0,0):C.GC_291})

V_136 = Vertex(name = 'V_136',
               particles = [ P.A, P.A, P.A, P.W__minus__, P.W__plus__ ],
               color = [ '1' ],
               lorentz = [ L.VVVVV43, L.VVVVV46, L.VVVVV8 ],
               couplings = {(0,1):C.GC_298,(0,2):C.GC_297,(0,0):C.GC_296})

V_137 = Vertex(name = 'V_137',
               particles = [ P.A, P.A, P.A, P.A, P.W__minus__, P.W__plus__ ],
               color = [ '1' ],
               lorentz = [ L.VVVVVV43, L.VVVVVV46, L.VVVVVV6 ],
               couplings = {(0,2):C.GC_318,(0,0):C.GC_319,(0,1):C.GC_317})

V_138 = Vertex(name = 'V_138',
               particles = [ P.A, P.A, P.A, P.W__minus__, P.W__plus__, P.Z ],
               color = [ '1' ],
               lorentz = [ L.VVVVVV17, L.VVVVVV18, L.VVVVVV2, L.VVVVVV37, L.VVVVVV38, L.VVVVVV4, L.VVVVVV41, L.VVVVVV51, L.VVVVVV52 ],
               couplings = {(0,2):C.GC_166,(0,0):C.GC_222,(0,6):C.GC_168,(0,7):C.GC_223,(0,8):C.GC_227,(0,1):C.GC_226,(0,3):C.GC_221,(0,5):C.GC_224,(0,4):C.GC_164})

V_139 = Vertex(name = 'V_139',
               particles = [ P.A, P.A, P.A, P.W__minus__, P.W__minus__, P.W__plus__, P.W__plus__ ],
               color = [ '1' ],
               lorentz = [ L.VVVVVVV1, L.VVVVVVV11, L.VVVVVVV17 ],
               couplings = {(0,0):C.GC_229,(0,2):C.GC_231,(0,1):C.GC_230})

V_140 = Vertex(name = 'V_140',
               particles = [ P.A, P.W__minus__, P.W__minus__, P.W__minus__, P.W__plus__, P.W__plus__, P.W__plus__ ],
               color = [ '1' ],
               lorentz = [ L.VVVVVVV3, L.VVVVVVV4, L.VVVVVVV8 ],
               couplings = {(0,0):C.GC_172,(0,1):C.GC_174,(0,2):C.GC_170})

V_141 = Vertex(name = 'V_141',
               particles = [ P.A, P.A, P.A, P.A, P.W__minus__, P.W__minus__, P.W__plus__, P.W__plus__ ],
               color = [ '1' ],
               lorentz = [ L.VVVVVVVV17, L.VVVVVVVV2, L.VVVVVVVV24 ],
               couplings = {(0,1):C.GC_238,(0,2):C.GC_239,(0,0):C.GC_240})

V_142 = Vertex(name = 'V_142',
               particles = [ P.A, P.A, P.W__minus__, P.W__minus__, P.W__plus__, P.W__plus__, P.Z ],
               color = [ '1' ],
               lorentz = [ L.VVVVVVV12, L.VVVVVVV13, L.VVVVVVV6 ],
               couplings = {(0,0):C.GC_208,(0,1):C.GC_209,(0,2):C.GC_207})

V_143 = Vertex(name = 'V_143',
               particles = [ P.A, P.A, P.W__minus__, P.W__minus__, P.W__minus__, P.W__plus__, P.W__plus__, P.W__plus__ ],
               color = [ '1' ],
               lorentz = [ L.VVVVVVVV16, L.VVVVVVVV22, L.VVVVVVVV4 ],
               couplings = {(0,2):C.GC_212,(0,0):C.GC_214,(0,1):C.GC_210})

V_144 = Vertex(name = 'V_144',
               particles = [ P.W__minus__, P.W__minus__, P.W__minus__, P.W__plus__, P.W__plus__, P.W__plus__, P.Z ],
               color = [ '1' ],
               lorentz = [ L.VVVVVVV10, L.VVVVVVV16, L.VVVVVVV18 ],
               couplings = {(0,1):C.GC_54,(0,2):C.GC_58,(0,0):C.GC_56})

V_145 = Vertex(name = 'V_145',
               particles = [ P.W__minus__, P.W__minus__, P.W__minus__, P.W__minus__, P.W__plus__, P.W__plus__, P.W__plus__, P.W__plus__ ],
               color = [ '1' ],
               lorentz = [ L.VVVVVVVV21 ],
               couplings = {(0,0):C.GC_73})

V_146 = Vertex(name = 'V_146',
               particles = [ P.A, P.A, P.A, P.W__minus__, P.W__minus__, P.W__plus__, P.W__plus__, P.Z ],
               color = [ '1' ],
               lorentz = [ L.VVVVVVVV12, L.VVVVVVVV14, L.VVVVVVVV7 ],
               couplings = {(0,2):C.GC_233,(0,1):C.GC_234,(0,0):C.GC_232})

V_147 = Vertex(name = 'V_147',
               particles = [ P.A, P.W__minus__, P.W__minus__, P.W__plus__, P.W__plus__, P.Z, P.Z ],
               color = [ '1' ],
               lorentz = [ L.VVVVVVV2, L.VVVVVVV5, L.VVVVVVV7 ],
               couplings = {(0,0):C.GC_171,(0,1):C.GC_173,(0,2):C.GC_175})

V_148 = Vertex(name = 'V_148',
               particles = [ P.A, P.W__minus__, P.W__minus__, P.W__minus__, P.W__plus__, P.W__plus__, P.W__plus__, P.Z ],
               color = [ '1' ],
               lorentz = [ L.VVVVVVVV10, L.VVVVVVVV18, L.VVVVVVVV6 ],
               couplings = {(0,2):C.GC_176,(0,0):C.GC_180,(0,1):C.GC_178})

V_149 = Vertex(name = 'V_149',
               particles = [ P.A, P.A, P.W__minus__, P.W__minus__, P.W__plus__, P.W__plus__, P.Z, P.Z ],
               color = [ '1' ],
               lorentz = [ L.VVVVVVVV15, L.VVVVVVVV3, L.VVVVVVVV9 ],
               couplings = {(0,1):C.GC_211,(0,0):C.GC_213,(0,2):C.GC_215})

V_150 = Vertex(name = 'V_150',
               particles = [ P.W__minus__, P.W__minus__, P.W__plus__, P.W__plus__, P.Z, P.Z, P.Z ],
               color = [ '1' ],
               lorentz = [ L.VVVVVVV14, L.VVVVVVV15, L.VVVVVVV9 ],
               couplings = {(0,0):C.GC_57,(0,1):C.GC_59,(0,2):C.GC_55})

V_151 = Vertex(name = 'V_151',
               particles = [ P.W__minus__, P.W__minus__, P.W__minus__, P.W__plus__, P.W__plus__, P.W__plus__, P.Z, P.Z ],
               color = [ '1' ],
               lorentz = [ L.VVVVVVVV1, L.VVVVVVVV19, L.VVVVVVVV25 ],
               couplings = {(0,0):C.GC_62,(0,1):C.GC_64,(0,2):C.GC_60})

V_152 = Vertex(name = 'V_152',
               particles = [ P.A, P.W__minus__, P.W__minus__, P.W__plus__, P.W__plus__, P.Z, P.Z, P.Z ],
               color = [ '1' ],
               lorentz = [ L.VVVVVVVV11, L.VVVVVVVV13, L.VVVVVVVV8 ],
               couplings = {(0,2):C.GC_179,(0,1):C.GC_181,(0,0):C.GC_177})

V_153 = Vertex(name = 'V_153',
               particles = [ P.W__minus__, P.W__minus__, P.W__plus__, P.W__plus__, P.Z, P.Z, P.Z, P.Z ],
               color = [ '1' ],
               lorentz = [ L.VVVVVVVV20, L.VVVVVVVV23, L.VVVVVVVV5 ],
               couplings = {(0,2):C.GC_61,(0,1):C.GC_63,(0,0):C.GC_65})

