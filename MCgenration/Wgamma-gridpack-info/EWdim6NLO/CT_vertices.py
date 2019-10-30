# This file was automatically created by FeynRules 2.1.7
# Mathematica version: 8.0 for Mac OS X x86 (64-bit) (November 6, 2010)
# Date: Fri 29 Nov 2013 12:01:45


from object_library import all_vertices, all_CTvertices, Vertex, CTVertex
import particles as P
import CT_couplings as C
import lorentz as L


V_1 = CTVertex(name = 'V_1',
               type = 'R2',
               particles = [ P.g, P.g, P.g ],
               color = [ 'f(1,2,3)' ],
               lorentz = [ L.VVV8 ],
               loop_particles = [ [ [P.b], [P.c], [P.d], [P.s], [P.t], [P.u] ], [ [P.g] ] ],
               couplings = {(0,0,0):C.R2GC_403_55,(0,0,1):C.R2GC_403_56})

V_2 = CTVertex(name = 'V_2',
               type = 'R2',
               particles = [ P.g, P.g, P.g, P.g ],
               color = [ 'd(-1,1,3)*d(-1,2,4)', 'd(-1,1,3)*f(-1,2,4)', 'd(-1,1,4)*d(-1,2,3)', 'd(-1,1,4)*f(-1,2,3)', 'd(-1,2,3)*f(-1,1,4)', 'd(-1,2,4)*f(-1,1,3)', 'f(-1,1,2)*f(-1,3,4)', 'f(-1,1,3)*f(-1,2,4)', 'f(-1,1,4)*f(-1,2,3)', 'Identity(1,2)*Identity(3,4)', 'Identity(1,3)*Identity(2,4)', 'Identity(1,4)*Identity(2,3)' ],
               lorentz = [ L.VVVV12, L.VVVV2, L.VVVV3, L.VVVV5 ],
               loop_particles = [ [ [P.b], [P.c], [P.d], [P.s], [P.t], [P.u] ], [ [P.g] ] ],
               couplings = {(2,1,0):C.R2GC_370_37,(2,1,1):C.R2GC_370_38,(0,1,0):C.R2GC_370_37,(0,1,1):C.R2GC_370_38,(4,1,0):C.R2GC_368_33,(4,1,1):C.R2GC_368_34,(3,1,0):C.R2GC_368_33,(3,1,1):C.R2GC_368_34,(8,1,0):C.R2GC_369_35,(8,1,1):C.R2GC_369_36,(7,1,0):C.R2GC_375_44,(7,1,1):C.R2GC_407_61,(6,1,0):C.R2GC_374_42,(6,1,1):C.R2GC_408_62,(5,1,0):C.R2GC_368_33,(5,1,1):C.R2GC_368_34,(1,1,0):C.R2GC_368_33,(1,1,1):C.R2GC_368_34,(11,0,0):C.R2GC_372_40,(11,0,1):C.R2GC_372_41,(10,0,0):C.R2GC_372_40,(10,0,1):C.R2GC_372_41,(9,0,1):C.R2GC_371_39,(2,2,0):C.R2GC_370_37,(2,2,1):C.R2GC_370_38,(0,2,0):C.R2GC_370_37,(0,2,1):C.R2GC_370_38,(6,2,0):C.R2GC_404_57,(6,2,1):C.R2GC_404_58,(4,2,0):C.R2GC_368_33,(4,2,1):C.R2GC_368_34,(3,2,0):C.R2GC_368_33,(3,2,1):C.R2GC_368_34,(8,2,0):C.R2GC_369_35,(8,2,1):C.R2GC_409_63,(7,2,0):C.R2GC_375_44,(7,2,1):C.R2GC_375_45,(5,2,0):C.R2GC_368_33,(5,2,1):C.R2GC_368_34,(1,2,0):C.R2GC_368_33,(1,2,1):C.R2GC_368_34,(2,3,0):C.R2GC_370_37,(2,3,1):C.R2GC_370_38,(0,3,0):C.R2GC_370_37,(0,3,1):C.R2GC_370_38,(4,3,0):C.R2GC_368_33,(4,3,1):C.R2GC_368_34,(3,3,0):C.R2GC_368_33,(3,3,1):C.R2GC_368_34,(8,3,0):C.R2GC_369_35,(8,3,1):C.R2GC_406_60,(6,3,0):C.R2GC_374_42,(6,3,1):C.R2GC_374_43,(7,3,0):C.R2GC_405_59,(7,3,1):C.R2GC_370_38,(5,3,0):C.R2GC_368_33,(5,3,1):C.R2GC_368_34,(1,3,0):C.R2GC_368_33,(1,3,1):C.R2GC_368_34})

V_3 = CTVertex(name = 'V_3',
               type = 'R2',
               particles = [ P.c__tilde__, P.s, P.G__plus__ ],
               color = [ 'Identity(1,2)' ],
               lorentz = [ L.FFS5 ],
               loop_particles = [ [ [P.c, P.g, P.s] ] ],
               couplings = {(0,0,0):C.R2GC_400_53})

V_4 = CTVertex(name = 'V_4',
               type = 'R2',
               particles = [ P.t__tilde__, P.b, P.G__plus__ ],
               color = [ 'Identity(1,2)' ],
               lorentz = [ L.FFS3, L.FFS5 ],
               loop_particles = [ [ [P.b, P.g, P.t] ] ],
               couplings = {(0,0,0):C.R2GC_418_66,(0,1,0):C.R2GC_421_69})

