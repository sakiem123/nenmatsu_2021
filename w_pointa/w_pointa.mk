MAKEFILE_DIR 	:= $(dir $(lastword $(MAKEFILE_LIST)))
INCLUDE 		+= $(MAKEFILE_DIR)include
W_SRCDIR		:= $(MAKEFILE_DIR)src
W_SRCS			:= $(wildcard $(W_SRCDIR)/*.c)
SRCS			+= $(W_SRCS)
W_OBJDIR		:= $(MAKEFILE_DIR)obj
OBJDIR			+= $(W_OBJDIR)
OBJS			+= $(addprefix $(W_OBJDIR)/,$(patsubst %.c,%.o,$(W_SRCS)))
