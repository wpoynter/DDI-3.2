EXEC = DDI_3_2
LIBNAME = libddi-3-2.a
CXXFLAGS = -c -Wall $(COMPILE)
OBJDIR = build/
OUT = bin/
LINK = -Llib/ -lticppd

rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

ifndef CXX
    CXX = g++
endif

ifndef AXX
    AXX = ar rs
endif

ifeq ($(mode),release)
	OBJDIR := $(OBJDIR)Release/
	OUT := $(OUT)Release/
else
	mode = debug
	OBJDIR := $(OBJDIR)Debug/
	OUT := $(OUT)Debug/
	CXXFLAGS += -g -DDEBUG
endif

SOURCES := $(call rwildcard,src/classes/,*.cpp)
HEADERS := $(call rwildcard,src/classes/,*.h*)
OBJECTS := $(patsubst src/classes/%,$(OBJDIR)%,$(SOURCES:.cpp=.o))
TESTSRC := $(call rwildcard,test/,*.cpp)
TESTOBJ := $(patsubst test/%,test/$(OBJDIR)%,$(TESTSRC:.cpp=.o))

build: $(OUT)$(EXEC)

all:
	@make build mode=debug
	@make build mode=release
	
$(OUT)$(EXEC): $(OBJECTS)
	@mkdir -p $(OUT)
	@echo "<<< Linking >>>"
	$(CXX) $(OBJECTS) -o $@ $(LINK)

$(OBJDIR)%.o: src/classes/%.cpp $(HEADERS)
	@mkdir -p $(dir $@)
	@echo "<<< Compiling >>> "$<
	$(CXX) $(CXXFLAGS) $< -o $@
	@echo ""
	
clean:
	@echo "<<< Cleaning >>>"
	rm -rf $(OBJDIR)
	rm -rf $(OUT)
	rm -rf test/$(OBJDIR)

static: $(OUT)$(LIBNAME) 

test: $(OUT)$(EXEC)Test

$(OBJDIR)$(LIBNAME): $(patsubst $(OBJDIR)main.o,,$(OBJECTS))
	@echo "<<< Creating Library >>>"
	@mkdir -p $(OBJDIR)
	$(AXX) $(OBJDIR)$(LIBNAME) $(patsubst $(OBJDIR)main.o,,$(OBJECTS))

test/$(OBJDIR)%.o: test/%.cpp $(HEADERS)
	@mkdir -p $(dir $@)
	@echo "<<< Compiling >>> "$<
	$(CXX) $(CXXFLAGS) $< -o $@
	@echo ""

$(OUT)$(EXEC)Test: $(OBJDIR)$(LIBNAME) $(TESTOBJ)
	@echo "<<< Linking Test >>>"
	@mkdir -p $(OUT)
	$(CXX) $(TESTOBJ) -o $@ $(LINK) $(TESTLINK) $(OBJDIR)$(LIBNAME)

clobber:
	@echo "<<< Clobbering >>>"
	rm -rf build/
	rm -rf bin/
	rm -rf test/build/