V_5 = CTVertex(name = 'V_5',
               type = 'R2',
               particles = [ P.b__tilde__, P.b, P.G0 ],
               color = [ 'Identity(1,2)' ],
               lorentz = [ L.FFS1 ],
               loop_particles = [ [ [P.b, P.g] ] ],
               couplings = {(0,0,0):C.R2GC_390_49})

V_6 = CTVertex(name = 'V_6',
               type = 'R2',
               particles = [ P.b__tilde__, P.b, P.H ],
               color = [ 'Identity(1,2)' ],
               lorentz = [ L.FFS2 ],
               loop_particles = [ [ [P.b, P.g] ] ],
               couplings = {(0,0,0):C.R2GC_389_48})

V_7 = CTVertex(name = 'V_7',
               type = 'R2',
               particles = [ P.c__tilde__, P.c, P.G0 ],
               color = [ 'Identity(1,2)' ],
               lorentz = [ L.FFS1 ],
               loop_particles = [ [ [P.c, P.g] ] ],
               couplings = {(0,0,0):C.R2GC_398_51})

V_8 = CTVertex(name = 'V_8',
               type = 'R2',
               particles = [ P.t__tilde__, P.t, P.G0 ],
               color = [ 'Identity(1,2)' ],
               lorentz = [ L.FFS1 ],
               loop_particles = [ [ [P.g, P.t] ] ],
               couplings = {(0,0,0):C.R2GC_419_67})

V_9 = CTVertex(name = 'V_9',
               type = 'R2',
               particles = [ P.c__tilde__, P.c, P.H ],
               color = [ 'Identity(1,2)' ],
               lorentz = [ L.FFS2 ],
               loop_particles = [ [ [P.c, P.g] ] ],
               couplings = {(0,0,0):C.R2GC_399_52})

V_10 = CTVertex(name = 'V_10',
                type = 'R2',
                particles = [ P.t__tilde__, P.t, P.H ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFS2 ],
                loop_particles = [ [ [P.g, P.t] ] ],
                couplings = {(0,0,0):C.R2GC_420_68})

V_11 = CTVertex(name = 'V_11',
                type = 'R2',
                particles = [ P.s__tilde__, P.c, P.G__minus__ ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFS3 ],
                loop_particles = [ [ [P.c, P.g, P.s] ] ],
                couplings = {(0,0,0):C.R2GC_401_54})

V_12 = CTVertex(name = 'V_12',
                type = 'R2',
                particles = [ P.b__tilde__, P.t, P.G__minus__ ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFS3, L.FFS5 ],
                loop_particles = [ [ [P.b, P.g, P.t] ] ],
                couplings = {(0,0,0):C.R2GC_422_70,(0,1,0):C.R2GC_417_65})

V_13 = CTVertex(name = 'V_13',
                type = 'R2',
                particles = [ P.u__tilde__, P.u, P.a ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV1 ],
                loop_particles = [ [ [P.g, P.u] ] ],
                couplings = {(0,0,0):C.R2GC_340_7})

V_14 = CTVertex(name = 'V_14',
                type = 'R2',
                particles = [ P.c__tilde__, P.c, P.a ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV1 ],
                loop_particles = [ [ [P.c, P.g] ] ],
                couplings = {(0,0,0):C.R2GC_340_7})

V_15 = CTVertex(name = 'V_15',
                type = 'R2',
                particles = [ P.t__tilde__, P.t, P.a ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV1 ],
                loop_particles = [ [ [P.g, P.t] ] ],
                couplings = {(0,0,0):C.R2GC_340_7})

V_16 = CTVertex(name = 'V_16',
                type = 'R2',
                particles = [ P.u__tilde__, P.u, P.g ],
                color = [ 'T(3,2,1)' ],
                lorentz = [ L.FFV1 ],
                loop_particles = [ [ [P.g, P.u] ] ],
                couplings = {(0,0,0):C.R2GC_331_4})

V_17 = CTVertex(name = 'V_17',
                type = 'R2',
                particles = [ P.c__tilde__, P.c, P.g ],
                color = [ 'T(3,2,1)' ],
                lorentz = [ L.FFV1 ],
                loop_particles = [ [ [P.c, P.g] ] ],
                couplings = {(0,0,0):C.R2GC_331_4})

V_18 = CTVertex(name = 'V_18',
                type = 'R2',
                particles = [ P.t__tilde__, P.t, P.g ],
                color = [ 'T(3,2,1)' ],
                lorentz = [ L.FFV1 ],
                loop_particles = [ [ [P.g, P.t] ] ],
                couplings = {(0,0,0):C.R2GC_331_4})

V_19 = CTVertex(name = 'V_19',
                type = 'R2',
                particles = [ P.d__tilde__, P.u, P.W__minus__ ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV2 ],
                loop_particles = [ [ [P.d, P.g, P.u] ] ],
                couplings = {(0,0,0):C.R2GC_382_46})

V_20 = CTVertex(name = 'V_20',
                type = 'R2',
                particles = [ P.s__tilde__, P.c, P.W__minus__ ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV2 ],
                loop_particles = [ [ [P.c, P.g, P.s] ] ],
                couplings = {(0,0,0):C.R2GC_382_46})

V_21 = CTVertex(name = 'V_21',
                type = 'R2',
                particles = [ P.b__tilde__, P.t, P.W__minus__ ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV2 ],
                loop_particles = [ [ [P.b, P.g, P.t] ] ],
                couplings = {(0,0,0):C.R2GC_382_46})

V_22 = CTVertex(name = 'V_22',
                type = 'R2',
                particles = [ P.u__tilde__, P.u, P.Z ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV2, L.FFV8 ],
                loop_particles = [ [ [P.g, P.u] ] ],
                couplings = {(0,0,0):C.R2GC_342_8,(0,1,0):C.R2GC_333_6})

