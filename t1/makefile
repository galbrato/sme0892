all:
	@gcc -o newton_exec newton.c
	@./newton_exec
	@gcc -o secantes_exec secantes.c
	@./secantes_exec

newton:
	@gcc -o newton_exec newton.c
	@./newton_exec
	@nano newton_saida[-2.0_0.0].dat
	@nano newton_saida[0.0_2.0].dat
secantes:
	@gcc -o secantes_exec secantes.c
	@./secantes_exec
	@nano secantes_saida[-2.0_0.0].dat
	@nano secantes_saida[0.0_2.0].dat
bissecao:
	@gcc -o bissecao_exec bissecao.c
	@./bissecao_exec
	@nano bissecao_saida[-2.0_0.0].dat
	@nano bissecao_saida[0.0_2.0].dat

clear:
	@rm *saida*
	@rm *_exec
