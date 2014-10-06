CODE_DIR = wanderer
GRADE_DIR = grader

all: project_code
.PHONY: project_code
.PHONY: grader

project_code:
	$(MAKE) -C $(CODE_DIR)

grader:
	$(MAKE) -C $(GRADE_DIR)

clean:
	$(MAKE) -C $(CODE_DIR) clean
	rm -rf $(CODE_DIR)/bin

