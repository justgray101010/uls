NAME = uls

INC = ./inc/uls.h

HEADTMP = ./uls.h

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
	get_max_len.c \
	mx_printname.c \
	mx_printDirs.c \
	mx_1l.c \
	mx_2l.c \
	mx_readdir.c \
	mx_isAllow.c \
	mx_getAll.c \
	mx_flagR.c \

SRCS = src/uls.c \
	src/mx_getCurrentFlags.c \
	src/mx_sortFlags.c \
	src/mx_countFlags.c \
	src/mx_getErrors.c \
	src/mx_getPermission.c \
	src/mx_getFiles.c \
	src/mx_getDirs.c \
	src/mx_prior.c \
	src/sorting.c \
	src/mx_backsort.c \
	src/mx_printErr.c \
	src/get_info.c \
	src/mx_standartout.c \
	src/mx_printFiles.c \
	src/mx_space.c \
	src/mx_defSpace.c \
	src/output.c \
	src/mx_sizetoa.c \
	src/mx_getFinfo.c \
	src/get_max_len.c \
	src/mx_printname.c \
	src/mx_printDirs.c \
	src/mx_1l.c \
	src/mx_2l.c \
	src/mx_readdir.c \
	src/mx_isAllow.c \
	src/mx_getAll.c \
	src/mx_flagR.c \
		

OBJ = uls.o \
	mx_getCurrentFlags.o \
	mx_sortFlags.o \
	mx_countFlags.o \
	mx_getErrors.o \
	mx_getPermission.o \
	mx_getFiles.o \
	mx_getDirs.o \
	mx_prior.o \
	sorting.o \
	mx_backsort.o \
	mx_printErr.o \
	get_info.o \
	mx_standartout.o \
	mx_printFiles.o \
	mx_space.o \
	mx_defSpace.o \
	output.o \
	mx_sizetoa.o \
	mx_getFinfo.o \
	get_max_len.o \
	mx_printname.o \
	mx_printDirs.o \
	mx_1l.o \
	mx_2l.o \
	mx_readdir.o \
	mx_isAllow.o \
	mx_getAll.o \
	mx_flagR.o \

OBJO = ./obj/uls.o \
	./obj/mx_getCurrentFlags.o \
	./obj/mx_sortFlags.o \
	./obj/mx_countFlags.o \
	./obj/mx_getErrors.o \
	./obj/mx_getPermission.o \
	./obj/mx_getFiles.o \
	./obj/mx_getDirs.o \
	./obj/mx_prior.o \
	./obj/sorting.o \
	./obj/mx_backsort.o \
	./obj/mx_printErr.o \
	./obj/get_info.o \
	./obj/mx_standartout.o \
	./obj/mx_printFiles.o \
	./obj/mx_space.o \
	./obj/mx_defSpace.o \
	./obj/output.o \
	./obj/mx_sizetoa.o \
	./obj/mx_getFinfo.o \
	./obj/get_max_len.o \
	./obj/mx_printname.o \
	./obj/mx_printDirs.o \
	./obj/mx_1l.o \
	./obj/mx_2l.o \
	./obj/mx_readdir.o \
	./obj/mx_isAllow.o \
	./obj/mx_getAll.o \
	./obj/mx_flagR.o \
		
CFLGS = -std=c11 -Wall -Wextra -Wpedantic -Werror

all: install clean

install:
	@make -C libmx -f Makefile install
	@cp $(INC) $(SRCS) .
	@clang $(CFLGS) -c  $(SRC)
	@mkdir -p obj
	@mv $(OBJ) ./obj
	@clang $(CFLGS) $(OBJO) libmx/libmx.a -o $(NAME)

uninstall: clean
	@make -C libmx -f Makefile uninstall
	@rm -rf $(NAME)

clean:
	@make -C libmx -f Makefile clean
	@rm -rf $(OBJO) $(SRC) $(HEADTMP)
	@rm -rf ./obj

reinstall: uninstall all
