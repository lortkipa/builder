
# define platform
flags += -DLINUX

# create bin
bin:
	@mkdir -p $(bin_path)

ifeq ($(config), debug)
demo_run:
	@cd $(demo_path) && export PATH=$(abspath $(bin_path)):$$PATH && gdb $(project)
else
demo_run:
	@cd $(demo_path) && export PATH=$(abspath $(bin_path)):$$PATH && $(project)
endif
