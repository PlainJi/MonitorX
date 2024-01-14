#
# Makefile
# WARNING: relies on invocation setting current working directory to Makefile location
# This is done in .vscode/task.json
#

PROJECT 			?= monitorX
PLATFORM_X86		= x86
PLATFORM_T113 		= t113

ifeq ($(platform), $(PLATFORM_T113))
	TOOL_PREFIX		:= arm-linux-gnueabihf-
	DEFINES 		:= -DUSE_FBDEV=1
	CFLAGS			:= -Wl,-rpath=./lib/t113/lib
	INC_PATH 		:= -I./lib/t113/include -I./lib/t113/include/freetype2
	LD_PATH			:= -L./lib/t113/lib
	LD_LIBS			:= 
else ifeq ($(platform), $(PLATFORM_X86))
	TOOL_PREFIX		:= 
	DEFINES			:= -DUSE_SDL=1
	CFLAGS			:= -Wl,-rpath=./lib/x86/lib
	INC_PATH 		:= -I./lib/x86/include -I./lib/x86/include/freetype2
	LD_PATH			:= -L./lib/x86/lib
	LD_LIBS			:= -lSDL2
else
$(error "Usage: make platform=[x86|t113]")
endif

SRC_EXT      		:= c
OBJ_EXT				:= o
MAKEFLAGS 			:= -j $(shell nproc)

BIN					:= $(PROJECT).$(platform)
SRC_DIR				:= .
WORKING_DIR			:= ./build
BUILD_DIR			:= $(WORKING_DIR)/obj
OUTPUT_DIR			:= ./output/$(BIN)

CC					= $(TOOL_PREFIX)gcc
STRIP				= $(TOOL_PREFIX)strip
CFLAGS 				+= -std=gnu99 -O0 -g -Wall -Wshadow -Wundef -Wextra -Wno-comment \
					   -Wno-error=strict-prototypes -Wmissing-prototypes -Wno-error=missing-prototypes \
					   -Wno-unused-function -Wno-unused-parameter -Wno-unused-value -Wno-unused-variable \
					   -Wpointer-arith -fno-strict-aliasing -Wno-error=cpp -Wuninitialized -Wmaybe-uninitialized \
					   -Wno-missing-field-initializers -Wdouble-promotion -Wclobbered -Wdeprecated \
					   -Wtype-limits -Wsizeof-pointer-memaccess -Wno-format-nonliteral -Wno-cast-qual \
					   -Wunreachable-code -Wno-switch-default -Wreturn-type -Wmultichar \
					   -Wformat-security -Wno-ignored-qualifiers -Wno-error=pedantic -Wno-sign-compare \
					   -Wempty-body -Wstack-usage=8192

DEFINES				+= -DUSE_EVDEV=1 -DLV_BUILD_TEST=0 -DLV_BUILD_EXAMPLES=0
INC_PATH 			+= -I./src/ -I./src/hal/lv_drivers/ -I./src/thirdparty/ -I./src/thirdparty/lvgl/ \
						-I./src/app/ -I./src/ui/ -I./src/thirdparty/cJSON/ -I./src/thirdparty/iniparser/src/ \
						-I./src/thirdparty/thread/
LD_LIBS	 			+= -lcurl -lssl -lcrypto -lz -pthread -lfreetype
# LD_LIBS				+= -lavcodec -lavformat -lavutil -lswscale
TARGET 				:= $(OUTPUT_DIR)/$(BIN)
COMPILE				= $(CC) $(CFLAGS) $(INC_PATH) $(DEFINES)
# Automatically include all source files
SRCS 				:= $(shell find $(SRC_DIR) -type f -name '*.c' \
						-not -path './src/thirdparty/iniparser/test/*' \
						-not -path './src/thirdparty/iniparser/example/*')
OBJECTS    			:= $(patsubst $(SRC_DIR)%, $(BUILD_DIR)%, $(SRCS:.$(SRC_EXT)=.$(OBJ_EXT)))

all: default

$(BUILD_DIR)/%.$(OBJ_EXT): $(SRC_DIR)/%.$(SRC_EXT)
	@echo 'Building $<'
	@mkdir -p $(dir $@)
	@$(COMPILE) -c -o "$@" "$<"

default: $(OBJECTS)
	@mkdir -p $(OUTPUT_DIR)
	@echo 'CFLAGS $(CFLAGS)'
	@echo 'LD_PATH $(LD_PATH)'
	@echo 'LD_LIBS $(LD_LIBS)'
	@echo 'LINK $(TARGET)'
	@$(CC) -o $(TARGET) $(OBJECTS) $(CFLAGS) $(LD_PATH) ${LD_LIBS}
#	@echo 'STRIP $(BIN)'
#	@$(STRIP) $(BIN)
	@mkdir -p $(OUTPUT_DIR)/lib/$(platform)
	@cp -rf lib/$(platform)/lib/ $(OUTPUT_DIR)/lib/$(platform)/	
	@cp -rf res/ $(OUTPUT_DIR)
	@cp config.ini $(OUTPUT_DIR)
	@cd output/;tar -czf $(BIN).tar.gz $(BIN)

clean:
	rm -rf $(WORKING_DIR)
	rm -rf output

install: ${BIN}
	install -d ${DESTDIR}/usr/lib/${PROJECT}/bin
	install $< ${DESTDIR}/usr/lib/${PROJECT}/bin
