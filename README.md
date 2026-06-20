# Como compilar e executar os exercícios

## 1. Pré-requisito: compilador instalado

O `gcc` (MinGW-w64 / WinLibs) já foi instalado via `winget` nesta máquina.

Se acabou de instalar (ou se o comando `gcc` não for reconhecido), **feche e abra um terminal novo** (ou reinicie o VS Code) antes de continuar — o Windows só atualiza o `PATH` em sessões novas.

Para confirmar que está tudo certo, rode:

```powershell
gcc --version
```

Se aparecer a versão do gcc, está pronto pra compilar.

## 2. Entrar na pasta dos exercícios

```powershell
cd "seu repositório"
```

## 3. Compilar um exercício

```powershell
gcc lista1-exerc20.c -o exerc20.exe
```

Troque `lista1-exerc20.c` pelo arquivo desejado e `exerc20.exe` pelo nome que quiser dar ao executável.

Para ver avisos de código suspeito durante a compilação (recomendado antes de entregar):

```powershell
gcc -Wall lista1-exerc20.c -o exerc20.exe
```

## 4. Executar o programa compilado

```powershell
.\exerc20.exe
```

A maioria dos exercícios abre um menu interativo (digite o número da opção e aperte Enter). Eles usam `system("cls")` e `system("pause")`, então funcionam melhor rodando direto no terminal (não dá pra automatizar a entrada via pipe/script).

## 5. Compilar e já executar em um único comando

```powershell
gcc lista1-exerc20.c -o exerc20.exe; .\exerc20.exe
```

## Observações

- Cada exercício é independente — repita os passos 3 e 4 trocando o nome do arquivo.
- Os arquivos `.exe` gerados podem ser apagados depois de testar; eles não fazem parte do código-fonte entregue.
- `lista1-exerc9.c` não existe mais: foi renomeado para `lista1-exerc9.txt` (edição intencional, fora deste fluxo de compilação).
