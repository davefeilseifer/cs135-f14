CODE_DIR = wanderer
all: project_code
.PHONY: project_code

project_code:
	. /opt/ros/indigo/setup.she
	$(MAKE) -C $(CODE_DIR)

clean:
	$(MAKE) -C $(CODE_DIR) clean
	rm -rf $(CODE_DIR)/bin

