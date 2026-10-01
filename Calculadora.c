#include <stdio.h>
#include <math.h>
#include <locale.h>

void exibirMenu(void) {
    printf("=======================================\n");
    printf("              CALCULADORA              \n");
    printf("=======================================\n\n");
    printf("1. Soma\n");
    printf("2. Subtração\n");
    printf("3. Multiplicação\n");
    printf("4. Divisão\n");
    printf("5. Exponenciação\n");
    printf("6. Raiz quadrada\n");
    printf("7. Soma de n valores\n");
    printf("8. Cálculo da Sequência de Fibonacci\n");
    printf("9. Área do círculo\n");
    printf("10. Área do retângulo\n");
    printf("11. Volume do cubo\n");
    printf("12. Volume do cilindro\n");
    printf("13. Visualizar histórico\n");
    printf("0. Sair\n\n");
    printf("Escolha uma opção: ");
}

void soma(void) {
    float a, b, resultado;
    FILE *arquivo;

    printf("\n--- SOMA ---\n");
    printf("Digite o primeiro número: ");
    scanf("%f", &a);

    printf("Digite o segundo número: ");
    scanf("%f", &b);

    resultado = a + b;

    printf("Resultado: %.2f\n\n", resultado);

    arquivo = fopen("historico.txt", "a");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fprintf(arquivo, "%.2f + %.2f = %.2f\n", a, b, resultado);

    fclose(arquivo);
}

void subtracao(void) {
    float a, b, resultado;
    FILE *arquivo;

    printf("\n--- SUBTRAÇÃO ---\n");
    printf("Digite o primeiro número: ");
    scanf("%f", &a);

    printf("Digite o segundo número: ");
    scanf("%f", &b);

    resultado = a - b;

    printf("Resultado: %.2f\n\n", resultado);

    arquivo = fopen("historico.txt", "a");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fprintf(arquivo, "%.2f - %.2f = %.2f\n", a, b, resultado);

    fclose(arquivo);
}

void multiplicacao(void) {
    float a, b, resultado;
    FILE *arquivo;

    printf("\n--- MULTIPLICAÇÃO ---\n");
    printf("Digite o primeiro número: ");
    scanf("%f", &a);

    printf("Digite o segundo número: ");
    scanf("%f", &b);

    resultado = a * b;

    printf("Resultado: %.2f\n\n", resultado);

    arquivo = fopen("historico.txt", "a");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fprintf(arquivo, "%.2f * %.2f = %.2f\n", a, b, resultado);

    fclose(arquivo);
}

void divisao(void) {
    printf("\n[Em desenvolvimento: Divisão]\n\n");
}

void exponenciacao(void) {
    printf("\n[Em desenvolvimento: Exponenciação]\n\n");
}

void raizQuadrada(void) {
    printf("\n[Em desenvolvimento: Raiz quadrada]\n\n");
}

void somaDeNValores(void) {
    printf("\n[Em desenvolvimento: Soma de N valores]\n\n");
}

void calculoDeSequenciaDeFibonacci(void) {
    printf("\n[Em desenvolvimento: Fibonacci]\n\n");
}

void areaDoCirculo(void) {
    printf("\n[Em desenvolvimento: Área do Círculo]\n\n");
}

void areaDoRetangulo(void) {
    printf("\n[Em desenvolvimento: Área do Retângulo]\n\n");
}

void volumeDoCubo(void) {
    printf("\n[Em desenvolvimento: Volume do Cubo]\n\n");
}

void volumeDoCilindro(void) {
    printf("\n[Em desenvolvimento: Volume do Cilindro]\n\n");
}

void visualizarHistorico(void) {
    FILE *arquivo;
    char linha[100];

    arquivo = fopen("historico.txt", "r");

    if (arquivo == NULL) {
        printf("\nAinda não existe histórico.\n\n");
        return;
    }

    printf("\n=======================================\n");
    printf("             HISTÓRICO                 \n");
    printf("=======================================\n");

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);
    }

    printf("\n");

    fclose(arquivo);
}

int main(void) {

    setlocale(LC_ALL, "Portuguese");

    int opcao;

    do {
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                soma();
                break;

            case 2:
                subtracao();
                break;

            case 3:
                multiplicacao();
                break;

            case 4:
                divisao();
                break;

            case 5:
                exponenciacao();
                break;

            case 6:
                raizQuadrada();
                break;

            case 7:
                somaDeNValores();
                break;

            case 8:
                calculoDeSequenciaDeFibonacci();
                break;

            case 9:
                areaDoCirculo();
                break;

            case 10:
                areaDoRetangulo();
                break;

            case 11:
                volumeDoCubo();
                break;

            case 12:
                volumeDoCilindro();
                break;

            case 13:
                visualizarHistorico();
                break;

            case 0:
                printf("\nSaindo do programa...\n");
                break;

            default:
                printf("\nOpção inválida! Tente novamente.\n\n");
                break;
        }

    } while (opcao != 0);

    return 0;
}

