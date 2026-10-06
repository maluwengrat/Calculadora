#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

typedef struct {
    float numero1;
    float numero2;
    float resultado;
    char operacao[20];
} Operacao;

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

void adicionarHistorico(Operacao **historico, int *quantidade,
                        float numero1, float numero2,
                        float resultado, char operacao[]) {

    Operacao *temp;

    temp = realloc(*historico, (*quantidade + 1) * sizeof(Operacao));

    if (temp == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }

    *historico = temp;

    (*historico)[*quantidade].numero1 = numero1;
    (*historico)[*quantidade].numero2 = numero2;
    (*historico)[*quantidade].resultado = resultado;

    snprintf((*historico)[*quantidade].operacao,
             sizeof((*historico)[*quantidade].operacao),
             "%s", operacao);

    (*quantidade)++;
}

void soma(Operacao **historico, int *quantidade) {

    float a, b, resultado;

    printf("\n--- SOMA ---\n");
    printf("Digite o primeiro número: ");
    scanf("%f", &a);

    printf("Digite o segundo número: ");
    scanf("%f", &b);

    resultado = a + b;

    printf("Resultado: %.2f\n\n", resultado);

    adicionarHistorico(historico, quantidade,
                       a, b, resultado, "Soma");
}

void subtracao(Operacao **historico, int *quantidade) {

    float a, b, resultado;

    printf("\n--- SUBTRAÇÃO ---\n");
    printf("Digite o primeiro número: ");
    scanf("%f", &a);

    printf("Digite o segundo número: ");
    scanf("%f", &b);

    resultado = a - b;

    printf("Resultado: %.2f\n\n", resultado);

    adicionarHistorico(historico, quantidade,
                       a, b, resultado, "Subtração");
}

void multiplicacao(Operacao **historico, int *quantidade) {

    float a, b, resultado;

    printf("\n--- MULTIPLICAÇÃO ---\n");
    printf("Digite o primeiro número: ");
    scanf("%f", &a);

    printf("Digite o segundo número: ");
    scanf("%f", &b);

    resultado = a * b;

    printf("Resultado: %.2f\n\n", resultado);

    adicionarHistorico(historico, quantidade,
                       a, b, resultado, "Multiplicação");
}

void divisao(Operacao **historico, int *quantidade) {

    float a, b, resultado;

    printf("\n--- DIVISÃO ---\n");
    printf("Digite o primeiro número: ");
    scanf("%f", &a);

    printf("Digite o segundo número: ");
    scanf("%f", &b);

    if (b == 0) {
        printf("Não é possível dividir por zero.\n\n");
        return;
    }

    resultado = a / b;

    printf("Resultado: %.2f\n\n", resultado);

    adicionarHistorico(historico, quantidade,
                       a, b, resultado, "Divisão");
}

void exponenciacao(Operacao **historico, int *quantidade) {

    float a, b, resultado;

    printf("\n--- EXPONENCIAÇÃO ---\n");
    printf("Digite a base: ");
    scanf("%f", &a);

    printf("Digite o expoente: ");
    scanf("%f", &b);

    resultado = pow(a, b);

    printf("Resultado: %.2f\n\n", resultado);

    adicionarHistorico(historico, quantidade,
                       a, b, resultado, "Exponenciação");
}

void raizQuadrada(Operacao **historico, int *quantidade) {

    float numero, resultado;

    printf("\n--- RAIZ QUADRADA ---\n");
    printf("Digite um número: ");
    scanf("%f", &numero);

    if (numero < 0) {
        printf("Não é possível calcular raiz de número negativo.\n\n");
        return;
    }

    resultado = sqrt(numero);

    printf("Resultado: %.2f\n\n", resultado);

    adicionarHistorico(historico, quantidade,
                       numero, 0, resultado, "Raiz quadrada");
}

void somaDeNValores(Operacao **historico, int *quantidade) {

    int n, i;
    float *valores;
    float soma = 0;

    printf("\n--- SOMA DE N VALORES ---\n");
    printf("Quantos valores deseja somar? ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Quantidade inválida.\n\n");
        return;
    }

    valores = calloc(n, sizeof(float));

    if (valores == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }

    for (i = 0; i < n; i++) {
        printf("Digite o %dº valor: ", i + 1);
        scanf("%f", &valores[i]);

        soma += valores[i];
    }

    printf("Resultado: %.2f\n\n", soma);

    adicionarHistorico(historico, quantidade,
                       n, 0, soma, "Soma de N valores");

    free(valores);
}

