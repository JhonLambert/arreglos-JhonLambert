#include <stdio.h>
#include <string.h>

int main() {
    char estudiantes[5][30];
    char asignaturas[3][30];
    float notas[5][3] = {{0}};
    float promedioEstudiante[5];
    float promedioAsignatura[3];
    float maxEstudiante[5], minEstudiante[5];
    float maxAsignatura[3], minAsignatura[3];
    int aprobados[3], reprobados[3];
    int nombresIngresados = 0, materiasIngresadas = 0, notasIngresadas = 0;

    int opcion;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Ingresar nombres de estudiantes\n");
        printf("2. Ingresar nombres de asignaturas\n");
        printf("3. Ingresar notas de estudiantes\n");
        printf("4. Ver tabla de notas\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        fflush(stdin);

        switch(opcion) {
            case 1:
                for (int i = 0; i < 5; i++) {
                    printf("Ingrese el nombre del estudiante #%d: ", i + 1);
                    fgets(estudiantes[i], 30, stdin);
                    estudiantes[i][strcspn(estudiantes[i], "\n")] = '\0';
                }
                nombresIngresados = 1;
                break;

            case 2:
                for (int j = 0; j < 3; j++) {
                    printf("Ingrese el nombre de la asignatura #%d: ", j + 1);
                    fgets(asignaturas[j], 30, stdin);
                    asignaturas[j][strcspn(asignaturas[j], "\n")] = '\0';
                }
                materiasIngresadas = 1;
                break;

            case 3:
                if (!nombresIngresados || !materiasIngresadas) {
                    printf("Debe ingresar primero los nombres de estudiantes y asignaturas.\n");
                    break;
                }

                for (int i = 0; i < 5; i++) {
                    printf("\nEstudiante: %s\n", estudiantes[i]);
                    for (int j = 0; j < 3; j++) {
                        do {
                            printf("Ingrese nota para %s en %s (0-10): ", estudiantes[i], asignaturas[j]);
                            scanf("%f", &notas[i][j]);
                            if (notas[i][j] < 0 || notas[i][j] > 10)
                                printf("Nota invalida. Intente nuevamente.\n");
                        } while (notas[i][j] < 0 || notas[i][j] > 10);
                    }
                }
                notasIngresadas = 1;
                break;

            case 4:
                if (!notasIngresadas) {
                    printf("Primero debe ingresar las notas.\n");
                    break;
                }

            
                for (int i = 0; i < 5; i++) {
                    maxEstudiante[i] = 0;
                    minEstudiante[i] = 10;
                }
                for (int j = 0; j < 3; j++) {
                    promedioAsignatura[j] = 0;
                    maxAsignatura[j] = 0;
                    minAsignatura[j] = 10;
                    aprobados[j] = 0;
                    reprobados[j] = 0;
                }

                for (int i = 0; i < 5; i++) {
                    float suma = 0;
                    for (int j = 0; j < 3; j++) {
                        float nota = notas[i][j];
                        suma += nota;

                        if (nota > maxEstudiante[i]) maxEstudiante[i] = nota;
                        if (nota < minEstudiante[i]) minEstudiante[i] = nota;

                        promedioAsignatura[j] += nota;

                        if (nota > maxAsignatura[j]) maxAsignatura[j] = nota;
                        if (nota < minAsignatura[j]) minAsignatura[j] = nota;

                        if (nota >= 6) aprobados[j]++;
                        else reprobados[j]++;
                    }
                    promedioEstudiante[i] = suma / 3.0;
                }

                printf("\npromedio por estudiante\n");
                for (int i = 0; i < 5; i++) {
                    printf("%s: %.2f (Max: %.2f, Min: %.2f)\n", estudiantes[i], promedioEstudiante[i], maxEstudiante[i], minEstudiante[i]);
                }

                printf("\npromedio por asignatura\n");
                for (int j = 0; j < 3; j++) {
                    float promedio = promedioAsignatura[j] / 5.0;
                    printf("%s: %.2f (Max: %.2f, Min: %.2f)\n", asignaturas[j], promedio, maxAsignatura[j], minAsignatura[j]);
                }

                printf("\naprobados y reprobados por asignatura \n");
                for (int j = 0; j < 3; j++) {
                    printf("%s: Aprobados: %d | Reprobados: %d\n", asignaturas[j], aprobados[j], reprobados[j]);
                }
                break;

            case 5:
                printf("gracias por usar el programa\n");
                break;

            default:
                printf("Opcion invalida. Intente nuevamente.\n");
        }

    } while(opcion != 5);

    return 0;
}