V_23 = CTVertex(name = 'V_23',
                type = 'R2',
                particles = [ P.c__tilde__, P.c, P.Z ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV2, L.FFV8 ],
                loop_particles = [ [ [P.c, P.g] ] ],
                couplings = {(0,0,0):C.R2GC_342_8,(0,1,0):C.R2GC_333_6})

V_24 = CTVertex(name = 'V_24',
                type = 'R2',
                particles = [ P.t__tilde__, P.t, P.Z ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV2, L.FFV8 ],
                loop_particles = [ [ [P.g, P.t] ] ],
                couplings = {(0,0,0):C.R2GC_342_8,(0,1,0):C.R2GC_333_6})

V_25 = CTVertex(name = 'V_25',
                type = 'R2',
                particles = [ P.d__tilde__, P.d, P.a ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV1 ],
                loop_particles = [ [ [P.d, P.g] ] ],
                couplings = {(0,0,0):C.R2GC_330_3})

V_26 = CTVertex(name = 'V_26',
                type = 'R2',
                particles = [ P.s__tilde__, P.s, P.a ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV1 ],
                loop_particles = [ [ [P.g, P.s] ] ],
                couplings = {(0,0,0):C.R2GC_330_3})

V_27 = CTVertex(name = 'V_27',
                type = 'R2',
                particles = [ P.b__tilde__, P.b, P.a ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV1 ],
                loop_particles = [ [ [P.b, P.g] ] ],
                couplings = {(0,0,0):C.R2GC_330_3})

V_28 = CTVertex(name = 'V_28',
                type = 'R2',
                particles = [ P.d__tilde__, P.d, P.g ],
                color = [ 'T(3,2,1)' ],
                lorentz = [ L.FFV1 ],
                loop_particles = [ [ [P.d, P.g] ] ],
                couplings = {(0,0,0):C.R2GC_331_4})

V_29 = CTVertex(name = 'V_29',
                type = 'R2',
                particles = [ P.s__tilde__, P.s, P.g ],
                color = [ 'T(3,2,1)' ],
                lorentz = [ L.FFV1 ],
                loop_particles = [ [ [P.g, P.s] ] ],
                couplings = {(0,0,0):C.R2GC_331_4})

V_30 = CTVertex(name = 'V_30',
                type = 'R2',
                particles = [ P.b__tilde__, P.b, P.g ],
                color = [ 'T(3,2,1)' ],
                lorentz = [ L.FFV1 ],
                loop_particles = [ [ [P.b, P.g] ] ],
                couplings = {(0,0,0):C.R2GC_331_4})

V_31 = CTVertex(name = 'V_31',
                type = 'R2',
                particles = [ P.u__tilde__, P.d, P.W__plus__ ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV2 ],
                loop_particles = [ [ [P.d, P.g, P.u] ] ],
                couplings = {(0,0,0):C.R2GC_382_46})

V_32 = CTVertex(name = 'V_32',
                type = 'R2',
                particles = [ P.c__tilde__, P.s, P.W__plus__ ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV2 ],
                loop_particles = [ [ [P.c, P.g, P.s] ] ],
                couplings = {(0,0,0):C.R2GC_382_46})

V_33 = CTVertex(name = 'V_33',
                type = 'R2',
                particles = [ P.t__tilde__, P.b, P.W__plus__ ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV2 ],
                loop_particles = [ [ [P.b, P.g, P.t] ] ],
                couplings = {(0,0,0):C.R2GC_382_46})

V_34 = CTVertex(name = 'V_34',
                type = 'R2',
                particles = [ P.d__tilde__, P.d, P.Z ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV2, L.FFV3 ],
                loop_particles = [ [ [P.d, P.g] ] ],
                couplings = {(0,0,0):C.R2GC_332_5,(0,1,0):C.R2GC_333_6})

V_35 = CTVertex(name = 'V_35',
                type = 'R2',
                particles = [ P.s__tilde__, P.s, P.Z ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV2, L.FFV3 ],
                loop_particles = [ [ [P.g, P.s] ] ],
                couplings = {(0,0,0):C.R2GC_332_5,(0,1,0):C.R2GC_333_6})

V_36 = CTVertex(name = 'V_36',
                type = 'R2',
                particles = [ P.b__tilde__, P.b, P.Z ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV2, L.FFV3 ],
                loop_particles = [ [ [P.b, P.g] ] ],
                couplings = {(0,0,0):C.R2GC_332_5,(0,1,0):C.R2GC_333_6})

V_37 = CTVertex(name = 'V_37',
                type = 'R2',
                particles = [ P.u__tilde__, P.u ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FF1 ],
                loop_particles = [ [ [P.g, P.u] ] ],
                couplings = {(0,0,0):C.R2GC_329_2})

V_38 = CTVertex(name = 'V_38',
                type = 'R2',
                particles = [ P.c__tilde__, P.c ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FF2, L.FF3 ],
                loop_particles = [ [ [P.c, P.g] ] ],
                couplings = {(0,0,0):C.R2GC_394_50,(0,1,0):C.R2GC_329_2})

V_39 = CTVertex(name = 'V_39',
                type = 'R2',
                particles = [ P.t__tilde__, P.t ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FF2, L.FF3 ],
                loop_particles = [ [ [P.g, P.t] ] ],
                couplings = {(0,0,0):C.R2GC_413_64,(0,1,0):C.R2GC_329_2})