void calculoDeSequenciaDeFibonacci(void) {

    int n, i;
    int *fibonacci;

    printf("\n--- FIBONACCI ---\n");
    printf("Quantos termos deseja visualizar? ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Quantidade inválida.\n\n");
        return;
    }

    fibonacci = malloc(n * sizeof(int));

    if (fibonacci == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }

    fibonacci[0] = 0;

    if (n > 1) {
        fibonacci[1] = 1;
    }

    for (i = 2; i < n; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }

    printf("Sequência: ");

    for (i = 0; i < n; i++) {
        printf("%d ", fibonacci[i]);
    }

    printf("\n\n");

    free(fibonacci);
}

void areaDoCirculo(Operacao **historico, int *quantidade) {

    float raio, resultado;

    printf("\n--- ÁREA DO CÍRCULO ---\n");
    printf("Digite o raio: ");
    scanf("%f", &raio);

    resultado = 3.14159 * raio * raio;

    printf("Área: %.2f\n\n", resultado);

    adicionarHistorico(historico, quantidade,
                       raio, 0, resultado, "Área do círculo");
}

void areaDoRetangulo(Operacao **historico, int *quantidade) {

    float base, altura, resultado;

    printf("\n--- ÁREA DO RETÂNGULO ---\n");
    printf("Digite a base: ");
    scanf("%f", &base);

    printf("Digite a altura: ");
    scanf("%f", &altura);

    resultado = base * altura;

    printf("Área: %.2f\n\n", resultado);

    adicionarHistorico(historico, quantidade,
                       base, altura, resultado, "Área do retângulo");
}

void volumeDoCubo(Operacao **historico, int *quantidade) {

    float lado, resultado;

    printf("\n--- VOLUME DO CUBO ---\n");
    printf("Digite o lado: ");
    scanf("%f", &lado);

    resultado = lado * lado * lado;

    printf("Volume: %.2f\n\n", resultado);

    adicionarHistorico(historico, quantidade,
                       lado, 0, resultado, "Volume do cubo");
}

void volumeDoCilindro(Operacao **historico, int *quantidade) {

    float raio, altura, resultado;

    printf("\n--- VOLUME DO CILINDRO ---\n");
    printf("Digite o raio: ");
    scanf("%f", &raio);

    printf("Digite a altura: ");
    scanf("%f", &altura);

    resultado = 3.14159 * raio * raio * altura;

    printf("Volume: %.2f\n\n", resultado);

    adicionarHistorico(historico, quantidade,
                       raio, altura, resultado, "Volume do cilindro");
}

void salvarHistorico(Operacao *historico, int quantidade) {

    FILE *arquivo;
    int i;

    arquivo = fopen("historico.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    for (i = 0; i < quantidade; i++) {
        fprintf(arquivo,
                "%s: %.2f %.2f = %.2f\n",
                historico[i].operacao,
                historico[i].numero1,
                historico[i].numero2,
                historico[i].resultado);
    }

    fclose(arquivo);
}

void visualizarHistorico(void) {

    FILE *arquivo;
    char linha[150];

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
    Operacao *historico = NULL;
    int quantidade = 0;

    do {

        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                soma(&historico, &quantidade);
                break;

            case 2:
                subtracao(&historico, &quantidade);
                break;

            case 3:
                multiplicacao(&historico, &quantidade);
                break;

            case 4:
                divisao(&historico, &quantidade);
                break;

            case 5:
                exponenciacao(&historico, &quantidade);
                break;

            case 6:
                raizQuadrada(&historico, &quantidade);
                break;

            case 7:
                somaDeNValores(&historico, &quantidade);
                break;

            case 8:
                calculoDeSequenciaDeFibonacci();
                break;

            case 9:
                areaDoCirculo(&historico, &quantidade);
                break;

            case 10:
                areaDoRetangulo(&historico, &quantidade);
                break;

            case 11:
                volumeDoCubo(&historico, &quantidade);
                break;

            case 12:
                volumeDoCilindro(&historico, &quantidade);
                break;

            case 13:
                salvarHistorico(historico, quantidade);
                visualizarHistorico();
                break;

            case 0:
                salvarHistorico(historico, quantidade);
                printf("\nSaindo do programa...\n");
                break;

            default:
                printf("\nOpção inválida! Tente novamente.\n\n");
                break;
        }

    } while (opcao != 0);

    free(historico);

    return 0;
}
