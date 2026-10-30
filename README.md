# Dora MAP'S

Jogo interativo em C com a biblioteca `graphics.h`, desenvolvido no 1º período para praticar lógica de programação. Apresenta um mapa interativo com curiosidades sobre lugares do mundo e um easter egg inspirado na "Dora Maps", que dá nome ao projeto.

## Conceitos aplicados

Funções, estruturas e programação gráfica em C.

## Tecnologias

- C
- Code::Blocks com MinGW
- `graphics.h` (WinBGIm)

## Configuração do ambiente

1. Instale o [Code::Blocks](https://www.codeblocks.org/) e o [MinGW](https://osdn.net/projects/mingw/releases/) (marque o `gcc` e a `win32api`).
2. Em *Settings → Compiler → Toolchain executables*, confirme o diretório do MinGW.
3. Adicione a biblioteca gráfica:
   - copie `graphics.h` e `winbgim.h` para a pasta `include` do MinGW;
   - copie `libbgi.a` para a pasta `lib` do MinGW.
4. Em *Settings → Compiler → Linker settings → Other linker options*, adicione:

```
-lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32
```

## Executar

```bash
git clone https://github.com/KlebersonCLima/Projeto--Dora-Map-s.git
```

Abra o projeto no Code::Blocks e compile. O executável pronto está na pasta `IMAGENS E EXECUTAVEL`.

## Licença

Projeto acadêmico e educacional. O uso, a modificação e a distribuição são livres para aprendizado e projetos não comerciais; para outros fins, mantenha os créditos ao autor.
