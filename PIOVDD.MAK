all: pio.sys

pio.sys: $(OBJS) $(LIBS) $(DEF) makefile
        $(LINK) $(LFLAGS) @<<$(@B).lnk
$(OBJ1) +
$(OBJ2)
$@
$*.map
$(LIBS)
$(DEF)
<<keep
        $(MAPSYM) $*.map
