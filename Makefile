TARGET_MAIN=main
TARGET_REMOVE=rm
TARGET_ALL=all

DIR_SRC=src/
DIR_INC=include/
DIR_OBJ=obj/

PATH_SRC=$(DIR_SRC)$(FILE_SRC)

ifdef SYSTEMROOT
	RM = del /Q
	FixPath = $(subst /,\,$1)
else
	ifeq ($(shell uname), Linux)
		RM = rm -f
		FixPath = $1
	endif
endif

_DEPS=catch.hpp Business.hpp Persistence.hpp Domain.hpp Entity.hpp sqlite3.h
DEPS=$(patsubst %,$(DIR_INC)%,$(_DEPS))

_OBJ=Main.o Business.o Persistence.o Entity.o Domain.o Test.o sqlite3.o
OBJ = $(patsubst %,$(DIR_OBJ)%,$(_OBJ))

CFLAGS=g++ -std=gnu++11

obj/sqlite3.o: include/sqlite3.c
	gcc include/sqlite3.c -o obj/sqlite3.o -c

$(DIR_OBJ)%.o: $(DIR_SRC)%.cpp $(DEPS)
	$(CFLAGS) -c -o $@ $< -I$(DIR_INC)

$(TARGET_ALL): $(TARGET_REMOVE) $(TARGET_MAIN)

$(TARGET_MAIN): $(OBJ)
	$(CFLAGS) -o $@ $^ -I$(DIR_INC)

$(TARGET_REMOVE):
	$(RM) $(call FixPath,main)
	$(RM) -r $(DIR_OBJ)
	mkdir $(DIR_OBJ)
