import random

opcoes = ("pedra", "papel", "tesoura")
jogador = input("Escolha pedra, papel ou tesoura? ").lower()
computador = random.choice(opcoes)

if jogador == computador:
    resultado = "Empate!"
elif (
    (jogador == "pedra" and computador == "tesoura") 
    or (jogador == "papel" and computador == "pedra")
    or (jogador == "tesoura" and computador == "papel")
):
    resultado = "Você ganhou!"
else:
    resultado = "Você perdeu!"

print(f"Python escolheu: {computador}")
print(resultado)
 
