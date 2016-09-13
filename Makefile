TARGET_MAIN=main
TARGET_REMOVE=rm
TARGET_ALL=all

DIR_SRC=src/
DIR_INC=include/
DIR_OBJ=obj/

PATH_SRC=$(DIR_SRC)$(FILE_SRC)

_DEPS=catch.hpp Domain.hpp Entity.hpp Headers.hpp
DEPS = $(patsubst %,$(DIR_INC)%,$(_DEPS))

_OBJ=Main.o Domain.o Entity.o 
OBJ = $(patsubst %,$(DIR_OBJ)%,$(_OBJ))

CFLAGS=g++ -std=c++0x 

$(DIR_OBJ)%.o: $(DIR_SRC)%.cpp $(DEPS)
	$(CFLAGS) -c -o $@ $< -I$(DIR_INC)

$(TARGET_ALL): $(TARGET_REMOVE) $(TARGET_MAIN)

$(TARGET_MAIN): $(OBJ)
	$(CFLAGS) -o $@ $^ -I$(DIR_INC)

$(TARGET_REMOVE):
	$(TARGET_REMOVE) -f $(TARGET_MAIN)


