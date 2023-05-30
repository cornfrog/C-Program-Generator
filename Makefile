all:
	@gcc program-gen.c -o program-gen
	@mv program-gen bin/
	@echo MAKE Success: use \'make run\' to run

run:
	@./bin/program-gen

clean:
	@rm bin/program-gen
	@echo MAKE Clean: use \'make\' to get program back
