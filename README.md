# 🌍 Projeto Dora-MAP'S  

Trabalho desenvolvido no 1º período para aprimorar a lógica de programação em **linguagem C**, utilizando o ambiente de desenvolvimento **Code::Blocks**.  

## 📌 Sobre o Projeto  
O objetivo do projeto foi explorar o uso de **funções**, **estruturas** e a biblioteca **graphics.h** para criar um jogo interativo. O jogo apresenta um **mapa interativo** que exibe curiosidades sobre diferentes lugares do mundo.  

Além disso, há um **easter egg** inspirado na "Dora Maps", o que deu origem ao nome do projeto.  

## Tecnologias Utilizadas  
- **Linguagem C**  
- **Code::Blocks**  
- **Biblioteca graphics.h**  

## Como Executar  
1. **Baixe o repositório** ou clone com:  
   ```bash
   git clone https://github.com/seu-usuario/Dora-MAPS.git
# 🎮 DoraMap’s

Um jogo desenvolvido em C utilizando a biblioteca `graphics.h`.

## Requisitos

Para executar o projeto corretamente, você precisa:

- [Code::Blocks](https://www.codeblocks.org/) instalado
- [MinGW](https://osdn.net/projects/mingw/releases/) configurado no sistema
- Configuração do Code::Blocks para compilar projetos em C
- Biblioteca `graphics.h` configurada

## Configuração do Ambiente

### 1️⃣ Instalando o MinGW  
Baixe e instale o MinGW pelo link oficial. Durante a instalação, certifique-se de marcar as opções para o compilador `gcc` e a biblioteca `win32api`.  

### 2️⃣ Configurando o Code::Blocks  
Após instalar o MinGW, siga os passos:  

1. Abra o **Code::Blocks**.  
2. Vá em **Settings** → **Compiler...**.  
3. Na aba **Toolchain executables**, verifique se o diretório do MinGW está corretamente configurado.  

### 3️⃣ Configurando a `graphics.h`  
A biblioteca `graphics.h` não vem por padrão no MinGW, então é necessário adicioná-la manualmente:  

1. Baixe os arquivos `graphics.h`, `winbgim.h`, `libbgi.a` e copie-os para:  
   - `graphics.h` e `winbgim.h` → Dentro da pasta `include` do MinGW  
   - `libbgi.a` → Dentro da pasta `lib` do MinGW  
2. No Code::Blocks, vá em **Settings** → **Compiler...** → **Linker settings**.  
3. Adicione a seguinte linha nos **Other linker options**:  
   ```bash
   -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32
## Licença

Este projeto foi desenvolvido exclusivamente para fins acadêmicos e educacionais.  
Você tem permissão para usar, modificar e distribuir o código livremente, desde que seja para aprendizado ou projetos não comerciais.  

Caso deseje utilizá-lo para outros fins, recomendamos dar os devidos créditos ao autor original.  