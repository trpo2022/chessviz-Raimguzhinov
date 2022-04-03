Команда которую обещал, но нужно установить RipGrep:
```sudo apt install rg```

Сама команда:
```
rg --ignore --hidden --files --glob '!.git/' "$@" | tree --fromfile -a
```

Можно сделать алиас:
```
alias gitree='rg --ignore --hidden --files --glob '!.git/' "$@" | tree --fromfile -a'
```

![Пример](https://github.com/trpo2022/chessviz-Raimguzhinov/.gitree.png)