V_40 = CTVertex(name = 'V_40',
                type = 'R2',
                particles = [ P.d__tilde__, P.d ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FF1 ],
                loop_particles = [ [ [P.d, P.g] ] ],
                couplings = {(0,0,0):C.R2GC_329_2})

V_41 = CTVertex(name = 'V_41',
                type = 'R2',
                particles = [ P.s__tilde__, P.s ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FF1 ],
                loop_particles = [ [ [P.g, P.s] ] ],
                couplings = {(0,0,0):C.R2GC_329_2})

V_42 = CTVertex(name = 'V_42',
                type = 'R2',
                particles = [ P.b__tilde__, P.b ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FF2, L.FF3 ],
                loop_particles = [ [ [P.b, P.g] ] ],
                couplings = {(0,0,0):C.R2GC_386_47,(0,1,0):C.R2GC_329_2})

V_43 = CTVertex(name = 'V_43',
                type = 'R2',
                particles = [ P.g, P.g ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.VV2, L.VV3, L.VV4 ],
                loop_particles = [ [ [P.b] ], [ [P.b], [P.c], [P.d], [P.s], [P.t], [P.u] ], [ [P.c] ], [ [P.g] ], [ [P.t] ] ],
                couplings = {(0,2,3):C.R2GC_328_1,(0,0,0):C.R2GC_344_9,(0,0,2):C.R2GC_344_10,(0,0,4):C.R2GC_344_11,(0,1,1):C.R2GC_347_18})

V_44 = CTVertex(name = 'V_44',
                type = 'R2',
                particles = [ P.g, P.g, P.H ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.VVS4 ],
                loop_particles = [ [ [P.b] ], [ [P.c] ], [ [P.t] ] ],
                couplings = {(0,0,0):C.R2GC_346_15,(0,0,1):C.R2GC_346_16,(0,0,2):C.R2GC_346_17})

V_45 = CTVertex(name = 'V_45',
                type = 'R2',
                particles = [ P.g, P.g, P.W__minus__, P.W__plus__ ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.VVVV12 ],
                loop_particles = [ [ [P.b, P.t], [P.c, P.s], [P.d, P.u] ] ],
                couplings = {(0,0,0):C.R2GC_355_32})

V_46 = CTVertex(name = 'V_46',
                type = 'R2',
                particles = [ P.a, P.g, P.g, P.Z ],
                color = [ 'Identity(2,3)' ],
                lorentz = [ L.VVVV12 ],
                loop_particles = [ [ [P.b], [P.d], [P.s] ], [ [P.c], [P.t], [P.u] ] ],
                couplings = {(0,0,0):C.R2GC_350_23,(0,0,1):C.R2GC_350_24})

V_47 = CTVertex(name = 'V_47',
                type = 'R2',
                particles = [ P.g, P.g, P.Z, P.Z ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.VVVV12 ],
                loop_particles = [ [ [P.b], [P.d], [P.s] ], [ [P.c], [P.t], [P.u] ] ],
                couplings = {(0,0,0):C.R2GC_353_29,(0,0,1):C.R2GC_353_30})

V_48 = CTVertex(name = 'V_48',
                type = 'R2',
                particles = [ P.a, P.a, P.g, P.g ],
                color = [ 'Identity(3,4)' ],
                lorentz = [ L.VVVV12 ],
                loop_particles = [ [ [P.b], [P.d], [P.s] ], [ [P.c], [P.t], [P.u] ] ],
                couplings = {(0,0,0):C.R2GC_348_19,(0,0,1):C.R2GC_348_20})

V_49 = CTVertex(name = 'V_49',
                type = 'R2',
                particles = [ P.g, P.g, P.g, P.Z ],
                color = [ 'd(1,2,3)', 'f(1,2,3)' ],
                lorentz = [ L.VVVV1, L.VVVV12 ],
                loop_particles = [ [ [P.b], [P.d], [P.s] ], [ [P.c], [P.t], [P.u] ] ],
                couplings = {(1,0,0):C.R2GC_352_27,(1,0,1):C.R2GC_352_28,(0,1,0):C.R2GC_351_25,(0,1,1):C.R2GC_351_26})

V_50 = CTVertex(name = 'V_50',
                type = 'R2',
                particles = [ P.a, P.g, P.g, P.g ],
                color = [ 'd(2,3,4)' ],
                lorentz = [ L.VVVV12 ],
                loop_particles = [ [ [P.b], [P.d], [P.s] ], [ [P.c], [P.t], [P.u] ] ],
                couplings = {(0,0,0):C.R2GC_349_21,(0,0,1):C.R2GC_349_22})

V_51 = CTVertex(name = 'V_51',
                type = 'R2',
                particles = [ P.g, P.g, P.H, P.H ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.VVSS13 ],
                loop_particles = [ [ [P.b] ], [ [P.c] ], [ [P.t] ] ],
                couplings = {(0,0,0):C.R2GC_345_12,(0,0,1):C.R2GC_345_13,(0,0,2):C.R2GC_345_14})

V_52 = CTVertex(name = 'V_52',
                type = 'R2',
                particles = [ P.g, P.g, P.G0, P.G0 ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.VVSS13 ],
                loop_particles = [ [ [P.b] ], [ [P.c] ], [ [P.t] ] ],
                couplings = {(0,0,0):C.R2GC_345_12,(0,0,1):C.R2GC_345_13,(0,0,2):C.R2GC_345_14})

V_53 = CTVertex(name = 'V_53',
                type = 'R2',
                particles = [ P.g, P.g, P.G__minus__, P.G__plus__ ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.VVSS13 ],
                loop_particles = [ [ [P.b, P.t] ], [ [P.c, P.s] ] ],
                couplings = {(0,0,0):C.R2GC_354_31,(0,0,1):C.R2GC_345_13})

