CC		:= gcc
INCLUDE := include
DEST	:= bin
PROGRAM := mainprog
SRCDIR	:= src
SRCS	:= $(wildcard $(SRCDIR)/*.c)
R_SRCS  := $(wildcard $(SRCDIR)/*.c)
OBJDIR	:= obj
R_OBJDIR:= $(OBJDIR)
OBJS	:= $(addprefix $(R_OBJDIR)/,$(patsubst %.c,%.o,$(R_SRCS)))
COMPILE_SWITCH := NORMAL_MODE DEBUG_MODE

include */*.mk

.PHONY: all clean
#test:
#		echo "****SRCS**** $(SRCS)"
#		echo "****R_SRCS**** $(R_SRCS)"
#		echo "****OBJS**** $(OBJS)"
#		echo "****INCLUDE**** $(INCLUDE)"
#		echo "****OBJDIR**** $(OBJDIR)"
#		echo "$(addsuffix /*, $(OBJDIR))"
#		echo "$(OBJDIR)/%.o: %.c"
#		echo "$(addsuffix /%.o, $(OBJDIR)): %.c"

all:	$(PROGRAM)

$(PROGRAM):	$(OBJS)
		$(CC) -o $(DEST)/$@ $^

$(addsuffix /%.o, $(OBJDIR)): %.c
		@if [ ! -e `dirname $@` ]; then mkdir -p `dirname $@`; fi
		$(CC) $(addprefix -D ,$(COMPILE_SWITCH)) $(addprefix -I ,$(INCLUDE)) -o $@ -c $<

clean:		
		rm -rf bin/*
		rm -rf $(addsuffix /*, $(OBJDIR))
