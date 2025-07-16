
# define platform
flags += -DLINUX

# create bin
bin:
	@mkdir -p $(bin_path)

# set in envirment variable
set:
	@export PATH=$(bin_path)/$(project)
