# How to Build

## Dependencias

* build-essential
* qt6-base-dev

```bash
sudo apt install qt6-base-dev build-essential
```

## Clonando o repositório

```bash
git clone https://github.com/Tiger-OperatingSystem/welcome-qt.git
```

## Build

```bash
cd welcome-qt/welcome.src
qmake6 welcome.pro
make
```

## Executando

```bash
./welcome
```
