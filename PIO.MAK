pio.sys: pioinit.obj piouser.obj pioin.obj pioout.obj piodata.obj piocout.obj ioseg.obj
	\sdk20\toolkt20\os2bin\link386 /nod /noi /noe /map:0 /exepack /align:16 pioinit+piouser+pioin+pioout+piodata+piocout+ioseg,pio.sys,pio,d:\drvlib\vdd\vdh.lib\
        ,pio.def
        mapsym pio

pioinit.obj: pioinit.c pio.h mvdm.h
	cl386 -c -Asnw -G3s -Zflp pioinit.c

pioin.obj: pioin.c pio.h mvdm.h
	cl386 -c -Asnw -G3s -Zflp pioin.c

pioout.obj: pioout.c pio.h mvdm.h
	cl386 -c -Asnw -G3s -Zflp pioout.c

piouser.obj: piouser.c pio.h mvdm.h
	cl386 -c -Asnw -G3s -Zflp piouser.c

piodata.obj: piodata.c pio.h mvdm.h
	cl386 -c -Asnw -G3s -Zflp piodata.c

piocout.obj: piocout.c pio.h mvdm.h
	cl386 -c -Asnw -G3s -Zflp piocout.c

ioseg.obj: ioseg.asm
       ml /c /Cx ioseg.asm