V_54 = CTVertex(name = 'V_54',
                type = 'UV',
                particles = [ P.g, P.g, P.g ],
                color = [ 'f(1,2,3)' ],
                lorentz = [ L.VVV6, L.VVV8, L.VVV9 ],
                loop_particles = [ [ [P.b] ], [ [P.c] ], [ [P.d], [P.s], [P.u] ], [ [P.g] ], [ [P.ghG] ], [ [P.t] ] ],
                couplings = {(0,1,0):C.UVGC_403_55,(0,1,1):C.UVGC_403_56,(0,1,2):C.UVGC_403_57,(0,1,5):C.UVGC_403_58,(0,2,3):C.UVGC_356_1,(0,0,4):C.UVGC_357_2})

V_55 = CTVertex(name = 'V_55',
                type = 'UV',
                particles = [ P.g, P.g, P.g, P.g ],
                color = [ 'd(-1,1,3)*d(-1,2,4)', 'd(-1,1,3)*f(-1,2,4)', 'd(-1,1,4)*d(-1,2,3)', 'd(-1,1,4)*f(-1,2,3)', 'd(-1,2,3)*f(-1,1,4)', 'd(-1,2,4)*f(-1,1,3)', 'f(-1,1,2)*f(-1,3,4)', 'f(-1,1,3)*f(-1,2,4)', 'f(-1,1,4)*f(-1,2,3)', 'Identity(1,2)*Identity(3,4)', 'Identity(1,3)*Identity(2,4)', 'Identity(1,4)*Identity(2,3)' ],
                lorentz = [ L.VVVV12, L.VVVV2, L.VVVV3, L.VVVV5 ],
                loop_particles = [ [ [P.b] ], [ [P.b], [P.c], [P.d], [P.s], [P.t], [P.u] ], [ [P.c] ], [ [P.d], [P.s], [P.u] ], [ [P.g] ], [ [P.ghG] ], [ [P.t] ] ],
                couplings = {(2,1,4):C.UVGC_369_12,(2,1,5):C.UVGC_369_11,(0,1,4):C.UVGC_369_12,(0,1,5):C.UVGC_369_11,(4,1,4):C.UVGC_368_9,(4,1,5):C.UVGC_368_10,(3,1,4):C.UVGC_368_9,(3,1,5):C.UVGC_368_10,(8,1,4):C.UVGC_369_11,(8,1,5):C.UVGC_369_12,(7,1,0):C.UVGC_407_72,(7,1,2):C.UVGC_407_73,(7,1,3):C.UVGC_407_74,(7,1,4):C.UVGC_407_75,(7,1,5):C.UVGC_407_76,(7,1,6):C.UVGC_407_77,(6,1,0):C.UVGC_407_72,(6,1,2):C.UVGC_407_73,(6,1,3):C.UVGC_407_74,(6,1,4):C.UVGC_408_78,(6,1,5):C.UVGC_408_79,(6,1,6):C.UVGC_407_77,(5,1,4):C.UVGC_368_9,(5,1,5):C.UVGC_368_10,(1,1,4):C.UVGC_368_9,(1,1,5):C.UVGC_368_10,(11,0,4):C.UVGC_372_15,(11,0,5):C.UVGC_372_16,(10,0,4):C.UVGC_372_15,(10,0,5):C.UVGC_372_16,(9,0,4):C.UVGC_371_13,(9,0,5):C.UVGC_371_14,(2,2,4):C.UVGC_369_12,(2,2,5):C.UVGC_369_11,(0,2,4):C.UVGC_369_12,(0,2,5):C.UVGC_369_11,(6,2,0):C.UVGC_404_59,(6,2,2):C.UVGC_404_60,(6,2,4):C.UVGC_404_61,(6,2,5):C.UVGC_404_62,(6,2,6):C.UVGC_404_63,(4,2,4):C.UVGC_368_9,(4,2,5):C.UVGC_368_10,(3,2,4):C.UVGC_368_9,(3,2,5):C.UVGC_368_10,(8,2,0):C.UVGC_409_80,(8,2,2):C.UVGC_409_81,(8,2,3):C.UVGC_409_82,(8,2,4):C.UVGC_409_83,(8,2,5):C.UVGC_409_84,(8,2,6):C.UVGC_409_85,(7,2,1):C.UVGC_374_23,(7,2,4):C.UVGC_375_25,(7,2,5):C.UVGC_375_26,(5,2,4):C.UVGC_368_9,(5,2,5):C.UVGC_368_10,(1,2,4):C.UVGC_368_9,(1,2,5):C.UVGC_368_10,(2,3,4):C.UVGC_369_12,(2,3,5):C.UVGC_369_11,(0,3,4):C.UVGC_369_12,(0,3,5):C.UVGC_369_11,(4,3,4):C.UVGC_368_9,(4,3,5):C.UVGC_368_10,(3,3,4):C.UVGC_368_9,(3,3,5):C.UVGC_368_10,(8,3,0):C.UVGC_406_66,(8,3,2):C.UVGC_406_67,(8,3,3):C.UVGC_406_68,(8,3,4):C.UVGC_406_69,(8,3,5):C.UVGC_406_70,(8,3,6):C.UVGC_406_71,(6,3,1):C.UVGC_374_23,(6,3,4):C.UVGC_374_24,(6,3,5):C.UVGC_371_13,(7,3,0):C.UVGC_404_59,(7,3,2):C.UVGC_404_60,(7,3,4):C.UVGC_405_64,(7,3,5):C.UVGC_405_65,(7,3,6):C.UVGC_404_63,(5,3,4):C.UVGC_368_9,(5,3,5):C.UVGC_368_10,(1,3,4):C.UVGC_368_9,(1,3,5):C.UVGC_368_10})

