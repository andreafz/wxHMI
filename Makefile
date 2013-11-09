.PHONY: clean All

All:
	@echo "----------Building project:[ wxHMI - Debug ]----------"
	@cd "wxHMI" && $(MAKE) -f  "wxHMI.mk"
clean:
	@echo "----------Cleaning project:[ wxHMI - Debug ]----------"
	@cd "wxHMI" && $(MAKE) -f  "wxHMI.mk" clean
