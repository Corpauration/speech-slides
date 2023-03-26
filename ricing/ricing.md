---
marp: true
footer: ![](../theme/corpauration.svg)
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
    background-color: transparent;
  }
  img[alt~="small"] {
    width: 40vw;
  }
  th a, td a {
    font-size: 15px;
    text-align: left;
    font-weight: normal;
    margin: 0;
    padding: 0;
    display: block;
  }
---

# Ricing

Ou l'art de personnaliser son ordinateur

![bg left:40% height:300px](https://avatars.githubusercontent.com/u/7955393?s=600&v=4)

---

## Qu’est-ce qui vous attends ?

![center](img/preview.png)

---

## Qu’est-ce qui vous attends ?

- Reprenons les bases
- Partons de A à Z

---

## On **A**llume la machine

![bg left:50% height:300px](https://media.tenor.com/ThL-zP5VYmgAAAAC/power-on-press-button.gif)

- Power-on self test
- UEFI initialise le matériel nécessaire au démarrage
- NVRAM lu pour voir quel .efi lancer

---

## Le **B**ootloader se lance

- GRUB
- Limine
- rEFInd
- systemd-boot
- Plop Boot Manger

---

## **C**'est au tour du kernel de se lancer

---

## On lance **D**onc ensuite l'initramfs

Créé un système de fichier (temporaire) vide qui va permettre de charger des modules nécessaires au lancement de son
système (disque dur, encryption, ...)

---

## Au tour de l'**E**arly userspace

Les différents modules du kernel sont chargés, déchiffrage, plymouth.

Le vrai système de fichier est monté puis définit comme la racine.

---

## **F**inalement le premier processus est lancé

Systemd...

Quand il a tout lancé il lance au choix :

- getty
Terminal virtuel initialisé et protégé derrière un invité qui demande login et mdp
- Un display manager
Session graphique

---

## Parlons enfin de **G**raphique

1. Display manager
2. Xorg
1. Window manager
2. Compositeur
3. Wayland
4. Environnement de bureau

---

## Ecran de connexion grap**H**ique (aka display manager)

- gdm (Support de themes -> changer arrière plan et couleurs)
- [sddm](https://github.com/sddm/sddm) (Support de themes -> couleurs, images, positions)
- [lightdm](https://github.com/canonical/lightdm) (Support de "greeter")

---

## Ecran de connexion grap**H**ique (aka display manager)

| ![small](https://i.redd.it/nbh7d06nn5m01.png) <br> [Credits](https://www.reddit.com/r/unixporn/comments/84wypv/lightdmwebkit2greeter_ricing_the_greeter/) | ![small](https://i.redd.it/y5ju53ev9hz31.png) <br> [Credits](https://www.reddit.com/r/unixporn/comments/dy66ue/lightdmtinygreeter_tiny_material/)      |
|-----------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------|
| ![small](https://github.com/nautilor/nord-sddm/raw/master/Nord/preview.png) <br> [Credits](https://github.com/nautilor/nord-sddm)                         | ![small](https://images.pling.com/img/00/00/44/96/51/1312658/3bd097cc6c63bac30c354aa736020a52620d.png) <br> [Credits](https://store.kde.org/p/1312658) |

---

## Serveur graph**I**que

- Xorg
- Wayland

---

### Xorg

- Utilisation la plus répendu
- Fonctionne sous la forme d'un ensemble de librairies
  - Xlib
  - XCB (plus récente et moderne)
