NAME = uls

SRCD = src
INCD = inc
OBJD = obj
LBMXD = libmx

LMBX = libmx.a
INC = uls.h
SRC = uls.c \
	mx_getCurrentFlags.c \
	mx_sortFlags.c \
	mx_countFlags.c \
	mx_getErrors.c \
	mx_getPermission.c \
	mx_getFiles.c \
	mx_getDirs.c \
	mx_prior.c \
	sorting.c \
	mx_backsort.c \
	mx_printErr.c \
	get_info.c \
	mx_standartout.c \
	mx_printFiles.c \
	mx_space.c \
	mx_defSpace.c \
	output.c \
	mx_sizetoa.c \
	mx_getFinfo.c \
	mx_printinode.c \
	get_max_len.c \
	mx_printname.c \
	mx_printDirs.c \
	mx_1l.c \
	mx_2l.c \
	mx_readdir.c \
	mx_isAllow.c \
	mx_getAll.c \
	mx_flagR.c \

INCLUDE = -I $(LBMXD) \
	-I $(INCD) \

LBMXS = $(addprefix $(LBMXD)/, $(LMBX))
INCS = $(addprefix $(INCD)/, $(INC))
SRCS = $(addprefix $(SRCD)/, $(SRC))
OBJS = $(addprefix $(OBJD)/, $(SRC:%.c=%.o))
	
CFLAGS = -std=c11 -g $(addprefix -W, all extra error pedantic)

all: install clean

install: $(LBMXS) $(NAME)

$(LBMXS):
	@cd $(LBMXD) && make -f Makefile install

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(LBMXS) $(OBJS) -o $@

$(OBJD)/%.o: $(SRCD)/%.c $(INCS)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(OBJS): | $(OBJD)

$(OBJD):
	@mkdir -p $@

uninstall: clean
	@cd $(LBMXD) && make -f Makefile uninstall
	@rm -rf $(NAME)	

clean:
	@cd $(LBMXD) && make -f Makefile clean
	@rm -rf $(OBJD)

reinstall: clean all
