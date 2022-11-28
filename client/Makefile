#
# Makefile
# WARNING: relies on invocation setting current working directory to Makefile location
# This is done in .vscode/task.json
#

PROJECT 			?= sys_monitor
TARGET_X86	= x86
TARGET_T113 = t113

ifeq ($(target), $(TARGET_T113))
	CC				:= arm-openwrt-linux-muslgnueabi-gcc
	DEFINES 		:= -D USE_FBDEV=1 -D USE_EVDEV=1
else ifeq ($(target), $(TARGET_X86))
	CC				:= gcc
	DEFINES			:= -D USE_SDL=1 -D USE_MOUSE=1 -D USE_MOUSEWHEEL=1 -D USE_KEYBOARD=1
	LDLIBS			:= -lSDL2
else
	echo "Usage: make target=[x86|t113]"
endif

SRC_EXT      		:= c
OBJ_EXT				:= o
MAKEFLAGS 			:= -j $(shell nproc)

SRC_DIR				:= ./
WORKING_DIR			:= ./build
BUILD_DIR			:= $(WORKING_DIR)/obj
BIN_DIR				:= $(SRC_DIR)

CFLAGS 				?= -std=gnu99 -O3 -g0 -Wall -Wshadow -Wundef -Wmissing-prototypes \
					   -Wall -Wextra -Wno-unused-function -Wno-error=strict-prototypes\
					   -Wpointer-arith -fno-strict-aliasing -Wno-error=cpp -Wuninitialized \
					   -Wmaybe-uninitialized -Wno-unused-parameter -Wno-missing-field-initializers \
					   -Wtype-limits -Wsizeof-pointer-memaccess -Wno-format-nonliteral -Wno-cast-qual \
					   -Wunreachable-code -Wno-switch-default -Wreturn-type -Wmultichar \
					   -Wformat-security -Wno-ignored-qualifiers -Wno-error=pedantic -Wno-sign-compare \
					   -Wno-error=missing-prototypes -Wdouble-promotion -Wclobbered -Wdeprecated \
					   -Wempty-body -Wtype-limits -Wstack-usage=2048 -Wno-unused-value \
					   -Wno-unused-parameter -Wno-missing-field-initializers -Wuninitialized \
					   -Wmaybe-uninitialized -Wall -Wextra -Wno-unused-parameter \
					   -Wno-missing-field-initializers -Wtype-limits -Wsizeof-pointer-memaccess \
					   -Wno-format-nonliteral -Wpointer-arith -Wno-cast-qual -Wmissing-prototypes \
					   -Wunreachable-code -Wno-switch-default -Wreturn-type -Wmultichar \
					   -Wformat-security -Wno-ignored-qualifiers -Wno-sign-compare

DEFINES				+= -DLV_BUILD_TEST=0 -DUSE_EVDEV=1
INC 				:= -I./ -I./lvgl/
LDLIBS	 			+= -lm -pthread
BIN 				:= $(BIN_DIR)/$(PROJECT)
COMPILE				= $(CC) $(CFLAGS) $(INC) $(DEFINES)
# Automatically include all source files
SRCS 				:= $(shell find $(SRC_DIR) -type f -name '*.c' -not -path '*/\.*')
OBJECTS    			:= $(patsubst $(SRC_DIR)%,$(BUILD_DIR)/%,$(SRCS:.$(SRC_EXT)=.$(OBJ_EXT)))

all: default

$(BUILD_DIR)/%.$(OBJ_EXT): $(SRC_DIR)/%.$(SRC_EXT)
	@echo 'Building project file: $<'
	@mkdir -p $(dir $@)
	@$(COMPILE) -c -o "$@" "$<"

default: $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CC) -o $(BIN) $(OBJECTS) $(LDFLAGS) ${LDLIBS}

clean:
	rm -rf $(WORKING_DIR)

install: ${BIN}
	install -d ${DESTDIR}/usr/lib/${PROJECT}/bin
	install $< ${DESTDIR}/usr/lib/${PROJECT}/bin/
