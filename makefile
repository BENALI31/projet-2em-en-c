Compilation=gcc
	
projet_final.exe :  projet_finale_sous_prog.o projet_finale_main.o
	$(Compilation) projet_finale_main.o projet_finale_sous_prog.o -o projet_final.exe
	@echo "--------------------------------------------------------- "
	@echo "--------------------------------------------------------- "
	@echo "vous pouvez lancez le programme avec la commande   ./projet_final.exe  "
	@echo "--------------------------------------------------------- "
	@echo "-----------------------------------mes salutations -----------------------------------------------  "
projet_finale_main.o : projet_finale_main.c projet_finale.h
	$(Compilation) -c projet_finale_main.c
	@echo "--------------------------------------------------------- "
	@echo "--------------------------------------------------------- "
projet_finale_sous_prog.o : projet_finale_sous_prog.c projet_finale.h

	$(Compilation) -c projet_finale_sous_prog.c
	@echo "--------------------------------------------------------- "
	@echo "--------------------------------------------------------- "
		
	

	

	
 
