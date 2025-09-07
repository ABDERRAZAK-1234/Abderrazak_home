#include <stdio.h>

float moyenneEtudiant(float notes[30][3], int i){
    float somme=0;
    for (int j = 0; j < 3; j++) {
        somme += notes[i][j];
    }
    return somme / 3;
}

float moyenneMatiere(float notes[30][3], int j, int nbr_etudiants){
    float somme=0;
    for (int i = 0; i < nbr_etudiants; i++) {
        somme += notes[i][j];
    }
    return somme / nbr_etudiants;
}

int meilleurEtudiant(float notes[30][3], int nbr_etudiants){
    int meilleur=0;
    float meilleureMoy=moyenneEtudiant(notes,0);
    for (int i = 1; i < nbr_etudiants; i++) {
        float moy=moyenneEtudiant(notes,i);
        if (moy>meilleureMoy){
            meilleureMoy=moy;
            meilleur=i;
        }
    }
    return meilleur;
}

int main() {
    float notes[30][3];
    int nbr_etudiants = 0;
    int choix;
    int i,j;

    do {
        printf("\n-------- MENU --------\n");
        printf("1. Saisir les notes\n");
        printf("2. Afficher les moyennes\n");
        printf("3. Afficher le meilleur étudiant\n");
        printf("4. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                do {
                    printf("Saisir nombre d'etudiants (max 30) : ");
                    scanf("%d", &nbr_etudiants);
                    if(nbr_etudiants <1 || nbr_etudiants>30)
                        printf("Erreur, nombre d'etudiants doit etre entre 1 et 30!\n");
                } while(nbr_etudiants <1 || nbr_etudiants>30);

                for(i=0;i<nbr_etudiants;i++){
                    for(j=0;j<3;j++){
                        char* matiere = (j==0) ? "Mathematique" : (j==1) ? "Informatique" : "Physique";
                        do {
                            printf("Saisir la note de %s de l'etudiant %d : ", matiere, i+1);
                            scanf("%f", &notes[i][j]);
                            if(notes[i][j]<0 || notes[i][j]>20)
                                printf("Erreur, la note doit etre entre 0 et 20!\n");
                        } while(notes[i][j]<0 || notes[i][j]>20);
                    }
                }
                break;

            case 2:
                for(i=0;i<nbr_etudiants;i++){
                    printf("Moyenne de l'etudiant %d = %.2f\n", i+1, moyenneEtudiant(notes,i));
                }
                for(j=0;j<3;j++){
                    printf("Moyenne de la matiere %d = %.2f\n", j+1, moyenneMatiere(notes,j,nbr_etudiants));
                }
                break;

            case 3:
                if(nbr_etudiants == 0){
                    printf("Veuillez saisir les notes d'abord!\n");
                } else {
                    int mei = meilleurEtudiant(notes, nbr_etudiants);
                    printf("Le meilleur etudiant est numero %d avec une moyenne de %.2f\n", mei+1, moyenneEtudiant(notes, mei));
                }
                break;

            case 4:
                printf("Au revoir !\n");
                break;

            default:
                printf("Choix invalide!\n");
        }

    } while(choix != 4);

    return 0;
}
