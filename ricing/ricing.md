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
  img[alt~="center-c1"] {
    display: block;
    margin: 0 auto;
    background-color: transparent;
    height: 55vh;
  }
  img[alt~="center-c2"] {
    display: block;
    margin: 0 auto;
    background-color: transparent;
    height: 20vh;
  }
  img[alt~="small"] {
    width: 40vw;
  }
  img[alt~="tiny"] {
    width: 5vw;
  }
  th a, td a {
    font-size: 15px;
    text-align: left;
    font-weight: normal;
    margin: 0;
    padding: 0;
    display: block;
  }
  inline {
    display: inline;
  }
  inline p {
    display: inline;
  }
  inline p br {
    display: none !important;
  }
---

# Ricing

Ou l'art de personnaliser son ordinateur

![bg left:40% height:300px](https://avatars.githubusercontent.com/u/7955393?s=600&v=4)

---

## Qu’est-ce qui vous attend ?

![center](img/preview.png)

---

## Qu’est-ce qui vous attend ?

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

- gdm (Support de themes -> changer arrière-plan et couleurs)
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

![bg left:30% height:300px](https://upload.wikimedia.org/wikipedia/commons/9/90/X.Org_Logo.svg)

- Utilisation la plus répandue
- Fonctionne sous la forme d'un ensemble de librairies
  - Xlib
  - XCB (plus récente et moderne)

---

### Xorg

![bg left:30% height:300px](https://upload.wikimedia.org/wikipedia/commons/9/90/X.Org_Logo.svg)

- Window manager
  - Gère les fenêtres
  - Peut gérer l'interface (barre de tache)
  - Peut gérer les notifications
  - Peut gérer les keybindings
  - Window manager les plus connus : [awesomewm](https://awesomewm.org/), [i3](https://i3wm.org/), [openbox](http://openbox.org/), [xfwm](https://docs.xfce.org/xfce/xfwm4/start), [mutter](https://gitlab.gnome.org/GNOME/mutter), [kwin](https://en.wikipedia.org/wiki/KWin)
- Compositeurs
  - Gère les "effets" (transparence, floue, peut empêcher le screen-tearing, ...)
  - Compositeurs connus : [Johann Sebastian Bach](https://en.wikipedia.org/wiki/Johann_Sebastian_Bach), [picom](https://github.com/yshui/picom), [mutter](https://gitlab.gnome.org/GNOME/mutter), [kwin](https://en.wikipedia.org/wiki/KWin)

---

### Wayland

![bg left:20% height:150px](https://wayland.freedesktop.org/wayland.png)

- Remplace Xorg (plus facile à développer et maintenir)
- Un serveur wayland est appelé compositeur (fait office de compositeur)
- Un compositeur fait aussi office de window manager
- Plus optimisé et rapide que Xorg
- Compatible avec les applications faites pour Xorg grâce à Xwayland
- Ajoute de la sécurité entre l'intéraction entre les applications (cause souvent des soucis pour les partages d'écrans)
- Nvidia...
- Compositeurs les plus connus : [sway](https://github.com/swaywm/sway), [hyprland](https://hyprland.org/), [weston](https://gitlab.freedesktop.org/wayland/weston), [mutter](https://gitlab.gnome.org/GNOME/mutter), [kwin](https://en.wikipedia.org/wiki/KWin)

---

## **J**'ai oublié plymouth

- Permet d'avoir un démarrage (et arrêt) graphique
- Personnalisable. [Une référence](https://github.com/adi1090x/plymouth-themes)

---

## Des**K**top Environnement

- Rassemble :
  - Un window manager (avec compositeur) ou compositeur (wayland)
  - Un écosystème d'applications
  - (facultativement) Un display manager
- Patte graphique unifié et partagé
- Plus facile pour des gens qui débutent ou qui ne veulent pas s'embêter avec des détails techniques
- Exemple :
  - [GNOME](https://www.gnome.org/) basé sur GTK
  - [KDE Plasme](https://www.kde.org/plasma-desktop) basé sur Qt
  - [Xfce](https://xfce.org/) basé sur GTK
  - [Cutefish](https://cutefish-ubuntu.github.io/) basé sur Qt

---

## Des**K**top Environnement

| ![small](https://i.imgur.com/Ts8KxBw.png) <br> [Credits](https://youtu.be/GtvbT_p0HMk)                                                   | ![small](https://kde.org/announcements/plasma/5/5.27.0/fullscreen_with_apps.png) <br> [Credits](https://www.kde.org/plasma-desktop)                                         |
|------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| ![small](https://news.itsfoss.com/content/images/2022/12/xfce-4-18-hero.jpg) <br> [Credits](https://news.itsfoss.com/xfce-4-18-release/) | ![small](https://www.opensourcefeed.org/screenshots/CutefishOS%200.6/08%20About%20the%20System.jpg) <br> [Credits](https://www.opensourcefeed.org/cutefish-os-0.6-release/) |

---

## **L**es shells

Il n'y a pas que l'interface graphique : il y a les shells.

> Interpréteur de commande, fournit une interface à l'utilisateur pour interagir avec son pc

- [bash](https://www.gnu.org/software/bash/)
- [zsh](https://www.zsh.org/)

---

## **L**es shells

Il n'y a pas que l'interface graphique : il y a les shells (POSIX compliant).

> Interpréteur de commande, fournit une interface à l'utilisateur pour interagir avec son pc

- [bash](https://www.gnu.org/software/bash/)
- [zsh](https://www.zsh.org/)
- ~~[fish](https://fishshell.com/)~~

---

# **M**aintenant passons au sujet qui nous intéresse

![center-c1](https://i.redd.it/5n5sezvuwsi61.jpg)

---

## Qu'est-ce qu'o**N** peut customiser ?

- Interface
  - Window manager / compositeur wayland
  - Curseurs
  - Barre de recherche / Spotlight
  - Notifications
  - Desktop Environnement
- Shell
- Bootloader (grub)
- Plymouth
- Display manager
- Bonus

---

## B**O**n commençons par l'interface

![center-c1](img/diag-decision.svg)

---

## **P**remièrement sway / i3

![center-c1](img/sway.png)

https://github.com/joan31/dotfiles-sway

---

## Débar**Q**ue alors : awesomewm

![center-c1](img/awesome1.jpg)

https://github.com/ChocolateBread799/dotfiles

---

## Débar**Q**ue alors : awesomewm

![center-c1](img/awesome2.png)

https://github.com/Kasper24/KwesomeDE

---

## Débar**Q**ue alors : awesomewm

<video style="display:block; margin: 0 auto; height: 50vh" controls loop src="img/awesome3.mp4"></video>

Coming soon™

---

## Débarque alors l'enfer d'**U**buntu

- Versions 20.04 & 22.04
- sway 1.4 vs 1.8
- Dernière version d'awesome : 2019 (4.3) -> 1 588 commits sur leur github depuis

---

## **V**oilà la solution

Installer une distribution "rolling-release"

![center](https://upload.wikimedia.org/wikipedia/commons/thumb/e/e8/Archlinux-logo-standard-version.png/1920px-Archlinux-logo-standard-version.png)

---

## **V**oilà la solution

En vrai j'ai réalisé une solution alternative :

**lulu**

![center-c2](https://opengraph.githubassets.com/a18ee585c7d547f37b5d688a9f859404118f88816caff0dfae665b7fe7bf664b/alyrow/lulu)

- A un paquet pour awesome
- Simple d'utilisation (`lulu install awesome-git`)

<div class="inline">

  ![tiny](img/lulu.png)
 https://github.com/alyrow/lulu/releases/tag/1.0.5
</div>

---

## **W**orking with desktop environment

La majorité des DE (GNOME, KDE Plasma, Xfce) supportent des themes.

Il existe des boutiques des themes : https://www.pling.com/

- Thèmes pour GTK 3/4 (GNOME)
- Thèmes pour KDE Plasma
- Thèmes pour Xfce

---

## **W**orking with desktop environment

![center-c1](https://images.pling.com/img/00/00/32/24/44/1400409/screenshot-20220210-145749.png)

https://store.kde.org/p/1400409

---

## **W**orking with desktop environment

![center-c1](https://images.pling.com/img/00/00/32/24/44/1477941/1efdeaf7afb9ade25589fac2a2d59570d0d673f9b3128714f0d95f81a23bdc46b925.png)

https://www.pling.com/p/1477941/

---

## bash **X** zsh

- Upgrade de bash
- Completion
- ...
- Themable
- Plugins

[Oh My ZSH](https://ohmyz.sh/)

![bg left:40% height:300px](https://raw.githubusercontent.com/romkatv/powerlevel10k-media/master/prompt-styles-high-contrast.png)

https://github.com/romkatv/powerlevel10k

![center-c2](https://raw.githubusercontent.com/romkatv/powerlevel10k-media/master/performance.gif)

---

## Corpauration theme but it's only grub **Y**et

_insert photo_

https://github.com/Corpauration/corpauration-theme

---

## Un **Z**est pour finir

- Plymouth

![center-c2](https://raw.githubusercontent.com/adi1090x/files/master/plymouth-themes/previews/53.gif)

https://github.com/adi1090x/plymouth-themes

Détail pour installer un thème + un script pour tester le thème sans redémarrer


- Pour les pc hp : pour changer le logo de l'école

![tiny](img/logo.png)
