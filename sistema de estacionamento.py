import random
nome = input("Digite o seu nome: ")
print(f"\nOlá {nome}! Seja bem-vindo ao nosso estacionamento.")
print(f"Nosso estacionamento, o valor cobrado é de R$ 8,00 por hora. O tempo máximo permitido é de 12 horas.")
print(f"\nPara prosseguir, digite os dados do seu carro e o tempo de estacionamento")
prosseguir = input("Deseja prosseguir? (S/N): ").lower()
if prosseguir == "S" or prosseguir == "s":
    print(f"\nÓtimo, vamos prosseguir com o cadastro do seu carro.")
else:
    print(f"\nObrigado por utilizar nosso estacionamento, {nome}.")
    exit()
cpf = input("Digite o seu CPF(000.000.000-00): ")
modelo = input("Digite o modelo do seu carro: ")
placa = input("Digite a placa do seu carro(ABC-1234): ")
tempo = int(input("Digite o tempo de estacionamento em horas: "))
preco = tempo*8

estacionamento = random.randint(1, 100)
print(f"\n -modelo do seu carro: {modelo}.")
print(f" -Número da placa: {placa}.")
print(f" -Número da Vaga: {estacionamento}.")
print(f"\nO tempo de estacionamento é de {tempo} horas.")
print(f"\nO valor total a ser pago é de R$ {preco},00. Obrigado por utilizar nosso estacionamento, {nome}.")






