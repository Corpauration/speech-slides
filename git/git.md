---
marp: true
footer: ![ ](../theme/corpauration.svg)
style: |
  footer {
    width: calc(100% - 60px);
    left: 30px;
    right: 30px;
  }
  footer img {
    max-height: 4em;
    background-color: transparent;
    float: right;
  }
  img[alt~="center"] {
    display: block;
    margin: 0 auto;
  }  
---

# Git

Ou l'art de versionner son code

![bg left:40% height:300px](https://git-scm.com/images/logos/logomark-orange@2x.png)

---

## Qu’est-ce que GIT ?

- Système de gestion de versions de code (ou autres fichiers)
- Garde l’historique de toutes les modifications faites
- Conçu pour le travail en équipe
- Utilisé pour développer le kernel linux
- Système de branche qui permet de travailler sur des espaces isolé et séparé

---

## Hébergeurs GIT

- GitHub : Plateforme la plus connue
- Gitlab :
    - On peut héberger sa propre instance
    - Gitlab de l’école : [https://gitlab.etude.cy-tech.fr/](https://gitlab.etude.cy-tech.fr/)
- Review de code
- Fonctionnalité de build automatisé
- Liste de tâche, de problèmes

---

## Comment accéder à un hébergeur depuis son ordi ?

Avec une clé [ssh](https://fr.wikipedia.org/wiki/Secure_Shell) :

- Fonctionne sur un système de clé publique, clé privée
- Plus solide qu’un mot de passe

On va générer une clé ssh et l’ajouter dans le gitlab de l’école

---

## Comment accéder à un hébergeur depuis son ordi ?

- Génération de la clé ssh

```sh
$ ssh-keygen -t ed25519 -C "login@cy-tech.fr"
```

- Le programme va vous demander où stocker la clé, par défaut, il la met à l’emplacement /home/cytech/.ssh/id_ed25519
- Entrez un mdp si vous le souhaitez pour protéger votre clé en local
- 2 fichiers sont créés :

```
~/.ssh/id_ed25519 (clée privée)
~/.ssh/id_ed25519.pub (clée publique)
```

---

## Comment accéder à un hébergeur depuis son ordi ?

- ssh-agent
    - Gère toutes clés ssh
    - GIT et d’autres outils qui utilisent les clés ssh passent par lui pour savoir quelle clé utiliser
- Démarrage de ssh-agent
    - Sur des machines avec des environnements graphiques tels que GNOME, KDE… il est démarré automatiquement
    - Démarrage manuel :

```sh
$ eval $(ssh-agent)
```

---

## Comment accéder à un hébergeur depuis son ordi ?

- Ajoutons la clé ssh dans ssh-agent

```sh
$ ssh-add ~/.ssh/id_ed25519
```

- Ajoutons la clé ssh dans l’instance gitlab de l’école
    - [https://gitlab.etude.cy-tech.fr/](https://gitlab.etude.cy-tech.fr/)
    - Utilisez les identifiants de l’université pour vous connecter

---

## Comment accéder à un hébergeur depuis son ordi ?

![center](img/gitlab0.png)

---

## Comment accéder à un hébergeur depuis son ordi ?

![center](img/gitlab1.png)

---

## Entrons dans le vif du sujet :

![bg left:40% height:300px](https://res.cloudinary.com/practicaldev/image/fetch/s--buWpzO3t--/c_limit%2Cf_auto%2Cfl_progressive%2Cq_auto%2Cw_880/https://dev-to-uploads.s3.amazonaws.com/i/xosaqxln2vnadyyv7b46.png)

---

## Un peu de vocabulaire...

- **repository** / **repo** = Espace de travail sur lequel git a une influence sur les fichiers / dossiers contenus dedans
- **commit** = État où les modifications faites ont été enregistrées à une heure
    - va voir mon dernier commit = va voir les derniers changements/modif que j’ai fait
    - commit ce que tu as fait stp = sauvegarde tes modifications stp
- **head** = Tête des modifications / Commit (Modification) le plus récent
- **origin** = Réfère à la version du repo sur le serveur distant
- **master** / **main** = Nom généralement utilisé pour la branche principale

---

## Comment on interagit avec GIT ?

- Simplement avec la commande `git`

![bg right:40% height:300px](https://media.tenor.com/-bYrw7bjx-UAAAAC/youre-right-good.gif)

---

## Définissons notre identité

Chaque commit est associé à une personne qui est défini par un nom et une adresse mail.

```sh
$ git config --global user.name "Votre nom"
$ git config --global user.email "Votre email"
```

---

## Comment récupérer un repo git distant ?

Avec la commande :

```sh
$ git clone <url>  # Clone un repo dans un dossier portant son nom
```

Ici \<url\> est soit :

- Un lien https ([https://github.com/Corpauration/cyrel](https://github.com/Corpauration/cyrel)) → N’utilise pas notre
  clé ssh pour s’authentifier
- Une adresse qui commence par `git@` (git@github.com:Corpauration/cyrel.git) → Utilise notre clé ssh

---

## Comment voir les logs du repo ?

Avec la commande :

```sh
$ git log
```

![center](img/git0.png)

--- 

## Comment voir les modifications faites par un commit ?

Avec la commande :

```sh
$ git show <commit>
```

---

## Comment voir les modifications faites par un commit ?

![center height:500px](img/git1.png)


--- 

## Comment voir les modifications faites depuis un commit ?

Avec la commande :

```sh
$ git diff <commit>
```

---

## Comment voir les modifications faites depuis un commit ?

![center height:500px](img/git2.png)

---

## Comment créer un repo git ?

Créez un dossier vide et à l’intérieur initialisez un nouveau repo git avec la commande :

```sh
$ git init
```

Le dossier contient le dossier `.git`

---

## Comment le lier à un repo en ligne ?

- Créer le repo en ligne :

Exemple avec le gitlab de l’école :

![center height:300px](img/gitlab2.png)

---

## Comment le lier à un repo en ligne ?

- Lier notre repo à celui créé en ligne

```sh
$ git remote add origin git@gitlab.etude.cy-tech.fr:schwerkolt/git-test.git
```

---

## Regardons le status de notre repository

Dans votre dossier, créez un fichier toto

```sh
$ git status
```

![center height:300px](img/git3.png)

---

## Comment sauvegarder les modifications faites ?

- Mettre un fichier dans la liste des changements qu’on veut sauvegarder

```sh
$ git add <fichier>   # git rm --cached <fichier>    pour le retirer de la liste
```

- Sauvegardons les modifications

```sh
$ git commit   # Ouvre vim/nano pour écrire le message de commit
$ git commit -m "Message de commit"
```

---

## Comment modifier un commit qui vient juste d'être fait ?

- Modification du/des fichiers
- Mettre le fichier dans la liste des changements qu'on veut modifier

```sh
$ git add toto
```

- Modifions le dernier commit

```sh
$ git commit --amend
$ git commit --amend -m "Message de commit"
```

---

## Comment annuler le commit juste fait ?

```sh
$ git reset HEAD~1
```

---

## Comment remettre un fichier à l'état de la dernière modification ?

```sh
$ git restore <fichier>
```

---

## Comment envoyer les modifications au serveur ?

- Envoyer les modifications & attacher sa branche `master` locale à une du même nom sur le serveur (`origin`)

```sh
$ git push --set-upstream origin master
$ git push -u origin master
```

- Sinon

```sh
$ git push
```

---

## Comment récupérer les commits faits depuis le serveur

```sh
$ git pull
```

Deux modes de récupérations :

- **Merge**

Créer un commit pour unifier les commits locaux avec ceux sur le serveur

```sh
$ git pull # Mode par défaut
$ git pull --no-rebase
```

- **Rebase**

Récupère les commits sur le serveur et les mets avant les commits locaux

```sh
$ git pull --rebase
```

---

## Le stash

> Stash = Fourre tout

**Problématique :** vous êtes en train de travailler sur une fonctionnalité non fini (vous ne pouvez pas commit) mais
vous devez récupérer un commit sur le serveur.

Mettre les modifications non commit dans le stash, pull, puis remettre les modifs dans votre environnement de travail :

```sh
$ git stash
$ git pull
$ git stash apply
```

En une commande :

```sh
$ git pull --autostash
```

---

## Tout va bien dans le meilleur des mondes ?

Imaginons deux personnes modifie la même partie d'un fichier ?

---

## Tout va bien dans le meilleur des mondes ?

![center](https://media.tenor.com/ZFc20z8DItkAAAAd/facepalm-really.gif)

Il y a des conflits...

---

## Conflit - Solution 1

Vous avez pull en mode merge.

```sh
$ git pull # git pull --no-rebase
```

```
<<<<<<< HEAD
Local
=======
Serveur
>>>>>>> 3e30aaa97a30c042cf6b5fd6da7d586b82969dd8

Coding Night !
```

Fixez les conflits, puis faites un commit & push

---

## Conflit - Solution 2

Vous avez pull en mode merge.

```sh
$ git pull --rebase
```

```
<<<<<<< HEAD
Serveur
=======
Local
>>>>>>> bbd2100 (Conflict)

Coding Night !
```

Fixez les conflits, puis faites :

```sh
$ git add ... # Les fichiers qui avaient des conflits
$ git rebase --continue

# Puis push
$ git push
```

---

## Les branches

- Créer une branche

```sh
$ git branch <nom>
```

- Voir la liste des branches

```sh
$ git branch
```

- Changer de branche

```sh
$ git checkout <nom>
```

---

## Les branches

- Envoyer les modifications & attacher sa branche locale à une du même nom sur le serveur (`origin`)

```sh
$ git push --set-upstream origin <nom>
$ git push -u origin <nom>
```

- Sinon

```sh
$ git push
```

---

## Éloignons-nous des commandes

---

## Conseils

- Message de commits en anglais
- Quand vous faites un commit, assurez-vous que le projet reste fonctionnel : Ne pas commit du code qui ne compile pas
- Faites un commit par fonctionnalités et pas un gros commit par jour
- Utilisez les branches

---

## Fonctionnalités des hébergeurs GIT

- Merge request
- Todo list
- Reports des problèmes

---

# Des questions ?