V_56 = CTVertex(name = 'V_56',
                type = 'UV',
                particles = [ P.c__tilde__, P.s, P.G__plus__ ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFS5 ],
                loop_particles = [ [ [P.c, P.g] ], [ [P.c, P.g, P.s] ], [ [P.g, P.s] ] ],
                couplings = {(0,0,0):C.UVGC_400_46,(0,0,2):C.UVGC_400_47,(0,0,1):C.UVGC_400_48})

V_57 = CTVertex(name = 'V_57',
                type = 'UV',
                particles = [ P.t__tilde__, P.b, P.G__plus__ ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFS3, L.FFS5 ],
                loop_particles = [ [ [P.b, P.g] ], [ [P.b, P.g, P.t] ], [ [P.g, P.t] ] ],
                couplings = {(0,0,0):C.UVGC_418_97,(0,0,2):C.UVGC_418_98,(0,0,1):C.UVGC_418_99,(0,1,0):C.UVGC_421_102,(0,1,2):C.UVGC_421_103,(0,1,1):C.UVGC_421_104})

V_58 = CTVertex(name = 'V_58',
                type = 'UV',
                particles = [ P.b__tilde__, P.b, P.G0 ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFS1 ],
                loop_particles = [ [ [P.b, P.g] ] ],
                couplings = {(0,0,0):C.UVGC_390_36})

V_59 = CTVertex(name = 'V_59',
                type = 'UV',
                particles = [ P.b__tilde__, P.b, P.H ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFS2 ],
                loop_particles = [ [ [P.b, P.g] ] ],
                couplings = {(0,0,0):C.UVGC_389_35})

V_60 = CTVertex(name = 'V_60',
                type = 'UV',
                particles = [ P.c__tilde__, P.c, P.G0 ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFS1 ],
                loop_particles = [ [ [P.c, P.g] ] ],
                couplings = {(0,0,0):C.UVGC_398_44})

V_61 = CTVertex(name = 'V_61',
                type = 'UV',
                particles = [ P.t__tilde__, P.t, P.G0 ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFS1 ],
                loop_particles = [ [ [P.g, P.t] ] ],
                couplings = {(0,0,0):C.UVGC_419_100})

V_62 = CTVertex(name = 'V_62',
                type = 'UV',
                particles = [ P.c__tilde__, P.c, P.H ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFS2 ],
                loop_particles = [ [ [P.c, P.g] ] ],
                couplings = {(0,0,0):C.UVGC_399_45})

V_63 = CTVertex(name = 'V_63',
                type = 'UV',
                particles = [ P.t__tilde__, P.t, P.H ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFS2 ],
                loop_particles = [ [ [P.g, P.t] ] ],
                couplings = {(0,0,0):C.UVGC_420_101})

V_64 = CTVertex(name = 'V_64',
                type = 'UV',
                particles = [ P.s__tilde__, P.c, P.G__minus__ ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFS3 ],
                loop_particles = [ [ [P.c, P.g] ], [ [P.c, P.g, P.s] ], [ [P.g, P.s] ] ],
                couplings = {(0,0,0):C.UVGC_401_49,(0,0,2):C.UVGC_401_50,(0,0,1):C.UVGC_401_51})

V_65 = CTVertex(name = 'V_65',
                type = 'UV',
                particles = [ P.b__tilde__, P.t, P.G__minus__ ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFS3, L.FFS5 ],
                loop_particles = [ [ [P.b, P.g] ], [ [P.b, P.g, P.t] ], [ [P.g, P.t] ] ],
                couplings = {(0,0,0):C.UVGC_422_105,(0,0,2):C.UVGC_422_106,(0,0,1):C.UVGC_422_107,(0,1,0):C.UVGC_417_94,(0,1,2):C.UVGC_417_95,(0,1,1):C.UVGC_417_96})

V_66 = CTVertex(name = 'V_66',
                type = 'UV',
                particles = [ P.u__tilde__, P.u, P.a ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV4 ],
                loop_particles = [ [ [P.g, P.u] ] ],
                couplings = {(0,0,0):C.UVGC_365_6})

V_67 = CTVertex(name = 'V_67',
                type = 'UV',
                particles = [ P.c__tilde__, P.c, P.a ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV1, L.FFV6 ],
                loop_particles = [ [ [P.c, P.g] ] ],
                couplings = {(0,0,0):C.UVGC_365_6,(0,1,0):C.UVGC_392_38})

V_68 = CTVertex(name = 'V_68',
                type = 'UV',
                particles = [ P.t__tilde__, P.t, P.a ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV1, L.FFV6 ],
                loop_particles = [ [ [P.g, P.t] ] ],
                couplings = {(0,0,0):C.UVGC_365_6,(0,1,0):C.UVGC_411_87})

V_69 = CTVertex(name = 'V_69',
                type = 'UV',
                particles = [ P.u__tilde__, P.u, P.g ],
                color = [ 'T(3,2,1)' ],
                lorentz = [ L.FFV5, L.FFV6 ],
                loop_particles = [ [ [P.b] ], [ [P.c] ], [ [P.d], [P.s], [P.u] ], [ [P.g] ], [ [P.ghG] ], [ [P.g, P.u] ], [ [P.t] ] ],
                couplings = {(0,0,5):C.UVGC_360_5,(0,1,0):C.UVGC_373_17,(0,1,1):C.UVGC_373_18,(0,1,2):C.UVGC_373_19,(0,1,3):C.UVGC_373_20,(0,1,4):C.UVGC_373_21,(0,1,6):C.UVGC_373_22})

