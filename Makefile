DEFAULT_GOAL: dbg

FINDGOAL=$(findstring $(1),$(MAKECMDGOALS))
LDFLAGS	:=$(LDFLAGS)
CFLAGS	:=$(CFLAGS)

ifeq ($(call FINDGOAL,rel),rel)
	BINDIR	:=bin/rel
	CFLAGS	:=$(CFLAGS) -O2 -NDEBUG
	LDFLAGS	:=$(LDFLAGS) -lm
else
	BINDIR	:=bin/dbg
	CFLAGS	:=$(CFLAGS) -O0 -g
	LDFLAGS	:=$(LDFLAGS) -lm
endif

SRCS	:=$(shell find src -type f -name "*.c")
GETOBJS	=$(patsubst %.c,$(BINDIR)/%.o,$(filter %.c,$(1)))
OBJS	:=$(call GETOBJS,$(SRCS))
TARGET	:=test

dbg: $(BINDIR)/$(TARGET)
rel: $(BINDIR)/$(TARGET)

$(BINDIR)/$(TARGET): $(OBJS)
	mkdir -p $(dir $@)
	$(CC) $^ -o $@ $(LDFLAGS) $(LDFLAGS_LIB)
run: $(BINDIR)/$(TARGET)
	$<
gdb: $(BINDIR)/$(TARGET)
	gdb $<
lldb: $(BINDIR)/$(TARGET)
	lldb $<

# $(1) source file
define MAKEOBJ
$(BINDIR)/$(dir $(1))$(shell gcc -M $(1) | tr -d '\\\n')
	mkdir -p $$(dir $$@)
	$(CC) -c $$< -o $$@ $(CFLAGS) $(CFLAGS_LIB)
endef

$(foreach src,$(SRCS),$(eval $(call MAKEOBJ,$(src))))

.PHONY: clean
clean:
	rm -rf bin/
