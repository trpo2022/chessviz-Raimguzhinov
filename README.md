Команда которую обещал, но нужно установить RipGrep:
```
sudo apt install rg
```

Сама команда:
```
rg --ignore --hidden --files --glob '!.git/' "$@" | tree --fromfile -a
```

Можно сделать алиас:
```
alias gitree='rg --ignore --hidden --files --glob '!.git/' "$@" | tree --fromfile -a'
```

#

<img src="https://sun9-87.userapi.com/impg/drCUM0o0R0O5_DYtoD9PfALJERyxtCtCV2RG-A/4CwYEdiLdpU.jpg?size=2376x1636&quality=96&sign=f49201d760de783180e6d249a003bea4&type=album" style=" width:800px ; height:600px "></a>

