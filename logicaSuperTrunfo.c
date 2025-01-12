#include <stdio.h>
#include <string.h> // Importação para usar a função strcspn

float cadastrarNovaCarta(
    char *estado, 
    char *codigoDaCarta, 
    char *nomeDaCidade, 
    int *populacao, 
    int *pontosTuristicos,
    float *PIB,
    float *areaEmKM,
    float *densidadePopulacional
) {
    float PibPerCapita = 0;
    printf("============ Cadastrando Nova Carta ===========\n");

    printf("Digite a sigla do estado: ");
    scanf("%s", estado);
    getchar(); // Limpa o caractere de nova linha do buffer

    printf("Digite o código da carta: ");
    scanf("%s", codigoDaCarta);
    getchar(); // Limpa o caractere de nova linha do buffer

    printf("Digite o nome da cidade: ");
    fgets(nomeDaCidade, 100, stdin);
    nomeDaCidade[strcspn(nomeDaCidade, "\n")] = '\0'; // Remove o caractere de nova linha

    printf("Digite o número de habitantes da cidade: ");
    scanf("%d", populacao);

    printf("Digite a área total da cidade em km²: ");
    scanf("%f", areaEmKM);

    printf("Digite a quantidade de pontos turísticos: ");
    scanf("%d", pontosTuristicos);

    printf("Digite o PIB da cidade: ");
    scanf("%f", PIB);

    printf("\n ***** Carta cadastrada com sucesso ***** \n");

    // Calculo do PIB per capita: divide o PIB pela População
    PibPerCapita = *PIB / *populacao;

    // Calculo da Densidade Populacional: População dividida pelo Território em km²
    *densidadePopulacional = *populacao / *areaEmKM;

    return PibPerCapita;
}

void verificarCartaVencedora(float PibPerCapitaA, float PibPerCapitaB) {
    if (PibPerCapitaA > PibPerCapitaB) {
        printf("Resultado: Carta 1 é a vencedora! \n");
    } else {
        printf("Resultado: Carta 2 é a vencedora! \n");
    }
}

void exibirDadosDaCartaCadastrada(
    char *estado,
    char *codigoDaCarta,
    char *nomeDaCidade,
    int pontosTuristicos, 
    int populacao,
    float areaEmKM,
    float PIB,
    float PibPerCapita,
    float densidadePopulacional
) {
    printf("Estado: %s\n", estado);
    printf("Código: %s\n", codigoDaCarta);
    printf("Cidade: %s\n", nomeDaCidade);
    printf("Pontos Turísticos: %d\n", pontosTuristicos);
    printf("População: %d\n", populacao);
    printf("Área: %.0f\n", areaEmKM);
    printf("PIB: %.0f\n", PIB);
    printf("PIB per Capita: %.1f\n", PibPerCapita);
    printf("Densidade Populacional: %f\n", densidadePopulacional);
}

int main() {
    // Dados da carta 1
    char estadoA[3], codigoDaCartaA[5], nomeDaCidadeA[100];
    int populacaoA, pontosTuristicosA;
    float PIBA, PibPerCapitaA, areaEmKMA, densidadePopulacionalA;

    // Dados da carta 2
    char estadoB[3], codigoDaCartaB[5], nomeDaCidadeB[100];
    int populacaoB, pontosTuristicosB;
    float PIBB, PibPerCapitaB, areaEmKMB, densidadePopulacionalB;
    
    printf("============ Bem-vindo ao jogo Super Trunfo ===========\n");
    PibPerCapitaA = cadastrarNovaCarta(estadoA, codigoDaCartaA, nomeDaCidadeA, &populacaoA, &pontosTuristicosA, &PIBA, &areaEmKMA, &densidadePopulacionalA);
    PibPerCapitaB = cadastrarNovaCarta(estadoB, codigoDaCartaB, nomeDaCidadeB, &populacaoB, &pontosTuristicosB, &PIBB, &areaEmKMB, &densidadePopulacionalB);

    printf("============= Esses são os dados da carta 1 ============ \n");
    exibirDadosDaCartaCadastrada(estadoA, codigoDaCartaA, nomeDaCidadeA, pontosTuristicosA, populacaoA, areaEmKMA, PIBA, PibPerCapitaA, densidadePopulacionalA);

    printf("============= Esses são os dados da carta 2 ============ \n");
    exibirDadosDaCartaCadastrada(estadoB, codigoDaCartaB, nomeDaCidadeB, pontosTuristicosB, populacaoB, areaEmKMB, PIBB, PibPerCapitaB, densidadePopulacionalB);

    printf("============ Exibir Resultados ============");

    printf("\nComparação de cartas \n");
    printf("Carta 1 - Estado: %s, Código: %s, População: %d, PIB per Capita: %.1f \n", estadoA, codigoDaCartaA, populacaoA, PibPerCapitaA);
    printf("Carta 2 - Estado: %s, Código: %s, População: %d, PIB per Capita: %.1f \n", estadoB, codigoDaCartaB, populacaoB, PibPerCapitaB);
    
    verificarCartaVencedora(PibPerCapitaA, PibPerCapitaB);

    return 0;
}
