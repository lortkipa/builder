
# paths
bin_path := ../bin
src_path := ../src
demo_path := ../demo

# general settings
project := builder
compiler := clang
srcs := $(wildcard $(src_path)/*.c) $(wildcard $(src_path)/*/*.c) $(wildcard $(src_path)/*/*/*.c)
libraries :=
flags := -std=c23 -I$(src_path)

# config specific settings
ifeq ($(config), debug)
	flags += -DDEBUG -O0 -g -Wall -Wextra
else ifeq ($(config), dev)
	flags += -DDEV -O3 -ffast-math -Wall -Wextra
else 
	flags += -DSHIP -O3 -ffast-math
endif

# include platform specific settings
run_cmd := ./$(project)
ifeq ($(OS), Windows_NT)
	include windows.mk
else
	include linux.mk
endif

# build scripts
.PHONY: bin build set demo_run all

all: bin build set demo_run

build:
	$(compiler) $(flags) $(srcs) $(libraries) -o $(bin_path)/$(project)
