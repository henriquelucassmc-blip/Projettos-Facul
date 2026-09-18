import java.util.Scanner;

public class sistemaEstacionamento {

    static Scanner scanner = new Scanner(System.in);

    static String nomeCadastro = "";
    static String cpfCadastro = "";
    static String modeloCadastro = "";
    static String placaCadastro = "";

    static int tempoCadastro = 0;
    static double precoTotal = 0;

    static int totalVagas = 1000;
    static int vagasOcupadas = 0;

    public static void main(String[] args) throws InterruptedException {

        System.out.print("Olá, seja bem-vindo! Informe seu nome completo: ");
        nomeCadastro = scanner.nextLine();

        System.out.println(
                "\nO nosso estacionamento cobra R$6,00 por hora, com limite de 12 horas."
        );

        System.out.print("Deseja prosseguir para o nosso sistema? (S/N): ");
        String situacao = scanner.nextLine();

        if (situacao.equalsIgnoreCase("S")) {

            System.out.println(
                    "\nVamos prosseguir com o atendimento!"
            );

            menu();

        } else {

            System.out.println(
                    "Atendimento encerrado. Tenha um ótimo dia!"
            );
        }

        scanner.close();
    }


    static void menu() throws InterruptedException {

        int opcao;

        do {

            System.out.println("\n<------ Sistema do Estacionamento ------>\n");

            System.out.println("1 -> Iniciar cadastro");
            System.out.println("2 -> Realizar pagamento");
            System.out.println("3 -> Imprimir nota fiscal");
            System.out.println("4 -> Verificar vagas disponíveis");
            System.out.println("5 -> Sair");

            System.out.print("\nEscolha uma opção: ");

            opcao = scanner.nextInt();
            scanner.nextLine(); // limpa o ENTER do teclado


            switch (opcao) {

                case 1:

                    System.out.print("\nIniciando cadastro");

                    for (int i = 0; i < 3; i++) {

                        System.out.print(".");
                        Thread.sleep(1000);

                    }

                    System.out.println("\n\nCadastro iniciado com sucesso!\n");


                    // Verifica se existem vagas

                    if (vagasOcupadas >= totalVagas) {

                        System.out.println("Estacionamento lotado!");
                        break;

                    }


                    System.out.print("Digite seu CPF (XXX.XXX.XXX-XX): ");
                    cpfCadastro = scanner.nextLine();


                    System.out.print("Qual o modelo do seu carro? ");
                    modeloCadastro = scanner.nextLine();


                    System.out.print("Digite o número da placa (AAA1234): ");
                    placaCadastro = scanner.nextLine();


                    System.out.print(
                            "Por quanto tempo utilizará o estacionamento? (Máximo 12h): "
                    );

                    tempoCadastro = scanner.nextInt();
                    scanner.nextLine();


                    // Validação do tempo

                    if (tempoCadastro <= 0 || tempoCadastro > 12) {

                        System.out.println(
                                "\nTempo inválido! O limite é de 12 horas."
                        );

                        tempoCadastro = 0;
                        precoTotal = 0;

                    } else {

                        precoTotal = tempoCadastro * 6;

                        vagasOcupadas++;

                        System.out.println(
                                "\nCadastro realizado com sucesso!"
                        );

                        System.out.println(
                                "Uma vaga foi ocupada."
                        );
                    }

                    break;


                case 2:

                    if (precoTotal == 0) {

                        System.out.println(
                                "\nPrimeiro realize o cadastro do veículo!"
                        );

                        break;
                    }


                    System.out.printf(
                            "\nO preço total do estacionamento ficará em: R$ %.2f%n",
                            precoTotal
                    );


                    System.out.print(
                            "Qual a forma de pagamento? (Dinheiro/PIX/Cartão): "
                    );

                    String formaPagamento = scanner.nextLine();


                    if (formaPagamento.equalsIgnoreCase("Dinheiro")) {

                        System.out.println(
                                "Você escolheu pagar em dinheiro!"
                        );

                    } else if (formaPagamento.equalsIgnoreCase("PIX")) {

                        System.out.println(
                                "Você escolheu pagar via PIX!"
                        );

                    } else if (
                            formaPagamento.equalsIgnoreCase("Cartão") ||
                            formaPagamento.equalsIgnoreCase("Cartao")
                    ) {

                        System.out.println(
                                "Você escolheu pagar com cartão!"
                        );

                    } else {

                        System.out.println(
                                "Forma de pagamento inválida!"
                        );

                        break;
                    }


                    System.out.print(
                            "Deseja realizar o pagamento? (S/N): "
                    );

                    String pagamento = scanner.nextLine();


                    if (pagamento.equalsIgnoreCase("S")) {

                        System.out.println(
                                "Pagamento realizado com sucesso!"
                        );

                    } else {

                        System.out.println(
                                "Pagamento não realizado!"
                        );
                    }

                    break;


                case 3:

                    if (cpfCadastro.isEmpty()) {

                        System.out.println(
                                "\nNenhum cadastro foi realizado!"
                        );

                        break;
                    }


                    System.out.println("\n<------ NOTA FISCAL ------>\n");

                    System.out.println("NOME: " + nomeCadastro);

                    System.out.println("CPF: " + cpfCadastro);

                    System.out.println("MODELO DO CARRO: " + modeloCadastro);

                    System.out.println("PLACA: " + placaCadastro);

                    System.out.println("TEMPO: " + tempoCadastro + " hora(s)");

                    System.out.println("\n===========================");

                    System.out.printf(
                            "TOTAL A PAGAR = R$ %.2f%n",
                            precoTotal
                    );

                    System.out.println("===========================");

                    break;


                case 4:

                    int vagasDisponiveis = totalVagas - vagasOcupadas;

                    System.out.println(
                            "\n<------ VAGAS ------>"
                    );

                    System.out.println(
                            "Total de vagas: " + totalVagas
                    );

                    System.out.println(
                            "Vagas ocupadas: " + vagasOcupadas
                    );

                    System.out.println(
                            "Vagas disponíveis: " + vagasDisponiveis
                    );


                    if (vagasDisponiveis == 0) {

                        System.out.println(
                                "\nESTACIONAMENTO LOTADO!"
                        );

                    } else if (vagasDisponiveis <= 5) {

                        System.out.println(
                                "\nATENÇÃO: poucas vagas disponíveis!"
                        );

                    } else {

                        System.out.println(
                                "\nHá vagas disponíveis!"
                        );
                    }

                    break;


                case 5:

                    System.out.println(
                            "\nSaindo do sistema. Tenha um ótimo dia!"
                    );

                    break;


                default:

                    System.out.println(
                            "\nOpção inválida! Escolha uma opção de 1 a 5."
                    );
            }

        } while (opcao != 5);
    }
}
