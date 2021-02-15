---
title: Utilisation de Qt en ligne de commande
author: Iglesys347
---

## Ecrire le code source

Ecrire les différents .cpp et .h. On peut les mettre dans des répertoires tels que `src/` ou `include/` par exemple, Qt saura les retrouver.

## Générer le .pro du projet

Il faut créer le fichier de projet Qt (extension .pro), pour cela, éxécuter dans le répertoire du projet :

```bash
qmake -project
```

Un fichier `<nom_du_prjet>.pro` est alors créé. Il va falloir rajouter quelques lignes pour que tout fonctionne bien :

1. Ouvrir le fichier .pro (`nano <nom_du_prjoet>.pro` ou `gedit <nom_du_projet>.pro`)
2. Ajouter la ligne : `QT += gui widgets` en dessous de `INCLUDEPATH += .`
3. Ajouter la ligne : `OBJECTS_DIR = build` en dessous de la ligne précédement ajoutée si on veut que que les fichiers .o soient créés dans un répertoire en particulier (ici le répertoire `build/`)
4. Modifier la ligne `TARGET = <nom_du_projet>` par `TARGET = bin/<nom_du_projet>` pour que l'éxécutable soit rangé dans un répertoire particulier (ici le répertoire `bin`)

## Générer le `Makefile`

Pour pouvoir compiler le projet, on va avoir besoin d'un `Makefile` ce dernier peut être créé via la commande :

```bash
qmake <nom_du_projet>.pro
```

## Compiler le projet

Pour compiler le projet, nous allons utiliser le `Makefile` que nous venons de créer. Pour cela il suffit de faire dans le répertoire du projet (là ou se situe le Makefile):

```bash
make
```

Cela va créer les objets .o dans le répertoire `build` et l'écécutable `<nom_du_projet>` dans le répertoire `bin` (si le fichier de projet a été configuré de la même manière que précédement).

## Exécuter le programme

Il ne reste plus qu'à exécuter le programme, pour ce faire :

```bash
./executable
```

Ce qui donne dans notre exemple :

```bash
./bin/<nom_du_projet>
```

## Annexe

### Installation de Qt en ligne de commande

Exécuter les lignes suivantes :

```bash
sudo apt-get update
sudo apt-get install build-essential
sudo apt-get install qtcreator #optionel
sudo apt install qt5-default
sudo apt-get install qt5-doc qtbase5-examples qtbase5-doc-html #optionnel
```
