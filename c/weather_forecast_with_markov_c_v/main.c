#include <stdio.h>
#include <stdlib.h>
void probablities(float arr[])
{
    char input[100];
    fgets(input, sizeof(input), stdin);
    sscanf(input, " %f , %f , %f ", &arr[0], &arr[1], &arr[2]);
}

void matris_carpim(float matris[3][3], float olasılıklar[3])
{
    float yeni_olasılıklar[3] = {0.0, 0.0, 0.0};
    for (int i = 0; i < 3; i++)
    {
        float toplam = 0;
        for (int j = 0; j < 3; j++)
        {
            toplam += matris[j][i] * olasılıklar[j];
        }
        yeni_olasılıklar[i] = toplam;
    }
    printf("new possibilities: %.2f, %.2f, %.2f\n", yeni_olasılıklar[0], yeni_olasılıklar[1], yeni_olasılıklar[2]);
}

int main()
{
    float array[3] = {0.0f, 0.0f, 0.0f};
    printf("Please enter the initial probabilities separated by commas, for example (0.3, 0.1, 0.6).");
    probablities(array);
    printf("you entered %.1f , %.1f , %.1f\n", array[0], array[1], array[2]);

    float matris[3][3] = {
        {0.2, 0.3, 0.5},
        {0.4, 0.5, 0.1},
        {0.3, 0.4, 0.3}};
    matris_carpim(matris, array);

    return 0;
}