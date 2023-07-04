CC := g++
SRCDIR := src
TSTDIR := tests
OBJDIR := build
BINDIR := bin
COVDIR := coverage

MAIN := program/main.cpp
TESTER := program/tester.cpp

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
TSTSOURCES := $(shell find $(TSTDIR) -type f -name *.$(SRCEXT))

# -g debug, --coverage cobertura
CFLAGS := -Wall -std=c++17
LDFLAGS := -lgcov
INC := -I include/ -I third_party/

$(OBJDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $< -coverage

main: $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $(INC) $(MAIN) $^ -o $(BINDIR)/main -coverage $(LDFLAGS)

tests: $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $(INC) $(TESTER) $(TSTSOURCES) $^ -o $(BINDIR)/tester $(LDFLAGS)
	$(BINDIR)/tester

coverage: tests
	@mkdir -p $(COVDIR)
	gcov $(OBJECTS) --object-directory $(OBJDIR) --output-directory $(COVDIR)

# all: main

clean:
	$(RM) -r $(OBJDIR)/* $(BINDIR)/* $(COVDIR)/* *.gcda *.gcno

.PHONY: clean