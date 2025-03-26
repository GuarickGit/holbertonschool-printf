# 📚 Projet : \_printf

## 📝 Auteurs

- Claire Castan https://github.com/Helvlaska
- Kevin Fresne https://github.com/GuarickGit

---

## 📖 Sommaire

1. Introduction
2. Objectif du projet
3. Flowchart
4. Arborescence du projet
5. Compilation
6. Liste des fonctions
7. Contraintes
8. Journal de bord / Décisions prises
9. Tests réalisés
10. Sources / Références

---

## 1️⃣ Introduction

Ce projet s’inscrit dans le cadre de la formation Holberton et a pour objectif de reproduire la fonction `printf` en langage C. Il s'agit d’un exercice exigeant, qui nous pousse à structurer notre code, travailler en équipe et respecter des contraintes de normes strictes (notamment la norme Betty). Nous avons choisi de développer ce projet en collaboration en suivant un flowchart détaillé, une méthodologie étape par étape, et un travail de validation rigoureux à chaque étape. Cette documentation vise à présenter notre organisation, notre logique de développement, ainsi que les choix techniques effectués tout au long du projet.

## 2️⃣ Objectif du projet

- Reproduire la fonction `printf`.
- Gérer différents specifiers (`c`, `s`, `%`, etc.).  (A COMPLETER)
- Respecter les normes Betty.
- Créer un code lisible, structuré et évolutif.

## 3️⃣ Flowchart

👉 **Insérer ici une image du flowchart** 

## 4️⃣ Arborescence du projet

```
/holbertonschool-printf
│
├── main.h
├── _printf.c
├── specifiers.c
├── README.md
└── (Autres fichiers...)
```

## 5️⃣ Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c
```

## 6️⃣ Liste des fonctions

| Fichier             | Fonction             | Rôle                                                 |
| ------------------- | -------------------- | ---------------------------------------------------- |
| _printf.c           | _printf             | Fonction principale, lecture et dispatch             |
| specifiers.c        | print_char           | Affiche un caractère                                 |
| specifiers.c        | print_string         | Affiche une chaîne de caractères                     |
| specifiers.c        | print_percent        | Affiche un `%` littéral                              |
| _printf.c           | print_unknown_char   | Gère les caractères non reconnus après `%`           |
| _printf.c           | handle_specifier     | Gère la recherche et l'appel de la fonction associée |

## 7️⃣ Contraintes

- Respecter la norme Betty (40 lignes max / fonction).
- Pas d’utilisation de fonctions interdites.
- Gestion propre des erreurs.
- Retourner le nombre de caractères écrits.

## 8️⃣ Journal de bord / Décisions prises

*(À remplir au fur et à mesure : décisions de design, ajustements, choix de structure.
Exemple d'entrée : Date, décision prise, raison, impact sur le projet.)*

## 9️⃣ Tests réalisés

- Liste de tests unitaires.
- Tests d’intégration.
- Capture de validations par le checker.

## 🔟🔗 Sources / Références

- Documentation man de `printf`
- Cours Holberton
- Discussions entre binômes
- ChatGPT

---

👉 **Note finale :** Le README sera relu et finalisé à la fin du projet.