V_70 = CTVertex(name = 'V_70',
                type = 'UV',
                particles = [ P.c__tilde__, P.c, P.g ],
                color = [ 'T(3,2,1)' ],
                lorentz = [ L.FFV1, L.FFV6 ],
                loop_particles = [ [ [P.b] ], [ [P.c] ], [ [P.c, P.g] ], [ [P.d], [P.s], [P.u] ], [ [P.g] ], [ [P.ghG] ], [ [P.t] ] ],
                couplings = {(0,0,2):C.UVGC_360_5,(0,1,0):C.UVGC_373_17,(0,1,1):C.UVGC_373_18,(0,1,3):C.UVGC_373_19,(0,1,4):C.UVGC_373_20,(0,1,5):C.UVGC_373_21,(0,1,6):C.UVGC_373_22,(0,1,2):C.UVGC_393_39})

V_71 = CTVertex(name = 'V_71',
                type = 'UV',
                particles = [ P.t__tilde__, P.t, P.g ],
                color = [ 'T(3,2,1)' ],
                lorentz = [ L.FFV1, L.FFV6 ],
                loop_particles = [ [ [P.b] ], [ [P.c] ], [ [P.d], [P.s], [P.u] ], [ [P.g] ], [ [P.ghG] ], [ [P.g, P.t] ], [ [P.t] ] ],
                couplings = {(0,0,5):C.UVGC_360_5,(0,1,0):C.UVGC_373_17,(0,1,1):C.UVGC_373_18,(0,1,2):C.UVGC_373_19,(0,1,3):C.UVGC_373_20,(0,1,4):C.UVGC_373_21,(0,1,6):C.UVGC_373_22,(0,1,5):C.UVGC_412_88})

V_72 = CTVertex(name = 'V_72',
                type = 'UV',
                particles = [ P.d__tilde__, P.u, P.W__minus__ ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV2 ],
                loop_particles = [ [ [P.d, P.g], [P.g, P.u] ], [ [P.d, P.g, P.u] ] ],
                couplings = {(0,0,0):C.UVGC_382_27,(0,0,1):C.UVGC_382_28})

V_73 = CTVertex(name = 'V_73',
                type = 'UV',
                particles = [ P.s__tilde__, P.c, P.W__minus__ ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV2 ],
                loop_particles = [ [ [P.c, P.g] ], [ [P.c, P.g, P.s] ], [ [P.g, P.s] ] ],
                couplings = {(0,0,0):C.UVGC_395_41,(0,0,2):C.UVGC_382_27,(0,0,1):C.UVGC_382_28})

V_74 = CTVertex(name = 'V_74',
                type = 'UV',
                particles = [ P.b__tilde__, P.t, P.W__minus__ ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV2 ],
                loop_particles = [ [ [P.b, P.g] ], [ [P.b, P.g, P.t] ], [ [P.g, P.t] ] ],
                couplings = {(0,0,0):C.UVGC_414_90,(0,0,2):C.UVGC_414_91,(0,0,1):C.UVGC_382_28})

V_75 = CTVertex(name = 'V_75',
                type = 'UV',
                particles = [ P.c__tilde__, P.c, P.Z ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV2, L.FFV8 ],
                loop_particles = [ [ [P.c, P.g] ] ],
                couplings = {(0,0,0):C.UVGC_396_42,(0,1,0):C.UVGC_397_43})

V_76 = CTVertex(name = 'V_76',
                type = 'UV',
                particles = [ P.t__tilde__, P.t, P.Z ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV2, L.FFV8 ],
                loop_particles = [ [ [P.g, P.t] ] ],
                couplings = {(0,0,0):C.UVGC_415_92,(0,1,0):C.UVGC_416_93})

V_77 = CTVertex(name = 'V_77',
                type = 'UV',
                particles = [ P.d__tilde__, P.d, P.a ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV4 ],
                loop_particles = [ [ [P.d, P.g] ] ],
                couplings = {(0,0,0):C.UVGC_359_4})

V_78 = CTVertex(name = 'V_78',
                type = 'UV',
                particles = [ P.s__tilde__, P.s, P.a ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV4 ],
                loop_particles = [ [ [P.g, P.s] ] ],
                couplings = {(0,0,0):C.UVGC_359_4})

V_79 = CTVertex(name = 'V_79',
                type = 'UV',
                particles = [ P.b__tilde__, P.b, P.a ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV1, L.FFV6 ],
                loop_particles = [ [ [P.b, P.g] ] ],
                couplings = {(0,0,0):C.UVGC_359_4,(0,1,0):C.UVGC_384_30})

V_80 = CTVertex(name = 'V_80',
                type = 'UV',
                particles = [ P.d__tilde__, P.d, P.g ],
                color = [ 'T(3,2,1)' ],
                lorentz = [ L.FFV5, L.FFV6 ],
                loop_particles = [ [ [P.b] ], [ [P.c] ], [ [P.d, P.g] ], [ [P.d], [P.s], [P.u] ], [ [P.g] ], [ [P.ghG] ], [ [P.t] ] ],
                couplings = {(0,0,2):C.UVGC_360_5,(0,1,0):C.UVGC_373_17,(0,1,1):C.UVGC_373_18,(0,1,3):C.UVGC_373_19,(0,1,4):C.UVGC_373_20,(0,1,5):C.UVGC_373_21,(0,1,6):C.UVGC_373_22})

V_81 = CTVertex(name = 'V_81',
                type = 'UV',
                particles = [ P.s__tilde__, P.s, P.g ],
                color = [ 'T(3,2,1)' ],
                lorentz = [ L.FFV5, L.FFV6 ],
                loop_particles = [ [ [P.b] ], [ [P.c] ], [ [P.d], [P.s], [P.u] ], [ [P.g] ], [ [P.ghG] ], [ [P.g, P.s] ], [ [P.t] ] ],
                couplings = {(0,0,5):C.UVGC_360_5,(0,1,0):C.UVGC_373_17,(0,1,1):C.UVGC_373_18,(0,1,2):C.UVGC_373_19,(0,1,3):C.UVGC_373_20,(0,1,4):C.UVGC_373_21,(0,1,6):C.UVGC_373_22})

V_82 = CTVertex(name = 'V_82',
                type = 'UV',
                particles = [ P.b__tilde__, P.b, P.g ],
                color = [ 'T(3,2,1)' ],
                lorentz = [ L.FFV1, L.FFV6 ],
                loop_particles = [ [ [P.b] ], [ [P.b, P.g] ], [ [P.c] ], [ [P.d], [P.s], [P.u] ], [ [P.g] ], [ [P.ghG] ], [ [P.t] ] ],
                couplings = {(0,0,1):C.UVGC_360_5,(0,1,0):C.UVGC_373_17,(0,1,2):C.UVGC_373_18,(0,1,3):C.UVGC_373_19,(0,1,4):C.UVGC_373_20,(0,1,5):C.UVGC_373_21,(0,1,6):C.UVGC_373_22,(0,1,1):C.UVGC_385_31})

V_83 = CTVertex(name = 'V_83',
                type = 'UV',
                particles = [ P.u__tilde__, P.d, P.W__plus__ ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV2 ],
                loop_particles = [ [ [P.d, P.g], [P.g, P.u] ], [ [P.d, P.g, P.u] ] ],
                couplings = {(0,0,0):C.UVGC_382_27,(0,0,1):C.UVGC_382_28})

V_84 = CTVertex(name = 'V_84',
                type = 'UV',
                particles = [ P.c__tilde__, P.s, P.W__plus__ ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV2 ],
                loop_particles = [ [ [P.c, P.g] ], [ [P.c, P.g, P.s] ], [ [P.g, P.s] ] ],
                couplings = {(0,0,0):C.UVGC_395_41,(0,0,2):C.UVGC_382_27,(0,0,1):C.UVGC_382_28})

V_85 = CTVertex(name = 'V_85',
                type = 'UV',
                particles = [ P.t__tilde__, P.b, P.W__plus__ ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV2 ],
                loop_particles = [ [ [P.b, P.g] ], [ [P.b, P.g, P.t] ], [ [P.g, P.t] ] ],
                couplings = {(0,0,0):C.UVGC_414_90,(0,0,2):C.UVGC_414_91,(0,0,1):C.UVGC_382_28})

V_86 = CTVertex(name = 'V_86',
                type = 'UV',
                particles = [ P.b__tilde__, P.b, P.Z ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FFV2, L.FFV3 ],
                loop_particles = [ [ [P.b, P.g] ] ],
                couplings = {(0,0,0):C.UVGC_387_33,(0,1,0):C.UVGC_388_34})

V_87 = CTVertex(name = 'V_87',
                type = 'UV',
                particles = [ P.u__tilde__, P.u ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FF4 ],
                loop_particles = [ [ [P.g, P.u] ] ],
                couplings = {(0,0,0):C.UVGC_358_3})

V_88 = CTVertex(name = 'V_88',
                type = 'UV',
                particles = [ P.c__tilde__, P.c ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FF2, L.FF3 ],
                loop_particles = [ [ [P.c, P.g] ] ],
                couplings = {(0,0,0):C.UVGC_394_40,(0,1,0):C.UVGC_391_37})

V_89 = CTVertex(name = 'V_89',
                type = 'UV',
                particles = [ P.t__tilde__, P.t ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FF2, L.FF3 ],
                loop_particles = [ [ [P.g, P.t] ] ],
                couplings = {(0,0,0):C.UVGC_413_89,(0,1,0):C.UVGC_410_86})

V_90 = CTVertex(name = 'V_90',
                type = 'UV',
                particles = [ P.d__tilde__, P.d ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FF4 ],
                loop_particles = [ [ [P.d, P.g] ] ],
                couplings = {(0,0,0):C.UVGC_358_3})

V_91 = CTVertex(name = 'V_91',
                type = 'UV',
                particles = [ P.s__tilde__, P.s ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FF4 ],
                loop_particles = [ [ [P.g, P.s] ] ],
                couplings = {(0,0,0):C.UVGC_358_3})

V_92 = CTVertex(name = 'V_92',
                type = 'UV',
                particles = [ P.b__tilde__, P.b ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.FF2, L.FF3 ],
                loop_particles = [ [ [P.b, P.g] ] ],
                couplings = {(0,0,0):C.UVGC_386_32,(0,1,0):C.UVGC_383_29})

V_93 = CTVertex(name = 'V_93',
                type = 'UV',
                particles = [ P.g, P.g ],
                color = [ 'Identity(1,2)' ],
                lorentz = [ L.VV1, L.VV5 ],
                loop_particles = [ [ [P.b] ], [ [P.c] ], [ [P.g] ], [ [P.ghG] ], [ [P.t] ] ],
                couplings = {(0,1,0):C.UVGC_402_52,(0,1,1):C.UVGC_402_53,(0,1,4):C.UVGC_402_54,(0,0,2):C.UVGC_367_7,(0,0,3):C.UVGC_367_8})

